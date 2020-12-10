## Using CMake

To build the src file:

- `mkdir build` --- > pwd shoudl be at the same level as this readme and __CMakeLists.txt__
- `cd build`
- `cmake ..`
- `make`
- Now there will be an executable file (as named in the _add_executable_ line in __CMakeLists.txt__) in the build directory.
- `./_executablefilename_`

### Why cmake?

- once the `cmake ..` command has been run, you only have to run the `make` command for any changes made to the project
- for projects with many files and long compile times, this makes things more efficient
- Of course, if things go wrong, it can be rebuilt from the ground up by deleteing the build directory and staring at the beginning. 

Note: This GIT repo is setup to ignore the build files created. Hence you will not see the build files made!