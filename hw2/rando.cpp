/* 
rando.cpp: Calculate the sum of eight input numbers
Created on: Feb.4, 2017
Author: Kaimeng Yang
*/

#include <iostream> 
#include <stdlib.h>
#include <time.h>
using namespace std;

void guessGame(int num_one, int num_two);

int main()
{
	int number_one, number_two;
	
	srand(time(NULL));
	number_one = ((rand() % 11) + 5);
	number_two = ((rand() % 11) + 5);

	guessGame(number_one, number_two);

	return 0;
}

void guessGame(int num_one, int num_two)
{
	int first_guess, second_guess, sum;

	sum = num_one + num_two;

	cout << "What is " << num_one << " + " << num_two << " ? " << endl;
	cin >> first_guess;

	if (first_guess == sum)
	{
		cout << "Correct. Game over! " << endl;
	}
	else 
	{
		cout << "Incorrect. Try again. What is " << num_one << " + " << num_two << " ? " << endl;
		cin >> second_guess;

		if(second_guess == sum)
		{
			cout << "Corect, game over! " << endl;
		}
		else 
		{
			cout << "Sorry, still wrong, the correct answer is " << sum << endl;
		}
	}
	
	return;
}