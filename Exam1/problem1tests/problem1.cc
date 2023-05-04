// Copyright 2024 Harshil
#include<iostream>  // for cin, and cout, and endl
using std::endl;
using std::cout;
using std::cin;

int main() {
  int alphabetCount = 0, digitalNumber = 0;
  char c;
  // let's read the sentence from the file now
  // read until it has next char
  while (cin.get(c)) {
    // break away if you reach the end of the sentence
    // end of the sentence's would've have been reached
    // if it ends in the following
    if (c == '.' || c == '?' || c == '!') {
        break;
    }
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
      alphabetCount++;
    } else if (c >= '0' && c <= '9') {
      digitalNumber++;
    }
  }
  if (alphabetCount == 1) {
    cout << "Input sentence contains " << alphabetCount
        << " alphabetic character"
        << " and " << digitalNumber << " digits." << endl;
  } else if (alphabetCount > 1) {
    cout << "Input sentence contains " << alphabetCount
        << " alphabetic characters"
        << " and " << digitalNumber << " digits." << endl;
  }
  return 0;
}
