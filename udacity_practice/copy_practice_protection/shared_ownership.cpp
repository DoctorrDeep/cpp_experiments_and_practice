#include <iostream>

class SharedCopy {
private:
  int *_myInt;
  static int _cnt; // _cnt will be shared by all objects of class

public:
  SharedCopy(int val);
  ~SharedCopy();
  SharedCopy(SharedCopy &source);
};

// initialize static var
int SharedCopy::_cnt = 0;

// Constructor for SharedCopy object
SharedCopy::SharedCopy(int val) { // only inout is 42
  _myInt = (int *)malloc(sizeof(int));
  *_myInt = val;
  ++_cnt;
  std::cout << "resource allocated at address " << _myInt << std::endl;
}

// Destructor for SharedCopy object
SharedCopy::~SharedCopy() {
  --_cnt;
  if (_cnt == 0) {
    free(_myInt);
    std::cout << "resource freed at address " << _myInt << std::endl;
  } else {
    std::cout << "instance at address " << this << " (object pointer) goes out of scope with _cnt = " << _cnt << std::endl;
  }
}

// Control how copy is done : copy constructor
SharedCopy::SharedCopy(SharedCopy &source) {
  _myInt = source._myInt;
  ++_cnt;
  std::cout << _cnt << " instances with handles to address " << _myInt << " (resource pointer) with _myInt = " << *_myInt << std::endl;
}

int main() {
  SharedCopy source(42);
  SharedCopy destination1(source);
  SharedCopy destination2 = destination1;
  SharedCopy destination3(source);
  SharedCopy destination4(source);

  return 0;
}

//Output

// resource allocated at address 0x55dee8a9deb0
// 2 instances with handles to address 0x55dee8a9deb0 with _myInt = 42
// 3 instances with handles to address 0x55dee8a9deb0 with _myInt = 42
// 4 instances with handles to address 0x55dee8a9deb0 with _myInt = 42
// 5 instances with handles to address 0x55dee8a9deb0 with _myInt = 42
// instance at address 0x7ffc2b4ef900 goes out of scope with _cnt = 4
// instance at address 0x7ffc2b4ef8f8 goes out of scope with _cnt = 3
// instance at address 0x7ffc2b4ef8f0 goes out of scope with _cnt = 2
// instance at address 0x7ffc2b4ef8e8 goes out of scope with _cnt = 1
// resource freed at address 0x55dee8a9deb0

// Rule of Three
// copy constructor, copy destructor, copy assignment operator(overloading)
// For any class, if you make 1, make the other 2

// In the above example the assignment operator was not used and thus might lead to the counter variable not being properly decremented
// (note: i did not notice the improper decrement fron destination2)