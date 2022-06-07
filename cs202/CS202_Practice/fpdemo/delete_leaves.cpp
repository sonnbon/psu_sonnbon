#include "table.h"

//Delete every leaf and return the number deletedd

int table::delete_leaves()
{
    if (!root) return 0;
    if (!root->right && !root->left)
    {
        delete root;
        root = nullptr;
    }

    return delete_leaves(root);
}


int table::delete_leaves(node * & root)
{
    int count{0};

    if (!root) return 0;

    if (root->left && !root->left->left && !root->left->right)
    {
        delete root->left;
        root->left = nullptr;
        ++count;
    }
    if (root->right && !root->right->left && !root->right->right)
    {
        delete root->right;
        root->right = nullptr;
        ++count;
    }

    count += delete_leaves(root->left);
    count += delete_leaves(root->right);

    return count;
}




