/*
 * File: Combinations.cpp
 * ----------------------
 * Name: Nathan Hayes-Roth
 * Section: Linford
 * This file computes the combination function given the integer values
 * for n and k. It also displays Pascal's triangle up to row n for clarity.
 */

#include <iostream>
#include "simpio.h"
using namespace std;

void pascalsTriangle(int n, int k);
int combination (int n, int k);

/* Main Function: reads in values for n and k,
 * calls combination to compute c(n,k),
 * and calls pascalsTriangle to display the triangle up to row n.
 */
int main() {
	cout << "Ready to compute Combinations Function." << endl<<endl	// Welcome the user
		<<"Please choose n (Pascal's Row #): ";		//
	int n;											//
	cin >> n;										// Ask for and read in values
	cout <<"And k (Pascal's Column #): ";			// for n and k
	int k;											//
	cin >> k;										//
	cout << endl << "c(" <<n <<", " << k	// Call combination and display the calculated	
		 << ") = " <<combination(n,k);		// value in an understandable way.
	cout << endl << "Pascal's Triangle Up to row n: " << endl;	// Call pascalsTriangle and
	pascalsTriangle(n,k);										// explain with a message.
	return 0;
}
//combination Function: recursively compute c(n,k)
int combination(int n, int k) {
	if (k == 0) return 1;	// first column is always 1 and avoid negative column errors
	if (n == 0) return 0;	// avoid negative row errors
	return combination(n - 1, k - 1) + combination(n - 1, k);
}

//pascalsTriangle Function: displays Pascal's Triangle up to row n
void pascalsTriangle(int n, int k){
	for (int row=0; row<=n; row++){		//at each row
		for (int column=0; column<=row; column++){		// step through as many columns as there are rows
			cout << combination(row,column)<<" ";	//and print out c(n,k) for that index
		}
		cout << endl;	// jump to next row of triangle
	}
}