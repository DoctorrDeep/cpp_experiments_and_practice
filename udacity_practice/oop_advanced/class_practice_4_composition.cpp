#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::string;
using std::vector;

class Wheel {
public:
  Wheel() : dia(50) {}
  float dia;
};

class Car {
public:
  Car() : wheels(4, Wheel()){}
  vector<Wheel> wheels;
};

int main(){
  Wheel wheel;
  Car car;
  for (auto i: car.wheels){
    cout << "Wheel dia = " << i.dia << "\n";
  }
}
