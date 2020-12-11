## Main links

- Udacity project repo: [Repo README.md](https://github.com/udacity/CppND-Route-Planning-Project/blob/master/README.md)
- IO2D project repo: [Samples maps repo](https://github.com/cpp-io2d/P0267_RefImpl/tree/master/P0267_RefImpl/Samples/maps)
- Troubleshooting [https://github.com/udacity/CppND-Route-Planning-Project/issues/1](https://github.com/udacity/CppND-Route-Planning-Project/issues/1)

## How to get started?

#### IO2D

```
cd ~/Documents;
sudo apt update;
sudo apt install build-essential;
sudo apt install cmake;
sudo apt install libcairo2-dev;
sudo apt install libgraphicsmagick1-dev;
sudo apt install libpng-dev;
git clone --recurse-submodules https://github.com/cpp-io2d/P0267_RefImpl;
cd ~/Documents/P0267_RefImpl;
vim ~/Documents/P0267_RefImpl/CMakeLists.txt;
```
Remove the following lines (L38-L40)
```
if( NOT DEFINED IO2D_WITHOUT_SAMPLES )
    add_subdirectory(P0267_RefImpl/Samples)
endif()
```

```
mkdir ~/Documents/P0267_RefImpl/Debug;
cd ~/Documents/P0267_RefImpl/Debug;
cmake --config Debug "-DCMAKE_BUILD_TYPE=Debug" ..;
cmake --build .;
sudo make install;
```

#### Udacity project repo

TODO:Maybe its best to fork the Udacity project?

```
cd ~/Documents;
git clone git@github.com:udacity/CppND-Route-Planning-Project.git --recurse-submodules
cd ~/Documents/CppND-Route-Planning-Project;
mkdir ~/Documents/CppND-Route-Planning-Project/build;
cd ~/Documents/CppND-Route-Planning-Project/build;
cmake ..;
make;
```

## Check if the installation was successful

```
cd ~/Documents/CppND-Route-Planning-Project/build;
./test;
./OSM_A_star_search;
```

<img src="map.png" width="800" height="540" />