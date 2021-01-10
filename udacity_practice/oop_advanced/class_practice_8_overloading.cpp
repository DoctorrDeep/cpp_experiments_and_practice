#include <iostream>
using std::cout;
// TODO: Write hello() function
void hello() { cout << "Hello, World!\n"; }

// TODO: Overload hello() three times
// NOPE: this was NOT OVERLOADING!!!
class Human1 {
public:
  void hello() { cout << "Hello human 1\n"; };
};

class Human2 {
public:
  void hello() { cout << "Hello human 2\n"; };
};

class Human3 {
public:
  void hello() { cout << "Hello human 3\n"; };
};

// TODO: Overload hello() three times
class Human {};
class Dog {};
class Cat {};

void hello(Human human) { cout << "Hello dear human!\n"; }
void hello(Dog dog) { cout << "Hello dear dog!\n"; }
void hello(Cat cat) { cout << "Hello dear cat!\n"; }

// TODO: Call hello() from main()
int main() {
  cout << "\nThis is NOT overloading the hello() function!\n";
  Human1 human1;
  human1.hello();
  Human2 human2;
  human2.hello();
  Human3 human3;
  human3.hello();

  cout << "\nThis is ACTUAL overloading of the hello() function!\n";
  hello();
  hello(Human());
  hello(Cat());
  hello(Dog());
}