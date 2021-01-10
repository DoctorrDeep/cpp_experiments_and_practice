// Note the IDE might complain about some code in this file.
// Compile will not error if used with "g++ -std=c++17"
#include <assert.h>
#include <vector>

// TODO: Declare a generic, templatized average function
template <typename T> T average(T a, T b) { return (a + b) / 2; }

int main() {
  assert(average<double>(2.0, 5.0) == 3.5); // Normal way of calling a template
  assert(average(2.0, 5.0) == 3.5); // Calling template with deductions in compiler

  std::vector<int> hits{1, 2,
                        3}; // Normal way of declating + intializing a vector
  std::vector gits{2, 3,
                   4}; // Declaring + initializing a vector with deductions.
                       // Note: use "g++ -std=c++17" when compiling. Else it
                       // will complain about "missing template arguments"
  assert(hits.size() == 3);
  assert(gits.size() == 3);
}