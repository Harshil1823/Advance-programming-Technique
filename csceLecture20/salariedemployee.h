// Copyright 2023 bhipp
// Define a Salaried Employee class
#ifndef _SALARIED_EMPLOYEE_H_
#define _SALARIED_EMPLOYEE_H_

#include<string>
using std::string;
#include<iostream>
using std::cout;
using std::endl;
#include"employee.h"

namespace CSCE240_Employees {

class SalariedEmployee : public Employee {
 public:
  // constructor to set all data members
  explicit SalariedEmployee(string first = "Jane", string last = "Doe",
                            string job_title = "TBD", int pays = 52,
                            double salary = 0);
  // constructor to take an Employee object and add a salary to create a
  // SalariedEmployee
  explicit SalariedEmployee(const Employee& emp, double salary = 0);

  virtual ~SalariedEmployee() { cout << "~SalariedEmployee() called on "
                             << GetLast() << endl; }
  // accesssor function for annual_salary
  double GetSalary() const { return annual_salary_; }
  // mutator function for annual_salary
  void SetSalary(double salary);
  // Print
  virtual void Print() const;
  // Pay
  virtual double Pay() const;
 private:
  double annual_salary_;
};

}  // namespace CSCE240_Employees

#endif  // _SALARIED_EMPLOYEE_H_
