#include "table.h"
using namespace std;

//These are the functions that you will be writing for Lab #10


//STEP 1
int table::count()	//SAMPLE wrapper function
{
    if (!root) return 0;

	return count(root);
}

int table::count(node * root)
{
    int num {0};

    if (!root) return 0;

    num = count(root->left);
    if (this->root->data != root->data)
        ++num;
    num += count(root->right);

    return num;
}


//STEP 2
int table::count_right_subtree()
{
    if (!root) return 0;
    if (!root->left)
        return count_right_subtree(root);
    return count_right_subtree(root->left);
}
int table::count_right_subtree(node * root)
{
    int count{0};
    if (!root) return 0;
    if (!root->left)
    {
        count = count_right_subtree(root->right);
        return count;
    }


    count = count_right_subtree(root->left);
    ++count;
    count += count_right_subtree(root->right);

    return count;
}


//STEP 3
int table::remove_largest()
{
    int largest{0};

    if (!root) return 0;
    if (!root->right)
    {
        node * hold = root->left;
        largest = root->data;
        delete root;
        root = hold;
        return largest;
    }
    return remove_largest(root->right);
}
int table::remove_largest(node * & root)
{
    int largest{0};
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


//STEP 4
int table::sum()
{
    if (!root) return 0;

    return sum(root);
}

int table::sum(node * root)
{
    int total{0};
    int count{0};
    int avg{0};

    if (!root) return 0;


    total += sum(root->left);
    if (root->data % 3 == 0 || root->data % 5 == 0)
        total = root->data;
    total += sum(root->right);

    ++count;
    avg = total / count;
    return avg;
}

//STEP 5
int table::copy(table & to_copy)
{
    if (!root)
    {
        to_copy.root = nullptr;
        return 0;
    }

    return copy(to_copy.root, root);
}

int table::copy(node * & destination, node * source)
{
    int count{0};

    if (!source)
    {
        destination = nullptr;
        return 0;
    }

    return count;
}

/*
//STEP 6a Challenge
int table::create_full(){}
int table::create_full(node * & new_tree){}


//STEP 6b
bool table::is_full(){}
bool table::is_full(node * root){}


//STEP 6c
int table::display_largest(){}
int table::display_largest(node * root){}


//STEP 6d
int table::display_largest2(){}
int table::display_largest2(node * root){}
*/


