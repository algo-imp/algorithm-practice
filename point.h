/*
 * point.h
 *
 *  Created on: Mar 8, 2014
 *      Author: vietnguyen
 */

#ifndef POINT_H_
#define POINT_H_

#include <string>
using namespace std;

class point{
public:
	double _x,_y;
	point(){_x=0; _y = 0;}
	point(double x, double y){_x = x; _y = y;}
	void setX(double x){_x = x;}
	void setY(double y){_y = y;}
	point operator+(point);
	point operator-(point);
	double operator*(point); //dot product
	double operator^(point); //cross product, for find area
	string toString();
};


#endif /* POINT_H_ */
