#include <cassert>
#include <cmath>
#include <iostream>
#include <stdexcept>

// TODO: Define class Sphere
class Sphere {
public:
  // Constructor
  Sphere(float r) : radius_(r), volume_(c_ * pi_ * pow(r, 3)) {
    counter_++;
    if (r <= 0)
      throw std::invalid_argument(
          "Invalid radius. Use positive non-zero float.");
  }

  // Accessors
  float Radius() const { return radius_; }
  float Volume() const { return volume_; };
  int Counter() const { return counter_; };

  // Mutators

private:
  // Private members
  static float constexpr pi_{
      3.14}; // Option 1: Unchanging value with static and constexpr.
             // Available to all objects of the class.
             // Constexp is because this value gets set at compile time.
             // All others options (2,3) will be evaluated at run time!
  static float const c_; // Option 2: Unchanging value with static and const.
                         // The member is defined outside the class.
                         // Available to all objects of the class.
  float const radius_;
  float const volume_;

  static int counter_; // Option 3: a non constant static member that changes
                       // simultaneously for all objects of the class. Hence, no
                       // "const"
};

float const Sphere::c_{
    4.0f / 3.0f}; // From Option 2. Notice that "static" is not mentioned.
                  // Because the static-ness of it has been
                  // declared inside the class already!

int Sphere::counter_{0}; // From Option 3. Notice again that "static" should not
                         // be mentioned here.

void PrintState(std::string const &s_name, float const &val) {
  std::cout << "value of " << s_name << " is " << val << "\n";
}

// Test
int main(void) {
  Sphere sphere(5);
  assert(sphere.Radius() == 5);
  assert(abs(sphere.Volume() - 523.6) < 1);

  Sphere sphere1(5);
  PrintState("counter sphere1", sphere1.Counter());
  Sphere sphere2(5);
  PrintState("counter sphere1", sphere1.Counter());
  Sphere sphere3(5);
  PrintState("counter sphere1", sphere1.Counter());
  Sphere sphere4(5);
  PrintState("counter sphere", sphere.Counter());
  PrintState("counter sphere1", sphere1.Counter());
  PrintState("counter sphere4", sphere4.Counter());
}