//Copyright 2023 Harshil
// Define the employement class
#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_
#include<string>
using std::string;

namespace CSCE240_Employees{
 class Employee {
 public:
  explicit Employee( string first = "jane", string last = "doe",
                      string job_title = "TBD", int pays = 52);
  void SetFirst(string f);
  void SetLast(string l);
  void SetJobTitle(string title);
  void SetPaysPerYear(int ppy);
  string GetFirst() const {return first_name_;}
  string GetLast() const {return last_name_;} 
  string GetJobTitle() const {return job_title_;}
  int GetPaysPerYear() const {return pays_per_year_;}
  virtual void Print() const;
 private:
   string first_name_;
   string last_name_;
   string job_title_;
   int pays_per_year_;
 };

} //end of namespace

#endif