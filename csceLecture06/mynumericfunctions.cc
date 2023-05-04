// Copyright 2023 bhipp
// implement the functions in mynumericfunctions header file
#include"mynumericfunctions.h"
#include<iostream>
using std::cout;
using std::endl;
#include<cmath>

int Factorial(int n) {
  int total = 1;
  if ( n < 0 ) {
    cout << "Factorial is not defined for negative integers" << endl;
    total = 0;
  }
  for ( int i = 2; i <= n; ++i )
    total *= i;
  return total;
}

bool QuadraticFormula(double a, double b, double c, double& root1,
                      double& root2) {
  double discriminant = b * b - 4 * a * c;
  if ( discriminant < 0 )
    return false;
  root1 = (-1 * b + sqrt(discriminant)) / (2 * a);
  root2 = (-1 * b - sqrt(discriminant)) / (2 * a);
  return true;
}
