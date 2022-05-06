#include "Prog34_Williams_table.h"
using namespace std;

// *****************************************************************************
// Author: Connor Williams
// Date: July 30, 2021
// Course: CS163 Data Structures
// Assignment: Program 3/4
// Filename: Prog34_Williams_main.cpp
// *****************************************************************************
// This file contains the necessary variables, objects, and function calls to 
// test for the successful operations of creating, manipulating, and removing
// animals from an adoption roster. Each animal will be held in an "animal"
// object and each list (or table) of animals will be held in a "table" object.
// Animals can be added to the "table" object or loaded from an external file.
// They can also be saved to the external file when the user is finished with
// program. The list of animals can be displayed by a particular type and breed
// or altogether in sorted order by name and breed. The user can also find
// particular animals based on their breed and name or remove a particular 
// animal by name. Testing allows for checking for empty data and lists or data
// items and lists that are already filled. All program options/tests are listed 
// in a text-based menu format.
// *****************************************************************************



int main()
{
  //Variable definitions
  char type[SIZE];       //User inputted animal's type
  char breed[SIZE];      //User inputted animal's breed
  char name[SIZE];       //User inputted animal's name
  char needs[SIZE];      //User inputted animal's requirements
  float age = 0.0;       //User inputted animal's age
  char notes[SIZE];      //User inputted animal's description
  int menu_option = 0;   //User inputted menu option choice
  animal new_animal;     //Object to hold one animal
  table roster(101);     //Object holds all animals


  cout << "This application will allow you to match people who want to\n"
       << "foster an animal with animals needing shelter. You can add,\n"
       << "remove, find, and display animals. You can also save or load\n"
       << "animals to or from an external file.\n\n"
       << "Choose from the menu below to start testing your program."
       << endl;
  do
  {
    cout << "\n\t1) Add an animal to the system\n"
         << "\t2) Display all animals of a particular type and breed\n"
         << "\t3) Find a particular animal based on their breed and name\n"
         << "\t4) Display the last found animal (for debugging purposes)\n"
         << "\t5) Display all animals in sorted order by breed and name\n"
         << "\t6) Remove an animal from the system\n"
         << "\t7) Save animals to an external file\n"
         << "\t8) Load animals from an external file\n"
         << "\t9) Exit program\n"
         << endl << endl;

    cout << "Enter a number from the menu: ";
    cin >> menu_option;
    cin.ignore(100, '\n');

    //Text-based menu
    switch (menu_option)
    {
      case 1:
        //Take client input to create an animal
        cout << "Please enter the type of animal (cat, dog, bird, etc.): ";
        cin.get(type, SIZE, '\n');
        cin.ignore(400, '\n');
  
        cout << "Please enter the breed of animal (e.g., German Shepherd): ";
        cin.get(breed, SIZE, '\n');
        cin.ignore(400, '\n');

        cout << "Please enter the animal's name: ";
        cin.get(name, SIZE, '\n');
        cin.ignore(400, '\n');

        cout << "Please enter any requirements (e.g. needs to live alone): ";
        cin.get(needs, SIZE, '\n');
        cin.ignore(400, '\n');

        cout << "Please enter the animal's age: ";
        cin >> age;
        cin.ignore(400, '\n');

        cout << "Please enter a description (e.g., Found lost): ";
        cin.get(notes, SIZE, '\n');
        cin.ignore(400, '\n');
  
        //Check and set animal
        if (!new_animal.set(type, breed, name, needs, age, notes))
          cerr << "There's nothing to add...\n\n";
        
        //Check and insert a new animal into a hash table and a binary search
        //tree
        if (!roster.insert(type, breed, name, new_animal))
          cerr << "There's nothing to add...\n\n";
        break;
  
      case 2:
        cout << "Please enter the type of animal (cat, dog, bird, etc.): ";
        cin.get(type, SIZE, '\n');
        cin.ignore(400, '\n');
  
        cout << "Please enter the breed of animal (e.g., German Shepherd): ";
        cin.get(breed, SIZE, '\n');
        cin.ignore(400, '\n');

        //Check and display a match from the hash table
        if (!roster.display_match(type, breed))
          cerr << "There's nothing to display...\n\n";
        break;

      case 3:
        cout << "Please enter the breed of animal (e.g., German Shepherd): ";
        cin.get(breed, SIZE, '\n');
        cin.ignore(400, '\n');
  
        cout << "Please enter the animal's name: ";
        cin.get(name, SIZE, '\n');
        cin.ignore(400, '\n');

        //Check and retrieve a match from the binary search tree
        if (!roster.retrieve(breed, name, new_animal))
          cerr << "Match not found...\n\n";
        else
          cout << "Match found!\n\n";
        break;

      case 4:
        //Check and display the most recently found animal (for debugging
        //purposes).
        if(!new_animal.display())
          cerr << "There's nothing to display...\n\n";
        break;

      case 5:
        //Check and display all animals in sorted ordered by breed and name from
        //the binary search tree.
        if (!roster.display_all())
          cerr << "There's nothing to display...\n\n";
        break;
   /*
      case 6:
        break;

      case 7:
        break;
    */
      case 9:
        //Exit the program
        cout << "Exiting program" << endl << endl;
        break;

      default:
        cout << "That's not an option. Try again..." << endl << endl;
    } 

  } while (menu_option != 9);

  return 0;
}
