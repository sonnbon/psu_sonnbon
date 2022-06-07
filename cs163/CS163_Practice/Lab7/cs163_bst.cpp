#include "cs163_bst.h"

using namespace std;


// ***These are sample wrapper functions
table::~table()
{
     remove_all(root); //call the recursive removal_all private function
}

// This is a wrapper function that will call the recursive count function
int table::count()
{
    //Notice how the returned value from the recursive function is used
    return count(root);
}

// Now it is your turn to write the count function recursively
int table::count (node * root)
{
    int counter = 0;

    if (!root) return 0;

    counter = count(root->left);
    ++counter;
    counter += count(root->right);
    return counter;
}


// Start with the wrapper function that calls the recursive function
int table::sum()
{
    //Call the recursive function here:
    return sum(root);

}

// Now it is your turn to write the sum function recursively
int table::sum (node * root)
{
    int sum_of = 0;

    if (!root) return 0;

    sum_of = root->data;
    sum_of += sum(root->left);
    sum_of += sum(root->right);
    return sum_of;
}


int table::height()   //simply call the private version of the functions
{
    //Call the recursive function here:
    return height(root);
}

//Now write this function recursively
//STUDY THIS ONE. STEP THROUGH A STACK TO VISUALIZE.
int table::height (node * root)
{
    int count_l = 0;
    int count_r = 0;

    if (!root) return 0;

    count_l += height(root->left);
    ++count_l;

    count_r += height(root->right);
    ++count_r;

    return max(count_l, count_r);
}



int table::remove_all()
{
    //Call the recursive function here:
    return remove_all(root);

}

// Now it is your turn to write the remove_all function recursively
int table::remove_all(node * & root)
{
    int count = 0;
    if (!root) return 0;

    ++count;
    count += remove_all(root->left);
    count += remove_all(root->right);

    delete root;
    root = NULL;
    
    return count;
}  


int table::copy(const table & to_copy)
{
    //Call the recursive function here:
    return copy(root, to_copy.root);
}

// Now it is your turn to write the copy function recursively
int table::copy(node * & dest_root, node * source_root) 
{
    int count = 0;

    if (!source_root)
    {
        dest_root = NULL;
        return 0;
    }

    dest_root = new node;
    dest_root->data = source_root->data;

    count += copy(dest_root->left, source_root->left);
    ++count;
    count += copy(dest_root->right, source_root->right);

    return count;
}  





















