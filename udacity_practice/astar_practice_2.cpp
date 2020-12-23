#include <fstream> // file streaming classes to interact with files
#include <iostream>
#include <sstream> // allows istringstream
#include <string>
#include <vector>
using std::cout;
using std::istringstream;
using std::string;
using std::vector;

void BoardPrinter(const vector<vector<int>> &board) {
  cout << "The board as interpreted in vectored-int form\n";
  for (const auto &a_row : board) {
    for (const auto &an_item : a_row) {
      cout << an_item << " ";
    }
    cout << "\n";
  }
}

vector<int> ReadNumbersFromLine(const string &line) {
  istringstream my_stream(line);
  int n;
  char c;
  vector<int> row;
  while (my_stream >> n >> c) {
    cout << n << c << " streaming continues\n";
    row.push_back(n);
  }
  cout << "Streaming is dead!!\n";

  return row;
}

vector<vector<int>> ReadBoardFile(const string &filePath,
                                  const string &fileName) {
  vector<vector<int>> board;
  vector<string> basic_board;
  std::ifstream my_file;
  string fileLocation = filePath + "/" + fileName;
  my_file.open(filePath + "/" + fileName);
  if (my_file) {
    cout << "The file stream has been created\n";
    string line;
    while (getline(my_file, line)) {
      cout << line << "\n";
      board.push_back(ReadNumbersFromLine(line));
      basic_board.push_back(line);
    }
  } else {
    cout << fileLocation << " not found.\n";
  }

  cout << "\nThe board as seen in the file.\n";
  for (int i = 0; i < basic_board.size(); i++) {
    cout << basic_board[i] << "\n";
  }
  return board;
}

int main() {
  vector<vector<int>> the_board = ReadBoardFile(".", "1.board");
  BoardPrinter(the_board);
}
