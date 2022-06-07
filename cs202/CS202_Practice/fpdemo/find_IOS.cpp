#include "table.h"


//Find the IOS and return its contents
//return 0 if root doesnt have two children

int table::find_IOS()
{
    if (!root) return 0;
    if (!root->right) return 0;
    if (!root->left) return 0; //This prompt requires two children

    return find_IOS(root->right);
}


int table::find_IOS(node * root)
{
    if (!root->left) //If at beginning we know root will not be null because of the wrapper function
        return root->data;

    return find_IOS(root->left);
}
