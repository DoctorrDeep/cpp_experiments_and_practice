// Compare between public Vs protected/private inheritance
// This example demonstrates the privacy levels
// between parent and child classes

#include <iostream>
#include <string>
using std::string;
using std::cout;

class Vehicle {
public:
    int wheels = 0;
    string color = "blue";
    
    void Print() const
    {
        cout << "This " << color << " vehicle has " << wheels << " wheels!\n";
    }
};

class Car : public Vehicle {
public:
    bool sunroof = false;
    string new_color = color + " new car ";
};

class Bicycle : protected Vehicle {
public:
    bool kickstand = true;
    string new_color = color + " new bicycle";
    
};

class Scooter : private Vehicle {
public:
    bool electric = false;
    string new_color = color + " new scooter";
};

int main() 
{
    Car car;
    car.wheels = 4;
    car.Print();
    cout << car.new_color << "\n";
    Bicycle bicycle;
    // bicycle.wheels = 2; // Wont work!
    // bicycle.Print(); // Wont work!
    cout << bicycle.new_color << "\n";
    Scooter scooter;
    // scooter.wheels = 3; // Wont work!
    // scooter.Print(); // Wont work!
    cout << scooter.new_color << "\n";
};