#include <iostream>
#include <memory>

class MyClass {
public:
  MyClass(int member) : _member(member) {}
  void printVal(){
    std::cout << ", manages obj instance at " << this << ", with val = " << _member << std::endl;
  }

private:
  int _member;
};

void myFunc(std::weak_ptr<MyClass> my_wk_ptr){

  std::cout << "myFunc() pointer location " << &my_wk_ptr << std::endl;
  std::cout << "    Shared pointer use_count = " << my_wk_ptr.use_count() << std::endl;
}

int main(){

  std::shared_ptr<MyClass> my_shr_ptr = std::make_shared<MyClass>(23);
  std::weak_ptr<MyClass> my_wk_ptr(my_shr_ptr);
  std::cout << "  main() pointer location " << &my_wk_ptr << std::endl;
  std::cout << "    Weak pointer use_count = " << my_wk_ptr.use_count() << std::endl;

  myFunc(my_wk_ptr); // a copy of the weak pointer will be made here. 
                     // Default copy actions by compiler is ideal here

  std::cout << "  main() pointer location " << &my_wk_ptr << std::endl;
  std::cout << "    Weak pointer use_count = " << my_wk_ptr.use_count() << std::endl;

  return 0;
}

// OUTPUT ( XXX, YYY : simplified memory addresses )

//   main() pointer location XXX
//     Shared pointer use_count = 1
// myFunc() pointer location YYY
//     Shared pointer use_count = 1
//   main() pointer location XXX
//     Shared pointer use_count = 1