#include "Prog2_Williams_queue.h"

// *****************************************************************************
// Author: Connor Williams
// Date: July 16, 2021
// Course: CS163 Data Structures
// Assignment: Program 2
// Filename: Prog2_Williams_stack.h
// *****************************************************************************
// This file contains a node structure and a class Abstract Data Type, named 
// "stack". This Abstract Data Type is used to specifically work with the
// a Linear Linked List of Arrays data structure, pushing, popping, copying
// after popping, displaying the top of the stack, or displaying all of its 
// contents. These contents, within each node's array's element, make up the 
// information for all the tasks or steps of a queue. All member functions (not 
// including the constructor or destructor) within the Abstract Data Type return 
// an integer value to represent success or failure of an operation to the 
// client. Arguments that will be passed in member functions include an object 
// of the "queue" class data type for adding and copying purposes, respectively.
// *****************************************************************************



// - - - - - S T R U C T U R E S - - - - -
//
// This structure manages one node structure that holds a dynamically allocated
// array of trials of the "queue" class data type and a next pointer to the node
// structure.
struct node
{
  queue * trials; //Dynamically allocated array of trials of the "queue" class 
                  //data type
  node * next;    //Next pointer to the node structure data type
};
// -----------------------------------------------------------------------------



// - - - - - C L A S S E S - - - - -
//
// This class manages a Linear Linked List of Arrays of queues, which hold a
// Circular Linked List of tasks for completing a particular activity. It allows 
// for pushing and popping queue objects to the top and from the top of the 
// stack, respectively, and for copying of a queue object after popping it, by 
// passing in objects as arguments inputted from the client. It also displays 
// all contents of the list or a queue just from the top of the stack for 
// debugging purposes.
class stack
{
  public:
    stack();                        //Constructor, initializes data members to
                                    //NULL or 0.
    ~stack();                       //Destructor, deallocates dynamic data
                                    //members and resets all data members to
				                    //NULL or 0.
    int push(const queue & to_add); //Add a queue object to the top of the stack
    int display_all() const;        //Displays all contents in the stack
    int display_top() const;        //Displays queue at the top of the stack
    int pop(queue & copy_to);       //Remove queue from the top of the stack and
                                    //copy its contents

  private:
    node * head;   //Head pointer to the node
    int top_index; //Index to keep track of the top of the stack
};
// -----------------------------------------------------------------------------




