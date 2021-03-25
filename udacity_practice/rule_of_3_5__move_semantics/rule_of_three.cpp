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
    std::cout << "CREATING instance of MyMovableClass at " << this
              << " allocated with size = " << _size * sizeof(int) << " bytes"
              << std::endl;
  }

  ~MyMovableClass() // 1 : destructor
  {
    std::cout << "DELETING instance of MyMovableClass at " << this << std::endl;
    delete[] _data;
  }

  MyMovableClass(const MyMovableClass &source) // 2 : Copy constructor
  {
    _size = source._size; // copy size int to copy
    _data = new int[_size]; // allocate memory the of correct size to copy
    *_data = *source._data; // copy contents of source _data to copy memory location for data
    std::cout << "Copying (copy constructor) content at " << &source << " to instance at " << this << std::endl;
  }

  MyMovableClass &operator=(const MyMovableClass &source) // 3 : Copy assignment operator
  {
    std::cout << "Copying (copy assignment operator) content at " << &source << " to instance at " << this << std::endl;

    if (_data == source._data){
      return *this;
    }

    delete[] _data;


    _size = source._size;
    int *_data = new int[_size];
    *_data = *source._data;

    // The above 3 lines could also arranged like this
    // int *_data = new int[source._size]; // --> notice the use of source._size instead of _size since it has not been defined yet
    // *_data = *source._data;  // --> same sequence as above. First the memory is allocated on heap then content is sent to heap
    // _size = source._size; // --> size definition comes last

    return *this;    
  }


};

// Function that creates an instance of class OUTSIDE class scope
MyMovableClass createObject(int size){
  MyMovableClass obj(size);
  return obj;
}

int main(){
  MyMovableClass obj1(10); // normal constructor
  MyMovableClass obj2(obj1); // copy constructor
  MyMovableClass obj3 = obj1;// copy constructor(Yes!)
  obj2 = obj3;  // copy assignment operator

  MyMovableClass obj4 = createObject(20);
  // first createObject creates an instance temporarily in the stack
  // Then obj4 is populated (not tenporary) by doing a copy operation with the copy constructor on the temporary object
  // This copy constructor is NOT going to do the cout (see OUTPUT below) because cout is in 
  // a copy constructor for a temporary object (output of createObject)
  // 2 expensive copy operation: 
  // temp data on stack (output of `obj(size)`) --> temporary object (output of `createObject(20)`) --> obj4 (target destionation)
}

// Output

// CREATING instance of MyMovableClass at 0x7ffccfa5f8d0 allocated with size = 40 bytes        --> obj1
// Copying (copy constructor) content at 0x7ffccfa5f8d0 to instance at 0x7ffccfa5f8e0          --> obj1 to obj2
// Copying (copy constructor) content at 0x7ffccfa5f8d0 to instance at 0x7ffccfa5f8f0          --> obj1 to obj3
// Copying (copy assignment operator) content at 0x7ffccfa5f8f0 to instance at 0x7ffccfa5f8e0  --> obj3 to obj2
// CREATING instance of MyMovableClass at 0x7ffcbfebf630 allocated with size = 80 bytes        --> obj4
// DELETING instance of MyMovableClass at 0x7ffcbfebf630   --> obj4
// DELETING instance of MyMovableClass at 0x7ffccfa5f8f0   --> obj3
// DELETING instance of MyMovableClass at 0x7ffccfa5f8e0   --> obj2
// DELETING instance of MyMovableClass at 0x7ffccfa5f8d0   --> obj1