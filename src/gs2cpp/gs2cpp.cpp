#include "gs2cpp.h"

#include <string>

#include "gs_common.h"
#include "gs_file.h"

#define TAB g_parse->getTab()
#define INC_TAB g_parse->incTab()
#define DEL_TAB g_parse->delTab()
#define G_TRACE_PARAM_OVER_MAX_LEN "\"{\\\"trace_param_over_max_len\\\":true}\""

//////////////////////////////////////////////////////////////////////////////////
//
Gaussian2Cpp::Gaussian2Cpp()
    : _checkDefault(false),
      _onlyStruct(false),
      _bSqlSupport(false),
      _bXmlSupport(false),
      _bJsonSupport(true),
      _namespace("gaussian") {}

string Gaussian2Cpp::writeToXml(const TypeIdPtr& pPtr) const {
  ostringstream s;
  if (std::dynamic_pointer_cast<Enum>(pPtr->getTypePtr())) {
    s << TAB << "p->value[\"" << pPtr->getId()
      << "\"] = " + _namespace + "::XmlOutput::writeXml((" + _namespace +
             "::Int32)"
      << pPtr->getId() << ", _cdata_format);" << endl;
  } else if (pPtr->getTypePtr()->isArray()) {
    s << TAB << "p->value[\"" << pPtr->getId()
      << "\"] = " + _namespace + "::XmlOutput::writeXml((const "
      << tostr(pPtr->getTypePtr()) << " *)" << pPtr->getId() << "Len"
      << ");" << endl;
  } else if (pPtr->getTypePtr()->isPointer()) {
    s << TAB << "p->value[\"" << pPtr->getId()
      << "\"] = " + _namespace + "::XmlOutput::writeXml((const "
      << tostr(pPtr->getTypePtr()) << " )" << pPtr->getId() << "Len"
      << ");" << endl;
  } else {
    MapPtr mPtr = std::dynamic_pointer_cast<Map>(pPtr->getTypePtr());
    VectorPtr vPtr = std::dynamic_pointer_cast<Vector>(pPtr->getTypePtr());
    if (!_checkDefault || pPtr->isRequire() ||
        (!pPtr->hasDefault() && !mPtr && !vPtr)) {
      BuiltinPtr bPtr = std::dynamic_pointer_cast<Builtin>(pPtr->getTypePtr());
      if (pPtr->getTypePtr()->isSimple() ||
          (bPtr && bPtr->kind() == Builtin::KindString)) {
        s << TAB << "p->value[\"" << pPtr->getId()
          << "\"] = " + _namespace + "::XmlOutput::writeXml(" << pPtr->getId()
          << ", _cdata_format);" << endl;
      } else {
        s << TAB << "p->value[\"" << pPtr->getId()
          << "\"] = " + _namespace + "::XmlOutput::writeXml(" << pPtr->getId()
          << ");" << endl;
      }
    } else {
      string sDefault = pPtr->def();
      BuiltinPtr bPtr = std::dynamic_pointer_cast<Builtin>(pPtr->getTypePtr());
      if (bPtr && bPtr->kind() == Builtin::KindString) {
        sDefault = "\"" + GS_Common::replace(pPtr->def(), "\"", "\\\"") + "\"";
      }

      if (mPtr || vPtr) {
        s << TAB << "if (" << pPtr->getId() << ".size() > 0)" << endl;
      } else {
        s << TAB << "if (" << pPtr->getId() << " != " << sDefault << ")"
          << endl;
      }

      s << TAB << "{" << endl;
      INC_TAB;
      s << TAB << "p->value[\"" << pPtr->getId()
        << "\"] = " + _namespace + "::XmlOutput::writeXml(" << pPtr->getId()
        << ");" << endl;
      DEL_TAB;
      s << TAB << "}" << endl;
    }
  }

  return s.str();
}

string Gaussian2Cpp::readFromXml(const TypeIdPtr& pPtr, bool bIsRequire) const {
  ostringstream s;
  if (std::dynamic_pointer_cast<Enum>(pPtr->getTypePtr())) {
    s << TAB << "common::XmlInput::readXml((common::Int32&)" << pPtr->getId()
      << ", pObj->value[\"" << pPtr->getId() << "\"]";
  } else if (pPtr->getTypePtr()->isArray()) {
    s << TAB << "common::XmlInput::readXml(" << pPtr->getId() << "Len"
      << ", pObj->value[\"" << pPtr->getId() << "\"]" << getSuffix(pPtr);
  } else if (pPtr->getTypePtr()->isPointer()) {
    // "not support";
  } else {
    s << TAB << "common::XmlInput::readXml(" << pPtr->getId()
      << ",pObj->value[\"" << pPtr->getId() << "\"]";
  }
  s << ", " << ((pPtr->isRequire() && bIsRequire) ? "true" : "false") << ");"
    << endl;

  return s.str();
}

string Gaussian2Cpp::writeToSql(const TypeIdPtr& pPtr) const {
  ostringstream s;
  if (std::dynamic_pointer_cast<Enum>(pPtr->getTypePtr())) {
    s << TAB << "_mycols[\"" << pPtr->getId()
      << "\"] = make_pair(common::GS_Mysql::DB_INT, common::GS_Common::tostr("
      << pPtr->getId() << "));" << endl;
  }

  BuiltinPtr bPtr = std::dynamic_pointer_cast<Builtin>(pPtr->getTypePtr());
  if (bPtr) {
    switch (bPtr->kind()) {
      case Builtin::KindBool:
      case Builtin::KindByte:
      case Builtin::KindShort:
      case Builtin::KindInt:
      case Builtin::KindLong:
        s << TAB << "_mycols[\"" << pPtr->getId()
          << "\"] = make_pair(common::GS_Mysql::DB_INT, "
             "common::GS_Common::tostr("
          << pPtr->getId() << "));" << endl;
        break;
      case Builtin::KindFloat:
      case Builtin::KindDouble:
        s << TAB << "_mycols[\"" << pPtr->getId()
          << "\"] = make_pair(common::GS_Mysql::DB_STR, "
             "common::GS_Common::tostr("
          << pPtr->getId() << "));" << endl;
        break;
      case Builtin::KindString:
        s << TAB << "_mycols[\"" << pPtr->getId()
          << "\"] = make_pair(common::GS_Mysql::DB_STR, "
             "common::GS_Common::trim("
          << pPtr->getId() << "));" << endl;
        break;
      default:
        break;
    }
  } else if (!pPtr->getTypePtr()->isSimple()) {
    s << TAB << "_mycols[\"" << pPtr->getId()
      << "\"] = make_pair(common::GS_Mysql::DB_STR, "
         "common::GS_Json::writeValue(common::JsonOutput::writeJson("
      << pPtr->getId() << ")));" << endl;
  }

  return s.str();
  return s.str();
}

string Gaussian2Cpp::readFromSql(const TypeIdPtr& pPtr, bool bIsRequire) const {
  ostringstream s;
  EnumPtr ePtr = std::dynamic_pointer_cast<Enum>(pPtr->getTypePtr());
  if (ePtr) {
    s << TAB << pPtr->getId() << " = (" << ePtr->getSid()
      << ")GS_Common::strto<common::Int32>(_mysrd[\"" << pPtr->getId()
      << "\"]);" << endl;
  }

  BuiltinPtr bPtr = std::dynamic_pointer_cast<Builtin>(pPtr->getTypePtr());
  if (bPtr) {
    switch (bPtr->kind()) {
      case Builtin::KindBool:
        s << TAB << pPtr->getId()
          << " = GS_Common::strto<common::Bool>(_mysrd[\"" << pPtr->getId()
          << "\"]);" << endl;
        break;
      case Builtin::KindByte:
        s << TAB << pPtr->getId() << " = GS_Common::strto<common::"
          << (bPtr->isUnsigned() ? "UInt8" : "Char") << ">(_mysrd[\""
          << pPtr->getId() << "\"]);" << endl;
        break;
      case Builtin::KindShort:
        s << TAB << pPtr->getId() << " = GS_Common::strto<common::"
          << (bPtr->isUnsigned() ? "UInt16" : "Short") << ">(_mysrd[\""
          << pPtr->getId() << "\"]);" << endl;
        break;
      case Builtin::KindInt:
        s << TAB << pPtr->getId() << " = GS_Common::strto<common::"
          << (bPtr->isUnsigned() ? "UInt32" : "Int32") << ">(_mysrd[\""
          << pPtr->getId() << "\"]);" << endl;
        break;
      case Builtin::KindLong:
        s << TAB << pPtr->getId() << " = GS_Common::strto<common::"
          << (bPtr->isUnsigned() ? "UInt64" : "Int64") << ">(_mysrd[\""
          << pPtr->getId() << "\"]);" << endl;
        break;
      case Builtin::KindFloat:
        s << TAB << pPtr->getId()
          << " = GS_Common::strto<common::Float>(_mysrd[\"" << pPtr->getId()
          << "\"]);" << endl;
        break;
      case Builtin::KindDouble:
        s << TAB << pPtr->getId()
          << " = GS_Common::strto<common::Double>(_mysrd[\"" << pPtr->getId()
          << "\"]);" << endl;
        break;
      case Builtin::KindString:
        s << TAB << pPtr->getId() << " = GS_Common::trim(_mysrd[\""
          << pPtr->getId() << "\"]);" << endl;
        break;
      default:
        break;
    }
  } else if (!pPtr->getTypePtr()->isSimple()) {
    s << TAB << "common::JsonInput::readJson(" << pPtr->getId()
      << ", common::GS_Json::getValue(_mysrd[\"" << pPtr->getId()
      << "\"]), false);" << endl;
  }

  return s.str();
}

