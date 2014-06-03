/*
 * srm600-div2-prob2.cpp
 *
 *  Created on: Jun 3, 2014
 *      Author: vietnguyen
 */

#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

class ORSolitaireDiv2{
public:

	/* Top Coder solution - backtrack */

	int getMinimum(vector<int> numbers, int goal)
	{
	    int n = numbers.size();
	    int res = n; // worst case: remove n cards

	    // Decided to use a c++11 lambda to avoid using class attributes/globals,
	    // sorry about that:
	    function<void(int,int,int) > backtrack = [&] (int p, int X, int removed) {
	        // p: next card to remove or not
	        // X: current OR value of remaining valid cards
	        // removed: total number of removed cards.
	        if (p == n) {
	            res = std::min(res, removed);
	        } else {
	            if ( (goal | numbers[p]) != goal ) {
	                // ignore:
	                backtrack(p + 1, X , removed);
	            } else {
	                if (removed + 1 < res) {
	                    // remove:
	                    backtrack(p + 1, X , removed + 1);
	                }
	                // don't remove:
	                if ( (X | numbers[p]) != goal ) {
	                    backtrack(p + 1, X | numbers[p], removed);
	                }
	            }

	        }

	    };
	    backtrack(0, 0, 0);
	    return res;
	}

	/* My solution - does not work */
	/*
	int getMinimum(vector<int> numbers, int goal){
		bool isInGoal[30];
		int count[30];
		int i=0;
		fill(isInGoal, isInGoal + 30, false);
		fill(count, count + 30, 0);
		while(goal !=0){
			isInGoal[i] = goal % 2 == 1 ? true : false;
			cout << goal % 2;
			goal = goal/2;
			i++;
		}
		cout << "\n";
		for(int i = 0 ; i< numbers.size(); i++){
			int test = numbers[i];
			int k = 0;
			while(test != 0){
				count[k] += (test%2 == 0? 0: 1);
				cout << test%2;
				test = test/2;
				k++;
			}
			cout << "\n";
		}
		int min = 30;
		for(int i = 0; i<30; i++){
			cout << i << ":" << isInGoal[i] << ", " << count[i] << "\n";
			if(isInGoal[i] && count[i] < min){
				min = count[i];
				cout << min << "\n";
			}
		}
		return min;
	}
	*/
};
