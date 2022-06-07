#include "table.h"

//Copy every leaf to a new tree and return the number copied
int table::copy_leaves(table & new_list)
{
    if (!root)
    {
        new_list.root = nullptr;
        return 0;
    }

    return copy_leaves(new_list.root, root);
}


int table::copy_leaves(node * & dest, node * src)
{
    int count {0};

    if (!src)
        return 0;

    
    if (!src->left && !src->right)
    {
        node * hold = dest;
        dest = new node;
        dest->data = src->data;
        if (!hold)
        {
            dest->left = nullptr;
            dest->right = nullptr;
        }
        else
        {
            if (dest->data <= hold->data)
            {
                dest->right = hold;
                dest->left = nullptr;
            }
            else
            {
                dest->left = hold;
                dest->right = nullptr;
            }
        }
        ++count;
    }

    count += copy_leaves(dest, src->left);
    count += copy_leaves(dest, src->right);

    return count;
}


