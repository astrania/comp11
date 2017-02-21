/* 
rock.cpp: rock, scissors, paper game for three rounds between two p1s
Created on: Feb.17, 2017
Author: Kaimeng Yang
*/
#include <iostream>
using namespace std;

void play_game();

int main()
{
    cout << "3 rounds of play. The player with the most points at the end wins. Let's go! " << endl;

    play_game();

    return 0;
}

void play_game()
{
    char p1, p2; // character entered
    int pts1 = 0, pts2 = 0; // points for each player

    for(int i = 0; i < 3; i++)
    {
        // prompt the user to reenter if input is invalid
        do
        {
            cout << "Player one: R, S, or P?" << endl;
            cin >> p1;
        } while(p1 != 'R' && p1 != 'S' && p1 != 'P'); 

        do
        {
            cout << "Player two: R, S, or P?" << endl;
            cin >> p2;
        } while(p2 != 'R' && p2 != 'S' && p2 != 'P');

        if (p1 == 'R' && p2 == 'R')
        {   
            cout << "Rock for everyone. Tie." << endl;
        }
      
        else if (p1 == 'R' && p2 == 'S')
        {
            cout << "Rock smashes scissors. Player 1 wins." << endl;
            pts1++;
        }
    
        else if (p1 == 'R' && p2 == 'P')
        {
            cout << "Paper covers rock. Player 2 wins." << endl;
            pts2++;
        }
      
        else if (p1 == 'P' && p2 == 'P')
        {
            cout << "Paper for everyone. Tie." << endl;
        }
      
        else if (p1 == 'P' && p2 == 'S')
        {
            cout << "Scissors cut paper. Player 2 wins." << endl;
            pts2++;
        }
      
        else if (p1 == 'P' && p2 == 'R')
        {
            cout << "Paper covers rock. Player 1 wins." << endl;
            pts1++;
        }
      
        else if (p1 == 'S' && p2 == 'S')
        {
            cout << "Scissors for everyone. Tie." << endl;
        }
      
        else if (p1 == 'S' && p2 == 'P')
        {
            cout << "Scissors cut paper. Player 1 wins." << endl;
            pts1++;
        }
      
        else if (p1 == 'S' && p2 == 'R')
        {
            cout << "Rock smashes scissors. Player 2 wins." << endl;
            pts2++;
        }
    }
    
    if (pts1 > pts2)
    {
        cout << "Player one wins with " << pts1 << " points!" << endl;
    }
    else if(pts1 == pts2)
    {
        cout << "Wow, tie. Both of you have " << pts1 << " points!" << endl;
    } 
    else 
    {
        cout << "Player two wins with " << pts2 << " points!" << endl;
    }

    return;
}