#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "longest-substring.h"

char *longestSubstring(char *s)
{
    int size = strlen(s), currentChar = 0, initialPosition = 0, i = 0;
    char longestString[size];
    char temporalString[size];
    char usedLetters[255];

    longestString[0] = '\0';
    memset(usedLetters, 0, sizeof(usedLetters));
    for (initialPosition = 0; initialPosition < size; initialPosition++)
    {
        currentChar = initialPosition;
        i = 0;
        while (s[currentChar++])
        {
            if (usedLetters[s[currentChar]] == 0)
            {
                usedLetters[s[currentChar]] = 1;
                temporalString[i++] = s[currentChar];
            }
            else
            {
                temporalString[i++] = '\0';
                if (strlen(temporalString) >= strlen(longestString))
                {
                    strcpy(longestString, temporalString);
                }
                temporalString[0] = '\0';
                memset(usedLetters, 0, sizeof(usedLetters));
                break;
            }
        }
        //If longest string reach the end of the original string no need to keep searching
        //it is the longest
        if (currentChar >= size)
        {
            break;
        }
    }
    return strdup(longestString);
}

int lengthOfLongestSubstring(char *s)
{
    return strlen(longestSubstring(s));
}