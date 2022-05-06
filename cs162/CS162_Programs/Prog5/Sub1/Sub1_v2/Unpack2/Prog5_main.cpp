#include "Prog5_animal_list.h"
using namespace std;

// *****************************************************************************
// Author: Connor Williams
// Class Number: CS162 - Introduction to Computer Science
// Programming Assignment #5: Creating a Linear Linked List of Favorite Animals
// Name of File: Prog5_main.cpp
// Date: June 3, 2021
// *****************************************************************************
// This file holds the main function, which calls the functions implemented and
// prototyped from the files 'Prog5_animal_list.cpp' and 'Prog5_animal_list.h',
// respectively.  User chooses from a menu, deciding how they want to 
// manipulate their dynamically allocated linear linked list. User can add new
// animals, display all content of each animal, display all content of each
// animal of a particular breed, remove an animal from the list of a particular
// name, and/or delete an entire created list.
// *****************************************************************************



int main()
{
    //Variable defintions
    node * head = NULL;            //Pointer to the 'node' structure 
    new_animal * favorite = NULL;  //Pointer to the 'new_animal' structure
    int menu_option = 0;

    //Welcome the user
    welcome();

    do
    {
      //Get user's decision on what to do
      menu_option = menu();

      switch (menu_option)
      {
        case 1:
	  //Read in and add new animal to list
          read_animal(favorite);
          build(head, favorite);
	  break;
        case 2:
	  //Display all the contents of each animal in the list
	  display_all(head);
	  break;
        case 3:
	  //Find and display an animal and its contents, searched by breed
	  search_breed(head);  //We don't need to catch bool
	  break;
        case 4:
	  //Remove an animal from the list, searched by name
	  cout << "Coming soon..." << endl << endl;
	  break;
        case 5:
	  //Delete everything in the list
	  cout << "Coming soon..." << endl << endl;
	  break;
	case 6:
	  //Delete everything in the list and then exit the program
	  //<Deallocating list function coming soon>
	  exit();
	  break;
        default:
	  cout << "That is an invalid response. Please try again."
	       << endl << endl;
      }
    } while (menu_option != 6);

    return 0;
}
