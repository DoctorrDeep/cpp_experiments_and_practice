// In this exercise, you will start with a LineSegment class and create a Circle
// class. Note that you will compose Circle from LineSegment, instead of
// inheriting Circle from LineSegment. Specifically, the length attribute from
// LineSegment will become the circle's radius.

#include <assert.h>
#include <cmath>
#include <iostream>

// Define pi
#define PI 3.14;

// Define LineSegment Class/Struct
struct LineSegment {
public:
  // Define public attribute length
  float length;
};

// Define Circle subclass
class Circle {
  // Define public Area()
public:
  Circle(LineSegment &rad) : radius_(rad){};
  float Area();

private:
  LineSegment &radius_;
};

float Circle::Area() { return pow(radius_.length, 2) * PI; }

// Test in main()
int main() {
  LineSegment radius{3};
  Circle circle(radius);
  assert(int(circle.Area()) == 28);
}