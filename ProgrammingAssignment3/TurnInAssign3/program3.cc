// Copyright 2023 Harshil
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cctype>
#include"program3functions.h"
using std::endl;
using std::cout;

int main(int argc, char *argv[]) {
  findMaxChars(argv[1]);
  cout << endl;
  findMinChars(argv[1]);
  printInOrder(argv[1]);
  arrayWithFrequency(argv[1]);
  cout << endl;
  printBarChart(argv[1]);
  return 0;
}
