// Copyright Harshil 2023 
#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<cstdlib> //for srand and rand
#include<ctime> // for time
#include<iomanip> // for setw


int main() {
  const int kRows = 4, kCols = 7;
  int my_big_array[kRows][kCols] = {{1, 2}, {2}, {-4,5}};

  for(int r=0; r < kRows; ++r) {
    for (int c=0; c<kCols; ++c) {
        cout << std::setw(5) << my_big_array[r][c];
    }
    cout << endl;
  }

  for (int i = 0;  i < kRows * kCols; ++i) {
    cout << std::setw(5) << my_big_array[0][i] <<
            ((i + 1) % kCols == 0 ? "\n" : "");
  }
  cout << my_big_array[1][7] << endl;
  return 0;
}


/*
//populate function will fill the array with "random" integers 
void Populate( int n[], int size);
//print function will output the values to the standard output device
void Print ( const int n[], int size);
// insertion sort - N^2 average and worst case sort method with and awsome N best case
void InsertionSort( int n[], int size);
// binarySearch - only works on sorted arrays - returns position of the 
// found value or -1 if the value is not in the array
int BinarySearch (const int n[], int searchValue, int top, int bottom =0);

int main () {
  srand(time(0));
  const int kSize = 15;
  int myArray[kSize] = { 13, 2 , 3};
  Print(myArray, kSize);
  Populate(myArray, kSize);
  Print(myArray, kSize);
  InsertionSort(myArray, kSize);
  Print(myArray, kSize);
  int looking4;
  cout << "what are you looking for? ";
  cin >> looking4;
  cout << BinarySearch(myArray, looking4, kSize-1) << endl;
  return 0;
}

void Print (const int n[], int size) {
  for (int i=0; i < size; ++i) {
    cout << std::setw(5) << n[i];
    cout << endl;
  }
}

void Populate (int n [], int size) {
  for (int i=0; i < size; ++i) {
    n[i] = rand() % 100;  // assign any random value between 
                          // 0 and 100 
  }
}

void InsertionSort( int n [], int size ) {
  for(int sorted=1; sorted < size; ++sorted) {
    int next = sorted; // This is the position of the next item to insert
                       // in the sorted sub-array
    
    // find where this value needs to be added 
    while( n[next] < n[next-1] && next > 0) {
      int temp = n[next-1]; // swap the value with the new one
      n[next-1] = n[next];  // before if it's smaller than the 
      n[next] = temp;       // one before it
      --next;
    }
  }
}

int BinarySearch (const int n[], int searchValue, int top, int bottom) {
  int middle = (bottom + top) / 2;
  if( n[middle] == searchValue) {
    return middle;
  }
  if(top <= bottom) {
    return -1;
  }
  if(n[middle] > searchValue){
    return BinarySearch(n, searchValue, middle-1, bottom);
  }
  return BinarySearch(n, searchValue, top, middle+1);
}
*/
