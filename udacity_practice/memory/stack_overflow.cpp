// cause stack overflow to calculate stack size
#include <iostream>

static int i = 1;

void MyFunc() {
  int k = 3;
  //   printf("3: %p \n", &k);
  std::cout << "3 stored at " << &k << " . Recursion depth " << i << "\n";
  i++;
  MyFunc();
}

int main() { MyFunc(); }

// Save the output of this file in a txt file
// g++ --std=c++17 stack_overflow.cpp && ./a.out > x.txt
// Segmentation fault (core dumped)
//
// copy the memory location (in hex) from first and last line of x.txt
//
// 3 stored at 0x7fffa6f6e404 . Recursion depth 1
// 3 stored at 0x7fffa6f6e3e4 . Recursion depth 2
// 3 stored at 0x7fffa6f6e3c4 . Recursion depth 3
// ...
// ...
// 3 stored at 0x7fffa6770a84 . Recursion depth 261837
// 3 stored at 0x7fffa6770a64 . Recursion depth 261838
// 3 stored at 0x7fffa6770a44 . Recursion de
//
// From this take teh 1st and last memory location
// 0x7fffa6f6e404, 0x7fffa6770a44
// Now to calculate the diff , cheat and use python REPL
//
// >>> (int("0x7fffa6f6e404", 16) - int("0x7fffa6770a44", 16))/(pow(2,20))
// 7.99066162109375
// >>>
//
// This shows that the size of the stack is 8 MB
// Also, note the address allocation is from end of the 8MB to beginning of 0MB
// Usually the operating system will do the allocation de-allocation
// automatically