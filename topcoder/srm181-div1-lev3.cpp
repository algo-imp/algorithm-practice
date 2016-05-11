/*
 * srm181-div1-lev3.cpp
 *
 *  Created on: Mar 18, 2014
 *      Author: vietnguyen
 * 		Problem:
http://community.topcoder.com/stat?c=problem_statement&pm=2288&rd=4725
 */

#include <iostream>
#include <queue>

using namespace std;
class KiloManX{
public:
	int leastShots(vector<string> damageChart, vector<int> bossHealth);
    void test();
};

bool visited[32768];

class nodeKilo{

public:
	int weapons;
	int shots;
	nodeKilo(int _weapons, int _shots){
		weapons = _weapons;
		shots = _shots;
	}
	//Define a comparator that puts nodes with less shots on top appropriate to your language

};
bool operator<(const nodeKilo& leftNode, const nodeKilo& rightNode){
	if(leftNode.shots != rightNode.shots) return (leftNode.shots < rightNode.shots);
	return false;
}

int KiloManX::leastShots(vector<string> damageChart, vector<int> bossHealth){
	priority_queue<nodeKilo> pq;
	int numberWeapons = 15;

	pq.push(nodeKilo(0,0));

	while(pq.empty() == false){
		nodeKilo top = pq.top();
		pq.pop();

		//Make sure we don't visit the same configuration twice
		if(visited[top.weapons]) continue;
		visited[top.weapons] = true;

		//A quick trick to check if we have all the weapons, meaning we defeated all the bosses.
		// We use the fact that (2^numberWeapons - 1) will have all the numWeapons bits set to 1
		if(top.weapons == (1 << numberWeapons) - 1)
			return top.shots;

		for(int i = 0; i < damageChart.size(); i++){
			//Check if we've already visited this boss, then don't bother trying him again
			if(top.weapons >> i & 1) continue;

			//Now figure out what the best amount of time that we can destroy this boss is, given the weapons we have
			//We initialize this value to the boss'health, as that is our default (with our KiloBuster).
			int best = bossHealth[i];
			for(int j=0; j<damageChart.size(); j++){
				if(i==j) continue;
				if(((top.weapons >> j) & 1) && damageChart[j][i] != '0'){
					//We have this weapon, so try using it to defeat this boss
					int shotsNeeded = bossHealth[i] / (damageChart[j][i] - '0');
					if(bossHealth[i] % (damageChart[j][i]-'0') != 0) shotsNeeded ++;
					best = min(best, shotsNeeded);

				}
			}

			//Add the new node to be searched, showing that we defeated boss i, and we used 'best' shots to defeat him
			pq.push(nodeKilo(top.weapons | (1<<i), top.shots + best));

		}
	}
}

int main(){
	string in[] = {"1542", "7935", "1139", "8882"};
	vector<string> damageChart(in, in + sizeof(in) / sizeof(in[0]));
	int in2[] = {150,150,150,150};
	vector<int> bossHealth(in2, in2 + sizeof(in2) / sizeof(in2[0]));
	KiloManX km;
	cout << km.leastShots(damageChart, bossHealth) << "\n";

}
