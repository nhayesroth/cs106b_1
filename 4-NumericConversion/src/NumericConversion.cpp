/*
 * File: NumericConversion.cpp
 * ---------------------------
 * Nathan Hayes-Roth
 * Section: Linford
 * This file implements recursive functions for inToString and stringtoInt
 * 
 */

#include <iostream>
#include <string>
#include "simpio.h"
#include "strlib.h"
using namespace std;

/* Function prototypes */
string intToString(int n);
int stringToInt(string str);

/* Main program */
int main() {
	int test1=4;
	int test2=-89;
	int test3=2340;
	cout<<"intToString("<<test1<<") = "<<intToString(test1)<<endl;
	cout<<"intToString("<<test2<<") = "<<intToString(test2)<<endl;
	cout<<"intToString("<<test3<<") = "<<intToString(test3)<<endl;
   return 0;
}

/* intToString: converts integers to strings */
string intToString(int i){
	string str;
	// zero
	if (i==0) {
		return "0";
	}
	// negative numbers
	if (i<0) {
		str="-";
		i=-i;
	}
	// i>=10
	if (i>=10){
		string tens = intToString(i/10);
		string rem = intToString(i%10);
		str+=tens+rem;
		return str;
	}
	// base case 0 < i < 10
	char ch = '0' + i;
	str += string() + ch; 
	return str;
}

/* stringToInt: converts strings to integers */
int stringToInt(string str){
	return 0;
}
