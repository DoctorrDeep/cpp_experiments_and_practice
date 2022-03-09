#include <iostream>
#include <thread>

class Vehicle {
public:
  void operator()() {
    std::cout << "Vehicle object has been created" << std::endl;
  }
};

int main() {

  // Create thread
  // std::thread t(Vehicle()); // This breaks

  // Right way #1
  std::thread t1( (Vehicle()) ); // Add extra pair of parenthesis

  // Right way #2
  std::thread t2 = std::thread( Vehicle() ); // Use copy initialization

  // Right way #3
  std::thread t3{ Vehicle() }; // Use uniform initialization with braces


  // Simulate work
  std::cout << "Finished work in main thread." << std::endl;

  // wait for threads to finish
  t1.join();
  t2.join();
  t3.join();

  return 0;
}