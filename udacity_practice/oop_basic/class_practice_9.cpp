// Static methods in classes
#include <cassert>
#include <cmath>
#include <iostream>
#include <stdexcept>

// TODO: Define class Sphere
class Sphere {
public:
  // Constructor
  Sphere(float r) : radius_(r), volume_(ValidateCalculateVolume(r)) {}

  // Accessors
  float Radius() const { return radius_; };
  float Volume() const { return volume_; };

  // Mutators
  void Radius(float new_radius) {
    radius_ = new_radius;
    volume_ = ValidateCalculateVolume(radius_);
  };

  // Static method for ValidateCalculateVolume so that the method can be called from outside the class
  static float ValidateCalculateVolume(float any_radius) {
    if (any_radius <= 0)
      throw std::invalid_argument(
          "Invalid radius. Use positive non-zero float.");
    else
      return (4.0f / 3.0f) * M_PI * pow(any_radius, 3);
  }

private:
  // Private members
  float radius_;
  float volume_;
};

// Test
int main(void) {
  // Direct assert on static method from class without instantiating an object
  // of the class "Sphere::ValidateCalculateVolume"
  assert(abs(Sphere::ValidateCalculateVolume(3) - 113.1) < 1);

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

  // Direct assert on static method from class without instantiating an object
  // of the class "Sphere::ValidateCalculateVolume"
  assert(abs(Sphere::ValidateCalculateVolume(3) - 113.1) < 1);
}