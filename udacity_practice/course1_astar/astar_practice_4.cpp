#include <fstream> // file streaming classes to interact with files
#include <iostream>
#include <sstream> // allows istringstream
#include <string>
#include <vector>
using std::cout;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;

enum class State { kEmpty, kObstacle };

string CellString(const State &cell) {
  switch (cell) {
  case State::kObstacle:
    return "⛰️   ";
  default:
    return "0   ";
  }
}

void BoardDetails(const vector<vector<State>> &board) {
  cout << "Size of board (num rows) = " << board.size() << "\n";
  for (const vector<State> &a_row : board)
    cout << "Size of row (num columns) = " << a_row.size() << "\n";
}

void BoardPrinter(const vector<vector<State>> &board) {
  cout << "This is what the board looks like right now!\n";
  for (const auto &a_row : board) {
    for (const auto &an_item : a_row) {
      cout << CellString(an_item) << " ";
    }
    cout << "\n";
  }
}

vector<State> ReadNumbersFromLine(const string &line) {
  istringstream my_stream(line);
  int n;
  char c;
  vector<State> row;
  while (my_stream >> n >> c && c == ',') {
    if (n == 0) {
      row.push_back(State::kEmpty);
    } else {
      row.push_back(State::kObstacle);
    }
  }
  return row;
}

vector<vector<State>> ReadBoardFile(const string &filePath,
                                    const string &fileName) {
  vector<vector<State>> board;
  string fileLocation = filePath + "/" + fileName;
  ifstream my_file(fileLocation);
  if (my_file) {
    cout << "The file stream has been created\n";
    string line;
    while (getline(my_file, line)) {
      board.push_back(ReadNumbersFromLine(line));
    }
  } else {
    cout << fileLocation << " not found.\n";
  }
  return board;
}

int main() {
  vector<vector<State>> board = ReadBoardFile(".", "1.board");
  BoardDetails(board);
  BoardPrinter(board);
}
