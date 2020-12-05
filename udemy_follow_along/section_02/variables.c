// Variables
// run with
// g++ variables.c -o vars && ./vars
#include <iostream>
using namespace std;

int main(){

    int numberCats = 5;
    cout << "number of Cats: " << numberCats << endl;

    int numberDogs = 7;
    cout << "number of Dogs: " << numberDogs << endl;

    int totalAnimals = 0;
    totalAnimals = numberCats + numberDogs;
    cout << "number of Animals: " << numberCats + numberDogs << endl;
    cout << "number of Animals: " << totalAnimals << endl;

	return 0;
}
