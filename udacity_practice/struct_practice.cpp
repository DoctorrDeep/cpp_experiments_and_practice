#include <cassert>
#include <iostream>
#include <string>

struct Date {
  int day{1};
  std::string month{"January"};
  int year = 2000;
};

struct StrictDate {
public:
  int Day() {
    return day; // get call that returns the current value of 'day' which is
                // private
  }
  void Day(int day) {
    this->day = day; // set call that sets the value of 'day' which is private
                     // and return nothing
  }
  std::string Month() { return month; }
  void Month(std::string month) { this->month = month; }
  int Year() { return year; }
  void Year(int year) {
    // In this case the invariant (setter) is going to check value
    bool is_good_year = year / 1000 > 1; // check if year is after 2000 AD

    // if (is_good_year) {
    //   this->year = year;
    // } else {
    //   this->year = 2020;
    // }

    // the following  line is doing the same as the if condition above
    this->year = year * is_good_year + 2020 * (not is_good_year);
  }

private:
  int day{1};
  std::string month{"January"};
  int year{2000};
};

int main() {

  // Example 1
  Date date_one;
  date_one.day = 10;
  assert(date_one.day == 10);
  assert(date_one.month == "January");
  assert(date_one.year == 2000);
  std::cout << "The simple struct date was checked to be " << date_one.day
            << "/" << date_one.month << "/" << date_one.year << "\n";

  // Example 2
  StrictDate date_two;
  date_two.Year(1981); // makes a set call on STruct date_two
  // All assert are making get calls on the struct "date_two.___()"
  assert(date_two.Day() == 1);
  assert(date_two.Month() == "January");
  assert(date_two.Year() == 1981);
  std::cout << "The accessor mutator date was checked to be " << date_two.Day()
            << "/" << date_two.Month() << "/" << date_two.Year() << "\n";
}