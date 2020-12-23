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

/*
Note all of these can be used interchangeably:
- "color" "this->color" "this->Car::color"
- "distance" "this->distance" "this->Car::distance"
- "number" "this->number" "this->Car::number"

Similarly the IncrementDistance could have teh following too:
- { distance++; }
- { this->distance++; }
- { this->Car::distance++; }
*/