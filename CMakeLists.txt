cmake_minimum_required(VERSION 2.8.11)
project(TestFFTW)

list(APPEND CMAKE_MODULE_PATH ${TestFFTW_SOURCE_DIR}/CMake)

if(${TestFFTW_BINARY_DIR} STREQUAL ${TestFFTW_SOURCE_DIR})
    message(FATAL_ERROR "Source folder should not be be same as build folder!")
endif()

#------------------------------------------------
# Define path for static libraries and excutables
#------------------------------------------------
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY
    ${TestFFTW_BINARY_DIR}/lib
    CACHE PATH "Single output directory for building all libraries.")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY
    ${TestFFTW_BINARY_DIR}/bin
    CACHE PATH "Single output directory for building all executables.")
    
#------------------------------------------------
# Set fftw library for other targets
#------------------------------------------------
add_library(TestFFTW_fftw INTERFACE)

include(FindFFTW)

message(STATUS "The fftw include directories are: ${FFTW_INCLUDE_DIRS}")

message(STATUS "The library is available in directory ${FFTW_DOUBLE_LIB}")
target_link_libraries(TestFFTW_fftw INTERFACE FFTW::Double)

add_subdirectory(src)


