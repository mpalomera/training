#include <stdlib.h>
#include <stdio.h>
#include "merge.h"
#include <assert.h>

/*****************************
 * mergeTrees
 * Recursive solution merge two trees 
 * @param:
 *  {TreeNode *} t1: first tree
 *  {TreeNode *} t2: second tree
 * @return:
 *  {TreeNode *} merged tree 
*/
TreeNode *mergeTrees(const TreeNode *t1, const TreeNode *t2)
{

    if (t1 == NULL && t2 == NULL)
    {
        return NULL;
    }
    else
    {

        TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
        if (t1 && t2)
        {
            node->value = t1->value + t2->value;
            node->left = mergeTrees(t1->left, t2->left);
            node->right = mergeTrees(t1->right, t2->right);
        }
        else if (t1 != NULL)
        {
            node->value = t1->value;
            node->left = mergeTrees(t1->left, NULL);
            node->right = mergeTrees(t1->right, NULL);
        }
        else if (t2 != NULL)
        {
            node->value = t2->value;
            node->left = mergeTrees(NULL, t2->left);
            node->right = mergeTrees(NULL, t2->right);
        }
        return node;
    }
}
