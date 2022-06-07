#include "table.h"

float display_largest_and_smallest(node * root)
{
    if (!root) return 0;

    //Wrapper functions - set the stage for what we are going to do
    int h_left = display_smallest(root); //height left
    int h_right = display_largest(root); //height right


    return ((h_left + h_right) / 2.0);
}

//smallest
int display_smallest(node * root)
{
    if (!root->left) //NOW WE ARE AT THE SMALLEST ITEM
    {
        cout << "Smallest is: " << root->data << endl;
        return 1;
    }
    return display_smallest(root->left) + 1;
}

//largest
int display_largest(node * root)
{
    if (!root->right)
    {
        cout << "Largest is: " << root->data << endl;
        return 1;
    }
    return display_largest(root->right) + 1;
}
