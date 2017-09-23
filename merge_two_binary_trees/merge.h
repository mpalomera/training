
typedef struct tn
{
    int value;
    struct tn *left;
    struct tn *right;
} TreeNode;

TreeNode* mergeTrees(const TreeNode*, const TreeNode* );
