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

#endif /* SRM_HEADER_H_ */
