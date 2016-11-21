#include <iostream>
#include "BalanceCalculator.h"
#include "BalanceCalculatorParallel.h"

#include <ctime>

using namespace std;

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

//  char filename[] = "../task.txt.example";
  char filename[] = "/home/dmitriy/big_task.txt";
  BalanceCalculatorParallel balanceCalculator(filename);

  clock_t begin = clock();
  balanceCalculator.calculate();
  clock_t end = clock();
  double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
  std::cout << elapsed_secs << endl;
  double* T = balanceCalculator.getT();

  for(int i = 0; i < 3; i++) {
    std::cout << T[i] << std::endl;
  }

  std::cout << "Done!" << std::endl;
  return 0;
}