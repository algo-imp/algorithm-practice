/*
 * codeforces-round225-div1-A.cpp
 *
 *  Created on: Mar 29, 2014
 *      Author: vietnguyen
 */

#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> a(n+1);
	vector<int> left(n+1);	//number of cows scared on the left
	vector<int> right(n+1); //number of cows scared on the right
	left[1] = 0;
	for(int i = 1; i <=n; i++){
		cin >> a[i];
		if(a[i] == 0 & i!=1)
			right[1] ++;
	}

	cout << "i: 1; left: " << left[1] << "; right: " << right[1] << "\n";
	for(int i = 2; i<=n; i++){
		left[i] = left[i-1] + a[i-1];
		right[i] = right[i-1] -(1-a[i]);
		cout << "i: " << i << "; left: " << left[i] << "; right: " << right[i] << "\n";
	}

	int milkLost = 0;
	vector<int> visited(n+1);
	for(int i=1;i<=n;i++){
		visited[i] = false;
	}
	for(int round = 1; round <=n; round++){
		int minSum = n;
		int index = 1;
		for(int i = 1; i<=n; i++){
			if(visited[i] == true) continue;
			if(minSum>left[i] + right[i]){
				minSum = left[i] + right[i];
				index = i;
			}
		}
		cout << "index = " << index << "\n";
		milkLost += (left[index] + right[index]);
		cout << "milk lost: " << milkLost << "\n";
		if(a[index] == 1){
			for(int i = index + 1; i <= n ; i++){
				left[i] --;
				cout << "\ti:" << i << "left:" << left[i] << "\n";
			}
		}else{
			for(int i = 1; i < index; i++){
				right[i] --;
				cout << "\ti:" << i << "right:" << right[i] << "\n";
			}
		}
		visited[index] = true;

	}
	cout << milkLost;

}
