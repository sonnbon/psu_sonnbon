#include "Prog2_Williams_task.h"
using namespace std;

// *****************************************************************************
// Author: Connor Williams
// Date: July 13, 2021
// Course: CS163 Data Structures
// Assignment: Program 2
// Filename: Prog2_Williams_queue.cpp
// *****************************************************************************
//
// *****************************************************************************


/*
struct q_node
{
  task new_task; //New task or step of the "task" class data type
  q_node * next; //Next pointer to the "q_node" structure data type
};
*/
//    q_node * rear; //Pointer to the rear of the circular linked list



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
  while (rear)
  {
    q_node * temp = NULL;      //Initialize temp pointer to q_node to NULL
    q_node * current = rear;   //Initialize current pointer to q_node to rear

    do
    {
      temp = rear->next;       //Set temp pointer to its next pointer
      delete current;          //Delete current pointer
      current = temp;          //Set current pointer to temp pointer
    } while (current != rear); //Continue loop until current is equal to rear
    rear = NULL;               //Set rear pointer to NULL
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
    rear = new node;             //Rear gets the value new node
    rear->new_task.copy(to_add); //Copy the passed in object to rear's data
    rear->next = rear;           //Rear's next pointer gets the value of itself
  }
  else
  {
    q_node * temp = rear->next; //Initialize temp pointer to rear's next pointer
    rear->next = new node;      //Rear's next pointer gets the value new node
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

  q_node * temp = rear->next->next; //Initializes temp pointer to get the value
                                    //of rear's next's next's pointer
  delete rear->next;                //Deallocate rear's next pointer
  rear->next = temp;                //Rear's next pointer gets the value of temp
  return 1;                         //Returns a success of the operation
}




int queue::display_all() const
{

}




int queue::copy_queue(queue & to_copy)
{

}



