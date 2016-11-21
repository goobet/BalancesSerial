#include <cstdio>
#include "BalanceCalculator.h"

BalanceCalculator::BalanceCalculator(double **a, double *t, int n) {
  _a = a;
  _t = t;
  _n = n;
  initLocals();
}


void BalanceCalculator::multiply(double *v, double **m, double *r) {
  for(int i = 0; i < _n; i++) {
    r[i]= 0;
    for(int j = 0; j < _n; j++) {
      r[i] += v[j]*m[j][i];
    }
  }
}

void BalanceCalculator::calculate() {
//  calculateB();
  multiply(_t, _a, _T);
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

BalanceCalculator::BalanceCalculator(char *filename) {
  FILE* file = fopen(filename, "r");
  fscanf(file, "%d", &_n);

  _a = new double*[_n];
  for(int i = 0; i < _n; i++) {
    _a[i] = new double[_n];
    for(int j = 0; j < _n; j++) {
      fscanf(file, "%lf", &_a[i][j]);
    }
  }

  _t = new double[_n];
  for(int i = 0; i < _n; i++) {
    fscanf(file, "%lf", &_t[i]);
  }
  fclose(file);
  initLocals();
}

void BalanceCalculator::initLocals() {
  _matrix_inverse = MatrixInverse(_n);

  _b = new double *[_n];
  _ema = new double *[_n];
  for (int i = 0; i < _n; i++) {
    _ema[i] = new double[_n];
  }
  for (int i = 0; i < _n; i++) {
    _b[i] = new double[_n];
  }

  _T = new double[_n];
}