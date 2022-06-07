#include "CS162_pet.h"

//Connor Williams
//CS162 - Lecture on classes
//This file is setting up a hotel for pets


//Constants
const int HOTEL = 5;

//Class Interface
class pet_hotel
{
    public:
        pet_hotel();         //default constructor
        ~pet_hotel();        //destructor
        bool input();        //read in a pet
        bool display_all();  //display all pets at the hotel
        void save_all();     //save all the pets


    private:
        pet all_pets[HOTEL]; //Array for the max number of pets
        int num_pets;        //The number of pets actually in the hotel now
};
