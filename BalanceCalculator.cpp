//
// Created by dmitriy on 11/21/16.
//

#include "BalanceCalculator.h"

BalanceCalculator::BalanceCalculator(double **a, double *t, int n) {
  _a = a;
  _t = t;
  _n = n;
  _matrix_inverse = MatrixInverse(_n);

  _b = new double*[_n];
  _ema = new double*[_n];
  for(int i = 0; i < _n; i++) {
    _ema[i] = new double[_n];
  }
  for(int i = 0; i < _n; i++) {
    _b[i] = new double[_n];
  }

  _T = new double[_n];
}

void BalanceCalculator::mult(double* v, double** m, double* r) {
  for(int i = 0; i < _n; i++) {
    r[i]= 0;
    for(int j = 0; j < _n; j++) {
      r[i] += v[j]*m[j][i];
    }
  }
}

void BalanceCalculator::calculate() {
  calculateB();
  mult(_t, _b, _T);
}

double *BalanceCalculator::getT() const {
  return _T;
}

void BalanceCalculator::calculateB() {
  for(int i = 0; i < _n; i++) {
    for(int j = 0; j < _n; j++) {
      double g = i == j ? 1 : 0;
      _ema[i][j] = g - _a[i][j];
    }
  }

  _matrix_inverse.calculate(_ema, _b);
}
