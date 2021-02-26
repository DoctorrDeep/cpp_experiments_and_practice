#include <iostream>
#include <stdlib.h>

class MyClass {
  int _mymember;
  // double _theirmember;

public:
  MyClass() { std::cout << "Constructor is called\n"; }
  ~MyClass() { std::cout << "Destructor is called\n"; }

  void *operator new[](size_t size) { // see explanation in `overloading_new_and_delete.cpp`. This one is for arrays
    std::cout << "new: Allocating " << size << " bytes of memory" << std::endl;
    void *p = malloc(size);

    return p;
  }

  void operator delete[](void *p) { // see explanation in `overloading_new_and_delete.cpp`. This one is for arrays.
    std::cout << "delete: Memory is freed again " << std::endl;
    free(p);
  }
};

int main() {
  MyClass *p = new MyClass[3]();
  delete[] p;
}

// std output

// new: Allocating 20 bytes of memory  // --> Notice how memory is instantiated BEFORE constructor is called
// Constructor is called // --> 3 times because 3 in line 25 "new MyClass[3]();"
// Constructor is called // --> 3 times because 3 in line 25 "new MyClass[3]();"
// Constructor is called // --> 3 times because 3 in line 25 "new MyClass[3]();"
// Destructor is called
// Destructor is called
// Destructor is called
// delete: Memory is freed again // --> Memory is deallocated AFTER the destructor is called

// Notice that int mem size 4, and size of array is 3. Hence the 1st line output shoudl have been
// `new: Allocating 12 bytes of memory`
// the additional 8 bytes is the compilers overhead reqd to keep track of allocated blocks of memory
// which itself consumes some memory. The plus 8 can be seen if size = 100 (expected 400, allocated 408)