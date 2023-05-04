//Copyright 2023 Harshil
//define the square class
#ifndef _SQUARE_H
#define _SQUARE_H
#include"rectangle.h"
#include<iostream>
using std::ostream;

namespace csce240_shapes {
class Square : public Rectangle {
  friend ostream& operator << (ostream& whereto, const Square& s);
  public:
    explicit Square(double side);
    
    //redifing the setwifth and setLength functions
    void SetWidth(double side); 
    void SetLength(double side);  
  };

}


#endif