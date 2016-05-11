/*
 * srm599-div2-prob3.cpp
 * Tag: backtrack
 *  Created on: Jun 1, 2014
 *      Author: vietnguyen
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class SimilarNames2{
	vector<string> _names;
public:
	int backtrack(int index, int maxsize, int remaining){
		cout << "In backtrack: " << index << ", " << maxsize << ", " << remaining << "\n";
		if(remaining == 0)
			return 1;
		else{
			int res = 0;
			for(int i = index + 1; i< maxsize; i++ ){
				if(_names[i].substr(0, _names[index].size()) == _names[index])
					res += backtrack(i, maxsize, remaining - 1);
			}
			return res;
		}
	}
	int count (vector<string> names, int L){
		if(L<2) {
			int size = names.size();
			int res = 1;
			for(int i = 1; i<=size; i++){
				res *= i;
			}
			return res;
		}
		sort(names.begin(), names.end());

		_names = names;
		for(int i = 0; i< _names.size(); i++){
			cout << _names[i] << " ";
		}
		cout << "\n";
		int temp = 0;
		for(int i = 0; i< _names.size(); i++){
			temp += backtrack(i, _names.size(), L-1);
		}
		cout << "temp = " << temp << "\n";
		for(int i = 1; i<= (names.size()-L); i++){
			int x = 0;
			for(int j = 1; j <= i; j++){
				x = (x+temp) % 1000000007;
			}
			temp = x;
			cout << "temp = " << temp << "\n";
		}
		return temp;
	}
};
