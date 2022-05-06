#include "Cell_Survey_Williams.h"
using namespace std;

// ****************************************************************************
// Author: Connor Williams
// Date: July 6, 2021
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
    app_head = NULL; //Set application list head pointer to NULL
}



// Destructor deallocates all data members memory and resets them to zero. This
// member function has no return type.
cell_survey::~cell_survey()
{
    app_node * app_temp = NULL; //Initialize temporary pointer for application
                                //list to NULL, for traversing
    use_node * use_temp = NULL; //Initialze temporary pointer for usage list
                                //to NULL, for traversing

    //Loop through the application list and deallocate everything.
    while (app_head)
    {
      //Loop through the usage list and deallocate everything.
      while (app_head->use_head)
      {
        use_temp = app_head->use_head->next_use; //Temp pointer gets the value
	                                         //of the next usage head
						 //pointer
	delete app_head->use_head;               //Deallocate usage head
	app_head->use_head = use_temp;           //Usage head gets the value of
	                                         //the next node
      }
      app_temp = app_head->next_app; //Temp gets the value of the next app head
      delete app_head;               //Deallocate application head
      app_head = app_temp;           //App head gets the value of the next node
    }
}



// This member function takes the user's input for information about an
// application and copies it to a correctly sized, newly allocated application.
// This function takes the "name", "type", and "description" arrays of
// characters, passed by array, as well as the object "an_app" of the 
// "cell_app" structure data type, passed by reference, as arugments and 
// returns an integer to represent a success or failure of the operation.
int cell_survey::set_app(char name[], char type[], char description[], 
		         cell_app & an_app)
{
    if (!name || !type || !description) return 0;

    if (an_app.name) delete [] an_app.name;
    if (an_app.type) delete [] an_app.type;
    if (an_app.description) delete [] an_app.description;

    an_app.name = new char[strlen(name) + 1];
    strcpy(an_app.name, name);

    an_app.type = new char[strlen(type) + 1];
    strcpy(an_app.type, type);

    an_app.description = new char[strlen(description) + 1];
    strcpy(an_app.description, description);

    return 1;
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
    //application information.
    app_node * temp = new app_node; //Dynamically allocate new node for
                                    //temporary pointer
    temp->next_app = NULL;          //Set temporary's next pointer to NULL
    temp->use_head = NULL;          //Set temporary's usage head pointer to 
                                    //NULL

    //Dynamically allocate the applications "name" array to the correct size
    //and then copy the client inputted "name" over.
    temp->app_data.name = new char[strlen(app.name) + 1];
    strcpy(temp->app_data.name, app.name);

    //Dynamically allocate the application's "type" array to the correct
    //size and then copy the client inputted "type" over.
    temp->app_data.type = new char[strlen(app.type) + 1];
    strcpy(temp->app_data.type, app.type);

    //Dynamically allocate the applications "description" array to the
    //correct size and then copy the client inputted "description" over.
    temp->app_data.description = new char[strlen(app.description) + 1];
    strcpy(temp->app_data.description, app.description);

    //Check if the list is empty.
    if (!app_head)
    {
      app_head = temp; //Head gets the value of temp
      return 1;        //Returns a success
    }
    //Check if temp's name is less than or equal to the current application 
    //node's name, alphabetically.
    if (strcmp(temp->app_data.name, 
	       app_head->app_data.name) <= 0)
    {
      temp->next_app = app_head; //Temp's next pointer get the value of head
      app_head = temp;           //Head gets the value of the temp pointer
      return 1;                  //Returns a success
    }
    return add_new(app_head->next_app, app); //Recursively place the new
                                             //application in its correct
					     //alphabetically position and
					     //returns success or failure
}



