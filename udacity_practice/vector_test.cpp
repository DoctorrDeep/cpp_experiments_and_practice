#include <iostream>
#include <vector>

using std::cout;
using std::vector;

int main() {
  auto k_1 = 5;
  auto k_2 = {1, 2, 3};

  cout << k_1 << "\n";

  for (auto i : k_2)
    cout << i << " ";
  cout << "\n";

  vector<int> v_1{1, 2, 3};
  vector<int> v_11;
  v_11 = {6, 8};

  for (int i : v_1)
    cout << i << " ";
  cout << "\n";
  for (int i : v_11) {
    cout << i << " ";
  }
  cout << "\n";

  cout << "We vectored!"
       << " In 1D.\n";

  vector<vector<int>> v_2{{11, 22}, {33, 44}};

  for (auto i : v_2) {
    for (auto j : i) {
      cout << j << " ";
    }
    cout << "\n";
  }
  cout << "\n";

  cout << "We vectored!"
       << " In 2D.\n";
}