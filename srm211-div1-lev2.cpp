/**
 * TopCoder Single round Match 211 - Division I, Level Two
 * http://community.topcoder.com/stat?c=problem_statement&pm=2998
 */
#include <stack>
#include <vector>
#include <sstream>
#include "srm_header.h"

using namespace std;

class node {
public:
	int x,y;
	node(int _x, int _y){ x = _x; y = _y;}
};

vector<int> grafixMask::sortedAreas(vector<string> rectangles){

	for(int i = 0; i < 600; i++){
		for (int j = 0; j < 400; j ++){
			fill[i][j] = false;
		}
	}
	for (string s: rectangles){
		istringstream iss(s);
		int xtl, ytl, xbr, ybr; //coordinates of the top left point and the bottom right point of the rectangle
		iss >> ytl >> xtl >> ybr >> xbr;
		for (int i = xtl; i <= xbr; i++)
			for(int j = ytl; j <= ybr; j++){
				fill[i][j] = true;
			}
	}

	vector<int> result;
	for(int x=0; x < 600; x ++)
		for(int y = 0; y <  400; y++){
			if(fill[x][y] == false)
				result.push_back(doFill(x,y));
		}

	sort(result.begin(), result.end());

	return result;
}

int grafixMask::doFill(int x, int y){
	int result = 0;

	//Declare our stack of nodes, and push our starting node onto the stack
	stack<node> s;
	s.push(node(x,y));

	while(s.empty() == false){
		node top = s.top();
		s.pop();

		//Check to ensure that we are within the bounds of the grid, if not, continue
		if(top.x < 0 || top.x >= 600) continue;
		if(top.y < 0 || top.y >= 400) continue;

		//Check that we haven't already visited this position, as we don't want to count it twice
		if(fill[top.x][top.y]) continue;

		fill[top.x][top.y] = true; //Record that we have visited this node

		//We have found this node to be empty, and part of this connected area, so add 1 to the result
		result++;

		//Now we know that we have at least one empty square, then we will attempt to visit every node adjacent to this node
		s.push(node(top.x + 1, top.y));
		s.push(node(top.x - 1, top.y));
		s.push(node(top.x, top.y + 1));
		s.push(node(top.x, top.y - 1));
	}
	return result;
}

int grafixMask::test(){
	vector<string> s;
	s.push_back("48 192 351 207");
	s.push_back("48 392 351 407");
	s.push_back("120 52 135 547");
	s.push_back("260 52 275 547");
	vector<int> res = sortedAreas(s);
	for (int i : res){
		cout << i << "\t";
	}
}
