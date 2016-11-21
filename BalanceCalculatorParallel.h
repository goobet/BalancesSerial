#ifndef BALANCESSERIAL_BALANCECALCULATORPARALLEL_H
#define BALANCESSERIAL_BALANCECALCULATORPARALLEL_H


#include "BalanceCalculator.h"

class BalanceCalculatorParallel: public BalanceCalculator {
public:
    BalanceCalculatorParallel(double **a, double *t, int n): BalanceCalculator(a, t, n) { }
    BalanceCalculatorParallel(char* filename): BalanceCalculator(filename) { }
protected:
    void multiply(double *v, double **m, double *r);
};


#endif //BALANCESSERIAL_BALANCECALCULATORPARALLEL_H
