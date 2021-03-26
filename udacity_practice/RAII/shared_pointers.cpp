#include <iostream>
#include <memory>

int main() {

  std::shared_ptr<int> my_shr_ptr1(new int{2});
  std::cout << "Pointer count" << my_shr_ptr1.use_count() << ", address " << my_shr_ptr1.get() << " with value " << *my_shr_ptr1  << "\n";

  {
    std::shared_ptr<int> my_shr_ptr2 = my_shr_ptr1;
    std::cout << "Pointer count" << my_shr_ptr2.use_count() << ", address " << my_shr_ptr2.get() << " with value " << *my_shr_ptr2  << "\n";
  }

  std::cout << "Pointer count" << my_shr_ptr1.use_count() << ", address " << my_shr_ptr1.get() << " with value " << *my_shr_ptr1  << "\n";

  return 0;
}