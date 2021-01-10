class Vehicle {};

class Car : public Vehicle {
public:
  bool sunroof = false;
};

class Bicycle : public Vehicle {
public:
  bool kickstand = true;
};

int main() {
  Vehicle a_vehicle;
  Car a_car;
  Bicycle a_bicycle;
}