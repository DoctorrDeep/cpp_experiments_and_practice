#include <fstream> // file streaming classes to interact with files
#include <iostream>
#include <sstream> // allows istringstream
#include <string>
#include <vector>
using std::cout;
using std::istringstream;
using std::string;
using std::vector;

void BoardDetails(const vector<vector<int>> &board) {
  cout << "Size of board (num rows) = " << board.size() << "\n";
  for (const vector<int> &a_row : board)
    cout << "Size of row (num columns) = " << a_row.size() << "\n";
}

void BoardPrinter(const vector<vector<int>> &board) {
  cout << "This is what the board looks like right now!\n";
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
  while (my_stream >> n >> c && c == ',') {
    row.push_back(n);
  }
  //   cout << "Streaming the line is done!!\n";
  return row;
}

vector<vector<int>> ReadBoardFile(const string &filePath,
                                  const string &fileName) {
  vector<vector<int>> board;
  std::ifstream my_file;
  string fileLocation = filePath + "/" + fileName;
  my_file.open(filePath + "/" + fileName);
  if (my_file) {
    cout << "The file stream has been created\n";
    string line;
    while (getline(my_file, line)) {
      //   cout << line << " This line has been read and will be
      //   processed.\n";
      board.push_back(ReadNumbersFromLine(line));
    }
  } else {
    cout << fileLocation << " not found.\n";
  }
  return board;
}

int main() {
  vector<vector<int>> board = ReadBoardFile(".", "1.board");
  BoardDetails(board);
  BoardPrinter(board);
}
