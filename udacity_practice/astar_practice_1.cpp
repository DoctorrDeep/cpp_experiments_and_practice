#include <iostream>
#include <vector>
using std::cout;
using std::vector;

int main() {
  vector<vector<int>> board;
  board = {{0, 1, 0, 0, 0, 0},
           {0, 1, 0, 0, 0, 0},
           {0, 1, 0, 0, 0, 0},
           {0, 1, 0, 0, 0, 0},
           {0, 0, 0, 0, 1, 0}};

  cout << "Board made\n";
}