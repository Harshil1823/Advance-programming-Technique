//Copyright 2023 Harshil
// testDrive the Rectangle class
#include<iostream>
using std::cout;
using std::endl;
#include"square.h"
using namespace csce240_shapes;

void PrintSquare(const Square& s) {
  for(int i=0; i < s.GetLength(); ++i){
    cout << "*";
  }
  for(int i = 0; i < s.GetLength() - 2 ; ++i) {
    cout << "\n*";
    for(int j=0; j < s.GetLength() - 2; ++j) {
      cout << " ";
    }
    cout << "*\n";
  }
  for(int i=0; i < s.GetLength(); ++i){
    cout << "*";
  }
}

int main () {
  Rectangle r;
  cout << r << endl;
  r.SetWidth(4.2);
  cout << r << endl;
  Square s(5);  //calls the sqaure constructor - Rectangle constructor
              // executes before the body of the square constructor 
  cout << s << endl;
  s.SetWidth(3);
  cout << s << endl;
  PrintSquare(s);
  PrintSquare(Square(7));
  // PrintSquare(7);   - can't do this cuz we explicitly tell constructor to take object as a pram
  //                      no int would work
  // you can cast this and make it work. look at the code below.
  // PrintSquare(Square(7));
  return 0;
}