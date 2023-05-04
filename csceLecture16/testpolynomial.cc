//Copyright 2023 Harshil
// test drive the functionality of the Polynomial Class
#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include"polynomial.h"

int main () {
   Polynomial::SetVariable('r'); // can call static functions without having 
                                 // an object
   Polynomial p1(5), p2(3);
   p1[8] = 7;
   cout << p1 << "\n" << p2 << endl;
   p1.SetVariable('z'); // this is changing static that belongs to the entire class
   cout << p1 << "\n" << p2 << endl;
   cout << p2[10] << endl;
   cout << p1 + p2 << endl;
 //  Polynomial p1(2), p2(5);
 //  cout << p1[0] << endl;
 //  cout << p2[10] << endl;
 //  p1[2] = 1;
 //  p1[1] = 3;
 //  p1[0] = 6;
 //  p1[8] = 11;
  //  cout << p1 << endl;
  //  cout << p2[10] << endl;
 /*   cout << p1 << "\n" << p2 << endl;
    p1.SetDegree(3);
    p2 = p1; // if we don't overload this ourselves - this will do a member-wise
             // copy of the data members
             // when we have a pointer as a data member, we need to overload
             // the operator to ensure that two object's data memebers don't
             // point to the same location
   // Polynomial p3 = p2; // for the same reason, we need to write a copy constructor
    cout << p1 << endl;
    cout << p2 << endl;
    p1.SetDegree(5);
    cout << p1 << endl;
    cout << p2 << endl;
*/
    return 0;
}