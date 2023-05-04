// Copyright 2023 Harshil Shah
// Merge function implemented by Harshil Shah
// Print function implemented by bhipp
#include"pointerproblemfunctions.h"
#include<iostream>
using std::cout;
using std::endl;
#include<iomanip>
using std::setw;

// do not modify the implementation of the Print function
void Print(const SortedDynamicArray * nums) {
  for ( int i = 0; i < nums->size; ++i )
    cout << setw(4) << nums->values[i];
  cout << endl;
}

// implement the Merge function (described in pointerproblemfunctions.h) here
void Merge(SortedDynamicArray * const first_array,
    const SortedDynamicArray * const second_array)  {
  // get the sizes of the two arrays
  int size1 = first_array->size;
  int size2 = second_array->size;

  // create a new array to hold the merged values
  int *merged_values = new int[size1 + size2];

  // merge the values into the new array
  int i = 0, j = 0, k = 0;
  while (i < size1 && j < size2) {
    if (first_array->values[i] < second_array->values[j]) {
      merged_values[k++] = first_array->values[i++];
    } else if (second_array->values[j] < first_array->values[i]) {
      merged_values[k++] = second_array->values[j++];
    } else {
      // if the values are equal, only add one of them to the merged array
      merged_values[k++] = first_array->values[i++];
      j++;
    }
  }

  // add any remaining values from the first array
  while (i < size1) {
    merged_values[k++] = first_array->values[i++];
  }

  // add any remaining values from the second array
  while (j < size2) {
    merged_values[k++] = second_array->values[j++];
  }

  // delete the old array and update the
  // first_array to point to the merged array
  delete[] first_array->values;
  first_array->values = merged_values;
  first_array->size = k;
}
