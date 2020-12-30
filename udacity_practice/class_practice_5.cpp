// Scope resolution + Initializer Lists
// Class has accessor and mutator and constructor
// Mutator and constructor will be defined outide class definition
#include <cassert>
#include <iostream>

class Date {
public:
  Date(int day, int month, int year);

  // Accessor (Getter)
  int Day() { return day; }
  // Mutator (Setter) containing no invariant function
  void Day(int day);

  // Accessor (Getter)
  int Month() { return month; }
  // Mutator (Setter) containing no invariant function
  void Month(int month);

  // Accessor (Getter)
  int Year() { return year; }
  // Mutator (Setter) containing no invariant function
  void Year(int year); //{ Date::year = year; }

private:
  int day{1};
  int month{1};
  int year{2020};
};

// Date class constructor being defined outside class definition
// below "year(y)"
// "year" private member variable from class "int year{2020};" (line 29)
// "(y)" passing the local variable sent to the constructor from main() "Date date(-1, 14, -2000);" (line 60)
// Note: the "year(y)" and the commented out "// Year(y);" inside the constructor 
//       will bypass the mutator Year function!
Date::Date(int d, int m, int y) : year(y) {
  Day(d);
  Month(m);
  // Year(y);
}

void Date::Day(int day) {
  bool is_good_day = day > 0 && day < 32;
  Date::day = day * is_good_day + 1 * (not is_good_day);
}

void Date::Month(int month) {
  bool is_good_month = month > 0 && month < 13;
  Date::month = month * is_good_month + 1 * (not is_good_month);
}

void Date::Year(int year) {
  bool is_good_year = year > 10;
  Date::year = year * is_good_year + 2020 * (not is_good_year);
}

int main() {
  Date date(-1, 14, -2000);
  assert(date.Day() != -1);
  assert(date.Month() != 14);
  assert(date.Year() == -2000);

  std::cout << date.Day() << "/" << date.Month() << "/" << date.Year() << "\n";
}