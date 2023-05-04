//Copyright 2023 Harshil
#include"salariedemployee.h"
#include<iostream>
using std::cout;
using std::endl;
#include<string>
using std::string;
#include"employee.h"

namespace CSCE240_Employees {

//constructor to set all data members
SalariedEmployee::SalariedEmployee (string first, string last,
                      string job_title, int pays,
                      double salary) : Employee(first, last, job_title, pays),
                      annual_salary_(0)
{
  SetSalary(salary);
}
  //constructor to take an employee object and add a salaray to create
  // a salaried employee 
SalariedEmployee::SalariedEmployee(const Employee& emp, double salary) :
                            Employee(emp), annual_salary_(0)
{
  SetSalary(salary);
}
//mutator function for annual salaray
void SalariedEmployee::SetSalary(double salary) {
  if (salary >= 0){
    annual_salary_ = salary;
  }
}
//print 
void SalariedEmployee::Print() const {
  Employee::Print();
  cout << "Annual Salaray: $" << annual_salary_ << endl;
}
//pay
double SalariedEmployee::Pay() const{
  return annual_salary_ / GetPaysPerYear();
}

}  // end of namespace