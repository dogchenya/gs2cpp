﻿#include "gs_common.h"

#include <chrono>
#include <thread>

#include "gs_port.h"

#if TARGET_PLATFORM_WINDOWS
#include <sys/timeb.h>
#pragma comment(lib, "ws2_32.lib")
#endif

// #if TARGET_PLATFORM_WINDOWS || TARGET_PLATFORM_IOS
// #define HOST_NAME_MAX 64
// #endif

#include <signal.h>
#include <string.h>

#include <cmath>

namespace common {

#define MATCH_DOUBLE                           \
  if (vx.size() != vy.size()) {                \
    return false;                              \
  }                                            \
  auto it1 = vx.begin();                       \
  auto it2 = vy.end();                         \
  while (it1 != vx.end() && it2 != vy.end()) { \
    if (!equal(*it1, *it2, epsilon)) {         \
      return false;                            \
    }                                          \
    ++it1;                                     \
    ++it2;                                     \
  }                                            \
  return true;

const float GS_Common::_EPSILON_FLOAT = 0.000001f;
const double GS_Common::_EPSILON_DOUBLE = 0.000001;

void GS_Common::sleep(uint32_t sec) { std::this_thread::sleep_for(std::chrono::seconds(sec)); }

void GS_Common::msleep(uint32_t ms) { std::this_thread::sleep_for(std::chrono::milliseconds(ms)); }

bool GS_Common::equal(double x, double y, double epsilon) { return fabs(x - y) < epsilon; }

bool GS_Common::equal(double x, double y, float epsilon) { return equal(x, y, (double)epsilon); }

bool GS_Common::equal(float x, float y, float epsilon) { return fabsf(x - y) < epsilon; }

bool GS_Common::equal(float x, float y, double epsilon) { return equal(x, y, float(epsilon)); }

bool GS_Common::equal(const vector<double> &vx, const vector<double> &vy, double epsilon) { MATCH_DOUBLE }

bool GS_Common::equal(const vector<double> &vx, const vector<double> &vy, float epsilon) {
  return equal(vx, vy, double(epsilon));
}

bool GS_Common::equal(const vector<float> &vx, const vector<float> &vy, float epsilon) { MATCH_DOUBLE }

bool GS_Common::equal(const vector<float> &vx, const vector<float> &vy, double epsilon) {
  return equal(vx, vy, float(epsilon));
}

bool GS_Common::equal(const set<double> &vx, const set<double> &vy, double epsilon) { MATCH_DOUBLE }

bool GS_Common::equal(const set<double> &vx, const set<double> &vy, float epsilon) {
  return equal(vx, vy, double(epsilon));
}

bool GS_Common::equal(const set<float> &vx, const set<float> &vy, float epsilon) {
  return equal(vx, vy, double(epsilon));
}

bool GS_Common::equal(const set<float> &vx, const set<float> &vy, double epsilon) { MATCH_DOUBLE }

bool GS_Common::equal(const unordered_set<double> &vx, const unordered_set<double> &vy, double epsilon) { MATCH_DOUBLE }

bool GS_Common::equal(const unordered_set<double> &vx, const unordered_set<double> &vy, float epsilon) {
  return equal(vx, vy, double(epsilon));
}

bool GS_Common::equal(const unordered_set<float> &vx, const unordered_set<float> &vy, float epsilon) {
  return equal(vx, vy, double(epsilon));
}

bool GS_Common::equal(const unordered_set<float> &vx, const unordered_set<float> &vy, double epsilon) { MATCH_DOUBLE }

template <>
string GS_Common::tostr<bool>(const bool &t) {
  char buf[2];
  buf[0] = t ? '1' : '0';
  buf[1] = '\0';
  return string(buf);
}

template <>
string GS_Common::tostr<char>(const char &t) {
  char buf[2];
  snprintf(buf, 2, "%c", t);
  return string(buf);
}

template <>
string GS_Common::tostr<unsigned char>(const unsigned char &t) {
  char buf[2];
  snprintf(buf, 2, "%c", t);
  return string(buf);
}

template <>
string GS_Common::tostr<short>(const short &t) {
  char buf[16];
  snprintf(buf, 16, "%d", t);
  return string(buf);
}

template <>
string GS_Common::tostr<unsigned short>(const unsigned short &t) {
  char buf[16];
  snprintf(buf, 16, "%u", t);
  return string(buf);
}

template <>
string GS_Common::tostr<int>(const int &t) {
  char buf[16];
  snprintf(buf, 16, "%d", t);
  return string(buf);
}

template <>
string GS_Common::tostr<unsigned int>(const unsigned int &t) {
  char buf[16];
  snprintf(buf, 16, "%u", t);
  return string(buf);
}

template <>
string GS_Common::tostr<long>(const long &t) {
  char buf[32];
  snprintf(buf, 32, "%ld", t);
  return string(buf);
}

template <>
string GS_Common::tostr<long long>(const long long &t) {
  char buf[32];
  snprintf(buf, 32, "%lld", t);
  return string(buf);
}

template <>
string GS_Common::tostr<unsigned long>(const unsigned long &t) {
  char buf[32];
  snprintf(buf, 32, "%lu", t);
  return string(buf);
}

template <>
string GS_Common::tostr<float>(const float &t) {
  // C++11 to_string，默认保留后面6位小数
  string s = std::to_string(t);

  //去掉无效0, eg. 1.0300 -> 1.03;1.00 -> 1
  bool bFlag = false;
  int pos = int(s.size() - 1);
  for (; pos > 0; --pos) {
    if (s[pos] == '0') {
      bFlag = true;
      if (s[pos - 1] == '.') {
        //-2为了去掉"."号
        pos -= 2;
        break;
      }
    } else {
      break;
    }
  }

  if (bFlag) s = s.substr(0, pos + 1);

  return s;
}

template <>
string GS_Common::tostr<double>(const double &t) {
  // C++11 to_string，默认保留后面6位小数
  string s = std::to_string(t);
  //去掉无效0, eg. 1.0300 -> 1.03;1.00 -> 1
  bool bFlag = false;
  int pos = int(s.size() - 1);
  for (; pos > 0; --pos) {
    if (s[pos] == '0') {
      bFlag = true;
      if (s[pos - 1] == '.') {
        //-2为了去掉"."号
        pos -= 2;
        break;
      }
    } else {
      break;
    }
  }

  if (bFlag) s = s.substr(0, pos + 1);

  return s;
}

template <>
string GS_Common::tostr<long double>(const long double &t) {
  char buf[32];
  snprintf(buf, 32, "%Lf", t);
  string s(buf);

  //去掉无效0, eg. 1.0300 -> 1.03;1.00 -> 1
  bool bFlag = false;
  int pos = int(s.size() - 1);
  for (; pos > 0; --pos) {
    if (s[pos] == '0') {
      bFlag = true;
      if (s[pos - 1] == '.') {
        //-2为了去掉"."号
        pos -= 2;
        break;
      }
    } else {
      break;
    }
  }

  if (bFlag) s = s.substr(0, pos + 1);

  return s;
}

template <>
string GS_Common::tostr<std::string>(const std::string &t) {
  return t;
}

string GS_Common::trim(const string &sStr, const string &s, bool bChar) {
  if (sStr.empty()) {
    return sStr;
  }

  /**
   * 将完全与s相同的字符串去掉
   */
  if (!bChar) {
    return trimright(trimleft(sStr, s, false), s, false);
  }

  return trimright(trimleft(sStr, s, true), s, true);
}

string GS_Common::trimleft(const string &sStr, const string &s, bool bChar) {
  if (sStr.empty()) {
    return sStr;
  }

  /**
   * 去掉sStr左边的字符串s
   */
  if (!bChar) {
    if (sStr.length() < s.length()) {
      return sStr;
    }

    if (sStr.compare(0, s.length(), s) == 0) {
      return sStr.substr(s.length());
    }

    return sStr;
  }

  /**
   * 去掉sStr左边的 字符串s中的字符
   */
  string::size_type pos = 0;
  while (pos < sStr.length()) {
    if (s.find_first_of(sStr[pos]) == string::npos) {
      break;
    }

    pos++;
  }

  if (pos == 0) return sStr;

  return sStr.substr(pos);
}

string GS_Common::trimright(const string &sStr, const string &s, bool bChar) {
  if (sStr.empty()) {
    return sStr;
  }

  /**
   * 去掉sStr右边的字符串s
   */
  if (!bChar) {
    if (sStr.length() < s.length()) {
      return sStr;
    }

    if (sStr.compare(sStr.length() - s.length(), s.length(), s) == 0) {
      return sStr.substr(0, sStr.length() - s.length());
    }

    return sStr;
  }

  /**
   * 去掉sStr右边的 字符串s中的字符
   */
  string::size_type pos = sStr.length();
  while (pos != 0) {
    if (s.find_first_of(sStr[pos - 1]) == string::npos) {
      break;
    }

    pos--;
  }

  if (pos == sStr.length()) return sStr;

  return sStr.substr(0, pos);
}

string GS_Common::lower(const string &s) {
  string sString = s;
  for (string::iterator iter = sString.begin(); iter != sString.end(); ++iter) {
    *iter = tolower(*iter);
  }

  return sString;
}

string GS_Common::upper(const string &s) {
  string sString = s;

  for (string::iterator iter = sString.begin(); iter != sString.end(); ++iter) {
    *iter = toupper(*iter);
  }

  return sString;
}

bool GS_Common::isdigit(const string &sInput) {
  string::const_iterator iter = sInput.begin();

  if (sInput.empty()) {
    return false;
  }

  while (iter != sInput.end()) {
    if (!::isdigit(*iter)) {
      return false;
    }
    ++iter;
  }
  return true;
}

//用于计算时区差异!
class TimezoneHelper {
 public:
  TimezoneHelper() {
    struct tm timeinfo;
    time_t secs, local_secs, gmt_secs;

    // UTC时间戳
    time(&secs);

    //带时区时间
    GS_Port::localtime_r(&secs, &timeinfo);
    local_secs = ::mktime(&timeinfo);
#if !TARGET_PLATFORM_WINDOWS
    timezone_local = string(timeinfo.tm_zone);
#endif

    //不带时区时间
    GS_Port::gmtime_r(&secs, &timeinfo);

    gmt_secs = ::mktime(&timeinfo);
    timezone_diff_secs = local_secs - gmt_secs;
  }

#if !TARGET_PLATFORM_WINDOWS
  static string timezone_local;
#endif

