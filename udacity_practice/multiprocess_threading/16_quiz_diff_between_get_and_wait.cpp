#include <cmath>
#include <future>
#include <iostream>
#include <thread>

void computeSqrt(std::promise<double> &&prms, double input) {
  std::this_thread::sleep_for(std::chrono::milliseconds(2000));
  double output = sqrt(input);
  prms.set_value(output);
}

void computeSqrtWithExceptions(std::promise<double> &&prms, double input) {
  std::this_thread::sleep_for(std::chrono::milliseconds(2000));
  try {
    if (input >= 0) {
      double output = sqrt(input);
      prms.set_value(output);
    } else {
      throw std::runtime_error("Exception from thread: Sqrt of negative number "
                               "(imaginary numbers are imaginary).");
    }
  } catch (...) {
    prms.set_exception(std::current_exception());
  }
}

int main() {
  // define input data
  double input = 42.0;

  // create promise and future
  std::promise<double> prms1_2;
  std::future<double> ftr1_2 = prms1_2.get_future();

  // start thread and pass promise as argument
  std::thread t1_2(computeSqrt, std::move(prms1_2), input);




  /* Option 1: Easy, no-timeout-checking way */
  // fetch results of function call from thread and print results

  //   double output = ftr1_2.get();
  //   std::cout << "Sqrt of " << input << " = " << output << std::endl;

  /* Option 1 ends here */




  /* Option 2: Wait for result to become available. If that or a specified
               timeout is reached, exit the code with error message. */

  // define wait period
  int timeoutMilliseconds = 3000;
  //   int timeoutMilliseconds = 1000;

  // wait for result to become available
  auto status = ftr1_2.wait_for(std::chrono::milliseconds(timeoutMilliseconds));
  if (status == std::future_status::ready) // result is ready
  {
    std::cout << "Success: Sqrt of " << input << " = " << ftr1_2.get()
              << std::endl;
  } else if (status == std::future_status::timeout ||
             status == std::future_status::deferred) {
    std::cout << "Fail: Sqrt of " << input << " could not be computed in time."
              << std::endl;
  }
  /* Option 2 ends here */




  // thread barrier
  t1_2.join();





  /* Option 3: Check if thread threw exception and handle accordingly */

  // define input data
  double bad_input = -42.0;

  // create promise and future
  std::promise<double> prms3;
  std::future<double> ftr3 = prms3.get_future();

  // start thread and pass promise as argument
  std::thread t3(computeSqrtWithExceptions, std::move(prms3), bad_input);

  // wait for result to become available
  auto status3 = ftr3.wait_for(std::chrono::milliseconds(3000));
  if (status3 == std::future_status::ready) // result is ready
  {
    try {
      double output = ftr3.get();
      std::cout << "Success: Sqrt of " << bad_input << " = " << output
                << std::endl;
    } catch (std::runtime_error e) {
      std::cout << e.what() << std::endl;
    }
  } else if (status3 == std::future_status::timeout ||
             status3 == std::future_status::deferred) {
    std::cout << "Fail: Sqrt of " << bad_input
              << " could not be computed in time." << std::endl;
  }

  // thread barrier
  t3.join();

  /* Option 3 ends here */





  return 0;
}

// Output of the above: Option 2
/*
---If timeoutMilliseconds = 3000---
Success: Sqrt of 42 = 6.48074

---If timeoutMilliseconds = 1000---
Fail: Sqrt of 42 could not be computed in time.
*/




// Output of the above: Option 3
/*
Exception from thread: Sqrt of negative number (imaginary numbers are imaginary).
*/
