#include "Prog5_animal_list.h"
using namespace std;

// *****************************************************************************
// Author: Connor Williams
// Class Number: CS162 - Introduction to Computer Science
// Programming Assignment #5: Creating a Linear Linked List of Favorite Animals
// Name of File: Prog5_main.cpp
// Date: June 2, 2021
// *****************************************************************************
// This file holds the main function
// *****************************************************************************



int main()
{
    //Variable defintions
    node * head;
    new_animal * favorite;

    //Call
    read_animal(favorite);
    build(head, favorite);
    //display_one(head);
//    build(head);
//    display_all(head);
//    search_breed(head);


    return 0;
}