  static int64_t timezone_diff_secs;
};

#if !TARGET_PLATFORM_WINDOWS
string TimezoneHelper::timezone_local;
#endif

int64_t TimezoneHelper::timezone_diff_secs = 0;

int GS_Common::str2tm(const string &sString, const string &sFormat, struct tm &stTm) { return 0; }

time_t GS_Common::str2time(const string &sString, const string &sFormat) {
  struct tm stTm;
  if (0 == str2tm(sString, sFormat, stTm)) {
    //注意这里没有直接用mktime, mktime会访问时区文件, 会巨慢!
    static TimezoneHelper helper;
    return GS_Port::timegm(&stTm) - TimezoneHelper::timezone_diff_secs;
  }
  return 0;
}

int GS_Common::strgmt2tm(const string &sString, struct tm &stTm) {
  return str2tm(sString, "%a, %d %b %Y %H:%M:%S GMT", stTm);
}

string GS_Common::tm2str(const struct tm &stTm, const string &sFormat) {
  char sTimeString[255] = "\0";

  strftime(sTimeString, sizeof(sTimeString), sFormat.c_str(), &stTm);

  return string(sTimeString);
}

int GS_Common::gettimeofday(struct timeval &tv) { return GS_Port::gettimeofday(tv); }

void GS_Common::tm2time(const time_t &t, struct tm &tt) {
  //加快速度, 否则会比较慢, 不用localtime_r(会访问时区文件, 较慢)
  static TimezoneHelper helper;
  time_t localt = t + TimezoneHelper::timezone_diff_secs;

  GS_Port::gmtime_r(&localt, &tt);

#if !TARGET_PLATFORM_WINDOWS
  static string local_timezone = TimezoneHelper::timezone_local;
  tt.tm_zone = const_cast<char *>(local_timezone.c_str());
  tt.tm_gmtoff = TimezoneHelper::timezone_diff_secs;
#endif
}

string GS_Common::tm2str(const time_t &t, const string &sFormat) {
  struct tm tt;
  tm2time(t, tt);

  return tm2str(tt, sFormat);
}

void GS_Common::tm2tm(const time_t &t, struct tm &tt) { tm2time(t, tt); }

string GS_Common::now2str(const string &sFormat) {
  time_t t = time(NULL);
  return tm2str(t, sFormat.c_str());
}

// string GS_Common::now2msstr()
//{
//    return ms2str(now2ms());
//}

string GS_Common::ms2str(int64_t ms) {
  time_t t = ms / 1000;

  auto duration_in_ms = ms % 1000;
  tm tt;

  GS_Port::localtime_r(&t, &tt);

  string s;
  s.resize(128);
  const char *szFormat = "%04d-%02d-%02d %02d:%02d:%02d.%03ld";
  size_t n = snprintf(&s[0], s.size(), szFormat, tt.tm_year + 1900, tt.tm_mon + 1, tt.tm_mday, tt.tm_hour, tt.tm_min,
                      tt.tm_sec, duration_in_ms);
  s.resize(n);

  return s;
}

string GS_Common::now2msstr() {
  time_t t = time(NULL);

  auto duration_in_ms = now2ms();

  tm tt;

  GS_Port::localtime_r(&t, &tt);

  string s;
  s.resize(128);
  const char *szFormat = "%04d-%02d-%02d %02d:%02d:%02d.%03ld";
  size_t n = snprintf(&s[0], s.size(), szFormat, tt.tm_year + 1900, tt.tm_mon + 1, tt.tm_mday, tt.tm_hour, tt.tm_min,
                      tt.tm_sec, duration_in_ms % 1000);
  s.resize(n);

  return s;
}

string GS_Common::now2GMTstr() {
  time_t t = time(NULL);
  return tm2GMTstr(t);
}

string GS_Common::tm2GMTstr(const time_t &t) {
  struct tm tt;

  GS_Port::gmtime_r(&t, &tt);
  return tm2str(tt, "%a, %d %b %Y %H:%M:%S GMT");
}

string GS_Common::tm2GMTstr(const struct tm &stTm) { return tm2str(stTm, "%a, %d %b %Y %H:%M:%S GMT"); }

string GS_Common::nowdate2str() { return now2str("%Y%m%d"); }

string GS_Common::nowtime2str() { return now2str("%H%M%S"); }

int64_t GS_Common::now2ms() {
  struct timeval tv;

  GS_Common::gettimeofday(tv);

  return tv.tv_sec * (int64_t)1000 + tv.tv_usec / 1000;
}

int64_t GS_Common::now2us() {
  struct timeval tv;

  GS_Common::gettimeofday(tv);

  return tv.tv_sec * (int64_t)1000000 + tv.tv_usec;
}

//参照phorix的优化
static char c_b2s[256][4] = {
  "00", "01", "02", "03", "04", "05", "06", "07", "08", "09", "0a", "0b", "0c", "0d", "0e", "0f", "10", "11", "12",
  "13", "14", "15", "16", "17", "18", "19", "1a", "1b", "1c", "1d", "1e", "1f", "20", "21", "22", "23", "24", "25",
  "26", "27", "28", "29", "2a", "2b", "2c", "2d", "2e", "2f", "30", "31", "32", "33", "34", "35", "36", "37", "38",
  "39", "3a", "3b", "3c", "3d", "3e", "3f", "40", "41", "42", "43", "44", "45", "46", "47", "48", "49", "4a", "4b",
  "4c", "4d", "4e", "4f", "50", "51", "52", "53", "54", "55", "56", "57", "58", "59", "5a", "5b", "5c", "5d", "5e",
  "5f", "60", "61", "62", "63", "64", "65", "66", "67", "68", "69", "6a", "6b", "6c", "6d", "6e", "6f", "70", "71",
  "72", "73", "74", "75", "76", "77", "78", "79", "7a", "7b", "7c", "7d", "7e", "7f", "80", "81", "82", "83", "84",
  "85", "86", "87", "88", "89", "8a", "8b", "8c", "8d", "8e", "8f", "90", "91", "92", "93", "94", "95", "96", "97",
  "98", "99", "9a", "9b", "9c", "9d", "9e", "9f", "a0", "a1", "a2", "a3", "a4", "a5", "a6", "a7", "a8", "a9", "aa",
  "ab", "ac", "ad", "ae", "af", "b0", "b1", "b2", "b3", "b4", "b5", "b6", "b7", "b8", "b9", "ba", "bb", "bc", "bd",
  "be", "bf", "c0", "c1", "c2", "c3", "c4", "c5", "c6", "c7", "c8", "c9", "ca", "cb", "cc", "cd", "ce", "cf", "d0",
  "d1", "d2", "d3", "d4", "d5", "d6", "d7", "d8", "d9", "da", "db", "dc", "dd", "de", "df", "e0", "e1", "e2", "e3",
  "e4", "e5", "e6", "e7", "e8", "e9", "ea", "eb", "ec", "ed", "ee", "ef", "f0", "f1", "f2", "f3", "f4", "f5", "f6",
  "f7", "f8", "f9", "fa", "fb", "fc", "fd", "fe", "ff"};

string GS_Common::bin2str(const void *buf, size_t len, const string &sSep, size_t lines) {
  if (buf == NULL || len <= 0) {
    return "";
  }

  string sOut;
  const unsigned char *p = (const unsigned char *)buf;

  for (size_t i = 0; i < len; ++i, ++p) {
    sOut += c_b2s[*p][0];
    sOut += c_b2s[*p][1];
    sOut += sSep;

    //换行
    if ((lines != 0) && ((i + 1) % lines == 0)) {
      sOut += "\n";
    }
  }

  return sOut;
}

string GS_Common::bin2str(const string &sBinData, const string &sSep, size_t lines) {
  return bin2str((const void *)sBinData.data(), sBinData.length(), sSep, lines);
}

int GS_Common::str2bin(const char *psAsciiData, unsigned char *sBinData, int iBinSize) {
  int iAsciiLength = (int)strlen(psAsciiData);

  int iRealLength = (iAsciiLength / 2 > iBinSize) ? iBinSize : (iAsciiLength / 2);
  for (int i = 0; i < iRealLength; i++) {
    sBinData[i] = x2c(psAsciiData + i * 2);
  }
  return iRealLength;
}

string GS_Common::str2bin(const string &sString, const string &sSep, size_t lines) {
  const char *psAsciiData = sString.c_str();

  size_t iAsciiLength = sString.length();
  string sBinData;
  for (size_t i = 0; i < iAsciiLength; i++) {
    sBinData += x2c(psAsciiData + i);
    i++;
    i += sSep.length();  //过滤掉分隔符

    if (lines != 0 && sBinData.length() % lines == 0) {
      i++;  //过滤掉回车
    }
  }

  return sBinData;
}

char GS_Common::x2c(const string &sWhat) {
  register char digit;

  if (sWhat.length() < 2) {
    return '\0';
  }

  digit = (sWhat[0] >= 'A' ? ((sWhat[0] & 0xdf) - 'A') + 10 : (sWhat[0] - '0'));
  digit *= 16;
  digit += (sWhat[1] >= 'A' ? ((sWhat[1] & 0xdf) - 'A') + 10 : (sWhat[1] - '0'));

  return (digit);
}

string GS_Common::replace(const string &sString, const string &sSrc, const string &sDest) {
  if (sSrc.empty()) {
    return sString;
  }

  string sBuf = sString;

  string::size_type pos = 0;

  while ((pos = sBuf.find(sSrc, pos)) != string::npos) {
    sBuf.replace(pos, sSrc.length(), sDest);
    pos += sDest.length();
  }

  return sBuf;
}

string GS_Common::replace(const string &sString, const map<string, string> &mSrcDest) {
  if (sString.empty()) {
    return sString;
  }

  string tmp = sString;
  map<string, string>::const_iterator it = mSrcDest.begin();

  while (it != mSrcDest.end()) {
    string::size_type pos = 0;
    while ((pos = tmp.find(it->first, pos)) != string::npos) {
      tmp.replace(pos, it->first.length(), it->second);
      pos += it->second.length();
    }

    ++it;
  }

  return tmp;
}

bool GS_Common::matchPeriod(const string &s, const string &pat) {
  if (s.empty()) {
    return false;
  }

  if (pat.empty()) {
    return true;
  }

  if (pat.find('*') == string::npos) {
    return s == pat;
  }

  string::size_type sIndex = 0;
  string::size_type patIndex = 0;
  do {
    if (pat[patIndex] == '*') {
      if (s[sIndex] == '.') {
        return false;
      }

      while (sIndex < s.size() && s[sIndex] != '.') {
        ++sIndex;
      }
      patIndex++;
    } else {
      if (pat[patIndex] != s[sIndex]) {
        return false;
      }
      ++sIndex;
      ++patIndex;
    }
  } while (sIndex < s.size() && patIndex < pat.size());

  return sIndex == s.size() && patIndex == pat.size();
}

bool GS_Common::matchPeriod(const string &s, const vector<string> &pat) {
  for (size_t i = 0; i < pat.size(); i++) {
    if (GS_Common::matchPeriod(s, pat[i])) {
      return true;
    }
  }
  return false;
}

#if TARGET_PLATFORM_LINUX || TARGET_PLATFORM_IOS

void GS_Common::daemon() {
  pid_t pid;

  if ((pid = fork()) != 0) {
    exit(0);
  }

  setsid();

  signal(SIGINT, SIG_IGN);
  signal(SIGHUP, SIG_IGN);
  signal(SIGQUIT, SIG_IGN);
  signal(SIGPIPE, SIG_IGN);
  signal(SIGTTOU, SIG_IGN);
  signal(SIGTTIN, SIG_IGN);
  signal(SIGCHLD, SIG_IGN);
  signal(SIGTERM, SIG_IGN);
  ignorePipe();

  if ((pid = fork()) != 0) {
    //父进程结束,变成daemon
    exit(0);
  }

  umask(0);

  //  chdir("/");
}

void GS_Common::ignorePipe() {
  struct sigaction sig;

  memset(&sig, 0, sizeof(struct sigaction));

  sig.sa_handler = SIG_IGN;
  sig.sa_flags = 0;
  sigemptyset(&sig.sa_mask);
  sigaction(SIGPIPE, &sig, NULL);
}

#endif

bool GS_Common::isPrimeNumber(size_t n) {
  size_t nn = (size_t)sqrt((double)n);
  for (size_t i = 2; i <= nn; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

size_t GS_Common::toSize(const string &s, size_t iDefaultSize) {
  if (s.empty()) {
    return iDefaultSize;
  }

  char c = s[s.length() - 1];
  if (c != 'K' && c != 'M' && c != 'G' && GS_Common::trim(s) == GS_Common::tostr(GS_Common::strto<size_t>(s))) {
    //没有后缀, 且转换是正确的
    return (size_t)(GS_Common::strto<size_t>(s));
  } else if (c == 'K' || c == 'M' || c == 'G') {
    if (s.length() == 1) {
      return iDefaultSize;
    }

    float n = GS_Common::strto<float>(s.substr(0, s.length() - 1));

    if (GS_Common::trim(s.substr(0, s.length() - 1)) != GS_Common::tostr(n)) {
      return iDefaultSize;
    }

    if (c == 'K') {
      return (size_t)(n * 1024);
    }
    if (c == 'M') {
      return (size_t)(n * 1024 * 1024);
    }
    if (c == 'G') {
      return (size_t)(n * 1024 * 1024 * 1024);
    }
  }

  return iDefaultSize;
}

string GS_Common::getHostName() {
  string hostName;
  char buff[256] = {0};
  int ret = ::gethostname(buff, sizeof(buff));
  if (0 == ret) {
    hostName = string(buff);
  } else {
    // 获取不到host， 则直接传空串。
  }
  return hostName;
}

#if TARGET_PLATFORM_LINUX || TARGET_PLATFORM_IOS

// Generate the randome string, a SHA1-sized random number
void GS_Common::getRandomHexChars(char *p, unsigned int len) {
  const char *const chars = "0123456789abcdef";
  FILE *fp = fopen("/dev/urandom", "r");
  if (!fp || fread(p, len, 1, fp) == 0) {
    for (unsigned int j = 0; j < len; j++) p[j] ^= rand();
  }

  if (fp) fclose(fp);

  for (unsigned int j = 0; j < len; j++) p[j] = chars[p[j] & 0x0F];
}

#endif

string GS_Common::nextDate(const string &sDate) {
  time_t tomorrow = GS_Common::str2time(sDate + "000000", "%Y%m%d%H%M%S") + 60 * 60 * 24;

  return GS_Common::tm2str(tomorrow, "%Y%m%d");
}

string GS_Common::prevDate(const string &sDate) {
  time_t tomorrow = GS_Common::str2time(sDate + "000000", "%Y%m%d%H%M%S") - 60 * 60 * 24;

  return GS_Common::tm2str(tomorrow, "%Y%m%d");
}

int GS_Common::nextDate(int iDate) { return GS_Common::strto<int>(nextDate(GS_Common::tostr(iDate))); }

int GS_Common::prevDate(int iDate) { return GS_Common::strto<int>(prevDate(GS_Common::tostr(iDate))); }

string GS_Common::nextMonth(const string &sMonth) {
  if (sMonth.length() != 6) {
    return "197001";
  }
  int year = GS_Common::strto<int>(sMonth.substr(0, 4));
  int month = GS_Common::strto<int>(sMonth.substr(4, 2));

  int monthNew = month + 1;
  int yearNew = year;
  if (monthNew == 13) {
    monthNew = 1;
    yearNew = year + 1;
  }

  yearNew = (yearNew >= 1970 && yearNew <= 9999) ? yearNew : 1970;
  monthNew = (monthNew >= 1 && monthNew <= 12) ? monthNew : 0;

  char szMonth[4] = {0};
  snprintf(szMonth, sizeof(szMonth) - 1, "%02d", monthNew);
  return GS_Common::tostr(yearNew) + szMonth;
}

string GS_Common::prevMonth(const string &sMonth) {
  if (sMonth.length() != 6) {
    return "197001";
  }
  int year = GS_Common::strto<int>(sMonth.substr(0, 4));
  int month = GS_Common::strto<int>(sMonth.substr(4, 2));

  int monthNew = month - 1;
  int yearNew = year;
  if (monthNew == 0) {
    monthNew = 12;
    yearNew = year - 1;
  }
  yearNew = (yearNew >= 1970 && yearNew <= 9999) ? yearNew : 1970;
  monthNew = (monthNew >= 1 && monthNew <= 12) ? monthNew : 0;

  char szMonth[4] = {0};
  snprintf(szMonth, sizeof(szMonth) - 1, "%02d", monthNew);
  return GS_Common::tostr(yearNew) + szMonth;
}

string GS_Common::nextYear(const string &sYear) {
  if (sYear.length() != 4) {
    return "1970";
  }
  int year = GS_Common::strto<int>(sYear.substr(0, 4));
  int yearNew = year + 1;

  yearNew = (yearNew >= 1970 && yearNew <= 9999) ? yearNew : 1970;

  return GS_Common::tostr(yearNew);
}

string GS_Common::prevYear(const string &sYear) {
  if (sYear.length() != 4) {
    return "1970";
  }
  int year = GS_Common::strto<int>(sYear.substr(0, 4));
  int yearNew = year - 1;

  yearNew = (yearNew >= 1970 && yearNew <= 9999) ? yearNew : 1970;

  return GS_Common::tostr(yearNew);
}

int GS_Common::secondsToDateInt(time_t seconds) {
  struct tm tt;

  GS_Common::tm2tm(seconds, tt);
  return (1900 + tt.tm_year) * 10000 + (tt.tm_mon + 1) * 100 + tt.tm_mday;
}

string GS_Common::secondsToDateString(time_t seconds) { return GS_Common::tostr(secondsToDateInt(seconds)); }

string GS_Common::secondsToMondayString(time_t seconds) {
  //换到周一
  int week = GS_Common::strto<int>(GS_Common::tm2str(seconds, "%w"));
  seconds -= (week - 1) * 86400;

  return GS_Common::tm2str(seconds, "%Y%m%d");
}

string GS_Common::secondsToMonthString(time_t seconds) { return GS_Common::tm2str(seconds, "%Y-%m"); }

string GS_Common::msToTimeString(int64_t ms) {
  int64_t sec = ms / 1000;
  int64_t msec = ms % 1000;

  char szMS[5] = {0};
  snprintf(szMS, sizeof(szMS) - 1, "%03d", (int)msec);

  return GS_Common::tm2str(sec, "%Y%m%d-%H%M%S-") + string(szMS);
}

int64_t GS_Common::timeStringToMs(const string &timeStr) {
  vector<string> vt = GS_Common::sepstr<string>(timeStr, "-");
  if (vt.size() != 3) {
    return 0;
  }

  string &date = vt[0];
  string &time = vt[1];
  string &ms = vt[2];

  if (date.size() != 8 || time.size() != 6 || ms.size() != 3) {
    return 0;
  }

  int64_t lsec = GS_Common::str2time(date + time);
  int64_t lms = GS_Common::strto<int64_t>(ms);

  return lsec * 1000 + lms;
}

bool GS_Common::getSectionFromMs(int64_t ms, string &date, string &time, string &mstick) {
  string timeStr = msToTimeString(ms);
  vector<string> vt = GS_Common::sepstr<string>(timeStr, "-");
  if (vt.size() != 3) {
    return false;
  }

  date = vt[0];
  time = vt[1];
  mstick = vt[2];

  return true;
}

string GS_Common::getDateFromMs(int64_t ms) {
  string date;
  string time;
  string mstick;
  if (!getSectionFromMs(ms, date, time, mstick)) {
    return "00000000";
  }

  return date;
}

string GS_Common::getTimeFromMs(int64_t ms) {
  string date;
  string time;
  string mstick;
  if (!getSectionFromMs(ms, date, time, mstick)) {
    return "000000";
  }

  return time;
}

int GS_Common::msToNowSeconds(int64_t ms) {
  int64_t sec = ms / 1000;

  //换成当天的秒
  int64_t now = GS_Common::str2time(GS_Common::tm2str(sec, "%Y%m%d") + "000000", "%Y%m%d%H%M%S");

  return (sec - now);
}

int GS_Common::nowDaySeconds() { return GS_Common::msToNowSeconds(GS_Common::now2ms()); }

int64_t GS_Common::msToNowMs(int64_t ms) {
  int64_t sec = ms / 1000;

  //换成当天的秒
  int64_t now = GS_Common::str2time(GS_Common::tm2str(sec, "%Y%m%d") + "000000", "%Y%m%d%H%M%S");

  return now * 1000;
}

int64_t GS_Common::us() {
  struct timeval tv;
  GS_Common::gettimeofday(tv);
  return tv.tv_sec * (int64_t)1000000 + tv.tv_usec;
}

int64_t GS_Common::dateToMs(const string &sDate) {
  int64_t now;

  if (sDate.find('-') != string::npos) {
    now = GS_Common::str2time(sDate + "000000", "%Y-%m-%d%H%M%S");
  } else {
    //换成当天的秒
    now = GS_Common::str2time(sDate + "000000", "%Y%m%d%H%M%S");
  }

  return now * 1000;
}

int64_t GS_Common::dateToSecond(const string &sDate) {
  int64_t now;

  if (sDate.find('-') != string::npos) {
    now = GS_Common::str2time(sDate + "000000", "%Y-%m-%d%H%M%S");
  } else {
    //换成当天的秒
    now = GS_Common::str2time(sDate + "000000", "%Y%m%d%H%M%S");
  }

  return now;
}

int GS_Common::dateTo(const string &sDate, const string &sPeriod) {
  if (sPeriod == "W") {
    return dateToWeek(sDate);
  } else if (sPeriod == "M") {
    return dateToMonth(sDate);
  } else if (sPeriod == "Q") {
    return dateToSeason(sDate);
  } else if (sPeriod == "S") {
    return dateToHalfYear(sDate);
  } else if (sPeriod == "Y") {
    return dateToYear(sDate);
  }

  return 0;
}

int GS_Common::dateToWeekday(const string &sDate) {
  struct tm date;
  GS_Common::str2tm(sDate, "%Y%m%d", date);

  return date.tm_wday;
}

int GS_Common::dateToWeek(const string &sDate) {
  struct tm date;
  GS_Common::str2tm(sDate, "%Y%m%d", date);

  return GS_Common::strto<int>(GS_Common::tm2str(date, "%W"));
}

int GS_Common::dateToMonth(const string &sDate) { return GS_Common::strto<int>(sDate.substr(4, 2)); }

int GS_Common::dateToSeason(const string &sDate) {
  string month = sDate.substr(4, 2);
  if (month == "01" || (month == "02") || (month == "03")) {
    return 1;
  } else if (month == "04" || (month == "05") || (month == "06")) {
    return 2;
  } else if (month == "07" || (month == "08") || (month == "09")) {
    return 3;
  } else if (month == "10" || (month == "11") || (month == "12")) {
    return 4;
  }

  return 0;
}

int GS_Common::dateToHalfYear(const string &sDate) {
  string month = sDate.substr(4, 2);
  if (month == "01" || (month == "02") || (month == "03") || (month == "04") || (month == "05") || (month == "06")) {
    return 1;
  } else if (month == "07" || (month == "08") || (month == "09") || (month == "10") || (month == "11") ||
             (month == "12")) {
    return 2;
  }

  return 0;
}

int GS_Common::dateToYear(const string &sDate) { return GS_Common::strto<int>(sDate.substr(0, 4)); }

int64_t GS_Common::timeToDaySec(int64_t hour, int64_t min) { return hour * 3600 + min * 60; }

int64_t GS_Common::getNextAbsClockMs(int64_t clockSec) {
  int64_t now = GS_Common::now2ms();
  int64_t nowSec = GS_Common::msToNowSeconds(now);
  int64_t currentDateMs = GS_Common::dateToMs(GS_Common::getDateFromMs(now));

  //如果已经超过了通知时间,则改到第二天继续通知
  int64_t notityRealTimeMs = 0;
  if (nowSec > clockSec + 1) {
    notityRealTimeMs = currentDateMs + clockSec * 1000 + ONE_DAY_MS;
  } else {
    notityRealTimeMs = currentDateMs + clockSec * 1000;
  }

  return notityRealTimeMs;
}

int GS_Common::nextDate(int iDate, int offset) {
  if (offset == 0) {
    return iDate;
  } else if (offset < 0) {
    return prevDate(iDate, std::abs(offset));
  }
  time_t t = GS_Common::str2time(GS_Common::tostr(iDate * 1000000LL));
  t = t + ONE_DAY_SEC * offset;
  return GS_Common::strto<int>(GS_Common::tm2str(t, "%Y%m%d"));
}

int GS_Common::prevDate(int iDate, int offset) {
  if (offset == 0) {
    return iDate;
  } else if (offset < 0) {
    return nextDate(iDate, std::abs(offset));
  }
  time_t t = GS_Common::str2time(GS_Common::tostr(iDate * 1000000LL));
  t = t - ONE_DAY_SEC * offset;
  return GS_Common::strto<int>(GS_Common::tm2str(t, "%Y%m%d"));
}

int GS_Common::lastDate(int iDate, const char period) {
  if (period == 'D') {
    return iDate;
  }
  switch (period) {
    case 'W':  // 周日为一周的开始, 周六结束
    {
      struct tm t;
      int rc = GS_Common::str2tm(GS_Common::tostr(iDate), "%Y%m%d", t);
      if (rc != 0) {
        return rc;
      }
      if (t.tm_wday == 6) {
        return iDate;
      }

      int offset = 6 - t.tm_wday;  // 下周六
      return nextDate(iDate, offset);
    }
    case 'M':  // 下月一号的上一天是一个月的开始
    {
      int month = iDate / 10000;
      month = iDate - month * 10000;
      month = month / 100;
      int monthDateStart = ((iDate / 10000)) * 10000 + (month + 1) * 100 + 1;  // 下月初
      if (month == 12) {
        monthDateStart = ((iDate / 10000) + 1) * 10000 + (0 + 1) * 100 + 1;  // 下年一月初
      }
      return prevDate(monthDateStart, 1);  // 上一天: 上月底
    }
    case 'Q':  // 331, 630, 930, 1231
    {
      const int seasonDateEnd[4] = {331, 630, 930, 1231};
      std::function<int(int)> date2season = [](int date) {
        int month = date / 10000;
        month = date - month * 10000;
        month = month / 100;
        return ((month - 1) / 3);
      };
      return ((iDate / 10000)) * 10000 + seasonDateEnd[date2season(iDate)];
    }
    case 'S':  // 631, 1231
    {
      int tmp = ((iDate / 10000)) * 10000 + 631;
      if (iDate > tmp) {
        return ((iDate / 10000)) * 10000 + 1231;
      } else {
        return tmp;
      }
    } break;
    case 'Y':  // 1231
    {
      return ((iDate / 10000)) * 10000 + 1231;
    }
    default:
      return -1;
  }
}

// 判断两个日期是否在同一周期中
inline bool GS_Common::matchPeriod(int lastDate, int date, const std::string &period) {
  if (lastDate == 0 || date == 0) {
    return false;
  }
  if (period == "W") {
    int a = GS_Common::dateToWeek(GS_Common::tostr(lastDate));
    int b = GS_Common::dateToWeek(GS_Common::tostr(date));
    return a == b;
  } else if (period == "M") {
    int a = GS_Common::dateToMonth(GS_Common::tostr(lastDate));
    int b = GS_Common::dateToMonth(GS_Common::tostr(date));
    return a == b;
  } else if (period == "Q") {
    int a = GS_Common::dateToSeason(GS_Common::tostr(lastDate));
    int b = GS_Common::dateToSeason(GS_Common::tostr(date));
    return a == b;
  } else if (period == "S") {
    int a = GS_Common::dateToHalfYear(GS_Common::tostr(lastDate));
    int b = GS_Common::dateToHalfYear(GS_Common::tostr(date));
    return a == b;
  } else if (period == "Y") {
    int a = GS_Common::dateToYear(GS_Common::tostr(lastDate));
    int b = GS_Common::dateToYear(GS_Common::tostr(date));
    return a == b;
  }
  return false;
}

int GS_Common::getMatchPeriodDays(const std::vector<int> &days, const std::pair<string, int> &period,
                                  std::vector<int> &matchDays) {
  std::map<std::string, int> periodList{{"W", 5}, {"M", 25}, {"Q", 25 * 3}, {"S", 25 * 3 * 2}, {"Y", 256}};
  std::string p = GS_Common::upper(period.first);
  if (periodList.find(p) == periodList.end()) {
    return -1;
  } else if ((periodList.at(p) < std::abs(period.second)) || period.second == 0) {
    return -1;
  }

  // 按周期切片
  std::vector<std::vector<int>> slice;
  int lastDate = 0;
  int idx = 0;
  for (auto const d : days) {
    if (d <= 0) {
      continue;
    }
    // 第一次必然不匹配 lastDate == 0
    if (!GS_Common::matchPeriod(d, lastDate, p)) {
      lastDate = d;
      slice.emplace_back(std::vector<int>());
      idx++;
    }
    slice[idx - 1].push_back(d);
  }

  // 在周期切片中按下标取对应的数据
  for (auto const &v : slice) {
    if (std::abs(period.second) > v.size()) {
      continue;
    }
    if (period.second > 0) {
      matchDays.push_back(v.at(period.second - 1));
    } else if (period.second < 0) {
      matchDays.push_back(v.at(v.size() + period.second));
    }
  }
  return 0;
}

}  // namespace common
