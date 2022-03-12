#include <iostream>
#include <thread>
#include <vector>

void printHello() {
  // perform work
  std::cout << "Hello from worker thread #" << std::this_thread::get_id()
            << std::endl;
}

int main() {

  // create threads
  std::vector<std::thread> my_threads;
  for (size_t i = 0; i < 5; ++i) {

    // Copying theread objects causes a compile error
    //  Why? because pushing a thread object into a vector causes an attempt to
    //  copy the thread object. Threads do not have a copy constructor and thus
    //  cannot be duplicated, rightfully so, since that would cause further
    //  unintended forking.
    /*
    std::thread t(printHello);
    my_threads.push_back(t);
     */

    // Solution to the above problem is to use move semantics
    //  refresh topics of move semantics, rvalue lvalue, rvalue references.
    //  emplace_back internally uses move semantics to move the threads to a
    //  vector instead of making a copy.
    my_threads.emplace_back(std::thread(printHello));
  }

  // do something in main()
  std::cout << "Hello from the main thread #" << std::this_thread::get_id()
            << std::endl;

  // call join on all thread objects using a range-based loop
  for (auto &t : my_threads) {
    t.join();
  }

  return 0;
}

// Output
/*
> ./a.out
Hello from worker thread #Hello from worker thread
#139658618537536139658610144832

Hello from worker thread #139658601752128
Hello from worker thread #139658593359424
Hello from the main thread #139658618552768
Hello from worker thread #139658512037440


> ./a.out
Hello from worker thread #140451900499520
Hello from worker thread #140451892106816
Hello from worker thread #140451883714112
Hello from worker thread #140451805918784
Hello from the main thread #140451900514752
Hello from worker thread #140451797526080


> ./a.out
Hello from worker thread #Hello from worker thread
#140367575152192140367566759488

Hello from worker thread #140367558366784
Hello from worker thread #140367549974080
Hello from the main thread #140367575167424
Hello from worker thread #140367541581376
*/

// Its different everytime. What do we learn from this?
//  - thread order is non-deterministic
//  - new thread execution can happen while another thread is still running
// This interleaving of execution is the cause of lots of concurrency bugs.
