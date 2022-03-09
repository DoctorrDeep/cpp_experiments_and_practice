#include <iostream>

void increment_id(int &i) { ++i; };
void print_val(int &i) { std::cout << "Main thread value " << i << std::endl; };

int main() {

  int id = 0; // Define integer valriable

  // create lambdas

  // #0 : Fails and thus commented out
  // auto f0 = []() { std::cout << "ID: " << id << std::endl; };
  // Error in compilation 'id' is out of scope, thus cannot be accessed

  increment_id(id); // id = 1 after this step

  // #1 : works
  auto f1 = [id]() { std::cout << "f1 ID: " << id << std::endl; };

  increment_id(id); // id = 2 after this step

  // #2 : works
  auto f2_1 = [&id]() { std::cout << "f2_1 ID: " << id << std::endl; };
  // NO local scope change
  auto f2_2 = [&id]() { std::cout << "f2_2 ID: " << ++id << std::endl; };
  // increment applies globally WHEN f2_2() is called
  auto f2_3 = [&id]() mutable {
    std::cout << "f2_2 ID: " << ++id << std::endl;
  };
  // increment applies globally WHEN f2_2() is called
  // Same effect as f2_2. 'mutable' is not doing much since the pointer allows
  // more options.

  // #3 : Fails and thus commented out
  // auto f3_1 = [id]() { increment_id(id); std::cout << "ID: " << id <<
  //   std::endl; };
  // auto f3_2 = [id]() { std::cout << "ID: " << ++id <<
  //   std::endl; };
  // Error in compilation because id is read-only

  // #4 : works
  auto f4_1 = [id]() mutable { std::cout << "f4_1 ID: " << ++id << std::endl; };
  auto f4_2 = [id]() mutable {
    increment_id(id);
    std::cout << "f4_2 ID: " << id << std::endl;
  };
  auto f4_3 = [&id]() mutable {
    increment_id(id);
    std::cout << "f4_3 ID: " << id << std::endl;
  };

  // #5 : works
  auto f5_1 = [id](const int ie) {
    std::cout << "f5_1 ID + IE: " << id << ", " << ie << " = " << ie + id
              << std::endl;
  };
  auto f5_2 = [&id](const int ie) {
    std::cout << "f5_2 ID + IE: " << id << ", " << ie << " = " << ie + id
              << std::endl;
  };

  // execute lambdas
  // f0();
  f1();
  print_val(id);
  f2_1();
  print_val(id);
  f2_2();
  print_val(id);
  // f3_1();
  // f3_2();
  f4_1();
  print_val(id);
  f4_2();
  print_val(id);
  f4_3();
  print_val(id);
  f5_1(5);
  print_val(id);
  f5_2(5);
  print_val(id);

  return 0;
}

// Output of running the above. Kepe in mind that f0, f3_1, f3_2 not run
/*
f1 ID: 1
Main thread value 2
f2_1 ID: 2
Main thread value 2
f2_2 ID: 3
Main thread value 3
f4_1 ID: 3
Main thread value 3
f4_2 ID: 3
Main thread value 3
f4_3 ID: 4
Main thread value 4
f5_1 ID + IE: 2, 5 = 7
Main thread value 4
f5_2 ID + IE: 4, 5 = 9
Main thread value 4
*/
