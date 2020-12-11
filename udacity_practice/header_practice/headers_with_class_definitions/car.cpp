#include "car.h"
#include <iostream>
// #include <string>
// using std::cout;
// using std::string;

void Car::PrintCarData() {
  cout << "The distance that the " << color << " car " << number
       << " has traveled is: " << distance << "\n";
}

void Car::IncrementDistance() { distance++; }

void Sedan::PrintDoorData() {
  cout << "The Sedan (car number " << Car::number << ") has " << door_count
       << " doors.\n";
}