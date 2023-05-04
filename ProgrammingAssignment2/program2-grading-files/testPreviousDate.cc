// Copyright 2023 bhipp
// runs sample tests for PreviousDate function
#include<iostream>
using std::cout;
using std::endl;
#include "program2functions.h"

int main() {
  int month = 5, day = 7, year = 2024;
  PreviousDate(month, day, year);
  if ( month == 5 && day == 6 && year == 2024 ) {
    cout << "Passed 5/7/2023 to 5/6/2023 test" << endl;
  } else {
    cout << "Failed 5/7/2023 to 5/6/2023  test" << endl;
  }

  month = 3;
  day = 1;
  year = 2024;
  PreviousDate(month, day, year);
  if ( month == 2 && day == 29 && year == 2024 ) {
    cout << "Passed 3/1/2024 to 2/29/2024 test" << endl;
  } else {
    cout << "Failed 3/1/2024 to 2/29/2024  test" << endl;
  }

  month = 1;
  day = 1;
  year = 2028;
  PreviousDate(month, day, year);
  if ( month == 12 && day == 31 && year == 2027 ) {
    cout << "Passed 1/1/2028 to 12/31/2027 test" << endl;
  } else {
    cout << "Failed 1/1/2028 to 12/31/2027 test" << endl;
  }

  month = 12;
  day = 1;
  year = 1999;
  PreviousDate(month, day, year);
  if ( month == 11 && day == 30 && year == 1999 ) {
    cout << "Passed 12/1/1999 to 11/30/1999 test" << endl;
  } else {
    cout << "Failed 12/1/1999 to 11/30/1999 test" << endl;
  }

  month = 6;
  day = 31;
  year = 2018;
  PreviousDate(month, day, year);
  if ( month == 6 && day == 31 && year == 2018 ) {
    cout << "Passed unchanged invalid date test" << endl;
  } else {
    cout << "Failed unchanged invalid date test" << endl;
  }

  return 0;
}
