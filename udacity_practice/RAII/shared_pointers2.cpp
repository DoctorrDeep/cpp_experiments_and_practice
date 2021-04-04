#include <iostream>
#include <memory>

class MyClass {
public:
  ~MyClass() { std::cout << this << " obj of MyClass is being deleted \n"; }
};

int main() {

  std::shared_ptr<MyClass> class1(new MyClass);
  std::cout << class1.get() << " raw pointer location of class1 with count " << class1.use_count() << "\n";

  class1.reset(new MyClass);
  std::cout << class1.get() << " raw pointer location of class1 AFTER reset with count " << class1.use_count() << "\n";

  return 0;
}

// 0x55a6f5c4deb0 raw pointer location of class1 with count 1
// 0x55a6f5c4deb0 obj of MyClass is being deleted 
// 0x55a6f5c4e300 raw pointer location of class1 AFTER resetwith count 1
// 0x55a6f5c4e300 obj of MyClass is being deleted 