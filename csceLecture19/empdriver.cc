//Copyright 2023 Harshil
// test drive the employee family of classes
#include"employee.h"
using CSCE240_Employees::Employee;
#include"hourlyemployee.h"
using CSCE240_Employees::HourlyEmployee;
#include"salariedemployee.h"
using CSCE240_Employees::SalariedEmployee;
#include<iostream>
using std::cout;
using std::endl;
using std::cin;

int main() {

/*  Employee just_an_employee("Q", "U");
  just_an_employee.Print();
  HourlyEmployee hourly(just_an_employee, 15, 40);
  hourly.Print();

  HourlyEmployee edefault, einitialized ("john", "Smith", "Porgrammer", 12);
  edefault.Print();
  einitialized.Print();

  SalariedEmployee sal1(just_an_employee), sal2("A", "jones", "CEO", 24, 300000);
  sal1.Print();
  sal2.Print();
*/
  Employee * epointer;
  Employee e("BOB", "Dailder", "contractor");
  HourlyEmployee he("Thomas", "Train", "transporter worker", 52, 12, 60);
  SalariedEmployee se("Oscar", "Grounch", "sanitation", 125000);
  int which;
  cout << "Enter 1 for employee, 2 for hourly employee, 3 for salaried employee";
  cin >> which;
  switch(which) {
    case 1:
      epointer = &e;
      break;
    case 2:
      epointer = &he;  // it's okay to have a base class pointer point to be a derived 
                      // class object - a derived class object is a base class 
                      // object 
      break;
    default:
      epointer = &se;
  }
  //called the arrow operator
  epointer->Print();
  return 0;
}