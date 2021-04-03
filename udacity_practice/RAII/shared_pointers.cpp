#include <iostream>
#include <memory>

int main() {

  std::shared_ptr<int> my_shr_ptr1(new int{2});
  std::cout << "Pointer count" << my_shr_ptr1.use_count() << ", address " << my_shr_ptr1.get() << " with value " << *my_shr_ptr1  << "\n";

  {
    // This is defining a local scope. Once the control goes out of this curly braces
    // temp data in stack stack will be cleaned out (like, for example, a for-loop or function)
    // In this case: my_shr_ptr2
    std::shared_ptr<int> my_shr_ptr2 = my_shr_ptr1;
    std::cout << "Pointer count" << my_shr_ptr2.use_count() << ", address " << my_shr_ptr2.get() << " with value " << *my_shr_ptr2  << "\n";
  }

  std::cout << "Pointer count" << my_shr_ptr1.use_count() << ", address " << my_shr_ptr1.get() << " with value " << *my_shr_ptr1  << "\n";

  return 0;
}

// Output 

// Pointer count1, address 0x5644d0cbbeb0 with value 2
// Pointer count2, address 0x5644d0cbbeb0 with value 2
// Pointer count1, address 0x5644d0cbbeb0 with value 2