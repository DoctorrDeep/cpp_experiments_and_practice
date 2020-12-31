#include <cassert>
#include <cmath>
#include <iostream>
#include <stdexcept>

// TODO: Define class Sphere
class Sphere {
public:
  // Constructor
  Sphere(float r) : radius_(r), volume_((4.0f / 3.0f) * M_PI * pow(r, 3)) {
    if (r <= 0)
      throw std::invalid_argument(
          "Invalid radius. Use positive non-zero float.");
  }

  // Accessors
  float Radius() const { return radius_; }
  float Volume() const { return volume_; };

  // Mutators

private:
  // Private members
  float const radius_;
  float const volume_;
};

// Test
int main(void) {
  Sphere sphere(5);
  assert(sphere.Radius() == 5);
  assert(abs(sphere.Volume() - 523.6) < 1);
}