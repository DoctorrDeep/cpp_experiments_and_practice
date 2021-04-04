#include <iostream>
#include <memory>

int main() {

  std::shared_ptr<int> a_shr_ptr(new int);
  std::weak_ptr<int> a_wk_ptr(a_shr_ptr);
  // std::cout << a_wk_ptr.get() << "a_wk_ptr is pointing to a null shared pointer\n";

  a_shr_ptr.reset(new int);

  if (a_wk_ptr.expired() == true) {
    std::cout << "a_wk_ptr is pointing to a null shared pointer\nCause: ";
    std::cout << a_shr_ptr.get() << " a_shr_ptr is pointing to a new object\n";
  }

  return 0;
}

// Output
// a_wk_ptr is pointing to a null shared pointer
// Cause: 0x5590356f3ef0 a_shr_ptr is pointing to a new object