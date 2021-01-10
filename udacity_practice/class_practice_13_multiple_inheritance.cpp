// In the code below, the Dog class inherits from both Animal and Pet. Once you
// have examined the code below, add a Cat class that also inherits from Animal
// and Pet.

// The Cat class should have the attribute string color. Design the Cat class to
// pass the tests in the main() function.

#include <assert.h>
#include <iostream>
#include <string>

class Animal {
public:
  double age;
};

class Pet {
public:
  std::string name;
};

// Dog derives from *both* Animal and Pet
class Dog : public Animal, public Pet {
public:
  std::string breed;
};

class Cat : public Animal, public Pet {
public:
  std::string color;
};

int main() {
  Cat cat;
  cat.age = 10;
  cat.name = "Max";
  cat.color = "black";
  assert(cat.color == "black");
  assert(cat.age == 10);
  assert(cat.name == "Max");
}