string Gaussian2Cpp::writeToJson(const TypeIdPtr& pPtr) const {
  ostringstream s;
  if (std::dynamic_pointer_cast<Enum>(pPtr->getTypePtr())) {
    s << TAB << "p->value[\"" << pPtr->getId()
      << "\"] = " + _namespace + "::JsonOutput::writeJson((" + _namespace +
             "::Int32)"
      << pPtr->getId() << ");" << endl;
  } else if (pPtr->getTypePtr()->isArray()) {
    /*
        s << TAB << "p->value[\"" << pPtr->getId() << "\"] = " + _namespace +
       "::JsonOutput::writeJson((const "
            << tostr(pPtr->getTypePtr()) << " *)" << pPtr->getId() << "Len"  <<
       ");" << endl;
        */
    s << TAB << "p->value[\"" << pPtr->getId()
      << "\"] = " + _namespace + "::JsonOutput::writeJson((const "
      << tostr(pPtr->getTypePtr()) << " *)" << pPtr->getId() << ", "
      << pPtr->getId() << "Len"
      << ");" << endl;
  } else if (pPtr->getTypePtr()->isPointer()) {
    /*
        s << TAB << "p->value[\"" << pPtr->getId() << "\"] = " + _namespace +
       "::JsonOutput::writeJson((const "
            << tostr(pPtr->getTypePtr()) << " )" << pPtr->getId() << "Len"  <<
       ");" << endl;
        */
    s << TAB << "p->value[\"" << pPtr->getId()
      << "\"] = " + _namespace + "::JsonOutput::writeJson((const "
      << tostr(pPtr->getTypePtr()) << " )" << pPtr->getId() << ", "
      << pPtr->getId() << "Len"
      << ");" << endl;

  } else {
    MapPtr mPtr = std::dynamic_pointer_cast<Map>(pPtr->getTypePtr());
    VectorPtr vPtr = std::dynamic_pointer_cast<Vector>(pPtr->getTypePtr());

    // 对于json， 不检测默认值
    if (true || !_checkDefault || pPtr->isRequire() ||
        (!pPtr->hasDefault() && !mPtr && !vPtr)) {
      s << TAB << "p->value[\"" << pPtr->getId()
        << "\"] = " + _namespace + "::JsonOutput::writeJson(" << pPtr->getId()
        << ");" << endl;
    } else {
      string sDefault = pPtr->def();

      BuiltinPtr bPtr = std::dynamic_pointer_cast<Builtin>(pPtr->getTypePtr());
      if (bPtr && bPtr->kind() == Builtin::KindString) {
        sDefault =
            "\"" + common::GS_Common::replace(pPtr->def(), "\"", "\\\"") + "\"";
      }

      if (mPtr || vPtr) {
        s << TAB << "if (" << pPtr->getId() << ".size() > 0)" << endl;
      } else if (bPtr && (bPtr->kind() == Builtin::KindFloat ||
                          bPtr->kind() == Builtin::KindDouble)) {
        s << TAB << "if (!common::GS_Common::equal(" << pPtr->getId() << ","
          << sDefault << "))" << endl;
      } else {
        s << TAB << "if (" << pPtr->getId() << " != " << sDefault << ")"
          << endl;
      }

      s << TAB << "{" << endl;
      INC_TAB;
      s << TAB << "p->value[\"" << pPtr->getId()
        << "\"] = " + _namespace + "::JsonOutput::writeJson(" << pPtr->getId()
        << ");" << endl;
      DEL_TAB;
      s << TAB << "}" << endl;
    }
  }

  return s.str();
}

string Gaussian2Cpp::readFromJson(const TypeIdPtr& pPtr,
                                  bool bIsRequire) const {
  ostringstream s;
  // if (std::dynamic_pointer_cast<Enum>(pPtr->getTypePtr()))
  // {
  //     s << TAB << _namespace + "::JsonInput::readJson((" + _namespace +
  //     "::Int32&)" << pPtr->getId() << ",pObj->value[\"" << pPtr->getId() <<
  //     "\"]";
  // }
  // else

  if (pPtr->getTypePtr()->isArray()) {
    // s << TAB << _namespace + "::JsonInput::readJson(" << pPtr->getId() <<
    // "Len" << ",pObj->value[\"" << pPtr->getId() << "\"]" << getSuffix(pPtr);
    s << TAB << _namespace + "::JsonInput::readJson(" << pPtr->getId() << ", "
      << "sizeof(" + pPtr->getId() + ")"
      << ", " << pPtr->getId() << "Len"
      << ", pObj->value[\"" << pPtr->getId() << "\"]";
  } else if (pPtr->getTypePtr()->isPointer()) {
#if 0
        s << TAB << pPtr->getId() <<" = ("<<tostr(pPtr->getTypePtr())<<")_is.cur();"<<endl;
        s << TAB << "_is.read("<< pPtr->getId()<<", _is.left(), "<< pPtr->getId() << "Len";
#endif
    s << TAB << "not support";
  } else {
    s << TAB << _namespace + "::JsonInput::readJson(" << pPtr->getId()
      << ",pObj->value[\"" << pPtr->getId() << "\"]";
  }
  s << ", " << ((pPtr->isRequire() && bIsRequire) ? "true" : "false") << ");"
    << endl;

#if 0
    if(pPtr->getTypePtr()->isPointer())
    s << TAB <<"_is.mapBufferSkip("<<pPtr->getId() << "Len);"<<endl;
#endif

  return s.str();
}

string Gaussian2Cpp::writeTo(const TypeIdPtr& pPtr) const {
  ostringstream s;
  if (std::dynamic_pointer_cast<Enum>(pPtr->getTypePtr())) {
    s << TAB << "_os.write((" + _namespace + "::Int32)" << pPtr->getId() << ", "
      << pPtr->getTag() << ");" << endl;
  } else if (pPtr->getTypePtr()->isArray()) {
    s << TAB << "_os.write((const " << tostr(pPtr->getTypePtr()) << " *)"
      << pPtr->getId() << ", " << pPtr->getId() << "Len"
      << ", " << pPtr->getTag() << ");" << endl;
  } else if (pPtr->getTypePtr()->isPointer()) {
    s << TAB << "_os.write((const " << tostr(pPtr->getTypePtr()) << ")"
      << pPtr->getId() << ", " << pPtr->getId() << "Len"
      << ", " << pPtr->getTag() << ");" << endl;
  } else {
    MapPtr mPtr = std::dynamic_pointer_cast<Map>(pPtr->getTypePtr());
    VectorPtr vPtr = std::dynamic_pointer_cast<Vector>(pPtr->getTypePtr());

    if (!_checkDefault || pPtr->isRequire() ||
        (!pPtr->hasDefault() && !mPtr && !vPtr)) {
      s << TAB << "_os.write(" << pPtr->getId() << ", " << pPtr->getTag()
        << ");" << endl;
    } else {
      string sDefault = pPtr->def();

      BuiltinPtr bPtr = std::dynamic_pointer_cast<Builtin>(pPtr->getTypePtr());
      if (bPtr && bPtr->kind() == Builtin::KindString) {
        sDefault =
            "\"" + common::GS_Common::replace(pPtr->def(), "\"", "\\\"") + "\"";
      }

      if (mPtr || vPtr) {
        s << TAB << "if (" << pPtr->getId() << ".size() > 0)" << endl;
      } else {
        s << TAB << "if (" << pPtr->getId() << " != " << sDefault << ")"
          << endl;
      }

      s << TAB << "{" << endl;
      INC_TAB;
      s << TAB << "_os.write(" << pPtr->getId() << ", " << pPtr->getTag()
        << ");" << endl;
      DEL_TAB;
      s << TAB << "}" << endl;
    }
  }

  return s.str();
}

