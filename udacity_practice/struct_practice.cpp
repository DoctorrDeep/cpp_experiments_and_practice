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
  int Day() { return day; }
  void Day(int day) { this->day = day; }
  std::string Month() { return month; }
  void Month(std::string month) { this->month = month; }
  int Year() { return year; }
  void Year(int year) { this->year = year; }

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
  std::cout << "The simple struct date was checked to be " << date_one.day << "/"
            << date_one.month << "/" << date_one.year << "\n";

  // Example 2
  StrictDate date_two;
  date_two.Year(1981);
  assert(date_two.Day() == 1);
  assert(date_two.Month() == "January");
  assert(date_two.Year() == 1981);
  std::cout << "The accessor mutator date was checked to be " << date_two.Day() << "/"
            << date_two.Month() << "/" << date_two.Year() << "\n";
}