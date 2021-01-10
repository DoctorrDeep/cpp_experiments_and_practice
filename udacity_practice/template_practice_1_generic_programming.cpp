#include <assert.h>

// TODO: Create a generic function Product that multiplies two parameters

template <typename Type> Type Product(Type a, Type b) { return a * b; }
// "Type", "a", "b", "Product": are all variables and can be named 
// in any way desired. See example below.
template <typename T> T Prdct(T aum, T boom) { return aum * boom; }

int main() {
  assert(Product<int>(10, 2) == 20);
  assert(Prdct<float>(10.1, 2) - 20.2 < 0.1);
}