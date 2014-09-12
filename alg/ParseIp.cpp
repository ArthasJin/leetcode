#include <fstream>
#include <iostream>
#include <cctype>
#include <cstdlib>

using namespace std;

typedef unsigned int uint;

uint ip2num(const char* buf) {
  uint res = 0, b = 0;
  for (; *buf;) {
    char c = *buf++;
    if (c == '.') {
      res = (res << 8) + b;
      b = 0;
    } else if (isdigit(c)) {
      b = b * 10 + (c - '0');
    } else {
      return (res << 8) + b;
    }
  }
  return (res << 8) + b;
}

