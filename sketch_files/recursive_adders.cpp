#include <iostream>

int simple_adder(int &&n){
    if (n == 0) return 0;
    else return simple_adder(n-1) + n;
}

int one_line_adder(int &&n){
    return (n != 0) * (simple_adder(n-1) + n) + (n == 0);
}

int main(){
    std::cout << "Simple adder for 10: " << simple_adder(10) << std::endl;
    std::cout << "One_line adder for 10: " << one_line_adder(10) << std::endl;
    return 0;
}