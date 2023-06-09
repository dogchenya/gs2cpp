﻿#include "parse.h"
#include "gaussian.tab.hpp"
#include <errno.h>
#include <fstream>
#include <string.h>
#include "gs_common.h"
#include "gs_file.h"

GaussianParsePtr g_parse = std::make_shared<GaussianParse>();

void yyerror(char const *msg) { g_parse->error(msg); }

GaussianParse::GaussianParse() {
  _bWithGaussian = false;
  _bUseCurrentPath = false;
  _itab = 0;
  _bUseCurrentPathFirst = false;
  initScanner();
}

void GaussianParse::setGaussian(bool bWithGaussian) { _bWithGaussian = bWithGaussian; }

void GaussianParse::setHeader(const string &sHeader) { _sHeader = sHeader; }

void GaussianParse::setCurrentPriority(bool bFlag) { _bUseCurrentPathFirst = bFlag; }

string GaussianParse::getHeader() {
  if (_sHeader.empty()) return _sHeader;
  return _sHeader + "/";
}

void GaussianParse::clear() {
  while (!_contexts.empty()) _contexts.pop();
  while (!_contains.empty()) _contains.pop();
  _vcontexts.clear();
  _structs.clear();
  _vec_ros_params.clear();
  _enums.clear();
  _namespaces.clear();
}

void GaussianParse::parse(const string &sFileName) {
  if (_bUseCurrentPath) {
    std::string sTemp = sFileName;
    bool isExist = common::GS_File::isFileExist(sFileName);

    if (!isExist) {
      sTemp = common::GS_File::extractFileName(sFileName);
    }

    clear();

    _contains.push(std::make_shared<Container>(""));
    if (!(yyin = fopen(sTemp.c_str(), "r"))) {
      error("open file '" + sFileName + "(" + sTemp + ")" + "' error :" + string(strerror(errno)));
    }

    pushFile(sFileName);

    yyparse();

    return;
  }

  if (_bUseCurrentPathFirst) {
    std::string sTemp = common::GS_File::extractFileName(sFileName);
    bool isExist = common::GS_File::isFileExist(sTemp);

    if (!isExist) {
      sTemp = sFileName;
    }

    clear();

    _contains.push(std::make_shared<Container>(""));
    if (!(yyin = fopen(sTemp.c_str(), "r"))) {
      error("open file '" + sFileName + "(" + sTemp + ")" + "' error :" + string(strerror(errno)));
    }

    pushFile(sFileName);

    yyparse();

    return;
  }

  {
    clear();

    _contains.push(std::make_shared<Container>(""));
    if (!(yyin = fopen(sFileName.c_str(), "r"))) {
      error("open file '" + sFileName + "' error :" + string(strerror(errno)));
    }

    pushFile(sFileName);

    yyparse();
  }
}

void GaussianParse::pushFile(const string &file) {
  ContextPtr c = std::make_shared<Context>(file);
  _contexts.push(c);
  _vcontexts.push_back(c);
}

ContextPtr GaussianParse::popFile() {
  ContextPtr c = _contexts.top();
  _contexts.pop();
  return c;
}

