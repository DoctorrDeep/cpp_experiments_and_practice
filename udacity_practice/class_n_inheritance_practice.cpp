#include <iostream>
#include <string>
using std::cout;
using std::string;

/* Class Car */
class Car {
public:
  void PrintCarData() {
    cout << "The distance that the " << color << " car " << number
         << " has traveled is: " << distance << "\n";
  }

  void IncrementDistance() { distance++; }

  // Adding a constructor here:
  Car(string c, int n, int d) : color(c), number(n), distance(d) {
    // Setting the class attributes with
    // The values passed into the constructor.
    //         color = c;
    //         number = n;
    //         distance = d;
  }

  string color;
  int distance;
  int number;
};

/* Class Sedan inherited from class Car */
class Sedan : public Car {
public:
  void PrintDoorData() {
    cout << "The Sedan car number " << Car::number << " has " << door_count
         << " doors.\n";
  }
  Sedan(string c, int n, int d, int door) : Car(c, n, d) { door_count = door; };

  int door_count;
};

/* Main */
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