#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MIN 1
#define MAX 5
//Make random number(function)
int numrandom(void);
//say rules to player + Get player's answer + check if number is neggative(function)
int playernum(void);
//Compare random number with player's guess(function)
bool nums_compare(int computer_num, int player_num);



int main(void)
{
    //computer making random number
    int computer_num  = numrandom();
    //start of game
    int player_num = playernum();
    //Compare random number with player's guess
    bool game_result = nums_compare(computer_num, player_num);
    //Printing result
    if(game_result)
    {
        printf("YOU WIN!\n");
    }
    else
    {
        printf("YOU LOSE!\n");
    }
}
//Function for getting random number from 0 to 5
int numrandom(void)
{
    srand(time(NULL));
    return rand() % MAX + MIN;
}

//Function for player
int playernum(void)
{
    int x;
    do
    {
        x = get_int("Enter a number from 1 to 5: ");
    }
    while(x < MIN || x > MAX);

    return x;
}

//Function for getting bool value
bool nums_compare(int computer_num, int player_num)
{
    return computer_num == player_num;
}
