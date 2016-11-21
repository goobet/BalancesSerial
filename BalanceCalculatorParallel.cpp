#include "BalanceCalculatorParallel.h"

void BalanceCalculatorParallel::multiply(double *v, double **m, double *r) {
  int i;
  #pragma omp parallel for private(i) num_threads(2)
  for(i = 0; i < _n; i++) {
    r[i]= 0;
    for(int j = 0; j < _n; j++) {
      r[i] += v[j]*m[j][i];
    }
  }
}