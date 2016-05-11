/*
 * srm574-div2-prob1.cpp
 *
 *  Created on: May 31, 2014
 *      Author: vietnguyen
 */

#include <iostream>
#include <sstream>
#include <map>
#include <vector>
using namespace std;

class CityMap{
public:

	string getLegend(vector<string> cityMap, vector<int> POIS){
		map<char, int> numberOfPOIs;

		for(int i = 0; i < cityMap.size(); i++){
			string temp = cityMap[i];
			istringstream iss(temp);
			char c;
			for(int j = 0; j < temp.length(); j++){
				iss >> c;
				if(c != '.'){
					if(numberOfPOIs.find(c) == numberOfPOIs.end()){
						numberOfPOIs[c] = 1;
					}
					else{
						numberOfPOIs[c] ++;
					}
				}
			}
		}

		ostringstream res;
		for(int i = 0; i< POIS.size(); i++){
			for(map<char,int>::iterator it = numberOfPOIs.begin(); it != numberOfPOIs.end(); it++){
				if(POIS[i] == it->second){
					res << it->first;
					numberOfPOIs.erase(it);
					break;
				}
			}
		}

		return res.str();

	}
};
