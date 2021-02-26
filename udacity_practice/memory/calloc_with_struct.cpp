#include <iostream>
#include <stdlib.h>

using std::cout;

int main(){

  // void *p = malloc(sizeof(int)); // doesnt work
  int *p = (int*)malloc(sizeof(int));
  cout << "Value = " <<  *p << "\nAddress = " << p << "\n";
  int *q = (int*)malloc(sizeof(int));
  cout << "Value = " <<  *q << "\nAddress = " << q << "\n";
  int *r = (int*)malloc(sizeof(int));
  cout << "Value = " <<  *r << "\nAddress = " << r << "\n";

  int *a = (int*)malloc(3*sizeof(int));
  a[0] = 1;
  a[1] = 2;
  a[2] = 3;
  cout << a << " " << a[0] << " " << a[1] << " " << a[2] << "\n";

  struct MyStruct {
    int i;
    double d;
    char a[5];
  };

  // Struct created with calloc
  MyStruct *s = (MyStruct*)calloc(4,sizeof(MyStruct));
  s[0].i = 4;
  s[0].d = 3.14159;
  s[0].a[0] = 'a';

  for (int i =0; i < 4; i++){
    cout << "\nMyStruct #" << i << " data \n";
    cout << "int i :" << s[i].i << "\n";
    cout << "double d :" << s[i].d << "\n";
    cout << "char a[5] :" << s[i].a << "\n";
  }
}

// Output

// Value = 0 --> Auto initialized value
// Address = 0x5605e7e87eb0
// Value = 0 --> Auto initialized value
// Address = 0x5605e7e882e0
// Value = 0 --> Auto initialized value
// Address = 0x5605e7e88300
//
// 0x5605e7e88320 1 2 3 --> Array output. Array created by malloc.

// MyStruct #0 data 
// int i :4
// double d :3.14159
// char a[5] :a

// MyStruct #1 data  --> wasn't defined
// int i :0
// double d :0
// char a[5] :

// MyStruct #2 data --> wasn't defined
// int i :0
// double d :0
// char a[5] :

// MyStruct #3 data --> wasn't defined
// int i :0
// double d :0
// char a[5] :