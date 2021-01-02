// Scope resolution!!!
// Class has accessor and mutator but no constructor
// Mutator will be defined outide class definition
#include <cassert>
#include <iostream>

class Date {
public:
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
  void Year(int year);

private:
  int day{1};
  int month{1};
  int year{2020};
};

void Date::Day(int day) {
  bool is_good_day = day > 0 && day < 32;
  Date::day = day * is_good_day + 1 * (not is_good_day);
}

void Date::Month(int month) {
  bool is_good_month = month > 0 && month < 13;
  Date::month = month * is_good_month + 1 * (not is_good_month);
}

void Date::Year(int year) {
  bool is_good_year = year > 0;
  Date::year = year * is_good_year + 2020 * (not is_good_year);
}

int main() {
  Date date;
  date.Day(-1);
  date.Month(14);
  date.Year(2000);
  assert(date.Day() != -1);
  assert(date.Month() != 14);
  assert(date.Year() == 2000);

  std::cout << date.Day() << "/" << date.Month() << "/" << date.Year() << "\n";
}