#include <iostream>
#include <stdlib.h>

class MyClass {
private:
  int _number;

public:
  MyClass() {
    std::cout << "Assign number\n";
    _number = 0;
  }

  void setNumber(int number) {
    _number = number;
    std::cout << "Number: " << _number << "\n";
  }
};

int main() {
  // [WORKS] allocate memory using new
  MyClass *myClass = new MyClass();
  myClass->setNumber(42); // works as expected
  delete myClass;

  return 0;
}