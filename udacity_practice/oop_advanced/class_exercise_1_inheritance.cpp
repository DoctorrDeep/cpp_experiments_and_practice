#include <iostream>
#include <string>
using std::cout;
using std::string;

// Define base class Animal

class Animal {
public:
  string name;
  string color;
  int age;
};

// Declare derived class Snake
class Snake : public Animal {
public:
  float length = 25.2;
  void MakeSound() {
    cout << "Hisss, I am " << length << " cm long snek and I eat grep.\n";
  }
};

// Declare derived class Cat
class Cat : public Animal {
public:
  float height = 15.7;
  void MakeSound() {
    cout << "Meow, I am not cow! I am " << height << " cm tall cat.\n";
  }
};

// Test in main()
int main() {
  Snake snake;
  snake.MakeSound();
  Cat cat;
  cat.MakeSound();

  cat.name = "Mimi";
  cat.color = "grey";
  cat.age = 4;

  cout << cat.name << " the " << cat.color << " cat is "<< cat.age << " years old!\n";
}