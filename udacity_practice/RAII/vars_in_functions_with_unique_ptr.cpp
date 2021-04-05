#include <iostream>
#include <memory>

class MyClass {
public:
  MyClass(int member) : _member(member) {}
  void printVal() {
    std::cout << ", managed object " << this << " with val = " << _member
              << std::endl;
  }

private:
  int _member;
};

void myFunc(std::unique_ptr<MyClass> my_unq_ptr2) {
  std::cout << "Functions unique pointer : " << &my_unq_ptr2;
  my_unq_ptr2->printVal();
}

int main() {
  std::unique_ptr<MyClass> my_unq_ptr1 = std::make_unique<MyClass>(23);
  std::cout << "  main()s unique pointer : " << &my_unq_ptr1;
  my_unq_ptr1->printVal();

  myFunc(std::move(my_unq_ptr1));

  if (my_unq_ptr1) {
    my_unq_ptr1->printVal();
  }
  // The IF block is ignored since the original `my_unq_ptr1` was handed over to
  // `my_unq_ptr2` with "move" which destroys the original copy of the shared
  // pointer (default unique ptr implementation). The new `my_unq_ptr2` is
  // destroyed when the function scope finishes. No leak, no heap MyClass
  // anymore in main()!

  return 0;
}

// OUTPUT ( AAA, BBB, XXX : simplified memory addresses )

//   main()s unique pointer : AAA, managed object XXX with val = 23
// Functions unique pointer : BBB, managed object XXX with val = 23