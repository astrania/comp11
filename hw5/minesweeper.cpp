/* COMP11
 * Spring 2017
 * Starter code - HW5 */

#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;

const int DIMEN = 9;
const int MAX_MINES = 50;
const char MINE = 'x';
const char UNSEEN = '-';

// lower bound for the board index
const int LOWER = 0;

// actual non mines generated
int ACTUAL_NON_MINES;

// function prototypes
void print_board(char [][DIMEN]);
void populate_plain_board(char [][DIMEN]);
void populate_mines(char [][DIMEN]);
void count_vici_mines(int, int, char[][DIMEN], char[][DIMEN]);
bool validity(int, int, char [][DIMEN]);
bool check_losing(int, int, char[][DIMEN], char [][DIMEN]);
bool check_winning(char[][DIMEN], char [][DIMEN]);
bool is_empty(int, int);

int main()
{
    srand(time(NULL));

    char user_board[DIMEN][DIMEN];
    char mines[DIMEN][DIMEN];
    int row, col;
    bool game_over = false;

    populate_plain_board(user_board);
    populate_mines(mines);

    cout << "Let's play minesweeper!\n";
    print_board(user_board);

    while(!game_over)
    {
        do{
            cout << "Enter a row and column number";
            cout << " of the square to uncover" << endl;
            cin >> row >> col;
        } while(validity(row,col,user_board) == false);

        count_vici_mines(row, col, user_board, mines);

        if (check_losing(row, col, user_board, mines) == true)
        {
            cout << "OH NO YOU HIT A MINE GAME OVER!" << endl;
            print_board(user_board);
            game_over = true;
            break;
        }

        if (check_winning(user_board, mines) == true)
        {
            cout << "YOU WON!!!!" << endl;
            game_over = true;
            break;
        }
    }
    
    return 0;
}

void populate_plain_board(char board[][DIMEN])
{
    for (int i = 0; i < DIMEN; i++)
    {
        for (int j = 0; j < DIMEN; j++)
        {
            board[i][j] = UNSEEN;
        }
    }
}

// random number generator, generates 1 or 0
// if 0, not place the mine in the square
// if 1, places the mine 
int mines_gen()
{
    return (rand() % 2);
}

void populate_mines(char mines_board[][DIMEN])
{
    int curr_mines = 0; 
    int k;

    for (int i = 0; i < DIMEN; i++)
    {
        for (int j = 0; j < DIMEN; j++)
        {
            k  = mines_gen();
            if (k == 1 && curr_mines < MAX_MINES)
            {
                    mines_board[i][j] = MINE;
                    curr_mines++;
            }
            else
            {
                mines_board[i][j] = UNSEEN;
            }
        }
    }

    ACTUAL_NON_MINES = DIMEN * DIMEN - curr_mines;
    print_board(mines_board);
}

void print_board(char board[][DIMEN])
{
    cout << "  ";
    for (int i = 0; i < DIMEN; i++)
        cout << i << " ";
    cout << endl;

    for (int i = 0; i < DIMEN; i++)
    {
        cout << i << " ";
        for (int j = 0; j < DIMEN; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// verify user input
bool validity(int num1, int num2, char board[][DIMEN])
{
    if (num1 < DIMEN && num1 >= LOWER && num2 < DIMEN 
        && num2 >= LOWER && board[num1][num2] !='0' 
        && board[num1][num2] !='1' && board[num1][num2] != '2' 
        && board[num1][num2] !='3' && board[num1][num2] != '4' 
        && board[num1][num2] !='5' && board[num1][num2] !='6'
        && board[num1][num2] !='7' && board[num1][num2] !='8')    
    {   
        return true;
    }
    else 
    {   
        return false;
    }
}

bool is_empty(int num1, int num2)
{
    if (num1 > DIMEN - 1 || num1 < LOWER || num2 > DIMEN - 1 
        || num2 < LOWER)
    {
            return false;
    }
    else
    {
        return true;
    } 
}

// count the number of vicinity mines for the selected square
// update and reveal the number accordingly 
void count_vici_mines(int num1, int num2, char board[][DIMEN], char mines_board[][DIMEN])
{
    int count = 0;
    int i,j;

    i = num1; 
    j = num2;

    if(is_empty(i, j-1) != false && mines_board[i][j-1]== MINE) count++;
    if(is_empty(i-1, j-1) != false && mines_board[i-1][j-1] == MINE) count++;
    if(is_empty(i+1, j-1) != false && mines_board[i+1][j-1] == MINE) count++;
    if(is_empty(i-1, j) != false && mines_board[i-1][j] == MINE) count++;
    if(is_empty(i+1, j) != false && mines_board[i+1][j] == MINE) count++;
    if(is_empty(i, j+1) != false && mines_board[i][j+1] == MINE) count++;
    if(is_empty(i-1, j+1) != false && mines_board[i-1][j+1] == MINE) count++;
    if(is_empty(i+1, j+1) != false && mines_board[i+1][j+1] == MINE) count++;

    switch(count)
    {
        case 0: board[i][j] = '0'; break;
        case 1: board[i][j] = '1'; break;
        case 2: board[i][j] = '2'; break;
        case 3: board[i][j] = '3'; break;
        case 4: board[i][j] = '4'; break;
        case 5: board[i][j] = '5'; break;
        case 6: board[i][j] = '6'; break;
        case 7: board[i][j] = '7'; break;
        case 8: board[i][j] = '8'; break;
    }
    print_board(board);
}

// reveals all mines when the player hits one mine
// return true for losing the game
bool check_losing(int num1, int num2, char board[][DIMEN], char mines_board[][DIMEN])
{
    if (mines_board[num1][num2] == MINE)
    {
        for (int i = 0; i < DIMEN; i++)
        {
            for (int j = 0; j < DIMEN; j++)
            {
                if(mines_board[i][j] == MINE)
                {
                    board[i][j] = MINE;
                }
            }
        }
        return true;
    }
    return false;
}

// the player wins if he uncovers all the squares that do not have mines in them
// return true for winning the game
bool check_winning(char board[][DIMEN], char mines_board[][DIMEN])
{
    int non_mines_count = 0;

    for (int i = 0; i < DIMEN; i++)
    {
        for (int j = 0; j < DIMEN; j++)
        {
            if((mines_board[i][j] == UNSEEN) && (board[i][j] != UNSEEN))
            {
                non_mines_count++;
            }
        }
    }

    if(non_mines_count == ACTUAL_NON_MINES)
    {
        return true;
    }
    else
    {
        return false;
    }
}
