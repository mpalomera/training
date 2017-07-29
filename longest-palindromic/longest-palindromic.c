#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "longest-palindromic.h"

int isPalindrome(char *s)
{
    int length = strlen(s) - 1;
    int i;
    while (s[i] == s[length])
    {
        i++;
        length--;
        if (i >= length)
        {
            return 1;
        }
    }
    return 0;
}

char *longestPalindrome(char *s)
{
    char test[MAXLENGTH];
    int slength = strlen(s);
    int length = slength - 1;
    int initial = 0;
    int i = 0, j = 0;

    printf(""); // <-- Mistery. It is needed to work, it is a change on the stack
   
    if (isPalindrome(s))
    {
        return strdup(s);
    }

    while (length)
    {
        while (1)
        {
            for (j = 0, i = initial; i < length + initial; i++, j++)
            {
                test[j] = s[i];       
            }

            test[j] = '\0';
            if (j == length)
            {
                if (isPalindrome(test))
                {
                    return strdup(test);
                }
                initial++;
                if (length + initial >= slength)
                {
                    break;
                }
            }
            else
            {
                break;
            }
        }
        length--;
        initial = 0;
    }
    return strdup(&s[length]);
}
