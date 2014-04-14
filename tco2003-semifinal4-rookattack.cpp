/*
 * tco2003-semifinal4-rookattack.cpp
 * Problem Statement: http://community.topcoder.com/stat?c=problem_statement&pm=1931&rd=4709
 *  Created on: Apr 10, 2014
 *      Author: vietnguyen
 */

#include <iostream>
#include <vector>
#include <deque>
#include <stdio.h>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;
class RookAttack
{
	// a list of the non-empty squares for each row
	vector<int> lst[300];
	//in this arrays we keep matches found to every row and column
	int row_match[300], col_match[300];
	//we search for an augmenting path starting with row source
	bool find_match(int source){
		// from[x] = the row-vertex that precedes x in the path
		int from[300], where, match;
		for(int i = 0; i < 300; i++){
			from[i] = -1;
		}
		//memset (from, -1, sizeof(from));
		from[source] = source;
		deque<int> q;
		q.push_back(source);
		bool found_path = false;
		while(!found_path && !q.empty()){
			//where = current row-vertex we are in
			where = q.front();
			q.pop_front();
			//we take every uncut square in the current row
			for (int i = 0; i < lst[where].size(); ++ i){
				match = lst[where][i];
				//next = the row matched with column match
				int next = col_match[match];
				if (where!=next){
					// no row matched with column match thus we found an augmenting path
					if(next == -1){
						found_path = true;
						break;

					}
					//a check whether we already visited the row-vertex next
					if(from[next] == -1){
						q.push_back(next);
						from[next] = where;
					}
				}
			}
		}
		if(!found_path)
			return false;
		while(from[where] != where){
			//we de-match where from its current match (aux) and match it with match
			int aux = row_match[where];
			row_match[where] = match;
			col_match[match] = where;
			where = from[where];
			match = aux;

		}
		//at this point where = source
		row_match[where] = match;
		col_match[match] = where;
		return true;
	}

public:
	int howMany(int rows, int cols, vector<string> cutouts){
		//build lst from cutouts; column j shoud appear in row's i list if square(i,j) is present on the board
		for(int r = 0; r < rows; r++){
			for(int c = 0; c < cols; c++ ){
				lst[r].push_back(c);
			}
		}
		for (int i = 0; i < cutouts.size(); i++){
			string s = cutouts[i];
			istringstream in(s);
			int row, col;
			in >> row;
			in >> col;
			std::vector<int>::iterator pos = std::find(lst[row].begin(), lst[row].end(), col);
			if(pos != lst[row].end())
				lst[row].erase(pos);
		}
		int ret = 0;
		for(int i = 0; i < 300; i++){
			row_match[i] = -1;
		}
		for(int i = 0; i < 300; i++){
			col_match[i] = -1;
		}
		//we try to find a match for each row
		for(int i = 0; i <rows; ++ i)
			ret+=find_match(i);
		return ret;
	}
};

int main(){
	return 0;

}
