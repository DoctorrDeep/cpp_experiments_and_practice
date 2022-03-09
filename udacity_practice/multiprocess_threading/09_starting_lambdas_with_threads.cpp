#include <iostream>
#include <thread>

int main() {

  int id = 0;

  // Starting first thread by reference
  auto f0 = [&id]() {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout << "a> id in 1st thread t1= " << id << std::endl;
  };
  std::thread t1(f0);

  // Starting second thread by value
  std::thread t2([id]() {
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "b> id in 2nd thread t2= " << id << std::endl;
  });

  // increment and print id in main
  ++id;
  std::cout << "c> id in main= " << id << std::endl;

  // wait for threads to finish before return
  t1.join();
  t2.join();

  return 0;
}


// OUtput
/*
c> id in main= 1
b> id in 2nd thread t2= 0
a> id in 1st thread t1= 1
*/