// Copyright 2023 Harshil
// Introduction to class
#include<iostream>
using std::cout;
using std::cin;
using std::endl;

class School {
  public:
    School(); //{ //constructor for our school class - default constructor is 
              // constructor that can be called with no arguments
     // enrollment = 0;
   // }

  
  // accessro function - public function providesa a copy of the value 
  //                      of a private/protected data member
  // const on the end of the function means member function won't modify 
  // the objects its called on (won't change the values of data member)
  int GetEnrollment() const {return enrollment_;}
  
  // mutator function - public function changes the value of memeber
  void SetEnrollment(int newEnrollment);

  private:  // make members private that we want to restrict access to / keep 
            // in a consistent state
    int enrollment_;
};

//implement the constructor outside of the class definition
// to specify that it's coming from the School class, needed to be tied to the
// class using the scope resolution operator(::)
School::School() {
  enrollment_= 0;
}

void School::SetEnrollment(int newEnrollment) {
  if (newEnrollment > 0) {
    enrollment_ = newEnrollment;
  }
}

int main () {
  School my_School; // declare a variable of our class type 
                    // a variable of class type is called an object
                    // instantiate - create an instance of (declare/initialize a object of class)
  cout << my_School.GetEnrollment() << endl;
  int x;
  cout << "what's the actaul enrollment? ";
  cin >> x;
  my_School.SetEnrollment(x);
  cout << my_School.GetEnrollment() << endl;
  return 0;
}