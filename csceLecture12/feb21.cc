// Copyright 2023 Harshil
#include<iostream>
using std:: cout;
using std::endl;
using std::cin;
#include<fstream>
using std::ifstream;

int main () {
  // read in major grades for each class we're taking this semester
  int num_classses;
  int major_grades;
  double * * the_grades;
  do {
    cout << "how many classes you taking tatti? ";
    cin >> num_classses;
  } while (num_classses <= 0);
  the_grades = new double * [num_classes]; //create array of that many address

  if ( the_grades == nullptr) {
    //check that the allocation was sucessfull
    cout << "Trouble!!! " << endl;
  }

  for (int i=0; i < num_classses; ++i) {
    do {
        cout << "how maby major grades are there in class" << i + 1 << "?";
        cin >> major_grades;
    } while(major_grades <=0);
    the_grades[i] = new double [major_grades];
    if(the_grades[i] == nullptr) {
        cout << "couldn't reserve " << major_grades << " spots" << endl;
        return 0;
    }
    cout << "enter the " << major_grades << "grade values: ";
    for( int j =0; j < major_grades;+++j) {
        cin >> the_grades[i][j]
    }
  }

  for(int the_class =0; the_class < num_classses; ++the_class) {
    cout << "Grades for class " << the_class << ": ";
  }
}


/*
THIS ONE DOESN'T WORK PROPERLY
 
int main() {
  int size;
  int * ptr;
  do { 
    cout << "how many character do you need? ";
    cin >> size;
  } while ( size <= 0);
  ptr = new char[size]; // dynamically allocates a block of size character 
                        // the address is held in ptr
  if (ptr == nullptr) {
    cout << "couldn't alllocated the request memory ";
    return 0;
  }
  cout << "enter your " << size << " characters ";
  for (int i =0; i < size; ++i) {
    cin >> ptr[i];
  }
  ptr[size] = '\0';
  cout << ptr << endl;

  // whenever we're finished with the dynamically allocated memory, we free
  // it up with the delete
  delete [] ptr; // doesn't delete the pointer, but deletes the memory in adress the ptr holds

  ptr = nullptr;
  cout << "ptr still exists! ";
}
*/

// char *[] or char * *
// first argument is the number of elements of args
// args holds the name of the executable and the additional 
// cstrings following that executable
/*
int main (int numargs, char * args[]) {
  cout << "numargs = " << numargs << endl;
  for(int i=0; i < numargs; ++i) {
    cout << args[i] << endl;
  }
  ifstream inobject(args[1]);
  char next;
  inobject >> next;
  while( inobject.good()) {
    cout << next << endl;
    inobject >> next;
  }
  inobject.close();
  return 0;
}
*/

/*
int main() {
  const int kRows = 4;
 // const int kCols = 12;
  // note: this reserves 48 spots, but not all of them are needed
  // we'll modify this to use pointers on Tuesday!
  // const char words[kRows][kCols] = { "you", "me", "another", "yet another" };
  const char * words[kRows] = {"you", "me", "another", "yet another"};
  for ( int i = 0; i < kRows; ++i ) {
    cout << words[i] << endl;
  }
  return 0; 
}
*/
