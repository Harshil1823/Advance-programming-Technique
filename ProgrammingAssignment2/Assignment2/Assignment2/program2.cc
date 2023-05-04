// Copyright Harshil 2023
#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include"program2functions.h"

int main() {
  int month, day, year = 0;
  int month2, day2, year2 = 0;
  char slashOne, slashTwo;
  // telling the compiler that this function will be used
  int dayOfYear(int month, int day, int year);
  int numberOfDays(int month, int day, int year,
                    int month2, int day2, int year2);
  // for date 1
  cin >> month >> slashOne >> day >> slashTwo >> year;
  // for date 2
  cin >> month2 >> slashOne >> day2 >> slashTwo >> year2;

  // check if it's a valid date or not
  bool result = ValidDate(month, day, year);
  bool result2 = ValidDate(month2, day2, year2);
  if ( !result || !result2 ) {
    cout << month << slashOne << day << slashTwo << year
         << " is not a valid date" << endl;
    cout << month2 << slashOne << day2 << slashTwo << year2
         << " is not a valid date" << endl;
    return 0;
  }

  int tempDays = 0;
  tempDays = numberOfDays(day, month, year, day2, month2, year2);

  if (tempDays > 0) {
    cout << month << slashOne << day << slashTwo << year
         << " is " << tempDays << " days before " <<
         month2 << slashOne << day2 << slashTwo << year2 << endl;
  } else if ( tempDays == 0 ) {
    cout << month << slashOne << day << slashTwo << year
         << " is " << tempDays << " days before " <<
         month2 << slashOne << day2 << slashTwo << year2 << endl;
  } else if ( tempDays < 0 ) {
    // multiply tempsDays which is negative to positive
    tempDays = tempDays * -1;
    cout << month << slashOne << day << slashTwo << year
         << " is " << tempDays << " days after " <<
         month2 << slashOne << day2 << slashTwo << year2 << endl;
  } else {
    return 0;
  }
}

int numberOfDays(int from_day, int from_month, int from_year,
                    int to_day, int to_month, int to_year) {
    const int days_in_month[] = {0, 31, 28, 31, 30, 31, 30,
                                    31, 31, 30, 31, 30, 31};

    int days = 0;
    for (int year = from_year; year < to_year; ++year) {
        days += 365;
        if ((year % 4 == 0 && year % 100 != 0)
                || year % 400 == 0) {
            ++days;
        }
    }
    for (int month = 1; month < from_month; ++month) {
        days -= days_in_month[month];
        if (month == 2 && ((from_year % 4 == 0 && from_year % 100 != 0)
            || from_year % 400 == 0)) {
            --days;
        }
    }
    for (int month = 1; month < to_month; ++month) {
        days += days_in_month[month];
        if (month == 2 && ((to_year % 4 == 0 && to_year % 100 != 0)
            || to_year % 400 == 0)) {
            ++days;
        }
    }
    days -= (from_day - 1);
    days += (to_day - 1);
    return days;
}
