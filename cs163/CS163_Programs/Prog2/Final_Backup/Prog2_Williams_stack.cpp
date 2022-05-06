#include "Prog2_Williams_stack.h"
using namespace std;

// *****************************************************************************
// Author: Connor Williams
// Date: July 23, 2021
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



// The constructor initializes the data members to NULL or 0. This constructor 
// takes no arguments and returns nothing.
stack::stack()
{
  head = NULL;   //Set head to NULL
  top_index = 0; //Set top index to 0.
}




// The destructor deallocates any dynamically allocated memory and resets it to
// NULL. This destructor takes no arguments and returns nothing.
stack::~stack()
{
  node * temp = NULL;  //Set temp pointer to NULL

  //Check if the list is empty
  while (head)
  {
    temp = head->next; //Set temp to head's next pointer

    //Check if the array of queue's is NULL
    if (head->trials)
    {
      delete [] head->trials; //Delete head's array of queue's
      head->trials = NULL;    //Set head's array of queue's to NULL
    }

    delete head;              //Delete head
    head = temp;              //Head gets the value of temp
  }
  
  top_index = 0;       //Set top index to 0
}



// This member function pushes or adds an object of the "queue" class data
// type to the top of an object of the "stack" class data type. This member
// function takes an object "to_add" of the constant "queue" class data type,
// passed by reference, as an argument and returns an integer to represent
// the success or failure of an operation.
int stack::push(const queue & to_add)
{
  //Check if that passed in object's list is empty
  if (to_add.is_empty())
    return 0; //Returns a failure of the operation

  //Check if the list is empty or, if not, if the top index is equal to the MAX
  //number of elements allowed in an array of queue's
  if (!head || (head && top_index == MAX))
  {
    node * temp = head;            //Temp gets the value of head
    head = new node;               //Dynamically allocate a new node to head
    head->trials = new queue[MAX]; //Dynamically allocate a new array of queue's
                                   //to head's trials
    head->trials[0].copy(to_add);  //The passed in object gets added to the
                                   //first element of the head's trials array
    head->next = temp;             //Head's next pointer gets the value of temp
    top_index = 1;                 //Set the top index to represent the next 
                                   //element of the array
    return top_index;              //Return the top index's value
  }

  head->trials[top_index].copy(to_add); //The passed in object gets added to the
                                        //top_index element of the head's trials
                                        //array
  ++top_index;                          //Increment the top index

  return top_index;                     //Return the top index's value
}



// This member function displays all objects of the "queue" class data type
// held within an object of the "stack" class data type. This constant member 
// function takes no arguments and returns an integer to represent the success
// or failure of an operation.
int stack::display_all() const
{
  //Check if list is empty
  if (!head)
    return 0; //Returns a failure of the operation
  
  node * current = head;   //Current gets the value of head
  int i = top_index;       //Set i to get the value of the top index
  int stack_num = count(); //Set the number of elements in the list to get the
                           //returned value of the count member function
  
  //Continue until current is NULL
  while (current)
  {
    do
    {
      --i; //Decrement the index

      //To separate the different queue's pushed to the stack, for readability
      cout << "\tTrial #" << stack_num << ":" << endl;

      current->trials[i].display_all(); //Current's indexed element of the 
                                        //trials array gets displayed
                                       
      //To separate the different queue's pushed to the stack, for readability
      cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" 
           << endl << endl;

      --stack_num; //Decrement the number of elements that there are in the
                   //array of queue's

    } while (i > 0); //Continue until index is equal to 0
    
    i = MAX;                 //Reset index to MAX number of elements an array of
                             //queue's can hold
    current = current->next; //Current gets the value of its next pointer
  } 

  return 1; //Returns a success of the operation
}



// This member function displays an object of the "queue" class data type from
// the top of the list of an object of the "stack" class data type. This 
// constant member function takes no arguments and returns an integer to 
// represent the success or failure of an operation.
int stack::display_top() const
{
  //Check if the list is empty
  if (!head)
    return 0; //Returns a failure of the operation

  int i = top_index;       //Set i to get the value of the top index
  int stack_num = count(); //Set the number of elements in the list to get the
                           //returned value of the count member function

  --i; //Decrement the index

  //To separate the different queue's pushed to the stack, for readability
  cout << "\tTrial #" << stack_num << ":" << endl;

  head->trials[i].display_all(); //Head's top indexed element of the trials
                                 //array gets displayed

  //To separate the different queue's pushed to the stack, for readability
  cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" 
       << endl << endl;

  return 1; //Returns a success of the operation
}



// This member function pops or removes the object of the "queue" class data
// type from the top of the list of an object of the "stack" class data type.
// The popped object is copied to a passed in object of the "queue" class data
// type. This member function takes an object "copy_to" of the "queue" class
// data type, passed by reference, as an argument and returns an integer to 
// represent success or faiure of the operation.
int stack::pop(queue & copy_to)
{
  //Check if the list is empty
  if (!head)
    return 0; //Returns a failure of the operation

  --top_index;                           //Decrement the top index
  copy_to.copy(head->trials[top_index]); //Copy queue to be popped to passed in
                                         //object

  //Check that the current array of queue's is not NULL and that the top index 
  //is at its first element.
  if (head->trials && top_index == 0)
  {
    node * temp = head->next; //Set temp to the head's next pointer
    delete [] head->trials;   //Delete head's array of queue's
    head->trials = NULL;      //Set head's array of queue's to NULL
    delete head;              //Delete head
    head = temp;              //Head gets the value of temp
    top_index = MAX;          //Reset top index to MAX number of elements that
                              //an array of queue's can hold
  }

  return 1; //Returns a success of the operation
}



// This member function counts the number of activities that have been pushed
// onto the stack. This constant member function takes no arguments and returns
// the count.
int stack::count() const
{
  //Check if the list is empty.
  if (!head)
    return 0; //Returns a failure of the operation

  node * current = head; //Set current to the value of the head pointer
  int count = 0;         //Set count to zero
  int i = top_index;     //Set i to get the value of the top index

  while (current)
  {
    do
    {
      --i;     //Decrement to the element at the top of the stack
      ++count; //Increment the count

    } while (i > 0); //Continue until the index is at the first element of the
                     //head
    
    i = MAX; //Reset i to get the value of MAX
    current = current->next; //Current get the value of its next pointer
  }

  return count; //Return the number of activities pushed onto the stack
}



