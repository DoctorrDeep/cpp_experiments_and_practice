// Integer types
// run with 
// g++ integer_types.c -o int_ts && ./int_ts

#include <iostream>
#include <limits.h>
using namespace std;

int main(){
    int aNum = 4386570743826597843697;
    cout << "You sent: " << aNum << endl;

    cout << "INT_MAX: " << INT_MAX << endl;
    cout << "INT_MIN: " << INT_MIN << endl;

    // long int aNewNum = 4386570743826597843;
    // cout << "You sent: " << aNewNum << endl;

    short int aNewNum = 23434;
    cout << "You sent: " << aNewNum << endl;

    cout << "Size of int: " << sizeof(int) << endl;
    cout << "Size of long int: " << sizeof(long int) << endl;
    cout << "Size of short int: " << sizeof(short int) << endl;


    return 0;
}