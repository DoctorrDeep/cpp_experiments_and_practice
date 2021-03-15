#include <iostream>

void myFunction(int &val) { std::cout << "val = " << val << std::endl; }

int main() {

  // Case 1:
  int j = 42;
  myFunction(j);

  myFunction(42); // blocks compilation. comment to run case 2
  // errors because 42 is an rvalue and the finction expected an lvalue
  // Output :
  // r_value_references.cpp:9:14: error: cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’
  //   9 |   myFunction(42);
  //     |              ^~

  int k = 23;
  myFunction(j + k); // blocks compilation. comment to run case 2
  // j, k are l values but the output of `j+k` is a temporary value, an r value!
  // r_value_references.cpp:16:16: error: cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’
  //  16 |   myFunction(j + k);
  //     |              ~~^~~


  // Case 2:
  int a = 1; 
  int b = 2; 
  int c = a + b; // sum of `a` and `b` are created temporarily as an rvalue 
                 // which is copied to memory location `c` the lvalue
  int &&d = a + b; // sum of `a` and `b` are created temporarily
                   // the rvalue reference allows holding the temporary memory directly as `d`
  std::cout << "c = " << c << ", d = " << d << std::endl;
  return 0;
}