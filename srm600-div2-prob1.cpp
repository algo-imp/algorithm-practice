/*
 * srm600-div2-prob1.cpp
 *
 *  Created on: Jun 2, 2014
 *      Author: vietnguyen
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

class TheShuttles{
public:
	int getLeastCost(vector<int> cnt, int baseCost, int seatCost){
		sort(cnt.begin(), cnt.end());
		int minCost = std::numeric_limits<int>::max();
		for(int X = cnt[0]; X <= cnt[cnt.size()-1]; X++){
			int nShuttles = 0;
			int cost = 0;
			for(int i = 0; i <cnt.size(); i++){
				nShuttles += cnt[i] / X;
				if(cnt[i] % X != 0 ) nShuttles +=1;
				cout << X << "," << cnt[i] << "," << nShuttles << "\n";
			}
			cost = nShuttles * (baseCost + X *seatCost);
			if(cost < minCost) minCost = cost;
		}
		return minCost;
	}
};
