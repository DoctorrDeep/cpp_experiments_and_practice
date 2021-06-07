### BIG NOTE

All programs with thread have to be compliled with `-pthread` flag

#### Good Example 

```
$ g++ -pthread 02_simple_thread_example.cpp && ./a.out && rm a.out
```

#### Bad Example 

```
`$ g++ 02_simple_thread_example.cpp && ./a.out && rm a.out`
/usr/bin/ld: /tmp/ccMAQUvo.o: in function `std::thread::thread<void (&)(), , void>(void (&)())':
02_simple_thread_example.cpp:(.text._ZNSt6threadC2IRFvvEJEvEEOT_DpOT0_[_ZNSt6threadC5IRFvvEJEvEEOT_DpOT0_]+0x33): undefined reference to `pthread_create'
collect2: error: ld returned 1 exit status
```

Note the mention of `undefined reference to  'pthread_create'`