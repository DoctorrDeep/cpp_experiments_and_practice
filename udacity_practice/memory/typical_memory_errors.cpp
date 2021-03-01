// Try each block uncomented (one at a time)

// #include <iostream>
#include <stdio.h>
#include <string.h>


int main() {
  // Block 1: Buffer Overruns

  // char my_str[1]; // Note this code will work if yopu chnage it to `char my_str[14];`
  // strcpy(my_str, "BufferHathOverrun");
  // printf("\n\n %s \n\n",my_str);

      // STDOutput

      // "compiler warning"
      //   typical_memory_errors.cpp: In function ‘int main()’:
      // typical_memory_errors.cpp:10:9: warning: ‘void* __builtin_memcpy(void*, const void*, long unsigned int)’ writing 18 bytes into a region of size 1 overflows the destination [-Wstringop-overflow=]
      //    10 |   strcpy(my_str, "BufferHathOverrun");
      //       |   ~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~

      // "during execurtion"
      // BufferHathOverrun 
      // *** stack smashing detected ***: terminated
      // Aborted (core dumped)



  // Block 2: Uninitialized memory (This is potentially undefined but in g++ (GCC) 10.2.0 all are initialized to 0!)
  //          In fact if you run this with another non-erroring block of code, then this will show a weird high number!
  // int a;
  // int b = a * 42;
  // printf("\n\n%d\n\n",b);



  // Block 3a: Incorrect pairing of allocation and deallocation
  // double *pDbl=new double[5]; 
  // delete pDbl;  // Correct implementation

  // Block 3b: Incorrect pairing of allocation and deallocation
  // char *pChr=new char[5];
  // delete[] pChr;
  // delete[] pChr;

      // Std output
      // free(): double free detected in tcache 2
      // Aborted (core dumped)



  // Block 4: Invalid memory access --> g++ 10.2.0 does not error this 
  char *pStr=new char[25];
  delete[] pStr;
  strcpy(pStr, "Invalid Access");
  printf("\n\n %s \n\n",pStr);
}