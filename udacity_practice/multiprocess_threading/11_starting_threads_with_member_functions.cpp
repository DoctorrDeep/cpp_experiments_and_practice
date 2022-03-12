#include <iostream>
#include <thread>
#include <memory>

class Vehicle {
public:
  Vehicle() : _id(0) {}
  void addId(int id) { _id = id; }
  void printID() { std::cout << "Vehicle ID= " << _id << std::endl; }

private:
  int _id;
};

int main() {


  //***PART 1***//

  // create thread
  Vehicle v1, v2;

  // call member function on class object v1, v2
  // std::thread t0 = std::thread(Vehicle::addId, v1, 2); // Does not work
  std::thread t1 = std::thread(&Vehicle::addId, v1, 2);
  std::thread t2 = std::thread(&Vehicle::addId, &v2, 2);

  // wait for threads to finish
  // t0.join();
  t1.join();
  t2.join();

  // print Vehicle ID
  // v0.printID();
  v1.printID();
  v2.printID();


  //***PART 2***//

  // create thread
  std::shared_ptr<Vehicle> v(new Vehicle);
  std::thread t = std::thread(&Vehicle::addId, v, 2);

  //wait for thread to finish
  t.join();

  //print Vehicle id;
  v->printID();

  return 0;
}

//Output
/*
Vehicle ID= 0 --> becausse v1 was passed to the thread by value, 
                  what happened in the thread does not affect v1 in the main thread.
Vehicle ID= 2 --> because v2 was passed by reference, what happened in the thread affects v2 in main.
Vehicle ID= 1
*/
