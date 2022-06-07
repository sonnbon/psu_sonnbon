#include "table.h"

int display_inorder(node * root) //displaying in sorted order and return the number
                                 //of nodes
{
    if (!root) return 0; //empty tree? at the end?

    //Inorder traversal
    int counter = 0;
    counter = display_inorder(root->left);
    ++counter; //cout current node
    cout << root->data << " ";
    counter += display_inorder(root->right);
    return counter;
}

void destroy_all(node * & root)
{
    if (!root) return;
    destroy_all(root->left);
    destroy_all(root->right);
    delete root;
    root = NULL;
    return;
}
