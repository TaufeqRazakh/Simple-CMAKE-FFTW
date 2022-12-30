add_executable(fftw-test fftw_test.cpp)

target_link_libraries(fftw-test LINK_PUBLIC TestFFTW_fftw)
