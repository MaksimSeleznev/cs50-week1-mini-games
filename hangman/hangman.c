#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int wordsize;
    char letter;
    char word[] = "table";
    char hidden[] = {'_', '_', '_', '_', '_'};
    wordsize = strlen(word);
    bool stop = false;
    while(!stop)
    {
        bool win = true;
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
    }

}