#include <cassert>
#include <cmath>
#include <iostream>
#include <stdexcept>

// TODO: Define class Sphere
class Sphere {
public:
  // Constructor
  Sphere(float r) : radius_(r), volume_(ValidateCalculateVolume()) {}

  // Accessors
  float Radius() const { return radius_; };
  float Volume() const { return volume_; };

  // Mutators
  void Radius(float new_radius) {
    radius_ = new_radius;
    volume_ = ValidateCalculateVolume();
  };

private:
  // Private members
  float radius_;
  float volume_;
  float ValidateCalculateVolume() {
    if (radius_ <= 0)
      throw std::invalid_argument(
          "Invalid radius. Use positive non-zero float.");
    else
      return (4.0f / 3.0f) * M_PI * pow(radius_, 3);
  }
};

// Test
int main(void) {
  Sphere sphere(5);
  assert(sphere.Radius() == 5);
  assert(abs(sphere.Volume() - 523.6) < 1);

  sphere.Radius(3);
  assert(sphere.Radius() == 3);
  assert(abs(sphere.Volume() - 113.1) < 1);

  bool caught{false};
  try {
    sphere.Radius(-1);
  } catch (...) {
    caught = true;
  }
  assert(caught);
}