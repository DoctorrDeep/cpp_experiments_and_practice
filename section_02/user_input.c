// User inputs
// run with
// g++ user_input.c -o u_in && ./u_in
#include <iostream>
using namespace std;

int main(){

    cout << "Enter dog breed: " << flush ;

    string typeDog1;
    cin >> typeDog1;

    cout << "You entered: " << typeDog1 << endl;


    cout << "Enter count of dogs in breed " << typeDog1 << ": " << flush ;

    int countDog1;
    cin >> countDog1;

    cout << "There are " << countDog1 << " dogs of type " << typeDog1 <<  endl;

	return 0;
}
