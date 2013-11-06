#include "Middle.h"

namespace lab2 {

  Middle::Middle() : Date() {}
  Middle::Middle(int y, int m, int d) : Date(y,m,d) {}
  Middle::Middle(unsigned long long num) : Date(num) {}
  Middle::Middle(const Date& d) : Date(d) {}
}
