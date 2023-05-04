//Copyright 2023 Harshil
#include"polynomial.h"
#include<iostream>
using std::cout;
using std::endl;

//we initialize the static data members on the class not in a constructor
char Polynomial::variable_ = 'x';


void Polynomial::SetVariable(char var) {
  if ( var >= 'a' && var <= 'z') {
    variable_ = var;
  }
}

Polynomial Polynomial::operator+ (const Polynomial& rightoperand) const {
  int maxdegree = ( degree_ >= rightoperand.degree_ ? degree_ 
                                                        : rightoperand.degree_ );
  Polynomial result (maxdegree);
  for ( int i = 0; i <= maxdegree; ++i) {
    if (i > degree_) {
      result[i] = rightoperand[i];
    } else if (i > rightoperand.degree_) {
      result[i] = (*this)[i];
    } else {
      result[i] = (*this)[i] + rightoperand[i];
    }
  }
  return result;
}

double& Polynomial::operator[] (int term) {
  //we can desgin this different ways but. The key is to ensure that we stay in bounds.
  if (term < 0) {
    term = 0;
  }
  //if setting a coefficient that's larger than the degreee
  //let's increase the degree of polynomial to fit
  if (term > degree_) {
    double * newCoefficients = new double [term + 1];
    //copy over the old coefficients
    for (int i=0; i <= degree_; ++i) {
      newCoefficients[i] = coefficients_[i];
    }
    // place 0s in the new spots larger than degree_
    for (int j= degree_ + 1; j<= term; ++j) {
      newCoefficients[j] = 0;
    }
    delete [] coefficients_;
    coefficients_ = newCoefficients;
    degree_ = term;

    term = degree_;
  }
  return coefficients_[term];
}

double Polynomial::operator[] (int term) const {
  //we can desgin this different ways but. The key is to ensure that we stay in bounds.
  if (term < 0) {
    term = 0;
  }
  if (term > degree_){
//    term = degree_;
      return 0;
  }
  return coefficients_[term];
}

Polynomial::Polynomial(const Polynomial& tocopy) {
  degree_ = tocopy.degree_;
  coefficients_ = new double [degree_ + 1];
  for ( int i = 0; i <= degree_; ++i) {
    coefficients_[i] = tocopy.coefficients_[i];
  }
}

Polynomial& Polynomial::operator = (const Polynomial& rightoperand ) {
  if ( degree_ != rightoperand.degree_) {
    degree_ = rightoperand.degree_;
    delete[] coefficients_;
    coefficients_ = new double [ degree_ + 1];
  }
  for ( int i = 0; i <= degree_; ++i) {
    coefficients_[i] = rightoperand.coefficients_[i];
  }
  //return the value of the object that was just updated
  // this pointer = holds the address of the object
  return *this;
}

//Freind is keybaord is only used in the header file
ostream& operator << ( ostream& wherto, const Polynomial& p) {
  //friendship allows this non-memeber  function to directly access degree_
  // and coefficients_
  for ( int i = p.degree_; i >= 0; --i) {
    if(p.coefficients_[i] != 0) {
      wherto << p.coefficients_[i] << p.variable_ << "^" << i << (i > 0 ? "+" : "");
    }
  }
  return wherto;
}



// member initializer list
Polynomial::Polynomial(int degree) : degree_(0), coefficients_(nullptr) {
  if (degree >= 0) {
    degree_ = degree;
  }
  // dynamically allocate a block of degree_ +1 double to hold the values
  // of our polynomial's coefficients
  coefficients_ = new double[degree_ + 1];
  //backwards compatibility for old compilers
  if( coefficients_ == nullptr) {
    cout << "couldn't allocate requested memory" << endl;
    exit(1);
  }
  // initalizing all of the coefficients to 1 by default
  for ( int i = degree_; i >= 0; --i ) {
    coefficients_[i] = 1;
  }
}
// this function is called on existing object, so if we have to reallocate
// memory, we need to make sure we deallocate (release) previosuly allocated
// memory to avoid a memory leak
void Polynomial::SetDegree(int degree) {
  if (degree == degree_ || degree < 0) {
    return;
  } else {
    degree_ = degree;
    delete [] coefficients_; // free up the preiovuslt dynamically allocated memory
    //backwards compatibility o
    if( coefficients_ == nullptr) {
      cout << "couldn't allocate requested memory" << endl;
      exit(1);
    }
  // initalizing all of the coefficients to 1 by default
    for ( int i = degree_; i >= 0; --i ) {
      coefficients_[i] = 1;
    }
  }
}