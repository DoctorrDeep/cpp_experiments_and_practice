#include <assert.h>
#include <cmath>

// TODO: Define PI
#define PI 3.14159
// for some reason in "class_exercise_3_override.cpp" `;` was optional at the
// end of the define line (works with and without semi-colon.) In this case
// where PI is being used in main(), there are some objections raised by the
// compiler. No idea why...

// TODO: Declare abstract class VehicleModel
class VehicleModel {
  // TODO: Declare virtual function Move()
  virtual void Move(double velocity, double phi) = 0;
  // Since this base class cannot be instantiated this virtual function need not
  // be declared under "public:"
};
// TODO: Derive class ParticleModel from VehicleModel
class ParticleModel : VehicleModel {
public:
  // Constructor not required since all member variables
  // are being initialized to 0
  // ParticleModel(double x = 0, double y = 0, double t = 0)
  //     : x(x), y(y), theta(t) {}

  // TODO: Define x, y, and theta
  double x = 0;
  double y = 0;
  double theta = 0;

  // TODO: Override the Move() function
  void Move(double vel, double phi) override {
    theta += phi;
    x += vel * cos(theta);
    y += vel * sin(theta);
  };
};

// TODO: Derive class BicycleModel from ParticleModel
class BicycleModel : public ParticleModel {
  // The "public"  in "public ParticleModel {" is essential, otherwise x, y
  // theta will not be accessible to the derived class BicycleModel
public:
  // Constructor not required since all member variables
  // are being initialized to 0
  // BicycleModel(double x = 0.0, double y = 0, double t = 0, double l = 1) :
  // x(x), y(y), theta(t), L(l){};

  // TODO: Override the Move() function
  void Move(double vel, double phi) override {
    theta += (vel / L) * tan(phi);
    x += vel * cos(theta);
    y += vel * sin(theta);
  };

  // x,y,theta will be passed from the base class.
  // Hence no need to declare them
  // double x, y, theta;

  // TODO: Define L
  double const L = 1;
};

// TODO: Pass the tests
int main() {
  // Test function overriding
  ParticleModel particle;
  BicycleModel bicycle;
  particle.Move(10, PI / 9);
  bicycle.Move(10, PI / 9);
  assert(particle.x != bicycle.x);
  assert(particle.y != bicycle.y);
  assert(particle.theta != bicycle.theta);
}