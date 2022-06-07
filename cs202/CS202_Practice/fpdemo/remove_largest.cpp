#include "table.h"

//Remove largest and return largest data item
int table::remove_largest()
{
    int largest{0};

    if (!root) return 0;
    if (!root->right)
    {
        largest = root->data;
        delete root;
        root = nullptr;
        return largest;
    }
    return remove_largest(root->right);
}


int table::remove_largest(node * & root)
{
    int largest {0};

    if (!root) return 0;
    if (!root->right)
    {
        largest = root->data;
        node * hold = root->left;
        delete root;
        root = hold;
        return largest;
    }

    return remove_largest(root->right);
}
