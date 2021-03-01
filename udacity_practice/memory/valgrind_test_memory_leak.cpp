int main(){
  int* pInt = new int[10];
  return 0;
}

// Run by installing valgrind
// create the binary 
// `g++ valgrind_test_memory_leak.cpp` // binary called a.out will be created
// run valgrind
// `valgrind --verbose --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=valgrind-output.txt ./a.out`
// contents of log file are a lot , see for yourself