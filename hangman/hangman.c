#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
//Rundom word
int rundom_word(int wordsize);

int main(void)
{
    srand(time(NULL));
    int countwords = 11;
    char letter;
    int attempts = 1;
    //selecting rundom number
    string words[] = {"table", "apple", "store", "water", "phone", "stone", "glass", "minus", "black", "white", "small"};
    char hidden[] = {'_', '_', '_', '_', '_'};
    int index = rundom_word(countwords);
    string word = words[index];
    int wordsize = strlen(word);



    bool stop = false;
    while(!stop)
    {
        bool win = true;
        printf("[Attempt #%i]\n", attempts);
        for(int x = 0; x < wordsize; x++)
        {
            printf("%c ", hidden[x]);
        }
        letter = get_char("\nEnter your letter: ");
        for(int i = 0; i < wordsize; i++)
        {
            if(word[i] == letter)
            {
                hidden[i] = word[i];
            }
        }

        for(int k = 0; k < wordsize; k++)
        {

            if(hidden[k] == '_')
            {
                win = false;
                break;
            }
        }

        if(win == true)
        {
            for(int j = 0; j < wordsize; j++)
            {
                printf("%c ", word[j]);
            }
            printf("\nYOU WIN!\n");
            stop = true;

        }
        attempts+=1;
    }


}

int rundom_word(int countwords)
{

    int runword = rand() % countwords;
    return runword;
}

