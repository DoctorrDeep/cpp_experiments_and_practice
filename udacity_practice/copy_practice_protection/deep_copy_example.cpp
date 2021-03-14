#include <iostream>

class DeepCopy {
private:
  int *_myInt;

public:
  // constructor
  DeepCopy(int val) {
    _myInt = (int *)malloc(sizeof(int));
    *_myInt = val;
    std::cout << "resource allocated at address " << _myInt << std::endl;
  }
  // destructor
  ~DeepCopy() {
    free(_myInt);
    std::cout << "resource freed at address " << _myInt << std::endl;
  }

  // copy constructor
  DeepCopy(DeepCopy &source) {
    _myInt = (int *)malloc(sizeof(int)); // make pointer to unused heap
    *_myInt = *source._myInt; // copy source value to  new heap location
    std::cout << "resource allocated at address " << _myInt << " with _myInt = " << *_myInt << std::endl;
  }

  // copy assignment operator
  DeepCopy &operator=(DeepCopy &source) {
    _myInt = (int *)malloc(sizeof(int)); // make pointer to unused heap
    std::cout << "resource allocated at address " << _myInt << " with _myInt=" << *_myInt << std::endl;
    *_myInt = *source._myInt; // copy source value to  new heap location
    return *this;
  }
};

int main() {
  DeepCopy source(42);
  DeepCopy dest1(source);
  DeepCopy dest2 = dest1;
  DeepCopy dest3 = source;

  return 0;
}

// Output

// resource allocated at address 0x55f6faf9deb0  --> source(42)
// resource allocated at address 0x55f6faf9e2e0 with _myInt = 42 --> dest1 (1st copy of source)
// resource allocated at address 0x55f6faf9e300 with _myInt = 42 --> dest2 (copy of dest1)
// resource allocated at address 0x55f6faf9e320 with _myInt = 42 --> dest3 (2nd copy of source)
// resource freed at address 0x55f6faf9e320  --> dest3
// resource freed at address 0x55f6faf9e300  --> dest2
// resource freed at address 0x55f6faf9e2e0  --> dest1
// resource freed at address 0x55f6faf9deb0  --> source(42)