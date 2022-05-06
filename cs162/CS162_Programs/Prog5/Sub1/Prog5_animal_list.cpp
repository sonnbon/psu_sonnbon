#include "Prog5_animal_list.h"
using namespace std;

// *****************************************************************************
// Author: Connor Williams
// Class Number: CS162 - Introduction to Computer Science
// Programming Assignment #5: Creating a Linear Linked List of Favorite Animals
// Name of File: Prog5_animal_list.cpp
// Date: June 2, 2021
// *****************************************************************************
// This file holds the implementation of all functions included from the
// 'Prog5_animal_list.h' header file.
// *****************************************************************************



void build(node * & head, new_animal * & favorite)
{
    //Check if list is empty
    if (!head)
    {
      head = new node;
      strcpy(head->data->name, favorite->name);
      strcpy(head->data->breed, favorite->breed);
      strcpy(head->data->likeability, favorite->likeability);
      head->data->rank = favorite->rank;
      strcpy(head->data->fav_food, favorite->fav_food);
      head->next = NULL;
    }
    else
    {
      node * current = head->next;
      node * previous = head;

      node * temp = new node;
      strcpy(temp->data->name, favorite->name);
      strcpy(temp->data->breed, favorite->breed);
      strcpy(temp->data->likeability, favorite->likeability);
      temp->data->rank = favorite->rank;
      strcpy(temp->data->fav_food, favorite->fav_food);

      while (current->next && temp->data->rank < current->data->rank)
      {
        previous = current;
	current = current->next;
      }
      if (!current->next)
      {
        current->next = temp;
	temp->next = NULL;
      }
      else
      {
        previous->next = temp;
        temp->next = current;
      }
    }
}



//Function displays all of the contents of each favorite animal in the linear
//linked list, as long as the list is not empty, by calling the 'display_one'
//function while traversing through the list. This function takes the 'node'
//structure's 'head' pointer, passed by value, and returns nothing.
void display_all(node * head)
{
    if (!head)
      cout << "The list is empty. Try adding animals first!." << endl << endl;
    else
    {
      while (head)
      {
        display_one(head);
        cout << endl;
        head = head->next;
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
    int count = 0;
    bool match = true;
    char temp[INFO];
    char * breed_choice = NULL;

    cout << "What breed would you like to search by? ";
    cin.get(temp, INFO, '\n');
    cin.ignore(100, '\n');

    breed_choice = new char[strlen(temp) + 1];
    strcpy(breed_choice, temp);
    
    if (!head)
      cout << "The list is empty. Try adding an animal first!" << endl << endl;
    else
    {
      while (head && !strcmp(head->data->breed, breed_choice))
      {
        display_one(head);
	cout << endl;
	head = head->next;
	++count;
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
    //Variable defintions
    char temp[INFO];  //To be temporary array to allow structure member arrays
                      //to be sized just right

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
}

void display_one(new_animal * favorite)
{
    cout << "Name: " << favorite->name << endl;
    cout << "Breed: " << favorite->breed << endl;
    cout << "What you like about the animal: " << favorite->likeability 
	 << endl;
    cout << "Number of likes: " << favorite->rank << endl;
    cout << "The animals favorite food: " << favorite->fav_food << endl;
}    






