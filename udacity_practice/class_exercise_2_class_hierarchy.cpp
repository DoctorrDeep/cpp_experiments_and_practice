#include <cassert>

// TODO: Declare Vehicle as the base class
class Vehicle {
public:
  int wheels;
};

// TODO: Derive Car from Vehicle
class Car : public Vehicle {
public:
  Car() { setWheelCount(); }
  void setWheelCount() { wheels = 4; };
  bool trunk;
  int seats;
};

// TODO: Derive Sedan from Car
class Sedan : public Car {
public:
  Sedan() {
    setTrunk();
    setSeat();
  }
  void setTrunk() { trunk = true; };
  void setSeat() { seats = 4; };
};

// TODO: Update main to pass the tests
int main() {
  Sedan sedan;
  assert(sedan.trunk == true);
  assert(sedan.seats == 4);
  assert(sedan.wheels == 4);
}