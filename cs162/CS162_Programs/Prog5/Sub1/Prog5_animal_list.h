#include <iostream>
#include <cctype>
#include <cstring>

// *****************************************************************************
// Author: Connor Williams
// Class Number: CS162 - Introduction to Computer Science
// Programming Assignment #5: Creating a Linear Linked List of Favorite Animals
// Name of File: Prog5_animal_list.h
// Date: June 2, 2021
// *****************************************************************************
// This header file holds the structure and function defintions and prototypes
// needed in order to create a linear linked list of a users favorite animals.
// *****************************************************************************


//Constants
const int INFO = 51;  //To be max allowable size of any array before they are
                      //dynamically allocated to be the right sized array.


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



//Structure holds the 'new_animal' structure as a data type and a 'next' pointer
//to itself allowing for a linear linked list to be created. 
struct node
{
    new_animal * data;
    node * next;
};



//Function Prototypes
void build(node * & head, new_animal * & favorite);                  //Adds a new animal into a linear 
                                            //linked list
void display_all(node * head);              //Displays the contents of all 
                                            //animals in list
bool search_breed(node * head);             //Displays the animals of a 
                                            //particular breed
void read_animal(new_animal * & favorite);          //Reads in contents for one new
                                            //favorite animal
void display_one(new_animal * favorite);


