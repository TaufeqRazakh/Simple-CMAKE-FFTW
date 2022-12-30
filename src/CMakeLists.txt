add_executable(fftw-test fftw_test.cpp)
add_executable(fftw-test3 fftw_test3.cpp)

target_link_libraries(fftw-test LINK_PUBLIC TestFFTW_fftw)
target_link_libraries(fftw-test3 LINK_PUBLIC FFTW::Double)
