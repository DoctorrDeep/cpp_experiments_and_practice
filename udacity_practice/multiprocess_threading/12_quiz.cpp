#include <iostream>
#include <memory>
#include <string>
#include <thread>

class Vehicle {
private:
  int _id;
  std::string _name;

public:
  Vehicle() : _id(0) {}
  void addInt(int id) { _id = id; };
  void setName(std::string name) { _name = name; };
  void printId() { std::cout << "Vehicle ID = " << _id << std::endl; }
  void printName() { std::cout << "Vehicle Name = " << _name << std::endl; }
};

int main() {

  // create thread
  std::shared_ptr<Vehicle> v(new Vehicle);
  std::thread t_id = std::thread(&Vehicle::addInt, v, 2);
  std::thread t_name = std::thread(&Vehicle::setName, v, "What is my name?");

  // wait for thread to finish
  t_id.join();
  t_name.join();

  // print vehicle id
  v->printId();
  v->printName();

  return 0;
}

// Output
/*
Vehicle ID = 2
Vehicle Name = What is my name?
*/
