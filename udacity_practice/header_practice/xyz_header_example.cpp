// To run this file :
// g++ xyz_header_example.cpp && ./a.out
// note: g++ xyz_header_example.cpp will create the a.out file

// The contents of header_example.h are included in
// the corresponding .cpp file using quotes:
#include "header_example.h"

#include <iostream>
using std::cout;

void OuterFunction(int i) { InnerFunction(i); }

void InnerFunction(int i) {
  cout << "The value of the integer is: " << i << "\n";
}

int main() {
  int a = 5;
  OuterFunction(a);
}