// Run with
// g++ car_main_I.cpp car.cpp && ./a.out && rm a.out
#include "car.h"

int main() {
  // Create class instances for each car.
  Car car_1 = Car("green", 1, 100);
  Car car_2{"red", 2, 200};
  Car car_3 = Car("blue", 3, 300);
  Sedan sed_1 = Sedan("mahogany", 10, 2, 12);
  Sedan sed_2{"jetblack", 11, 1, 5};

  // Increment car_1's position by 1.
  car_1.IncrementDistance();
  sed_1.IncrementDistance();
  sed_2.IncrementDistance();

  // Print out the position and color of each car.
  car_1.PrintCarData();
  car_2.PrintCarData();
  car_3.PrintCarData();
  sed_1.PrintCarData();
  sed_1.PrintDoorData();
  sed_2.PrintCarData();
  sed_2.PrintDoorData();
}