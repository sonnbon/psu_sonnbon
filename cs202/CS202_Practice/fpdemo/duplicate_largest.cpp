#include "table.h"

int table::duplicate_largest()
{
    if (!root)
        return 0;
    if (!root->right)
        return 0;
    return duplicate_largest(root->right);
}

//Recursive
int table::duplicate_largest(node * & root)
{
    if (!root->right)
    {
        node * temp = new node;
        temp->data = root->data;
        root->right = temp;
        temp->left = nullptr;
        temp->right = nullptr;
        return root->data;
    }
    return duplicate_largest(root->right);
}
