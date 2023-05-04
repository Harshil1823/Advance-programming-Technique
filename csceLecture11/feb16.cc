// Copyright 2023 Harshil Shah
// multi-subscripted arrays as function as paramters
// introduction to pointers
#include<iostream>
using std::cout;
using std::cin;
using std::endl;

//double value function as a argument
//void Double(int &num) {
void Double (int * num) {  // accepts a adress
  *num *= 2;  // de reference
}

// print array function as a pointer argument
//void print(const int nums [], int size) {

// as with the array we aren't going to change the values of the 
// integer the pointer references so we make this paramter a * constant 
// to constant ints
void Print (const int * nums, int size) {
  for(int i=0; i<size;++i) {
    cout << nums[i] << " ";
    // same as --> cout << *(nums + i) << endl;
  }
  cout << endl;
}
int main() {
  int x = 6;
  Double(&x);  // to send the address of x to the function we use a refrence operator
  cout << x << endl;
  int num[5] = {9};
  Print(num, 5);
}


/*
int main () {
  char words[] = "Here's some c-string text";
  cout << words << endl;
  cout << words + 7 << endl;
  int i = 0;
  while (words[i] != '\0') {
    cout << words[i++];
  }
  cout << endl;

  char *ptr = words;
  while( *ptr != '\0') {
    cout << *(ptr++);
  }
  


  return 0;
}
*/

/*
int main() {
  double number = 17;
  cout << "number= " << number << endl;
  cout << "&number = " << &number << endl;
  double * dptr; // declared dpointer as a pointer to a double
  dptr = &number; // assign pointer the address of number
  cout << "dptr = " << dptr << endl;
  cout << "*dptr = " << *dptr << endl; // dereference 
  cout << "&dptr = " << &dptr << endl;
  // can add/subtract and integer and an adress to move fixed number of 
  // memory location away
  cout << "dptr + 4 = " << dptr + 4 << endl;
  //doesn't make sense to multiply an adress by integer
  //   cout << "dptr * 4 = " << dptr * 4 << endl;
  return 0;
}
*/


/*
const int kCols = 6;  // file scope global variable - avoid these whenever
                      // possible. Needed here for use by multiple functions
                      // in this file

// for mult-subscripted array parameters, first [] is empty
// all of the rest must have a constant int
void PrintDoubleSubscriptedArray(const double big_array[][kCols], int rows) {
  for ( int i = 0; i < rows; ++ i ) {
    for ( int j = 0; j < kCols; ++j ) {
      cout << big_array[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {
  const int kRows = 4;
  double some_numbers[kRows][kCols] = { {4, 2.3}, {-1.2} };
  PrintDoubleSubscriptedArray(some_numbers, kRows);
  return 0;
}
*/