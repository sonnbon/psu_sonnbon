#include "Prog5_animal_list.h"
using namespace std;

// *****************************************************************************
// Author: Connor Williams
// Class Number: CS162 - Introduction to Computer Science
// Programming Assignment #5: Creating a Linear Linked List of Favorite Animals
// Name of File: Prog5_main.cpp
// Date: June 8, 2021
// *****************************************************************************
// This file holds the main function, which calls the functions implemented and
// prototyped from the files 'Prog5_animal_list.cpp' and 'Prog5_animal_list.h',
// respectively. Calling these functions allows the user to choose when and how
// to grow and shrink a list of their favorite animals. The user chooses from a 
// menu, deciding how they want to manipulate their dynamically allocated linear 
// linked list. User can add new animals, display all content of each animal, 
// display all content of each animal of a particular breed, remove an animal 
// from the list of a particular name, and/or delete an entire created list. 
// When the user exits the program, the linear linked list will be destroyed, if
// it has not been already.
// *****************************************************************************



int main()
{
    //Variable defintions
    node * head = NULL;            //Pointer to the 'node' structure 
    new_animal * favorite = NULL;  //Pointer to the 'new_animal' structure
    char * choice = NULL;          //Pointer to an array of characters for a
                                   //user search type
    int menu_option = 0;           //To be user's menu number choice

    //Welcome the user
    welcome();

    do
    {
      menu_option = menu();  //Get user's decision on which menu item to choose

      switch (menu_option)
      {
        case 1:
	  //Read in and add new animal to list
          build(head, favorite);
	  break;
        case 2:
	  //Display all the contents of each animal in the list
	  display_all(head);
	  break;
        case 3:
	  //Find and display an animal and its contents, searched by breed
	  display_breed(head, choice);
	  break;
        case 4:
	  //Remove an animal from the list, searched by name
	  remove_animal(head, choice);
	  break;
        case 5:
	  //Delete everything in the list
	  destroy(head, favorite, choice);
	  break;
	case 6:
	  //Delete everything in the list and then exit the program
	  destroy(head, favorite, choice);
	  exit();
	  break;
        default:
	  cout << "That is an invalid response. Please try again."
	       << endl << endl;
      }
    } while (menu_option != 6);  //Loop menu unless user decides to exit

    return 0;
}
