// copyright 2023 Harshil Shah
#include<iostream>
using std:: cout;
using std:: endl;
using std:: cin; // object for accepting input from the standard keyboard
#include<cstdlib> // rand, srand
#include<ctime>

// function to return a random number between 1 and 6
// function prototype;
// int dice();

//function implementation
int dice(){
    return rand() % 6 + 1;
}

int main(){
// cout << sizeof(long) << endl;
  srand( time(0) ); // seed the random function with the current time in order to get a different list of values
                    //each time the program runs
  for( int k =1; k < 10; ++k){
    cout << dice() << endl;
  }
  int stopping_point;
  do{
    cout << "Enter a positive integer.";
    cin >> stopping_point;
  } while ( stopping_point < 1 );
  
  int i = 1;
  while(i <= stopping_point){
    cout << i++ << "\n";
    // i = i + 1; // i +=1; ++i; i++;
  }
  for(int j = 1; j <= stopping_point; ++j ){
    cout << j << "\n";
  }
  cout << "at the end of the main i = " << i;
  //j is not visible outside the for loop (scope varaible)
  // cout << " and j = " << j << endl;
  return 0;
}
