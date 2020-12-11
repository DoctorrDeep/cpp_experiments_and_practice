#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>
using std::cout;
using std::string;

class Car {
public:
  void PrintCarData();
  void IncrementDistance();
  // Adding a constructor here:
  Car(string c, int n, int d) : color(c), number(n), distance(d) {}

  int number; // Keeping it public so that Sedan can use in car.cpp

private:
  string color;
  int distance;
};

class Sedan : public Car {
public:
  void PrintDoorData();
  Sedan(string c, int n, int d, int door) : Car(c, n, d) { door_count = door; };

private:
  int door_count;
};

#endif