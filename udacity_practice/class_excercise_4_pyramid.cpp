#include <cassert>
#include <stdexcept>

// TODO: Define class Pyramid
class Pyramid {
  // public class members
public:
  // constructor
  Pyramid(int l, int w, int h);

  // accessors
  int Length() const { return length_; };
  int Width() const { return width_; };
  int Height() const { return height_; };

  // mutators
  void Length(int x) { length_ = Validate(x); };
  void Width(int x) { width_ = Validate(x); };
  void Height(int x) { height_ = Validate(x); };

  int Validate(int x) {
    if (x >= 0)
      return x;
    else
      throw std::invalid_argument("negative dimension");
  };

  // public Volume() function
  float Volume() {
    // Option 1
    // return (length_ * width_ * height_) / 3;
    // Option 2
    return (Length() * Width() * Height()) / 3;
  };

  // private class members
private:
  int length_;
  int width_;
  int height_;
};

Pyramid::Pyramid(int l, int w, int h) {
  Length(l);
  Width(w);
  Height(h);
};

// Test
int main() {
  Pyramid pyramid(4, 5, 6);
  assert(pyramid.Length() == 4);
  assert(pyramid.Width() == 5);
  assert(pyramid.Height() == 6);
  assert(pyramid.Volume() == 40);

  bool caught{false};
  try {
    Pyramid invalid(-1, 2, 3);
  } catch (...) {
    caught = true;
  }
  assert(caught);
}