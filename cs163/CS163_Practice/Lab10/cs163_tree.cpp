#include "cs163_tree.h"
using namespace std;



//These are the functions that you will be writing for the BST


void table::display_largest()
{
    if (!root) return;
    return display_largest(root);
}      	//STEP 1


void table::display_largest(node * root) 
{
    if (!root) return;

    if (!root->right)
    {
        cout << "Largest is: " << root->data << endl << endl;
        return;
    }

    return display_largest(root->right);
}

int table::count_root() 
{
    if (!root) return 0;
    int match = root->data;
    return count_root(root, match);

}		//STEP 2


int table::count_root(node * root, int match) 
{
    if (!root) return 0;
     
    int count = count_root(root->left, match);
    if (root->data == match)
        ++count;
    return count += count_root(root->right, match);
}


void table::copy(table & source) 
{
    if (!source.root) return;
    remove_root(source.root);
    return copy(root, source.root);
}  	//STEP 3



void table::copy(node * & destination, node * source) 
{

    if (!source)
    {
        destination = NULL;
        return;
    }

    destination = new node;
    destination->data = source->data;
    destination->left = NULL;
    destination->right = NULL;
    
    copy(destination->left, source->left);
    copy(destination->right, source->right);
}


void table::remove_root(node * & root)
{
    if (!root) return;
    if (!root->left && !root->right)
    {
        delete root;
        root = NULL;
    }
    else if (!root->left)
    {
        node * hold = root->right;
        delete root;
        root = hold;
    }
    else if (!root->right)
    {
        node * hold = root->left;
        delete root;
        root = hold;
    }
    else
    {
        node * successor = root->right;
        if (!successor->left)
        {
            node * hold = successor->right;
            root->data = successor->data;
            delete successor;
            root->right = hold;
        }
        else
        {
            node * prev = NULL;
            while (successor->left)
            {
                prev = successor;
                successor = successor->left;
            }
            node * hold = successor->right;
            root->data = successor->data;
            delete successor;
            prev->left = hold;
        }
    }
}
      


//Now for the 2-3-4 Tree		//STEP 4
int table::count_3_data()   //sample wrapper function that return the count
{
      return count_3_data(root234);
}	     
     
int table::count_3_data(node234 * root){}	                    


//STEP 5
int table::height(){}                    //Return the height
int table::height(node234 * root){}                    

//STEP 6
//Copy from the argument into the data members...
int table::copy_234(table & copy_from) {}
int table::copy(node234 * & destination, node234 * source){}      
