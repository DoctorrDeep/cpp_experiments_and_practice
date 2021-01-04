#include <iostream>
#include <string>
using std::string;

class Vehicle {
public:
  int wheels = 0;
  string color = "blue";
  string maker = "placeholder generic";

  void Print() const {
    std::cout << "This " << color << " vehicle from "<< maker << " has " << wheels << " wheels!\n";
  }
};

class Car : public Vehicle {
public:
  bool sunroof = false;
  string maker = "Peugeot";
};

class Bicycle : public Vehicle {
public:
  bool kickstand = true;
  string maker = "Hero";
};

class Trolley : public Vehicle {
public:
  bool handle = true;
  string maker = "AmazonBasics";
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
};