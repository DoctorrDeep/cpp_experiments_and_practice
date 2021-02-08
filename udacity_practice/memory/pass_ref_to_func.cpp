#include <iostream>

void AddFour(int &val) {
  std::cout << &val << " " << val << " , Inside function, before +4\n";
  val += 4;
  std::cout << &val << " " << val << " , Inside function, after +4\n";
}

int main() {
  int val = 0;
  std::cout << &val << " " << val << " , Main, Before func call\n";
  AddFour(val);
  std::cout << &val << " " << val << " , Main, After func call\n";
  val += 2;
  std::cout << &val << " " << val
            << " , Main, After func call, After local increment\n";
  return 0;
}

// Output as expected

// 0x7ffc0e0840d4 0 , Main, Before func call
// 0x7ffc0e0840d4 0 , Inside function, before +4
// 0x7ffc0e0840d4 4 , Inside function, after +4
// 0x7ffc0e0840d4 4 , Main, After func call
// 0x7ffc0e0840d4 6 , Main, After func call, After local increment
// val = 6