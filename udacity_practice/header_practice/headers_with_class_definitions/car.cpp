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
  cout << "The Sedan (car number " << this->Car::number << ") has "
       << this->door_count << " doors.\n"; // Note the usage of `this`!
}