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
// set and copied to another object. The "ismatch" and "get_sorted" functions
// both pass in two arrays of characters to find matches and to choose a 
// sorting direction, respectively. All member functions return an integer data
// type to the client to represent success or failure of the operation.
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
  //Check and confirm array of characters is pointing NULL.
  if (type)
  {
    delete [] type;
    type = NULL;
  }

  //Check and confirm array of characters is pointing NULL.
  if (breed)
  {
    delete [] breed;
    breed = NULL;
  }
  
  //Check and confirm array of characters is pointing NULL.
  if (name)
  {
    delete [] name;
    name = NULL;
  }

  //Check and confirm array of characters is pointing NULL.
  if (needs)
  {
    delete [] needs;
    needs = NULL;
  }

  age = 0;

  //Check and confirm array of characters is pointing NULL.
  if (notes)
  {
    delete [] notes;
    notes = NULL;
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
  //Check and confirm array of characters is pointing NULL.
  if (type)
  {
    delete [] type;
    type = NULL;
  }

  type = new char[strlen(add_type) + 1]; //Allocate memory of the right size
  strcpy(type, add_type);                //Copy client input to object's data

  //Check and confirm array of characters is pointing NULL.
  if (breed)
  {
    delete [] breed;
    breed = NULL;
  }
  
  breed = new char[strlen(add_breed) + 1]; //Allocate memory of the right size
  strcpy(breed, add_breed);                //Copy client input to object's data

  //Check and confirm array of characters is pointing NULL.
  if (name)
  {
    delete [] name;
    name = NULL;
  }

  name = new char[strlen(add_name) + 1]; //Allocate memory of the right size
  strcpy(name, add_name);                //Copy client input to object's data

  //Check and confirm array of characters is pointing NULL.
  if (needs)
  {
    delete [] needs;
    needs = NULL;
  }

  needs = new char[strlen(add_needs) + 1]; //Allocate memory of the right size
  strcpy(needs, add_needs);                //Copy client input to object's data

  age = add_age; //Copy clients input to object's data

  //Check and confirm array of characters is pointing NULL.
  if (notes)
  {
    delete [] notes;
    notes = NULL;
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
  //Returns completion of the operation to create an animal
  return set(to_add.type, to_add.breed, to_add.name, to_add.needs, to_add.age,
             to_add.notes);
}



// This member function displays the data set and allocated to the "animal" 
// class. This member function is constant, takes no arguments, and returns an 
// integer to represent success or failure of the operation.
int animal::display() const
{
  //Checks that data has been added to the data members
  if (!type || !breed || !name || !needs || !notes)
    return 0; //Returns a failure of the operation

  cout << "Type of animal: " << type << endl
       << "Breed of animal: " << breed << endl
       << "Animal's Name: " << name << endl
       << "Animal's Requirements: " << needs << endl
       << "Age: " << age << endl
       << "Description: " << notes << endl << endl;

  return 1; //Returns a success of the operation
}



// This member function checks if the client inputted search parameters match
// the object's data. This member function takes two arrays of characters as
// arguments and returns an integer to represent true (1) or false (0).
int animal::ismatch(char is_type[], char is_breed[])
{
  //Check if object has data for comparison
  if (!type || !breed)
    return 0; //Returns failure of the operation

  //Check if both arguments match with object's data
  if (!strcmp(type, is_type) && !strcmp(breed, is_breed))
    return 1; //Returns true

  return 0; //Returns false
}



// This member function checks to see that the client inputted data has been
// added to an object. This member function takes no arguments and returns an
// integer to represent true (1) or false (0).
int animal::isempty() const
{
  //Check if object has correct inputted data
  if (!type || !breed || !name || !needs || !notes)
    return 1; //Returns true

  return 0; //Returns false
}



// This member function compares client inputted data to an object's data
// and checks whether it is less in value alphabetically. This member function
// takes two arrays of characters as arguments and returns an integer to 
// represent a failure (0), data that is less than (1), or data that is greater
// than (2).
int animal::get_sorted(char add_breed[], char add_name[])
{
  //Check that the object has valid data
  if (!breed || !name)
    return 0; //Returns a failure of the operation

  int sort = 0; //Number decides sorting value. 
                //(1 - breed less than or breed the same but name less than
                // 2 - breed greater than or breed the same and name greater)

  //Check if the passed in data is less than object's data, alphabetically
  if (strcmp(add_breed, breed) < 0 || 
     (!strcmp(add_breed, breed) && strcmp(add_name, name) < 0))
    sort = 1;

  //The data greater than the object's data overall, alphabetically
  else
    sort = 2;

  return sort; //Returns false, the data is greater than
}



// This member function compares client inputted data to an object's data
// and checks whether they match in value alphabetically. This member function
// takes two arrays of characters as arguments and returns an integer to
// represent a success or failure of the operation.
int animal::retrieve(char find_breed[], char find_name[])
{
  //Check that the object has valid data
  if (!breed || !name)
    return 0; //Returns a failure of the operation

  //Check if the passed in data matches both the object's breed and name,
  //alphabetically.
  if (!strcmp(find_breed, breed) && !strcmp(find_name, name))
    return 1; //Returns true that the data is a match
    
  return 0; //Returns false, the data is not a matchA
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