bool GaussianParse::getFilePath(const string &s, string &file) {
  if (_bUseCurrentPath) {
    if (s.length() < 2 || s[0] != '\"' || s[s.length() - 1] != '\"') {
      error("#include need \"FILENAME\"");
    }

    file = s.substr(1, s.length() - 2);

    std::string sTemp = file;
    bool isExist = common::GS_File::isFileExist(file);

    if (!isExist) {
      file = common::GS_File::extractFileName(file);
    }

    for (size_t i = 0; i < _vcontexts.size(); i++) {
      if (_vcontexts[i]->getFileName() == file) {
        return false;
      }
    }

    return true;
  }

  if (_bUseCurrentPathFirst) {
    if (s.length() < 2 || s[0] != '\"' || s[s.length() - 1] != '\"') {
      error("#include need \"FILENAME\"");
    }

    file = s.substr(1, s.length() - 2);

    std::string sTemp = common::GS_File::extractFileName(file);
    bool isExist = common::GS_File::isFileExist(sTemp);

    if (isExist) {
      file = sTemp;
    }

    for (size_t i = 0; i < _vcontexts.size(); i++) {
      if (_vcontexts[i]->getFileName() == file) {
        return false;
      }
    }

    return true;
  }

  if (s.length() < 2 || s[0] != '\"' || s[s.length() - 1] != '\"') {
    error("#include need \"FILENAME\"");
  }

  file = s.substr(1, s.length() - 2);

  if (!common::GS_File::isFileExist(file)) {
    for (size_t i = 0; i < _vIncludePath.size(); i++) {
      if (common::GS_File::isFileExist(_vIncludePath[i] + "/" + file)) {
        file = _vIncludePath[i] + "/" + file;
        break;
      }
    }
  }

  for (size_t i = 0; i < _vcontexts.size(); i++) {
    if (_vcontexts[i]->getFileName() == file) {
      return false;
    }
  }

  return true;
}

string GaussianParse::getCurrFileName() { return _contexts.top()->getFileName(); }

void GaussianParse::nextLine() { _contexts.top()->nextLine(); }

ContextPtr GaussianParse::currentContextPtr() { return _contexts.top(); }

void GaussianParse::error(const string &msg) {
  cerr << _contexts.top()->getFileName() << ": " << _contexts.top()->getCurrLine() << ": error: " << msg << endl;
  exit(-1);
}

int GaussianParse::checkKeyword(const string &s) {
  std::map<std::string, int>::const_iterator it = _keywordMap.find(s);
  if (it != _keywordMap.end()) {
    return it->second;
  }

  if (!_bWithGaussian) {
    string sPrefix = "gaussian";
    //不能以gaussian开头
    if ((s.length() >= sPrefix.length()) && (s.substr(0, sPrefix.length()) == sPrefix)) {
      error("identifier can't start with 'gaussian'");
    }
  }
  return GAUSSIAN_IDENTIFIER;
}

void GaussianParse::initScanner() {
  _keywordMap["void"] = GAUSSIAN_VOID;
  _keywordMap["struct"] = GAUSSIAN_STRUCT;
  _keywordMap["ros_params"] = GAUSSIAN_ROS_PARAMS;
  _keywordMap["bool"] = GAUSSIAN_BOOL;
  _keywordMap["byte"] = GAUSSIAN_BYTE;
  _keywordMap["short"] = GAUSSIAN_SHORT;
  _keywordMap["int"] = GAUSSIAN_INT;
  _keywordMap["double"] = GAUSSIAN_DOUBLE;
  _keywordMap["float"] = GAUSSIAN_FLOAT;
  _keywordMap["long"] = GAUSSIAN_LONG;
  _keywordMap["string"] = GAUSSIAN_STRING;
  _keywordMap["vector"] = GAUSSIAN_VECTOR;
  _keywordMap["map"] = GAUSSIAN_MAP;
  _keywordMap["key"] = GAUSSIAN_KEY;
  _keywordMap["routekey"] = GAUSSIAN_ROUTE_KEY;
  _keywordMap["module"] = GAUSSIAN_NAMESPACE;
  _keywordMap["interface"] = GAUSSIAN_INTERFACE;
  _keywordMap["out"] = GAUSSIAN_OUT;
  _keywordMap["require"] = GAUSSIAN_REQUIRE;
  _keywordMap["optional"] = GAUSSIAN_OPTIONAL;
  _keywordMap["false"] = GAUSSIAN_FALSE;
  _keywordMap["true"] = GAUSSIAN_TRUE;
  _keywordMap["enum"] = GAUSSIAN_ENUM;
  _keywordMap["const"] = GAUSSIAN_CONST;
  _keywordMap["unsigned"] = GAUSSIAN_UNSIGNED;
}

