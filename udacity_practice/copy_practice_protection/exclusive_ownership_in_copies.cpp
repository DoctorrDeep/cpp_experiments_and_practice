#include <iostream>

class ExclusiveCopy {
private:
  int *_myInt;

public:
  // Constructor
  ExclusiveCopy() {
    _myInt = (int *)malloc(sizeof(int));
    std::cout << "resource allocated" << std::endl;
  }

  // destructor
  ~ExclusiveCopy() {
    if (_myInt != nullptr) {
      free(_myInt);
      std::cout << "resource freed" << std::endl;
    }
  }

  // Copy constructor
  ExclusiveCopy(ExclusiveCopy &source) {
    _myInt = source._myInt;
    source._myInt = nullptr;
  }

  // Copy assignment operator (operator overloading)
  ExclusiveCopy &operator=(ExclusiveCopy &source) {
    _myInt = source._myInt;
    source._myInt = nullptr;
    return *this;
  }
};

int main() {
  ExclusiveCopy source;
  ExclusiveCopy destination(source);
  ExclusiveCopy new_destination(destination);

  return 0;
}