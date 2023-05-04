// copyright 2023 Harshil
// define temperature class
#ifndef _TEMPERATURE_H_
#define _TEMPERATURE_H_
#include <string>  //string class defined in the standard library
using std::string;  // string is in std namespace
class Temperature {
  // by default they are private
  public:
    //Constructor
    // if constructor can be called with a single argument, we'll make the 
    // constructor explicit to ensure that it's only called if we explicitly
    // ask for it to be called (Temperaturs won't be created out of double
    // without us specifically calling the constructor)
    explicit Temperature(double v=0, string u="Celsius");  // called whenever the object is instantiated
    //destructor - no return type, name = ~classname()
    ~Temperature();
    // mutator function
    void SetValue(double v);
    void SetUnits(string m);
    // accessor functions
    double GetValue() const { return value_; }
    string GetUnits() const { return units_; }

    // convert from one unit of measure to another
    void Convert(string newunits);

    void Print() const;
  private:
    double value_;
    // using object of one class as a data memeber in another
    // class is called "composition"
    // one class "has a(n)" object of another class as a data member
    string units_;  //Fahrenheit, Celsius, Kelvin

};

#endif // end _TEMPERATURE_H_
