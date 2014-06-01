/*
 * srm599-div2-prob1.cpp
 *
 *  Created on: Jun 1, 2014
 *      Author: vietnguyen
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class MiniatureDachshund {
public:
	int maxMikan(vector<int> mikan, int weight){
		sort(mikan.begin(), mikan.end());
		int index = 0;
		while(index < mikan.size() && weight + mikan[index] <= 5000){
			cout << weight + mikan[index ]<< "\n";
			weight += mikan[index];
			index ++;
		}
		return index;
	}
};
