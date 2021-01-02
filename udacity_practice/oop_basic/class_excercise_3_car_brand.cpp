#include <cstring>
#include <iostream>
#include <string>

class Car {
  // TODO: Declare private attributes
private:
  int horsepower{400};
  int weight{2500};
  std::string brand;

  // TODO: Declare getter and setter for brand
public:
  std::string GetBrand() const { return brand; };
  void SetBrand(std::string b) { brand = b; };
  int GetHp() const { return horsepower; };
  void SetHp(int hp) { horsepower = hp; };
  int GetWeight() const { return weight; };
  void SetWeight(int w) { weight = w; };
};

// Test in main()
int main() {
  Car car;
  car.SetBrand("Peugeot");
  std::cout << car.GetBrand() << "\n";
}