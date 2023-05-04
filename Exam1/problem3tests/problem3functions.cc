// Copyright 2023 Harshil
#include<iostream>
using std::cin;
using std::cout;
using std::endl;
#include"problem3functions.h"

int NumDigits(int num) {
  int countDigits = 0;
  if (num == 0) {
    return 1;
  }
  while (num != 0) {
    num = num/10;
    countDigits++;
  }
  return countDigits;
}

bool FindAndReplace(int &x, int find, int replace) {

  int tempFind = NumDigits(find);
  // cout << "tempFind" << tempFind << endl;
  int tempReplace = NumDigits(replace);
  // cout << "tempReplace" << tempFind << endl;

  if (tempFind > tempReplace || find < 0 || replace < 0) {
    return false;
  }
if (tempFind == 1 && tempReplace == 1) {
  int new_number = 0;
  int multiplier = 1;
  int temp_number = x;
  while (temp_number > 0) {
    int digit = temp_number % 10;
    if (digit == find) {
      digit = replace;
    }
    new_number += digit * multiplier;
    multiplier *= 10;
    temp_number /= 10;
  }
  x = new_number;
  return true;
} else if (tempFind == 2 && tempReplace == 2) {
  int new_number1 = 0;
  int multiplier1 = 1;
  int temp_number1 = x;
  while (temp_number1 > 0) {
    int two_digit = temp_number1 % 100;
    if (two_digit == find) {
      two_digit = replace;
    }
    new_number1 += two_digit * multiplier1;
    multiplier1 *= 100;
    temp_number1 /= 100;
  }
  x = new_number1;
  return true;
}
  return false;
}