string Gaussian2Cpp::readFrom(const TypeIdPtr& pPtr, bool bIsRequire) const {
  ostringstream s;
  if (std::dynamic_pointer_cast<Enum>(pPtr->getTypePtr())) {
    //枚举强制类型转换在O2编译选项情况下会告警
    string tmp = _namespace + "::Int32 eTemp" +
                 GS_Common::tostr(pPtr->getTag()) + generateInitValue(pPtr);

    s << TAB << tmp << endl;
    s << TAB << "_is.read(eTemp" << GS_Common::tostr(pPtr->getTag());
  } else if (pPtr->getTypePtr()->isArray()) {
    // s << TAB << "_is.read(" << pPtr->getId() << ", " << getSuffix(pPtr) << ",
    // " << pPtr->getId() << "Len";
    s << TAB << "_is.read(" << pPtr->getId() << ", "
      << "sizeof(" + pPtr->getId() + ")"
      << ", " << pPtr->getId() << "Len";
  } else if (pPtr->getTypePtr()->isPointer()) {
    s << TAB << pPtr->getId() << " = (" << tostr(pPtr->getTypePtr())
      << ")_is.cur();" << endl;
    s << TAB << "_is.read(" << pPtr->getId() << ", _is.left(), "
      << pPtr->getId() << "Len";
  } else {
    s << TAB << "_is.read(" << pPtr->getId();
  }

  s << ", " << pPtr->getTag() << ", "
    << ((pPtr->isRequire() && bIsRequire) ? "true" : "false") << ");" << endl;

  if (std::dynamic_pointer_cast<Enum>(pPtr->getTypePtr())) {
    s << TAB << pPtr->getId() << " = (" << tostr(pPtr->getTypePtr()) << ")eTemp"
      << GS_Common::tostr(pPtr->getTag()) << ";" << endl;
  }

  if (pPtr->getTypePtr()->isPointer())
    s << TAB << "_is.mapBufferSkip(" << pPtr->getId() << "Len);" << endl;

  return s.str();
}

// string Gaussian2Cpp::readUnknown(const TypeIdPtr& pPtr) const
// {
//     ostringstream s;
//     s << TAB << "_is.readUnknown(sUnknownField, " <<  pPtr->getTag() << ");"
//     << endl; return s.str();
// }
// string Gaussian2Cpp::writeUnknown() const
// {
//     ostringstream s;
//     s << TAB << "_os.writeUnknown(sUnknownField);" << endl;
//     return s.str();
// }

string Gaussian2Cpp::display(const TypeIdPtr& pPtr) const {
  ostringstream s;
  if (std::dynamic_pointer_cast<Enum>(pPtr->getTypePtr())) {
    s << TAB << "_ds.display((" + _namespace + "::Int32)" << pPtr->getId()
      << ",\"" << pPtr->getId() << "\");" << endl;
    ;
  } else if (pPtr->getTypePtr()->isArray() || pPtr->getTypePtr()->isPointer()) {
    s << TAB << "_ds.display(" << pPtr->getId() << ", " << pPtr->getId()
      << "Len"
      << ",\"" << pPtr->getId() << "\");" << endl;
  } else {
    s << TAB << "_ds.display(" << pPtr->getId() << ",\"" << pPtr->getId()
      << "\");" << endl;
    ;
  }

  return s.str();
}

string Gaussian2Cpp::displaySimple(const TypeIdPtr& pPtr, bool bSep) const {
  ostringstream s;
  if (std::dynamic_pointer_cast<Enum>(pPtr->getTypePtr())) {
    s << TAB << "_ds.displaySimple((" + _namespace + "::Int32)" << pPtr->getId()
      << ", " << (bSep ? "true" : "false") << ");" << endl;
  } else if (pPtr->getTypePtr()->isArray()) {
    s << TAB << "_ds.displaySimple(" << pPtr->getId() << ", " << pPtr->getId()
      << "Len"
      << "," << (bSep ? "true" : "false") << ");" << endl;
  } else if (pPtr->getTypePtr()->isPointer()) {
    s << TAB << "_ds.displaySimple(";
    s << (bSep ? "" : ("(const " + tostr(pPtr->getTypePtr()) + ")"));
    s << pPtr->getId() << ", " << pPtr->getId() << "Len"
      << "," << (bSep ? "true" : "false") << ");" << endl;
  } else {
    s << TAB << "_ds.displaySimple(" << pPtr->getId() << ", "
      << (bSep ? "true" : "false") << ");" << endl;
  }

  return s.str();
}

string Gaussian2Cpp::generateCollection(const TypeIdPtr& pPtr,
                                        bool bSep) const {
  ostringstream s;
  if (pPtr->getTypePtr()->isArray()) {
    s << TAB << "_jj.generateCollection("
      << "\"" << pPtr->getId() << "\""
      << ", " << pPtr->getId() << ", " << pPtr->getId() << "Len"
      << ");"
      << "\n"
      << (bSep ? TAB + "_jj.append(\",\", false);" : "") << endl;
  } else {
    s << TAB << "_jj.generateCollection("
      << "\"" << pPtr->getId() << "\""
      << ", " << pPtr->getId() << ");"
      << "\n"
      << (bSep ? TAB + "_jj.append(\",\", false);" : "") << endl;
  }

  return s.str();
}

/*******************************获取定长数组坐标********************************/
int Gaussian2Cpp::getSuffix(const TypeIdPtr& pPtr) const {
  BuiltinPtr bPtr = std::dynamic_pointer_cast<Builtin>(pPtr->getTypePtr());
  if (bPtr && bPtr->kind() == Builtin::KindString && bPtr->isArray()) {
    return bPtr->getSize();
  }

  VectorPtr vPtr = std::dynamic_pointer_cast<Vector>(pPtr->getTypePtr());
  if (vPtr && vPtr->isArray()) {
    return vPtr->getSize();
  }

  return -1;
}

/*******************************定长数组坐标********************************/

string Gaussian2Cpp::toStrSuffix(const TypeIdPtr& pPtr) const {
  ostringstream s;

  int i = getSuffix(pPtr);

  if (i >= 0) {
    s << "[" << i << "]";
  }
  return s.str();
}
/*******************************BuiltinPtr********************************/

string Gaussian2Cpp::tostr(const TypePtr& pPtr) const {
  BuiltinPtr bPtr = std::dynamic_pointer_cast<Builtin>(pPtr);
  if (bPtr) return tostrBuiltin(bPtr);

  VectorPtr vPtr = std::dynamic_pointer_cast<Vector>(pPtr);
  if (vPtr) return tostrVector(vPtr);

  MapPtr mPtr = std::dynamic_pointer_cast<Map>(pPtr);
  if (mPtr) return tostrMap(mPtr);

  StructPtr sPtr = std::dynamic_pointer_cast<Struct>(pPtr);
  if (sPtr) return tostrStruct(sPtr);

  EnumPtr ePtr = std::dynamic_pointer_cast<Enum>(pPtr);
  if (ePtr) return tostrEnum(ePtr);

  if (!pPtr) return "void";

  assert(false);
  return "";
}

string Gaussian2Cpp::tostrBuiltin(const BuiltinPtr& pPtr) const {
  string s;

  switch (pPtr->kind()) {
    case Builtin::KindBool:
      s = "bool";
      break;
    case Builtin::KindByte:
      s = "char";
      break;
    case Builtin::KindShort:
      //为了兼容java无unsigned, 编解码时把gaussian文件中 unsigned char
      //对应到short c++中需要还原回来
      s = (pPtr->isUnsigned() ? _namespace + "::UInt8"
                              : _namespace + "::Short");
      break;
    case Builtin::KindInt:
      s = ("int32_t");
      break;
    case Builtin::KindLong:
      s = (pPtr->isUnsigned() ? _namespace + "::" + "UInt32"
                              : _namespace + "::Int64");
      break;
    case Builtin::KindFloat:
      s = "float";
      break;
    case Builtin::KindDouble:
      s = "double";
      break;
    case Builtin::KindString:
      if (pPtr->isArray())
        s = _namespace + "::Char";  // char a [8];
      else
        s = "std::string";  // string a;
      break;
    case Builtin::KindVector:
      s = "std::vector";
      break;
    case Builtin::KindMap:
      s = "std::map";
      break;
    default:
      assert(false);
      break;
  }

  return s;
}
/*******************************VectorPtr********************************/
string Gaussian2Cpp::tostrVector(const VectorPtr& pPtr) const {
  //数组类型
  if (pPtr->isArray()) {
    return tostr(pPtr->getTypePtr());
  }

  //指针类型
  if (pPtr->isPointer()) {
    return tostr(pPtr->getTypePtr()) + " *";
  }

  string s = Builtin::builtinTable[Builtin::KindVector] + string("<") +
             tostr(pPtr->getTypePtr());

  if (std::dynamic_pointer_cast<Map>(pPtr->getTypePtr()) ||
      std::dynamic_pointer_cast<Vector>(pPtr->getTypePtr())) {
    s += " >";
  } else {
    s += ">";
  }
  return s;
}
/*******************************MapPtr********************************/
string Gaussian2Cpp::tostrMap(const MapPtr& pPtr) const {
  string s = Builtin::builtinTable[Builtin::KindMap] + string("<") +
             tostr(pPtr->getLeftTypePtr()) + ", " +
             tostr(pPtr->getRightTypePtr());
  if (std::dynamic_pointer_cast<Map>(pPtr->getRightTypePtr()) ||
      std::dynamic_pointer_cast<Vector>(pPtr->getRightTypePtr())) {
    s += " >";
  } else {
    s += ">";
  }
  return s;
}

