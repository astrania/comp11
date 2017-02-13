/* 
Trick99.cpp: There are two players in the “99 trick”, one to 
predict the answer, and one to put in a number upon which some 
calculations will result in the predicted answer.
Created on: Jan.27, 2017
Author: Kaimeng Yang
*/

#include <iostream>
using namespace std;

int main(){
	// declalration, use answer_two_temp to store a temporary value 
	// of answer_two in the middle calculation steps
	int answer_one, answer_two, answer_two_temp, factor;
	
	// store 99("subtracting 99 from the predicted answer") into num_one, 
	// store 100("removes the hundreds digit") into num_two;
	// store 1("the unit digit") into num_three
	// make them const so that they won't change values
	const int num_one = 99, num_two = 100, num_three = 1;

	cout << "Player one, enter a number between 10-49: " << endl;
	cin >> answer_one;
	cout << "Player two, enter a number between 50-99: " << endl;
	cin >> answer_two;

	factor = num_one - answer_one;
	answer_two_temp = answer_two + factor;
	answer_two_temp = answer_two_temp - num_two;
	answer_two_temp = answer_two_temp + num_three;
	answer_two = answer_two - answer_two_temp;

	cout << "Actual result: " << answer_two << endl;

	if (answer_two == answer_one){
		cout << "And voila! Player 1's answer was right!" << endl;
	}
	else { 
		cout << "Oops, this is not the predicted answer!" << endl;
	}

	return 0;
}
