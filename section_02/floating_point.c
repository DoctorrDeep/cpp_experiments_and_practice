// Floating point
// run with 
// g++ floating_point.c -o fl_p && ./fl_p

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    // float aNum = 76.88885;
    // double aNum = 76.88885;
    long double aNum = 76.88885;

    cout << "You sent: " << aNum << endl;
    cout << "fixed: " << fixed << aNum << endl;
    cout << "scientific: " << scientific << aNum << endl;  
    cout << "set precision 20 , fixed: " << setprecision(20) << fixed << aNum << endl;

    return 0;
}