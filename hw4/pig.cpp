#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

// Function prototype: end_round                                                
int end_round(int, int &, int &, int);
// Function prototype: check_for_win                                            
int check_for_win(int, int);

// Number of points needed to win                                               
const int THRESHOLD = 20;

int roll_dice();

int main ()
{
        // Seed the random variable
        srand(time(NULL));

        // Total number of points for each player.                              
        int pone_points = 0, ptwo_points = 0;

        // Whose turn it is. Player One always starts.                          
        int turn = 1;

        // Is the game over yet                                                 
        bool game_over = false;

        // While loop for the game. A game comprises several rounds.                                             
        while( !game_over )
        {
                // Announce whose turn it is                                                                     
                cout << "Player " << turn << " is up!\n";

                // Round-specific variables                                                                      
                bool round_over = false;
                int round_points = 0;
                /****************************************                                                        
                 * YOUR CODE GOES HERE!                 *                                                        
                 ****************************************/
                while(!round_over)
                {
                        int i, roll;
                        
                        do {
                            cout << "Enter 0 to roll or 1 to hold" << endl;
                            cin >> i;
                        } while(i!= 1 && i != 0);
                        
                        if (i == 1) 
                        {
                            cout << "End of round." << endl;
               
                            if (turn == 1)
                            {
                                if (round_points + pone_points >= THRESHOLD)
                                {
                                    cout << "Player one wins!" << endl;
                                    round_over = true;
                                    game_over = true;
                                }
                            }
                            if (turn == 2)
                            {
                                if (round_points + ptwo_points >= THRESHOLD)
                                {
                                    cout << "Player two wins!" << endl;
                                    round_over = true;
                                    game_over = true;
                                }
                            }   
                            if (round_points >= THRESHOLD)
                            {
                                cout << "Player " << turn << " wins the game!" << endl;
                                round_over = true;
                                game_over = true;
                            }
                            round_over = true;
                        }
                        else
                        {   
                            roll = roll_dice();
                            cout << "You rolled a " << roll << endl;
                            if (roll == 1)
                            {
                                cout << "Round over, no points!" << endl;   
                                
                                if (turn == 1)
                                {
                                    if (round_points + pone_points >= THRESHOLD)
                                    {
                                        cout << "Player one wins!" << endl;
                                        round_over = true;
                                        game_over = true;
                                    }
                                }
                                if (turn == 2)
                                {
                                    if (round_points + ptwo_points >= THRESHOLD)
                                    {
                                        cout << "Player two wins!" << endl;
                                        round_over = true;
                                        game_over = true;
                                    }
                                }
                                if (round_points >= THRESHOLD)
                                {
                                    cout << "Player " << turn << " wins the game!" << endl;
                                    round_over = true;
                                    game_over = true;
                                }
                                round_over = true;
                            }
                            else
                            {      
                                round_points += roll;
                                
                                if (turn == 1)
                                {
                                    if (round_points + pone_points >= THRESHOLD)
                                    {
                                        cout << "Player one wins!" << endl;
                                        round_over = true;
                                        game_over = true;
                                    }
                                }
                                if (turn == 2)
                                {
                                    if (round_points + ptwo_points >= THRESHOLD)
                                    {
                                        cout << "Player two wins!" << endl;
                                        round_over = true;
                                        game_over = true;
                                    }
                                }
                                if (round_points >= THRESHOLD)
                                {
                                    cout << "Player " << turn << " wins the game!" << endl;
                                    round_over = true;
                                    game_over = true;
                                }
                                cout << "Current round points: " << round_points << endl;
                            }
                        }
                           
                }
                int result_turn = end_round(turn, pone_points, ptwo_points, round_points);
                turn = result_turn;
        
                cout << "Player 1 has " << pone_points << endl;
                cout << "Player 2 has " << ptwo_points << endl;

                if(check_for_win(pone_points, ptwo_points) == 1)
                {
                    cout << "Player 1 wins the game!" << endl;
                    game_over = true;
                }
                else if(check_for_win(pone_points, ptwo_points) == 2)
                {  
                    cout << "Player 2 wins the game!" << endl;
                    game_over = true;
                }
        } // end game while loop                                                                                 

        // Game is over. End the program.                                                                        
        cout << "Thanks for playing!\n";
        return 0;
}

int roll_dice()
{
    return (rand() % 6 + 1);
}

// FUNCTION DEFINITION                                                                                           
// Function check_for_win                                                                                        
// Arguments:                                                                                                    
//      Player 1 and 2's points (ints)                                                                           
// Returns:                                                                                                      
//      0 is game is not over                                                                                    
//      1 if player one won                                                                                      
//      2 if player two won                                                                                      
// Does:                                                                                                         
//      Compares each score to the threshold                                                                     
int check_for_win(int pone_points, int ptwo_points)
{
        // Check the players' current points against the threshold                                               
        if( pone_points >= THRESHOLD )
        {
                return 1;
        }
        else if( ptwo_points >= THRESHOLD )
        {
                return 2;
        }

        // If we didn't meet either condition,                                                                   
        // then nobody won                                                                                       
        return 0;
}

// FUNCTION DEFINITION                                                                                           
// Function end_round                                                                                            
// Arguments:                                                                                                    
//      1. whose turn it is (int)                                                                                
//      2. player one's points (int, by ref)                                                                     
//      3. player two's points (int by ref)                                                                      
//      4. round points (int)                                                                                    
// Returns:                                                                                                      
//      # of updated turn 
// Does:                                                                                                         
//      Updates p1 and p2 points                                                                                 
//      Switches whose turn it is                                                                                
int end_round(int turn, int &pone_points, int &ptwo_points, int round_points)
{
        if(turn == 1)
        {
                pone_points += round_points;
                return 2;
        }
        else{
                ptwo_points += round_points;
                return 1;
        }
}
