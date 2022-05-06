#include "Prog2_Williams_task.h"

// *****************************************************************************
// Author: Connor Williams
// Date: July 16, 2021
// Course: CS163 Data Structures
// Assignment: Program 2
// Filename: Prog2_Williams_queue.h
// *****************************************************************************
// This file contains a "q_node" structure and a class Abstract Data Type, named 
// "queue". This Abstract Data Type is used to specifically work with the
// "q_node" Circular Linked List data structure, adding, removing, copying, or 
// displaying its contents. These contents, within the "q_node", make up the 
// information for tasks or steps in completing an activity of the user's 
// choice. All member functions (not including the constructor or destructor) 
// within the Abstract Data Type return an integer value to represent success or 
// failure of an operation to the client. Arguments that will be passed in member 
// functions include objects of the "task"  and "queue" class data type for 
// adding and copying purposes, respectively.
// *****************************************************************************



// - - - - - S T R U C T U R E S - - - - -
//
// This structure manages one node structure ("q_node") that holds a "new_task"
// object of the "task" class data type and a next pointer to the "q_node" node
// structure.
struct q_node
{
  task new_task; //New task or step of the "task" class data type
  q_node * next; //Next pointer to the "q_node" structure data type
};
// -----------------------------------------------------------------------------



// - - - - - C L A S S E S - - - - -
//
// This class manages a Circular Linked List (CLL) of task entrys for completing
// a particular activity, chosen by the user. It allows for adding and removing
// task entry objects to the rear and from the front of the list, respectively, 
// and for copying of a queue object by passing in objects as arguments inputted 
// from the client. It also displays all contents of the list for debugging 
// purposes.
class queue
{
  public:
    queue();                              //Constructor, initializes data member
                                          //to NULL
    ~queue();                             //Destructor, deallocates data member
                                          //and resets to NULL
    int enqueue(const task & to_add);     //Adds object to rear of circular list
    int dequeue();                        //Removes object from front of list
    int display_all() const;              //Displays all queues in list
    int copy(queue & copy_to);            //Copy to a queue object

  private:
    q_node * rear; //Pointer to the rear of the circular linked list
};
// -----------------------------------------------------------------------------




