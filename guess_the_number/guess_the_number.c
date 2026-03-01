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
void nums_compare(int computer_num);



int main(void)
{
    //computer making random number
    srand(time(NULL));
    int computer_num  = numrandom();
    //Compare random number with player's guess + final results
    nums_compare(computer_num);

}
//Function for getting random number from 1 to 5
int numrandom(void)
{
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

//Compare function
void nums_compare(int computer_num)
{
    int player_num;
    do
    {
        player_num = playernum();

        if(computer_num < player_num)
        {
            printf("Too big!\n");
        }
        else if(computer_num > player_num)
        {
            printf("Too small!\n");
        }
    }
    while(computer_num != player_num);

    printf("You win!\n");

}