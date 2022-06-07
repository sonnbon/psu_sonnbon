#include "table.h"


//Get the height of the tree
//return the height
int table::get_height()
{
    if (!root) return 0;

    return get_height(root);
}


int table::get_height(node * root)
{
    if (!root) return 0;

    int left = get_height(root->left);

    int right = get_height(root->right);

    return max(left, right) + 1;
}

