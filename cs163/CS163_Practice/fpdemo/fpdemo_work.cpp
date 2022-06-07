#include "table.h"

//Count number of items
int count_all(node * root)
{
    if (!root) return 0;

    int count = count_all(root->left);
    ++count;
    return count += count_all(root->right);
}



//Count number of even items
int count_even(node * root)
{
    if (!root) return 0;

    int count = count_even(root->left);
    if (root->data % 2 == 0)
        ++count;
    return count += count_even(root->right);
}



//Count number of nodes in largest left subtree
int count_largest_left(node * root)
{
    if (!root) return 0;
    if (!root->right)
        return count_all(root->left);
    return count_largest_left(root->right);
}


//Sum together the root's data and the largest node's data
int sum_root_largest(node * root)
{
    if (!root) return 0;
    int largest = get_largest(root);
    int sum = root->data + largest;
    return sum;
}


//Get largest data item
int get_largest(node * root)
{
    if (!root) return 0;
    if (!root->right)
        return root->data;
    return get_largest(root->right);
}


//Get smallest data item
int get_smallest(node * root)
{
    if (!root) return 0;
    if (!root->left)
        return root->data;
    return get_smallest(root->left);
}


//Display sorted
int display_sorted(node * root)
{
    if (!root) return 0;

    int count = display_sorted(root->left);
    cout << root->data << ' ';
    ++count;
    return count += display_sorted(root->right);
}


//Go to larger node Wrapper function
int count_larger(node * root)
{
    if (!root) return 0;
    int data = root->data;
    return count_larger_than_root(root->right, data);
}


//Count the number of items larger than root's data
int count_larger_than_root(node * root, int data)
{
    if (!root) return 0;

    int count = count_larger_than_root(root->left, data);
    if (data != root->data)
        ++count;
    return count += count_larger_than_root(root->right, data);
}


//Display largest and smallest items
int display_largest_smallest(node * root)
{
    if (!root) return 0;
    int smallest = get_smallest(root);
    int largest = get_largest(root);

    if (smallest == largest)
        cout << "There's only one node. Its value is: " << smallest << endl << endl;
    else
    {
        cout << "The smallest item is: " << smallest << endl;
        cout << "The largest item is: " << largest << endl;
    }
    return 1;
}


//Determine if the largest item is the same as the root's data
int largest_equal_root(node * root)
{
    if (!root) return 0;
    int largest = get_largest(root);
    if (root->data == largest)
        return 1;
    return 0;
}


//Display the root's IOS WRAPPER
int goto_root_IOS(node * root)
{
    if (!root) return 0;
    return display_root_IOS(root->right);
}

//Display the root's IOS
int display_root_IOS(node * root)
{
    if (!root) return 0;
    if (!root->left)
    {
        cout << "This is the IOS: " << root->data << endl << endl;
        return 1;
    }
    return display_root_IOS(root->left);
}


//Remove every leaf
int remove_leaves(node * & root)
{
    int count = 0;

    if (!root) return 0;
    if (!root->left && !root->right)
    {
        delete root;
        root = NULL;
        ++count;
        return count;
    }
    count = remove_leaves(root->left);
    return count += remove_leaves(root->right);
}


//Remove largest item
int remove_largest(node * & root)
{
    if (!root) return 0;
    if (!root->right)
    {
        if (!root->left)
        {
            delete root;
            root = NULL;
        }
        else
        {
            node * hold = root->left;
            delete root;
            root = hold;
        }
        return 1;
    }
    return remove_largest(root->right);
}


//Remove smallest item
int remove_smallest(node * & root)
{
    if (!root) return 0;
    if (!root->left)
    {
        if (!root->right)
        {
            delete root;
            root = NULL;
        }
        else
        {
            node * hold = root->right;
            delete root;
            root = hold;
        }
        return 1;
    }
    return remove_smallest(root->left);
}

//Remove smallest and largest item
int remove_smallest_and_largest(node * & root)
{
    int small_success = 0;
    int large_success = 0;

    if (!root) return 0;

    small_success = remove_smallest(root);
    large_success = remove_largest(root);

    if (small_success && large_success)
        return 1;
    return 0;
}

//Sum all the data
int sum_all(node * root)
{
    if (!root) return 0;

    int sum = sum_all(root->left);
    sum += root->data;
    return sum += sum_all(root->right);
}

//Average all data
float average_all(node * root)
{
    int sum = sum_all(root);
    int count = count_all(root);

    float average = sum / count;
    return average;
}

//Sum all the even data
int sum_even(node * root)
{
    if (!root) return 0;

    int sum = sum_even(root->left);
    if (root->data % 2 == 0)
        sum += root->data;
    return sum += sum_even(root->right);
}


//Average all the even data
float average_even(node * root)
{
    if (!root) return 0;
    int sum = sum_even(root);
    int count = count_even(root);
    float average = sum / count;
    return average;
}

//Copy to a new tree
int copy_tree(node * & dest, node * source)
{
    if (!source)
    {
        dest = NULL;
        return 0;
    }
    dest = new node;
    dest->data = source->data;
    dest->left = NULL;
    dest->right = NULL;

    copy_tree(dest->left, source->left);
    copy_tree(dest->right, source->right);
    return 1;
}


//Insert 99 into a BST
int insert_num(node * & root, int data)
{
    if (!root)
    {
        root = new node;
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        return 1;
    }

    if (data < root->data)
        return insert_num(root->left, data);
    return insert_num(root->right, data);
}


//Remove all items
int remove_all(node * & root)
{
    if (!root) return 0;
    remove_all(root->left);
    remove_all(root->right);

    delete root;
    root = NULL;
    return 1;
}

//Count number of times passed in value is in tree
int count_match(node * root, int data)
{
    if (!root) return 0;
    int count = 0;
    if (data == root->data)
    {
        ++count;
        return count += count_match(root->right, data);
    }
    else if (data > root->data)
        return count += count_match(root->right, data);
    else
        return count += count_match(root->left, data);
}



//Check for match
bool ismatch(node * root, int data)
{
    if (!root) return 0;
    int count = count_match(root, data);
    return count;
}


//Insert only if new
int insert_unique(node * & root, int data)
{
    if (ismatch(root, data))
        return 0;
    return insert_num(root, data);
}


//Count nodes with no children
int count_leaves(node * root)
{
    if (!root) return 0;
    int count = count_leaves(root->left);
    if (!root->left && !root->right)
        ++count;
    return count += count_leaves(root->right);
}


//Get height of tree
int get_height(node * root)
{
    if (!root) return 0;
    int l_count = 0;
    int r_count = 0;
    l_count += get_height(root->left);
    ++l_count;
    
    r_count += get_height(root->right);
    ++r_count;

    return max(l_count, r_count);
}

/*
//Copy into an array
int copy_to_array(node * root, int * & array)
{
    if (!root)
    {
        array = NULL;
        return 0;
    }
    int count = count_all(root);

    array = new int[count];
    return insert_array(root, array);
}
 */   
/*
//Display the largest two items
int display_largest_two(node * root)
{
    if (!root) return 0;

    int data = 0;

    int largest = get_largest(root);

    int second = get_second_largest(root, data);

    cout << "Largest is: " << largest << endl;
    cout << "Second largest is: " << second << endl;

    return 1;

}

*/

//Copy even data to a new tree
/*int copy_even(node * & dest, node * source)
{
    if (!source)
    {
        dest = NULL;
        return 0;
    }

    if (source->data % 2 == 0)
    {
        dest = new node;
        dest->data = source->data;
        dest->left = NULL;
        dest->right = NULL;
        return 1;
    }
    

}
*/












































