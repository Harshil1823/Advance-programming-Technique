// Copyright 2023 bhipp
// introduction to pointers
#include<iostream>
using std::cout;
using std::endl;
using std::cin;

int main() {
  const int kRows = 4;
  const int kCols = 12;
  // note: this reserves 48 spots, but not all of them are needed
  // we'll modify this to use pointers on Tuesday!
  const char words[kRows][kCols] = { "you", "me", "another", "yet another" };
  for ( int i = 0; i < kRows; ++i ) {
    cout << words[i] << endl;
  }
  return 0; 
}

/*
// double value function as a pointer argument
// void Double(int & num ) {
void Double( int * num ) {
  *num *= 2;
}
// print array function as a pointer argument
// void Print(const int nums[], int size ) {
// as with the array, we aren't going to change the values of the 
// integers the pointer references, so we make this parameter a * 
// to constant ints
void Print( const int * nums, int size ) {
//  *nums = 6;
    for ( int i = 0; i < size; ++i, ++nums )
      cout << *nums << " ";
//  for ( int i = 0; i < size; ++i )
//    cout << nums[i] << " ";
    // cout << *(nums + i) << endl;
  cout << endl;
} 

int main() {
  int x = 6;
  Double(&x);  // to send the address of x to the function, we use the reference
               // operator
  cout << x << endl;
  int nums[5] = {9};
  Print(nums, 5);

/*
  char words[] = "Here's some c-string text";
  cout << words << endl;
  cout << words + 7 << endl;
  int i = 0; 
  while ( words[i] != '\0' )
    cout << words[i++];
  cout << endl;

  char * ptr = words;
  while ( *ptr != '\0' )
    cout << *(ptr++);
  cout << endl;
*/

/*  double number = 17;
  cout << "number = " << number << endl;
  cout << "&number = " << &number << endl;
  double * dptr;  // declared dptr as a pointer to a double 
  dptr = &number;
  cout << "dptr = " << dptr << endl;
  cout << "*dptr = " << *dptr * 2 << endl;
  cout << "&dptr = " << &dptr << endl;
  // can add/subtract and integer and an address to move a fixed number of
  // memory locations away
  cout << "dptr + 4 = " << dptr + 4 << endl;
  // doesn't make sense to multiply an address by an integer
  // cout << "dptr * 4 = " << dptr * 4 << endl;
*/
/*
  return 0;
}
*/


// multi-subscripted arrays as function parameters
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
