#include "Prog5_animal_list.h"
using namespace std;

// *****************************************************************************
// Author: Connor Williams
// Class Number: CS162 - Introduction to Computer Science
// Programming Assignment #5: Creating a Linear Linked List of Favorite Animals
// Name of File: Prog5_animal_list.cpp
// Date: June 8, 2021
// *****************************************************************************
// This file holds the implementation of all functions included from the
// 'Prog5_animal_list.h' header file. This implementation file defines all
// functions necessary to allow for a user to build a linear linked list of 
// their favorite animals, display all contents within the list, display all 
// contents of a particular breed within the list, remove an animal from the 
// list searched by name, and deallocate all the contents in the list. Other 
// secondary functions are implemented for readability and to simplifly major
// functions. These secondary functions welcome the user, prompt and read in 
// the contents of an animal, prompt and read in search parameters for both
// breed type and animal name, display one animal, display menu options, and 
// display an exiting message.
// *****************************************************************************



//Function builds a linear linked list of the user's favorite animals along with
//all of the animals respective information. Function allows for list to be
//created, added to, and sorted by favorite animal. This function takes the
//'node' structure's 'head' pointer, passed by reference, and the 'new_animal'
//structure's 'favorite' pointer, passed by reference, as arguments and returns
//nothing.
void build(node * & head, new_animal * & favorite)
{
    read_animal(favorite);  //Prompt and read in one favorite animal

    if (!head)
    {
      head = new node;          //Allocate a new head node
      head->data = favorite;    //Set head data to user entered animal
      head->next = NULL;        //Set next node to NULL
    }
    else
    {
      node * current = head->next;  //Set initialized pointer to what head is
                                    //pointing to next.
      node * previous = head;       //Set initialized pointer to head.
      node * temp = new node;       //Allocate a temporary new node
      temp->data = favorite;        //Set pointer data to user's favorite animal
      temp->next = NULL;            //Set next temporary node to NULL

      //Sort favorite animals by most likes.
      if (temp->data->rank > head->data->rank)
      {
        temp->next = head;  //Set next temporary node to head
        head = temp;        //Set head to temporary pointer
      }	
      else
      {
        while (current && (temp->data->rank < current->data->rank))
        {
          previous = current;       //Set previous pointer to current pointer 
	  current = current->next;  //Set pointer to its next node  
        }
        temp->next = current;       //Set next temporary node to current pointer
        previous->next = temp;      //Set next previous node to temporary 
	                            //pointer
      }
    }
    cout << "You added " << favorite->name << " to your list!"
	 << endl << endl;
}



//Function displays all of the contents of each favorite animal in the linear
//linked list, as long as the list is not empty, by calling the 'display_one'
//function and traversing through the list by calling the function itself, 
//recursively. This function takes the 'node' structure's 'head' pointer, 
//passed by value, and returns an integer.
int display_all(node * head)
{
    //Variable definitions
    int count = 0;  //To check if list is empty

    if (head)
    {
      display_one(head->data);  //Displays the current data item
      cout << endl;
      count += display_all(head->next) + 1;  //Displays the data of the next 
                                             //node recursively
    }
    return count;
}



//Function prompts, reads in, and dynamically allocates an array in order for
//the user to search the list of animals by breed. This functions takes a
//pointer to an array of characters, passed by reference, as an argument and
//returns nothing.
void breed_search(char * & breed_choice)
{
    //Variable defintions
    char temp[INFO];      //To hold user's search parameter temporarily
    breed_choice = NULL;  //Pointer to get user's search parameter

    cout << "What breed would you like to search by? ";
    cin.get(temp, INFO, '\n');
    cin.ignore(100, '\n');
    cout << endl;

    breed_choice = new char[strlen(temp) + 1];  //Allocates right sized array
    strcpy(breed_choice, temp);                 //Copies to right sized array
}



//Function finds and displays just the animals of a particular breed, by
//matching a user entered array to the current node, calling the 
//'display_one' function, and then traversing through the list. This function
//takes the 'node' structure's 'head' pointer, passed by value, and the 
//'breed_choice' pointer to an array of characters, passed by value, as
//arguments and returns nothing.
void display_breed(node * head, char * breed_choice)
{
    //Variable definitions
    int count = 0;      //Checks if matches are greater than zero

    breed_search(breed_choice);  //Get user's search parameter choice
    
    if (!head)
    {
      cout << "The list is empty. Try adding an animal first!" << endl << endl;
    }
    else
    {
      node * current = head;  //Set initialized pointer to head
      while (current) 
      {
	if (!strcmp(current->data->breed, breed_choice))
        {
          display_one(current->data);  //Displays the current data item
	  cout << endl;
	  ++count;
        }
	current = current->next;  //Set pointer to its next node
      }
      if (count == 0)
        cout << "Sorry, there was no match found in the list." << endl << endl;
      else
      {
        cout << count << " " << breed_choice << " match(es) found!"
	     << endl << endl;
      }
    }
}



