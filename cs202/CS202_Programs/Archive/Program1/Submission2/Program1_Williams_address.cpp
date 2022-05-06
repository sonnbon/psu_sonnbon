#include "Program1_Williams_address.h"
using namespace std;



// *****************************************************************************
// Author: Connor Williams
// Date: October 20, 2021
// Course: CS202 - Programming Systems
// Project: Program 1
// Filename: Program1_Williams_address.cpp
// *****************************************************************************
// The purpose of this file is to implement address, parking stall, and vehicle
// object related member functions in order to manage locational and general
// vehicle information. This file implements the address class' ability to add, 
// manipulate, compare, read in, and display street and city information for one 
// object. The stall class has the ability to do the same as well as access 
// information from its parent class, address. The vehicle class has the ability
// to do the same as the address class as well as park and exit a vehicle in and
// from a parking stall and remove a vehicle object. Default and copy
// constructors are implemented in order to set members to their zero equivalent
// values and to deep copy another object with dynamic data, respectively. The 
// address class specifically takes pointers to character data types and address 
// object data types as arguments in order to change, compare, and copy 
// locational information. The stall class specifically takes integer data 
// types, pointers to character data types, and vehicle object data types as 
// arguments in order to change, compare, and remove locational information as 
// well as occupy or unoccupy a parking stall with a vehicle. The vehicle class
// specifically takes pointer to character data types, and vehicle object data 
// types as arguments in order to change, and park or exit a vehicle 
// from a stall. Member function return types include void, integer, and 
// boolean. Integer and boolean return types are specifically used to check for 
// the success of a member function's operation.
// *****************************************************************************



// - - - - - - - - - - ADDRESS CLASS IMPLEMENTATION - - - - - - - - - -

//This default constructor sets the street and city character pointer data type 
//members to their zero equivalent value in an initialization list. It has no 
//arguments or return type.
address::address(): street(nullptr), city(nullptr)
{}



//This constructor sets the street and city character pointer data type members
//to client inputted values. It has two pointers to the character data type as 
//arguments and has no return type.
address::address(char * a_street, char * a_city)
{
    //Checks if the inputted data is valid, then dynamically allocates the 
    //right-sized amount of memory in order to deep copy those values to their
    //respective data members.
    if (a_street && a_city)
    {
        street = new char[strlen(a_street) + 1];
        strcpy(street, a_street);

        city = new char[strlen(a_city) + 1];
        strcpy(city, a_city);
    }
}



//This copy constructor deep copies a client inputted constant address object to
//the invoked address object. It has a constant address object, passed by 
//reference, as an argument and has no return type.
address::address(const address & source)
{
    //Checks if the inputted object's data is valid, then dynamically allocates 
    //the right-sized amount of memory in order to deep copy those values to 
    //their respective data members.
    if (source.street && source.city)
    {
        street = new char[strlen(source.street) + 1];
        strcpy(street, source.street);

        city = new char[strlen(source.city) + 1];
        strcpy(city, source.city);
    }
}



//This destructor resets the street and city character pointer data type members
//to their zero equivalent value by deallocating any dynamically allocated
//memory. It has no arguments or return type. 
address::~address()
{
    if (street)
    {
        delete [] street;
        street = nullptr;
    }

    if (city)
    {
        delete [] city;
        city = nullptr;
    }
}



//This member function "changes" or adds a new street and city name to the
//address object. It checks whether the passed in data is valid before deep
//copying it to the object's data members. The data members are also first
//checked to see if they are already pointing to data. If so, they are 
//deallocated. Otherwise, right-sized memory is dynamically allocated to 
//these data members. This function takes two pointers to a character data
//type and has a void return type.
void address::change_address(char * new_street, char * new_city)
{

    //Checks if the passed in data is valid.
    if (new_street && new_city)
    {
        //Checks if data member already has data. If so, it must be deallocated.
        if (street)
            delete [] street;

        //Deep copies the passed in data to the data member.
        street = new char[strlen(new_street) + 1];
        strcpy(street, new_street);

        //Checks if data member already has data. If so, it must be deallocated.
        if (city)
            delete [] city;

        //Deep copies the passed in data to the data member.
        city = new char[strlen(new_city) + 1];
        strcpy(city, new_city);
    }

    return;    
}



//This member function "copies" or adds a new address object's data to the
//address object calling the function. It calls the change_address member
//function, which takes care of adding the passed in object's individual data
//members. This function takes a constant address object, passed by reference,
//as an argument and has a void return type.
void address::copy_address(const address & to_copy)
{
    //Returns member function to "change" or add the passed in object's data
    //members to the address object calling the function.
    return change_address(to_copy.street, to_copy.city);
}



//This constant member function checks whether the client inputted data matches
//with the address object's street name data member. This function takes a
//constant pointer to a character data type as an argument and returns true (a
//match) or false.
bool address::check_street(const char * to_compare) const
{
    //Variable definitions
    bool is_match = false; //Will change to true if a match is found

    
    //Checks whether the inputted data is valid, the data member is not NULL,
    //and if the inputted data matches the data member.
    if (to_compare && street && !strcmp(street, to_compare))
        is_match = true;

    return is_match; //Returns true or false (whether a match was found)
}



//This constant member function checks whether the client inputted data matches
//with the address object's city name data member. This function takes a
//constant pointer to a character data type as an argument and returns true (a
//match) or false.
bool address::check_city(const char * to_compare) const
{
    //Variable definitions
    bool is_match = false; //Will change to true if a match is found

    
    //Checks whether the inputted data is valid, the data member is not NULL,
    //and if the inputted data matches the data member.
    if (to_compare && city && !strcmp(city, to_compare))
        is_match = true;

    return is_match; //Returns true or false (whether a match was found)
}



//This member function removes all data from the address object. This function
//takes no arguments and returns an integer to represent the success or failure
//or an operation.
int address::remove()
{
    //Check to see if the data members are already NULL and return a failure of
    //the operation if so.
    if (!street || !city)
        return 0;

    if (street)
    {
        delete [] street;
        street = nullptr;
    }

    if (city)
    {
        delete [] city;
        city = nullptr;
    }

    return 1; //Returns a success of the operation
}



//This member function lets the client input or add address information of an
//object's street and city name. It prompts and reads in the client's data, then
//calls the change_address member function to add the information. This function
//takes no arguments and has a void return type.
void address::input()
{
    //Variable definitions
    char new_street[MAX]; //To be client inputted temporary street name
    char new_city[MAX];   //To be client inputted temporary city name

    cout << "Please enter the street name: ";
    cin.get(new_street, MAX, '\n');
    cin.ignore(100, '\n');
    
    cout << "Please enter the city name: ";
    cin.get(new_city, MAX, '\n');
    cin.ignore(100, '\n');

    //Returns member function to "change" or add the client inputted street
    //and city name to the address object's data members.
    return change_address(new_street, new_city);
}



//This constant member function displays the address object's street and city
//name information to the client. This function takes no arguments and has a
//void return type.
void address::display() const
{
    //Checks that the object has data before displaying.
    if (street && city)
    {
        cout << "Street: " << street << endl;
        cout << "City: " << city << endl << endl;
    }

    return;
}

// -----------------------------------------------------------------------------



