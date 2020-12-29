// Class has accessor and mutator but no constructor
// the compiler will create a default contructor which
// will accept no arguments when instantiating an object of the class
#include <cassert>
#include <iostream>

class Date {
public:

 // Accessor (Getter)
  int Day() { return day_; }
  // Mutator (Setter) containing an invariant function
  void Day(int day) {
    bool is_good_day = day > 0 && day < 32;
    day_ = day * is_good_day + 1 * (not is_good_day);
  }

  // Accessor (Getter)
  int Month() { return month_; }
  // Mutator (Setter) containing an invariant function
  void Month(int month) {
    bool is_good_month = month > 0 && month < 13;
    month_ = month * is_good_month + 1 * (not is_good_month);
  }

  // Accessor (Getter)
  int Year() { return year_; }
  // Mutator (Setter) containing an invariant function
  void Year(int year) {
    bool is_good_year = year > 0;
    year_ = year * is_good_year + 2020 * (not is_good_year);
  }

private:
  int day_{1};
  int month_{1};
  int year_{2020};
};

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