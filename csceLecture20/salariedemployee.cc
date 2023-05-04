// Copyright 2023 bhipp
// Implement Salaried Employee class functionality
#include"salariedemployee.h"
#include<iostream>
using std::cout;
using std::endl;
#include<string>
using std::string;
#include"employee.h"

namespace CSCE240_Employees {

SalariedEmployee::SalariedEmployee(string first, string last,
                     string job_title, int pays,
                     double salary) : Employee(first, last, job_title, pays),
                                      annual_salary_(0) {
  SetSalary(salary);
}

  // constructor to take an Employee object and add a salary to create a
  // SalariedEmployee
SalariedEmployee::SalariedEmployee(const Employee& emp, double salary) :
                            Employee(emp), annual_salary_(0) {
  SetSalary(salary);
}

void SalariedEmployee::SetSalary(double salary) {
  if ( salary >= 0 )
    annual_salary_ = salary;
}

// Print
void SalariedEmployee::Print() const {
  Employee::Print();
  cout << "Annual Salary: $" << annual_salary_ << endl;
}

double SalariedEmployee::Pay() const {
  return annual_salary_ / GetPaysPerYear();
}

}  // namespace CSCE240_Employees
