#include <cassert>
#include <iostream>
#include <stdexcept>
#include <vector>

using std::cout;
using std::vector;

class Matrix {
public:
  Matrix(int row, int column)
      : row_(row), column_(column), values_(row * column, 0) {
    checkRowColumnValue(row, column, -1, -1);
  }

  void checkRowColumnValue(int const r, int const c, int const new_r,
                           int const new_c) const {
    if (r <= 0 || c <= 0) {
      throw std::invalid_argument("row,column both have to be greater than 0");
    }

    if ((new_r > r || new_c > c) && new_r >= 0 && new_c >= 0) {
      throw std::invalid_argument(
          "row,column both have to be within bounds of matrix");
    }
  };

  vector<int> getRawValues() const { return values_;};

  void setRawValues(int pos, int value) { values_[pos] = value;};

  int &operator()(int r, int c) {
    checkRowColumnValue(row_, column_, r, c);
    return values_[r * row_ + c];
  };

  int operator()(int const r, int const c) const {
    checkRowColumnValue(row_, column_, r, c);
    return values_[r * row_ + c];
  };

  Matrix operator+(Matrix const &m){
    Matrix new_m(2,2);
    for(int i=0 ; i < new_m.getRawValues().size(); i++){
      new_m.setRawValues(i, values_[i] + m.getRawValues()[i]);
    }
    return new_m;
  };

private:
  int const row_;
  int const column_;
  vector<int> values_;
};

int main() {
  Matrix matrix1(2, 2);
  matrix1(0, 1) = 1;
  matrix1(1, 0) = 2;
  matrix1(1, 1) = 3;
  cout << "Matrix 1 values : " << matrix1(0, 0) << matrix1(0, 1) << matrix1(1, 0) << matrix1(1, 1) << "\n";

  Matrix matrix2(2, 2);
  matrix2(0, 1) = matrix1(0, 1) + 1;
  matrix2(1, 0) = matrix1(1, 0) + 2;
  matrix2(1, 1) = matrix1(1, 1) + 3;
  cout << "Matrix 2 values : " << matrix2(0, 0) << matrix2(0, 1) << matrix2(1, 0) << matrix2(1, 1) << "\n";

  Matrix empty_matrix(2,2);
  Matrix matrix3 = empty_matrix + matrix1 + matrix2;
  // matrix3 = matrix3 + matrix1 + matrix2;
  cout << "Matrix 3 values : " << matrix3(0, 0) << matrix3(0, 1) << matrix3(1, 0) << matrix3(1, 1) << "\n";
}