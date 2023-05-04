// Copyright 2023 Harshil
#include<iostream>
#include<cmath>
using std::cin;
using std::cout;
using std::endl;
#include"problem2functions.h"

double Distance(double x, double y, double x1, double y1) {
  return sqrt((x1-x)*(x1-x) + (y1-y)*(y1-y));
}

int OnCircle(double c0, double c1, double r, double x, double y) {
  // calculate the distance
  double distance = Distance(x, y, c0, c1);
  if (distance < r) {
    return -1;  // point lies on the inside of circle
  } else if (distance == r) {
    return 0;  // point lies on the circle
  } else {
    return 1;  // if the first two outcomes aren't true then
               // that means it's outside of the circle
  }
}

bool OnLine(double x1, double y1, double x2, double y2, double x3, double y3) {
  // to check if they lie on the same line
  // let's calculate the slope and compare that and
  // see if it's equal
  double slopeOne = (y2-y1) / (x2-x1);
  double slopeTwo = (y3-y2) / (x3-x2);
  // comapre teh slopes
  if (slopeOne == slopeTwo) {
    return true;
  } else {
    return false;
  }
}