// This member function passes in a head pointer to the "app_node" node 
// structure and an object of the "cell_app" structure data
// type, inputted from the client, and adds it to the list of cellphone 
// applications. Whether the list is empty or not, the cellphone application 
// to be added is sorted alphabetically by name. This member function takes the 
// head pointer to the "app_node" and the constant "app" object of the 
// "cell_app" structure data type, passed by reference, as arguments and 
// returns an integer to represent success of failure of the operation.
int cell_survey::add_new(app_node * & app_head, const cell_app & app)
{
    if (!app.name || !app.type || !app.description)
      return 0; //Returns a failure

    //Dynamically allocate a temporary pointer to hold user input cellphone
    //application information.
    app_node * temp = new app_node; //Dynamically allocate new node for
                                    //temporary pointer
    temp->next_app = NULL;          //Set temporary's next pointer to NULL
    temp->use_head = NULL;          //Set temporary's usage head pointer to 
                                    //NULL

    //Dynamically allocate the applications "name" array to the correct size
    //and then copy the client inputted "name" over.
    temp->app_data.name = new char[strlen(app.name) + 1];
    strcpy(temp->app_data.name, app.name);

    //Dynamically allocate the application's "type" array to the correct
    //size and then copy the client inputted "type" over.
    temp->app_data.type = new char[strlen(app.type) + 1];
    strcpy(temp->app_data.type, app.type);

    //Dynamically allocate the applications "description" array to the
    //correct size and then copy the client inputted "description" over.
    temp->app_data.description = new char[strlen(app.description) + 1];
    strcpy(temp->app_data.description, app.description);

    //Check if the list is empty.
    if (!app_head)
    {
      app_head = temp; //Head gets the value of temp
      return 1;        //Returns a success
    }
    //Check if temp's name is less than or equal to the current application 
    //node's name, alphabetically.
    if (strcmp(temp->app_data.name, 
	       app_head->app_data.name) <= 0)
    {
      temp->next_app = app_head; //Temp's next pointer get the value of head
      app_head = temp;           //Head gets the value of the temp pointer
      return 1;                  //Returns a success
    }
    return add_new(app_head->next_app, app); //Recursively place the new
                                             //application in its correct
					     //alphabetically position and
					     //returns success or failure
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

    //Loop through the list, displaying each application.
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



// This member function adds usage characteristics for one user's survey about
// a particular application, searched for by name. All added usage information
// is sorted by most frequently used (hours per day). This function takes a 
// "name_match" array of characters, passed by array, and an object "use" of
// the "cell_usage" data type, passed by reference, as arguments and returns
// an integer to represent a success or failure of the operation.
int cell_survey::insert_usage(char name_match[], const cell_usage & use)
{
    //Checks if any user inputs aren't allocated correctly or if the list is
    //empty.
    if (!use.user_name || !use.use_reason || !app_head)
      return 0; //Returns a failure

    use_node * temp = new use_node; //Allocate a new usage node to temp
    temp->next_use = NULL;          //Temp's next pointer gets the value NULL


    //Dynamically allocate the usage node's "user_name" array to the
    //correct size and then copy the client inputted "user_name" over.
    temp->use_data.user_name = new char[strlen(use.user_name) + 1];
    strcpy(temp->use_data.user_name, use.user_name);

    //Dynamically allocate the usage node's "use_reason" array to the
    //correct size and then copy the client inputted "use_reason" over.
    temp->use_data.use_reason = new char[strlen(use.use_reason) + 1];
    strcpy(temp->use_data.use_reason, use.use_reason);

    //Set the usage node's "frequency" to equal the client inputted 
    //"frequency".
    temp->use_data.frequency = use.frequency;
    
    //Check if the name to search by matches the application list head's
    //name.
    if (!strcmp(app_head->app_data.name, name_match))
    {
      //Check if the usage list within the application list is empty.
      if (!app_head->use_head)
      {
	app_head->use_head = temp; //The usage head pointer within the
	                           //application's node get the value temp
	return 1;                  //Returns a success
      }
      //Check if the user inputted frequency is less than or equal to the 
      //usage head pointer's frequency within the application's node.
      if (temp->use_data.frequency >= app_head->use_head->use_data.frequency)
      {
        temp->next_use = app_head->use_head; //Temp's next usage pointer gets
	                                     //the value of the usage head
					     //within the application node
	app_head->use_head = temp;           //Usage head within the
	                                     //application node gets the
					     //value temp
	return 1;                            //Returns a success
      }
      //Check if there is only one node in the usage list within the
      //application node.
      if (!app_head->use_head->next_use)
      {
        app_head->use_head->next_use = temp; //Usage head's next pointer within
	                                     //the application node gets the
					     //value temp
	return 1;                            //Returns a success
      }
      //Current use node gets the value of the usage head's next pointer within
      //the application node.
      use_node * current = app_head->use_head->next_use;
      //Previous use node gets the value of the usage head within the
      //application node.
      use_node * previous = app_head->use_head;

      //Traverse the usage list within the appplication node.
      while (current && temp->use_data.frequency < current->use_data.frequency)
      {
	previous = current;          //Previous gets the value current
	current = current->next_use; //Current gets the value of current's next
	                             //pointer
      }
      temp->next_use = current;      //Temp's next pointer gets the value
                                     //current
      previous->next_use = temp;     //Previous' next usage pointer gets the 
                                     //value temp
      return 1;                      //Returns a success
    }

    //Recursive call checks the next application in the list if the name
    //search did not find a match and returns a success or failure.
    return insert_usage(app_head->next_app, name_match, use);
}

    

// This member function adds usage characteristics for one user's survey about
// a particular application, searched for by name. All added usage information is
// sorted by most frequently used (hours per day). This function takes a head
// pointer to the application node, passed by reference, a "name_match" array 
// of characters, passed by array, and an object "use" of the "cell_usage" data 
// type, passed by reference, as arguments and returns an integer to represent 
// a success or failure of the operation.
int cell_survey::insert_usage(app_node * & app_head, char name_match[], const cell_usage & use)
{
    //Checks if any user inputs aren't allocated correctly or if the list is
    //empty.
    if (!use.user_name || !use.use_reason || !app_head)
      return 0; //Returns a failure

    use_node * temp = new use_node; //Allocate a new usage node to temp
    temp->next_use = NULL;          //Temp's next pointer gets the value NULL


    //Dynamically allocate the usage node's "user_name" array to the
    //correct size and then copy the client inputted "user_name" over.
    temp->use_data.user_name = new char[strlen(use.user_name) + 1];
    strcpy(temp->use_data.user_name, use.user_name);

    //Dynamically allocate the usage node's "use_reason" array to the
    //correct size and then copy the client inputted "use_reason" over.
    temp->use_data.use_reason = new char[strlen(use.use_reason) + 1];
    strcpy(temp->use_data.use_reason, use.use_reason);

    //Set the usage node's "frequency" to equal the client inputted 
    //"frequency".
    temp->use_data.frequency = use.frequency;
    
    //Check if the name to search by matches the application list head's
    //name.
    if (!strcmp(app_head->app_data.name, name_match))
    {
      //Check if the usage list within the application list is empty.
      if (!app_head->use_head)
      {
	app_head->use_head = temp; //The usage head pointer within the
	                           //application's node get the value temp
	return 1;                  //Returns a success
      }
      //Check if the user inputted frequency is less than or equal to the 
      //usage head pointer's frequency within the application's node.
      if (temp->use_data.frequency >= app_head->use_head->use_data.frequency)
      {
        temp->next_use = app_head->use_head; //Temp's next usage pointer gets
	                                     //the value of the usage head
					     //within the application node
	app_head->use_head = temp;           //Usage head within the
	                                     //application node gets the
					     //value temp
	return 1;                            //Returns a success
      }
      //Check if there is only one node in the usage list within the
      //application node.
      if (!app_head->use_head->next_use)
      {
        app_head->use_head->next_use = temp; //Usage head's next pointer within
	                                     //the application node gets the
					     //value temp
	return 1;                            //Returns a success
      }
      //Current use node gets the value of the usage head's next pointer within
      //the application node.
      use_node * current = app_head->use_head->next_use;
      //Previous use node gets the value of the usage head within the
      //application node.
      use_node * previous = app_head->use_head;

      //Traverse the usage list within the appplication node.
      while (current && temp->use_data.frequency < current->use_data.frequency)
      {
	previous = current;          //Previous gets the value current
	current = current->next_use; //Current gets the value of current's next
	                             //pointer
      }
      temp->next_use = current;      //Temp's next pointer gets the value
                                     //current
      previous->next_use = temp;     //Previous' next usage pointer gets the 
                                     //value temp
      return 1;                      //Returns a success
    }

    //Recursive call checks the next application in the list if the name
    //search did not find a match and returns a success or failure.
    return insert_usage(app_head->next_app, name_match, use);
}



// This member function displays all the usage characteristic information
// associated with every cellphone application that matches a searched for
// type. This function takes a "type_match" array of characters and returns
// an integer to represent success or failure.
int cell_survey::display_usage(char type_match[]) const
{
    if (!app_head) return 0; //The list is empty, operation fails

    app_node * app_temp = app_head; //Temp application pointer gets the value
                                    //of the application's head pointer

    //Loop through the application list, searching for type matches.
    while (app_temp)
    {
      //Check if user inputted type matches the current application node's
      //type.
      if (!strcmp(app_temp->app_data.type, type_match))
      {
        use_node * use_temp = app_temp->use_head; //Temp usage pointer gets the
	                                          //valud of the usage head
						  //within the temp app pointer
	//Loop through the usage list within the application node and display
	//all.
	while(use_temp)
	{
          cout << "Surveyor Name: " << use_temp->use_data.user_name << endl
	       << "Reason for Use: " << use_temp->use_data.use_reason << endl
	       << "Average # of Hours Used per Day: " 
	       << use_temp->use_data.frequency << " Hours" << endl << endl;
	  use_temp = use_temp->next_use; //Temp usage pointer gets the value of
	                                 //its next node
	}
      }
      app_temp = app_temp->next_app; //Temp application pointer gets the value
                                     //of its next node
    }
    return 1; //Returns a success
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

