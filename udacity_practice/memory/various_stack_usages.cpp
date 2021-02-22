#include <stdio.h>

void CallByValue(int i) {
  int j = 1;
  printf("call-by-value: %p\n", &j);
}

void CallByPointer(int *i) {
  int j = 1;
  printf("call-by-pointer: %p\n", &j);
}

void CallByReference(int &i) {
  int j = 1;
  printf("call-by-reference: %p\n", &j);
}

int main() {
  int i = 0;
  printf("stack bottom: %p\n", &i);
  CallByValue(i);
  CallByPointer(&i);
  CallByReference(i);
  return 0;
}

//output

// stack bottom: 0x7ffeda8c2274
// call-by-value: 0x7ffeda8c2254
// call-by-pointer: 0x7ffeda8c2254
// call-by-reference: 0x7ffeda8c2254