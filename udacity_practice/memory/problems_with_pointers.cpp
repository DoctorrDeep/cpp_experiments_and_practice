#include <iostream>
#include <stdlib.h>

int *f1(void) {

  // Wont work because the local variable x is destroyed after return.
  // Local variable is in stack which is reallocated by OS once
  // function handling is over. So, pointer to it is useless.
  // Will cause Segmentation fault.
  int x = 10;
  return &x;
}

int *f2(void) {

  // px is assigned value 10 without allocating space 
  // for the pointer in heap. Space was allocated only in stack 
  // which is reallocated by the OS once control is returned 
  // from this function. Hence, segmentation fault.
  int *px;
  *px = 10;
  return px;
}

int *f3(void) {

  // Works because malloc allocated memory in heap (not stack)
  // which persists even after the function is returned.
  int *px;
  px = (int *)malloc(sizeof(int));
  *px = 10;
  return px;
}

int *f4(void) {

  // Works because malloc allocated memory in heap (not stack)
  // which persists even after the function is returned.
  int *px = (int *)malloc(sizeof(int));
  *px = 10;
  return px;
}

int main() {

  int *x = f4();
  std::cout << x << " " << *x << "\n";
}