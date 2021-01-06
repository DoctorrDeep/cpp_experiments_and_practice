
    // Declare a class Rectangle.
    // Define a class Square.
    // Add class Rectangle as a friend of the class Square.
    // Add a private attribute side to class Square.
    // Create a public constructor in class Square that initializes the side attribute.
    // Add private members width and height to class Rectangle.
    // Add a Rectangle() constructor that takes a Square as an argument.
    // Add an Area() function to class Rectangle.

// Example solution for Rectangle and Square friend classes
#include <assert.h>

// Declare class Rectangle
class Rectangle{};

// Define class Square as friend of Rectangle
class Square{
  private:
  friend class Rectangle;
}
// Add public constructor to Square, initialize side
    // Add friend class Rectangle

    // Add private attribute side

// Define class Rectangle
    // Add public function to Rectangle: Area()
    
    // Add private attributes width, height;

// Define a Rectangle constructor that takes a Square

// Define Area() to compute area of Rectangle

// Update main() to pass the tests
int main()
{
    Square square(4);
    Rectangle rectangle(square);
    assert(rectangle.Area() == 16); 
}