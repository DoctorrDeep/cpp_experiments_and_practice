// Example solution for Shape inheritance
#include <assert.h>
#include <cmath>
#include <iostream>

// TODO: Define pi
#define PI 3.14159;

// TODO: Define the abstract class Shape
class Shape {
public:
  // TODO: Define public virtual functions Area() and Perimeter()
  // TODO: Append the declarations with = 0 to specify pure virtual functions
  virtual double Area() = 0; // Since it does nto change the shape derived class
                             // member variables, this could have been const
  virtual double Perimeter() = 0; // same here, it could have been
                                  // "virtual double Perimeter() const = 0;"
};

// TODO: Define Rectangle to inherit publicly from Shape
class Rectangle : public Shape {
public:
  // TODO: Declare public constructor
  Rectangle(double w, double h) : width(w), height(h) {}
  // TODO: Override virtual base class functions Area() and Perimeter()
  double Area() override { return width * height; };
  // "override" is not necessary as seen in Perimeter below
  double Perimeter() { return 2 * (width + height); };

private:
  // TODO: Declare private attributes width and height
  double width, height;
};

// TODO: Define Circle to inherit from Shape
class Circle : public Shape {
public:
  // TODO: Declare public constructor
  Circle(double r) : radius(r) {}
  // TODO: Override virtual base class functions Area() and Perimeter()
  double Area() { return pow(radius, 2) * PI; };
  double Perimeter() override { return radius * 2 * PI; };
  // "override" is not necessary as seen in Perimeter below
  // Also note: If the virtual function were to be declared as "const" in the
  // Shape base-class then this line would look likr this
  // "double Perimeter() const override { return radius * 2 * PI; };"

private:
  // TODO: Declare private member variable radius
  double radius;
};

// Test in main()
int main() {
  double epsilon = 0.1; // useful for floating point equality

  // Test circle
  Circle circle(12.31);
  assert(abs(circle.Perimeter() - 77.35) < epsilon);
  assert(abs(circle.Area() - 476.06) < epsilon);
  std::cout << circle.Perimeter() << " " << circle.Area() << "\n";

  // Test rectangle
  Rectangle rectangle(10, 6);
  assert(rectangle.Perimeter() == 32);
  assert(rectangle.Area() == 60);
  std::cout << rectangle.Perimeter() << " " << rectangle.Area() << "\n";
}