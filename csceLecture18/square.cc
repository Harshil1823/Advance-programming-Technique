// Copyright 2023 Harshil
// implement the functionality of square class
#include"rectangle.h"
#include"square.h"
#include<iostream>
using std::ostream;
namespace csce240_shapes {

ostream& operator << (ostream& whereto, const Square&s) {
  whereto << "Square: ";
  // the line below is completely valid to cast a derived class
  // object as a base class object to use the base class version
  // of the << opearor (just commenting it out because the output looks
  // weird in this example)
 // whereto << static_cast<Rectangle>(s);
  whereto << "sides: " << s.GetLength();
  return whereto;
}
  //important to call the base class constructor in the derived class
  //constructor's member initializer list to set up the base class members
  // correctly before entering the body of the derived class constructor
Square::Square(double side) : Rectangle(side, side) {
    //length_ = width_ = side; // can't access private members of the base class directly
  //  SetLength(side);  -- no longer necessary if we call the Rectangle constructor as above 
  //  SetWidth(side);
}
void Square::SetLength(double side) {
  //call the base class version of these redifned functions using the
  //base class name and scope resolution operator
  Rectangle::SetLength(side);
  Rectangle::SetWidth(side);
}
void Square::SetWidth(double side) {
  //call the base class version of these redifned functions using the
  //base class name and scope resolution operator
  Rectangle::SetLength(side);
  Rectangle::SetWidth(side);
}

}// end of namespace
