#ifndef BALANCESSERIAL_BALANCECALCULATOR_H
#define BALANCESSERIAL_BALANCECALCULATOR_H
#include "matrix_inverse.h"

class BalanceCalculator {
private:
    double** _a;
    double** _b;
    double** _ema;
    double* _t;
    int _n;
    MatrixInverse _matrix_inverse = 0;
public:
    double *getT() const;

private:
    double *_T;
    void calculateB();
public:
    BalanceCalculator(double **a, double *t, int n);
    void calculate();
protected:
    void mult(double* v, double** m, double* r);
};


#endif //BALANCESSERIAL_BALANCECALCULATOR_H
