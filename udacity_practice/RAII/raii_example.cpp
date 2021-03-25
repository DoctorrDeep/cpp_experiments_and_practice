#include <iostream>

class MyInt { 
// the object itself will be in stack but will deal wioth memaory addresses in the heap.
// Since `delete` is called here, it frees the main() from having to call delete on initialized heap data.
private:
  int *_p; // pointer to heap data

public:
  MyInt(int *p = NULL) { 
    _p = p;
    std::cout << "\nresource " << *_p << " at " << _p << " allocated" << std::endl;
  }

  ~MyInt() {
    std::cout << "resource " << *_p << " at " << _p << " deallocated" << std::endl;
    delete _p;
  }

  int &operator*() { return *_p;}
};

int main() {

  double den[] = {1.0, 2.0, 3.0, 4.0, 5.0};

  for (size_t i = 0; i < 5; i++) {

    // allocate resource on the stack
    MyInt en(new int(i)); // `new int(i)` creates a memory block in heap and initializes it with value i.
                          // and returns the new memory address to `MyInt en()`
                          // The deallocation of `en` will happen as soon as the object goes out of scope (next cycle of the loop)

    // use the resource
    std::cout << *en << "/" << den[i] << " = " << *en / den[i] << std::endl;
  }

  return 0;
}

// OUTPUT

// resource 0 at 0x55b5b2e1beb0 allocated
// 0/1 = 0
// resource 0 at 0x55b5b2e1beb0 deallocated

// resource 1 at 0x55b5b2e1beb0 allocated
// 1/2 = 0.5
// resource 1 at 0x55b5b2e1beb0 deallocated

// resource 2 at 0x55b5b2e1beb0 allocated
// 2/3 = 0.666667
// resource 2 at 0x55b5b2e1beb0 deallocated

// resource 3 at 0x55b5b2e1beb0 allocated
// 3/4 = 0.75
// resource 3 at 0x55b5b2e1beb0 deallocated

// resource 4 at 0x55b5b2e1beb0 allocated
// 4/5 = 0.8
// resource 4 at 0x55b5b2e1beb0 deallocated