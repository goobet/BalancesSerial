#include "matrix_inverse.h"

// public

MatrixInverse::MatrixInverse(int n)
{
  _n = n;
}

double** MatrixInverse::calculate(double **A, double **Y)
{
  // get the determinant of a
  double det = 1.0/CalcDeterminant(A,_n);

  // memory allocation
  double *temp = new double[(_n-1)*(_n-1)];
  double **minor = new double*[_n-1];
  for(int i=0;i<_n-1;i++)
    minor[i] = temp+(i*(_n-1));

  for(int j=0;j<_n;j++)
  {
    for(int i=0;i<_n;i++)
    {
      // get the co-factor (matrix) of A(j,i)
      GetMinor(A,minor,j,i,_n);
      Y[i][j] = det*CalcDeterminant(minor,_n-1);
      if( (i+j)%2 == 1)
        Y[i][j] = -Y[i][j];
    }
  }

  // release memory
  //delete [] minor[0];
  delete [] temp;
  delete [] minor;

  return Y;
}

// calculate the cofactor of element (row,col)
int MatrixInverse::GetMinor(double **src, double **dest, int row, int col, int _n)
{
  // indicate which col and row is being copied to dest
  int colCount=0,rowCount=0;

  for(int i = 0; i < _n; i++ )
  {
    if( i != row )
    {
      colCount = 0;
      for(int j = 0; j < _n; j++ )
      {
        // when j is not the element
        if( j != col )
        {
          dest[rowCount][colCount] = src[i][j];
          colCount++;
        }
      }
      rowCount++;
    }
  }

  return 1;
}

// Calculate the determinant recursively.
double MatrixInverse::CalcDeterminant( double **mat, int _n)
{
  // _n must be >= 0
  // stop the recursion when matrix is a single element
  if( _n == 1 )
    return mat[0][0];

  // the determinant value
  double det = 0;

  // allocate the cofactor matrix
  double **minor;
  minor = new double*[_n-1];
  for(int i=0;i<_n-1;i++)
    minor[i] = new double[_n-1];

  for(int i = 0; i < _n; i++ )
  {
    // get minor of element (0,i)
    GetMinor( mat, minor, 0, i , _n);
    // the recusion is here!

    det += (i%2==1?-1.0:1.0) * mat[0][i] * CalcDeterminant(minor,_n-1);
    //det += pow( -1.0, i ) * mat[0][i] * CalcDeterminant( minor,_n-1 );
  }

  // release memory
  for(int i=0;i<_n-1;i++)
    delete [] minor[i];
  delete [] minor;

  return det;
}