/*******************************StructPtr********************************/
string Gaussian2Cpp::tostrStruct(const StructPtr& pPtr) const {
  return pPtr->getSid();
}

// string Gaussian2Cpp::MD5(const StructPtr& pPtr) const {
//  string s;
//  vector<TypeIdPtr>& member = pPtr->getAllMemberPtr();
//  for (size_t j = 0; j < member.size(); j++) {
//    s += "_" + tostr(member[j]->getTypePtr());
//  }
//
//  return "\"" + common::GS_MD5::md5str(s) + "\"";
//}

/////////////////////////////////////////////////////////////////////
string Gaussian2Cpp::tostrEnum(const EnumPtr& pPtr) const {
  return pPtr->getSid();
}
///////////////////////////////////////////////////////////////////////
string Gaussian2Cpp::generateH(const StructPtr& pPtr,
                               const string& namespaceId) const {
  ostringstream s;

  s << TAB << "struct " << pPtr->getId()
    << " : public " + _namespace + "::GaussianStructBase" << endl;
  s << TAB << "{" << endl;

  s << TAB << "public:" << endl;

  INC_TAB;

  s << TAB << "static string className()" << endl;
  s << TAB << "{" << endl;
  INC_TAB;
  s << TAB << "return "
    << "\"" << namespaceId << "." << pPtr->getId() << "\""
    << ";" << endl;
  DEL_TAB;
  s << TAB << "}" << endl;
  // s << TAB << "static string MD5()" << endl;
  // s << TAB << "{" << endl;
  // INC_TAB;
  // s << TAB << "return " << MD5(pPtr) << ";" << endl;
  // DEL_TAB;
  // s << TAB << "}" << endl;

  ////////////////////////////////////////////////////////////
  //定义缺省构造函数
  s << TAB << pPtr->getId() << "()" << endl;
  s << TAB << "{" << endl;
  INC_TAB;
  s << TAB << "resetDefautlt();" << endl;
  vector<TypeIdPtr>& member = pPtr->getAllMemberPtr();

  if (_bXmlSupport) {
    s << TAB << "_cdata_format = false;" << endl;
  }

  DEL_TAB;
  s << TAB << "}" << endl;

  // resetDefault()函数
  s << TAB << "void resetDefautlt()" << endl;
  s << TAB << "{" << endl;
  INC_TAB;

  member = pPtr->getAllMemberPtr();
  for (size_t j = 0; j < member.size(); j++) {
    if (member[j]->getTypePtr()->isArray()) {
      s << TAB << member[j]->getId() << "Len = 0;" << endl;
      VectorPtr vPtr =
          std::dynamic_pointer_cast<Vector>(member[j]->getTypePtr());
      if (vPtr) {
        BuiltinPtr bPtr =
            std::dynamic_pointer_cast<Builtin>(vPtr->getTypePtr());
        if (bPtr &&
            bPtr->kind() !=
                Builtin::KindString)  //非内建类型或者string 类型不能memset
        {
          s << TAB << "memset(" << member[j]->getId() << ", 0, "
            << "sizeof(" << member[j]->getId() << "));" << endl;
        }
      }
      continue;
    }

    if (member[j]->getTypePtr()->isPointer()) {
      s << TAB << member[j]->getId() << "Len = 0;" << endl;
      s << TAB << member[j]->getId() << " = NULL;" << endl;
      continue;
    }

    VectorPtr vPtr = std::dynamic_pointer_cast<Vector>(member[j]->getTypePtr());
    MapPtr mPtr = std::dynamic_pointer_cast<Map>(member[j]->getTypePtr());
    // 如果是vector或者map，reset时需要调用clear方法
    if (vPtr || mPtr) {
      s << TAB << member[j]->getId() << ".clear();" << endl;
      continue;
    }

    StructPtr sPtr = std::dynamic_pointer_cast<Struct>(member[j]->getTypePtr());
    // 如果是结构体，那么需要调用resetDefautlt方法
    if (sPtr) {
      s << TAB << member[j]->getId() << ".resetDefautlt();" << endl;
      continue;
    }

    if (member[j]->hasDefault()) {
      BuiltinPtr bPtr =
          std::dynamic_pointer_cast<Builtin>(member[j]->getTypePtr());
      // string值要转义
      if (bPtr && bPtr->kind() == Builtin::KindString) {
        string tmp = common::GS_Common::replace(member[j]->def(), "\"", "\\\"");
        s << TAB << member[j]->getId() << " = \"" << tmp << "\";" << endl;
      } else {
        s << TAB << member[j]->getId() << " = " << member[j]->def() << ";"
          << endl;
      }
    } else {  //没有提供初始值才会走到这里,提供枚举类型初始化值
      EnumPtr ePtr = std::dynamic_pointer_cast<Enum>(member[j]->getTypePtr());
      if (ePtr) {
        vector<TypeIdPtr>& eMember = ePtr->getAllMemberPtr();
        if (eMember.size() > 0) {
          string sid = ePtr->getSid();
          s << TAB << member[j]->getId() << " = "
            << sid.substr(0, sid.find_first_of("::"))
            << "::" << eMember[0]->getId() << ";" << endl;
        }
      }
    }
  }

  DEL_TAB;
  s << TAB << "}" << endl;

  s << TAB << "template<typename WriterT>" << endl;
  s << TAB
    << "void writeTo(" + _namespace +
           "::GaussianOutputStream<WriterT>& _os) const"
    << endl;
  s << TAB << "{" << endl;
  INC_TAB;
  for (size_t j = 0; j < member.size(); j++) {
    s << writeTo(member[j]);
  }
  // if (_unknownField)
  // {
  // 	s << writeUnknown();
  // }
  DEL_TAB;
  s << TAB << "}" << endl;

  ///////////////////////////////////////////////////////////
  s << TAB << "template<typename ReaderT>" << endl;
  s << TAB
    << "void readFrom(" + _namespace + "::GaussianInputStream<ReaderT>& _is)"
    << endl;
  s << TAB << "{" << endl;
  INC_TAB;
  s << TAB << "resetDefautlt();" << endl;
  for (size_t j = 0; j < member.size(); j++) {
    s << readFrom(member[j]);
  }
  // if (_unknownField)
  // {
  //     s << readUnknown(member[member.size() - 1]);
  // }

  DEL_TAB;
  s << TAB << "}" << endl;

  if (_bJsonSupport) {
    s << TAB << "common::JsonValueObjPtr writeToJson() const" << endl;
    s << TAB << "{" << endl;
    INC_TAB;
    s << TAB
      << "common::JsonValueObjPtr p = std::make_shared<common::JsonValueObj>();"
      << endl;
    for (size_t j = 0; j < member.size(); j++) {
      s << writeToJson(member[j]);
    }
    s << TAB << "return p;" << endl;
    DEL_TAB;
    s << TAB << "}" << endl;

    s << TAB << "string writeToJsonString() const" << endl;
    s << TAB << "{" << endl;
    INC_TAB;
    s << TAB << "return common::GS_Json::writeValue(writeToJson());" << endl;
    DEL_TAB;
    s << TAB << "}" << endl;

    s << TAB
      << "void readFromJson(const common::JsonValuePtr & p, bool isRequire = "
         "true)"
      << endl;
    s << TAB << "{" << endl;
    INC_TAB;
    s << TAB << "resetDefautlt();" << endl;
    s << TAB << "if(NULL == p.get() || p->getType() != common::eJsonTypeObj)"
      << endl;
    s << TAB << "{" << endl;
    INC_TAB;
    s << TAB << "char s[128];" << endl;
    s << TAB
      << "snprintf(s, sizeof(s), \"read 'struct' type mismatch, get type: "
         "%d.\", (p.get() ? p->getType() : 0));"
      << endl;
    s << TAB << "throw common::GS_Json_Exception(s);" << endl;
    DEL_TAB;
    s << TAB << "}" << endl;
    s << TAB
      << "common::JsonValueObjPtr "
         "pObj=std::dynamic_pointer_cast<common::JsonValueObj>(p);"
      << endl;
    for (size_t j = 0; j < member.size(); j++) {
      s << readFromJson(member[j]);
    }
    DEL_TAB;
    s << TAB << "}" << endl;

    s << TAB << "void readFromJsonString(const string & str)" << endl;
    s << TAB << "{" << endl;
    INC_TAB;
    s << TAB << "readFromJson(common::GS_Json::getValue(str));" << endl;
    DEL_TAB;
    s << TAB << "}" << endl;
  }

  if (_bXmlSupport) {
    s << TAB << "void setXmlFormat(bool cdata = false)" << endl;
    s << TAB << "{" << endl;
    INC_TAB;
    s << TAB << "_cdata_format = cdata;" << endl;
    DEL_TAB;
    s << TAB << "}" << endl;

    s << TAB << "common::XmlValueObjPtr writeToXml() const" << endl;
    s << TAB << "{" << endl;
    INC_TAB;
    s << TAB
      << "common::XmlValueObjPtr p = std::make_shared<common::XmlValueObj>();"
      << endl;
    for (size_t j = 0; j < member.size(); j++) {
      s << writeToXml(member[j]);
    }
    s << TAB << "return p;" << endl;
    DEL_TAB;
    s << TAB << "}" << endl;

    s << TAB << "string writeToXmlString() const" << endl;
    s << TAB << "{" << endl;
    INC_TAB;
    s << TAB << "return common::GS_Xml::writeValue(writeToXml());" << endl;
    DEL_TAB;
    s << TAB << "}" << endl;

    s << TAB
      << "void readFromXml(const common::XmlValuePtr & p, bool isRequire = "
         "true)"
      << endl;
    s << TAB << "{" << endl;
    INC_TAB;
    s << TAB << "resetDefautlt();" << endl;
    s << TAB << "if(NULL == p.get() || p->getType() != eXmlTypeObj)" << endl;
    s << TAB << "{" << endl;
    INC_TAB;
    s << TAB << "char s[128];" << endl;
    s << TAB
      << "snprintf(s, sizeof(s), \"read 'struct' type mismatch, get type: "
         "%d.\", p->getType());"
      << endl;
    s << TAB << "throw GS_Xml_Exception(s);" << endl;
    DEL_TAB;
    s << TAB << "}" << endl;
    s << TAB
      << "common::XmlValueObjPtr pObj= "
         "std::dynamic_pointer_cast<common::XmlValueObj>(p);"
      << endl;
    for (size_t j = 0; j < member.size(); j++) {
      s << readFromXml(member[j]);
    }
    DEL_TAB;
    s << TAB << "}" << endl;

    s << TAB << "void readFromXmlString(const string & str)" << endl;
    s << TAB << "{" << endl;
    INC_TAB;
    s << TAB << "readFromXml(common::GS_Xml::getValue(str));" << endl;
    DEL_TAB;
    s << TAB << "}" << endl;
  }

  if (_bSqlSupport) {
    s << TAB
      << "common::GS_Mysql::RECORD_DATA& toSql(common::GS_Mysql::RECORD_DATA& "
         "_mycols) const"
      << endl;
    s << TAB << "{" << endl;
    INC_TAB;
    for (size_t j = 0; j < member.size(); j++) {
      s << writeToSql(member[j]);
    }
    s << TAB << "return _mycols;" << endl;
    DEL_TAB;
    s << TAB << "}" << endl;
    s << TAB << "void fromSql(common::GS_Mysql::MysqlRecord& _mysrd)" << endl;
    s << TAB << "{" << endl;
    INC_TAB;
    s << TAB << "resetDefautlt();" << endl;
    for (size_t j = 0; j < member.size(); j++) {
      s << readFromSql(member[j]);
    }
    DEL_TAB;
    s << TAB << "}" << endl;
  }

  s << TAB << "ostream& display(ostream& _os, int _level=0) const" << endl;
  s << TAB << "{" << endl;
  INC_TAB;
  s << TAB << _namespace + "::GaussianDisplayer _ds(_os, _level);" << endl;

  for (size_t j = 0; j < member.size(); j++) {
    s << display(member[j]);
  }
  s << TAB << "return _os;" << endl;
  DEL_TAB;
  s << TAB << "}" << endl;

  s << TAB << "ostream& displaySimple(ostream& _os, int _level=0) const"
    << endl;
  s << TAB << "{" << endl;
  INC_TAB;
  s << TAB << _namespace + "::GaussianDisplayer _ds(_os, _level);" << endl;

  for (size_t j = 0; j < member.size(); j++) {
    s << displaySimple(member[j], (j != member.size() - 1 ? true : false));
  }
  s << TAB << "return _os;" << endl;
  DEL_TAB;
  s << TAB << "}" << endl;

  DEL_TAB;
  s << TAB << "public:" << endl;
  INC_TAB;

  //定义成员变量
  for (size_t j = 0; j < member.size(); j++) {
    if (member[j]->getTypePtr()->isArray() ||
        member[j]->getTypePtr()->isPointer())  //数组类型、指针类型需要定义长度
    {
      s << TAB << _namespace + "::"
        << "UInt32 " << member[j]->getId() << "Len"
        << ";" << endl;
    }
    s << TAB << tostr(member[j]->getTypePtr()) << " " << member[j]->getId()
      << toStrSuffix(member[j]) << ";" << endl;
  }

  if (_bXmlSupport) {
    DEL_TAB;
    s << TAB << "private:" << endl;
    INC_TAB;
    s << TAB << "bool _cdata_format;" << endl;
  }

  // if  (_unknownField)
  // {
  //     s << TAB << "std::string sUnknownField;" << endl;
  // }
  DEL_TAB;
  s << TAB << "};" << endl;

  //定义==操作
  s << TAB << "inline bool operator==(const " << pPtr->getId() << "&l, const "
    << pPtr->getId() << "&r)" << endl;
  s << TAB << "{" << endl;
  INC_TAB;
  s << TAB << "return ";
  for (size_t j = 0; j < member.size(); j++) {
    if (member[j]->getTypePtr()->isArray() ||
        member[j]->getTypePtr()->isPointer())  //数组类型、指针类型
    {
      s << "!memcmp(l." << member[j]->getId() << ",r." << member[j]->getId()
        << ",l." << member[j]->getId() << "Len)";
    } else {
      BuiltinPtr bPtr =
          std::dynamic_pointer_cast<Builtin>(member[j]->getTypePtr());
      MapPtr mPtr = std::dynamic_pointer_cast<Map>(member[j]->getTypePtr());
      VectorPtr vPtr =
          std::dynamic_pointer_cast<Vector>(member[j]->getTypePtr());

      bool mapDouble = false;
      if (mPtr) {
        {
          BuiltinPtr innerPtr =
              std::dynamic_pointer_cast<Builtin>(mPtr->getLeftTypePtr());
          if (innerPtr && (innerPtr->kind() == Builtin::KindFloat ||
                           innerPtr->kind() == Builtin::KindDouble)) {
            mapDouble = true;
          }
        }
        {
          BuiltinPtr innerPtr =
              std::dynamic_pointer_cast<Builtin>(mPtr->getRightTypePtr());
          if (innerPtr && (innerPtr->kind() == Builtin::KindFloat ||
                           innerPtr->kind() == Builtin::KindDouble)) {
            mapDouble = true;
          }
        }
      }
      bool vecDouble = false;
      // vector比较
      if (vPtr) {
        BuiltinPtr innerPtr =
            std::dynamic_pointer_cast<Builtin>(vPtr->getTypePtr());
        if (innerPtr && (innerPtr->kind() == Builtin::KindFloat ||
                         innerPtr->kind() == Builtin::KindDouble)) {
          vecDouble = true;
        }
      }
      if (mapDouble || vecDouble) {
        s << "common::GS_Common::equal("
          << "l." << member[j]->getId() << ","
          << "r." << member[j]->getId() << ")";
      } else if (bPtr && (bPtr->kind() == Builtin::KindFloat ||
                          bPtr->kind() == Builtin::KindDouble)) {
        s << "common::GS_Common::equal("
          << "l." << member[j]->getId() << ","
          << "r." << member[j]->getId() << ")";
      } else {
        s << "l." << member[j]->getId() << " == r." << member[j]->getId();
      }
      // s << "l." << member[j]->getId() << " == r." << member[j]->getId();
    }
    if (j != member.size() - 1) {
      s << " && ";
    }
  }
  s << ";" << endl;
  DEL_TAB;
  s << TAB << "}" << endl;

  //定义!=
  s << TAB << "inline bool operator!=(const " << pPtr->getId() << "&l, const "
    << pPtr->getId() << "&r)" << endl;
  s << TAB << "{" << endl;
  INC_TAB;
  s << TAB << "return !(l == r);" << endl;
  DEL_TAB;
  s << TAB << "}" << endl;

  //定义 << >>
  if (_bJsonSupport) {
    //重载 <<
    s << TAB << "inline ostream& operator<<(ostream & os,const "
      << pPtr->getId() << "&r)" << endl;
    s << TAB << "{" << endl;
    INC_TAB;
    s << TAB << "os << r.writeToJsonString();" << endl;
    s << TAB << "return os;" << endl;
    DEL_TAB;
    s << TAB << "}" << endl;

    //重载 >>
    s << TAB << "inline istream& operator>>(istream& is," << pPtr->getId()
      << "&l)" << endl;
    s << TAB << "{" << endl;
    INC_TAB;
    s << TAB << "std::istreambuf_iterator<char> eos;" << endl;
    s << TAB << "std::string s(std::istreambuf_iterator<char>(is), eos);"
      << endl;
    s << TAB << "l.readFromJsonString(s);" << endl;
    s << TAB << "return is;" << endl;
    DEL_TAB;
    s << TAB << "}" << endl;
  }

  vector<string> key = pPtr->getKey();
  //定义<
  if (key.size() > 0) {
    s << TAB << "inline bool operator<(const " << pPtr->getId() << "&l, const "
      << pPtr->getId() << "&r)" << endl;
    s << TAB << "{" << endl;
    INC_TAB;
    for (size_t i = 0; i < key.size(); i++) {
      s << TAB << "if(l." << key[i] << " != r." << key[i] << ") ";
      for (size_t z = 0; z < member.size(); z++) {
        if (key[i] == member[z]->getId() &&
            (member[z]->getTypePtr()->isArray() ||
             member[z]->getTypePtr()->isPointer()))  //数组类型、指针类型
        {
          s << "memcmp(l." << key[i] << ",r." << key[i] << ",l." << key[i]
            << "Len)< 0";
        }
      }
      s << " return (l." << key[i] << " < r." << key[i] << ");" << endl;
    }

    s << TAB << "return false;" << endl;
    DEL_TAB;
    s << TAB << "}" << endl;

    //定义<=
    s << TAB << "inline bool operator<=(const " << pPtr->getId() << "&l, const "
      << pPtr->getId() << "&r)" << endl;
    s << TAB << "{" << endl;
    INC_TAB;
    s << TAB << "return !(r < l);" << endl;
    DEL_TAB;
    s << TAB << "}" << endl;

    //定义>
    s << TAB << "inline bool operator>(const " << pPtr->getId() << "&l, const "
      << pPtr->getId() << "&r)" << endl;
    s << TAB << "{" << endl;
    INC_TAB;
    s << TAB << "return r < l;" << endl;
    DEL_TAB;
    s << TAB << "}" << endl;

    //定义>=
    s << TAB << "inline bool operator>=(const " << pPtr->getId() << "&l, const "
      << pPtr->getId() << "&r)" << endl;
    s << TAB << "{" << endl;
    INC_TAB;
    s << TAB << "return !(l < r);" << endl;
    DEL_TAB;
    s << TAB << "}" << endl;
  }

  return s.str();
}

