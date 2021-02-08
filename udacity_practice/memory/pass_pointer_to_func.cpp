#include <iostream>

void AddThree(int *val) {
  std::cout << &val << " " << *val << " , Inside function, before +3\n";
  *val += 3;
  std::cout << &val << " " << *val << " , Inside function, after +3\n";
}

int main() {
  int val = 0;
  std::cout << &val << " " << val << " , Main, Before func call\n";
  AddThree(&val);
  std::cout << &val << " " << val << " , Main, After func call\n";
  val += 2;
  std::cout << &val << " " << val << " , Main, After func call, After local increment\n";
}

// Output
//
// 0x7ffeb530ac44 0 , Main, Before func call
// 0x7ffeb530ac28 0 , Inside function, before +3
// 0x7ffeb530ac28 3 , Inside function, after +3
// 0x7ffeb530ac44 3 , Main, After func call
// 0x7ffeb530ac44 5 , Main, After func call, After local increment
// 
// I expected all to have the same memory address..