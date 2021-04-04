#include <iostream>
#include <memory>

class MyClass {
public:
  ~MyClass() {
    std::cout << this << " raw pointer of obj of MyClass is being destroyed\n";
  }
  // private:
  std::shared_ptr<MyClass> _member;
};

int main() {

  std::shared_ptr<MyClass> class1(new MyClass);
  std::shared_ptr<MyClass> class2(new MyClass);

  class1->_member = class2;
  class2->_member = class1;
  // Without the above 2 lines (i.e. if the above lines are commented out)
  // there is no memory leak
  // Output
  // 0x562612f16ef0 raw pointer of obj of MyClass is being destroyed
  // 0x562612f16eb0 raw pointer of obj of MyClass is being destroyed

  return 0;
}
// Output:
// 
// (That was it. There was no output! Hence, memry leak.)

// Valgrind check:
// Create obj file for valgrind: `g++ shared_pointers3.cpp -o shared_pointers3`
// Run valgrind: `valgrind --verbose --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=shared_pointers3_valgrind_output.txt ./shared_pointers3`

// Juicy bits from the report
// ==5214== LEAK SUMMARY:
// ==5214==    definitely lost: 16 bytes in 1 blocks  ---> NOT good
// ==5214==    indirectly lost: 64 bytes in 3 blocks

// This is due to the circular reference that line 18 and line 19 introduce