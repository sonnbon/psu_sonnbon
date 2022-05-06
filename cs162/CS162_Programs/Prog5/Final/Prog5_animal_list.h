#include <iostream>
#include <cctype>
#include <cstring>

// *****************************************************************************
// Author: Connor Williams
// Class Number: CS162 - Introduction to Computer Science
// Programming Assignment #5: Creating a Linear Linked List of Favorite Animals
// Name of File: Prog5_animal_list.h
// Date: June 8, 2021
// *****************************************************************************
// This header file holds the structure and function defintions and prototypes
// needed in order to create a linear linked list of a user's favorite animals.
// One structure, 'new_animal' holds all the information needed to be included 
// with a new animal. The other structure, 'node', holds all the information
// necessary to create linearly linked nodes with the 'new_animal' content. The
// prototyped functions will allow the user to build a linear linked list,
// display all contents within the list, display all contents of a particular
// breed within the list, remove an animal from the list searched for by name, 
// and deallocate all the content in the list.
// *****************************************************************************


//Constants
const int INFO = 51;  //To be max allowable size of any array before they are
                      //dynamically allocated to be the right sized array


//Structures
//Structure holds information for a new animal
struct new_animal
{
    char * name;         //To be the name of the animal
    char * breed;        //To be the breed of the animal
    char * likeability;  //To be what the user likes about the animal
    int rank;            //To be number of likes
    char * fav_food;     //To be what the animal likes to eat
};



//Structure holds the 'data' pointer to the 'new_animal' structure and the 
//'next' pointer to the 'node' structure itself allowing for a linear linked 
//list to be created. 
struct node
{
    new_animal * data;  //Member will be dereferenced to access 'new_animal'
    node * next;        //Member will be dereferenced to access the next 'node'
};



//Function Prototypes
void welcome();                             //Welcomes the user

int menu();                                 //Menu list of options for user

void read_animal(new_animal * & favorite);  //Reads in contents for new animal

void build(node * & head,                   //Adds an animal into the list
	   new_animal * & favorite);

void display_one(node * head);    //Displays one new animal

void display_all(node * head);              //Displays all of the animals

void breed_search(char * & breed_choice);   //Gets user's breed search choice

void display_breed(node * head,             //Displays animal, searched by breed
		   char * & breed_choice);    

void name_search(char * & name_choice);     //Get user's name search choice

void remove_animal(node * & head,           //Removes animal, searched by name
		   char * & name_choice);

void destroy(node * & head,                 //Deallocates all memory from all
	     new_animal * & favorite,       //structures and arrays.
	     char * & choice);

void exit();                                //Exits the program

