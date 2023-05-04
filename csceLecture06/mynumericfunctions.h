// Copyright 2023 bhipp
#ifndef _MYNUMERICFUNCTIONS_H_
#define _MYNUMERICFUNCTIONS_H_

// prototype for a function
// precondition: we expect the argument to be a non-negative int
// postcondition: function returns n!
//                if the argument is negative, the function returns
//                0 and outputs a message to the standard output
//                device
int Factorial(int n);

// function to find the roots of a quadratic using the
// quadratic formula
// Preconditions: function is sent the coefficient of x^2,
//                the coefficient of x and the constant
//                coefficient for a quadratic polynomial
//                followed by two variables to hold the roots
// Postconditions: The function will return true if the quadratic has
//                 root(s) and false if not
//                 if the quadratic has real roots the
//                final two arguments will hold those values
bool QuadraticFormula(double a, double b, double c, double& root1,
                      double& root2);

#endif  //_MYNUMERICFUNCTIONS_H_
