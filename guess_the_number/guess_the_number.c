#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>



//Choose difficulty(function)
int choose_difficulty(void);
//RULES
void game_rules(int attempts);
//Make random number(function)
int numrandom(int min, int max);
//say rules to player + Get player's answer + check if number is neggative(function)
int playernum(int min, int max);
//Compare random number with player's guess(function)
void nums_compare(int attempts, int computer_num, int min, int max);




int main(void)
{
    int min, max, attempts;

    //choose level
    int level = choose_difficulty();
    if(level == 1)
    {
        min = 1;
        max = 5;
        attempts = 10;

    }
    else if(level == 2)
    {
        min = 1;
        max = 10;
        attempts = 7;

    }
    else
    {
        min = 1;
        max = 20;
        attempts = 5;

    }
    game_rules(attempts);
    //computer making random number
    srand(time(NULL));
    int computer_num  = numrandom(min, max);
    //Compare random number with player's guess + final results
    nums_compare(attempts, computer_num, min, max);

}

void game_rules(int attempts)
{
    printf("You should guess the number in specifed range.\n");
    printf("After each you will get a hint\n");
    printf("You have %i attempts\n", attempts);
}

//Fuction for choosing level
int choose_difficulty(void)
{
    int y;
    do
    {
        y = get_int("Choose your level: ");
    }
    while(y < 1 || y > 3);

    return y;
}
//Generate random number in given range
int numrandom(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

//Function for player
int playernum(int min, int max)
{
    int x;
    do
    {
        x = get_int("Enter a number from %i to %i\n", min, max);
    }
    while(x < min || x > max);

    return x;
}

//Compare function
void nums_compare(int attempts, int computer_num, int min, int max)
{
    int player_num;
    int i;
    for(i = 0; i < attempts; i++)
    {
        player_num = playernum(min, max);
        if(player_num < computer_num)
        {
            printf("Too small!\n");
        }
        else if(player_num > computer_num)
        {
            printf("Too big!\n");
        }
        else
        {
            printf("You win!\n");
            break;
        }

    }
    if(i == attempts && player_num != computer_num)
    {
            printf("You lose!\n");
    }



}