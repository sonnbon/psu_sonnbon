//Header files (.h files)
//  - #includes
//  - constants
//  - structures
//  - prototypes
//  - class interface (public/private sections of the class)
//
//  Group related functions together in .cpp files
//  A header file is the "glue" holding it all together
//
//
//  Connor Williams
//  CS 162 - Lecture on classes
//  This file is organizing what a single pet would require
//  when working with a class

#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>

//constants
const int NAME = 31;
const int BREED = 41;

//Class interface that manages one pet
class pet
{
    public:
        pet(); //construction - initialize the data members to their zero
               //equivalent value
        ~pet(); //destructor - reset the data members back to their zero 
                //equivalent value
        void input();  //read in a pet's info
        void display(); //display a pet's info
        void save();    //save to an external data file

    private:
        //This will represent the data that is shared among the member
        //functions in the public section
        char name[NAME];
        char breed[BREED];
};
