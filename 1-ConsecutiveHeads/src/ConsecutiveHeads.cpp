/*
 * File: ConsecutiveHeads.cpp
 * --------------------------
 * Name: [Nathan Hayes-Roth]
 * Section: [Tom Linford]
 * This file is the starter project for the coin-flipping problem.
 */

#include <iostream>
#include <string>
#include "random.h"
using namespace std;

string face(int coin);	//replace number with face name
 int flips=0;			//# of flips
 int consHeads=0;		//# of consecutive heads
 int coin=0;			//numeric representation of face

int main() {
	for (int i = 0; consHeads <= 3; i++){	//run until 3 consecutive heads
		flips++;							//increment flips
		srand( time( NULL ) );
		coin=rand()%2;						//simulate coin flip
		cout<<"flip#: "<<flips<<			//print information
			"   "<<face(coin)<<endl;
		if (coin==1)						//got heads
			consHeads++;
		if (coin==0)						//got tails
			consHeads=1;		
	}
	cout<<"It took "<<flips<< " flips to get 3 consecutive heads";
	return 0;
}

string face(int coin){
	if (coin==0) return "tails";	//0=>tails
	else return "heads";			//1=>heads
}