/* 
average.cpp: compute the average of an int array
Created on: March.8, 2017
Author: Kaimeng Yang
*/

#include <iostream>
using namespace std;

const int MAX = 5;

void average(int array[]);

int main()
{
	int array[MAX];

	cout << "Please enter 5 integers:" << endl;
	
	for(int i = 0; i < MAX; i++)
	{
		cin >> array[i];
	}

	average(array);

	return 0;
}

void average(int array[MAX])
{
	double sum, avg = 0;

	for(int i = 0; i < MAX; i++)
	{
		sum += array[i];
	}

	avg = sum / MAX;

	cout << "The average is: " << avg << endl;

	return;
}