string Gaussian2Cpp::generateH(const RosParamsPtr& rPtr) const {
  ostringstream s;
  DEL_TAB;
  s << TAB << "#define DEF_ROS_PARAM(type, name) \\" << endl;
  s << TAB << " public:                          \\" << endl;
  INC_TAB;
  s << TAB << "  const type name() { return this->Get<type>(#name); }" << endl;
  DEL_TAB;
  s << endl;

  s << TAB << "#define DEF_ROS_ARRAY_PARAM(type, name) \\" << endl;
  s << TAB << " public:                                \\" << endl;
  INC_TAB;
  s << TAB
    << "  const std::vector<type> name() { return this->GetArray<type>(#name); "
       "}"
    << endl;
  DEL_TAB;
  s << endl;

  s << TAB << "class DeviceController;" << endl;
  s << TAB << "class " << rPtr->getId() << " : public gsf::Counter" << endl;
  s << TAB << "{" << endl;
  s << TAB << "public:" << endl;
  INC_TAB;
  s << TAB << "explicit " << rPtr->getId()
    << "(DeviceController* const dev_ctrl) : dev_ctrl_(dev_ctrl) {}" << endl;
  s << TAB << "~" << rPtr->getId() << "() = default;" << endl;
  s << endl;

  s << TAB << "void Startup();" << endl;
  s << TAB << "void ExtraPatch();" << endl;
  // INC_TAB;
  // s << TAB << "auto& platform = dev_ctrl_->GetPlatform();" << endl;
  // s << TAB << "ros_params_ptr_ =
  // boost::dynamic_pointer_cast<common::RosParameters>(platform.GetParameters());"
  // << endl; s << TAB << "LoadParam();" << endl; DEL_TAB; s << TAB << "}" <<
  // endl;
  s << TAB << "void Cleanup() {}" << endl;
  s << endl;

  s << TAB << "template <typename T>" << endl;
  s << TAB << "T Get(const std::string& param_name) {" << endl;
  INC_TAB;
  s << TAB << "auto val = ros_params_ptr_->Get(param_name);" << endl;
  s << TAB << "if (val.GetType() == gsf::Value::Type::NIL) {" << endl;
  INC_TAB;
  s << TAB
    << "GS_INFO(\" Get is null !param_name : % s \", param_name.c_str());"
    << endl;
  s << TAB << "return static_cast<T>(0);" << endl;
  DEL_TAB;
  s << TAB << "} else" << endl;
  INC_TAB;
  s << TAB << "return static_cast<T>(ros_params_ptr_->Get(param_name));"
    << endl;
  DEL_TAB;
  DEL_TAB;
  s << TAB << "}" << endl;
  s << endl;

  s << TAB << "template <typename T>" << endl;
  s << TAB << "std::vector<T> GetArray(const std::string& param_name) {"
    << endl;
  INC_TAB;
  s << TAB << "std::vector<T> vec_ret;" << endl;
  s << TAB << "auto val_ary = ros_params_ptr_->Get(param_name);" << endl;
  s << TAB << "if (val_ary.GetType() == gsf::Value::Type::ARRAY) {" << endl;
  INC_TAB;
  s << TAB << "for (auto& item : val_ary.GetArrayRaw()) {" << endl;
  INC_TAB;
  s << TAB << "vec_ret.push_back(static_cast<T>(item));" << endl;
  DEL_TAB;
  s << TAB << "}" << endl;
  DEL_TAB;
  s << TAB << "}" << endl;
  s << TAB << "return vec_ret;" << endl;
  DEL_TAB;
  s << TAB << "}" << endl;
  s << endl;

  vector<TypeIdPtr>& member = rPtr->getAllMemberPtr();
  for (size_t j = 0; j < member.size(); j++) {
    if (member[j]->getTypePtr()->isArray()) {
      s << TAB << "DEF_ROS_ARRAY_PARAM(" << tostr(member[j]->getTypePtr())
        << ", " << member[j]->getId() << ");" << endl;
      continue;
    } else if (member[j]->getTypePtr()->isPointer()) {
      continue;
    } else if (member[j]->hasDefault()) {
      s << TAB << "DEF_ROS_PARAM(" << tostr(member[j]->getTypePtr()) << ", "
        << member[j]->getId() << ");" << endl;
      continue;
    } else
      continue;
  }
  s << endl;

  s << TAB << "void LoadParam() {" << endl;
  INC_TAB;
  s << TAB << "if (!ros_params_ptr_) return;" << endl;
  s << endl;
  for (size_t j = 0; j < member.size(); j++) {
    if (member[j]->getTypePtr()->isArray()) {
      string ros_namesp("");
      if (member[j]->NameSp() == "") {
        ros_namesp = "/device/scrubber/" + member[j]->getId();
      } else {
        ros_namesp = member[j]->NameSp();
      }
      // BuiltinPtr bPtr =
      // std::dynamic_pointer_cast<Builtin>(member[j]->getTypePtr()); auto tp =
      // bPtr->kind();
      s << TAB << "ros_params_ptr_->AddParam(\"" << member[j]->getId() << "\""
        << ", \"" << ros_namesp << "\", {" << member[j]->def() << "});" << endl;
      continue;
    } else if (member[j]->getTypePtr()->isPointer()) {
      continue;
    } else if (member[j]->hasDefault()) {
      string ros_namesp("");
      if (member[j]->NameSp() == "") {
        ros_namesp = "/device/scrubber/" + member[j]->getId();
      } else {
        ros_namesp = member[j]->NameSp();
      }
      BuiltinPtr bPtr =
          std::dynamic_pointer_cast<Builtin>(member[j]->getTypePtr());
      // string值要转义
      auto mm = member[j];
      switch (bPtr->kind()) {
        case Builtin::KindBool:
        case Builtin::KindInt:
        case Builtin::KindDouble:
          s << TAB << "ros_params_ptr_->AddParam(\"" << member[j]->getId()
            << "\""
            << ", \"" << ros_namesp << "\", "
            << "(" << tostr(member[j]->getTypePtr()) << ")" << member[j]->def()
            << ");" << endl;
          break;
        case Builtin::KindString: {
          s << TAB << "ros_params_ptr_->AddParam(\"" << member[j]->getId()
            << "\""
            << ", \"" << ros_namesp << "\", \"" << member[j]->def() << "\");"
            << endl;
        } break;
        default:
          break;
      }
      continue;
    } else
      continue;
  }
  DEL_TAB;
  s << TAB << "}" << endl;
  s << endl;

  // call back
  for (size_t j = 0; j < member.size(); j++) {
    if (member[j]->hasDefault() && member[j]->CbName() != "") {
      s << TAB << "void Set" << FixCBFuncName(member[j]->CbName())
        << "ValueChangedCB(std::function<void()> call_back) {" << endl;
      s << TAB << TAB << "ros_params_ptr_->SetValueChangedCb(\""
        << member[j]->getId() << "\", call_back);";
      s << endl;
      s << TAB << "}" << endl;
    }
  }
  s << endl;

  DEL_TAB;
  s << TAB << "protected:" << endl;
  INC_TAB;
  s << TAB << "DeviceController* const dev_ctrl_;" << endl;
  s << TAB << "common::RosParametersPtr ros_params_ptr_;" << endl;
  DEL_TAB;
  s << TAB << "};" << endl;
  s << TAB
    << "using ScrubberParametersPtr = boost::intrusive_ptr<ScrubberParameters>;"
    << endl;
  s << TAB << "#undef DEF_ROS_ARRAY_PARAM" << endl;
  s << TAB << "#undef DEF_ROS_PARAM" << endl;

  return s.str();
}

