#include "Prog5_animal_list.h"
using namespace std;

// *****************************************************************************
// Author: Connor Williams
// Class Number: CS162 - Introduction to Computer Science
// Programming Assignment #5: Creating a Linear Linked List of Favorite Animals
// Name of File: Prog5_animal_list.cpp
// Date: June 3, 2021
// *****************************************************************************
// This file holds the implementation of all functions included from the
// 'Prog5_animal_list.h' header file. This implementation file defines all
// functions necessary to allow for a user to build a linear linked list,
// display all contents within the list, display all contents of a particular
// breed within the list, remove an animal from the list searched by name, and
// deallocate all the content in the list.
// *****************************************************************************



//Function builds a linear linked list of the user's favorite animals along with
//all of the animals respective information. Function allows for list to be
//created, added to, and sorted by favorite animal. This function takes the
//'node' structure's 'head' pointer, passed by reference, and the 'new_animal'
//structure's 'favorite' pointer, passed by value, as arguments and returns
//nothing.
void build(node * & head, new_animal * favorite)
{
    //Check if list is empty
    if (!head)
    {
      head = new node;          //Allocate a new head node.
      head->data = favorite;    //Set head data to user entered animal
      head->next = NULL;        //Set what head node is pointing to next, to 
                                //NULL
    }
  
    //Traverse the list
    else
    {
      node * current = head->next;  //Set initialized node to what head is
                                    //pointing to next.
      node * previous = head;       //Set initialized node to head.
      node * temp = new node;       //Allocate a temporary new node
      temp->data = favorite;        //Set temporary node to user's favorite 
                                    //animal
      temp->next = NULL;            //Set what temporary node is pointing to 
                                    //next, to NULL
      if (temp->data->rank > head->data->rank)
      {
        temp->next = head;
        head = temp;
	return;
      }	
      while (current && (temp->data->rank < current->data->rank))
      {
        previous = current;       
	current = current->next;  
      }
      temp->next = current;
      previous->next = temp;  
    }
}



//Function displays all of the contents of each favorite animal in the linear
//linked list, as long as the list is not empty, by calling the 'display_one'
//function while traversing through the list. This function takes the 'node'
//structure's 'head' pointer, passed by value, and returns nothing.
void display_all(node * head)
{
    //Check if list is empty
    if (!head)
      cout << "The list is empty. Please add an animal first!" << endl << endl;

    //Traverse the list
    else
    {
      node * current = head;
      while (current)
      {
	display_one(current->data);
        cout << endl;
        current = current->next;  
      }
    }
}



//Function finds and displays just the animals of a particular breed, by
//matching a user entered array to the current node, calling the 
//'display_one' function, and then traversing through the list. This function
//takes the 'node' structure's 'head' pointer, passed by value, and returns
//true or false.
bool search_breed(node * head)
{
    //Variable definitions
    int count = 0;               //Counts how many matches are made
    bool match = true;           //Checks if a match is found
    char temp[INFO];             //To hold user's search parameter temporarily
    char * breed_choice = NULL;  //Pointer to get user's search parameter

    cout << "What breed would you like to search by? ";
    cin.get(temp, INFO, '\n');
    cin.ignore(100, '\n');
    cout << endl;

    breed_choice = new char[strlen(temp) + 1];
    strcpy(breed_choice, temp);
    
    //Check if list is empty
    if (!head)
      cout << "The list is empty. Try adding an animal first!" << endl << endl;

    //Traverse the list
    else
    {
      node * current = head;
      while (current) 
      {
	if (!strcmp(current->data->breed, breed_choice))
        {
          display_one(current->data);
	  cout << endl;
	  ++count;
        }
	current = current->next;
      }
      if (count == 0)
      {
        cout << "Sorry, there was no match found in the list." << endl << endl;
        match = false;
      }
    }
    return match;
}



//Function prompts and reads in a user's favorite new animal and stores its 
//contents to the 'new_animal' structure's variable, 'favorite'. All arrays are 
//dynamically allocated and sized just right. This function takes the 
//'new_animal' data type's pointer, 'favorite', passed by reference, as an 
//argument and returns nothing.
void read_animal(new_animal * & favorite)
{
    favorite = new new_animal;  //Dynamically allocate a new memory to pointer

    //Variable defintions
    char temp[INFO];  //To hold user's content entered array temporarily

    cout << "Please enter the name of the animal: ";
    cin.get(temp, INFO, '\n');
    cin.ignore(100, '\n');

    favorite->name = new char[strlen(temp) + 1];
    strcpy(favorite->name, temp);

    cout << "Please enter the breed of the animal: ";
    cin.get(temp, INFO, '\n');
    cin.ignore(100, '\n');

    favorite->breed = new char[strlen(temp) + 1];
    strcpy(favorite->breed, temp);

    cout << "Please enter what you like about the animal: ";
    cin.get(temp, INFO, '\n');
    cin.ignore(100, '\n');

    favorite->likeability = new char[strlen(temp) + 1];
    strcpy(favorite->likeability, temp);

    cout << "Please enter the number of likes for this animal: ";
    cin >> favorite->rank;
    cin.ignore(100, '\n');

    cout << "Please enter what the animal likes to eat: ";
    cin.get(temp, INFO, '\n');
    cin.ignore(100, '\n');

    favorite->fav_food = new char[strlen(temp) + 1];
    strcpy(favorite->fav_food, temp);

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
	 << "\t5 - Delete the entire list\n"
	 << "\t6 - Exit the program"
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
	 << "numbers only. There is no end to how many likes your chosen\n"
	 << "animal can have!"
	 << endl << endl;

    cout << "----------------------------------------------------------------\n"
	 << endl;
}



//Function prints out an exiting message to the user. This function takes no
//arguments and returns nothing.
void exit()
{
    cout << "----------------------------------------------------------------\n"
	 << "************************Exiting Program!************************\n"
	 << "----------------------------------------------------------------\n"
	 << endl;
}
