/* 
wordsort.cpp: sort three words and list them in alphabetical order
Created on: Feb.3, 2017
Author: Kaimeng Yang
*/

/*
Test input: cat, dog, wolf
* Expected output: cat, dog, wolf
*
* Test input: monday, friday, wednesday
* Expected output: friday, monday, wednesday
*
* Test input: jack, chole, chris
* Expected output: chole, chris, jack
*/

#include <iostream> 
#include <string>
using namespace std;
	
int main () {
	string list[3];
	
	cout << "please enter three words" << endl;
	cin >> list[0] >> list[1] >> list[2];

	if (list[0].compare(list[1]) > 0) swap(list[0], list[1]);
	if (list[0].compare(list[2]) > 0) swap(list[0], list[2]);
	if (list[1].compare(list[2]) > 0) swap(list[1], list[2]);
	
	cout << list[0] << " " << list[1] << " " << list[2] << endl;

	return  0;
}

