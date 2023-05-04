// copyright 2023 Harshil
#include"length.h"
#include<iostream>
#include<string>
using std::cout;
using std::endl;

Length Length::operator+(const Length& other) const {
  // convert the other length to the same units as the left operand
  double other_value = other.GetValue();
  if (other.GetUnits() != units_) {
    if (units_ == "inches") {
      // convert it to inches
      other_value /= 2.54;
    } else {
      // convert it to cm
      other_value *= 2.54;
    }
  }
  // add the values and return a new length object
  // with the same units as the left operand
  return Length(value_ + other_value, units_);
}

bool Length::operator==(const Length& other) const {
  double other_value = other.GetValue();
  string other_units = other.GetUnits();
  // Convert both lengths to the same units
  if (units_ == "inches" && other_units == "centimeters") {
    // convert it to inches
    other_value /= 2.54;
    other_units = "inches";
  } else if (units_ == "centimeters" && other_units == "inches") {
    // convert it to cm
    other_value *= 2.54;
    other_units = "centimeters";
  }
  // Compare the values
  return value_ == other_value && units_ == other_units;
}

bool Length::operator<(const Length& other) const {
  double thisValue = value_;
  double otherValue = other.value_;

  if (units_ != other.units_) {
    if (units_ == "inches") {
      thisValue *= 2.54;
    } else {
      otherValue *= 2.54;
    }
  }

  return thisValue < otherValue;
}

ostream& operator<<(ostream& os, const Length& length) {
  os << length.GetValue() << " " << length.GetUnits();
  return os;
}

Length::Length(double value, string units) {
  if (value < 0) {
    value_ = 0;
  } else {
    value_ = value;
  }
  if ( units != "inches" && units != "centimeters" ) {
    units_ = "inches";
  } else {
    units_ = units;
  }
}

void Length::SetUnits(string units) {
  if (units == "inches" || units == "centimeters") {
    units_ = units;
  }
}

void Length::SetValue(double value) {
  if (value >= 0) {
    value_ = value;
  }
}

string Length::GetUnits() const {
  return units_;
}

double Length::GetValue() const {
  return value_;
}

void Length::Convert(string units) {
  if (units == "centimeters" && units_ != "centimeters") {
    value_ = GetValue() * 2.54;
    units_ = units;
  } else if (units == "inches" && units_ != "inches") {
    value_ = GetValue() / 2.54;
    units_ = units;
  }
}
