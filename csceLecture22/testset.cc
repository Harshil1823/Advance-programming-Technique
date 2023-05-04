//Copyright 2023 Harshil
#include"set.h"
// IF YOU IMPLEMENT THE MEMBER FUNCTION IN A SOUCRE FILE
// SEPERATED FROM THE HEADER FILE) THEN YOU'LL HAVE TO INCLUDE THE SOURCE FILE 
// WHENEVER THE CLASS IS USED. This will give us a cpplint error that we'll have 
// to ignore.
#include"set.cc"
using namespace csce240_set;

int main () {
  Set<int> s1;
  s1.Print();
  int some_ints[6] = {1, 7, 22, 7, 22, 107};
  s1.SetValues(5, some_ints);
  s1.Print();

  Set<double>s2;
  s2.Print();
  double some_reals[8] = {0.3, 1.4, 6, 9, 12.4, 19.06, 25, 31 };
  s2.SetValues(8, some_reals);
  s2.Print();
  {
    Set<double> s3(s2);
    s3.Print();
  }
  s2.Print();
  Set<int> s4;
  s4 = s1;
  s4.SetValues(6, some_ints);
  s4.Print();
  s1.Print();
  return 0;
}