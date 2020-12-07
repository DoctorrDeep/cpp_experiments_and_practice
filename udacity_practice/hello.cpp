#include <iostream>
#include <string>
#include <vector>

int main() {
  std::cout << "Hello World!\n\n";

  std::vector<std::string> brothers{"Amar", "Akbar", "Anthony"};
  for (std::string const &brother : brothers) {
    std::cout << "Hello " << brother << "!\n";
  }
}