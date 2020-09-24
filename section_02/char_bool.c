// char_bool
// run with 
// g++ char_bool.c -o char_bool && ./char_bool

#include <iostream>

using namespace std;

int main(){

    cout << "bool:" << endl;
    
    // bool bVal = true;
    bool bVal = false;
    // bool bVal = '';
    // bool bVal = 'g';
    // bool bVal = 55;
    // bool bVal = '7';
    // bool bVal = 'g';

    cout << bVal << endl;


    cout << "char:" << endl;

    char cVal = 55;
    // char cVal = '7';
    // char cVal = 'g';
    // char cVal = 550;

    cout << cVal << endl;
    cout << (int)cVal << endl;


    return 0;
}