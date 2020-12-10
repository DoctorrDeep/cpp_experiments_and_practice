#include <algorithm> // for sort
#include <fstream>   // file streaming classes to interact with files
#include <iostream>
#include <sstream> // allows istringstream
#include <string>
#include <vector>
using std::cout;
using std::ifstream;
using std::istringstream;
using std::sort;
using std::string;
using std::vector;

enum class State { kEmpty, kObstacle, kClosed, kPath };

string CellString(const State &cell) {
  switch (cell) {
  case State::kObstacle:
    return "⛰️   ";
  case State::kClosed:
    return "X   ";
  case State::kPath:
    return "🚗   ";
  default:
    return "0   ";
  }
}

// Print details of the board like num of rows and columns
void BoardDetails(const vector<vector<State>> &board) {
  cout << "Size of board (num rows) = " << board.size() << "\n";
  for (const vector<State> &a_row : board)
    cout << "Size of row (num columns) = " << a_row.size() << "\n";
}

// Print the board
void BoardPrinter(const vector<vector<State>> &board) {
  for (const auto &a_row : board) {
    for (const auto &an_item : a_row) {
      cout << CellString(an_item) << " ";
    }
    cout << "\n";
  }
}

// heuristic func: calculate the Manhattan Taxicab
// distance between 2 points
int Heuristic(int x1, int y1, int x2, int y2) {
  return abs(x1 - x2) + abs(y1 - y2);
}

// Compare between f (g+h) values of open nodes
// 3rd value in vector (ind 2) is the g value
// 4th value in vector (ind 3) is the h value
bool Compare(const vector<int> &node1, const vector<int> &node2) {
  return (node1[2] + node1[3]) > (node2[2] + node2[3]);
}

// Sort the two-dimensional vector of ints in descending order.
void CellSort(vector<vector<int>> *v) { sort(v->begin(), v->end(), Compare); }

// Check if a cell(by indices) is on the grid
// and has value KEmpty i.e. open to be travelled on
bool CheckValidCell(const int &x, const int &y,
                    const vector<vector<State>> &grid) {
  const int count_rows = grid.size();
  const int count_columns = grid[0].size();
  if (0 <= x && x < count_rows && 0 <= y && y < count_columns)
    return grid[x][y] == State::kEmpty;
  return false;
}

// Add a node (x row,y column, g value, h value)
// to the open list and mark it as open.
void AddToOpen(const int &x, const int &y, const int &g, const int &h,
               vector<vector<int>> &open_nodes, vector<vector<State>> &grid) {
  open_nodes.push_back(vector<int>{x, y, g, h});
  grid[x][y] = State::kClosed;
}

// The A* search algorithm
vector<vector<State>> Search(vector<vector<State>> grid, const int init[2],
                             const int goal[2]) {
  // Create the vector of open nodes.
  vector<vector<int>> open{};

  // Initialize the starting node.
  int x = init[0];
  int y = init[1];
  int g = 0;
  int h = Heuristic(x, y, goal[0], goal[1]);

  // Add starting node to empty open nodes vector
  AddToOpen(x, y, g, h, open, grid);

  while (open.size() > 0) {
    // Get the next node
    CellSort(&open);
    auto current = open.back();
    open.pop_back();
    x = current[0];
    y = current[1];
    grid[x][y] = State::kPath;

    // Check if we're done.
    if (x == goal[0] && y == goal[1]) {
      return grid;
    }
    // else {
    // ExpandNeighbors
    // }
  }

  // TODO: remove placeholder before final version
  cout << "No path found!"
       << "\n";
  return std::vector<vector<State>>{};
}

// Convert string form of each line to enum State type
// and return the grid (vector of vectors of State enums)
vector<State> ReadStatesFromLine(const string &line) {
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

// Read the text based board from a file and
// convert it to a state based form of the board
vector<vector<State>> ReadBoardFile(const string &filePath,
                                    const string &fileName) {
  vector<vector<State>> board;
  string fileLocation = filePath + "/" + fileName;
  ifstream my_file(fileLocation);
  if (my_file) {
    cout << "The file stream has been created\n";
    string line;
    while (getline(my_file, line)) {
      board.push_back(ReadStatesFromLine(line));
    }
  } else {
    cout << fileLocation << " not found.\n";
  }
  return board;
}

int main() {
  // Read the board from file and convert it into someting processable
  auto board = ReadBoardFile(".", "1.board");

  // Declare the starting and goal locations on the board (y, x)
  int init[2]{0, 0};
  int goal[2]{4, 5};

  // Compute the path using A* from start to goal
  auto solution = Search(board, init, goal);

  // Graphically print the problem and its solution in the terminal
  BoardDetails(board);
  cout << "This is what the board looks like right now!\n";
  BoardPrinter(board);
  cout << "\nThe solution to the maze from A* search is as follows\n";
  BoardPrinter(solution);
}
