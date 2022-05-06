#include "Cell_Survey_Williams.h"
using namespace std;

// ****************************************************************************
// Author: Connor Williams
// Date: July 6, 2021
// Course: CS163 Data Structures
// Assignment: Program 1
// Filename: Main_Williams.cpp
// ****************************************************************************
// This file contains the necessary variables, objects, and function calls to 
// test for the successful operations of creating, manipulating, and removing
// cellphone applications to and from a list of applications. It will also
// allow a user to successfully create, manipulate, and remove a list of
// usage characteristics for each cellphone application that is added. In
// terms of the list of applications, a user can add to an empty list or a 
// list of already added applications and the new application will be 
// automatically sorted alphabetically. Calling the "display_all" function
// displays all the cellphone applications added, and is used to test whether
// the list is empty or, if there are list items, that it is sorted
// alphabetically. The user can do similar operations within each 
// cellphone application's information, creating and displaying usage
// characteristics from however many people are surveyed about their usage of
// a particular application. The "display_usage" function will display these
// usage characteristics that have been added by a particular cellphone
// application type, all sorted from longest use (hours per day) to shortest
// use. This display function will show all usage information for all 
// applications that match a particular type.................................
//
//
// ****************************************************************************

int main()
{
    //Variable definitions
    char name[SIZE];        //To be temporary array for application name
    char type[SIZE];        //To be temporary array for application type
    char description[SIZE]; //To be temporary array for application description
    char user_name[SIZE];   //To be temporary array for a user's name
    char use_reason[SIZE];  //To be temporary array for a user's reason for
                            //using an application
    char response;          //To be user's response yes or no
    cell_app an_app;        //Holds the information for one application
    cell_survey app_list;   //Holds the information for many applications
    cell_usage one_use;     //HOlds the information for one usage survey

    //Test displaying all the nodes from the list.
    if(!app_list.display_all())
      cerr << "There is nothing in the list...\n\n";

    //Test adding cellphone applications to a list of applications and making
    //sure they are sorted alphabetically.
    do
    {
      cout << "Please enter a cellphone application name to be added: ";
      cin.get(name, SIZE, '\n');
      cin.ignore(100, '\n');

      cout << "Please enter the type of application (financial, social media,\n"
	   << "etc.): ";
      cin.get(type, SIZE, '\n');
      cin.ignore(100, '\n');

      cout << "Please enter a description of the application: ";
      cin.get(description, SIZE, '\n');
      cin.ignore(100, '\n');

      if (!app_list.set_app(name, type, description, an_app))
        cerr << "You didn't enter anything...\n\n";

      if(!app_list.add_new(an_app))
        cerr << "There is nothing to add. Try again...\n\n";

      cout << "Enter another application? Yes (y) or No (n): ";
      cin >> response;
      cin.ignore(100, '\n');

    } while(again(response));
 
    //Test displaying all the nodes from the list.
    if(!app_list.display_all())
      cerr << "There is nothing in the list...\n\n";

    // ***Need to create set function for usage information***
    // Add usage information to a particular application, searched for name
    do
    {
      cout << "Please enter the application name you are looking for: ";
      cin.get(name, SIZE, '\n');
      cin.ignore(100, '\n');

      cout << "Please enter your name or write 'Anonymous': ";
      cin.get(user_name, SIZE, '\n');
      cin.ignore(100, '\n');
      one_use.user_name = new char[strlen(user_name) + 1];
      strcpy(one_use.user_name, user_name);

      cout << "What is your reason for using this application: ";
      cin.get(use_reason, SIZE, '\n');
      cin.ignore(100, '\n');
      one_use.use_reason = new char[strlen(use_reason) + 1];
      strcpy(one_use.use_reason, use_reason);

      cout << "On average, how often do you use this application per day\n"
	   << "(in hours): ";
      cin >> one_use.frequency;
      cin.ignore(100, '\n');

      //Test for usage characteristics properly being added
      if (!app_list.insert_usage(name, one_use))
        cerr << "Something went wrong... No match was found...\n\n";

      cout << "Enter another usage survey? Yes (y) or No (n): ";
      cin >> response;
      cin.ignore(100, '\n');

    } while(again(response));

    //Display all usage characteristics of every application that matches a 
    //type search
    cout << "Please enter the type of application you would like to see use\n"
	 << "characteristics for (financial, social media, etc.): ";
    cin.get(type, SIZE, '\n');
    cin.ignore(100, '\n');

    //Test for proper displaying of usage characteristic information
    if(!app_list.display_usage(type))
      cerr << "There is nothing in the list...\n\n";

    return 0;
}
