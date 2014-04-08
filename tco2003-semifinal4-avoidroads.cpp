/*
 * tco2003-semifinal4-avoidroads.cpp
 *
 *  Created on: Apr 2, 2014
 *      Author: vietnguyen
 *      Problem details: http://community.topcoder.com/stat?c=problem_statement&pm=1889&rd=4709
 */

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <algorithm>

using namespace std;

class AvoidRoads{
public:
	long numWays(int width, int height, vector<string> bad);
};

long AvoidRoads::numWays(int width, int height, vector<string> bad){
	bool badVertical[width+1][height+1];
	bool badHorizontal[width+1][height+1];

	for(int i = 0; i <= width; i++){

		for(int j = 0 ; j <= height; j++){
			badVertical[i][j] = false;
			badHorizontal[i][j] = false;
		}
	}

	for(int i = 0; i< bad.size(); i++){
		stringstream temp(bad[i]);
		int x, y, z,  t;
		temp >> x >> y >> z >> t;
		if(abs(z - x) ==1){
			badHorizontal[min(x,z)][y] = true;
			cout << "bad Horizontal at: " << min(x,z) << ", " << y << "\n";
		}
		else if(abs(t - y) == 1){
			badVertical[x][min(y,t)] = true;
			cout << "bad Vertical at: " << x << ", " << min(y,t) << "\n";
		}
	}

	long res [width+1][height+1];
	res[0][0] = 1;
	for(int i = 0; i<= width; i++ ){

		for(int j = 0; j <= height; j++){
			long temp = 0;
			if(i>0 && !badHorizontal[i-1][j] )	{
				temp += res[i-1][j];
			}
			if(j>0 && !badVertical[i][j-1]){
				temp += res[i][j-1];
			}
			cout << "temp = " << temp << "\n";
			if(i!=0 && j!=0) res[i][j] = temp;
			cout << "Ways to (" << i << "," << j << ") is: " << res[i][j] << "\n";
		}
	}
	return res[width][height];

	//return 0;
}

int main(){
	AvoidRoads av;
	int width = 6;
	int height = 6;
	string arrayString[] = {"0 0 0 1","6 6 5 6"};
	vector<string> bad;
	bad.push_back(arrayString[0]);
	bad.push_back(arrayString[1]);

	cout << av.numWays(width, height, bad) << "\n";
}
