/*
 * backtrack_findgraphpath.cpp
 * Reference: 7.1.3 - The Algorithm Design Manual
 *  Created on: May 12, 2014
 *      Author: vietnguyen
 */

#include <iostream>

using namespace std;

class edgenode{
public:
	int y;			/* adjacency info */
	int weight;		/* edge weight, if any */
	struct edgenode *next;		/* next edge in list */
};

class Graph{
private:
	static const int MAXV = 1000;		/* maximum number of vertices */
public:
	edgenode *edges[MAXV+1]; 	/*adjacency info */
	int degree[MAXV+1];			/* outdegree of each vertex */
	int nvertices;				/* number of vertices in graph */
	int nedges;					/* number of edges in graph */
	bool directed;				/* is the graph directed */
};

class GraphPaths{
private:
	int MAXCANDIDATES = 100;
	int NMAX = 100;
	int finished = false;
	Graph g;
	int s, t;		/* start node and end node */
	int solution_count = 0;
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

	void construct_candidates (int a[], int k, int n, int c[], int *ncandidates){
		int i;		/* counters */
		bool in_sol[NMAX];		/* what's already in the solution? */
		edgenode *p;			/* temporary pointer */
		int last;				/* last vertex on current path */

		for (i = 1; i < NMAX; i++) in_sol[i] = false;
		for (i = 1; i<k; i++) in_sol[a[i]]= true;

		if(k==1){		/* always start from vertex 1 */
			c[0] = 1;
			*ncandidates = 1;
		}
		else{
			*ncandidates = 0;
			last = a[k-1];
			p = g.edges[last];
			while(p!=NULL){
				if(!in_sol[p->y]){
					c[*ncandidates] = p->y;
					*ncandidates = *ncandidates + 1;

				}
				p = p->next;
			}
		}
	}

	bool is_a_solution(int a[], int k, int n){
		return (a[k] == t);
	}

	void process_solution (int a[], int k){
		solution_count ++;		/* count all s to t paths */
	}

	void make_move(int a[], int k, int n){

	}

	void unmake_move(int a[], int k, int n){

	}
};

int main(){
}
