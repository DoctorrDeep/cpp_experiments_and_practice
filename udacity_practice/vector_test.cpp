#include <iostream>
#include <vector>
#include <algorithm> // for sort, reverse

using std::cout;
using std::vector;

bool DesCompare(int i, int j){
  return i > j; // sort in descending order
}

bool AscCompare(int i, int j){
  return i < j; // sort in ascending order
}

int main() {

  // Example 1
  cout << "Example 1\n";
  auto k_1 = 5;
  auto k_2 = {1, 2, 3};

  cout << k_1 << "\n\n";

  // Example 2
  cout << "Example 2\n";
  for (auto i : k_2)
    cout << i << " ";
  cout << "\n\n";

  // Example 3,4
  cout << "Example 3,4\n";
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
       << " In 1D.\n\n";

  // Example 5
  cout << "Example 5\n";
  vector<vector<int>> v_2{{11, 22}, {33, 44}};

  for (auto i : v_2) {
    for (auto j : i) {
      cout << j << " ";
    }
    cout << "\n";
  }
  cout << "We vectored!"
       << " In 2D.\n\n";

  // Example 6
  cout << "Example 6\n";
  vector<int> v_3{4,5,6,3,2,1,0};

  cout << "The as-given order of v_3: ";
  for (int i: v_3) cout << i << " ";
  cout << "\n";

  std::reverse (v_3.begin(), v_3.end());
  cout << "The reverse order of v_3: ";
  for (int i: v_3) cout << i << " ";
  cout << "\n";

  std::sort (v_3.begin(), v_3.end(), DesCompare);
  cout << "The Descending order of v_3: ";
  for (int i: v_3) cout << i << " ";
  cout << "\n";

  std::sort (v_3.begin(), v_3.end(), AscCompare);
  cout << "The Descending order of v_3: ";
  for (int i: v_3) cout << i << " ";
  cout << "\n\n";
}