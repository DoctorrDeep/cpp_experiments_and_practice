#include <fstream> // file streaming classes to interact with files
#include <iostream>
#include <sstream> // allows istringstream
#include <string>
#include <vector>
using std::cout;
using std::istringstream;
using std::string;
using std::vector;

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
  std::ifstream my_file;
  string fileLocation = filePath + "/" + fileName;
  my_file.open(filePath + "/" + fileName);
  if (my_file) {
    cout << "The file stream has been created\n";
    string line;
    while (getline(my_file, line)) {
      cout << line << "\n";
      board.push_back(ReadNumbersFromLine(line));
    }
  } else {
    cout << fileLocation << " not found.\n";
  }
  return board;
}

int main() { vector<vector<int>> the_board = ReadBoardFile(".", "1.board"); }
