/*
 * tccc2003-semifinal3-zigzag.cpp
 *
 *  Created on: Mar 21, 2014
 *      Author: vietnguyen
 *      http://community.topcoder.com/stat?c=problem_statement&pm=1259&rd=4493

 */

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class ZigZag{
public:
	int longestZigZag(vector<int> sequence);
};

int ZigZag::longestZigZag(vector<int> sequence){
	int n = sequence.size();
	int f[n];
	bool isUp[n]; // check if in the longest sequence up to i-th member, is going up or down
	for (int i = 0 ; i < n ; i++){
		f[i] = 1;
		for(int j = 0; j < i; j++){
			//special case
			if(j == 0 ){
				f[i] = 2;
				isUp[i] = sequence[i] > sequence[0];
			}
			if(isUp[j] == true && sequence[j] > sequence[i]){
				if(f[i] < f[j] + 1){
					f[i] = f[j] + 1;
					isUp[i] = false;
				}
			}
			if(isUp[j] == false && sequence[j] < sequence[i]){
				if(f[i] < f[j] + 1){
					f[i] = f[j] + 1;
					isUp[i] = true;
				}
			}
		}
	}

	return f[n-1];
}

int main(){
	int test[] = { 1, 17, 5, 10, 13, 15, 10, 5, 16, 8 };
	vector<int> input(test,test + sizeof(test)/ sizeof(int));
	ZigZag z;
	cout << z.longestZigZag(input) << "\n";

}
