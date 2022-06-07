#include "table.h"

//Add a node into a binary search tree (data that is less is to the left,
//data that is greater than or equal is to the right). Return the length of the
//path where the data is added

/*
//PUBLIC VERSION - which is a wrapper function that sets the stage for an ADT's private
//recursive function
int table::insert(int data)
{
    //if (!root) //EMPTY LIST
    return add_bst(root, data);
}
*/


//PRIVATE MEMBER FUNCTION that is CALLED from a PUBLIC WRAPPER function
int add_bst(node * & root, int data)
{
    if (!root) //gone PAST the last node in a path
    {
        root = new node;
        root->data = data;
        root->left = root->right = NULL;
        return 1;
    }
    if (data < root->data)
        return 1 + add_bst(root->left, data);
    return 1 + add_bst(root->right, data);
}
