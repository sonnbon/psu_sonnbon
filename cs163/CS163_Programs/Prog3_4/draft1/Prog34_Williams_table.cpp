#include "Prog34_Williams_table.h"
using namespace std;

// *****************************************************************************
// Author: Connor Williams
// Date: July 27, 2021
// Course: CS163 Data Structures
// Assignment: Program 3/4
// Filename: Prog34_Williams_table.cpp
// *****************************************************************************
// This file contains the member functions of the "stack" class, which allows
// for a Linear Linked List (LLL) of Arrays of queue objects (Circular Linked 
// List of task entries to complete a particular activity), in which each node 
// holds information on a dynamically allocated array of "queue" objects and
// a next pointer to itself. From the client, a user can add a queue object to a 
// list of queues, display all the queues in the list, display just the top of 
// the stack, push a queue to the top of the stack, and pop a queue from the top 
// of the stack. The class is working with a LLL of Arrays data structure and is 
// doing so with two data members, a head pointer and a top index tracker. The
// head pointer  points to a dynamically allocated array of objects of the 
// "queue" class, which holds all necessary information for a queue activity.
// The top index tracker variable ("top_index") keeps track of where the top of
// the stack is. The "push" and "pop" member functions pass in an object 
// of the "queue" class in order to add to the LLL of Arrays and copy the object
// popped off the stack, respectively. All member functions return an integer 
// data type to the client to represent success or failure of the operation.
//
//
//
//
// ...
// *****************************************************************************

/*
    h_node ** hash_table; //Array of head pointers to the 
                          //hash table node
    t_node * root;        //Root pointer to the tree node
    int hash_table_size;  //Size of the hash table
*/

    
// The constructor initializes the data members to NULL or 0. This constructor 
// takes no arguments and returns nothing.
table::table(int size)
{
  root = NULL;                      //Set BST's root to NULL

  hash_table = new h_node * [size]; //Allocate new hash table node of client
                                    //input size

  //Iterate through new hash table.
  for (int i = 0; i < size; ++i)
    hash_table[i] = NULL;           //Set hash table's element to NULL

  hash_table_size = size;           //Set hash table's size to client input size
}




// The destructor deallocates any dynamically allocated memory and resets it to
// NULL. This destructor takes no arguments and returns nothing.
table::~table()
{
  BST_remove_all(root);

}




int table::hash_function(char key_value1[], char key_value2[])
{

  return 0;
}




int table::insert(const animal & new_animal)
{

  return 0;
}




int table::display_match(char type[], char breed[])
{

  return 0;
}




int table::retrieve(char name[], char breed[], animal & to_find)
{

  return 0;
}




int table::display_all() const
{

  return 0;
}




int table::remove_animal(char name[])
{

  return 0;
}



// This private member function deletes all the data in a Binary Search Tree.
// This member function takes a root pointer to the tree's node structure 
// data type, passed by reference, as an argument and returns an integer to 
// represent success or failure of the operation.
int table::BST_remove_all(t_node * & root)
{
  //Check if list is empty
  if (!root)
    return 0; //Returns failure of the operation

  BST_remove_all(root->left);  //Traverse the list left
  BST_remove_all(root->right); //Traverse the list right

  delete root; //Delete root
  root = NULL; //Set root to NULL

  return 1; //Returns success of the operation
}
