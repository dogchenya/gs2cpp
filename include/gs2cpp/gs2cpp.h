﻿#ifndef _GAUSSIAN2CPP_H_
#define _GAUSSIAN2CPP_H_

#include <cassert>
#include <string>

#include "parse.h"

using namespace common;

/**
 * 根据gaussian生成c++文件
 */
class Gaussian2Cpp {
 public:
  Gaussian2Cpp();

  /**
   * 生成
   * @param file
   */
  void createFile(const string &file);  //, const vector<string> &vsCoder);

  /**
   * 设置生成文件的目录
   *
   */
  void setBaseDir(const std::string &sPath) { _baseDir = sPath; }

  /**
   * 设置是否需要打包默认值
   */
  void setCheckDefault(bool bCheck) { _checkDefault = bCheck; }

  /**
   * 根据命令选项设置是否需要生成sql支持
   */
  void setSqlSupport(bool bSqlSupport) { _bSqlSupport = bSqlSupport; }

  /**
   * 根据命令选项设置是否需要生成xml支持
   */
  void setXmlSupport(bool bXmlSupport, const vector<string> &vXmlIntf) {
    _bXmlSupport = bXmlSupport;
    _vXmlIntf = vXmlIntf;
  }

  /**
   * 根据命令选项设置是否需要生成json支持
   */
  void setJsonSupport(bool bJsonSupport) { _bJsonSupport = bJsonSupport; }

  /**
   * 根据命令选项设置是否需要生成json支持
   */
  void setJsonSupport(const vector<string> &vJsonIntf) {
    _vJsonIntf = vJsonIntf;
  }

  /**
   * 设置是否只生成struct
   */
  void setOnlyStruct(bool bOnlyStruct) { _onlyStruct = bOnlyStruct; }

  void setGRospram(bool bgRospramFile) { _g_rosparam_file = bgRospramFile; }

  //下面是编解码的源码生成
 protected:
  /**
   * 生成xml
   * @param pPtr
   *
   * @return string
   */
  string writeToXml(const TypeIdPtr &pPtr) const;

  /**
   * 生成xml
   * @param pPtr
   *
   * @return string
   */
  string readFromXml(const TypeIdPtr &pPtr, bool bIsRequire = true) const;

  /**
   * 生成sql
   * @param pPtr
   *
   * @return string
   */
  string writeToSql(const TypeIdPtr &pPtr) const;

  /**
   * 生成sql
   * @param pPtr
   *
   * @return string
   */
  string readFromSql(const TypeIdPtr &pPtr, bool bIsRequire = true) const;

  /**
   * 生成json
   * @param pPtr
   *
   * @return string
   */
  string writeToJson(const TypeIdPtr &pPtr) const;

  /**
   * 生成json
   * @param pPtr
   *
   * @return string
   */
  string readFromJson(const TypeIdPtr &pPtr, bool bIsRequire = true) const;

  /**
   * 生成某类型的解码源码
   * @param pPtr
   *
   * @return string
   */
  string writeTo(const TypeIdPtr &pPtr) const;

  /**
   * 生成某类型的编码源码
   * @param pPtr
   *
   * @return string
   */
  string readFrom(const TypeIdPtr &pPtr, bool bIsRequire = true) const;

  /**
   *
   * @param pPtr
   *
   * @return string
   */
  //    string readUnknown(const TypeIdPtr &pPtr) const;
  /**
   *
   * @param pPtr
   *
   * @return string
   */
  // string writeUnknown()const;
  /**
   *
   * @param pPtr
   *
   * @return string
   */
  string display(const TypeIdPtr &pPtr) const;

  /**
   *
   * @param pPtr
   *
   * @return string
   */
  string displaySimple(const TypeIdPtr &pPtr, bool bSep) const;

  /**
   *
   * @param pPtr
   *
   * @return string
   */
  string generateCollection(const TypeIdPtr &pPtr, bool bSep) const;

  //下面是类型描述的源码生成
 protected:
  /**
   * 生成某类型的字符串描述源码
   * @param pPtr
   *
   * @return string
   */
  string tostr(const TypePtr &pPtr) const;

  /**
   * 生成内建类型的字符串源码
   * @param pPtr
   *
   * @return string
   */
  string tostrBuiltin(const BuiltinPtr &pPtr) const;
  /**
   * 生成vector的字符串描述
   * @param pPtr
   *
   * @return string
   */
  string tostrVector(const VectorPtr &pPtr) const;

  /**
   * 生成map的字符串描述
   * @param pPtr
   *
   * @return string
   */
  string tostrMap(const MapPtr &pPtr) const;

  /**
   * 生成某种结构的符串描述
   * @param pPtr
   *
   * @return string
   */
  string tostrStruct(const StructPtr &pPtr) const;

