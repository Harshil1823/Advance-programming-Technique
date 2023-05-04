#include "set.h"

#include <iostream>

using Project3Problem3::Set;
using std::cout;
using std::endl;

int main() {
  int values1[] = {1, 8, 2, 6, 3};
  int values2[] = {6, 4, 1};
  Set<int> set1(5, values1);
  Set<int> set2(3, values2);
  Set<int> intersection1 = set1.Intersection(set2);
  cout << "Intersection 1: ";
  intersection1.Print();

  char values3[] = {'a', 'c'};
  char values4[] = {'c', 'm', 'l', 't'};
  Set<char> set3(2, values3);
  Set<char> set4(4, values4);
  Set<char> intersection2 = set3.Intersection(set4);
  cout << "Intersection 2: ";
  intersection2.Print();

  double values5[] = {9.8, 2.7};
  double values6[] = {2.7, 4.16, 9.8};
  Set<double> set5(2, values5);
  Set<double> set6(3, values6);
  Set<double> intersection3 = set5.Intersection(set6);
  cout << "Intersection 3: ";
  intersection3.Print();

  int values7[] = {1, 2, 3};
  int values8[] = {2, 1, 3};
  Set<int> set7(3, values7);
  Set<int> set8(3, values8);
  bool equal1 = set7 == set8;
  cout << "Equal 1: " << (equal1 ? "true" : "false") << endl;

  char values9[] = {'a', 'b', 'x'};
  char values10[] = {'x', 'b'};
  Set<char> set9(3, values9);
  Set<char> set10(2, values10);
  bool equal2 = set9 == set10;
  cout << "Equal 2: " << (equal2 ? "true" : "false") << endl;

  char values11[] = {'a', 'b', 'c'};
  char values12[] = {'c', 'a', 'b'};
  Set<char> set11(3, values11);
  Set<char> set12(3, values12);
  bool equal3 = set11 == set12;
  cout << "Equal 3: " << (equal3 ? "true" : "false") << endl;

  return 0;
}