## Using CMake

To build the src file:

- `mkdir build` --- > pwd shoudl be at the same level as this readme and __CMakeLists.txt__
- `cd build`
- `cmake ..`
- `make`
- Now there will be an executable file (as named in the _add_executable_ line in __CMakeLists.txt__) in the build directory.
- `./_executablefilename_`

Note: This GIT repo is setup to ignore the build files created. Hence you will not see the build files made!