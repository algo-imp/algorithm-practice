/*
 * srm574-div2-prob3.cpp
 *
 *  Created on: May 31, 2014
 *      Author: vietnguyen
 */

#include <iostream>
#include <vector>
using namespace std;


class PolygonTraversal2{
public:
	int backtrack(vector<int> ps, bool visited[] , int nTarget){

		int curVertex = ps[ps.size()-1];
		cout << "In backtrack: " <<  curVertex << ", " << ps.size() << ", " << nTarget << "\n";
		if(ps.size() == nTarget){
			int i = ps[0];
			cout << "Visit: " << i << "\n";
			for(int j = 0; j < ps.size() - 1; j++){
				int start1 = ps[j] < ps[j+1]? ps[j] : ps[j+1];
				int end1 = ps[j] < ps[j+1]? ps[j+1] : ps[j];
				int start2 = curVertex < i ? curVertex : i;
				int end2 = curVertex < i ? i : curVertex;
				cout << start1 << "," << end1 << "," << start2 <<"," << end2 << "\n";
				if((start1 < start2 && start2 < end1 && end1 < end2) ||
						(start2 < start1 && start1 < end2 && end2 < end1)){
					cout << "Add " << i << "\n";
					ps.push_back(i);
					visited[i] = true;
					return 1;
				}
			}
			return 0;
		} else{
			int res = 0;
			for(int i = 1; i <= nTarget; i++ ){
				if(!visited[i]){
					cout << "Visit: " << i << "\n";
					for(int j = 0; j < ps.size() - 1; j++){
						int start1 = ps[j] < ps[j+1]? ps[j] : ps[j+1];
						int end1 = ps[j] < ps[j+1]? ps[j+1] : ps[j];
						int start2 = curVertex < i ? curVertex : i;
						int end2 = curVertex < i ? i : curVertex;
						cout << start1 << "," << end1 << "," << start2 <<"," << end2 << "\n";
						if((start1 < start2 && start2 < end1 && end1 < end2) ||
								(start2 < start1 && start1 < end2 && end2 < end1)){
							cout << "Add " << i << "\n";
							ps.push_back(i);
							visited[i] = true;
							res += backtrack(ps, visited, nTarget);
							break;
						}
					}
				}
			}

			return res;
		}

	}

	int count(int N, vector<int> points){
		bool visited[N+1];
		int countVisited = 0;
		fill_n(visited, N+1,  false);
		for(int i = 0; i < points.size(); i++){
			visited[points[i]] = true;
			countVisited ++;
		}
		return backtrack(points, visited, N);

	}
};
