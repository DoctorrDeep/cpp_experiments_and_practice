// if statement
// run with 
// g++ if_statement.c -o if_statement && ./if_statement

#include <iostream>

using namespace std;

int main(){

    string knownName = "Ambar";
    cout << "Enter your name > " << flush;
    
    string input;
    cin >> input;

    cout << "Your name : '" << input << "'" << endl;

    if (knownName == input){
        cout << "we know you! " << knownName << endl;
    }else{
        cout << "Who the heck is that? We dont know any " << input << endl;
    }


    return 0;
}