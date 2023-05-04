// Copyright 2023 Harshil
// Define polynomial class for polynomial expressions in one variable
// e.g. 3 x^2 + 2 x - 4 
#ifndef _POLYNOMIAL_H_
#define _POLYNOMIAL_H_
#include<iostream>
using std::ostream;

class Polynomial {
  // an opeator is a function with a speical name that is called in a speical way
  // + = <<
  // operator +   opeator=     operator<<
  // x + y  opeator +(x, y)  if the opeator is a standalone function
  //        x.operator + (y) if the opeator is a member function
  // cout << x    since the left opeand is not a polynomial object,
  //              the opeator will not be a member function of our class

  //we'll make the stream insertion opeator a friend of our class to give it
  //access to the private data memebers
  friend ostream& operator << ( ostream& whereto, const Polynomial& p);
 public:
  // recall, we'll make all constructor that can take exactly one argument
  // explicit 
  Polynomial(int degree=0);
  void SetDegree(int degree);

  //assignment opeator will take Polynomial object on the left is, so this  
  //operator can be a member of our class
  // x = y
  //anytime class has a pointer as a data member we need to include the 
  //following: a copy constructor, a destructor, and overloaded assignment operator
  Polynomial& operator = (const Polynomial& rightoperand);
  Polynomial(const Polynomial& tocopy); // copy constructor
  ~Polynomial() {delete [] coefficients_;}

  //let's overload the [] operator to index individual coefficients 
  //polynomial p(3); ;p[3]
  double& operator[](int term); 
  double operator[] (int term) const; // constatnt version that allows constatnt 
                                // objects to view individual coefficients
  static void SetVariable(char var);

  // + takes polynomial object as it's left operand, so we can make this
  // a member of our class
  Polynomial operator + (const Polynomial& rightoperand ) const;
 private:
  static char variable_; // static means there's exactly one of these for the entire class
  int degree_;
  double * coefficients_; // the number of coefficient is 1 more than the
                          // degree of polynomial  
};

#endif