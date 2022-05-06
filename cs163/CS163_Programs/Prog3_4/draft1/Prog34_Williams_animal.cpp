#include "Prog34_Williams_animal.h"
using namespace std;

// *****************************************************************************
// Author: Connor Williams
// Date: July 30, 2021
// Course: CS163 Data Structures
// Assignment: Program 3/4
// Filename: Prog34_Williams_animal.cpp
// *****************************************************************************
// This file contains the member functions of the "animal" class, which allows 
// for the creation, copying, and displaying of one "animal" object, holding
// information on the type of animal ("type"), breed of animal ("breed"), name
// of animal ("name"), animal requirements ("needs"), animal age ("age"), and
// animal description ("notes"). The class is working with its six data members,
// an integer ("age") and five dynamically allocated arrays ("type", "breed",
// "name", "needs", and "notes"). The "set" and "copy" member functions take 
// information from the client in order to set and copy a new animal. The "set" 
// member function passes in an integer and five arrays to be set to the classes 
// data members. The "copy" member function passes in an "animal" object to be 
// set and copied to another object. All member functions return an integer 
// data type to the client to represent success or failure of the operation.
// ****************************************************************************



// The constructor initializes all data members of the abstract data type to 0
// or NULL. This constructor takes no arguments and returns nothing.
animal::animal()
{
  type = NULL;  //Set type to NULL
  breed = NULL; //Set breed to NULL 
  name = NULL;  //Set name to NULL
  needs = NULL; //Set requirements (needs) to NULL
  age = 0;      //Set age to 0
  notes = NULL; //Set description (notes) to NULL
}



// The destructor deallocates any dynamically allocated memory and resets all
// data members to 0 or NULL. This destructor takes no arguments and returns 
// nothing.
animal::~animal()
{
  //Check if array of characters is pointing NULL.
  if (type)
  {
    delete [] type; //Deallocate memory
    type = NULL;    //Reset to NULL
  }

  //Check if array of characters is pointing NULL.
  if (breed)
  {
    delete [] breed; //Deallocate memory
    breed = NULL;      //Reset to NULL
  }
  
  //Check if array of characters is pointing NULL.
  if (name)
  {
    delete [] name; //Deallocate memory
    name = NULL;    //Reset to NULL
  }

  //Check if array of characters is pointing NULL.
  if (needs)
  {
    delete [] needs; //Deallocate memory
    needs = NULL;    //Reset to NULL
  }

  age = 0; //Reset to 0

  //Check if array of characters is pointing NULL.
  if (notes)
  {
    delete [] notes; //Deallocate memory
    notes = NULL;    //Reset to NULL
  }
}



// This member function creates a new animal. It sets the type, breed, name,
// needs, age, and notes to the client inputted respective data. This member 
// function takes an integer "age", and four arrays of characters, "type",
// "breed", "name", "needs", and "notes", as arguments and returns an integer to 
// represent completion of the operation.
int animal::set(char add_type[], char add_breed[], char add_name[],
                char add_needs[], float add_age, char add_notes[])
{
  //Check if array of characters is pointing NULL.
  if (type)
  {
    delete [] type; //Deallocate memory
    type = NULL;    //Reset to NULL
  }

  type = new char[strlen(add_type) + 1]; //Allocate memory of the right size
  strcpy(type, add_type);                //Copy client input to object's data

  //Check if array of characters is pointing NULL.
  if (breed)
  {
    delete [] breed; //Deallocate memory
    breed = NULL;      //Reset to NULL
  }
  
  breed = new char[strlen(add_breed) + 1]; //Allocate memory of the right size
  strcpy(breed, add_breed);                //Copy client input to object's data

  //Check if array of characters is pointing NULL.
  if (name)
  {
    delete [] name; //Deallocate memory
    name = NULL;    //Reset to NULL
  }

  name = new char[strlen(add_name) + 1]; //Allocate memory of the right size
  strcpy(name, add_name);                //Copy client input to object's data

  //Check if array of characters is pointing NULL.
  if (needs)
  {
    delete [] needs; //Deallocate memory
    needs = NULL;    //Reset to NULL
  }

  needs = new char[strlen(add_needs) + 1]; //Allocate memory of the right size
  strcpy(needs, add_needs);                //Copy client input to object's data

  age = add_age; //Copy clients input to object's data

  //Check if array of characters is pointing NULL.
  if (notes)
  {
    delete [] notes; //Deallocate memory
    notes = NULL;    //Reset to NULL
  }

  notes = new char[strlen(add_notes) + 1]; //Allocate memory of the right size
  strcpy(notes, add_notes);                //Copy client input to object's data

  return 1; //Returns a completion of the operation
}



// This member function copies client inputted data for an animal to an object 
// by returning the called function "set". This member function takes the object
// "to_add" of the constant "animal" class data type, passed by reference, 
// as an argument and returns an integer to represent completion of the
// operation.
int animal::copy(const animal & to_add)
{
  //Returns success or failure of the operation to create an animal
  return set(to_add.type, to_add.breed, to_add.name, to_add.needs, to_add.age,
             to_add.notes);
}



// This member function displays the data set and allocated to the "animal" 
// class. This member function is constant, takes no arguments, and returns an 
// integer to represent success or failure of the operation.
int animal::display() const
{
  //Checks that data has been added to the data members
  if (!type || !breed || !name || !needs || 0 == age || !notes)
    return 0; //Returns a failure of the operation

  cout << "Type of animal: " << type << endl
       << "Breed of animal: " << breed << endl
       << "Animals Name: " << name << endl
       << "Animals Requirements: " << needs << endl
       << "Age: " << age << endl
       << "Description: " << notes << endl << endl;

  return 1; //Returns a success of the operation
}



// This function checks whether the user would like to repeat an action they
// just did. This function takes a character "response" as an argument and 
// returns true or false to represent a yes or no response.
bool again(char response)
{
    //Variable definitions
    bool again = false; //To hold whether the user response is a yes or no

    response = toupper(response); //Capitalize response character

    if (response == 'Y')
      again = true; //Set again to true

    return again; //Returns true or false
}



