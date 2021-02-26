#include <iostream>
#include <stdlib.h>

class MyClass {
  int _mymember;
  // double _theirmember;

public:
  MyClass() { std::cout << "Constructor is called\n"; }
  ~MyClass() { std::cout << "Destructor is called\n"; }

  void *operator new(size_t size) { // This is how "new" is overloaded
                                    // `size_t size` is managed by the compiler.
                                    // Notice in line 32, `new MyClass()` has no
                                    // "size" component
    std::cout << "new: Allocating " << size << " bytes of memory" << std::endl;
    void *p = malloc(size); // this is the overloading part. It could have been "new"
                            // as well instead of malloc.
                            // now that the memory allocation has been
                            // overloaded, delete needs to be handled similarly by the
                            // programmer, not the compiler anymore.

    return p;
  }

  void operator delete(void *p) { // This is how delete is overloaded
    std::cout << "delete: Memory is freed again " << std::endl;
    free(p);
  }
};

int main() {
  MyClass *p = new MyClass();
  delete p;
}

// std Output for : int _mymember;

// new: Allocating 4 bytes of memory // --> Notice how memory is instantiated BEFORE constructor is called
// Constructor is called
// Destructor is called
// delete: Memory is freed again // --> Memory is deallocated AFTER the destructor is called


// std Output for : double _theirmember;

// new: Allocating 8 bytes of memory 
// Constructor is called
// Destructor is called
// delete: Memory is freed again 


// std Output for : int _mymember;double _theirmember;

// new: Allocating 16 bytes of memory // --> Why? It should have been 12!
// Constructor is called
// Destructor is called
// delete: Memory is freed again 