string Gaussian2Cpp::FixCBFuncName(const string& src_name) const {
  string res, s;
  s = src_name.substr(4, src_name.size());

  int len = s.size();
  res.resize(len);
  res[0] = s[0] - 'a' + 'A';
  int flag = 0;
  int count = 0;
  for (int i = 1; i < len; i++) {
    if (s[i] == '_') {
      flag = 1;
    } else if (flag) {
      count++;
      res[i - count] = s[i] - 'a' + 'A';
      flag = 0;
    } else {
      res[i - count] = s[i];
    }
  }
  res.resize(res.size() - count);

  return res;
}

/*******************************ContainerPtr********************************/
string Gaussian2Cpp::generateH(const ContainerPtr& pPtr) const {
  ostringstream s;
  for (size_t i = 0; i < pPtr->getAllNamespacePtr().size(); i++) {
    s << generateH(pPtr->getAllNamespacePtr()[i]) << endl;
    s << endl;
  }
  return s.str();
}

/******************************ParamDeclPtr***************************************/
string Gaussian2Cpp::generateH(const ParamDeclPtr& pPtr) const {
  ostringstream s;

  //输出参数, 或简单类型
  if (pPtr->isOut() || pPtr->getTypeIdPtr()->getTypePtr()->isSimple()) {
    s << tostr(pPtr->getTypeIdPtr()->getTypePtr());
  } else {
    //结构, map, vector, string
    s << "const " << tostr(pPtr->getTypeIdPtr()->getTypePtr()) << " &";
  }

  if (pPtr->isOut()) {
    s << " &";
  } else {
    s << " ";
  }
  s << pPtr->getTypeIdPtr()->getId();

  return s.str();
}

