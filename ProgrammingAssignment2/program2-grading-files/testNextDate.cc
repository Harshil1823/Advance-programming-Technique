// Copyright 2023 bhipp
// runs sample tests for NextDate function
#include<iostream>
using std::cout;
using std::endl;
#include "program2functions.h"

int main() {
  int month = 5, day = 7, year = 2024;
  NextDate(month, day, year);
  if ( month == 5 && day == 8 && year == 2024 ) {
    cout << "Passed 5/7/2023 to 5/8/2023 test" << endl;
  } else {
    cout << "Failed 5/7/2023 to 5/8/2023  test" << endl;
  }

  month = 2;
  day = 29;
  year = 2024;
  NextDate(month, day, year);
  if ( month == 3 && day == 1 && year == 2024 ) {
    cout << "Passed 2/29/2024 to 3/1/2024 test" << endl;
  } else {
    cout << "Failed 2/29/2024 to 3/1/2024 test" << endl;
  }

  month = 12;
  day = 30;
  year = 2028;
  NextDate(month, day, year);
  if ( month == 12 && day == 31 && year == 2028 ) {
    cout << "Passed 12/30/2028 to 12/31/2028 test" << endl;
  } else {
    cout << "Failed 12/30/2028 to 12/31/2028 test" << endl;
  }

  month = 8;
  day = 31;
  year = 1999;
  NextDate(month, day, year);
  if ( month == 9 && day == 1 && year == 1999 ) {
    cout << "Passed 8/31/1999 to 9/1/1999 test" << endl;
  } else {
    cout << "Failed 8/31/1999 to 9/1/1999 test" << endl;
  }

  month = 6;
  day = -1;
  year = 2018;
  NextDate(month, day, year);
  if ( month == 6 && day == -1 && year == 2018 ) {
    cout << "Passed unchanged invalid date test" << endl;
  } else {
    cout << "Failed unchanged invalid date test" << endl;
  }

  return 0;
}
