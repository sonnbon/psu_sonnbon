#include "Prog2_Williams_task.h"
using namespace std;

// *****************************************************************************
// Author: Connor Williams
// Date: July 23, 2021
// Course: CS163 Data Structures
// Assignment: Program 2
// Filename: Prog2_Williams_task.cpp
// *****************************************************************************
// This file contains the member functions of the "task" class, which allows for
// the creation, copying, and displaying of one "task" object, holding
// information on the task number ("task_num"), task description ("plan"), and 
// task notes ("notes"). The class is working with its three data members,
// an integer ("task_num") and two dynamically allocated arrays ("plan" and
// "notes"). The "create_entry" and "copy" member functions take information
// from the client in order to create and copy a task entry to complete a
// particular activity, respectively. The "create_entry" member function passes
// in an integer and two arrays to be set or copied to the classes data members.
// The "copy" member function passes in a "task" object to be set and copied to
// another object. All member functions return an integer data type to the 
// client to represent success or failure of the operation.
// ****************************************************************************



// The constructor initializes all data members of the abstract data type to 0
// or NULL. This constructor takes no arguments and returns nothing.
task::task()
{
  task_num = 0; //Set task number to 0
  plan = NULL;  //Set task description to NULL
  notes = NULL; //Set task notes to NULL
}



// The destructor deallocates any dynamically allocated memory and resets all
// data members to 0 or NULL. This destructor takes no arguments and returns 
// nothing.
task::~task()
{
  task_num = 0;      //Reset task number to 0

  //Checks that task description is not already NULL.
  if (plan)
  {
    delete [] plan;  //Deallocate task description's memory
    plan = NULL;     //Reset task description to NULL
  }

  //Checks that task notes is not already NULL.
  if (notes)
  {
    delete [] notes; //Deallocate task notes' memory
    notes = NULL;    //Reset task notes to NULL
  }
}



// This member function creates a task entry for an activity inputted by the
// client. It sets the task number, plan, and notes to the client
// inputted respective data. This member function takes an integer "num_toadd"
// and two arrays of characters, "plan_toadd" and "notes_toadd", as arguments 
// and returns an integer to represent success or failure of the operation.
int task::create_entry(int num_toadd, char plan_toadd[], char notes_toadd[])
{
  task_num = num_toadd; //Set task number to inputted task number

  //Check if task description is already pointing to memory
  if (plan)
  {
    delete [] plan; //Deallocate plan memory
    plan = NULL;    //Set plan to NULL
  }
  
  //Dynamically allocate memory of the right size to the task description and
  //copies the client input information to it.
  plan = new char[strlen(plan_toadd) + 1];
  strcpy(plan, plan_toadd);

  //Check if task notes are already pointing to memory
  if (notes)
  {
    delete [] notes; //Deallocate notes memory
    notes = NULL;    //Set notes to NULL
  }

  //Dynamically allocate memory of the right size to the task notes and copies
  //the client input information to it.
  notes = new char[strlen(notes_toadd) + 1];
  strcpy(notes, notes_toadd);

  return 1; //Returns a success of the operation
}



// This member function copies client inputted data for a task to an object by
// returning the called function "create_entry". This member function takes the 
// object "to_add" of the constant "task" class data type, passed by reference, 
// as an argument and returns an integer to represent success or failure of the 
// operation.
int task::copy(const task & to_add)
{
  //Returns success or failure of the operation to create a task entry
  return create_entry(to_add.task_num, to_add.plan, to_add.notes);
}



// This member function displays the data set and allocated to the "task" class.
// This member function is constant, takes no arguments, and returns an integer 
// to represent success or failure of the operation.
int task::display() const
{
  //Checks that data has been added to the data members
  if (0 == task_num || !plan || !notes)
    return 0; //Returns a failure of the operation

  cout << "Task Number " << task_num << ": " << plan << endl
       << "Notes for next time: " << notes << endl << endl;

  return 1; //Returns a success of the operation
}



// This function checks whether the user would like to repeat an action they
// just did. This function takes a character "response" as an argument and 
// returns true or false to represent a yes or no response.
bool again(char response)
{
    //Variable definitions
    bool again = false; //To hold whether the user response is a yes or no

    response = toupper(response); //Capitalize response character

    if (response == 'Y')
      again = true;               //Set again to true

    return again; //Returns true or false
}



