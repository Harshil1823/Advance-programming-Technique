//Copyright 2023 Harshil
// Define the recetangle class

#ifndef _RECTANGLE_H
#define _RECTANGLE_H
#include<iostream>
using std::ostream;


namespace csce240_shapes {
  class Rectangle {
      friend ostream& operator << (ostream&, const Rectangle&);
    public:
      explicit Rectangle(double l=1, double w=1);
      void SetLength(double l);
      void SetWidth(double w);
      double GetLength() const { return length_;}
      double GetWidth() const { return width_;}
      double Area() const;
      double Perimeter() const;
    private:
      double length_;
      double width_;

  }; //end class Rectangle
}//end namespace csce240_shapes




#endif