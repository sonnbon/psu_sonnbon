#include "table.h"

//Connor Williams
//CS163
//BST Removal

//Remove a match in the BST (WRAPPER FUNCTION)
int remove_after_isempty(node * & root, int data)
{
    if (!root) return 0;
    return remove_item(root, data);
}



//Remove a match in the BST
int remove_item(node * & root, int data)
{
    //Check if list is empty
    if (!root) return 0;

    //Check if there is a match
    if (data == root->data)
    {
      //If the node is a leaf
      if (!root->left && !root->right)
      {
        delete root;
        root = NULL;
      }
      //Else if the node only has a left child 
      else if (!root->right)
      {
        node * hold = root->left;
        delete root;
        root = hold;
      }
      //Else if the node only has a right child
      else if (!root->left)
      {
        node * hold = root->right;
        delete root;
        root = hold;
      }
      //Otherwise the node has two children
      else
      {
        node * right_hold = root->right; //Hold the right child

        //If IOS is the right child
        if (!right_hold->left)
        {
          node * hold = right_hold->right; //Hold the right hold's right child
          root->data = right_hold->data;   //Copy the data from right hold
          delete right_hold;               //Delete the right hold data
          root->right = hold;              //Connect the root's right child to
                                           //the right right's child, jumping
                                           //the deleted node
        }

        //Otherwise the right child is not the IOS
        else
        {
          node * current = root->right; //Current gets root's right child
          node * previous = current;    //Previous gets current value

          //Traverse current's left children
          while (current->left)
          {
            previous = current;
            current = current->left;
          }
          root->data = current->data;      //Copy the the current data to the root
          previous->left = current->right; //Set previous' left child to current's right
          delete current;                  //delete the current node
        }
      }
      return 1;
    }

    remove_item(root->left, data); //Recursively call the function through each left child
    remove_item(root->right, data); //Recursivly call the function through each right child
    return 0;
}
