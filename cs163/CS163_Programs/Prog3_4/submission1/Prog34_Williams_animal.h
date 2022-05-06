#include <iostream>
#include <cctype>
#include <cstring>

// *****************************************************************************
// Author: Connor Williams
// Date: July 30, 2021
// Course: CS163 Data Structures
// Assignment: Program 3/4
// Filename: Prog34_Williams_animal.h
// *****************************************************************************
// This file contains a class Abstract Data Type, named "animal". This data type 
// is used to specifically work with one object, creating, copying, or 
// displaying its contents, "type", "breed", "name", "needs", "age", and 
// "notes". These contents make up the information for one animal of the user's
// choice. All member functions (not including the constructor or 
// destructor) within the Abstract Data Type return an integer value to 
// represent success or failure of an operation to the client. Arguments that
// will be passed in member functions include an object of the "animal" class 
// data type for copying purposes, and variables of integer and character array
// data types for object creation, matching, sorting, and retrieving purposes.
// *****************************************************************************



// - - - - - C O N S T A N T S - - - - -
//
const int SIZE = 301; //Max size for any array of characters
// -----------------------------------------------------------------------------



// - - - - - P R O T O T Y P E S - - - - -
//
bool again(char response); //Checks if user wants to do an action again
// -----------------------------------------------------------------------------



// - - - - - C L A S S E S - - - - -
//
// This class manages one animal's information holding the type, breed, name, 
// requirements, age, and description of the animal. It allows for the creation
// and copying of one animal entry by passing in arrays, an integer, or an 
// object as arguments inputted from the client. It also displays an animal
// entry for debugging purposes.
class animal
{
  public:
    animal();                        //Constructor, initializes data
                                     //members to 0 or NULL
    ~animal();                       //Destructor, deallocates dynamic
                                     //data members and resets all data
					                 //members to 0 or NULL
    int set(char add_type[],         //Sets all information for one animal
            char add_breed[],
            char add_name[], 
            char add_needs[],
            float add_age, 
            char add_notes[]);
    int copy(const animal & to_add); //Makes a copy of the passed in object
    int display() const;             //Displays data in object
    int ismatch(char type[],         //Checks for user inputted matches
                char breed[]);
    int isempty() const;             //Checks if user inputted data is valid
    int get_sorted(char add_breed[], //Returns how object should be sorted
                   char add_name[]);
    int retrieve(char find_breed[],  //Checks for user inputted matches
                 char find_name[]);

  private:
    char * type;  //Type of animal
    char * breed; //Breed of animal
    char * name;  //Name of animal
    char * needs; //Animal's requirements
    float age;    //Age of animal
    char * notes; //Description of animal and/or animal's history
};
// -----------------------------------------------------------------------------




