#include "Prog2_Williams_stack.h"

// *****************************************************************************
// Author: Connor Williams
// Date: July 16, 2021
// Course: CS163 Data Structures
// Assignment: Program 2
// Filename: Prog2_Williams_stack.h
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
// *****************************************************************************


/*
struct node
{
  queue * trials; //Dynamically allocated array of trials of the "queue" class
                  //data type
  node * next;    //Next pointer to the node structure data type
};

DATA MEMBERS

    node * head;   //Head pointer to the node
    int top_index; //Index to keep track of the top of the stack
*/




// The constructor initializes the data members to NULL or 0. This constructor 
// takes no arguments and returns nothing.
stack::stack()
{

}




// The destructor deallocates any dynamically allocated memory and resets it to
// NULL. This destructor takes no arguments and returns nothing.
stack::~stack()
{

}



// This member function pushes or adds an object of the "queue" class data
// type to the top of an object of the "stack" class data type. This member
// function takes an object "to_add" of the constant "queue" class data type,
// passed by reference, as an argument and returns an integer to represent
// the success or failure of an operation.
int stack::push(const queue & to_add)
{

  return 0;
}



// This member function displays all objects of the "queue" class data type
// held within an object of the "stack" class data type. This constant member 
// function takes no arguments and returns an integer to represent the success
// or failure of an operation.
int stack::display_all() const
{

  return 0;
}




// This member function displays an object of the "queue" class data type from
// the top of the list of an object of the "stack" class data type. This 
// constant member function takes no arguments and returns an integer to 
// represent the success or failure of an operation.
int stack::display_top() const
{

  return 0;
}



// This member function pops or removes the object of the "queue" class data
// type from the top of the list of an object of the "stack" class data type.
// The popped object is copied to a passed in object of the "queue" class data
// type. This member function takes an object "copy_to" of the "queue" class
// data type, passed by reference, as an argument and returns an integer to 
// represent success or faiure of the operation.
int stack::pop(queue & copy_to)
{

  return 0;
}





