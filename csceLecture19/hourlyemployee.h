//Copyright 2023 Harshil
// Define the HOURLYEMPLOYEE class
#ifndef _HOURLY_EMPLOYEE_H
#define _HOURLY_EMPLOYEE_H
#include<string>
using std::string;
#include"employee.h"

namespace CSCE240_Employees{

class HourlyEmployee : public Employee {
 public:
  explicit HourlyEmployee(string first = "jane", string last = "doe",
                      string job_title = "TBD", int pays = 52, double rate = 7.25,
                      double hrs=0);
  //constructor to take an existing Employee object and create an 
  //hourlyEmployee version
  //NOTE: derived class object is a base class object - implicit casting ok
  //      base class object is not a derived class object - constructor
  //                            below allows us to explicitly cast
  explicit HourlyEmployee(const Employee& emp, double rate=7.25, double hrs=0);
  void SetRate(double r);
  void SetHourWorked(double hrs);
  double GetRate() const {return hourly_rate_;}
  double GetHoursWorked() const {return hours_worked_;}

  // redefine the print function
  //if it's virtual in base class then automatically virutal in derived class
  //stating for the clarity purposes
  virtual void Print() const;
  double Pay() const;

 private:
  double hourly_rate_;
  double hours_worked_;
};


}

#endif