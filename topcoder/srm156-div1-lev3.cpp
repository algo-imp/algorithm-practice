/**
 * TopCoder Single round Match 156 - Division I, Level three
 * http://topcoder.bgcoder.com/print.php?id=180
 */

#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include "srm_header.h"

class node{
public:
	int player1X, player1Y, player2X, player2Y;
	int steps; // The current number of steps we have taken to reach this step

};


bool visited[20][20][20][20];

void pushToQueue(queue<node> &q, node v){
	//Check if player 1 or player 2 is out of bounds, or on an X square, if so continue
	if(v.player1X<0 || v.player1X >= 20 || v.player2X < 0 || v.player2X >= 20 ||
			v.player1Y < 0 || v.player1Y >= 20 || v.player2Y < 0 || v.player2Y >= 20){
		return;
	}


	if(visited[v.player1X][v.player1Y][v.player2X][v.player2Y]) return;
	q.push(v);
	visited[v.player1X][v.player1Y][v.player2X][v.player2Y] = true;
}

void PathFinding::test(){

	vector<string> strTest ;
	strTest.push_back("....");
	strTest.push_back(".A..");
	strTest.push_back("..B.");
	strTest.push_back("....");
	cout << minTurns(strTest);

}

int PathFinding::minTurns(vector<string> board){
	int width = board[0].length();
	int height = board.size();

	for(int i = 0; i < 20; i ++){
		for(int j = 0; j < 20; j ++){
			for(int k = 0; k < 20; k ++){
				for(int l = 0; l < 20; l ++){
					visited[i][j][k][l] = false;
				}
			}
		}
	}

	node start;
	start.steps = 0;
	//Find the initial position of A and B, and save them in start
	for(int i=0;i<height; i ++){
		for (int j = 0; j < width; j++){
			if(board[i][j] == 'A'){
				start.player1X = i;
				start.player1Y = j;
				cout << "A:" << i << "\t" << j << "\n";
			}
			else if(board[i][j] == 'B'){
				start.player2X = i;
				start.player2Y = j;
				cout << "B:" << i << "\t" << j << "\n";
			}
		}
	}

	queue<node> q;
	pushToQueue(q,start);
	while(q.empty() == false){
		node top = q.front();
		q.pop();

		cout << top.player1X << "\t" << top.player1Y << "\t" << top.player2X << "\t" << top.player2Y << "\n";

		//Check if player 1 or player 2 is out of bounds, or on an X square, if so continue
		if(top.player1X<0 || top.player1X >= height || top.player2X < 0 || top.player2X >= height ||
				top.player1Y < 0 || top.player1Y >= width || top.player2Y < 0 || top.player2Y >= width){
			continue;
		}

		//Check if player 1 or player 2 is on top of each other, if so continue
		if(board[top.player1X][top.player1Y] == 'X' || board[top.player2X][top.player2Y] == 'X'){
			continue;
		}

		//Check if the current positions of A and B are t he opposite of what they were in start
		//If they are we have exchanged positions and are finish!
		if(top.player1X == start.player2X && top.player1Y == start.player2Y &&
			top.player2X == start.player1X && top.player2Y == start.player1Y)
			return top.steps;

		//Now we need to generate all of the transitions between nodes, we can do this quite easily using some nested for loops, one
		// for each direction that it is possible for one player to move. Since we need
		// to generate the following deltas: (-1,-1), (-1,0), (-1,1), (0,-1), (0,0), (0,1), (1,-1), (1,0), (1,1)
		// we can use a for loop from -1 to 1 to do exactly that
		for(int player1XDelta = -1 ; player1XDelta <= 1; player1XDelta ++){
			for(int player1YDelta = -1; player1YDelta <= 1; player1YDelta ++){
				for(int player2XDelta = -1; player2XDelta <=1; player2XDelta ++ ){
					for(int player2YDelta = -1; player2YDelta <=1; player2YDelta ++){
						//careful though! We have to make sure that player 1 and 2 did not swap positions on this turn
					      if (top.player1X == top.player2X + player2XDelta && top.player1Y == top.player2Y + player2YDelta &&
					         top.player2X == top.player1X + player1XDelta && top.player2Y == top.player1Y + player1YDelta)
					    	  continue;
					      cout << "Add new node: " << top.player1X + player1XDelta << "\t" << top.player1Y + player1YDelta << "\t" <<
					              top.player2X + player2XDelta << "\t" << top.player2Y + player2YDelta << "\n";

					      //Add the new node into the queue
					      node temp;
					      temp.player1X = top.player1X + player1XDelta;
					      temp.player1Y = top.player1Y + player1YDelta;
					      temp.player2X = top.player2X + player2XDelta;
					      temp.player2Y = top.player2Y + player2YDelta;
					      temp.steps = top.steps + 1;
					      pushToQueue(q, temp );
					}
				}
			}
		}
	}

	//It is not possible to exchange positions, so
	// we return -1. This is because we have explored all the states
	// possible from the starting state,
	// and haven't returned an answer yet
	return -1;
}
