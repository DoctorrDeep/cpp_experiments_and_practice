// Constant member variables at the cost of losing invariants
#include <cassert>
#include <iostream>

class Birthday {
public:
  Birthday(int const &day, int const &month, int const &year);
  // Birthday(int day, int month, int year); // Could also be this

  int Day() const { return day; }
  int Month() const { return month; }
  int Year() const { return year; }
  // The const after function declaration is because this is a getter function
  // Typically getters do not change the interior state of the object
  // Accessors/Getters only get data...

private:
  int const day;
  int const month;
  int const year;
};

Birthday::Birthday(int const &d, int const &m, int const &y)
    : day(d), month(m), year(y) {}

// Birthday::Birthday(int d, int m, int y) : day(d), month(m), year(y) {}
// Could also be this

int main() {
  Birthday date(-1, 14, -2000);
  assert(date.Day() == -1);
  assert(date.Month() == 14);
  assert(date.Year() == -2000);

  std::cout << date.Day() << "/" << date.Month() << "/" << date.Year() << "\n";
}