#include <iostream>
#include <cctype>
#include <cstring>

// *****************************************************************************
// Author: Connor Williams
// Date: July 23, 2021
// Course: CS163 Data Structures
// Assignment: Program 2
// Filename: Prog2_Williams_task.h
// *****************************************************************************
// This file contains a class Abstract Data Type, named "task". This data type 
// is used to specifically work with one object, creating, copying, or 
// displaying its contents, "task_num", "plan", and "notes". These contents make 
// up the information for one task or step in completing an activity of the 
// user's choice. All member functions (not including the constructor or 
// destructor) within the Abstract Data Type return an integer value to 
// represent success or failure of an operation to the client. Arguments that
// will be passed in member functions include an object of the "task" class data 
// type for copying purposes, and variables of integer and character data types 
// for object creation purposes.
// *****************************************************************************



// - - - - - C O N S T A N T S - - - - -
//
const int SIZE = 301; //Max size for any array of characters
// -----------------------------------------------------------------------------



// - - - - - P R O T O T Y P E S - - - - -
//
bool again(char response); //Checks if user wants to do an action again
// -----------------------------------------------------------------------------



// - - - - - C L A S S E S - - - - -
//
// This class manages one task entry's task number, description (plan), and
// notes for completing a particular activity, chosen by the user. It allows for 
// the creation and copying of one task entry by passing in integers, arrays, 
// and objects as arguments inputted from the client. It also displays a task 
// entry for debugging purposes.
class task
{
  public:
    task();                                //Constructor, initializes data
                                           //members to 0 or NULL
    ~task();                               //Destructor, deallocates dynamic
                                           //data members and resets all data
					                       //members to 0 or NULL
    int create_entry(int num_toadd,        //Creates a task entry from passed in
		     char plan_toadd[],            //information
		     char notes_toadd[]);
    int copy(const task & to_add);         //Makes a copy of the passed in 
                                           //object
    int display() const;                   //Displays data in object

  private:
    int task_num; //Task step number for activity
    char * plan;  //Description of activity's task
    char * notes; //Notes on how to improve step next time or what went wrong
};
// -----------------------------------------------------------------------------




