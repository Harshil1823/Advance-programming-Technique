// Copyright 2023 Harshil
#ifndef _TIMEOFDAY_H_
#define _TIMEOFDAY_H_
#include <iostream>
#include <iomanip>
// Define a TimeOfDay class that has private integer data members for the
//    hour (24 hour value)
//    minute
//    second
// The class should ensure that the data members always remain in a consistent
// state.
class TimeOfDay {
 public:
    // Add a constructor to allow the user to initialize the hour, minute,
    // and second, in that order, with default arguments of 0
    // If an argument value is invalid, the corresponding data member should be
    // initialized to zero. For example, TimeOfDay(9, 87, 13) should initialize
    // the hour to 9, the minute to 0, and the second to 13.
    explicit TimeOfDay(int hour = 0, int minute = 0, int second = 0);
    // Add mutator functions SetHour, SetMinute, and SetSecond that set the
    // data member if the argument is valid, and leave the data member unchanged
    // if the argument is invalid.
    void SetHour(int hour);
    void SetMinute(int minute);
    void SetSecond(int second);
    // Add accessor functions GetHour, GetMinute, and GetSecond that return
    // a copy of the value of the corresponding data member.
    int GetHour() const;
    int GetMinute() const;
    int GetSecond() const;
    // print method
    void Print(bool militaryTime = false, bool normalTime = false) const;

    // this is all stff that's helping in TimeInterval class
    bool operator<(const TimeOfDay& other) const;
    bool operator>=(const TimeOfDay& other) const;
    friend bool operator>(const TimeOfDay& lhs, const TimeOfDay& rhs);
    // TimeOfDay operator+(const TimeOfDay& other) const;
 private:
    int hour_;  // this needs 24 hour value
    int minute_;
    int second_;
};
// Add a Print function that will output the TimeOfDay object to the standard
// output device using cout, ending with endl (to flush the output buffer and
// go to the next line).
// The Print function should take two bool parameters for whether or not to
// display the time in military time (i.e. 24 hour format) and whether or
// not to display the seconds value.
// Both parameters should have default arguments of false.
// If the first argument is true, the time should print in military time (24
//  hour format), and if the first argument is false, the time should print
//  in a.m./p.m. format.
//  For example 13:00:00 in military time is equivalent to 01:00:00 p.m.
//          and 07:00:00 in military time is equivalent to 07:00:00 a.m.
// If the second argument is true, the output should display the seconds
//  value and if the second argument is false, the output should omit (drop,
//  don't round) the seconds component of the time.
// e.g. Print() output will be formated as hh:mm a.m. or hh:mm p.m.
//      Print(true) output will be formated as hh:mm
//      Print(true, true) output will be formated as hh:mm:ss
//      Print(false, true) output will be formatted as
//                         hh:mm:ss a.m. or hh:mm:ss p.m.
#endif
