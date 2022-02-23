#include <iostream>
#include <thread>

void threadFunction() {
  std::this_thread::sleep_for(std::chrono::seconds(1));
  std::cout << "Finished work in thread" << std::endl;
}

int main() {
  // Create thread
  std::thread t(threadFunction);

  // detach thread
  t.detach();

  // do something in main()
  std::this_thread::sleep_for(std::chrono::seconds(5));
  std::cout << "Finished work in main" << std::endl;

  return 0;
}

// Output Type 1
//  If main thread has 5s sleep and threadFunction has 1s sleep
/*
Finished work in thread  --> finished after 1s
Finished work in main --> appears after 5s wait from execution
*/

// Output Type 2
// If main thread has 1s sleep and threadFunction has 5s sleep
/*
Finished work in main --> finished after 1s.
*/
// Note that the functionThread did not get to publish results in output.
// Program run stops after 1s i.e. as long as main thread was active
// Then the remaining thread will eb harshly stopped (desctructor will be called
// no matter what state it is in) This is bad.
