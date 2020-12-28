#include <iostream>
#include <vector>
using std::cout;
using std::vector;

void BoardDetails(const vector<vector<int>> &board) {
  // For looping over items in board
  cout << "Size of board (num rows) = " << board.size() << "\n";
  for (const vector<int> &a_row : board)
    cout << "Size of row (num columns) = " << a_row.size() << "\n";

  // For looping over indexes of items in board
  // cout << "Size of board (num rows) = " << board.size() << "\n";
  // for (int i = 0; i < board.size(); i++)
  //   cout << "Size of row (num columns) = " << board[i].size() << "\n";
}

void BoardPrinter(const vector<vector<int>> &board) {
  for (const auto &a_row : board) {
    for (const auto &an_item : a_row) {
      cout << an_item << " ";
    }
    cout << "\n";
  }
}

int main() {
  vector<vector<int>> board;
  board = {{0, 1, 0, 0, 0, 0},
           {0, 1, 0, 0, 0, 0},
           {0, 1, 0, 0, 0, 0},
           {0, 1, 0, 0, 0, 0},
           {0, 0, 0, 0, 1, 0}};

  cout << "Board made\n";
  // cout << board[4][2] << "\n"; // works fine for 5rows X 6 columns
  // cout << board[1][5] << "\n"; // works fine for 5rows X 6 columns
  // cout << board[1][7] << "\n"; // works fine for 5rows X 6 columns
  // cout << board[6][2] << "\n"; // causes seg fault for 5rows X 6 columns

  BoardDetails(board);
  BoardPrinter(board);
}