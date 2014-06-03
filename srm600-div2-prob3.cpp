/*
 * srm600-div2-prob3.cpp
 *
 *  Created on: Jun 2, 2014
 *      Author: vietnguyen
 */

#include <iostream>
#include <vector>

using namespace std;

class PalindromeMatrixDiv2{
public:
	int minChange(vector<string> A, int rowCount, int columnCount){
		/* Don't have solution - Think of BFS, but seems to be slow */

		/* Solution: http://apps.topcoder.com/wiki/display/tc/SRM+600 */
		  int n = A.size(), m = A[0].size();
		    int pcols[m];
		    int prows[n];
		    int res = n * m;
		    // for use with next_permutation, pcols is initially: {0,0,...,0, 1,1,...1 }
		    for (int i = 0; i < m; i++) {
		        pcols[i] = (m - i - 1 < columnCount);
		    }
		    do {
		        // for use with *nested* next_permutation,
		        // prows is initially: {0,0,...,0, 1,1,...1 }
		        for (int j = 0; j < n; j++) {
		            prows[j] = (n - j - 1 < rowCount);
		        }
		        do {
		            // did you know? Only 4900 ways to do this.
		            int cost = 0;
		            bool visited[8][8];
		            memset( visited, false, sizeof(visited) );
		            for (int i = 0; i < n; i++) {
		                for (int j = 0; j < m; j++) {
		                    if (! visited[i][j] ) {
		                        int o = 0, z = 0;
		                        // A iterative version of DFS:
		                        // count the number o of '1's and number z of '0's
		                        //  in the connected component that contains (i,j)
		                        stack<int> S;
		                        S.push(i); S.push(j);
		                        while (! S.empty() ) {
		                            // (x,y) is connected to (i,j):
		                            int y = S.top(); S.pop();
		                            int x = S.top(); S.pop();
		                            if (! visited[x][y]) {
		                                // We didn't process it before:
		                                z += (A[x][y] == '0');
		                                o += (A[x][y] == '1');
		                                visited[x][y] = true;
		                                if (pcols[y]) {
		                                    // (n - x - 1, y) is connected to (x,y):
		                                    S.push(n - x - 1); S.push(y);
		                                }
		                                if (prows[x]) {
		                                    // (x, y) is connected to (x,m - y -1):
		                                    S.push(x); S.push(m - y - 1);
		                                }
		                            }
		                        }
		                        cost += min(o, z);
		                    }
		                }
		            }
		            res = std::min(res, cost);
		        } while (next_permutation(prows, prows + n) );
		    } while (next_permutation(pcols, pcols + m) );
		    return res;
	}
};