//Function prompts, reads in, and dynamically allocates an array in order for
//the user to search the list of animals by name. This functions takes a
//pointer to an array of characters, passed by reference, as an argument and
//returns nothing.
void name_search(char * & name_choice)
{
    //Variable defintions
    char temp[INFO];     //To hold user's search parameter temporarily
    name_choice = NULL;  //Pointer to get user's search parameter

    cout << "What name would you like to search by? ";
    cin.get(temp, INFO, '\n');
    cin.ignore(100, '\n');
    cout << endl;

    name_choice = new char[strlen(temp) + 1];  //Allocates right sized array
    strcpy(name_choice, temp);                 //Copies to right sized array
}



//Function finds and deletes just the animal of a particular name in the linear
//linked list once. Function checks if the list is empty, the first node, and
//then traverses in order to find the first name match to remove. This function
//takes the 'node' structure's 'head' pointer, passed by reference, and a
//'name_choice' pointer to an array of characters, passed by reference, as 
//arguments and returns nothing. 
void remove_animal(node * & head, char * & name_choice)
{
    name_search(name_choice);  //Get user's search parameter choice

    if (!head)
    {
      cout << "The list is empty. There are no animals to remove."
	   << endl << endl;
    }
    else if (!strcmp(head->data->name, name_choice))
    {
        node * hold = head->next;  //Set initialized pointer to what head is
	                           //pointing to next
	delete head;               //Deallocate head's memory
	head = hold;               //Update head to next node in the list
	cout << "First " << name_choice << " match removed from list."
	     << endl << endl;
    }
    else
    {
      
      node * current = head->next;  //Set initialized pointer to what head is
                                    //pointing to next.
      node * previous = head;       //Set initialized pointer to head.
      
      while (current && strcmp(current->data->name, name_choice))
      {
	previous = current;       //Set previous pointer to current pointer
	current = current->next;  //Set pointer to its next node
      }
      if (current)
      {
        previous->next = current->next;  //Set next previous node to next
	                                 //current node
	delete current;                  //Deallocate current's memory
	cout << "First " << name_choice << " match removed from list."
	     << endl << endl;
      }
      else
        cout << "Sorry, there was no match found in the list." << endl << endl;
    }
}
     


//Function deallocates the memory of the entire list and any other dynamically
//allocated arrays. This function takes the 'node' structure's 'head' pointer,
//passed by reference, the 'new_animal' structure's 'favorite' pointer, passed
//by reference, and the 'choice' pointer to an array of characters, passed by
//reference, as arguments and returns nothing.
void destroy(node * & head, new_animal * & favorite, char * & choice)
{
    if (!head)
    {
      cout << "No list to destroy." << endl << endl;
      return;
    }
    else if (!head->next)
    {
      delete head;  //Deallocate head's memory
      head = NULL;  //Set head to NULL
    }
    else
    {
      node * temp;  //Initialize a temporary pointer
      while (head)
      {
        temp = head->next;  //Set pointer to what head is pointing to next
	delete head;        //Deallocate head's memory
	head = temp;        //Update head to temporary pointer (NULL at end of
	                    //loop)
      }
    }
    cout << "The list has been destroyed." << endl << endl;

    if (favorite)
    {
      delete favorite;  //Deallocate favorite's memory
      favorite = NULL;  //Set favorite to NULL
    }
    if (choice)
    {
      delete [] choice;  //Deallocate choice array's memory
      choice = NULL;     //Set choice array to NULL
    }
}

        
     