  /**
   * 生成某种枚举的符串描述
   * @param pPtr
   *
   * @return string
   */
  string tostrEnum(const EnumPtr &pPtr) const;

  /**
   * 获取定长数组的坐标
   * @param pPtr
   *
   * @return string
   */

  string toStrSuffix(const TypeIdPtr &pPtr) const;

  /**
   * 获取定长数组的坐标
   * @param pPtr
   *
   * @return int
   */
  int getSuffix(const TypeIdPtr &pPtr) const;

  /**
   * 生成unsigned转换为signed的符串描述
   * @param pPtr
   *
   * @return string
   */
  // string unsigned2signedStr(const BuiltinPtr &pPtr) const;

  /**
   * 生成类型变量的解码源码
   * @param pPtr
   *
   * @return string
   */
  string decode(const TypeIdPtr &pPtr) const;

  /**
   * 生成类型变量的编码源码
   * @param pPtr
   *
   * @return string
   */
  string encode(const TypeIdPtr &pPtr) const;

  //以下是h文件的具体生成
 protected:
  /**
   * 结构的md5
   * @param pPtr
   *
   * @return string
   */
  string MD5(const StructPtr &pPtr) const;

  /**
   * 生成结构的头文件内容
   * @param pPtr
   *
   * @return string
   */
  string generateH(const StructPtr &pPtr, const string &namespaceId) const;

  /**
   * 生成容器的头文件源码
   * @param pPtr
   *
   * @return string
   */
  string generateH(const ContainerPtr &pPtr) const;

  string FixCBFuncName(const string &src_name) const;

  /**
   * 生成参数声明的头文件内容
   * @param pPtr
   *
   * @return string
   */
  string generateH(const ParamDeclPtr &pPtr) const;

  /**
   *
   * @param pPtr
   *
   * @return string
   */
  string generateOutH(const ParamDeclPtr &pPtr) const;

  /**
   *
   * @param pPtr
   * @param cn
   *
   * @return string
   */
  string generateAsyncResponseCpp(const OperationPtr &pPtr,
                                  const string &cn) const;

  /**
   * 生成参数声明的内容
   * @param pPtr
   *
   * @return string
   */
  string generateParamDecl(const ParamDeclPtr &pPtr) const;

  /**
   * 生成操作函数调用分发的源码
   * @param pPtr
   * @param cn
   *
   * @return string
   */
  string generateDispatchCoroAsync(const OperationPtr &pPtr,
                                   const string &cn) const;

  /**
   * 生成操作的servant的头文件源码
   * @param pPtr
   * @param bVirtual
   *
   * @return string
   */
  string generateH(const OperationPtr &pPtr, bool bVirtual,
                   const string &interfaceId) const;

  /**
   * 生成接口的头文件源码
   * @param pPtr
   *
   * @return string
   */
  string generateH(const InterfacePtr &pPtr, const NamespacePtr &nPtr) const;

  /**
   * 生成枚举的头文件源码
   * @param pPtr
   *
   * @return string
   */
  string generateH(const EnumPtr &pPtr) const;

  /**
   * 生成RosParams的头文件源码
   * @param rPtr
   *
   * @return string
   */
  string generateH(const RosParamsPtr &rPtr) const;

  /**
   * 生成常量头文件源码
   * @param pPtr
   *
   * @return string
   */
  string generateH(const ConstPtr &pPtr) const;

  /**
   * 生成名字空间的头文件源码
   * @param pPtr
   *
   * @return string
   */
  string generateH(const NamespacePtr &pPtr) const;

  /**
   * 生成名字空间的头文件源码
   * @param pPtr
   *
   * @return string
   */
  void generateH(const ContextPtr &pPtr) const;

  /**
   *
   * 根据名字查找结构
   * @param pPtr
   * @param id
   *
   * @return StructPtr
   */
  StructPtr findStruct(const ContextPtr &pPtr, const string &id);

  // /**
  //  *
  //  * 生成接口编解码代码
  //  * @param pPtr
  //  * @param interface
  //  */
  // void generateCoder(const ContextPtr &pPtr,const string &interface) const;

  // string generateCoder(const NamespacePtr &pPtr,const string & sInterface)
  // const;

  // string generateCoder(const InterfacePtr &pPtr) const;

  // string generateCoder(const OperationPtr &pPtr) const;

  string generateInitValue(const TypeIdPtr &pPtr) const;

 private:
  std::string _baseDir;

  bool _checkDefault;

  bool _onlyStruct;

  bool _g_rosparam_file;

  bool _bSqlSupport;

  bool _bXmlSupport;

  bool _bJsonSupport;

  vector<string> _vJsonIntf;
  vector<string> _vXmlIntf;

  std::string _namespace;
};

#endif
