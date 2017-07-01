#include <stdio.h>
#include <string.h>
#include "minunit.h"
#include "addTwoNumbers.h"

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

static char *testLinkedList()
{
  ListNode *l1 = NULL;
  int number;
  char errorMessage[100];
  pushLinkedList(&l1, 2);
  pushLinkedList(&l1, 4);
  pushLinkedList(&l1, 3);
  sprintf(errorMessage, "error,  l1->val (%d) != 2", l1->val);
  mu_assert(strdup(errorMessage), l1->val == 2);
  number = getNumberLinkedList(l1);
  sprintf(errorMessage, "error,  %d != 342", number);
  mu_assert(strdup(errorMessage), number == 342);
  return 0;
}

static char *testAddTwoNumbers()
{
  ListNode *l1 = NULL;
  ListNode *l2 = NULL;
  ListNode *l3 = NULL;
  int number1, number2, number3, total;
  char errorMessage[100];
  pushLinkedList(&l1, 2);
  pushLinkedList(&l1, 4);
  pushLinkedList(&l1, 3);
  pushLinkedList(&l2, 5);
  pushLinkedList(&l2, 6);
  pushLinkedList(&l2, 4);

  l3 = addTwoNumbers(l1, l2);
  number1 = getNumberLinkedList(l1);
  number2 = getNumberLinkedList(l2);
  number3 = getNumberLinkedList(l3);
  total = number1 + number2;
  sprintf(errorMessage, "error,  %d != %d", number3, total); //Test the convertion
  mu_assert(strdup(errorMessage), number3 == total);
  return 0;
}

static char *all_tests()
{
  mu_run_test(testLinkedList);
  mu_run_test(testAddTwoNumbers);
  return 0;
}

int main(int argc, char **argv)
{
  char *result = all_tests();
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
