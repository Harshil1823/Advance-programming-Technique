// Copyright 2023 Harshil Shah
#include<iostream>
using std:: cout;
using std:: endl;

int main() {
  cout << "I said, \"hello world\"\n";  // c strings
  cout << "what's up?" << endl;

  int x, y, z;  // declaring three interger variables
  x = y = z = 12;
  const int kConstant = 1;
  // cout << "x = " << x << "\ny = " << y << "\nz = " << z << endl;
  x = y = z = 13;
  cout << "x = " << x << "\ny = " << y << "\nz = " << z << endl;
  return 0;
}

// g++ -std=c++17 -Wall [fileName]
// -std=c++17
// -Wall option shows the warnings
// -o option can help you rename a file look below
// g++ -std=c++17 -wall [fileName] -o [newFileName]
// cpplint gives information about how you style sucks

