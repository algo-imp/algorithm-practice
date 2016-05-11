/**
 * TopCoder Single round Match 166 - Division II, Level Three
 * http://community.topcoder.com/stat?c=problem_statement&pm=1660
 *
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include "srm_header.h"

using namespace std;

pointInt pointInt::operator+(pointInt other){
	pointInt ret;
	ret.x = x + other.x;
	ret.y = y + other.y;
	return ret;
}

pointInt pointInt::operator-(pointInt other){
	pointInt ret;
	ret.x = x - other.x;
	ret.y = y - other.y;
	return ret;
}

int pointInt::operator*(pointInt other){
	return (x * other.x + y * other.y);
}

int pointInt::operator^(pointInt other){
	return (x * other.y - y * other.x);
}


double ConvexPolygon::findArea(vector<int> x, vector<int> y){
	pointInt start(x[0], y[0]);
	int len = x.size();
	double area = 0.0;
	for(int i = 1;  i+1< len; i++){
		pointInt first(x[i], y[i]);
		pointInt second(x[i+1], y[i+1]);
		area += (first - start) ^ (second - start);

	}
	return abs(area/2);
}
