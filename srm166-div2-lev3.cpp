/**
 * TopCoder Single round Match 166 - Division II, Level Three
 * http://community.topcoder.com/stat?c=problem_statement&pm=1660
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class pointInt{
public:
	int x, y;
	pointInt(){x = 0; y=0;}
	pointInt (int _x, int _y){x=_x; y=_y;}
	pointInt operator+ (pointInt);
	pointInt operator- (pointInt);
	int operator* (pointInt); //dot product
	int operator^ (pointInt);	//cross product

};


class ConvexPolygon{
public:
	double findArea(vector<int> x, vector<int> y);
};

pointInt pointInt::operator+(pointInt other){
	pointInt ret;
	ret.x = x + other.x;
	ret.y = y + other.y;
}

pointInt pointInt::operator-(pointInt other){
	pointInt ret;
	ret.x = x - other.x;
	ret.y = y - other.y;
}

int pointInt::operator*(pointInt other){
	return (x * other.x + y * other.y);
}

int pointInt::operator^(pointInt other){
	return (x * other.y - y * other.x);
}


double findArea(vector<int> x, vector<int> y){
	return 0;
}
