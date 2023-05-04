// Copyright 2023 Harshil Shah
// file Io examples
#include<iostream>  // for cin, and cout, and endl
#include<fstream>  // library for file system I/O, (ofstream, ifstream)
using std::ifstream;  // input file stream
using std::ofstream;  // output file stream
using std::endl;
using std::cout;

int main() {

  // opens a file or creates a file for output
  // by default the file will be overwritten
  // std::ofstream::app as the second argument to append
  // (add to the end of file ) if needed
  
  ofstream my_output_file("sample-output.txt"); // std::ofstream::app);
  // the output of file stream object can be used like cout
  my_output_file << "Hello world!" << endl;

  ifstream bingo("bingo.txt");
  char col;
  int num;

  while (bingo.good()) {
    bingo >> col >> num;
    cout << col << "-" << num << endl;
  }
  bingo.close();
  /*
  int x = 0, count = 0, sum = 0;
  ifstream my_input_file("some-numbers.txt");
  while ( my_input_file.good() ) {
    my_input_file >> x;
    sum += x;
    count++;
    cout << x << endl;
  }
  cout << "Average of the values in file is : " 
       << static_cast<double>(sum) / count << endl;
  my_input_file.close();
  */

  //  my_input_file >> x;
  //  cout << x << endl;

  return 0;
}