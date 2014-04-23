/*
 * kmp.cpp
 * An implementation of Knuth-Morris-Pratt string matching algorithm
 * From the book: Introduction to algorithms, Cormen et al.
 *  Created on: Apr 23, 2014
 *      Author: vietnguyen
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class kmp{
public:
	void kmpmatcher(string T,  string P){
		int n = T.length();
		int m = P.length();
		cout << n << "\t" << m <<"\n";
		vector<int> pi = computeprefixfunction(P);

		int q = 0;		//number of characters matched
		for (int i = 0; i < n; i++){	//scan the text from left to right
			while( q > 0 && P[q] != T[i]){
				q = pi[q];				//next character does not match
			}
			if(P[q] == T[i]){
				q = q+1;				//next character matches
			}
			if(q == m){					// is all of P matched?
				cout << "Pattern occurs with shift: " << (i-m+1) << "\n";
				q = pi[q];				// look for the next match
			}
		}

	}

	vector<int> computeprefixfunction(const string&  P){
		int m = P.length();
		vector<int> pi;
		pi.push_back(0); //dummy
		pi.push_back(0);
		int k = 0;
		for (int q = 2; q <= m; q++){
			while(k>0 && P[k+1] != P[q]){
				k = pi[k];
			}
			if(P[k+1] == P[q]){
				k = k + 1;
			}
			pi.push_back(k);

		}
		return pi;
	}
};

int main(){
	kmp test;
	string T("abcabckcjvkajvk;zxasbabnkljfkalfdkabaklk;kl;klklfjkljfdskl;fkljkwebvdavvavdkjvcvklweab");
	string P("fk");
	test.kmpmatcher(T,P);
	return 0;
}
