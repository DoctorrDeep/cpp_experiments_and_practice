#include <stdlib.h>

int main() {
  void *p = malloc(100 * sizeof(double));
  free(p); // OK

  void *q = malloc(100); 
  void *q2 = q;

  free(q); // OK
  free(q2); // ERROR

}
