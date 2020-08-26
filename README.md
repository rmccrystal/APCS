# APCS
A collection of all of my projects for AP Computer Science

## Compiling using CMake
```bash
mkdir build
cd build
cmake ..
make (project name)
```

## Automated testing using `check50`
Note: you need to compile using the commands above before you test
```bash
cd build
ctest -j8
```