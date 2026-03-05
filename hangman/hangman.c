#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
//Functions
int rundom_word(int wordsize);
int level_choose(void);

int main(void)
{
    srand(time(NULL));
    int countwords = 10;
    char letter;
    int attempts;
    int used_count = 0;
    //Arrays
    char used_letters[26];
    string words3[] = {"gun", "day", "big", "son", "sun", "sit", "rat", "tea", "yes", "pay"};
    string words4[] = {"solo", "full", "page", "dear", "lord", "call", "flat", "food", "long", "rule"};
    string words5[] = {"table", "apple", "store", "water", "phone", "stone", "glass", "minus", "black", "white", "small"};
    string words6[] = {"honest", "nectar", "gently", "hardly", "enable", "ground", "island", "expert", "second", "school"};
    //selecting rundom number
    int index = rundom_word(countwords);
    int level = level_choose();
    string word;
    if(level == 1)
    {
        attempts = 20;
        word = words3[index];
    }
    else if(level == 2)
    {
        attempts = 16;
        word = words4[index];
    }
    else if(level == 3)
    {
        attempts = 14;
        word = words5[index];
    }
    else
    {
        attempts = 12;
        word = words6[index];
    }
    int wordsize = strlen(word);
    char hidden[wordsize];
    for(int r = 0; r < wordsize; r++)
    {
        hidden[r] = '_';
    }

    int count_attempts = attempts;
    bool stop = false;
    while(!stop)
    {
        bool win = true;
        bool lose = false;

        printf("\n[Attempt #%i]\n", (attempts - count_attempts + 1));
        for(int x = 0; x < wordsize; x++)
        {
            printf("%c ", hidden[x]);
        }
        letter = get_char("\nEnter your letter: ");
        bool proverka = false;
        while(!proverka)
        {
            bool proverka2 = false;
            for(int t = 0; t < used_count; t++)
            {
                if(letter == used_letters[t])
                {
                    proverka2 = true;
                }
            }
            if(proverka2)
            {
                letter = get_char("\nYou have already entered this letter.\nEnter your letter: ");
            }
            if(!proverka2)
            {
                proverka = true;
            }
        }
        printf("Used letters: [");
        for(int q = 0; q < used_count; q++)
        {
            printf("%c, ", used_letters[q]);
        }
        printf("]");
        printf("\n");
        used_letters[used_count] = letter;
        used_count++;

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

        if(win)
        {
            for(int j = 0; j < wordsize; j++)
            {
                printf("%c ", word[j]);
            }
            printf("\nYOU WIN!\n");
            stop = true;

        }
        if((attempts - count_attempts) == count_attempts)
        {
            lose = true;
        }

        if(lose)
        {
            printf("\nYOU LOST!\n");
            printf("WORD: %s\n", word);
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
int level_choose(void)
{
    int lvl;
    do
    {
    lvl = get_int("Choose level from 1 to 4:\n");
    }
    while((lvl < 0) || (lvl > 5));
    return lvl;
}
