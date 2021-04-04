#include <iostream>
#include <memory>

int main(){

  std::shared_ptr<int> xyz(new int);
  std::cout << "Use count to shared pointers object xyz = " << xyz.use_count() << std::endl;

  std::weak_ptr<int> xyz1(xyz); // Weak pointers can point to shared pointers
  std::weak_ptr<int> xyz2(xyz1);// Weak pointers can point to other weak pointers
  std::cout << "Use count to shared pointers object xyz = " << xyz.use_count() << std::endl;

  // std::weak_ptr<int> xyz3(new int); // COMPILE Error
  // weak pointers can ONLY point other objects managed by a shared pointer
  // They non-owning references.

  return 0;
}

// OUTPUT
// Use count to shared pointers object xyz = 1
// Use count to shared pointers object xyz = 1

// When checked with valgrind, no leaks were found!
// `g++ weak_pointers.cpp -o weak_pointers`
// `valgrind --verbose --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=weak_pointers_valgrind_output.txt ./weak_pointers`