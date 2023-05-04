// Copyright 2023 Harshil Shah
#include<iostream>
using std::cout;
using std::endl;
using std::cin;
#include<iomanip>
#include<cmath>  // contains a lot of mathetmatical functions
                // like double (double base, double exponent)
                // double sqrt(double)
                // ceil(double) - rounding up
                // floor(double) - not rounding and throwing away decimal part
#include"myfunctions.h"  // i can now include this header file
                        //  in any C++ file that needs to use 
                        // one of the functions i've written in it

// write our own function to round to the nearest integer
// int RoundToInteger ( double num );  // function prototype - let the complier know that this funciton exists 

int main () {
  cout << pow ( 2, 7 ) << endl;
  cout << sqrt( 5 ) << endl;
  cout << ceil ( 2.4 ) << endl;  // display 3
  cout << floor ( 2.4 ) << endl;  // will display 2
  double x;
  cout << "enter a real number";
  cin >> x;
  cout << RoundToInteger(x) << endl;
  return 0;
}

    /*
    int RoundToInteger( double num ) {
        return floor( num + 0.5);
    }
    */
/*
int main () {
  double x;
  cout << "enter a real number ";
  cin >> x;
  cout << x << endl;
  cout << std::setprecision(3);
  cout << x << endl;
  cout << std::setiosflags( std::ios::showpoint |
            std::ios::fixed ) << x << endl;
  cout << std::setw(8) << x << endl;
  double y = 12.6;
  cout << std::setw(8) << y << endl;
  cout << x << endl;
  return 0;
}
*/
