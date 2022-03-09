#include <iostream>
#include <thread>

class Vehicle {
public:
  Vehicle(int id) : _id(id) {}
  void operator()() {
    std::cout << "Vehicle #" << _id << " has been created." << std::endl;
  }

private:
  int _id;
};

int main() {
  // Create thread
  std::thread t = std::thread(Vehicle(1));
  // Using copy initialization method(option 1 from previous file)

  // do work in main()
  std::cout << "Working in the main." << std::endl;

  // Wait for thread to finish
  t.join();

  return 0;
}