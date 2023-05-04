// Copyright 2023 bhipp
// tests the LeapYear function in #include<iostream>
#include<iostream>
using std::cout;
using std::endl;
#include "program2functions.h"

int main() {
  if ( !LeapYear(2021) )
    cout << "Passed non-leap year test" << endl;
  else
    cout << "Failed non-leap year test" << endl;

  if ( LeapYear(2016) )
    cout << "Passed 4-year leap year test" << endl;
  else
    cout << "Failed 4-year leap year test" << endl;

  if ( !LeapYear(2100) )
    cout << "Passed 100 year non-leap year test" << endl;
  else
    cout << "Failed 100 year non-leap year test" << endl;

  if ( LeapYear(2400) )
    cout << "Passed 400 year leap year test" << endl;
  else
    cout << "Failed 400 year leap year test" << endl;

  return 0;
}
