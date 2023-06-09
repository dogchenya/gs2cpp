﻿#include "gs_option.h"
#include "gs_common.h"

namespace common {

void GS_Option::decode(int argc, char *argv[]) {
  _mParam.clear();

  vector<string> v;
  for (int i = 1; i < argc; i++) {
    v.push_back(argv[i]);
  }
  for (size_t i = 0; i < v.size(); i++) {
    if (v[i].length() > 2 && v[i].substr(0, 2) == "--") {
      parse(v[i]);
    } else {
      _vSingle.push_back(v[i]);
    }
  }
}
void GS_Option::decode(const char *command) {
  _mParam.clear();
  if (command == NULL) return;
  vector<string> v = GS_Common::sepstr<string>(command, " \t");

  for (size_t i = 0; i < v.size(); i++) {
    if (v[i].length() > 2 && v[i].substr(0, 2) == "--") {
      parse(v[i]);
    } else {
      _vSingle.push_back(v[i]);
    }
  }
}

void GS_Option::parse(const string &s) {
  string::size_type pos = s.find('=');
  if (pos != string::npos) {
    _mParam[s.substr(2, pos - 2)] = s.substr(pos + 1);
  } else {
    _mParam[s.substr(2, pos - 2)] = "";
  }
}

string GS_Option::getValue(const string &sName, const string &def) const {
  auto it = _mParam.find(sName);
  if (it != _mParam.end()) {
    return it->second;
  }
  return def;
}

bool GS_Option::hasParam(const string &sName) const { return _mParam.find(sName) != _mParam.end(); }

const vector<string> &GS_Option::getSingle() const { return _vSingle; }

const map<string, string> &GS_Option::getMulti() const { return _mParam; }

vector<string> &GS_Option::getSingle() { return _vSingle; }

map<string, string> &GS_Option::getMulti() { return _mParam; }

}  // namespace common
