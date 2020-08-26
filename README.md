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

Run all tests:
```bash
cd build
ctest -j8 # test with 8 thrads
```

Test a specific project
```bash
cd build
ctest -R <project_name>
```
