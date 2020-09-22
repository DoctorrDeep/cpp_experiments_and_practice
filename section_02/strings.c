// Variables
// run with
// g++ strings.c -o strss && ./strss
#include <iostream>
using namespace std;

int main(){

    int value = 6;
    cout << "value: " << value << endl;

    string typeDog1 = "pitbull is a type";
    cout << "Type of dog: " << typeDog1 << endl;

    string typeDog2 = "lab is a type";
    cout << "Type of dog: " << typeDog2 << endl;

    cout << "Type of dogs: " << typeDog1 + " " + typeDog2 << endl;

    string allTypesDog = " ";
    allTypesDog = typeDog1 + allTypesDog + typeDog2;
    cout << "Type of dogs: " << allTypesDog << endl;

	return 0;
}
