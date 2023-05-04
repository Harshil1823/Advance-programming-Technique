//Copyright 2023 Harshil
//Introduction to structures
#include<iostream>
using std::cout;
using std::cin;
using std::endl;

// defining two dimensional point in the cartesian plane
struct Point {
  // by default all of them are public
  double x;
  double y;
};

int main() {
  Point some_point, some_other_point;
  cout << "enter the x and y coordinate of the first point: ";
  cin >> some_point.x >> some_point.y; 
  cout << "enter the x and y coordinate of the second point: ";
  cin >> some_other_point.x >> some_other_point.y; 
  cout << "The points are (" << some_point.x << "," << some_point.y << ") and "
        << "( " << some_other_point.x << "," << some_other_point.y 
        << ")" << endl;
  
  // can access the public memebers on a pointer either by dereferencing and
  // using the dot operator, or equivalently using the arrow operator
  Point * pointpointer = &some_point;
  cout << "accessing the coordinate " << (*pointpointer).x << "\n"
       << pointpointer->x << endl;
  Point bunch_of_points[5];
  cout << "enter 5 points ";
  for (int i=0; i < 5; ++i) {
    cin >> bunch_of_points[i].x >> bunch_of_points[i].y;
  }
  return 0;
}

     