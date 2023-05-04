// copyright 2023 Harhsil
// define the Forecast class
// A Forecast has Temperature object as data member
#ifndef _FORECAST_H_
#define _FORECAST_H_
#include "temperature.h"

class Forecast {
  public:
    explicit Forecast(double low=50, double high = 70, double rain=0);
    void Print() const;
    void SetChanceOfRain(double r);
    double GetChanceOfRain() const { return chance_of_rain_; }
    void setLow(double l);
    void SetHigh(double h);
  private:
    Temperature low_;
    Temperature high_;
    double chance_of_rain_;
};

#endif