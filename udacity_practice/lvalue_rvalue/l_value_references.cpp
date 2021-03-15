#include <iostream>

void increasebyone(int &i) { ++i;}

int main() {
  // Case 1: lvalue reference as an alternative name for object
  int i = 1;
  int &j = i; // j is a reference to i now.
              // any action on j or i will change both values
              // Both value are in the same memory location in stack.
              // see output below
  ++i;
  std::cout << "i = " << i << ", j = " << j << std::endl;
  ++j;
  std::cout << "i = " << i << ", j = " << j << std::endl;
  j = 23;
  std::cout << "i = " << i << ", j = " << j << std::endl;

  // Case 2: Pass by reference semantics
  int k{0};
  std::cout << "k: " << k << std::endl;
  increasebyone(k);
  std::cout << "k: " << k << std::endl;

  return 0;
}

// Output
// Case 1
// i = 2, j = 2
// i = 3, j = 3
// i = 23, j = 23

// Case 2
// k: 0
// k: 1