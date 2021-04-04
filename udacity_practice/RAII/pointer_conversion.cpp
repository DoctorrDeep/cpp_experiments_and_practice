#include <iostream>
#include <memory>

int main(){

  //construct a unique pointer
  std::unique_ptr<int> my_unq_ptr1(new int);
  std::cout << my_unq_ptr1.get() << ": Heap resource location of my_unq_ptr1\n";

  //(1) shared pointer from unique ptr
  std::shared_ptr<int> my_shr_ptr1 = std::move(my_unq_ptr1);
  // my_unq_ptr1 will lose access to resource in heap
  // my_shr_ptr1 wil now have access to same resource
  std::cout << "\nAfter step 1:\n";
  std::cout << my_unq_ptr1.get() << ": Heap resource location of my_unq_ptr1\n";
  std::cout << my_shr_ptr1.get() << ": Heap resource location of my_shr_ptr1\n";
  std::cout << my_shr_ptr1.use_count() << ": Shared pointer use_count of my_shr_ptr1\n";

  //(2) shared pointer from weak ptr
  std::weak_ptr<int> my_wk_ptr1(my_shr_ptr1); // create genericc weak pointer
  std::shared_ptr<int> my_shr_ptr2 = my_wk_ptr1.lock();
  // make a shared pointer from a weak pointer by calling `.lock()
  // Use case: If you need to make sure that the weak pointer you have is 
  // no deallocated before your work is done, use this technique.
  std::cout << "\nAfter step 2:\n";
  std::cout << my_unq_ptr1.get() << ": Heap resource location of my_unq_ptr1\n";
  std::cout << my_shr_ptr1.get() << ": Heap resource location of my_shr_ptr1\n";
  std::cout << my_shr_ptr1.use_count() << ": Shared pointer use_count of my_shr_ptr1\n";
  std::cout << my_wk_ptr1.use_count() << ": Weak pointer use_count of my_wk_ptr1\n";
  std::cout << my_shr_ptr2.get() << ": Heap resource location of my_shr_ptr2\n";
  std::cout << my_shr_ptr2.use_count() << ": Shared pointer use_count of my_shr_ptr2\n";

  //(3) raw pointer from shared (or unique) pointer
  int *my_raw_ptr1 = my_shr_ptr2.get();
  delete my_raw_ptr1;
  // Contd. from the Use case edsccribed in step (2)
  // here a raw pointer is extraced and an attempt is made to deallocate the memoory
  // This causes an error because that memeory is being managed by a shared pointer 
  // and hence cannot be deallocated except with special calls or end-of-scope.
  // NOTE1: it is not possible to convert away from a shared pointer
  // NOTE2: See output below

  std::cout << "\nAfter step 3:\n";
  std::cout << my_shr_ptr1.get() << ": Heap resource location of my_shr_ptr1\n";
  std::cout << my_shr_ptr1.use_count() << ": Shared pointer use_count of my_shr_ptr1\n";
  std::cout << my_wk_ptr1.use_count() << ": Weak pointer use_count of my_wk_ptr1\n";
  std::cout << my_shr_ptr2.get() << ": Heap resource location of my_shr_ptr2\n";
  std::cout << my_shr_ptr2.use_count() << ": Shared pointer use_count of my_shr_ptr2\n\n";

  return 0;
}

// OUTPUT
// 0x56408a0b1eb0: Heap resource location of my_unq_ptr1

// After step 1:
// 0: Heap resource location of my_unq_ptr1
// 0x56408a0b1eb0: Heap resource location of my_shr_ptr1
// 1: Shared pointer use_count of my_shr_ptr1

// After step 2:
// 0: Heap resource location of my_unq_ptr1
// 0x56408a0b1eb0: Heap resource location of my_shr_ptr1
// 2: Shared pointer use_count of my_shr_ptr1
// 2: Weak pointer use_count of my_wk_ptr1
// 0x56408a0b1eb0: Heap resource location of my_shr_ptr2
// 2: Shared pointer use_count of my_shr_ptr2

// After step 3:
// 0x56408a0b1eb0: Heap resource location of my_shr_ptr1
// 2: Shared pointer use_count of my_shr_ptr1
// 2: Weak pointer use_count of my_wk_ptr1
// 0x56408a0b1eb0: Heap resource location of my_shr_ptr2
// 2: Shared pointer use_count of my_shr_ptr2

// free(): double free detected in tcache 2
// Aborted (core dumped)

// NOTE: I expected the compiler to raise an error and stop me from using delete
// Instead the core dump happened when the shared pointers resources were deallocaetd 
// as part of end-of-scope cleanups!
// Tried with
// `g++ --std=c++17 pointer_conversion.cpp && ./a.out && rm a.out`
// `g++ --std=c++11 pointer_conversion.cpp && ./a.out && rm a.out`