string GaussianParse::getTab() {
  ostringstream s;
  for (int i = 0; i < _itab; i++) {
    s << "    ";
  }

  return s.str();
}

BuiltinPtr GaussianParse::createBuiltin(Builtin::Kind kind, bool isUnsigned) {
  return std::make_shared<Builtin>(kind, isUnsigned);
}

VectorPtr GaussianParse::createVector(const TypePtr &ptr) { return std::make_shared<Vector>(ptr); }

MapPtr GaussianParse::createMap(const TypePtr &pleft, const TypePtr &pright) {
  return std::make_shared<Map>(pleft, pright);
}

void GaussianParse::addNamespacePtr(const NamespacePtr &nPtr) { _namespaces.push_back(nPtr); }

NamespacePtr GaussianParse::findNamespace(const string &id) {
  for (size_t i = 0; i < _namespaces.size(); i++) {
    if (_namespaces[i]->getId() == id) {
      return _namespaces[i];
    }
  }

  return NULL;
}

NamespacePtr GaussianParse::currentNamespace() { return _namespaces.back(); }

void GaussianParse::addStructPtr(const StructPtr &sPtr) { _structs.push_back(sPtr); }

void GaussianParse::addRosParamsPtr(const RosParamsPtr &rPtr) { _vec_ros_params.push_back(rPtr); }

void GaussianParse::addEnumPtr(const EnumPtr &ePtr) { _enums.push_back(ePtr); }

StructPtr GaussianParse::findStruct(const string &sid) {
  string ssid = sid;

  //在当前namespace中查找
  NamespacePtr np = currentNamespace();
  if (ssid.find("::") == string::npos) {
    ssid = np->getId() + "::" + ssid;
  }

  for (size_t i = 0; i < _structs.size(); i++) {
    if (_structs[i]->getSid() == ssid) {
      return _structs[i];
    }
  }

  return NULL;
}

EnumPtr GaussianParse::findEnum(const string &sid) {
  string ssid = sid;

  //在当前namespace中查找
  NamespacePtr np = currentNamespace();
  if (ssid.find("::") == string::npos) {
    ssid = np->getId() + "::" + sid;
  }

  for (size_t i = 0; i < _enums.size(); i++) {
    if (_enums[i]->getSid() == ssid) {
      return _enums[i];
    }
  }

  return NULL;
}

bool GaussianParse::checkEnum(const string &idName) {
  for (size_t i = 0; i < _enums.size(); i++) {
    vector<TypeIdPtr> &list = _enums[i]->getAllMemberPtr();

    for (size_t j = 0; j < list.size(); j++) {
      if (list[j]->getId() == idName) {
        return true;
      }
    }
  }

  return false;
}
void GaussianParse::checkConflict(const string &sid) {
  //是否和枚举重名
  if (findEnum(sid)) {
    error("conflicts with enum '" + sid + "'");
  }

  //是否和结构重名
  if (findStruct(sid)) {
    error("conflicts with struct '" + sid + "'");
  }
}

TypePtr GaussianParse::findUserType(const string &sid) {
  StructPtr sPtr = findStruct(sid);
  if (sPtr) return sPtr;

  EnumPtr ePtr = findEnum(sid);
  if (ePtr) return ePtr;

  return NULL;
}

ContainerPtr GaussianParse::currentContainer() { return _contains.top(); }

void GaussianParse::pushContainer(const ContainerPtr &c) {
  _contains.push(c);
  NamespacePtr np = std::dynamic_pointer_cast<Namespace>(c);
  if (np) {
    addNamespacePtr(np);
  }
}

ContainerPtr GaussianParse::popContainer() {
  ContainerPtr c = _contains.top();
  _contains.pop();

  return c;
}

void GaussianParse::checkTag(int i) {
  if (i >= 256) {
    error("struct memeber tag can't beyond 256");
  }
  if (i < 0) {
    error("struct memeber tag can't less then 0");
  }
}

