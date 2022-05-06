#include "Program1_Williams_location.h"



// *****************************************************************************
// Author: Connor Williams
// Date: October 11, 2021
// Course: CS202 - Programming Systems
// Project: Program 1
// Filename: Program1_Williams_vehicle.h
// *****************************************************************************
// This file contains three classes of a larger hierarchy, which strongly focus
// on vehicular aspects of an object (vehicle, car, and truck). The purpose of 
// the vehicle class, being derived from address (defined in the
// "Program1_Williams_location.h" file) and a base class of car and
// truck, is to manage all vehicle information, including its make (Ford,
// Toyota, etc.), model (RAV4, Civic, Prius, etc.), license plate number, and
// its type (personal or delivery) while also inheritting from the address 
// class (street and city information). The user will be able to add, change, 
// find parking by parking stall, park or exit a parking stall, remove, and 
// display a vehicle object. The purpose of the car class, being a class derived
// from vehicle, is to manage a car's specific information, including the number
// of passengers, the car's passenger capacity, and what the trip's purpose is
// (Restaurant, Shopping, Sight-Seeing, etc.) while also inheritting from the
// vehicle class. The car subclass allows the user to focus in more on the
// internal behaviour and characteristics of the object. With this class, the 
// user will be able to add a car, add or remove passengers, check if a car is
// full of passengers, change the trip's purpose, and display the object's 
// information. The purpose of the truck class is to manage a truck's specific
// information, including its number of packages and its capacity while also 
// inheritting from the vehicle class. The truck subclass allows the user to 
// focus in more on the internal behaviour and characteristcs of the object, 
// just as with the car class. With this class, the user will be able to add a
// truck, add or remove a package, check if the truck is full of packages,
// change the truck's capacity, and display an object's information. In this 
// hierarchy, the goal is for the car or truck classes, derived from the vehicle
// class, to be created and navigated to and from parking stalls to occupy
// within a city.
// *****************************************************************************



//This vehicle class is derived from an address. It keeps track of an individual 
//vehicle for the purpose of being created, or destroyed, and navigated to find
//a parking stall to occupy, or exit, within a city. It manages a vehicle's make
//(Ford, Toyota, etc.), model (RAV4, Civic, Prius, etc.), license plate number,
//and type (personal/delivery). It allows for the creation of a vehicle as
//well as its manipulation, which includes changing the vehicle's make and
//model, parking in or exiting from a parking stall with a stall object as an
//argument (integer return types), and the removal of a vehicle based on its 
//license plate number (integer return type). It allows for the user to find a 
//parking stall to park in by stall object and type (integer return types). All 
//other member functions have a void return type. This stall class also allows 
//the user to display the vehicle object's information.
class vehicle: public address
{
    public:
        vehicle();                                  //Default constructor
        vehicle(char * make, char * model,          //Constructor to set members
                char * license, char * type);
        vehicle(const vehicle & source);            //Copy constructor
        ~vehicle();                                 //Destructor
        void change_vehicle(char * make,            //Change object's make/model
                            char * model);
        int find_parking(const stall & to_find)     //Find parking by stall
                         const;
        int park(const stall & to_occupy);          //Park an object in a stall
        int exit(const stall & to_exit);            //Exit a parking stall
        void input();                               //Adds vehicle to object
        int remove(const char * license);           //Remove vehicle object
        void display() const;                       //Displays object's vehicle

    protected:
        char * make;    //To be make of vehicle (i.e., Toyota)
        char * model;   //To be model of vehicle (i.e., RAV4)
        char * license; //To be license plate number
        char * type;    //To be type of vehicle (Delivery/Personal)
};



//This car class is derived from a vehicle. It keeps track of an individual 
//car for the purpose of keeping vehicle data plus car specific information. It
//manages a number of passengers, the car's capacity of passengers, and the
//trip's purpose (Restaurant, Shopping, Sight-Seeing, etc.). It allows for the 
//creation of a car as well as its manipulation, which includes changing the
//trip's purpose (void return type), and adding or removing passengers (integer 
//return types). It allows for the user to check if a car is full of passengers
//(bool return type). All other member functions have a void return type. This
//car class also allows the user to display the car object's information.
class car: public vehicle
{
    public:
        car();                                      //Default constructor
        car(int num_of_passengers, int capacity,    //Constructor to set members
            char * trip_purpose);
        car(const car & source);                    //Copy constructor
        ~car();                                     //Destructor
        void change_purpose(const char * to_change);//Changes trips purpose
        bool is_full() const;                       //Checks if object is full
        int remove_passenger(int num_of_passengers);//Removes passengers
        int add_passenger(int num_of_passengers);   //Adds passengers
        void input();                               //Adds car to object
        void display() const;                       //Displays object's car

        
    protected:
        int num_of_passengers; //To be number of passengers
        int capacity;          //To be object's passenger capacity
        char * trip_purpose;   //The trip's purpose (restaurant, shopping, etc.)
};



//This truck class is derived from a vehicle. It keeps track of an individual 
//truck for the purpose of keeping vehicle data plus truck specific information. 
//It manages a number of packages and the truck's capacity of packages. It 
//allows for the creation of a truck as well as its manipulation, which includes 
//changing the truck's capacity, and adding or removing packages (integer return 
//types). It allows for the user to check if a truck is full of packages
//(bool return type). All other member functions have a void return type. This
//truck class also allows the user to display the truck object's information.
class truck: public vehicle
{
    public:
        truck();                                    //Default constructor
        truck(int num_of_packages, int capacity);   //Constructor to set members
        ~truck();                                   //Destructor
        int change_capacity(int capacity);          //Change object's capacity
        bool is_full() const;                       //Checks if object is full
        int add_package(int num_of_packages);       //Add packages
        int remove_package(int num_of_packages);    //Remove packages (deliver)
        void input();                               //Adds truck to object
        void display() const;                       //Display object's truck

    protected:
        int num_of_packages; //To be number of packages
        int capacity;        //To be object's package capacity
};
        

 
