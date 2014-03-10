/*
 * geometry.cpp
 *
 *  Created on: Mar 8, 2014
 *      Author: vietnguyen
 *      Source: TopCoder Tutorials:
 *      	- Geometry Concepts: Basic concepts
 *      	- Geometry Concepts: Line Intersection and Its Applications
 */

#include "point.h"
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <cmath>
#include "geometry.h"
#include "point.h"

using namespace std;

//compute the distance from AB to C
double Geometry::linePointDist(point A, point B, point C, bool isSegment){
	double dist = ((B-A) ^ (C-A)) / sqrt((B-A)*(B-A));
	if(isSegment){
		int dot1 = (C-B) * (B-A);
		if(dot1 > 0) return sqrt((B-C) * (B-C));
		int dot2 = (C-A) * (A-B);
		if(dot2 > 0) return sqrt((A-C) * (A-C));
	}
	return abs(dist);
}

// find the area of the polygon defined by vertices
double Geometry::findPolygonArea(point vertex[], int numberOfVertices){
	double area = 0.0;
	for(int i = 1; i+1 < numberOfVertices; i++){
		point first(vertex[i]._x - vertex[0]._x, vertex[i]._y - vertex[0]._y );
		point second(vertex[i+1]._x - vertex[0]._x, vertex[i+1]._y - vertex[0]._y);
		area += first ^ second;
		cout << "i = " << i << "; area = " << area << "\n";
	}

	return abs(area/2);
}

// get the equation of the line passing two points
void Geometry::getLineEquation(point p1, point p2, double &A, double &B, double &C){
	A = p2._y - p1._y;
	B = p1._x - p2._x;
	C = A * p1._x + B * p1._y;
}

bool Geometry::getLineIntersection(Line line1, Line line2, point &interectPoint){
	double det = line1.getA() * line2.getB() - line2.getA() * line1.getB();
	if(det == 0){
		return false;
	}else{
		interectPoint._x = (line2.getB() * line1.getC() - line1.getB() * line2.getC())/det;
		interectPoint._y = (line1.getA() * line2.getC() - line2.getA() * line1.getC())/det;
		return true;
	}
}

void Geometry::testGeometry(){
	point A(0, 0);
	point B(0, 4);
	point C(1, 5);
	cout << to_string(linePointDist(A, B, C, true)) << "\n";

	point *vertex = new point[3];
	vertex[0].setX(0);
	vertex[0].setY(0);
	vertex[1].setX(0);
	vertex[1].setY(4);
	vertex[2].setX(1);
	vertex[2].setY(5);
	cout << findPolygonArea(vertex, 3) << "\n";

	double A1,B1,C1;
	point X(0,0);
	point Y(5,0);
	getLineEquation(X, Y, A1, B1, C1);
	double A2,B2,C2;
	point Z(1,4);
	point W(2,-4);
	getLineEquation(Z, W, A2, B2, C2);
	Line line1(A1,B1,C1);
	Line line2(A2,B2,C2);
	point intersect(0,0);
	if(getLineIntersection(line1, line2, intersect)){
		cout << "Intersect point: " << intersect.toString() << "\n";
	}else{
		cout << "Parallel\n";
	}
}
