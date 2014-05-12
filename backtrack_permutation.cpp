/*
 * backtrack_permutation.cpp
 * Reference: Chapter 7 - The Algorithm Design Manual
 *  Created on: May 12, 2014
 *      Author: vietnguyen
 */

#include <iostream>

using namespace std;

class Permutation{
private:
	int MAXCANDIDATES = 100;
	int NMAX = 100;
	bool finished = false;
public:
	void backtrack(int a[], int k, int input){
		int c[MAXCANDIDATES];
		int ncandidates;
		int i;

		if (is_a_solution(a,k,input)){
			process_solution(a,k);
		}
		else{
			k = k+1;
			construct_candidates(a,k,input,c,&ncandidates);
			for(i=0; i<ncandidates; i++){
				a[k] = c[i];
				make_move(a,k,input);
				backtrack(a,k,input);
				unmake_move(a,k,input);
				if(finished) return;	/* terminate early */
			}
		}
	}

	bool is_a_solution(int a[], int k, int n){
		return (k==n);	/* is k == n */
	}

	void construct_candidates(int a[], int k, int n, int c[], int *ncandidates){
		bool in_perm[NMAX];		/* who is in the permutation */
		for (int i = 1; i < NMAX; i++) in_perm[i] = false;
		for	(int i = 0; i < k; i++) in_perm[a[i]] = true;

		*ncandidates = 0;
		for (int i = 1; i <=n; i++){
			if(in_perm[i] == false){
				c[*ncandidates] = i;
				*ncandidates = *ncandidates + 1;
			}
		}
	}

	void process_solution(int a[], int k){
		for(int i = 1; i<=k; i++){
			cout << a[i];
		}
		cout << "\n";
	}

	void generate_permutations(int n){
		int a[NMAX];
		backtrack(a,0,n);
	}

	void make_move(int a[], int k, int n){

	}

	void unmake_move(int a[], int k, int n){

	}
};

int main(){
	Permutation p;
	p.generate_permutations(9);
}
