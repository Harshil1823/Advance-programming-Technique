#ifndef _PROBLEM2FUNCTIONS_H
#define _PROBLEM2FUNCTIONS_H

// function that returns the distance
// between two points 
double Distance (double x, double y, double x1=0, double y1=0);

// the x and y coordinates of the center of a circle as the first two parameters, 
// the radius of the circle as the third parameter, 
//and the x and y coordinates of a point as the fourth and fifth parameters (all doubles).
// The function should return -1 if the point lies inside of the circle, 
// 0 if the point lies on the circle, 
//and 1 if the point lies outside of the circle
int OnCircle(double c0, double c1, double r, double x, double y);

//Write a function named OnLine that takes the x and y coordinates (all doubles)
// of three points (x1, y1, x2, y2, x3, y3). 
// The function should return true if the three points lie on a straight line, 
// and false if they do not.
bool OnLine(double x1, double y1, double x2, double y2, double x3, double y3);

#endif