/* 
nim.cpp: Computer player and human player take turns to remove beans from a pile.
		 Who removes the last bean lost the game. There are 3 rounds in total, 
		 and there's a winner for each round, and an overall winner. 
Created on: Feb.17, 2017
Author: Kaimeng Yang
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void who_to_start(char c);
int beans_gen();

int main()
{
	char input;
	srand((unsigned int)time(NULL));

	do{    	
    	cout << "Welcome to Nim. I’ll flip a coin.";
    	cout << "Heads or tails(Enter 'h' or 't')?" << endl;
    	cin >> input;
	}while(input != 'h' && input != 't');

	who_to_start(input);

    return 0;
}

int beans_gen()
{
	return (rand() % 26 + 5);
}

// generate a random number, either one or zero
int toss_gen()
{
	return (rand() % 2);
}

// computer's pick of the number of beans for its move
int computer_pick()
{
	return (rand() % 3 + 1);
}

void who_to_start(char input)
{
	int i = 1; // game rounds
	int win_1 = 0, win_2 = 0; // rounds of winning
	int num;

	// let us assign 0 to "heads", and 1 to "tails"
	int toss = toss_gen();
	
	// only reassign toss's value in the two circumstances below
	if (toss == 0 && input == 't')
	{
		toss = 1;
	}
	if (toss == 1 && input == 't')
	{
		toss = 0;
	}

	while(i < 4){
		int beans = beans_gen();
		int curr_beans = beans;

		cout << "Game " << i << ": ";
		do{
		    // I move
			if(toss == 0){ 
				cout << "There are " << curr_beans << " beans." << endl;
				do{
					cout << "How many do you want to take?" << endl;
					cin >> num;
				}while((num != 1 && num!= 2 && num!= 3) || (num > curr_beans));

				curr_beans -= num;
			}
			// Computer moves
			else {
				do{
					num = computer_pick();
				}while((num != 1 && num!= 2 && num!= 3) || (num > curr_beans));

				cout << "There are " << curr_beans << " beans. I'll take " << num << "." << endl;
				curr_beans -= num;
			}
			toss = (toss + 1) % 2;     // switch player
		}while(curr_beans > 0);
		
		// who removes the last bean losses
		if(toss == 0)
		{
			cout << "You win! " << endl;
			win_1++;
		}
		if(toss == 1)
		{
			cout << "I(Computer) win! " << endl;
			win_2++;
		}
		toss = (toss + 1) % 2;  // switch player in the next round
		i++; 
	}
	
	// overall winner
	if(win_1 > win_2)
	{
		cout << "Congrats! You are the overall winner! " << endl;
	}
	else 
	{
		cout << "You lost. I(Computer) am the overall winner!" << endl;
	}

	return;
}
