#include <stdio.h>
#include <string.h>
#include "minunit.h"
#include "longest-palindromic.h"

#define KNRM "\x1B[0m"
#define KRED "\x1B[31m"
#define KGRN "\x1B[32m"
#define KYEL "\x1B[33m"
#define KBLU "\x1B[34m"
#define KMAG "\x1B[35m"
#define KCYN "\x1B[36m"
#define KWHT "\x1B[37m"
#define RESET "\033[0m"

int tests_run = 0;

static char *testIsPalindrom()
{
  char *pal = "baab";
  int expected = 1;
  int respond = isPalindrom(pal);
  char message[100];
  sprintf(message, "%s %d must equal to %d", pal, respond, expected);
  mu_assert(strdup(message), expected = respond);
  return 0;
}

static char *testLongestPalindrome()
{
  char *input = "cbbd";
  char *expected = "bb";
  char *respond = longestPalindrome(input);
  char message[100];
  sprintf(message, "%s must equal to %s", expected, respond);
  mu_assert(strdup(message), !strcmp(expected,respond));
  return 0;
}

static char *allTests()
{
  mu_run_test(testIsPalindrom);
  mu_run_test(testLongestPalindrome);
  return 0;
}

int main(int argc, char **argv)
{
  char *result = allTests();
  if (result != 0)
  {
    printf("-_-_-_-_-_-_-_,------,      o \n");
    printf("_-_-_-_-_-_-_-|   /\\_/\\ \n");
    printf("-_-_-_-_-_-_-~|__( X .X)  +     + \n");
    printf("_-_-_-_-_-_-_- \"\"  \"\" \n");
    printf(KRED "✗ %s \n" RESET, result);
  }
  else
  {
    printf("-_-_-_-_-_-_-_,------,      o \n");
    printf("_-_-_-_-_-_-_-|   /\\_/\\ \n");
    printf("-_-_-_-_-_-_-~|__( ^ .^)  +     + \n");
    printf("_-_-_-_-_-_-_-  \"\"  \"\" \n");
    printf(KGRN " ✓ ALL TESTS PASSED \n" RESET);
  }
  printf("Tests run: %d\n", tests_run);
  return result != 0;
}
