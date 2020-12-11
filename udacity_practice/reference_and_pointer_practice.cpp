#include <iostream>
using std::cout;

int *AddOne(int &j) {
  // Increment the referenced int and return the
  // address of j.
  j++;
  int k = j;
  cout << "j is " << j << "\n";
  cout << "j is saved at " << &j << "\n";
  cout << "k is " << k << "\n";
  cout << "k is saved at " << &k << "\n";

  return &j;
  // return &k;

  // if k's pointer is returned it goes out of scope for main().
  // Warnign is raised. The executable is executed and runs intot a segmentation
  // fault
}

int main() {
  int i = 1;
  cout << "The value of i is: " << i << "\n";
  cout << "i is saved at " << &i << "\n";

  // Declare a pointer and initialize to the value
  // returned by AddOne:
  int *my_pointer = AddOne(i);
  cout << "The value of i is now: " << i << "\n";
  cout << "The value of the int pointed to by my_pointer is: " << *my_pointer
       << "\n";
}