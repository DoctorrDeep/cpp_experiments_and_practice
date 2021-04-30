#include <iostream>
#include <memory>
#include <string>

using std::cout;
using std::string;

class MyClass {

private:
  std::string _my_text;

public:
  MyClass() {} // Constructor variation 1 (without text)
  MyClass(string text) { _my_text = text; } // Constructor variation 2(with text)
  ~MyClass() {
    cout << "Delete " << this << " containing " << _my_text << "\n";
  }
  void set_text(string text) { _my_text = text; }
};

int main() {

  std::unique_ptr<MyClass> class1(new MyClass());
  std::unique_ptr<MyClass> class2(new MyClass("Hey yo string2!"));

  // The instances of MyClass live on the heap.
  // class1 and class2 are the pointers managing the heap objects
  // class1 and class2 live on the stack.

  class1->set_text("Hi there string1!");

  *class1 = *class2;

  cout << "Unique pointer objects have stack addresses \n";
  cout << class1.get() << "    class1\n"; // access internal raw_pointer with `.get()`
  cout << class2.get() << "    class2\n"; // access internal raw_pointer with `.get()`

  // Notice again in the output
  // The destructors for class1 and class2 were not explicitly called here
  // However the output shows that the destructors were automatically called and
  // the resources of class1 and class2 were let go of.


  // Raw pointer implementation of the above (bad)

  MyClass *class3 = new MyClass();
  MyClass *class4 = new MyClass("Hey yo string4!");

  class3->set_text("Hi there string3!");

  *class3 = *class4;

  cout << "Raw pointer objects have heap addresses \n"; // since they were made with bare `new`
  cout << class3 << "    class3\n";
  cout << class4 << "    class4\n";

  delete class3; // delete has to be explicitly called
  delete class4; // delete has to be explicitly called
}


// OUTPUT (Memory addresses simplified for readability)

// Unique pointer objects have stack addresses
// AAAA    class1
// BBBB    class2

// Raw pointer objects have addresses
// CCCC    class3
// DDDD    class4

// Delete CCCC containing Hey yo string4! --> Raw (only when delete is explicitly called)  (class3)
// Delete DDDD containing Hey yo string4! --> Raw (only when delete is explicitly called)  (class4)

// Delete BBBB containing Hey yo string2! --> Uniq (class2)
// Delete AAAA containing Hey yo string2! --> Uniq (class1)
