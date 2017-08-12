#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "zigzag-conversion.h"

char *convert(char *s, int numRows)
{
    char **rows;
    int i, j = 0;
    int len = strlen(s);
    int indexes[numRows];

    for (i = 0; i < numRows; i++)
    {
        indexes[i] = 0;
    }
    char *result = malloc((len + 1) * sizeof(char));
    if (numRows == 1)
    {
        return s;
    }
    rows = (char **)malloc(sizeof(char *) * numRows);
    for (i = 0; i < numRows; i++)
    {
        rows[i] = (char *)calloc(len, sizeof(char));
    }
    i = 0;

    while (s[i])
    {
        for (j = 0; j < numRows; j++)
        {
            if (s[i])
            {
                rows[j][indexes[j]] = s[i];
                indexes[j] += 1;
                i++;
            }
            else
            {
                break;
            }
        }
        for (j = numRows - 2; j > 0; j--)
        {
            if (s[i])
            {
                rows[j][indexes[j]] = s[i];
                indexes[j] += 1;
                i++;
            }
            else
            {
                break;
            }
        }
    }
    strcpy(result, rows[0]);
    for (i = 1; i < numRows; i++)
    {
        strcat(result, rows[i]);
    }
    return result;
}