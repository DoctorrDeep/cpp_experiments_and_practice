// Run with
// g++ car_main_II.cpp car.cpp && ./a.out && rm a.out
#include "car.h"
#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::string;
using std::vector;

int main() {
  // Create an empty vector of pointers to Cars
  // and a null pointer to a car.
  vector<Car *> car_vect;
  Car *cp = nullptr;

  // The vector of colors for the cars:
  vector<string> colors{"red", "blue", "green"};

  // Create 100 cars with different colors and
  // push pointers to each of those cars into the vector.
  for (int i = 20; i <= 40; i++) {
    cp = new Car(colors[i % 3], i, (i + 1) * 5);
    car_vect.push_back(cp);
  }

  // Move each car forward by 2.
  for (Car *cp : car_vect) {
    cp->IncrementDistance();
    (*cp).IncrementDistance(); // This statement is the same as the (->) arrow
                               // statement above
  }

  // Print data about each car.
  for (Car *cp : car_vect) {
    cp->PrintCarData();
    cout << "public property car, car number " << cp->number << "\n\n";

    // will not work since color is a private property
    // cout << "private property car color " << cp->color << "\n";
  }
}