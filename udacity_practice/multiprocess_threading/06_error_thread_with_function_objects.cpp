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
  std::thread t(Vehicle());

  // Simulate work
  std::cout << "Finished work in main thread." << std::endl;

  // wait for thread to finish
  t.join();

  return 0;
}


// The above fails with the following because of C++s "most vexing parse"
/*
  06_thread_with_function_objects.cpp: In function ‘int main()’:
  06_thread_with_function_objects.cpp:13:16: warning: parentheses were disambiguated as a function declaration [-Wvexing-parse]
  13 |   std::thread t(Vehicle());
      |                ^~~~~~~~~~~
  06_thread_with_function_objects.cpp:13:16: note: replace parentheses with braces to declare a variable
  13 |   std::thread t(Vehicle());
      |                ^~~~~~~~~~~
      |                -
      |                {         -
      |                          }
  06_thread_with_function_objects.cpp:17:5: error: request for member ‘join’ in ‘t’, which is of non-class type ‘std::thread(Vehicle (*)())’
  17 |   t.join();
      |     ^~~~
  */