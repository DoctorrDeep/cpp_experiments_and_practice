#include <iostream>
#include <numeric> // needed by accumulate
#include <vector>
using std::accumulate;
using std::cout;
using std::vector;

int MySimpleTwoAdder(const int &i, const int &j) { return i + j; }

int MyIteratorReferenceAdder(const vector<int> &myvec) {
  int sum = 0;
  for (auto i = myvec.begin(); i != myvec.end(); i++) // ++i also works the same
  {
    sum += *i;
    cout << *i << " = whats in *i\n";

    // cout << " = whats in i" << i << "\n";
    // errors since there is not such thing as i (operand unsuitable)
  }
  return sum;
}

int main() {

  // Example 1
  auto a = 23;
  auto b = 42;
  //   auto a = "23";
  //   auto b = "42";
  cout << "MySimpleTwoAdder output = " << MySimpleTwoAdder(a, b) << "\n\n";

  // Example 2, 3, 4
  vector<int> v{87, 23, 65, 87, 87};

  cout << "MyIteratorReferenceAdder output = \n"
       << MyIteratorReferenceAdder(v) << "\n\n";

  cout << "Adding vector using accumulate :"
       << accumulate(v.begin(), v.end(), 0) << "\n\n";

  v.push_back(100);
  cout << "MyIteratorReferenceAdder output with 100 at the end = \n"
       << MyIteratorReferenceAdder(v) << "\n\n";
}