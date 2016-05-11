/*
 * srm_header.h
 *
 *  Created on: Mar 12, 2014
 *      Author: vietnguyen
 *      This header file contains all the definition of TopCoder SRM problems, which are called from main.cpp
 */

#ifndef SRM_HEADER_H_
#define SRM_HEADER_H_

#include <iostream>
#include <vector>

using namespace std;
class grafixMask{
public:
	bool fill[600][400];
	vector<int> sortedAreas(vector<string> rectangles);
	int doFill(int x, int y);
	int test();
};

class pointInt{
public:
	int x, y;
	pointInt(){x = 0; y=0;}
	pointInt (int _x, int _y){x=_x; y=_y;}
	pointInt operator+ (pointInt);
	pointInt operator- (pointInt);
	int operator* (pointInt); //dot product
	int operator^ (pointInt);	//cross product
	double findArea(vector<int>, vector<int>);
};

class ConvexPolygon{
public:
	double findArea(vector<int> x, vector<int> y);

};



class PathFinding{
public:
	int minTurns(vector<string> board);
	void test();
};

#endif /* SRM_HEADER_H_ */
