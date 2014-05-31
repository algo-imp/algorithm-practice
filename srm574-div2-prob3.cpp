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

	/* TOPCODER solution */
	int N;
	bool visited[14];
	int points[13];

	// This handy function returns true if the segment x -> y
	// intersects with any of the segments described by :
	// points[0] -> points[1], points[1] -> points[2], ...
	bool cross(int x, int y, int t)
	{
	    // Segment x -> y is the same as y -> x, pick the one with (x < y).
	    if (x > y) {
	        swap(x, y);
	    }
	    bool good = false;
	    for (int i = 0; i + 1 < t; i++) {
	        // Ignore segments that share a point with x -> y:
	        if ( points[i] == x || points[i+1] == x) continue;
	        if ( points[i] == y || points[i+1] == y) continue;

	        // p1 is true if points[i] belongs to the first partition.
	        bool p1 = ( x < points[i] && points[i] < y );
	        // p2 is true if points[i] belongs to the first partition.
	        bool p2 = ( x < points[i+1] && points[i+1] < y );

	        // Exactly one of p1,p2 must be true
	        good |= ( p1 != p2  );
	    }
	    return good;
	}

	// Use backtracking to pick the order of the points in the traversal
	// Crop when the new segment does not intersect with a previous one.
	int rec(int t)
	{
	    if (t == N) {
	        // can we go from points[N-1] to points[0] crossing something?
	        return ( cross( points[t - 1], points[0], t) ? 1 : 0);
	        // If so, we have found a good way to do it.
	    } else {
	        int res = 0;
	        for (int i = 1; i <= N; i++) {
	            // Pick a good finish point i for the next segment:
	            if ( !visited[i] && cross(points[t-1], i, t) ) {
	                // do not pick a point that was visited before.
	                // the new segment must intersect with at least one segment.

	                //  Temporarily mark the point as visited and add it to
	                // the array.
	                visited[i] = true;
	                points[t] = i;
	                res += rec(t + 1);
	                // backtrack:
	                visited[i] = false;
	            }
	        }
	        return res;
	    }
	}

	int count(int N, vector <int> points)
	{
	    this->N = N;
	    fill(visited, visited + 14, false);
	    for (int i=0; i<points.size(); i++) {
	        visited[ points[i] ] = true;
	        this->points[i] = points[i];
	    }
	    return rec( points.size() );
	}
/* My solution - NOT WORK
 * 	int backtrack(vector<int> ps, bool visited[] , int nTarget){

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
 */

};
