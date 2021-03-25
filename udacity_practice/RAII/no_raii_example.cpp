#include <iostream>

int main() {

  double den[] = {1.0, 2.0, 3.0, 4.0, 5.0};

  for (size_t i = 0; i < 5; i++) {

    // allocate resource to the heap
    double *en = new double(i);

    // use the resource
    std::cout << *en << "/" << den[i] << " = " << *en / den[i] << std::endl;

    // deallocate resource
    delete en;
  }

  return 0;
}

// OUTPUT

// 0/1 = 0
// 1/2 = 0.5
// 2/3 = 0.666667
// 3/4 = 0.75
// 4/5 = 0.8

// The above follows the basic mem mgmt process:
// Allocate resource -> do something with resource -> deallocate resource
// BUT, it is possible to forget the deallocate 
// OR, if an exception happens before deallocate, the deallocate never takes place 
// HENCE: RAII is needed.