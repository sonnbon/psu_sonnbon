#include "Cell_Survey_Williams.h"
using namespace std;

// ****************************************************************************
// Author: Connor Williams
// Date: July 2, 2021
// Course: CS163 Data Structures
// Assignment: Program 1
// Filename: Main_Williams.cpp
// ****************************************************************************
// This file contains the necessary variables, objects, and function calls to 
// test for the successfuly operation of creating, manipulating, and removing
// cellphone applications to and from a list of applications..................
//
//
// ****************************************************************************

int main()
{
    //Variable definitions
    char name[SIZE];        //To be temporary array for application name
    char type[SIZE];        //To be temporary array for application type
    char description[SIZE]; //To be temporary array for application description
    char response;          //To be user's response yes or no
    cell_app an_app;        //Holds the information for one application
    cell_survey app_list;   //Holds the information for many applications

    //Test adding cellphone applications to a list of applications and making
    //sure they are sorted alphabetically.
    do
    {
      cout << "Please enter a cellphone application name to be added: ";
      cin.get(name, SIZE, '\n');
      cin.ignore(100, '\n');
      an_app.name = new char[strlen(name) + 1];
      strcpy(an_app.name, name);

      cout << "Please enter the type of application (financial, social media,\n"
	   << "etc.): ";
      cin.get(type, SIZE, '\n');
      cin.ignore(100, '\n');
      an_app.type = new char[strlen(type) + 1];
      strcpy(an_app.type, type);

      cout << "Please enter a description of the application: ";
      cin.get(description, SIZE, '\n');
      cin.ignore(100, '\n');
      an_app.description = new char[strlen(description) + 1];
      strcpy(an_app.description, description);

      if(!app_list.add_new(an_app))
        cerr << "There is nothing to add. Try again...\n\n";

      cout << "Enter another application? Yes (y) or No (n): ";
      cin >> response;
      cin.ignore(100, '\n');

    } while(again(response));
 
    //Test displaying all the nodes from the list.
    if(!app_list.display_all())
      cerr << "There is nothing in the list...\n\n";

    return 0;
}
