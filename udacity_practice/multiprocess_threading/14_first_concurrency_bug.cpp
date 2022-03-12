#include <chrono>
#include <iostream>
#include <random>
#include <thread>
#include <vector>

int main() {
  // create threads
  std::vector<std::thread> my_threads;
  for (size_t i = 0; i < 10; ++i) {
    // create new thread from a lambda
    my_threads.emplace_back([i]() {
      // wait for certain amount of time
      std::this_thread::sleep_for(std::chrono::milliseconds(10 * i));

      // perform work
      std::cout << "Hello from worker thread #" << i << std::endl;
    });
  };

  // call join on all thread objects using a range-based loop
  for (auto &t : my_threads) {
    t.join();
  }

  // do something in main
  std::cout << "Hello from Main thread" << std::endl;

  return 0;
}