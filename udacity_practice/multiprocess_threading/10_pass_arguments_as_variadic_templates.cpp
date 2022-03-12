#include <iostream>
#include <string>
#include <thread>

void printID(int id) {
  std::this_thread::sleep_for(std::chrono::milliseconds(50));
  std::cout << "ID= " << id << std::endl;
}

void printIDAndName(int id, std::string name) {
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  std::cout << "ID= " << id << ", NAME= " << name << std::endl;
}

void printNameByWaittime(std::string name, int waitTime) {
  std::this_thread::sleep_for(std::chrono::milliseconds(waitTime));
  std::cout << "Name (this thread) = " << name << std::endl;
}

void printNameAndChange(std::string &name, int waitTime) {
  std::this_thread::sleep_for(std::chrono::milliseconds(waitTime));
  name += " Edited in thread func.";
  std::cout << "Name (this thread) = " << name << std::endl;
}

int main() {

  // Define an integer variable
  int id = 0;

  //***PART 1***//

  // Staerting threads using variadic tmeplates
  std::thread t1(printID, id);
  std::thread t2(printIDAndName, ++id, "MyString");

  // This will produce a compiler error
  // std::thread t3(printIDAndName, ++id);

  // wait to join threads
  t1.join();
  t2.join();
  // t3.join();


  //***PART 2***//

  std::string name1 = "MyThread1";
  std::string name2 = "MyThread2";

  // STarting threads using value-copy and move semantics
  std::thread t4(printNameByWaittime, name1, 10);
  std::thread t5(printNameByWaittime, std::move(name2), 100);

  // wait for threads before returning
  t4.join();
  t5.join();

  // print name from main
  std::cout << "Name (from main) = " << name1 << std::endl;
  std::cout << "Name (from main) = " << name2 << std::endl;
  // Since the move by lvalue is done the string variable 'name2'
  // is lost after it was passed to the thread.


  //***PART 3***//

  std::string name3("MyThread3");

  // starting thread
  std::thread t6(printNameAndChange, std::ref(name3), 50);
  // Reference to the name is passed, hence when the name is changed
  // in the function, it changes in main too.

  // Wait for thread before closing
  t6.join();

  // print name6 from main
  name3 += "(from main)";
  std::cout << name3 << std::endl;

  return 0;
}

// Output of above
/*
ID= 0
ID= 1, NAME= MyString
Name (this thread) = MyThread1
Name (this thread) = MyThread2
Name (from main) = MyThread1
Name (from main) = 
Name (this thread) = MyThread3 Edited in thread func.
MyThread3 Edited in thread func.(from main)
*/
