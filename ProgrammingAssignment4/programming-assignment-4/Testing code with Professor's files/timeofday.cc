//Copyright 2023 Harshil
#include"timeofday.h"
#include<iostream>
#include<string>
using std::cout;
using std::endl;
using std::string;

// implemnting the constructor
TimeOfDay::TimeOfDay (int hour, int minute, int second) {
  //using conditional operator to assign proper values
  // ? -- if-then;else
  hour_ = (hour >= 0 && hour <= 24) ? hour : 0;
  minute_ = (minute >= 0 && minute < 60) ? minute : 0;
  second_ = (second >= 0 && second < 60) ? second : 0;
  // make sure time is always normal
}

bool TimeOfDay::operator<(const TimeOfDay& other) const {
  if (hour_ < other.hour_) {
    return true;
  } else if (hour_ == other.hour_ && minute_ < other.minute_) {
    return true;
  } else {
    return false;
  }
}

bool TimeOfDay::operator>=(const TimeOfDay& other) const {
  if (hour_ > other.hour_) {
    return true;
  } else if (hour_ == other.hour_ && minute_ >= other.minute_) {
    return true;
  } else if (hour_ == other.hour_ && minute_ == other.minute_ && second_ >= other.second_) {
    return true;
  } else {
    return false;
  }
}

bool operator>(const TimeOfDay& lhs, const TimeOfDay& rhs) {
  if (lhs.GetHour() > rhs.GetHour()) {
    return true;
  } else if (lhs.GetHour() == rhs.GetHour()) {
    if (lhs.GetMinute() > rhs.GetMinute()) {
      return true;
    } else if (lhs.GetMinute() == rhs.GetMinute()) {
      if (lhs.GetSecond() > rhs.GetSecond()) {
        return true;
      }
    }
  }
  return false;
}
/*
TimeOfDay TimeOfDay::operator+(const TimeOfDay& other) const {
  int total_seconds = hour_ * 3600 + minute_ * 60 + second_ +
                      other.hour_ * 3600 + other.minute_ * 60 + other.second_;
  int hours = total_seconds / 3600 % 24;
  int minutes = (total_seconds / 60) % 60;
  int seconds = total_seconds % 60;
  return TimeOfDay(hours, minutes, seconds);
}
*/
void TimeOfDay::SetHour(int hour) {
  if (hour >= 0 && hour < 24) {
    hour_ = hour;
  }
}
void TimeOfDay::SetMinute(int minute) {
  if (minute >= 0 && minute < 60) {
    minute_ = minute;
  }
}
void TimeOfDay::SetSecond (int second) {
  if (second >= 0 && second < 60) {
    second_ = second;
  }
}
// Accessor functions implementation
int TimeOfDay::GetHour() const {
  return hour_;
}

int TimeOfDay::GetMinute() const {
  return minute_;
}

int TimeOfDay::GetSecond() const {
  return second_;
}

void TimeOfDay::Print(bool militaryTime, bool normalTime) const {

  int hour = hour_;
  string period = "a.m.";

  if(militaryTime) {
    cout << std::setfill('0') << std::setw(2) << hour << ":" << std::setw(2) << minute_;
    if(normalTime) {
        cout << ":" << std::setw(2) << second_;
    }
    cout << endl;
    return;
  }
  if(hour >= 12) {
    hour -= 12;
    period = "p.m.";
  }
  if(hour == 0) {
    hour = 12;
  }
  cout << std::setfill('0') << std::setw(2) << hour << ":" << std::setw(2) << minute_;

  if (normalTime) {
    cout << ":" << std::setw(2) << second_;
  }
  cout << " " << period << std::endl;
}