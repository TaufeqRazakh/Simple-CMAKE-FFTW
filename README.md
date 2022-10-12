# Simple CMake + FFTW
This project is used to build a simple application to test FFTW using CMake build system. 

This repository has benefitted by two openly available contributions

+ C [source code](https://people.sc.fsu.edu/~jburkardt/c_src/fftw_test/fftw_test.html) for FFTW test made available by John Burkardt.
+ CMake [module](https://github.com/egpbos/findFFTW) to find FFTW by Patrick Bos and contributors.


## Requirements
+ gcc 11 or higher
+ cmake 2.8.11 or higher
+ fftw

## How to build
Since we are trying to build this project with CMake there are some aspects which need special attention:
+ Build the final executable in a directory other than the source directory.
+ Specify the compiler as a CMake option. This is done by specifying the compiler to the `CMAKE_C_COMPILER` option. 
+ Find the final executable in the `bin/` directory after finishig the final build command.

## Discovery Take-off
The following commands will quickly set you up to running/testing on USC's [Discovery](https://www.carc.usc.edu/user-information/user-guides/hpc-basics/discovery-resources)
```
salloc -N 1 -p debug
module purge
module load gcc/11.3.0
module load mvapich2
module load cmake
module load fftw
mkdir build
cd build
cmake -DCMAKE_C_COMPILER=gcc ..
make
cd bin
./fftw-test
```

## Steps to follow for rapid development and testing
+ Go ahead make changes to your source file.
+ Then go back to your build directory and use `make` to replace the executable with a fresh one.
+ Resume  testing executable in `bin/` directory.
