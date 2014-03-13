/*
 * geometry.cpp
 *
 *  Created on: Mar 8, 2014
 *      Author: vietnguyen
 *      Source: TopCoder Tutorials:
 *      	- Geometry Concepts: Basic concepts
 *      	- Geometry Concepts: Line Intersection and Its Applications
 *      	- Geometry Concepts: Using Geometry in TopCoder problems
 */

#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <cmath>
#include <limits>
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

// get the intersection point of two lines
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

bool Geometry::getCircleFrom3Points(point A, point B, point C, point &center, double &radius){
	//get first line
	double A1,B1,C1;
	point X((A._x+B._x)/2, (A._y + B._y)/2); //center point of AB
	getLineEquation(A, B, A1, B1, C1);
	double D1 = -B1*X._x + A1*X._y;
	Line line1(-B1,A1, D1);

	//get second line
	double A2,B2,C2;
	point Y((B._x+C._x)/2, (B._y + C._y)/2); //center point of BC
	getLineEquation(B, C, A2, B2, C2);
	double D2 = -B2*X._x + A2*X._y;
	Line line2(-B2,A2, D2);

	//get intersect
	if(getLineIntersection(line1,line2, center)){
		cout << "Center: " << center.toString() << "\n";
		radius = center.distanceTo(A);
		cout << "Radius: " << radius << "\n";
		return true;
	}else{
		cout << "Center point is not valid!\n";
		radius = 0;
		return false;
	}
}

point Geometry::getReflection(Line line, point X){
	double A = line.getA();
	double B = line.getB();
	double D = -B* X._x + A * X._y;
	Line perpendicularLine(-B, A, D);

	point intersect;
	getLineIntersection(line, perpendicularLine, intersect);
	point Xprime(2* intersect._x - X._x, 2 *intersect._y - X._y);
	return Xprime;
}

void Geometry::convexHull(point *X, bool *isBelongToHull, int numberOfPoints , bool onEdge){
	int p = 0;
	//First find the leftmost point
	for(int i = 1; i < numberOfPoints; i++){
		if(X[i]._x < X[p]._x){
			p = i;
		}
	}
	int start = p;
	do{
		int n = -1;
		double dist = onEdge? numeric_limits<double>::max() :0;
		for(int i = 0; i<numberOfPoints; i++){
			//Don't go back to the same point you come from
			if(i==p) continue;

			//Don't go to a visited point
			if(isBelongToHull[i]) continue;

			//If there is no N yet, set it to i
			if(n==-1) n=i;
			int cross = (X[i] - X[p]) ^ (X[n] - X[p]);

			//d is the distance from P to X
			double d = (X[i] - X[p])*(X[i]-X[p]);
			if(cross < 0){
				//As described above, set N=X
				n=i;
				dist = d;
			}else if(cross == 0){
				if(onEdge && d<dist){
					dist = d;
					n=i;
				}else if(!onEdge && d>dist){
					dist = d;
					n=i;
				}
			}
		}
		p=n;
		isBelongToHull[p] = true;
	}while(start!=p);
}

void Geometry::testGeometry(){
	cout << "---\nLine and point distance\n---\n";
	point A(0, 0);
	point B(0, 4);
	point C(1, 5);
	cout << to_string(linePointDist(A, B, C, true)) << "\n";

	cout << "---\nPolygon area\n---\n";
	point *vertex = new point[3];
	vertex[0].setX(0);
	vertex[0].setY(0);
	vertex[1].setX(0);
	vertex[1].setY(4);
	vertex[2].setX(1);
	vertex[2].setY(5);
	cout << findPolygonArea(vertex, 3) << "\n";

	cout << "---\nLine intersection\n---\n";
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

	cout << "---\nA circle from 3 points\n---\n";
	point M(0,4);
	point N(0,-4);
	point P(4,0);
	point center;
	double radius;
	getCircleFrom3Points(M,N,P,center, radius);

	cout << "---\nReflection\n---\n";
	cout << getReflection(line1, N).toString() <<"\n";

	cout << "---\nConvex Hull\n---\n";
	point *pointSet = new point[5];
	bool isHull[5];
	pointSet[0].setX(0);
	pointSet[0].setY(0);
	pointSet[1].setX(3);
	pointSet[1].setY(0);
	pointSet[2].setX(0);
	pointSet[2].setY(3);
	pointSet[3].setX(-3);
	pointSet[3].setY(0);
	pointSet[4].setX(0);
	pointSet[4].setY(-3);

	convexHull(pointSet, isHull, 5, true);
	for(int i = 0; i < 5; i++){
		if(isHull[i]){
			cout << pointSet[i].toString();
		}
	}

}
