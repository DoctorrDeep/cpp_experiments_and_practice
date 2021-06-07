// How to run
// `g++ -pthread 02_simple_thread_example.cpp && ./a.out && rm a.out`
#include <iostream>
#include <thread>

void threadFunction() {

  std::this_thread::sleep_for(std::chrono::seconds(2));
  std::cout << "Finished working on function with thread with id "
            << std::this_thread::get_id() << std::endl;
}

int main() {

  // Create Thread
  std::thread t(threadFunction);

  // do something in main()
  std::this_thread::sleep_for(std::chrono::seconds(1));
  std::cout << "Finished working on main with thread id "
            << std::this_thread::get_id() << std::endl;

  t.join();

  return 0;
}

//Output 
/*
Finished working on main with thread id 140353948194624   --> finishes before function because it has lesser sleeptime
Finished working on function with thread with id 140353948190464
*/

// Output 2
// If thread sleep is 2s and main sleep is 1s i.e. MAIN finshes first
/*
Finished working on main with thread id 139800108709696
terminate called without an active exception
Aborted (core dumped)
*/

// Output 3
// If thread sleep is 1s and main sleep is 2s i.e. MAIN finshes last
/*
Finished working on function with thread with id 140664554534656
Finished working on main with thread id 140664554538816
terminate called without an active exception
Aborted (core dumped)
*/