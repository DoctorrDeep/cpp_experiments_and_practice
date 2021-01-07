#include <assert.h>
#include <string>

class Animal {
public:
  virtual std::string Talk() const = 0;
};

// TODO: Declare a class Dog that inherits from Animal
class Dog : public Animal {
public:
  std::string Talk() const;
};

// Note: Dog::Talk() is "overriding" Anmial::Talk() since Anmial::Talk()was
// declared virtual
std::string Dog::Talk() const { return "Woof"; }

class Puppy : public Dog {
public:
  std::string Talk() const;
};

// Note: Puppy::Talk() is "hiding" Dog::Talk() since Dog::Talk() was declared
// virtual. Same effect as overriding but hiding is NOT recommended, can lead to
// bizarre errors, particularly when the two functions have slightly different
// function signatures. https://isocpp.org/wiki/faq/strange-inheritance#hiding-rule
std::string Puppy::Talk() const { return "wooooo ooooooo oh"; }

int main() {
  Dog dog;
  assert(dog.Talk() == "Woof");
  Puppy puppy;
  assert(puppy.Talk() == "wooooo ooooooo oh");
}