// Class constructor declared inside class but not defined there
#include <cassert>
#include <iostream>

class Date {
public:
  // Constructor function declared within class definition but not defined here
  Date(int day_, int month_, int year_);

  int Day() { return day_; }
  void Day(int day) {
    bool is_good_day = day > 0 && day < 32;
    day_ = day * is_good_day + 1 * (not is_good_day);
  }
  int Month() { return month_; }
  void Month(int month) {
    bool is_good_month = month > 0 && month < 13;
    month_ = month * is_good_month + 1 * (not is_good_month);
  }
  int Year() { return year_; }
  void Year(int year) {
    bool is_good_year = year > 0;
    year_ = year * is_good_year + 2020 * (not is_good_year);
  }

private:
  int day_{1};
  int month_{1};
  int year_{2020};
};

// Date class constructor being defined outside class definition
// Note: d,m,y are local variables used only during the constructor
// The variable values are passed to the mutator functions 
// The variables are then forgotten
Date::Date(int d, int m, int y) {
  Day(d);
  Month(m);
  Year(y);
}

int main() {
  Date date(-1, 14, 2000);
  date.Day(-1);
  date.Month(14);
  date.Year(2000);
  assert(date.Day() != -1);
  assert(date.Month() != 14);
  assert(date.Year() == 2000);

  std::cout << date.Day() << "/" << date.Month() << "/" << date.Year() << "\n";
}