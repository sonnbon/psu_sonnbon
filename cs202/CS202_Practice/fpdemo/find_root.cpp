#include "table.h"

bool table::find_root()
{
    if (!root)
        return false;
    if (!root->right)
        return false;

    return find_root(root->right);
}

//Recursive
bool table::find_root(node * root)
{
    if (!root->left) //found IOS
    {
        if (this->root->data == root->data)
            return true;
        return false;
    }

    return find_root(root->left);
}

