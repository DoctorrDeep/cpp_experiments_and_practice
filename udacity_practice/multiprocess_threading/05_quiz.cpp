#include <iostream>
#include <thread>

void threadFunctionEven() {
  std::this_thread::sleep_for(std::chrono::milliseconds(10)); // simulate work
  std::cout << "Even thread" << std::endl;
}

void threadFunctionOdd() {
  std::this_thread::sleep_for(std::chrono::milliseconds(10)); // simulate work
  std::cout << "Odd thread" << std::endl;
}

int main() {

  for (int i = 0; i < 6; i++) {
    if (i % 2 == 0) {
      std::thread t(threadFunctionEven);
      t.detach();
    } else {
      std::thread t(threadFunctionOdd);
      t.detach();
    }
  }

  // std::this_thread::sleep_for(std::chrono::milliseconds(10)); // simulate work
  std::cout << "End of main thread is reached." << std::endl;
  return 0;
}

// Diff types of Output (as is code above)
/*

$> bash ./a.out
Odd threadEven threadOdd thread
Even thread


Odd thread
Even thread
End of main thread is reached.




$> bash ./a.out
Even thread
Odd thread
Even thread
Odd thread
Even thread
Odd thread
End of main thread is reached.




$> bash ./a.out
Even threadOdd thread

Even thread
Odd thread
Even thread
Odd thread
End of main thread is reached.




$> bash ./a.out
Even threadOdd thread
Even thread
Even thread

Odd thread
Odd thread
End of main thread is reached.
*/


// Output if sleep for function in main thread is commented out

/*

$> bash ./a.out
End of main thread is reached.


$> bash ./a.out
End of main thread is reached.


$> bash ./a.out
End of main thread is reached.


$> bash ./a.out
End of main thread is reached.


$> bash ./a.out
End of main thread is reached.

*/