/*
 * problem2.cpp
 *
 *  Created on: Apr 4, 2014
 *      Author: vietnguyen
 */

#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

class LongLongTripDiv2{
public:
	string isAble(long long, int, int);
};

string LongLongTripDiv2::isAble(long long D, int T, int B){
	long long total = (D+1) *(T+1);
	//bitset<total> able;
	vector<bool> able;
	//vector<bitset<T+1> > able;
	//bool able[D+1][T+1];
	for (long long distance = 0; distance <=D ; distance ++){

		//bitset<T+1> row;
		for (int jumps = 0; jumps <= T; jumps ++){
			//row.push_back(false);
			//row[jumps] = false;
			//able[distance][jumps] = false;
			//able[distance * (T+1) + jumps] = false;
			able.push_back(false);
		}
	}
	able[0] = true;
	for (long long distance = 1; distance<=D; distance++){
		for(int jumps = 1; jumps <= T; jumps++){
			//able[distance][jumps] = able[distance-1][jumps-1];
			bool temp = distance >=B ? able[(distance - B) *(T+1) + (jumps - 1)] : false;
			able[distance * (T+1) + jumps ] = able[(distance-1)*(T+1) + (jumps - 1)] | temp;

			//cout << "Distance: " << distance << "; Jumps: " << jumps << "; Able: " << able[distance][jumps] << "\n";
		}
	}
	string res = able[D * (T+1) + T] ? "Possible" : "Impossible";
	return res;
}

int main(){
	long long D = 1000010000100001;
	int T = 1100011;
	int B = 1000000000;
//	long long D = 1000;
//	int T = 100;
//	int B = 10;
	LongLongTripDiv2 test;
	cout << test.isAble(D,T,B);
}
