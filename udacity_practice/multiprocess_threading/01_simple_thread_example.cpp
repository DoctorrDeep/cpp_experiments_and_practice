#include <iostream>
#include <thread>

int main() {

  // Simple Example 1
  std::cout << "Hello concurrent world from main! Thread is = "
            << std::this_thread::get_id() << std::endl;

  // Simple Example 1
  unsigned int nCores = std::thread::hardware_concurrency();
  std::cout << "This machine supports concuurrency with " << nCores
            << " cores available.\n";

  return 0;
}


// Output 1
// With -ptread flag `g++ -pthread 01_simple_thread_example.cpp && ./a.out && rm a.out`
/* 
Hello concurrent world from main! Thread is = 139795943065408
This machine supports concuurrency with 8 cores available.
*/

// Output 2
// Without -ptread flag `g++ 01_simple_thread_example.cpp && ./a.out && rm a.out`
/* 
Hello concurrent world from main! Thread is = 1
This machine supports concuurrency with 8 cores available.
*/