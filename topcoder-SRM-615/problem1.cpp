/*
 * problem1.cpp
 *
 *  Created on: Apr 4, 2014
 *      Author: vietnguyen
 */

#include <iostream>
#include <vector>

using namespace std;

class AmebaDiv2{
public:
	int simulate(vector<int>, int);
};

int AmebaDiv2::simulate(vector<int> gels, int initsize){
	int size = initsize;
	for(int i=0; i< gels.size(); i++){
		if(size == gels[i]){
			size = size * 2;

		}
	}
	return size;
}

int main(){
	AmebaDiv2 a;
	int arraygels[] = {817,832,817,832,126,817,63,63,126,817,832,287,823,817,574};
	vector<int> gels(arraygels, arraygels + 15);
	int A = 63;
	int res = a.simulate(gels, A);
	cout << res;
	return 0;
}
