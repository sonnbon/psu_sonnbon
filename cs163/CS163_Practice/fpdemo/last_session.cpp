#include "table.h"

//Count the number of items in the largest item's left subtree
//and return the count


//Write the code to count the number of items in a tree
int count_all(node * root)
{
    if (!root) return 0;
    
    int count = count_all(root->left);
    return count += count_all(root->right);
}


//Now, write the wrapper function to go the largest item
//FIND the largest item!
int count_largest_left(node * root)
{
    if (!root) return 0;
    if (!root->right) //HAVE THE LARGEST ITEM!!!!
        return count_all(root->left);
    return count_largest_left(root->right);
}



//Find out if there is a duplicate item in the tree
//and return true if there is
//USE INORDER TRAVERSAL - handle the data in sorted order
bool is_duplicate(node * root, int & last_item)
{
    if (!root) return false;
    if (is_duplicate(root->left, last))
        return true; //Just stop - we found a duplicate

    if (root->data == last_item)
        return true;
    last_item = root->data;
    return is_duplicate(root->right, last_item);
}



//FIND and return the IOS from the root
//Call this function with root->right
int find_smallest(node * root)
{
    if (!root) return 0;
    if (!root->left) return root->data;
    return find_smallest(root->left);
}
