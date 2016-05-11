/*
 * srm184-div2-lev3.cpp
 *
 *  Created on: Mar 20, 2014
 *      Author: vietnguyen
 *      Link: http://community.topcoder.com/stat?c=problem_statement&pm=2356&rd=4740
 *      Apply: Floyd-Warshall graph searching
 */

#include <iostream>
#include <vector>
using namespace std;

class TeamBuilder{
public:
	vector<int> specialLocations(vector<string> paths);
};

vector<int> TeamBuilder::specialLocations(vector<string> paths){

	int N = paths.size();
	cout << "N = " << N << "\n";
	vector<vector<int> > adj;
	for(int i = 0; i < N; i ++){
		cout << "Row: " << i << "\n";
		string s = paths[i];
		cout << "String: " << s << "\n";
		vector<int> row;
		for(int j = 0; j < N; j++){
			row.push_back(s[j] -'0');
			cout << "row[" << j <<"] = " << row[j] << "\n";
		}
		adj.push_back(row);
	}

	//Floyd-Warshall
	for(int k = 0; k < N; k++){
		for (int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				if(i==j || j == k || k==i)
					continue;

				//only update those no-paths
				if(adj[i][j] == 0){
					if(adj[i][k] !=0 && adj[k][j] != 0){
						adj[i][j] = 1;
					}
				}
			}
		}

	}

	//find number of locations that can reach all other locations
	int firstNum = 0;
	for(int i = 0 ; i < N; i++){
		bool canReachAll = true;
		for(int j = 0; j<N; j++){
			if(j==i) continue;

			if(adj[i][j] == 0){
				canReachAll = false;
				break;
			}
		}

		if(canReachAll)
			firstNum ++;
	}

	//find number of locations that are reachable from other locations
	int secondNum = 0;
	for(int j = 0 ; j < N; j++){
		bool canBeReachedFromAll = true;
		for(int i = 0; i<N; i++){
			if(j!=i && adj[i][j] == 0){
				canBeReachedFromAll = false;
				break;
			}
		}

		if(canBeReachedFromAll)
			secondNum ++;
	}

	vector<int> res;
	res.push_back(firstNum);
	res.push_back(secondNum);
	return res;
}

int main(){

	string input[] = {"0010","1000","1100","1000"};
	vector<string> paths(input, input + sizeof(input) / sizeof(input[0]));
	TeamBuilder tb;
	vector<int> out = tb.specialLocations(paths);

	cout << "{" << out[0] << ", " << out[1] << "}\n";
}
