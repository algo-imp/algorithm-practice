/*
 * geometry.h
 *
 *  Created on: Mar 8, 2014
 *      Author: vietnguyen
 */

#ifndef GEOMETRY_H_
#define GEOMETRY_H_

#include "point.h"

class Geometry{
public :
	double linePointDist(point A, point B, point C, bool isSegment);
	double findPolygonArea(point vertex[], int numberOfVertices);

	void testGeometry();
};


#endif /* GEOMETRY_H_ */
