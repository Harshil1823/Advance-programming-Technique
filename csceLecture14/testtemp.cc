// copyright 2023 Harshil
#include"temperature.h"
#include<iostream>
using std::cout;
using std::cin;
using std::endl;
int main () {
  // NOTE: to call the default constructor, don't put parenthesis after
  //        the object name - if you do, the complier think you're defining
  //        a new funciton!
  Temperature t; // instantiate an object of the Temperature class
  // Don't put Temperature t(); 
  cout << t.GetValue() << " " << t.GetUnits() << endl;
  t.SetValue(72);
  t.SetUnits("Fahrenheit");
  cout << t.GetValue() << " " << t.GetUnits() << endl;
  // to call constructor with initial values, send in parenthesis
  Temperature t2(60), t3(80, "Fahrenheit");
  cout << t2.GetValue() << " " << t2.GetUnits() << endl;
  t3 = t; // if we don't overload the assigmnet operator, = will perform
          // a memberwise copy (if we have pointers as data members, this 
          // would be bad!!!!)
  cout << t3.GetValue() << " " << t3.GetUnits() << endl;
  return 0;
}