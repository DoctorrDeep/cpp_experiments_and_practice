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

void myFunc(std::shared_ptr<MyClass> my_shr_ptr2){

  std::cout << "myFunc() pointer location " << &my_shr_ptr2;
  my_shr_ptr2->printVal();
  std::cout << "    Shared pointer use_count = " << my_shr_ptr2.use_count() << std::endl;
}

int main(){

  std::shared_ptr<MyClass> my_shr_ptr1 = std::make_shared<MyClass>(23);
  std::cout << "  main() pointer location " << &my_shr_ptr1;
  my_shr_ptr1->printVal();
  std::cout << "    Shared pointer use_count = " << my_shr_ptr1.use_count() << std::endl;

  myFunc(my_shr_ptr1); // a copy of the shared pointer will be made here. 
                       // Default copy actions by compiler is ideal here

  std::cout << "  main() pointer location " << &my_shr_ptr1;
  my_shr_ptr1->printVal();
  std::cout << "    Shared pointer use_count = " << my_shr_ptr1.use_count() << std::endl;

  return 0;
}

// OUTPUT ( AAA, BBB, XXX : simplified memory addresses )

//   main() pointer location AAA, manages obj instance at XXX, with val = 23
//     Shared pointer use_count = 1
// myFunc() pointer location BBB, manages obj instance at XXX, with val = 23
//     Shared pointer use_count = 2
//   main() pointer location AAA, manages obj instance at XXX, with val = 23
//     Shared pointer use_count = 1