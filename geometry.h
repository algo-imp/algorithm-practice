/*
 * geometry.h
 *
 *  Created on: Mar 8, 2014
 *      Author: vietnguyen
 */

#ifndef GEOMETRY_H_
#define GEOMETRY_H_

#include "point.h"


class Line{
	double _A, _B, _C;
public:
	Line(double A, double B, double C ){_A = A; _B = B; _C = C;}
	double getA(){return _A;}
	double getB(){return _B;}
	double getC(){return _C;}
};


class Geometry{
public :
	double linePointDist(point A, point B, point C, bool isSegment);
	double findPolygonArea(point vertex[], int numberOfVertices);
	void getLineEquation(point p1, point p2, double &A, double &B, double &C); //line equation Ax + By = C
	bool getLineIntersection(Line line1, Line line2, point &intersectPoint); //return false if two lines are parallel. Else, return the intersect point.
	void testGeometry();
};

#endif /* GEOMETRY_H_ */
