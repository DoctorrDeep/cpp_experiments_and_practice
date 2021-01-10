// In this exercise, you will start with a LineSegment class and create a Circle
// class. Note that you will compose Circle from LineSegment, instead of
// inheriting Circle from LineSegment. Specifically, the length attribute from
// LineSegment will become the circle's radius.

#include <assert.h>
#include <cmath>
#include <iostream>

// Define pi
float const pi = 3.14;

// Define LineSegment Class
class LineSegment {
public:
  LineSegment(float lin_len) : length(lin_len) {}
  float getLength() { return length; };

protected:
  // Define protected attribute length
  float length;
};

// Define Circle subclass
class Circle {
public:
  Circle(LineSegment a_line) {
    setRadius(a_line.getLength());
    calcArea();
  }

  // Define public setRadius() and getArea()
  void setRadius(float r) { radius = r; };
  void calcArea() { area = pi * pow(radius, 2); };
  float getArea() { return area; };

private:
  float radius;
  float area;
};

// Test in main()
int main() {
  LineSegment radius{3};
  Circle circle(radius);
  assert(int(circle.getArea()) == 28);
}