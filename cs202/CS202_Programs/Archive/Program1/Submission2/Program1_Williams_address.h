#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>



// *****************************************************************************
// Author: Connor Williams
// Date: October 20, 2021
// Course: CS202 - Programming Systems
// Project: Program 1
// Filename: Program1_Williams_address.h
// *****************************************************************************
// This file contains one class of a larger hierarchy, which strongly focuses
// on locational aspects of an object (address). The purpose of the address 
// class, being a base class, is to manage all address information (street and 
// city) for any object's class that is derived from it. The user will be able 
// to add, change, copy, compare, and display an address of any address or 
// derived object.
// *****************************************************************************



// - - - - - - - - - - C O N S T A N T S - - - - - - - - - -

const int MAX = 31; //To be max character size for any inputted array
// -----------------------------------------------------------------------------



// - - - - - - - - - - C L A S S E S - - - - - - - - - -

//This address class keeps track of an individual address (street and city) for
//the purpose of keeping track of an object's location. It allows for the 
//creation of an address as well as its manipulation, which includes changing 
//the address with a new street and city name or by copying one address to the 
//current object's address. It allows for the user to compare an address by 
//street or by city and will return a bool value depending on if a match is 
//found. All other member functions have a void return type. This address class 
//also allows the user to display the street and city information of a certain 
//address object.
class address
{
    public:
        address();                                  //Default constructor 
        address(char * street, char * city);        //Constructor to set members
        address(const address & source);            //Copy constructor
        ~address();                                 //Destructor
        void change_address(char * new_street,      //Changes address of object
                            char * new_city);
        void copy_address(const address & to_copy); //Copies address to object
        bool check_street(const char * to_compare)  //Checks if streets match
                          const;
        bool check_city(const char * to_compare)    //Checks if cities match
                        const;
        int remove();                               //Removes address
        void input();                               //Adds address to object
        void display() const;                       //Displays object's address

    protected:
        char * street; //To be object's street name
        char * city;   //To be object's city name
};

// -----------------------------------------------------------------------------



