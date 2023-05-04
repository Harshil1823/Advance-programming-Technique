// copyright 2023 Harshil
// intorudciotn to arrays in C++
#include<iostream>
using std::cout;
using std::endl;
using std::cin;
#include<iomanip>
using std::setw;
using std::setiosflags;

// write a print function for an array of doubles
void PrintArray( const double numbers[], int size )
{
    // const won't allow the array to be modified
    cout << setiosflags ( std::ios::fixed | std::ios::showpoint );
    for (int i=0; i < size; i++) {
        cout << setw(10) << numbers[i];
    }
    cout << endl;
}
// Linear search
// return type
int LinearSearch ( const double numbers[], size, double search_value) {
    int found_position = -1, i = 0;
    while (found_position == -1 && i < size) {
        found_position = (numbers[i] == search_value ? i : -1);
    }
    return found_position;
}

int main () {
    const int kArraySize = 5; // google style guide - begins a constant 
                                // variable names with a k
    const double fixed_value[2] = {3.14, 2.718};
    PrintArray(fixed_value, 2); // if the printarray funciotn doesn't have 
                                 //  a const on the array paramter 
                                // we won't e able to send it a const array

    // can declare and initialize in a single statement, if there are 
    // fewer values in the list than the size, the remaining values
    // will be set to 0 (for an int, float, or double array)
    double some_doubles[kArraySize] = {1.2, 3.7, };
    for ( int j =0; j < kArraySize; ++j) {
        some_doubles[j] *= 3;
    }
    PrintArray( some_doubles, kArraySize);

    /*
    for (int i = 0; i < kArraySize; ++i) {
        cout << "some_doubles[" << i << "] = " << some_doubles[i] << " ";
        cout << endl;
        cout << some_doubles << endl; // starting block of the array
        cout << some_doubles +  1 << endl; // adding an interger to a memory 
        // location adds the int * size of what the memory location holds
    }
    */

    // a character array, c-string
    // leaving the [] empty is the same as [5] in this example - an 
    // exact fit to the initialized values
    char word [] = "word";  // same as {'w', 'o', 'r', 'd', '\o'}
                            // '\o' that's a null character
    word[4] = '!';
    cout << word << endl;
    // Line above is the same as the for loop 
    // it prints the values rather than the address which can be useful
    // loop example below does the same thing
    int k = 0;
    while (word[k] != '\0') {
        cout << word[k++];
    } 
    cout << endl;
    
    // NEVER DO THE THING BELOW
    // if input is longer than the array, it will overstep the array bounds
    cout << "enter a new word ";
    cin >> word;
    cout << "The character array world now holds " << word << endl;


    return 0;
}