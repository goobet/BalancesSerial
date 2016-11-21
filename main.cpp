#include <iostream>
#include "BalanceCalculator.h"

int main() {
  int n = 3;

  double** a = new double*[3];
  a[0] = new double[3];
  a[1] = new double[3];
  a[2] = new double[3];

  // 0.1 0.2 0.3
  // 0.3 0.4 0.2
  // 0.5 0.1 0.3

  a[0][0] = 0.1; a[0][1] = 0.2;  a[0][2] = 0.3;
  a[1][0] = 0.3; a[1][1] = 0.4;  a[1][2] = 0.2;
  a[2][0] = 0.5; a[2][1] = 0.1;  a[2][2] = 0.3;

  double* t = new double[n];
  // 1.2 1.4 1.9
  t[0] = 1.2;
  t[1] = 1.4;
  t[2] = 1.9;

  BalanceCalculator balanceCalculator(a, t, n);

  balanceCalculator.calculate();

  double* T = balanceCalculator.getT();

  for(int i = 0; i < 3; i++) {
    std::cout << T[i] << std::endl;
  }

  std::cout << "Done!" << std::endl;
  return 0;
}