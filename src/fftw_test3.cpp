#include <complex>
#include <vector>
#include "fftw3.h"

#define NX 32
#define NY 32
#define NZ 32

int main()
{
  std::vector<std::complex<float>> in, out;

  fftw_plan p;

  in.resize(NX*NY*NZ);
  out.resize(NX*NY*NZ);

  auto* in_ptr = in.data();
  auto* out_ptr = out.data();

  p = fftw_plan_dft_3d(NZ, NY, NX, reinterpret_cast<fftw_complex*>(in_ptr), 
		       reinterpret_cast<fftw_complex*>(out_ptr), FFTW_FORWARD, FFTW_ESTIMATE);
  //for (int i=0; i<NX*NY*NZ; i++) in[i] = {0.0, 0.0};

  fftw_execute(p);
  fftw_destroy_plan(p);

  return 0;
}
