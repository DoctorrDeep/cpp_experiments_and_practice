#include <future>
#include <iostream>
#include <thread>

void printMessage(std::string message) {
  std::this_thread::sleep_for(std::chrono::milliseconds(10));
  std::cout << "Thread 1_1 (no data sent back) (pure function):\n\t" << message
            << std::endl;
}

void modifyMessage(std::promise<std::string> &&prms, std::string message) {
  std::this_thread::sleep_for(std::chrono::milliseconds(4000));
  std::string newMessage = message + " (This is a modification)";
//   std::cout << "Thread 2_1 (modified data sent back) (pure function) (cout in "
//                "function):\n\t"
//             << newMessage << std::endl;
  prms.set_value(newMessage);
}

int main() {

  // define message
  std::string message = "My Message! My Truth!";

  /* Part 1: Normal Thread usage, no data comes back from thread*/
  // start thread using variadic templates
  std::thread t1_1(printMessage, message);

  // start thread using a lambda
  std::thread t1_2([message]() {
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    std::cout << "Thread 1_2 (no data sent back) (lambda function):\n\t" << message
              << std::endl;
  });

  // thread barrier
  t1_1.join();
  t1_2.join();

  /* Part 2: Thread usage with modified data comeing back from thread*/
  // create promise and future
  std::promise<std::string> prms;
  std::future<std::string> ftr = prms.get_future();

  // start thread and pass promise as argument
  std::thread t2_1(modifyMessage, std::move(prms), message);

  // print original message to console
  std::cout << "Thread 2_1 (original message) (pure function) (cout in main):\n\t"
            << message << std::endl;

  // retrieve modified message from future and print to console
  std::string messageFromThread = ftr.get();
  std::cout
      << "Thread 2_1 (modified data sent back) (pure function) (cout in main):\n\t"
      << messageFromThread << std::endl;

  // thread barrier
  t2_1.join();

  return 0;
}

// Output
/*
Thread 1_1 (no data sent back) (pure function):
        My Message! My Truth!
Thread 1_2 (no data sent back) (lambda function):
        My Message! My Truth!

Thread 2_1 (original message) (pure function) (cout in main):
        My Message! My Truth!
--- 4000 noticable millisedconds pass before the last line is printed. ---
Thread 2_1 (modified data sent back) (pure function) (cout in main):
        My Message! My Truth! (This is a modification)
*/
