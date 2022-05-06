#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>



// *****************************************************************************
// Author: Connor Williams
// Date: October 15, 2021
// Course: CS202 - Programming Systems
// Project: Program 1
// Filename: Program1_Williams_location.h
// *****************************************************************************
// This file contains three classes of a larger hierarchy, which strongly focus
// on locational and general vehicle aspects of an object (address, stall, and 
// vehicle). The purpose of the address class, being a base class, is to manage 
// all address information (street and city) for any object's class that is 
// derived from it. The user will be able to add, change, copy, compare, and 
// display an address of any address or derived object. The purpose of the stall 
// class, being a class derived from address, is to manage more specific 
// location information (block face identification and stall number) as well as 
// behavioral information (whether it is empty and what type of stall it is) 
// while also inheritting address information. The purpose of this specific 
// management is to have a stall ultimately be occupied or unoccupied by a 
// vehicle of a certain type. If a stall is occupied or a vehicle's type does 
// not match a stall's parking type, then it cannot park there. The user will be 
// able to add, change, remove, find, occupy, exit, and display a stall object. 
// The purpose of the vehicle class, being derived from address, is to manage 
// all vehicle information, including its make (Ford, Toyota, etc.), model 
// (RAV4, Civic, Prius, etc.), license plate number, and its type (personal or 
// delivery) while also inheritting from the address class (street and city 
// information). The user will be able to add, change, park or exit a parking 
// stall, and display a vehicle object.
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



//This vehicle class is derived from an address. It keeps track of an individual 
//vehicle for the purpose of being created, or destroyed, and navigated to find
//a parking stall to occupy, or exit, within a city. It manages a vehicle's make
//(Ford, Toyota, etc.), model (RAV4, Civic, Prius, etc.), license plate number,
//and type (personal/delivery). It allows for the creation of a vehicle as
//well as its manipulation, which includes changing the vehicle's make and
//model, copying data from another vehicle object (parking vehicle) and exiting 
//from a parking stall with a stall object as an argument (integer return 
//types). All other member functions have a void return type. This stall class 
//also allows the user to display the vehicle object's information.
class vehicle: public address
{
    public:
        vehicle();                                  //Default constructor
        vehicle(const vehicle & source);            //Copy constructor
        ~vehicle();                                 //Destructor
        void change_vehicle(char * make,            //Change object's make/model
                            char * model);
        int park(const vehicle & to_occupy);        //Park an object in a stall
        int exit(const vehicle & to_exit);             //Exit a parking stall
        void add(char * make, char * model,         //Adds a vehicle object
                 char * license, char * type);
        void input();                               //Adds vehicle to object
        void display() const;                       //Displays object's vehicle

    protected:
        char * make;    //To be make of vehicle (i.e., Toyota)
        char * model;   //To be model of vehicle (i.e., RAV4)
        char * license; //To be license plate number
        char * type;    //To be type of vehicle (Delivery/Personal)
};



// -----------------------------------------------------------------------------

//This stall class is derived from an address. It keeps track of an individual 
//parking stall for the purpose of being empty or occupied by a vehicle. It
//manages a block face identification number (block_id - a specific side of a
//city block with a given ID), a stall number (where the stall is on that block
//face), whether it is empty, what type of parking stall it is (2 Hour, 30 
//Minute, Loading Zone, etc.), and a vehicle object. It allows for the creation 
//of a parking stall as well as its manipulation, which includes changing the 
//stall type with a new stall type, removing a stall with the block ID and stall 
//number passed in (integer return type), and occupying (with a vehicle object) 
//or exiting a stall (integer return types). It allows for the user to find a 
//parking stall by street and type or by city and type, as well as to check if a 
//stall is empty (bool return types). All other member functions have a void 
//return type. This stall class also allows the user to display the stall 
//object's information.
class stall: public address
{
    public:
        stall();                                    //Default constructor
        stall(const stall & source);                //Copy constructor
        ~stall();                                   //Destructor
        void change_type(const char * stall_type);  //Change parking stall type
        int remove(int block_id, int stall_num);    //Remove specific stall
        bool find_by_street(char * street,          //Is it available on street
                            char * stall_type) 
                            const;
        bool find_by_city(char * city,              //Is it available in city
                          char * stall_type) 
                          const;
        bool is_empty() const;                      //Is object empty or full
        int occupy(const vehicle & to_occupy);      //Occupies parking stall
        int exit(const vehicle & to_exit);         //Free's a parking stall
        void input();                               //Adds stall to object
        void display() const;                       //Displays object's stall

    protected:
        int block_id;      //Block face ID number (location on a parking block)
        int stall_num;     //Stall number (location on a block face)
        bool empty;        //To be empty or occupied
        char * stall_type; //Stall type (2 Hour, 30 Minute, Loading Zone, etc.)
        vehicle my_vehicle; //Vehicle to occupy parking stall
};



 
