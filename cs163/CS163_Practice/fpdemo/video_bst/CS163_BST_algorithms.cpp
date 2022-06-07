#include "table.h"

//Count the number of nodes with no children
//return that count
//PREORDER traversal
int count_leaf(node * root)
{
    //Base
    if (!root) return 0;
    //Am I a leaf? Is so, count it and stop
    if (!root->left && !root->right)
        return 1;

    //Otherwise
    return count_left(root->left) + count_leaf(root->right);
}


//Display every even data item
//return the sum of all the data displayed
//INORDER traversal
int display_even(node * root)
{
    if (!root) return 0;

    int sum = display_even(root->left);
    if (root->data % 2 == 0)
    {
        cout << root->data << " ";
        sum += root->data;
    }
    sum += display_even(root->right);
    return sum;
}


//Count the number of items that have even data items as children
//POSTORDER traversal
bool count_child(node * root, int & count)
{
    if (!root) return true;

    //Left->right->visit the node (handle the children first)
    bool left = count_child(root->left, count);
    bool right = count_child(root->right, count);
    if (left && right)
        ++count;

    //visit the node (if I am even, return true)
    if (root->data % 2 == 0)
        return true;
    return false;
}
