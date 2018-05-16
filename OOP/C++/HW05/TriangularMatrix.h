#ifndef TRIANGULARMATRIX_H
#define TRIANGULARMATRIX_H
#include <iostream>
using namespace std;

class Matrix
{
public:
  Matrix(int n = 2);
  Matrix(const Matrix &m);
  ~Matrix();
  void readMatrix();
  int size() const;
  const Matrix &operator=(const Matrix &m);

  friend ostream &operator<<(ostream &out, const Matrix &x);
  friend Matrix operator*(double s, const Matrix &rt);

  double operator()(int i, int j) const;

  Matrix &operator+=(const Matrix &m);
  Matrix &operator-=(const Matrix &m);
  Matrix &operator*=(const Matrix &m);

  Matrix operator+(const Matrix &rt);
  Matrix operator-(const Matrix &rt);
  Matrix operator*(const Matrix &rt);
  Matrix operator*(double s);
  Matrix &operator*=(double s);

private:
  bool LorU; //0=lower 1=upper
  double *element;
  int arrSize;
  int matrixSize;
};
#endif