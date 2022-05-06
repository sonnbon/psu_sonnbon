#include "Cell_Survey_Williams.h"
using namespace std;

// ****************************************************************************
// Author: Connor Williams
// Date: July 9, 2021
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
// automatically sorted alphabetically ("add_new"). Calling the "display_all" 
// function displays all the cellphone applications added, and is used to test 
// whether the list is empty or, if there are list items, that it is sorted
// alphabetically. The user can do similar operations within each 
// cellphone application's information, creating and displaying usage
// characteristics from however many people are surveyed about their usage of
// a particular application ("insert_usage"). The "display_usage" function will 
// display these usage characteristics that have been added by a particular 
// cellphone application type, all sorted from longest use (hours per day) to 
// shortest use, separated by cellphone application name. The user can also 
// remove specific applications from the list, searched for by name, by calling 
// the "remove_app" function. If the user wishes to delete everything so they 
// can start over with a fresh list, the can call the "remove_all" function. 
// All program options/tests are listed in a text-based menu format.
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
    float frequency = 0.0;  //To be temporary float for user's usage frequency
                            //(in hours per day)
    char response = 'n';    //To be user's response yes or no
    int user_input = 0;     //To be user's option choice and/or test choice
    cell_app an_app;        //Holds the information for one application
    cell_survey app_list;   //Holds the information for many applications
    cell_usage one_use;     //HOlds the information for one usage survey

    //Welcome message
    cout << "This program allows you to manipulate (add/remove) cellphone\n"
	 << "applications to a list, sorted alphabetically. This program\n"
	 << "also allows you to manipulate (add/remove) 'usage survey'\n" 
	 << "information to each application. These surveys include\n"
	 << "information about why people use a specific application and how\n"
	 << "often (average hours per day). 'Usage surveys' are sorted by\n"
	 << "most frequently used." << endl << endl;
    cout << "Please choose from the options below (enter a whole number) and\n"
	 << "test the programs functionality." << endl << endl;
    
    //Menu options
    do
    {
      cout << "\t1) Add a new application\n"
	   << "\t2) Display all applications\n"
	   << "\t3) Insert Survey information for a given application\n"
	   << "\t4) Display usage for an application of a particular category\n"
	   << "\t5) Remove an application\n"
	   << "\t6) Delete everything\n"
	   << "\t7) Exit program\n"
	   << endl;
      cout << "Enter whole number choice here: ";
      cin >> user_input;
      cin.ignore(100, '\n');

      //Menu layout
      switch (user_input)
      {
        case 1:
          //Test adding cellphone applications to a list of applications.
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

	    //Set the user inputted information into the "an_app" object.
            app_list.set_app(name, type, description, an_app);

            //Checks if information was added correctly and adds it to the
	    //application list.
            if (!app_list.add_new(an_app))
              cerr << "There is nothing to add. Try again...\n\n";

            cout << "Enter another application? Yes (y) or No (n): ";
            cin >> response;
            cin.ignore(100, '\n');

          } while(again(response));
	  break;
        case 2:
          //Test displaying all the nodes from the list in alphabetical order.
          if (!app_list.display_all())
            cerr << "There is nothing in the list...\n\n";
	  break;
        case 3:
          //Add usage information to a particular application, searched for by i
	  //name
          do
          {
            cout << "Please enter the application name you are looking for: ";
            cin.get(name, SIZE, '\n');
            cin.ignore(100, '\n');

            cout << "Please enter your name or write 'Anonymous': ";
            cin.get(user_name, SIZE, '\n');
            cin.ignore(100, '\n');

            cout << "What is your reason for using this application: ";
            cin.get(use_reason, SIZE, '\n');
            cin.ignore(100, '\n');

            cout << "On average, how often do you use this application per day\n"
	         << "(in hours): ";
            cin >> frequency;
            cin.ignore(100, '\n');

	    //Set the user inputted information into the "one_use" object.
            app_list.set_use(user_name, use_reason, frequency, one_use);

            //Test for usage characteristics properly being added
            if (!app_list.insert_usage(name, one_use))
              cerr << "Something went wrong... No match was found...\n\n";

            cout << "Enter another usage survey? Yes (y) or No (n): ";
            cin >> response;
            cin.ignore(100, '\n');

          } while(again(response));
	  break;
        case 4:
          //Display all usage characteristics of every application that matches a 
          //type search, sorted by most frequently used for each application node.
          cout << "Please enter the type of application you would like to see use\n"
	       << "characteristics for (financial, social media, etc.): ";
          cin.get(type, SIZE, '\n');
          cin.ignore(100, '\n');

          //Test for proper displaying of usage characteristic information
          if (!app_list.display_usage(type))
            cerr << "There is nothing in the list or a match was not found...\n\n";
	  break;
        case 5:
          cout << "Please enter the name of an application you want to remove: ";
          cin.get(name, SIZE, '\n');
          cin.ignore(100, '\n');

	  //Check for proper removal of application, searched for by name.
          if (!app_list.remove_app(name))
            cerr << "The list is empty or a match was not found...\n\n";
	  else
	    cout << "Application removed." << endl << endl;
	  break;
        case 6:
	  //Check for proper removal of all applications
	  if (!app_list.remove_all())
            cerr << "There is nothing to remove...\n\n";
	  else
            cout << "All applications removed." << endl << endl;
	  break;
	case 7:
	  cout << "Exiting program..." << endl << endl;
	  break;
	default:
	  cout << "That is not a valid entry... Try again\n\n";
      }
    } while (user_input != 7);

    return 0;
}
