#include <memory>
#include <iostream>

void RawPointer() {
  int *my_raw_ptr = new int; // initialize pointer in heap
  *my_raw_ptr = 1;           // do something with it
   std::cout << "my_raw_ptr : " << my_raw_ptr << "\n";
  delete my_raw_ptr;         // deallocate pointer (i.e. delete the resource)
}

void UniquePointer() {
  std::unique_ptr<int> my_uniq_ptr(new int); // create a unique pointer on stack
  *my_uniq_ptr = 2;                          // assign a value
  std::cout << "my_uniq_ptr : " << my_uniq_ptr.get() << "\n";
  // delete is NOT necessary for unique pointers
  // as soon as `my_uniq_ptr` goes out of scope, it will be deallocated
  // NOTE: ALWAYS create smart pointers in stack, else the scoping mechanism will not work
}

int main(){
  RawPointer();
  UniquePointer();
  return 0;
}