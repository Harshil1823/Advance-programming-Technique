//Copyright 2023 Harshil 
#include"timeinterval.h"
#include<iostream>
#include<string>
using std::cout;
using std::endl;
using std::string;

TimeInterval::TimeInterval() : start_(0, 0, 0), end_(0, 0, 0) {}

TimeInterval::TimeInterval(const TimeOfDay& start, const TimeOfDay& end) {
  // Check if start is later in the day than end
  if (start > end) {
    // If start is later, set both start_ and end_ to start
    start_ = start;
    end_ = start;
  } else {
    // If start is earlier or the same as end, set start_ to start and end_ to end
    start_ = start;
    end_ = end;
  }
}
/*
// Implementation of earlier_time member function
TimeOfDay TimeInterval::earlier_time(const TimeOfDay& time1, const TimeOfDay& time2) const {
  if (time1 < time2) {
    return time1;
  } else {
    return time2;
  }
}

// Implementation of constructor
// uses the function earlier_time and then sets it accordingly
TimeInterval::TimeInterval(const TimeOfDay& start, const TimeOfDay& end)
  : start_(earlier_time(start, end)), end_(earlier_time(end, start)) {}
*/

TimeInterval::TimeInterval(const TimeOfDay& start, int length, const std::string& units) :
  start_(start) {
  
  int hours, minutes, seconds;
  hours = start.GetHour();
  minutes = start.GetMinute();
  seconds = start.GetSecond();

  if (units == "hours") {
    hours += length;
  } else if (units == "minutes") {
    minutes += length;
    hours += minutes / 60;
    minutes %= 60;
  } else if (units == "seconds") {
    seconds += length;
    minutes += seconds / 60;
    seconds %= 60;
    hours += minutes / 60;
    minutes %= 60;
  } else {
    // Invalid unit of time
    end_ = start;
    return;
  }
  hours %= 24; // Handle wrapping around to the next day

  end_ = TimeOfDay(hours, minutes, seconds);

  // Check if the interval is invalid
  if (end_ < start_) {
    end_ = start_;
  }
  
  /*
  if (units == "hours") {
    end_.SetHour(start.GetHour() + length);
  } else if (units == "minutes") {
    end_.SetMinute(start.GetMinute() + length);
  } else if (units == "seconds") {
    end_.SetSecond(start.GetSecond() + length);
  }

  if (end_ < start_) {
    end_ = TimeOfDay(0, 0, 0);
  }
  */
}

TimeOfDay TimeInterval::GetStartTime() const {
  return start_;
}

TimeOfDay TimeInterval::GetEndTime() const {
  return end_;
}

void TimeInterval::SetStartTime(const TimeOfDay& newStart) {
  if (newStart < end_) {
    start_ = newStart;
  }
}

void TimeInterval::SetEndTime(const TimeOfDay& newEnd) {
  if (newEnd >= start_) {
    end_ = newEnd;
  }
}

void TimeInterval::SetEndTime(int length, const std::string& units) {
   int hours, minutes, seconds;
   hours = start_.GetHour();
   minutes = start_.GetMinute();
   seconds = start_.GetSecond();

    int totalSeconds = hours * 3600 + minutes * 60 + seconds;
    if (units == "hours") {
        totalSeconds += length * 3600;
    } else if (units == "minutes") {
        totalSeconds += length * 60;
    } else if (units == "seconds") {
        totalSeconds += length;
    } else {
      end_ = start_;
      return;
    }

    // handle negative time intervals
    if (totalSeconds < 0) {
        totalSeconds += 24 * 3600;
    } else if (totalSeconds >= 24 * 3600) {
        totalSeconds -= 24 * 3600;
    }

    hours = totalSeconds / 3600 % 24;
    minutes = totalSeconds / 60 % 60;
    seconds = totalSeconds % 60;
    end_ = TimeOfDay(hours, minutes, seconds);

  /*
  if (units == "seconds") {
    end_ = start_ + TimeOfDay(0, 0, length);
  } else if (units == "minutes") {
    end_ = start_ + TimeOfDay(0, length, 0);
  } else if (units == "hours") {
    end_ = start_ + TimeOfDay(length, 0, 0);
  } else {
    cout << "Invalid time units." << std::endl;
  }

  TimeOfDay newEnd(start_);
  if (units == "hours") {
    newEnd.SetHour(end_.GetHour() + length);
  } else if (units == "minutes") {
    newEnd.SetMinute(end_.GetMinute() + length);
  } else if (units == "seconds") {
    newEnd.SetSecond(end_.GetSecond() + length);
  }
  if (newEnd >= start_) {
    end_ = newEnd;
  }
  */
}

void TimeInterval::Print(bool militaryTime, bool showSeconds) const {
  std::cout << "Start time: ";
  start_.Print(militaryTime, showSeconds);
  std::cout << "End time: ";
  end_.Print(militaryTime, showSeconds);

}
