#include <iostream>

bool MyLocalFunction(int myInt) {
  bool isBelowThreshold = myInt < 42 ? true : false;
  std::cout << &isBelowThreshold << "\n";
  return isBelowThreshold;
}

int main() {
  bool res = MyLocalFunction(23);
  std::cout << &res << "\n";
  return 0;
}