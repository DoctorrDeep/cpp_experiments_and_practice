#include <iostream>
#include <thread>

void functionThread() {

  std::this_thread::sleep_for(std::chrono::seconds(1));
  std::cout << "This is work 1 inside function." << std::endl;

  std::this_thread::sleep_for(std::chrono::seconds(1));
  std::cout << "This is work 2 inside function." << std::endl;
}

int main() {

  std::thread t(functionThread);

  // t.join();
  // Uncomment here to make sure that function is run first

  // Main work code
  std::this_thread::sleep_for(std::chrono::seconds(1));
  std::cout << "This is work 1 inside main." << std::endl;

  std::this_thread::sleep_for(std::chrono::seconds(1));
  std::cout << "This is work 2 inside main." << std::endl;

  t.join();
  // Uncomment here so that function and main work is done concurrently
}

// Output Type 1
// Standard output when t.join() is called before main work
/*
This is work 1 inside function.
This is work 2 inside function.
This is work 1 inside main.
This is work 2 inside main.
*/

// Output Type 2
// Random outcomes because teh t.join() placement makes the function and main
// excutions concurrent 

// Random 1 of n
/*
This is work 1 inside function.
This is work 1 inside main.
This is work 2 inside function.
This is work 2 inside main.
*/

// Random 2 of n
/*
This is work 1 inside main.
This is work 1 inside function.
This is work 2 inside function.This is work 2 inside main.
*/