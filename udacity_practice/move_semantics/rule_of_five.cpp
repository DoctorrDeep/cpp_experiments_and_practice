// There are 3 cases represented in 3 `int main(){` functions
// Make sure to scroll
#include <iostream>
#include <stdlib.h>

class MyMovableClass {
private:
  int _size;
  int *_data;

public:
  MyMovableClass(size_t size) // constructor
  {
    _size = size;
    _data = new int[_size];
    std::cout << "CREATING instance of MyMovableClass at " << this << " allocated with size = " << _size * sizeof(int) << " bytes" << std::endl;
  }

  ~MyMovableClass() // 1 : destructor
  {
    std::cout << "DELETING instance of MyMovableClass at " << this << std::endl;
    delete[] _data;
  }

  MyMovableClass(const MyMovableClass &source) // 2 : copy constructor
  {
    _size = source._size;
    _data = new int[_size];
    *_data = *source._data;
    std::cout << "COPYING content of instance " << &source << " to instance " << this << std::endl;
  }

  MyMovableClass &operator=(const MyMovableClass &source) // 3 : copy assignment operator
  {
    std::cout << "ASSIGNING content of instance " << &source << " to instance " << this << std::endl;
    if (this == &source)
      return *this;
    delete[] _data;
    _data = new int[source._size];
    *_data = *source._data;
    _size = source._size;
    return *this;
  }

  MyMovableClass(MyMovableClass &&source) // 4 : move constructor
  {
    std::cout << "MOVING (c'tor) instance " << &source << " to instance " << this << std::endl;
    _data = source._data;
    _size = source._size;
    source._data = nullptr;
    source._size = 0;
  }

  MyMovableClass &operator=(MyMovableClass &&source) // 5 : Move assignment operator
  {
    std::cout << "MOVING (assign) instance " << &source << " to instance " << this << std::endl;
    if (this == &source)
      return *this;
    delete[] _data;
    _data = source._data;
    _size = source._size;
    _data = nullptr;
    _size = 0;
    return *this;
  }
};

void useObject(MyMovableClass obj){
  std::cout << "Using object at " << &obj << std::endl;
}

// ===============Case 1: (Comment out Case 2/3)========================
// int main() {

//   MyMovableClass obj1(100), obj2(200); // constructor
//   MyMovableClass obj3(obj1); // copy constructor
//   MyMovableClass obj4 = obj1; // copy constructor
//   obj4 = obj2; // copy assignment operator

//   return 0;
// }

// Output Case 1 (memory locations simplified for readability)

// CREATING instance of MyMovableClass at AAA allocated with size = 400 bytes --> Constructor for obj1
// CREATING instance of MyMovableClass at BBB allocated with size = 800 bytes --> Constructor for obj2
// COPYING content of instance AAA to instance CCC                            --> source obj1 copied to obj3 with copy constructor
// COPYING content of instance AAA to instance DDD                            --> source obj1 copied to obj4 with copy constructor
// ASSIGNING content of instance BBB to instance DDD                          --> source obj2 copied to obj4 with copy constructor
// DELETING instance of MyMovableClass at DDD                                 --> End of code, deleting resources for obj4
// DELETING instance of MyMovableClass at CCC                                 --> End of code, deleting resources for obj3
// DELETING instance of MyMovableClass at BBB                                 --> End of code, deleting resources for obj2
// DELETING instance of MyMovableClass at AAA                                 --> End of code, deleting resources for obj1

// ===============Case 2: (Comment out Case 1/3)========================
// IMPORTANT!! Run with `g++ --std=c++11 -fno-elide-constructors rule_of_five.cpp && ./a.out && rm a.out`
// turn off an optimization techniques called copy elision

// int main() {

//   MyMovableClass obj5(100); // constructor
//   obj5 = MyMovableClass(200); // move assignment operator
//   MyMovableClass obj6 = MyMovableClass(300); // move constructor It is the same as `MyMovableClass obj6(MyMovableClass(300))`
//   MyMovableClass obj7(MyMovableClass(400));

//   return 0;
// }

// Output Case 2 (memory locations simplified for readability)

// CREATING instance of MyMovableClass at AAA allocated with size = 400 bytes   --> obj5(100) constructor
// CREATING instance of MyMovableClass at BBB allocated with size = 800 bytes   --> Temp object MyMovableClass(200)  move assignment operator
// MOVING (assign) instance BBB to instance AAA                                 --> BBB temp obj moved to obj5(AAA)
// DELETING instance of MyMovableClass at BBB                                   --> BBB deleted after above move is done 
// CREATING instance of MyMovableClass at BBB' allocated with size = 1200 bytes --> BBB' memory location is RE-USED to make temp obj MyMovableClass(300) move constructor
// MOVING (c'tor) instance BBB' to instance DDD                                 --> BBB' temp obj moved to obj6(DDD)
// DELETING instance of MyMovableClass at BBB'                                  --> BBB' deleted after above move is done
// CREATING instance of MyMovableClass at BBB" allocated with size = 1600 bytes --> BBB" memory location is RE-USED to make temp obj MyMovableClass(400) move constructor
// MOVING (c'tor) instance BBB" to instance CCC                                 --> BBB" temp obj moved to obj7(CCC)
// DELETING instance of MyMovableClass at BBB"                                  --> BBB" deleted after above move is done
// DELETING instance of MyMovableClass at CCC                                   --> End of code, deleting resources for obj7
// DELETING instance of MyMovableClass at DDD                                   --> End of code, deleting resources for obj6
// DELETING instance of MyMovableClass at AAA                                   --> End of code, deleting resources for obj5

// ===============Case 3: (Comment out Case 1/2)========================
int main(){
  // Copy then move (less efficient call to useObject)
  MyMovableClass obj1(100);
  useObject(obj1);

  // Direct Move (more efficient call to useObject)
  MyMovableClass obj2(200);
  useObject(std::move(obj2));
}

// Output

// CREATING instance of MyMovableClass at AAA allocated with size = 400 bytes  --> Create obj1 at AAA
// COPYING content of instance AAA to instance BBB                             --> Copy source obj1 to target : scope of useObject
// Using object at BBB                                                         --> output from useObject
// DELETING instance of MyMovableClass at BBB                                  --> Delete copy of obj1 BBB after useObject scope finishes
// CREATING instance of MyMovableClass at CCC allocated with size = 800 bytes  --> Create obj2 at CCC
// MOVING (c'tor) instance CCC to instance BBB'                                --> Move obj2 data from CCC to target BBB(location reused) : scope of useObject 
// Using object at BBB'                                                        --> output from useObject
// DELETING instance of MyMovableClass at BBB'                                 --> Delete BBB' after useObject scope finishes
// DELETING instance of MyMovableClass at CCC                                  --> End of code, deleting resources for obj2
// DELETING instance of MyMovableClass at AAA                                  --> End of code, deleting resources for obj1