string Gaussian2Cpp::generateOutH(const ParamDeclPtr& pPtr) const {
  if (!pPtr->isOut()) return "";

  ostringstream s;

  //输出参数, 或简单类型
  if (pPtr->getTypeIdPtr()->getTypePtr()->isSimple()) {
    s << tostr(pPtr->getTypeIdPtr()->getTypePtr()) << " ";
  } else {
    //结构, map, vector, string
    s << "const " << tostr(pPtr->getTypeIdPtr()->getTypePtr()) << " &";
  }
  s << pPtr->getTypeIdPtr()->getId();

  return s.str();
}

string Gaussian2Cpp::generateParamDecl(const ParamDeclPtr& pPtr) const {
  ostringstream s;

  if (pPtr->isOut() || pPtr->getTypeIdPtr()->getTypePtr()->isSimple()) {
    s << tostr(pPtr->getTypeIdPtr()->getTypePtr());

    if (pPtr->isOut())
      s << " &";
    else
      s << " ";
  } else {
    //输入参数
    s << "const " << tostr(pPtr->getTypeIdPtr()->getTypePtr()) << " &";
  }

  s << pPtr->getTypeIdPtr()->getId();

  return s.str();
}

///////////////////////////////////////////////////////////////////////////////////////////////
string Gaussian2Cpp::generateDispatchCoroAsync(const OperationPtr& pPtr,
                                               const string& cn) const {
  ostringstream s;
  s << TAB << "if (msg->response->iRet != common::GAUSSIANSERVERSUCCESS)"
    << endl
    << TAB << "{" << endl;

  INC_TAB;
  s << TAB << "callback_" << pPtr->getId() << "_exception(msg->response->iRet);"
    << endl;
  s << endl;

  s << TAB << "return msg->response->iRet;" << endl;
  DEL_TAB;
  s << TAB << "}" << endl;

  s << TAB
    << _namespace + "::GaussianInputStream<" + _namespace +
           "::BufferReader> _is;"
    << endl;
  s << endl;
  vector<ParamDeclPtr>& vParamDecl = pPtr->getAllParamDeclPtr();

  s << TAB << "_is.setBuffer(msg->response->sBuffer);" << endl;

  if (pPtr->getReturnPtr()->getTypePtr() || vParamDecl.size() > 0) {
    s << TAB << "try" << endl;
    s << TAB << "{" << endl;

    INC_TAB;
  }

  //对输出参数编码
  if (pPtr->getReturnPtr()->getTypePtr()) {
    s << TAB << tostr(pPtr->getReturnPtr()->getTypePtr()) << " "
      << pPtr->getReturnPtr()->getId()
      << generateInitValue(pPtr->getReturnPtr()) << ";" << endl;
    s << readFrom(pPtr->getReturnPtr()) << endl;
  }

  for (size_t i = 0; i < vParamDecl.size(); i++) {
    if (vParamDecl[i]->isOut()) {
      s << TAB << tostr(vParamDecl[i]->getTypeIdPtr()->getTypePtr()) << " "
        << vParamDecl[i]->getTypeIdPtr()->getId()
        << generateInitValue(vParamDecl[i]->getTypeIdPtr()) << ";" << endl;
      s << readFrom(vParamDecl[i]->getTypeIdPtr());
    }
  }

  s << TAB << "setResponseContext(msg->response->context);" << endl;
  s << endl;

  //异步回调都无返回值
  s << TAB << "callback_" << pPtr->getId() << "(";
  string sParams;
  if (pPtr->getReturnPtr()->getTypePtr()) {
    sParams = pPtr->getReturnPtr()->getId() + ", ";
  }
  for (size_t i = 0; i < vParamDecl.size(); i++) {
    if (vParamDecl[i]->isOut()) {
      sParams += vParamDecl[i]->getTypeIdPtr()->getId() + ", ";
    }
  }
  s << common::GS_Common::trimright(sParams, ", ", false) << ");" << endl;

  s << endl;

  if (pPtr->getReturnPtr()->getTypePtr() || vParamDecl.size() > 0) {
    DEL_TAB;

    s << TAB << "}" << endl;
    s << TAB << "catch(std::exception &ex)" << endl;
    s << TAB << "{" << endl;

    INC_TAB;
    s << TAB << "callback_" << pPtr->getId()
      << "_exception(common::GAUSSIANCLIENTDECODEERR);" << endl;
    s << endl;
    s << TAB << "return common::GAUSSIANCLIENTDECODEERR;" << endl;
    DEL_TAB;

    s << TAB << "}" << endl;
    s << TAB << "catch(...)" << endl;
    s << TAB << "{" << endl;

    INC_TAB;
    s << TAB << "callback_" << pPtr->getId()
      << "_exception(common::GAUSSIANCLIENTDECODEERR);" << endl;
    s << endl;
    s << TAB << "return common::GAUSSIANCLIENTDECODEERR;" << endl;
    DEL_TAB;

    s << TAB << "}" << endl;
    s << endl;
  }

  s << TAB << "return common::GAUSSIANSERVERSUCCESS;" << endl;

  return s.str();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////

string Gaussian2Cpp::generateInitValue(const TypeIdPtr& pPtr) const {
  BuiltinPtr bPtr = std::dynamic_pointer_cast<Builtin>(pPtr->getTypePtr());
  string init = "";
  if (bPtr && Builtin::KindBool == bPtr->kind()) {
    init = " = false";
  }

  //枚举强制类型转换在O2编译选项情况下会告警
  EnumPtr ePtr = std::dynamic_pointer_cast<Enum>(pPtr->getTypePtr());
  if (ePtr) {
    if (pPtr->hasDefault()) {
      string sid = ePtr->getSid();
      init = " = " + pPtr->def() + ";";
    } else {
      vector<TypeIdPtr>& eMember = ePtr->getAllMemberPtr();
      if (eMember.size() > 0) {
        string sid = ePtr->getSid();
        init = " = " + sid.substr(0, sid.find_first_of("::")) +
               "::" + eMember[0]->getId() + ";";
      }
    }
  }
  return init;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////
string Gaussian2Cpp::generateH(const OperationPtr& pPtr, bool bVirtual,
                               const string& interfaceId) const {
  ostringstream s;
  return s.str();
}

/**
 * 对接口名排序
 */
struct SortOperation {
  bool operator()(const OperationPtr& o1, const OperationPtr& o2) {
    return o1->getId() < o2->getId();
  }
};

/******************************InterfacePtr***************************************/
string Gaussian2Cpp::generateH(const InterfacePtr& pPtr,
                               const NamespacePtr& nPtr) const {
  ostringstream s;
  vector<OperationPtr>& vOperation = pPtr->getAllOperationPtr();

  std::sort(vOperation.begin(), vOperation.end(), SortOperation());

  //生成异步回调Proxy
  s << TAB << "/* callback of async proxy for client */" << endl;
  return s.str();
}

// struct SortOperation
//{
//    bool operator()(const OperationPtr &o1, const OperationPtr &o2)
//    {
//        return o1->getId() < o2->getId();
//    }
//};

/******************************EnumPtr***************************************/

string Gaussian2Cpp::generateH(const EnumPtr& pPtr) const {
  ostringstream s;
  s << TAB << "enum " << pPtr->getId() << endl;
  s << TAB << "{" << endl;
  INC_TAB;
  vector<TypeIdPtr>& member = pPtr->getAllMemberPtr();
  for (size_t i = 0; i < member.size(); i++) {
    s << TAB << member[i]->getId();
    if (member[i]->hasDefault()) {
      s << " = " << member[i]->def();
    }
    s << "," << endl;
  }
  DEL_TAB;
  s << TAB << "};" << endl;

  //生成枚举转字符串函数
  s << TAB << "inline string etos"
    << "(const " << pPtr->getId() << " & e)" << endl;
  s << TAB << "{" << endl;
  INC_TAB;

  s << TAB << "switch(e)" << endl;
  s << TAB << "{" << endl;
  INC_TAB;

  for (size_t i = 0; i < member.size(); i++) {
    s << TAB << "case " << member[i]->getId() << ": return "
      << "\"" << member[i]->getId() << "\";" << endl;
  }
  s << TAB << "default: return \"\";" << endl;

  DEL_TAB;
  s << TAB << "}" << endl;
  // s << TAB << "return \"\";" << endl;
  DEL_TAB;
  s << TAB << "}" << endl;

  //生成字符串转枚举函数
  s << TAB << "inline int stoe"
    << "(const string & s, " << pPtr->getId() << " & e)" << endl;
  s << TAB << "{" << endl;
  INC_TAB;

  for (size_t i = 0; i < member.size(); i++) {
    s << TAB << "if(s == \"" << member[i]->getId()
      << "\")  { e=" << member[i]->getId() << "; return 0;}" << endl;
  }
  s << endl;
  s << TAB << "return -1;" << endl;

  DEL_TAB;
  s << TAB << "}" << endl;

  return s.str();
}

/******************************ConstPtr***************************************/
string Gaussian2Cpp::generateH(const ConstPtr& pPtr) const {
  ostringstream s;

  if (pPtr->getConstGrammarPtr()->t == ConstGrammar::STRING) {
    string tmp =
        common::GS_Common::replace(pPtr->getConstGrammarPtr()->v, "\"", "\\\"");
    s << TAB << "const " << tostr(pPtr->getTypeIdPtr()->getTypePtr()) << " "
      << pPtr->getTypeIdPtr()->getId() << " = \"" << tmp << "\";" << endl;
  } else {
    s << TAB << "const " << tostr(pPtr->getTypeIdPtr()->getTypePtr()) << " "
      << pPtr->getTypeIdPtr()->getId() << " = " << pPtr->getConstGrammarPtr()->v
      << ((tostr(pPtr->getTypeIdPtr()->getTypePtr()) == _namespace + "::Int64")
              ? "LL;"
              : ";")
      << endl;
  }

  return s.str();
}
/******************************NamespacePtr***************************************/

string Gaussian2Cpp::generateH(const NamespacePtr& pPtr) const {
  ostringstream s;
  vector<InterfacePtr>& is = pPtr->getAllInterfacePtr();
  vector<StructPtr>& ss = pPtr->getAllStructPtr();
  vector<EnumPtr>& es = pPtr->getAllEnumPtr();
  vector<ConstPtr>& cs = pPtr->getAllConstPtr();
  vector<RosParamsPtr>& rs = pPtr->getAllRosParamsPtr();

  s << endl;
  s << TAB << "namespace " << pPtr->getId() << endl;
  s << TAB << "{" << endl;
  INC_TAB;

  for (size_t i = 0; i < rs.size(); i++) {
    s << generateH(rs[i]) << endl;
  }

  for (size_t i = 0; i < cs.size(); i++) {
    s << generateH(cs[i]) << endl;
  }

  for (size_t i = 0; i < es.size(); i++) {
    s << generateH(es[i]) << endl;
  }

  for (size_t i = 0; i < ss.size(); i++) {
    s << generateH(ss[i], pPtr->getId()) << endl;
  }

  s << endl;

  for (size_t i = 0; i < is.size() && _onlyStruct == false; i++) {
    s << generateH(is[i], pPtr) << endl;
    s << endl;
  }

  DEL_TAB;
  s << "};";

  s << endl << endl;

  return s.str();
}

void Gaussian2Cpp::generateH(const ContextPtr& pPtr) const {
  string n = g_parse->getFileName(pPtr->getFileName());
  string fileH =
      g_parse->getAbsoluteFileName(_baseDir, g_parse->replaceFileName(n, "h"));
  string fileCpp = g_parse->getAbsoluteFileName(
      _baseDir, g_parse->replaceFileName(n, "cpp"));
  //
  //    string n        =
  //    common::GS_File::excludeFileExt(common::GS_File::extractFileName(pPtr->getFileName()));
  //
  //    string fileH    = _baseDir + FILE_SEP + n + ".h";

  string define = common::GS_Common::upper("_" + n + "_h_");

  ostringstream s;

  s << g_parse->printHeaderRemark();

  s << "#ifndef " << define << endl;
  s << "#define " << define << endl;
  s << endl;
  s << "#include <map>" << endl;
  s << "#include <string>" << endl;
  s << "#include <vector>" << endl;
  if (_g_rosparam_file) {
    s << "#include \"gs_framework/counter.h\"" << endl;
    s << "#include \"gs_framework/platform.h\"" << endl;
    s << "#include \"gs_framework/components/comm_manager.h\"" << endl;
    s << "#include \"common/ros_parameters.h\"" << endl;
  }

  s << "using namespace std;" << endl;

  vector<string> include = pPtr->getIncludes();
  for (size_t i = 0; i < include.size(); i++) {
    s << "#include \"" << g_parse->getHeader()
      << common::GS_File::extractFileName(include[i]) << "\"" << endl;
  }

  vector<NamespacePtr> namespaces = pPtr->getNamespaces();
  for (size_t i = 0; i < namespaces.size(); i++) {
    s << generateH(namespaces[i]) << endl;
  }

  s << endl;
  s << "#endif" << endl;

  common::GS_File::makeDirRecursive(_baseDir);
  common::GS_File::save2file(fileH, s.str());
}

void Gaussian2Cpp::createFile(
    const string& file)  //, const vector<string>& vsCoder)
{
  std::vector<ContextPtr> contexts = g_parse->getContexts();
  for (size_t i = 0; i < contexts.size(); i++) {
    if (file == contexts[i]->getFileName()) {
      // if (vsCoder.size() == 0)
      // {
      generateH(contexts[i]);
      // }
      // else
      // {
      //     for (size_t j = 0; j < vsCoder.size(); j++)
      //     {
      //         generateCoder(contexts[i], vsCoder[j]);
      //     }
      // }
    }
  }
}

StructPtr Gaussian2Cpp::findStruct(const ContextPtr& pPtr, const string& id) {
  string sid = id;

  //在当前namespace中查找
  vector<NamespacePtr> namespaces = pPtr->getNamespaces();
  for (size_t i = 0; i < namespaces.size(); i++) {
    NamespacePtr np = namespaces[i];
    vector<StructPtr> structs = np->getAllStructPtr();

    for (size_t i = 0; i < structs.size(); i++) {
      if (structs[i]->getSid() == sid) {
        return structs[i];
      }
    }
  }

  return NULL;
}