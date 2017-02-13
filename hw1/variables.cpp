/* 
Variables.cpp: Calculate the sum of eight input numbers
Created on: Jan.27, 2017
Author: Kaimeng Yang
*/

#include <iostream> 
using namespace std;

/* 
use three variables: num stores the number each time the user enters, 
sum calculates the sum of all input numbers, and counter tracks the number 
of input numbers from 0 up to 7. The program interacts with user by asking 
him to enter eight numbers,and prints out a message when the sum of the 
eight numbers is calculated. 
*/

int main(){     
	int num;     
	int sum = 0;
	int counter = 0;

	while (counter < 8) { 
		cout << "Please enter a number: " << endl; 
		cin >> num;
		sum += num; 
		counter++; 
	}

	cout << "The sum is: " << sum;

    return 0; 
}