//Function prompts and reads in a user's favorite new animal and stores its 
//contents to the 'new_animal' structure's variable, 'favorite'. All arrays are 
//dynamically allocated and sized just right. This function takes the 
//'new_animal' data type's pointer, 'favorite', passed by reference, as an 
//argument and returns nothing.
void read_animal(new_animal * & favorite)
{

    //Variable defintions
    char temp[INFO];            //To hold user's content entered array 
                                //temporarily
    favorite = new new_animal;  //Dynamically allocate a new memory to pointer

    cout << "Please enter the name of the animal: ";
    cin.get(temp, INFO, '\n');
    cin.ignore(100, '\n');

    favorite->name = new char[strlen(temp) + 1];  //Allocates right sized array
    strcpy(favorite->name, temp);                 //Copies to right sized array

    cout << "Please enter the breed of the animal: ";
    cin.get(temp, INFO, '\n');
    cin.ignore(100, '\n');

    favorite->breed = new char[strlen(temp) + 1]; //Allocates right sized array
    strcpy(favorite->breed, temp);                //Copies to right sized array

    cout << "Please enter what you like about the animal: ";
    cin.get(temp, INFO, '\n');
    cin.ignore(100, '\n');

    favorite->likeability = new char[strlen(temp) + 1]; //Allocates right sized
                                                        //array
    strcpy(favorite->likeability, temp);                //Copies to right sized
                                                        //array

    cout << "Please enter the number of likes for this animal: ";
    cin >> favorite->rank;
    cin.ignore(100, '\n');

    cout << "Please enter what the animal likes to eat: ";
    cin.get(temp, INFO, '\n');
    cin.ignore(100, '\n');

    favorite->fav_food = new char[strlen(temp) + 1];  //Allocates right sized
                                                      //array
    strcpy(favorite->fav_food, temp);                 //Copies to right sized
                                                      //array
    cout << endl;
}



//Function displays one animal with its content categorized to the user. This
//function takes the 'new_animal' data type's pointer, 'favorite', passed by
//value, as an argument and returns nothing.
void display_one(new_animal * favorite)
{
    cout << "Name: " << favorite->name << endl;
    cout << "Breed: " << favorite->breed << endl;
    cout << "What you like about the animal: " << favorite->likeability 
	 << endl;
    cout << "Number of likes: " << favorite->rank << endl;
    cout << "The animals favorite food: " << favorite->fav_food << endl;
}    



//Function prompts the user to choose from the menu options to decide what they
//want to do. Their response is read in as an integer. This function takes no
//arguments and returns an integer.
int menu()
{
    //Variable defintions
    int choice = 0;  //To be user's whole number choice

    cout << "Choose what you would like to do from the menu options below.\n\n"
	 << "\t1 - Add a new animal to your list\n"
	 << "\t2 - Display the contents of all animals in your list\n"
	 << "\t3 - Display just the animals of a particular breed\n"
	 << "\t4 - Remove a particular animal from the list by name\n"
	 << "\t5 - Delete the entire list and start over\n"
	 << "\t6 - Delete the enitre list and exit the program"
	 << endl << endl;

    cout << "Enter a whole number: ";
    cin >> choice;
    cin.ignore(100, '\n');
    cout << endl;

    return choice;
}



//Function welcomes the user, displaying what the program does and how the
//user can properly use it. This function takes no arguments and returns
//nothing.
void welcome()
{
    cout << endl;
    cout << "----------------------------------------------------------------\n"
	 << "**********Welcome to the Favorite Animal List Builder!**********\n"
	 << "----------------------------------------------------------------\n"
	 << endl;

    cout << "This program allows you to add your favorite animals to a list,\n"
	 << "all of which will include an animals name, breed, what you like\n"
	 << "about them, how many likes the animal has, and what they like\n"
	 << "to eat. Each animal added to the list will be automatically\n"
	 << "sorted by which animal has the most likes! The higher the\n"
	 << "number of likes, the higher in the list the animal will be! You\n"
	 << "will then have the option to display all of the animals in your\n"
	 << "list or only those of a particular breed." 
	 << endl << endl;

    cout << "You may also search for animals by name and delete them from the\n"
	 << "list or you can choose to delete every animal from the list."
	 << endl << endl;

    cout << "Please enter the number of likes that an animal has in whole\n"
	 << "numbers only. There is no limit to how many likes your chosen\n"
	 << "animal can have!"
	 << endl << endl;

    cout << "----------------------------------------------------------------\n"
	 << endl;
}



//Function prints out an exiting message to the user after calling the 'destroy'
//function and deallocating all allocated memory. This function takes the 'node' 
//structure's 'head' pointer, passed by reference, the 'new_animal' structure's 
//'favorite' pointer, passed by reference, and the 'choice' pointer to an array 
//of characters, passed by reference, as arguments and returns nothing.
void exit(node * & head, new_animal * & favorite, char * & choice)
{
    destroy(head, favorite, choice);  //Destroys all allocated memory

    cout << "----------------------------------------------------------------\n"
	 << "************************Exiting Program!************************\n"
	 << "----------------------------------------------------------------\n"
	 << endl;
}
