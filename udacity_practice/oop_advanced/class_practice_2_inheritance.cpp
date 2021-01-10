#include <iostream>
#include <string>
using std::string;

class Vehicle {
public:
  int wheels = 0;
  string color = "blue";
  string maker = "placeholder generic";

  void Print() const {
    std::cout << "This " << color << " vehicle from " << maker << " has "
              << wheels << " wheels!\n";
  }
};

class Car : public Vehicle {
public:
  bool sunroof = false;
  string maker =
      "Peugeot"; // This value will not be set automatically. CAlling/setting it
                 // explicitly in main() will also not work! probably because
                 // the base class value is being overwritten but base class
                 // Print() is a const function. Use of a constructor could fix
                 // this issue, probably
};

class Bicycle : public Vehicle {
public:
  bool kickstand = true;
};

class Trolley : public Vehicle {
public:
  bool handle = true;
  // string maker = "AmazonBasics"; // See "Peugeot" above for car. The ONLY way
  // to make it work is by NOT mentioning the "maker"
};

int main() {
  Car car;
  car.wheels = 4;
  car.sunroof = true;
  car.Print();
  if (car.sunroof)
    std::cout << "And a sunroof!\n";

  Trolley trolley;
  trolley.wheels = 6;
  trolley.color = "Grey";
  trolley.Print();
  trolley.maker = "Amazon Soooo   Basic"; // This is when "maker" is actually
                                          // set to the non-inherited value
  trolley.Print();
};