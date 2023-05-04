// Copyright 2023 Harshil Shah
// implement the functions in program2functions.h header file
#include"program2functions.h"
#include<iostream>
using std::cout;
using std::endl;

bool LeapYear(int year) {
  if ( year % 400 == 0 || (year % 4 == 0 && year % 100 != 0) ) {
    return true;
  } else {
    return false;
  }
}

int LastDayOfMonth(int month, int year) {
  // which months have 31 days
  // Jan, March, May, July, August, October, December
  if ( month == 1 ||
      month == 3 ||
      month == 5 ||
      month == 7 ||
      month == 8 ||
      month == 10 || month == 12) {
        return 31;
  } else if ( month == 4 || month == 6 ||
              month == 9 || month == 11  ) {
        return 30;
  } else if (month == 2) {
    // return 0 if it's not a valid year
      if (year <= 0) {
        return 0;
      } else if (year % 400 == 0 || (year % 4 == 0 &&
                year % 100 != 0) ) {
        return 29;  // because this is leap year
      } else {
        return 28;  // regular feb not a leap year
      }
  } else {
    return 0;  // not a valid month
  }
}  // end of the method

bool ValidDate(int month, int day, int year) {
  if (year <= 0) {
    return false;
  }
  // check if the month is valid
  if ( month >= 1 && month <= 12 ) {
    if ( month == 1 ||
      month == 3 ||
      month == 5 ||
      month == 7 ||
      month == 8 ||
      month == 10 || month == 12) {
        if (day >= 1 && day <= 31) {
            return true;
        } else {
            return false;
        }
    } else if ( month == 4 || month == 6 ||
              month == 9 || month == 11 ) {
        if ( day >= 1 && day <= 30 ) {
            return true;
        } else {
            return false;
        }
    } else if ( month == 2 ) {
        // check if it's leap year and print accordingly
        if (year % 400 == 0 || (year % 4 == 0 &&
                    year % 100 != 0)) {
            if (day >= 1 && day <= 29) {
                return true;  // leap year
            } else {
                return false;
            }
        } else {
            if (day >= 1 && day <= 28) {
                return true;
            } else {
                return false;
            }
      }
    }
  }
// if not a valid month then default returns false
    return false;
}

void NextDate(int &month, int &day, int &year) {
  int numOfDaysinMonth = 0;
  // check if it's valid number of days in a month
  if ( month >= 1 && month <= 12 ) {
    if ( month == 1 ||
      month == 3 ||
      month == 5 ||
      month == 7 ||
      month == 8 ||
      month == 10 || month == 12) {
        if (day >= 1 && day <= 31) {
            numOfDaysinMonth = 31;
        }
    } else if ( month == 4 || month == 6 ||
              month == 9 || month == 11 ) {
        if ( day >= 1 && day <= 30 ) {
            numOfDaysinMonth = 30;
        }
    } else if ( month == 2 ) {
        // check if it's leap year and print accordingly
        if (year % 400 == 0 || (year % 4 == 0 &&
                    year % 100 != 0)) {
            if (day >= 1 && day <= 29) {  // leap year
                numOfDaysinMonth = 29;
        } else {
            if (day >= 1 && day <= 28) {
                numOfDaysinMonth = 28;
            }
            }
        }
    }
  }
  // error checking
  if (day > numOfDaysinMonth) {
    // this has to be false
    // ex: 6th month of year can't have 31 days hence false
    return;
  }
  // done assigning numOfDayInMonth
  if ( day < numOfDaysinMonth ) {
    day++;
  } else {
    // reset day if it's the last day
    day = 1;
    if ( month < 12 ) {
        month++;
    } else {
    // reset the month if it's december
    // reset it to jan
        month = 1;
        year++;
    }
  }
}

void PreviousDate(int &month, int&day, int &year) {
  // check if it's a validtestDate;
  bool result = ValidDate(month, day, year);
  if ( !result ) {
    return;
  }
  int numOfDaysinMonth;
  // for jan
  if (month == 1) {
  // check if day is > 1, if it's not then go do month--
    if (day > 1) {
        day--;
    } else {
        month = 12;
        year--;
        // set day to Dec31
        day = 31;
    }
  } else if (month == 2) {
    // check if it's leap year
    if ( year % 400 == 0 || (year % 4 == 0 && year % 100 != 0) ) {
        numOfDaysinMonth = 29;  // leapyear
    } else {
        numOfDaysinMonth = 28;  // not a leap year
    }
      if (day > 1) {
        day--;
    } else {
        // current month is feb decrement to jan
        month = 1;
        day = 31;
    }
  } else if ( month == 3 || month == 5 ||
              month == 7 || month == 8 ||
              month == 10 || month == 12) {
        // FOR ALL THE MONTHS WITH 31 DAYS
        if (day > 1) {
            day--;
        } else {
            // goes to the prev month which has 30 days
            month--;
            // what if we are decrementing and it's leap year or not
            // gotta check that
            if (month == 2) {
                 if ( year % 400 == 0 || (year % 4 == 0 && year % 100 != 0) ) {
                    numOfDaysinMonth = 29;  // leapyear
                } else {
                    numOfDaysinMonth = 28;
                }
            day = numOfDaysinMonth;
            }
        }
  } else if ( month == 4 || month == 6 ||
              month == 9 || month == 11) {
        numOfDaysinMonth = 30;
        if (day > 1) {
            day--;
        } else {
            month--;
            day = 31;  // prev month has 31 days
        }
  } else {
    return;
  }
}  // end of method
