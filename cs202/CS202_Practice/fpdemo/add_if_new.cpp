#include "table.h"

//Add item only if not already in table
//return bool
bool table::add_if_new(int data)
{
    return add_if_new(root, data);
}


bool table::add_if_new(node * & root, int data)
{
    if (!root)
    {
        root = new node;
        root->data = data;
        root->left = nullptr;
        root->right = nullptr;
        return true;
    }

    if (data == root->data)
        return false;

    if (data < root->data)
        return add_if_new(root->left, data);
    return add_if_new(root->right, data);
}
