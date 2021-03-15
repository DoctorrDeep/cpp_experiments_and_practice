# include <iostream>

int main() {
  // initialize some variables on the stack
  int i, j, *p;

  // correct usage of lvalues and rvalues

  i = 42; // i is an lvalue and 42 is an rvalue

  p = new int;
  *p = i; // the dereferenced pointer is an lvalue
  delete p;

  ((i <= 42) ? i : j) = 23; // the conditional operator returns an lvalue (eiter i or j)
  std::cout << i << std::endl;
  std::cout << j << std::endl;

  // incorrect usage of lvalues and rvalues
  // 42 = i; // error : the left operand must be an lvalue
  // j * 42 = 23; // error : the left operand must be an lvalue
  // Error from compiler from the above:
  // example_l_r.cpp: In function ‘int main()’:
  // example_l_r.cpp:16:3: error: lvalue required as left operand of assignment
  //   16 |   42 = i; // error : the left operand must be an lvalue
  //      |   ^~
  // example_l_r.cpp:17:5: error: lvalue required as left operand of assignment
  //   17 |   j * 42 = 23; // error : the left operand must be an lvalue
  //      |   ~~^~~~

  return 0;
}

// Output
// 23  --> i
// 32767  --> garbage value at j