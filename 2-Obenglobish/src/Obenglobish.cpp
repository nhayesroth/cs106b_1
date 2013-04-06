/*
 * File: Obenglobish.java
 * ----------------------
 * Name: Nathan Hayes-Roth
 * Section: Linford
 * This program will read in a word and translate it to Obenenglobish.
 */

#include <iostream>
#include <string>
#include "simpio.h"
#include "strlib.h"
using namespace std;

string wordToObenglobish (string word);	//translates word
bool isVowel(char ch);		//checks a character's nature

/* Main program 
* Displays text, asking for a word to be translated.
* Accepts the input word and passes it to wordToObenglobish for translation.
* Displays the translated word.
*/
int main() {
   cout << "Ready to learn Obenglobish?" << endl;
   string word;
   cout << "What would you like translated? ";
   getline (cin, word);
   string translation = wordToObenglobish(word);
   cout << "Translation: " << translation << endl;
   return 0;
}

/* Translation program */
string wordToObenglobish (string word){
	string result = "";
	for (int i = 0; i < word.length(); i++){	//steps through the word
		char c = word[i];
		if (isVowel(c)){	//standard obenglobish requirement
			if (i==0){
				cout<<"test";
				result = result + "ob" + c; //if it's the first letter, it can't 
											//violate either of the two exceptions
			}
			else if (isVowel(word[i-1])){	//rule #1
				result = result + c;
			} 
			else if (c == 'e' && i == word.length()-1){	//rule #2
				result = result + c;
			} 
			else{
				result = result + "ob" + c;	//meets requirements
			}
		}
		else{
			result = result + c;
		}
	}
	return result;
}

/* vowel checker 
*Note: 'Y' is not considered a vowel in this implementation.
*/
bool isVowel(char ch){
	if (ch == 'a' ||
		ch == 'e' ||
		ch == 'i' ||
		ch == 'o' ||
		ch == 'u'){
			return true;
	} 
	return false;
}
