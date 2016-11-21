class MatrixInverse
{
private:
    int _n;

    int GetMinor(double **src, double **dest, int row, int col, int order);
    double CalcDeterminant( double **mat, int order);
public:
    MatrixInverse(int n);

    double** calculate(double **A, double **Y);
};