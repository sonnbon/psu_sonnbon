#include "CS162_pet_hotel.h"
using namespace std;

//Connor Williams
//CS162 - Lecture on classes
//This file is setting up a hotel for pets and implementing the member functions

/*
        pet all_pets[HOTEL]; //Array for the max number of pets
        int num_pets;        //The number of pets actually in the hotel now
*/

//default constructor
pet_hotel::pet_hotel()
{
    num_pets = 0;    //the pet constructor is invoked automatically HOTEL
                     //number of times
}

//destructor
pet_hotel::~pet_hotel()
{
    num_pets = 0;      //the pet destructor is invoked automatically HOTEL
                      //number of times
}

//Input from the user a pet's information if there is room and return
//true if we are finished an false otherwise
bool pet_hotel::input()
{
    //Variable definitions
    bool is_full = false;

    if (num_pets >= HOTEL)    //we are out of room - the pet array is full
      is_full = true; 
    else
    {
      cout << "Please enter a pet's information " << endl;
      all_pets[num_pets].input();  //call the input function for the pet class
      ++num_pets;
      if (num_pets == HOTEL)   //THIS was the last pet we could add to array
        is_full = true;
    }
    return is_full;   //false if we are not done yet
}

//Display all pets at the hotel
bool pet_hotel::display_all()
{
    //Variable definitions
    bool has_pets = true;

    if (!num_pets)
      has_pets = false;
    for (int i = 0; i < num_pets; ++i)
      all_pets[i].display();

    return has_pets;
}

//save all the pets to an external file
void pet_hotel::save_all()
{
    for (int i = 0; i < num_pets; ++i)
        all_pets[i].save();
}
