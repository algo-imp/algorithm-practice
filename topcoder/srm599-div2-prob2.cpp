/*
 * srm599-div2-prob2.cpp
 * Tag: prime, factorization
 *  Created on: Jun 1, 2014
 *      Author: vietnguyen
 */

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class BigFatInteger2{
	/* Topcoder solution */

	// Extract all prime factors
	// result is a map that has primes as keys and
	// their exponents as values.
public:
	map<long, long> primeFactors(int x)
	{
	    map<long, long> res;
	    // Trial division.
	    for (int p = 2; p*p <= x; p++) {
	        if (x % p == 0) {
	            long r = 0;
	            while (x % p == 0) {
	                x /= p;
	                r++;
	            }
	            res[p] = r;
	        }
	    }
	    if (x != 1) {
	        res[x] = 1;
	    }
	    return res;
	}
	string isDivisible(int A, int B, int C, int D)
	{
	    // Extract prime factors
	    auto ap = primeFactors(A);
	    auto cp = primeFactors(C);
	    // Iterate the prime factors of C
	    for (auto k: cp) {
	        // check if for each prime factor of C, its exponent
	        // multiplied by D is <=  the same for A and B.
	        if ( k.second * D > ap[k.first] * B) {
	            return "not divisible";
	        }
	    }
	    return "divisible";
	}
	/* My solution - Too slow
	 * public:
	string isDivisible(int A, int B, int C, int D){
		map<int, int> primedivisorsA, primedivisorsC;
		//Test 2 first
		while(A%2 ==0){
			A = A/2;
		}
		while(C%2 == 0){
			B = B/2;
		}
		int test = 3;
		while(test < max(A,C)){
			if(A%test == 0){
				int count = 0;
				while(A%test == 0){
					count ++;
					A = A/test;

				}
				primedivisorsA.insert(pair<int, int>(test, count));

			}
			if(C%test == 0){
				int count = 0;
				while(C%test == 0){
					count ++;
					C = C/test;
				}

				primedivisorsC.insert(pair<int, int>(test, count));
			}
			test = test + 2;
		}
		//Check
		map<int,int>::iterator it = primedivisorsC.begin();
		while(it!=primedivisorsC.end()){
			int countC = it->second;
			int countA = primedivisorsA.find(it->first) == primedivisorsA.end() ? 0 : it->second;
			if(countC * D > countA *B )
				return "not divisible";
		}
		return "divisible";
	}
	 */

};
