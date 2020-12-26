#include <iostream>
#include <Eigen/Dense>
extern "C" {
  #include <gsl/gsl_matrix_float.h>
  #include <gsl/gsl_blas.h>
}
using Eigen::MatrixXd;

int main (void)
{
  gsl_matrix_float* input = gsl_matrix_float_alloc(1, 2);
  gsl_matrix_float_set(input, 0, 0, 1);
  gsl_matrix_float_set(input, 0, 1, 2);
  MatrixXd m(2,2);
  m(0,0) = 3;
  m(1,0) = 2.5;
  m(0,1) = -1;
  m(1,1) = m(1,0) + m(0,1);
  //std::cout << m << std::endl;
  return 0;
}