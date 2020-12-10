// To run this code :
// g++ main.cpp increment_and_sum.cpp vect_add_one.cpp && ./a.out && rm a.out

#include "increment_and_sum.h"
#include <iostream>
#include <vector>
using std::cout;
using std::vector;

int main() {
  vector<int> v{1, 20, 3, 4};
  int total = IncrementAndComputeVectorSum(v);
  cout << "The total is: " << total << "\n";
}