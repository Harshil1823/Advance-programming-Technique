// Copyright 2023 bhipp
// test drive the employee family of classes
#include<iostream>
using std::cout;
using std::endl;
using std::cin;
#include<fstream>
using std::ifstream;
#include"employee.h"
using CSCE240_Employees::Employee;
#include"hourlyemployee.h"
using CSCE240_Employees::HourlyEmployee;
#include"salariedemployee.h"
using CSCE240_Employees::SalariedEmployee;

int main() {
  ifstream infile("someemployees.txt");
  string first, last, jobtitle, emptype;
  int payfrequency, numemployees, i = 0;
  double hourlyrate, hours, salary;
  infile >> numemployees;
  // employee points to a block of pointers to Employees (think dynamically
  // allocated array of pointers)
  Employee * * employees = new Employee * [numemployees];
  do {
    infile >> first >> last >> jobtitle >> payfrequency >> emptype;
    if ( emptype == "hourly" ) {
      infile >> hourlyrate >> hours;
      employees[i] = new HourlyEmployee(first, last, jobtitle, payfrequency,
                                        hourlyrate, hours);
    } else if ( emptype == "salaried" ) {
      infile >> salary;
      employees[i] = new SalariedEmployee(first, last, jobtitle, payfrequency,
                                          salary);
    } /*else {
      employees[i] = new Employee(first, last, jobtitle, payfrequency);
    }*/
  } while ( infile.good() && ++i < numemployees );
  while ( i > 0 ) {
    --i;
    employees[i]->Print();
    cout << "Pay this period: $" << employees[i]->Pay() << endl;
    delete employees[i];
  }
  delete [] employees;
  return 0;
}
