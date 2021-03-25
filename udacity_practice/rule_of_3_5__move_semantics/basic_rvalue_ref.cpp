#include <iostream>

void myFunc(int &&i) {
  std::cout << "\nGot value " << i << std::endl;
  i++;
  std::cout << "Changed to value " << i << std::endl;
}

int myIntFunc(int &&i) {
  std::cout << "\nGot value " << i << std::endl;
  i++;
  std::cout << "Changed value to " << i << std::endl;
  return i;
}

int main() {
  // Case 1
  int i{40}, j{1};
  myFunc(i + j);

  // Case 2
  myFunc(42);

  // Case 3
  int c = myIntFunc(i + j);
  std::cout << "\nc: " << c << std::endl;

  // Case 4
  int d = myIntFunc(42);
  std::cout << "\nd: " << d << std::endl;

  // Case 5
  int m = 2;
  // myFunc(m);// errors
  // Output
  // basic_rvalue_ref.cpp:34:10: error: cannot bind rvalue reference of type ‘int&&’ to lvalue of type ‘int’
  //  34 |   myFunc(m);
  //     |          ^

  myFunc(std::move(m));
  m++; // according to docs after using m in `move` m should not 
       // be available in `main()` anymore. But here it is still usable.
       // compiling with `g++ --std=c++11` still works
  int n = myIntFunc(std::move(m));
  std::cout << "\nlvalue to rvalue :" << n << std::endl;
}

// Output

// Case 1:
// Got value 41
// Changed to value 42

// Case 2:
// Got value 42
// Changed to value 43

// Case 3:
// Got value 41
// Changed value to 42

// c: 42

// Case 4:
// Got value 42
// Changed value to 43

// d: 43

// Case 5:
// Got value 2
// Changed to value 3

// Got value 3
// Changed value to 4

// lvalue to rvalue :4