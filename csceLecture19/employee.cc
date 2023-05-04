//Copyright 2023 Harshil
#include"employee.h"
#include<iostream>
#include<string>
using std::string;
using std::cout;
using std::endl;

namespace CSCE240_Employees {

void Employee::SetFirst(string f) {
  if (f.length() > 0)  {
    first_name_ = f;
  }
}

void Employee::SetLast(string l) {
  if(l.length() > 0){
    last_name_ = l;
  }
}

void Employee::SetJobTitle(string title){
  if(title.length() > 0) {
    job_title_ = title;
  }
}

void Employee::SetPaysPerYear(int ppy) {
  if(ppy == 365 || ppy == 52 || ppy == 26 || ppy == 24 || ppy == 12) {
    pays_per_year_ = ppy;
  }
}

void Employee::Print() const {
  cout << "Employee Name: " << first_name_ << " " << last_name_
        << "\njob title: " << job_title_ << "\nPays per year: " <<
        pays_per_year_ << endl;
}
Employee::Employee( string first, string last, string job_title, int pays) : 
    first_name_("jane"), last_name_("doe"), job_title_("TBD"), pays_per_year_(52) {
  SetFirst(first);
  SetLast(last);
  SetJobTitle(job_title);
  SetPaysPerYear(pays);
}

}  //name space csce_240 Employees