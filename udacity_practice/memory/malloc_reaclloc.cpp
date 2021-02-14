#include <iostream>
#include <stdlib.h>

using std::cout;

int main() {
  int *p = (int *)malloc(2 * sizeof(int));
  p[0] = 7;
  p[1] = 9;

  cout << "\nAll 4 p's: only pos 1,2 allocated and assigned."
       << "\n"
       << "P0=" << p[0] << " P1=" << p[1] << " P2=" << p[2] << " P3=" << p[3]
       << "\n";
  // Danger here is p[2], p[3] have not been initialized. This could be memory
  // assigned to other programs.

  p = (int *)realloc(p, 4 * sizeof(int));
  p[2] = 13;
  p[3] = 17;

  cout << "\nAll 4 p's: all 4 pos allocated and assigned"
       << "\n"
       << "P0=" << p[0] << " P1=" << p[1] << " P2=" << p[2] << " P3=" << p[3]
       << "\n";

  p = (int *)realloc(p, 2 * sizeof(int));

  cout << "\nAll 4 p's: pos 2 and 3 have been deallocated"
       << "\n"
       << "P0=" << p[0] << " P1=" << p[1] << " P2=" << p[2] << " P3=" << p[3]
       << "\n";
  // danger here is that p[2] and p[3] have been deallocated and might be in use
  // by other programs.
  // No compiler errors, no runtime errors.

  // Using a new way to access pointers and their values

  cout << "\n";

  cout << p + 0 << " " << *(p + 0) << "\n";
  cout << p + 1 << " " << *(p + 1) << "\n";
  cout << p + 2 << " " << *(p + 2) << "\n";
  cout << p + 3 << " " << *(p + 3) << "\n";
}