/*
 * subset_backtrack.cpp
 *	Reference: Chapter 7 - The Algorithm Design Manual
 *  Created on: May 12, 2014
 *      Author: vietnguyen
 */

#include <iostream>

using namespace std;

class Subset{
private:
	int NMAX = 100;
	int MAXCANDIDATES = 2;
	bool finished = false;		/* found all solution yet */
public:
	void backtrack (int a[], int k, int input){
		int c[MAXCANDIDATES];	/* candidate for next position */
		int ncandidates;		/* next position candidate count */
		int i;					/* counter */
		if (is_a_solution(a,k,input)){
			process_solution(a, k , input);
		}else{
			k = k + 1;
			construct_candidates (a, k, input, c, &ncandidates);
			for (i = 0; i< ncandidates; i++){
				a[k] = c[i];
				make_move(a,k,input);
				backtrack(a,k,input);
				unmake_move(a,k,input);
				if(finished) return;
			}
		}
	}

	void make_move(int a[], int k, int n){

	}

	void unmake_move(int a[], int k, int n){

	}
	bool is_a_solution(int a[], int k, int n){
		return (k==n);		/* is k == n? */
	}

	void construct_candidates(int a[], int k, int n, int c[], int *ncandidates){
		c[0] = true;
		c[1] = false;
		*ncandidates = 2;
	}

	void process_solution(int a[], int k, int n){
		int i;			/* counter */
		cout << "{";
		for (i = 1; i<=k; i++){
			if (a[i] == true) cout << i ;
			else cout << " ";

			if(i < k) cout << ", ";
		}
		cout << "}\n";
	}

	void generate_subsets(int n){
		int a[NMAX];
		backtrack(a,0,n);
	}
};

int main(){
	Subset s;
	s.generate_subsets(10);
}
