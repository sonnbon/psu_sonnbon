#include "Cell_Survey_Williams.h"
using namespace std;

// ****************************************************************************
// Author: Connor Williams
// Date: July 2, 2021
// Course: CS163 Data Structures
// Assignment: Program 1
// Filename: Cell_Survey_Williams.cpp
// ****************************************************************************
// This file contains the member functions of the "cell_survey" class, which
// allow for a Linear Linked List of cellphone applications, in which each
// application has a Linear Linked List of user's usage characteristics, to be
// initialized, manipulated, and destroyed. From the client, a user can add a
// cellphone application to a list of applications, display all the
// applications in the list, insert user usage characteristics for a specific
// cellphone application, display all usage characteristics of cellphone
// applications of a specific type, and remove a specific cellphone application
// from the list. The class is working with two Linear Linked List data 
// structures and is doing so with two (head and tail) data members pointing to
// a cellphone applications node structure, which holds all necessary
// information for an application as well as a head pointer to a cellphone
// usage characteristic node, which holds all the necessary information for a
// user's usage characteristics. The classes "add_new" and "insert_usage" 
// member functions pass in the "cell_app" and "cell_usage" structure data
// types by reference, respectively, in order to manipulate the Linear Linked
// List. The "insert_usage", "display_usage", and "remove_app" member functions
// pass in arrays of characters for match searching purposes. All functions
// return an integer data type to the client to represent success or failure of
// the operation.
// ****************************************************************************



// Constructor initializes all data members to zero. This member function has
// no return type.
cell_survey::cell_survey()
{
    app_head = app_tail = NULL; //Set both head and tail pointers to NULL
}



// Destructor deallocates all data members memory and resets them to zero. This
// member function has no return type.
cell_survey::~cell_survey()
{
    app_node * temp = NULL; //Initialize temporary pointer to NULL, 
                            //for traversing

    //Loop through the list and deallocate everything.
    while (app_head)
    {
      temp = app_head->next_app; //Temp gets the value of head arrow next
      delete app_head;           //Deallocate the current head
      app_head = temp;           //Set head to the next node in the list
    }
    app_tail = NULL;             //Set tail pointer to NULL
}



// This member function passes in an object of the "cell_app" structure data
// type, inputted from the client, and adds it to the list of cellphone 
// applications. Whether the list is empty or not, the the cellphone
// application to be added is sorted alphabetically by name. This member
// function takes the constant "app" object of the "cell_app" structure data
// type, passed by reference, as an argument and returns an integer to 
// represent the success or failure of this operation.
int cell_survey::add_new(const cell_app & app)
{
    if (!app.name || !app.type || !app.description)
      return 0; //Returns a failure

    //Dynamically allocate a temporary pointer to hold user input cellphone
    //application information
    app_node * temp = new app_node; //Dynamically allocate new node for
                                    //temporary pointer
    temp->next_app = NULL;          //Set temporary's next pointer to NULL

    //Dynamically allocate the applications "name" array to the correct size
    //and then copy the client inputted "name" over.
    temp->app_data.name = new char[strlen(app.name) + 1];
    strcpy(temp->app_data.name, app.name);

    //Dynamically allocate the application's "type" array to the correct
    //size and then copy the client inputted "type" over.
    temp->app_data.type = new char[strlen(app.name) + 1];
    strcpy(temp->app_data.type, app.type);

    //Dynamically allocate the applications "description" array to the
    //correct size and then copy the client inputted "description" over.
    temp->app_data.description = new char[strlen(app.description) + 1];
    strcpy(temp->app_data.description, app.description);

    //Check if the list is empty
    if (!app_head)
    {
      app_head = app_tail = temp; //Set head and tail pointer to temporary
                                  //pointer
      return 1;                   //Returns a success
    }

    //If the user inputted application starts with a letter less than
    //the head's data, then the temporary pointer becomes the beginning of
    //the list.
    if (strcmp(temp->app_data.name, app_head->app_data.name) < 0)
    {
      temp->next_app = app_tail = app_head; //Temp's next pointer points to
                                            //the tail and head
      app_head = temp;                      //Head points to temp
      return 1; //Returns a success
    }

    app_node * current = app_head->next_app; //Initialize current pointer to
                                             //head's next pointer
    app_node * previous = app_head;          //Initialize previous pointer to
                                             //head
    //If there is only one node in the list, then the temporary pointer
    //becomes the second node in the list.
    if (!current)
      app_head->next_app = app_tail = temp; //Head's next pointer points to
                                            //the tail and temp
    else
    {
      //Traverse through the entire list while the temporary pointer's name
      //is less than the current pointer's name alphabetically.
      while (current && 
            (strcmp(temp->app_data.name, current->app_data.name) > 0))
      {
	//If the temporary pointer's name is greater than the previous
	//pointer's name and less than the current pointer's name
	//alphabetically, then add the temp node between the two other nodes.
        if ((strcmp(temp->app_data.name, previous->app_data.name) > 0) &&
	    (strcmp(temp->app_data.name, current->app_data.name) < 0))
        {
	  temp->next_app = current;  //Temp's next pointer get the value of
	                             //current
          previous->next_app = temp; //Previous' next pointer get the value of
	                             //temp
        }
        previous = current;          //Drag previous up to current
        current = current->next_app; //Drag current up to current's next
	                             //pointer
      }
      app_tail = previous;           //Set the tail to be the last node of the
                                     //list
      //At the last node, if its pointer's name is still less than the
      //temporary pointer's name alphabetically, then add temp's node to the
      //end of the list.
      if (strcmp(previous->app_data.name, temp->app_data.name) < 0)
        previous->next_app = app_tail = temp; //Previous' next pointer gets
                                              //the value of the tail and temp
    }
    return 1; //Returns a success
}



// This member function displays all the cellphone applications, sorted 
// alphabetically by name, if the list is not empty, by traversing through
// the list. This function takes no arguments and returns an integer to 
// represent the success or failure of this operation.
int cell_survey::display_all() const
{
    //Variable definitions
    int count = 0; //Counts how many applications are in the list

    if (!app_head) return 0; //The list is empty, operation fails

    app_node * current = app_head; //Initialize current pointer to head pointer

    //Loop through the list, displaying each application
    while (current)
    {
      ++count; //Increment one count, keeping track of number of nodes
      cout << "Cellphone Application: " << current->app_data.name << endl
	   << "Application Type: " << current->app_data.type << endl
	   << "Application Description: " << current->app_data.description
	   << endl << endl;
      current = current->next_app; //Set current pointer to current arrow next
    }
    return count; //Returns a success and the number of nodes in the list
}



int cell_survey::insert_usage(char name_match[], const cell_usage & use)
{
    return 0;
}



int cell_survey::display_usage(char type_match[]) const
{
    return 0;
}



int cell_survey::remove_app(char name_match[])
{
    return 0;
}



//This function checks whether the user would like to repeat an action they
//just did. This function takes a character "response" as an argument and 
//returns true or false to represent a yes or no response.
bool again(char response)
{
    //Variable definitions
    bool again = false; //To hold whether the user response is a yes or no

    response = toupper(response); //Capitalize response character
    if (response == 'Y')
      again = true;
    return again; //Returns true or false
}

