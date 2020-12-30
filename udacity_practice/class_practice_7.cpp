// Exercise: Encapsulation
// Add a private member function that calculates the number of days in a month,
// and use it to update the class invariants. Be sure to account for [leap
// years!](https://en.wikipedia.org/wiki/Leap_year#Algorithm)
#include <cassert>
#include <iostream>

class Date {
public:
  Date(int day, int month, int year);
  int Day() const { return day_; }
  void Day(int day);
  int Month() const { return month_; }
  void Month(int month);
  int Year() const { return year_; }
  void Year(int year) { year_ = year; }

private:
  int day_{1};
  int month_{1};
  int year_{0};

  int DaysInMonth() const;
  bool IsLeapYear(int year) const;
};

bool Date::IsLeapYear(int a_year) const {
  // if (year is not divisible by 4) then (it is a common year)
  // else if (year is not divisible by 100) then (it is a leap year)
  // else if (year is not divisible by 400) then (it is a common year)
  // else (it is a leap year)
  if (a_year % 4 != 0)
    return false;
  else if (a_year % 100 != 0)
    return true;
  else if (a_year % 400 != 0)
    return false;
  else
    return true;
}

int Date::DaysInMonth() const {
  {
    switch (month_) { // "month_" works because the function is private,
                      // "Month()" would also work. See "Year()" later

    case 1: // January
      return 31;
    case 2: // February
      if (IsLeapYear(Year()))
        return 29;
      else
        return 28;
    case 3: // March
      return 31;
    case 4: // April
      return 30;
    case 5: // May
      return 31;
    case 6: // June
      return 30;
    case 7: // July
      return 31;
    case 8: // August
      return 31;
    case 9: // September
      return 30;
    case 10: // October
      return 31;
    case 11: // November
      return 30;
    case 12: // December
      return 31;
    default:
      return 31;
    }
  }
}

Date::Date(int day, int month, int year) : year_(year) {
  Month(month);
  Day(day);
}

void Date::Day(int day) {
  if (day >= 1 && day <= DaysInMonth())
    day_ = day;
}

void Date::Month(int month) {
  if (month >= 1 && month <= 12)
    month_ = month;
}

// Test
int main() {
  Date date_1(29, 2, 2020);
  assert(date_1.Day() == 29);
  assert(date_1.Month() == 2);
  assert(date_1.Year() == 2020);
  std::cout << date_1.Day() << "/" << date_1.Month() << "/" << date_1.Year()
            << "\n";

  // This date fails because the date is not allowed
  Date date_2(30, 2, 2020);
  assert(date_2.Day() != 30);
  assert(date_2.Month() == 2);
  assert(date_2.Year() == 2020);
  std::cout << date_2.Day() << "/" << date_2.Month() << "/" << date_2.Year()
            << "\n";

  // This date fails because the date is not allowed
  Date date_3(29, 2, 2021);
  assert(date_3.Day() != 29);
  assert(date_3.Month() == 2);
  assert(date_3.Year() == 2021);
  std::cout << date_3.Day() << "/" << date_3.Month() << "/" << date_3.Year()
            << "\n";

  Date date_4(28, 2, 2021);
  assert(date_4.Day() == 28);
  assert(date_4.Month() == 2);
  assert(date_4.Year() == 2021);
  std::cout << date_4.Day() << "/" << date_4.Month() << "/" << date_4.Year()
            << "\n";

  Date date_5(29, 2, 2016);
  assert(date_5.Day() == 29);
  assert(date_5.Month() == 2);
  assert(date_5.Year() == 2016);
  std::cout << date_5.Day() << "/" << date_5.Month() << "/" << date_5.Year()
            << "\n";
}