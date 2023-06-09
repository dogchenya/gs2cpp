﻿#include "gs_option.h"
#include "gs_file.h"
#include "gs_common.h"
#include "gs2cpp.h"

void usage() {
  cout << "Usage : gs2cpp [OPTION] gaussianfile" << endl;
  cout
    << "  --dir=DIRECTORY                             generate source file to DIRECTORY(create gaussian protocol file "
       "to DIRECTORY, default is current directory)"
    << endl;
  cout
    << "  --check-default=<true,false>                optional field with default value not do package(default: true)"
    << endl;
  cout << "  --unjson                                    not json interface" << endl;
  cout << "  --rosparam                                  generate rosparam file" << endl;
  cout << "  --os                                        only create struct(not create interface) " << endl;
  cout << "  --include=\"dir1;dir2;dir3\"                set search path of gaussian protocol" << endl;
  cout << "  --currentPriority						   use current path first." << endl;
  cout << "  gs2cpp support type: bool byte short int long float double vector map" << endl;
  exit(0);
}

void check(vector<string>& vGaussian) {
  for (size_t i = 0; i < vGaussian.size(); i++) {
    string ext = common::GS_File::extractFileExt(vGaussian[i]);
    if (ext == "gaussian") {
      if (!common::GS_File::isFileExist(vGaussian[i])) {
        cerr << "file '" << vGaussian[i] << "' not exists" << endl;
        usage();
        exit(0);
      }
    } else {
      cerr << "only support gaussian file." << endl;
      exit(0);
    }
  }
}

int main(int argc, char* argv[]) {
  if (argc < 2) {
    usage();
  }

  common::GS_Option option;
  option.decode(argc, argv);
  vector<string> vGaussian = option.getSingle();

  check(vGaussian);

  if (option.hasParam("help")) {
    usage();
  }

  Gaussian2Cpp g2c;

  if (option.hasParam("dir")) {
    g2c.setBaseDir(option.getValue("dir"));
  } else {
    g2c.setBaseDir(".");
  }

  g2c.setCheckDefault(common::GS_Common::lower(option.getValue("check-default")) == "false" ? false : true);

  g2c.setOnlyStruct(option.hasParam("os"));

  g2c.setGRospram(option.hasParam("rosparam"));

  //默认支持json
  g2c.setJsonSupport(true);

  if (option.hasParam("unjson")) {
    g2c.setJsonSupport(false);
  }

  if (option.hasParam("xml")) {
    vector<string> vXmlIntf;
    string sXml = common::GS_Common::trim(option.getValue("xml"));
    sXml = common::GS_Common::trimleft(common::GS_Common::trimright(sXml, "]"), "[");
    if (!sXml.empty()) {
      vXmlIntf = common::GS_Common::sepstr<string>(sXml, ",", false);
    }
    g2c.setXmlSupport(true, vXmlIntf);
  }

  //g2c.setGaussianMaster(option.hasParam("gaussianMaster"));

  try {
    //增加include搜索路径
    g_parse->addIncludePath(option.getValue("include"));

    //是否可以以gaussian开头
    g_parse->setGaussian(option.hasParam("with-gaussian"));
    g_parse->setHeader(option.getValue("header"));
    g_parse->setCurrentPriority(option.hasParam("currentPriority"));

    // g2c.setUnknownField(option.hasParam("unknown"));
    for (size_t i = 0; i < vGaussian.size(); i++) {
      g_parse->parse(vGaussian[i]);
      g2c.createFile(vGaussian[i]);  //, vCoder);
    }
  } catch (exception& e) {
    cerr << e.what() << endl;
  }

  return 0;
}
