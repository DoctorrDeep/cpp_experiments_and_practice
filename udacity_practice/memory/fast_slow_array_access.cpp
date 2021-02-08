#include <chrono>
#include <iostream>

int main() {
  const int size = 4;
  // const int size = 4000;
  static int x[size][size];

  // Code to save timestamp before array fillup
  auto t1 = std::chrono::high_resolution_clock::now();

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {

      // Note: Comment out the std::cout lines inside the loop if
      //       array size is big.

      // Good way to access arrays
      x[i][j] = i + j;
      std::cout << &x[i][j] << ": i = " << i << ": j = " << j << "\n";

      // Bad way to access arrays
      // x[j][i] = i + j;
      // std::cout << &x[j][i] << ": j = " << j << ": i = " << i << "\n";
    }
  }

  // Code to save timestamp after array fillup
  auto t2 = std::chrono::high_resolution_clock::now();

  // Code to compute and print time needed for array fillup
  auto duration =
      std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
  std::cout << "Time taken to fill array = " << duration << " microseconds.\n";

  // 10^6 microseconds = 1 second

  return 0;
}