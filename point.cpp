/*
 * point.cpp
 *
 *  Created on: Mar 8, 2014
 *      Author: vietnguyen
 *      point class for geometry problems
 */

#include "point.h"
#include <string>
#include <math.h>

point point::operator+(point other){
	point ret;
	ret._x = _x + other._x;
	ret._y = _y + other._y;
	return ret;
}
point point::operator-(point other){
	point ret;
	ret._x = _x - other._x;
	ret._y = _y - other._y;
	return ret;
}

double point::operator*(point other){
	return _x * other._x + _y * other._y;
}

double point::operator^(point other){
	return _x * other._y - _y * other._x;
}

double point::distanceTo(point other){
	return sqrt(pow(_x - other._x, 2) + pow(_y - other._y,2) );
}
string point::toString(){
	string ret;
	ret = ret + "("+ to_string(_x) + "," + to_string(_y) + ")";
	return ret;
}