void GaussianParse::checkSize(int i) {
  if (i >= 1024 * 1024) {
    error("struct memeber size can't beyond 1M");
  }
  if (i < 1) {
    error("struct memeber size can't less than 1");
  }
}

void GaussianParse::checkArrayVaid(TypePtr &tPtr, int size) {
  checkSize(size);
  //只有string/vector可以为array类型
  //vector不可以嵌套array类型 例如不允许vector<string:8>:2;

  VectorPtr vPtr = std::dynamic_pointer_cast<Vector>(tPtr);
  if (vPtr) {
    if (vPtr->getTypePtr()->isArray()) {
      error("fixed array type can not be nested");
    }
    return;
  }
  BuiltinPtr bPtr = std::dynamic_pointer_cast<Builtin>(tPtr);
  if (bPtr && bPtr->kind() == Builtin::KindString) {
    return;
  }
  error("only string or vector can use fix array");
}

void GaussianParse::checkPointerVaid(TypePtr &tPtr) {
  //必须为vector<Byte>类型

  VectorPtr vPtr = std::dynamic_pointer_cast<Vector>(tPtr);
  if (vPtr) {
    BuiltinPtr bPtr = std::dynamic_pointer_cast<Builtin>(vPtr->getTypePtr());
    if (bPtr && bPtr->kind() == Builtin::KindByte) return;
  }
  error("only 'byte *' can  be pointer type");
}

void GaussianParse::checkConstValue(TypeIdPtr &tPtr, int c) {
  //只有内建类型才能有缺省值
  BuiltinPtr bPtr = std::dynamic_pointer_cast<Builtin>(tPtr->getTypePtr());
  EnumPtr ePtr = std::dynamic_pointer_cast<Enum>(tPtr->getTypePtr());
  VectorPtr vPtr = std::dynamic_pointer_cast<Vector>(tPtr->getTypePtr());
  if (!bPtr && !ePtr && !vPtr) {
    error("only base/enum type can have default value");
  }

  if (ePtr) {
    if (c != ConstGrammar::VALUE && c != ConstGrammar::ENUM) {
      error("default value of enum only be int or enum_type");
    }

    return;
  }
  if (vPtr) {
    return;
  }

  int b = bPtr->kind();

  if (c == ConstGrammar::VALUE) {
    if (b == Builtin::KindBool) {
      error("default value of bool can only be true or false");
    }
    if (b == Builtin::KindString) {
      error("default value of string can only be \"string\"");
    }
  } else if (c == ConstGrammar::BOOL) {
    if (b != Builtin::KindBool) {
      error("only bool type can be true or false");
    }
  } else if (c == ConstGrammar::STRING) {
    if (b != Builtin::KindString) {
      error("only string type can be \"string\"");
    }
  }
}

string GaussianParse::printHeaderRemark() {
  ostringstream s;
  s << "// **********************************************************************" << endl;
  s << "// This file was generated by a GAUSSIAN parser!" << endl;
  s << "// GAUSSIAN version "
    << "GAUSSIAN_VERSION"
    << "." << endl;
  s << "// **********************************************************************" << endl;
  s << endl;

  return s.str();
}

string GaussianParse::getFileName(const string &fileName) {
  string tmpFileName = fileName;
  string::size_type pos = tmpFileName.rfind('/');
  if (pos != string::npos) {
    tmpFileName = tmpFileName.substr(pos + 1);
  } else {
    pos = tmpFileName.rfind('\\');
    if (pos != string::npos) {
      tmpFileName = tmpFileName.substr(pos + 1);
    }
  }

  return common::GS_File::excludeFileExt(tmpFileName);
}

string GaussianParse::replaceFileName(const string &fileName, const string &ext) {
  return common::GS_File::excludeFileExt(getFileName(fileName)) + "." + ext;
}

string GaussianParse::getAbsoluteFileName(const string &baseDir, const string &fileName) {
  return baseDir + FILE_SEP + fileName;
}
