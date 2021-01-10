#include <assert.h>

// TODO: Declare a generic, templatized function Max()
template <typename T> T Max(T a, T b) {

  // Option 1: generic if
  // if (a > b)
  //   return a;
  // return b;

  // Option 2: ternary operator
  return a > b ? a : b;
}

int main() {
  assert(Max<int>(10, 50) == 50);
  assert(Max(10, 50) == 50); // Deduced type of input
  assert(Max<double>(5.7, 1.436246) == 5.7);
  assert(Max(5.7, 1.436246) == 5.7); // Deduced type of input
}