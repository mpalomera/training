#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "minunit.h"
#include "merge.h"

#define KNRM "\x1B[0m"
#define KRED "\x1B[31m"
#define KGRN "\x1B[32m"
#define KYEL "\x1B[33m"
#define KBLU "\x1B[34m"
#define KMAG "\x1B[35m"
#define KCYN "\x1B[36m"
#define KWHT "\x1B[37m"
#define RESET "\033[0m"

int testsRun = 0;

static TreeNode *createTree(int index, int *values, int size)
{
  if (index >= size || values[index] == -1)
  {
    return NULL;
  }
  else
  {
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->value = values[index];
    node->left = createTree(2 * index + 1, values, size);
    node->right = createTree(2 * index + 2, values, size);
    return node;
  }
}

static bool cmpTree(TreeNode *t1, TreeNode *t2)
{
  if (t1 == NULL && t2 == NULL)
  {
    return true;
  }
  if (t1 == NULL || t2 == NULL)
  {
    return false;
  }

  if (t1->value == t2->value)
  {
    return cmpTree(t1->left, t2->left) && cmpTree(t1->right, t2->right);
  }
  else
  {
    return false;
  }
}

static char *testUnit()
{
    /*
  Input: 
	Tree 1                     Tree 2                  
          1                         2                             
         / \                       / \                            
        3   2                     1   3                        
       /                           \   \                      
      5                             4   7                  
  */
  TreeNode *t1;
  int t1Values[] = {1, 3, 2, 5};
  int t1Size = 4;
  TreeNode *t2;
  int t2Values[] = {2, 1, 3, -1, 4, -1, 7};
  int t2Size = 7;
    /*
   Expected: 
  Merged tree:
	     3
	    / \
	   4   5
	  / \   \ 
	 5   4   7
  */
  TreeNode *expected;
  int expectedValues[] = {3, 4, 5, 5, 4, -1, 7};
  int expectedSize = 7;
  TreeNode *result;
  int pass;


  t1 = createTree(0, t1Values, t1Size);
  t2 = createTree(0, t2Values, t2Size);

  expected = createTree(0, expectedValues, expectedSize);
  result = mergeTrees(t1, t2);

  muAssert("Tree must be equal", cmpTree(expected, result));
  return 0;
}

static char *allTests()
{
  muRunTest(testUnit);
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
  printf("Tests run: %d\n", testsRun);
  return result != 0;
}
