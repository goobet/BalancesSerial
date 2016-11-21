#ifndef BALANCESSERIAL_BALANCECALCULATOR_H
#define BALANCESSERIAL_BALANCECALCULATOR_H
#include "matrix_inverse.h"

class BalanceCalculator {
public:
    double *getT() const;

private:
    double *_T;
    void calculateB();
  void initLocals();
public:
    BalanceCalculator(double **a, double *t, int n);
    BalanceCalculator(char* filename);
    void calculate();
protected:
    int _n;
    double** _a;
    double** _b;
    double** _ema;
    double* _t;
    MatrixInverse _matrix_inverse = 0;
    virtual void multiply(double *v, double **m, double *r);
};


#endif //BALANCESSERIAL_BALANCECALCULATOR_H
