// copyright Harshil 2023
#include"temperature.h"
#include<string>
using std::string;
#include<iostream>
using std::cout;
using std::endl;

void Temperature::Convert(string newunits) {
  if ( units_ == "Celsisu") {
    if ( newunits == "Kelvin") {
      value_ -= 273.15;
      units_ = newunits;
    } else if ( newunits == "Farenheit") {
      value_ = 9/5.0 * value_ + 32;
      units_ = newunits;
    }
  } else if ( units_ == "Kelvin" ) {
    if ( newunits == "Celsius" ) {
      value_ += 273.15;
      units_ = newunits;
    } else if ( newunits == "Fahrenheit" ) {
      value_ = 9 / 5.0 * ( value_ + 273.15 ) + 32;
      units_ = newunits;
    }
  } else if ( units_ == "Fahrenheit" ) {
    if ( newunits == "Celsius" ) {
      value_ = (value_ - 32) * 5 / 9.0;
      units_ = newunits;
    } else if ( newunits == "Kelvin") {
      value_ = (value_ - 32) * 5 / 9.0 - 273.15;
      units_ = newunits;
    }
  }
}

Temperature::~Temperature() {
    // toy example - just printing output so we can see when the 
    // destructor is called
    cout << "Destructor called for " << value_ << " " 
        << units_ << endl;
}
// Default constructor implementation
// member initializer list comes between the close parenthesis for the
// constructor parameters and the body of the function
// if the data member is an object of a class, the member initializer
//  list allows you to call the class constructor
Temperature::Temperature(double v, string u) : value_(0), units_("Celsius") {
 // value_ = 0;
 // units_ = "Celsius";
  SetValue(v);
  SetUnits(u);  //note: this function doesn't update units if the
                // argument is invalid, so we need line 10 above to
                // ensure that the units hold the valid value
}

void Temperature::SetValue(double v) {
  value_ = v;
}

void Temperature::SetUnits(string u) {
  // string class has == and = overloaded to compare the contents (characters)
  // of strings and copy the characters of the strings, respectively
  if (u == "Fahrenheit" || u == "Celsisus" || u == "Kelvin") {
    units_ = u;
  }
}

void Temperature::Print() const {
  cout << value_ << " degrees " << units_ << endl;
}