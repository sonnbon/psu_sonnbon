#include "Baron-Williams_BST.h"
using namespace std;

// *****************************************************************************
// Program 3
// Author: Connor Baron-Williams
// Due Date: February 28, 2022
// Course: CS202 Programming Systems
// Filename: Baron-Williams_main.cpp
// *****************************************************************************
// This file contains the main application that allows a user to manage 
// different collections of athletes competing in specific competitions in the
// Winter Olympics. This application will allow a user to add, search for, and
// display athlete information and their competition statistics. Of the three
// competition types, figure skating athletes are sorted alphabetically. The
// purpose of this application is to test and use operator overloading to
// achieve managing these three different types of athletes. The user can also
// choose to test specific athlete classes for full functionality, that which
// might not be included in the main application.
// *****************************************************************************



int main()
{
  //Variable definitions
  int option {0};      //User options to manage a list
  BAD_INPUT b_input;   //Users incorrect input if needed

  //Welcome user
  cout << "Hello. This program allows you to manage different types and lists"
       << "\nof athletes competing in three different types of competitions in"
       << "\nthe Winter Olympics. The three competition types are figure\n"
       << "skating, ski jumping, and bobsledding. Each athlete will have\n"
       << "personal information and their specific competition's statistics\n"
       << "available for you to add, find, change, or display.\n\n"
       << "Options for testing different objects are available as well.\n\n"
       << "Let's begin!" 
       << endl;

    do
    {
      cout << "\nWhat would you like to do?\n"
           << "1 - Create a list of figure skaters\n"
           << "2 - Create a list of ski jumpers\n"
           << "3 - Create a list of bobsledders\n"
           << "4 - - TEST athlete class functionality\n"
           << "5 - - TEST figure skating class functionality\n"
           << "6 - - TEST ski jumping class functionality\n"
           << "7 - - TEST bobsleding class functionality\n"
           << "8 - - TEST a BST of figure skaters functionality\n"
           << endl;

      cout << "Enter a whole number: ";
      cin >> option;
      cin.ignore(100, '\n');

      //Make sure user chooses a number between 1 and 8. Otherwise, throw a
      //BAD_INPUT structure and have them try again.
      try
      {
        if (option < 1 || option > 8 || cin.fail())
        {
          cin.clear();
          cin.ignore(100, '\n');
          b_input.bad_int = 0;
          throw b_input;
        }

        switch (option)
        {
          case 1:
            //Create a list of figure skaters
            BST_function();
            break;

          case 2:
            //Create a list of ski jumpers
            STL_array_function();
            break;

          case 3:
            //Create a list of bobsledders
            STL_forwardlist_function();
            break;

          case 4:
            //Test athlete class
            test_athlete();
            break;

          case 5:
            //Test figure skating class
            test_figure_skater();
            break;

          case 6:
            //Test ski jumping class
            test_ski_jumper();
            break;

          case 7:
            //Test bobsledding class
            test_bobsledder();
            break;

          case 8:
            //Test a collection of figure skaters
            test_BST();
            break;

          default:
            cout << "This default should not get called." << endl;
            break;
        }
      }

      //Catch any errors that may have occurred when choosing a switch option.
      catch (...)
      {
        cout << "That is not a valid response. Try again." << endl << endl;
      }

      cout << "See the main menu again? Yes (Y) or No (N): ";
  
    } while (again()); //Returns whether user enters Yes or No

  cout << "Exiting program... Goodbye." << endl << endl;

  return 0;
}
