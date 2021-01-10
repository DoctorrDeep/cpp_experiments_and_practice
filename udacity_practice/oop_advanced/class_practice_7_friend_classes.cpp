// Example solution for Rectangle and Square friend classes
#include <assert.h>

// Define class Square as friend of Rectangle
class Square {
public:
  Square(const int &a_side);

private:
  // Add friend class Rectangle
  friend class Rectangle;
  // Add private attribute side
  const int side_;
};

// Declare class Rectangle
class Rectangle {
public:
  Rectangle(const Square &square);
  // Add public function to Rectangle: Area()
  int Area() const;

private:
  // Add private attributes width, height;
  const int width_;
  const int height_;
};

// Add public constructor to Square, initialize side
Square::Square(const int &s) : side_(s) {}

// Define class Rectangle

// Define a Rectangle constructor that takes a Square
Rectangle::Rectangle(const Square &sq) : width_(sq.side_), height_(sq.side_) {}

// Define Area() to compute area of Rectangle
int Rectangle::Area() const { return width_ * height_; }

// Update main() to pass the tests
int main() {
  Square square(4);
  Rectangle rectangle(square);
  assert(rectangle.Area() == 16);
}