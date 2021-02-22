#include <iostream>

void AddThree(int *val_ptr) {
  std::cout << val_ptr << " " << *val_ptr << " , Inside function, before +3\n";
  *val_ptr += 3;
  std::cout << val_ptr << " " << *val_ptr << " , Inside function, after +3\n";
}

int main() {
  int val = 0;
  std::cout << &val << " " << val << " , Main, Before func call\n";
  AddThree(&val);
  std::cout << &val << " " << val << " , Main, After func call\n";
  val += 2;
  std::cout << &val << " " << val
            << " , Main, After func call, After local increment\n";
}

// Output
//
// 0x7ffc57f4c5a4 0 , Main, Before func call
// 0x7ffc57f4c5a4 0 , Inside function, before +3
// 0x7ffc57f4c5a4 3 , Inside function, after +3
// 0x7ffc57f4c5a4 3 , Main, After func call
// 0x7ffc57f4c5a4 5 , Main, After func call, After local increment