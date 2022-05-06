#include "Prog2_Williams_queue.h"
using namespace std;

// *****************************************************************************
// Author: Connor Williams
// Date: July 16, 2021
// Course: CS163 Data Structures
// Assignment: Program 2
// Filename: Prog2_Williams_queue.cpp
// *****************************************************************************
// This file contains the member functions of the "queue" class, which allows
// for a Circular Linked List (CLL) of task entries to complete a particular
// activity, in which each node holds information on a "task" object and
// a next pointer to itself. From the client, a user can add a task entry to a 
// list of tasks, display all the tasks in the list, enqueue a task to the rear
// of the CLL, dequeue a task from the front of the CLL, and copy an entire 
// queue object of tasks to a passed in object. The class is working with a CLL 
// data structure and is doing so with one (rear pointer) data member pointing 
// to an object of the "task" class, which holds all necessary information for a 
// task entry. The "enqueue" and "copy_queue" member functions pass in an object 
// of the "task" class and "queue" class, respectively, in order to add to the 
// CLL and copy the CLL. All member functions return an integer data type to 
// the client to represent success or failure of the operation.
// ****************************************************************************



// The constructor initializes the data member to NULL. This constructor takes
// no arguments and returns nothing.
queue::queue()
{
  rear = NULL; //Rear pointer set to NULL
}



// The destructor deallocates any dynamically allocated memory and resets it to
// NULL. This destructor takes no arguments and returns nothing.
queue::~queue()
{
  //Check if rear pointer is already NULL.
  if (rear)
  {
    q_node * temp = NULL;      //Initialize temp pointer to NULL
    q_node * real_rear = rear; //Initialize real_rear pointer to rear pointer

    while (rear->next != real_rear) //Continue loop until rear equals real_rear
    {
      temp = rear->next->next; //Set temp pointer to rear's next's next pointer
      delete rear->next;       //Delete rear's next pointer
      rear->next = temp;       //Set rear's next pointer to temp pointer
    }

    delete rear; //Delete rear's last pointer
    rear = NULL; //Set rear pointer to NULL
  }
}



// This member function adds a task to complete an activity to the rear of a
// Circular Linked List. If the list is empty, a new node is allocated and
// rear points to itself. Otherwise, a new node is allocated and the rear
// points to that new node. This member function takes a object "to_add" of the
// constant "task" class data type, passed by reference, as an argument and
// returns an integer to represent the completion of the operation.
int queue::enqueue(const task & to_add)
{
  //Check if the list is empty
  if (!rear)
  {
    rear = new q_node;           //Rear gets the value new node
    rear->new_task.copy(to_add); //Copy the passed in object to rear's data
    rear->next = rear;           //Rear's next pointer gets the value of itself
  }

  else
  {
    q_node * temp = rear->next; //Initialize temp pointer to rear's next pointer
    rear->next = new q_node;    //Rear's next pointer gets the value new node
    rear = rear->next;          //Traverse to next rear node
    rear->new_task.copy(to_add); //Copy the passed in object to rear's data
    rear->next = temp;          //Rear's next pointer gets the value of temp
  }

  return 1;                     //Returns completion of operation
}



// This member function removes a task to complete an activity from the front
// of a Circular Linked List. If the list is empty, nothing happens. Otherwise,
// the front node of the list is removed. This member function takes no 
// arguments and returns an integer to represent a success or failure of the
// operation.
int queue::dequeue()
{
  //Check if list is empty
  if (!rear)
    return 0; //Returns a failure of the operation

  if (rear == rear->next)
  {
    delete rear;
    rear = NULL;
    return 1;
  }
  
  q_node * temp = rear->next->next;   //Initializes temp pointer to get the 
                                      //value of rear's next's next's pointer
  delete rear->next;                  //Deallocate rear's next pointer
  rear->next = temp;                  //Rear's next pointer gets the value of 
                                      //temp

  return 1;                           //Returns a success of the operation
}



// This member function displays all the contents of the Circular Linked List,
// one node at a time by traversing through the list and calling "task" class
// display function on the "new_task" object each time. This constant member 
// function takes no arguments and returns an integer to represent a success
// or failure of the operation.
int queue::display_all() const
{
  //Check if list is empty.
  if (!rear)
    return 0; //Returns a failure of operation
   
  q_node * front = rear->next;   //Set front pointer to get rear's next value
  q_node * current = rear->next; //Set current pointer to get rear's next value

  //Traverse through list until rear pointer is equal to real_rear.
  do
  {
    current->new_task.display(); //Display contents of one task
    current = current->next;     //Rear pointer gets the value of its next 
                                 //pointer

  } while (current != front);    //Stop if rear is equal to real_rear

  return 1;                      //Returns a success of the operation
}



// The member function copies an object of the "queue" class to another object
// of the "queue" class. This member function takes the object "to_copy" of the
// constant "queue" class data type, passed by reference, as an argument and 
// returns an integer to represent success or failure of the operation.
int queue::copy(queue & copy_to)
{
  //Check if list is empty
  if (!rear)
      return 0; //Return a failure of operation

  //Check if passed in object is empty.
  while (copy_to.rear)
      copy_to.dequeue(); //Delete a node from the passed in object

  q_node * front = rear->next;   //Set front to the rear's next pointer
  q_node * current = rear->next; //Set current to the rear's next pointer

  //Traverse each node of the current classes "queue" and copy it to another
  //passed in object of the "queue" class data type.
  do
  {
    copy_to.enqueue(current->new_task); //Copy current object to passed in 
                                        //object
    current = current->next;            //Current gets the value of its next 
                                        //pointer
  } while (current != front);           //End loop when current equals front
  
  return 1;                             //Returns a success of the operation
}



