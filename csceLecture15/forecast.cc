//copyright 2023 harhsil 
// implement function of the forecast class
#include"forecast.h"
#include"temperature.h" // this would get included regardless, but 
                        // it's there so less confuion
#include<iostream>
using std::cout;
using std::endl;

Forecast::Forecast(double l, double h, double rain) : low_(-100, "Fahrenheit"), high_(200, "Fahrenheit"),
chance_of_rain_(0) {
  // chance_of_rain_ = 0;
  setLow(l);
  SetHigh(h);
  SetChanceOfRain(rain);
}

void Forecast::setLow(double l) {
  // at the moment we're assuming that low_ and high_ have the same units
  if ( l <= high_.GetValue() )  {
    low_.SetValue(l)
  }
}

void Forecast::SetHigh(double h) {
  // same assumption that temp units are the same
  if ( h >= low_.GetValue()) {
    high_.SetValue(h);
  }
}

void Forecast::SetChanceOfRain(double r) {
  if ( r >= 0 && r <= 100) {
    chance_of_rain_ = r;
  }
}

void Forecast::Print() const {
  cout << "Forecast low: "; 
  low_.Print(); // NOte: low is a temperature object, so it can can call any of the
                // public memebers of temperature
  cout << "Forecast high: ";
  high_.Print();
  cout << "Chance of percipitation: " << chance_of_rain_ << endl;
}