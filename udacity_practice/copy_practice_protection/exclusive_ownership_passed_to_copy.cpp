#include <iostream>

class ExclusiveCopy {
private:
  int *_myInt;

public:
  ExclusiveCopy() {
    _myInt = (int *)malloc(sizeof(int));
    std::cout << "resource allocated to " << _myInt << std::endl;
  }
  ~ExclusiveCopy() {
    if (_myInt != nullptr) {
      free(_myInt);
      std::cout << "resource freed from " << _myInt << std::endl;
    } else {
      std::cout << "resource NOT freed from " << _myInt << " since its already a nullptr." << std::endl;
    }
  }

  // Copy constructor
  ExclusiveCopy(ExclusiveCopy &source) {
    _myInt = source._myInt; // the pointer to heap memory is copied to new/copy object
    source._myInt = nullptr; // the pointer to the heap memory is removed from the original
    std::cout << "resource tranferred to copy : location of original resource " << source._myInt << std::endl;
    std::cout << "resource tranferred to copy : location of copy resource " << _myInt << std::endl;
  }

  // Copy assignment operator
  ExclusiveCopy &operator=(ExclusiveCopy &source) { // override the copy operator (NOT USED in examples below)
    _myInt = source._myInt; // the pointer to heap memory is copied to new/copy object
    source._myInt = nullptr; // the pointer to the heap memory is removed from the original
    std::cout << "resource tranferred to copy : location of original resource " << source._myInt << std::endl; 
    std::cout << "resource tranferred to copy : location of copy resource " << _myInt << std::endl;
    return *this;
  }
};

int main() {
  std::cout << "\nCase 1: \nThe original is copied twice\n\n";
  ExclusiveCopy source1;
  // ExclusiveCopy sourceX=source1;
  ExclusiveCopy destination1(source1);
  ExclusiveCopy new_destination1(source1);

  std::cout << "\n\nCase 2: \nThe original is copied once\nThe copy is then copied again\n\n";
  ExclusiveCopy source2;
  ExclusiveCopy destination2(source2);
  ExclusiveCopy new_destination2(destination2);

  return 0;
}

// Output

// Case 1: 
// The original is copied twice

// resource allocated to 0x55c1ce0ae2c0
// resource tranferred to copy : location of original resource 0
// resource tranferred to copy : location of copy resource 0x55c1ce0ae2c0
// resource tranferred to copy : location of original resource 0
// resource tranferred to copy : location of copy resource 0


// Case 2: 
// The original is copied once
// The copy is then copied again

// resource allocated to 0x55c1ce0ae2e0
// resource tranferred to copy : location of original resource 0
// resource tranferred to copy : location of copy resource 0x55c1ce0ae2e0
// resource tranferred to copy : location of original resource 0
// resource tranferred to copy : location of copy resource 0x55c1ce0ae2e0
// resource freed from 0x55c1ce0ae2e0                     ---> from Case 2  new_destination2 (final copy had the pointer)
// resource NOT freed from 0 since its already a nullptr. ---> from Case 2  destination2
// resource NOT freed from 0 since its already a nullptr. ---> from Case 2  source2
// resource NOT freed from 0 since its already a nullptr. ---> from Case 1  new_destination1 (second copy of the original had null pointer)
// resource freed from 0x55c1ce0ae2c0                     ---> from Case 1  destination1 (first copy of the original had pointer)
// resource NOT freed from 0 since its already a nullptr. ---> from Case 1  source1