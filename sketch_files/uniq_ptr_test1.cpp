#include <iostream>
#include <memory>
#include <string>

using std::cout;
using std::string;

// Raw pointers
class MyClass1r {
 public:
  // MyClass1r(string say) {
  //   *_say = say;
  //   cout << "Constructing MyClass1r\n";
  // };
  MyClass1r() {
    *_say = "what?";
    cout << "Constructing MyClass1r\n";
  };
  ~MyClass1r() {
    delete _say;
    cout << "Deconstructing MyClass1r\n";
  }

  void set_say(string new_say) { *_say = new_say; };

  string get_say() { return *_say; }

 private:
  string* _say = new string;
};

class MyClass2r {
 public:
  MyClass2r() {
    _say_class1 = new MyClass1r();
    cout << "Constructing MyClass2r\n";
  };
  ~MyClass2r() {
    delete _say_class1;
    cout << "Deconstructing MyClass2r\n";
  }

  MyClass1r* get_class1_handle() { return _say_class1; }

 private:
  MyClass1r* _say_class1;
};






// Unique ptr
class MyClass1u {
 public:
  //   MyClass1u(string say) {
  //   *_say = say;
  //   cout << "Constructing MyClass1u\n";
  // };
  MyClass1u() {
    _say = "What?";
    cout << "Constructing MyClass1u\n";
  };
  ~MyClass1u() { cout << "Deconstructing MyClass1u\n"; }

  void set_say(string new_say) { _say = new_say; };

  string get_say() { return _say; }

 private:
  string _say;
};

class MyClass2u {
 public:
  MyClass2u() {
    cout << "Constructing MyClass2u\n";
  }
  ~MyClass2u() {
    // delete _say_class1;
    cout << "Deconstructing MyClass2u\n";
  }

  MyClass1u* get_class1_handle() { return _say_class1.get();}

 private:
  std::unique_ptr<MyClass1u> _say_class1 = std::make_unique<MyClass1u>();
};



// Main!
int main() {

  cout << "\nRaw pointer based ops\n\n";
  MyClass2r* a_class = new MyClass2r();
  cout << a_class->get_class1_handle()->get_say() << std::endl;
  delete a_class;

  cout << "\nUnique pointer based ops\n\n";
  MyClass2u* b_class = new MyClass2u();
  cout << b_class->get_class1_handle()->get_say() << std::endl;
  b_class->get_class1_handle()->set_say("Say what?");
  cout << b_class->get_class1_handle()->get_say() << std::endl;
  delete b_class;
}