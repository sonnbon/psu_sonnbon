#include "Program1_Williams_node.h"
using namespace std;



// *****************************************************************************
// Author: Connor Williams
// Date: October 20, 2021
// Course: CS202 - Programming Systems
// Project: Program 1
// Filename: Program1_Williams_main.cpp
// *****************************************************************************
// The purpose of this file is to act as the application client to test and
// call functions in order to add, manipulate, and remove address', parking 
// stall's, vehicle's, car', and truck's all with the goal of being able to have
// three smart devices (stall, car, and truck) communicate wih each other and
// occupy or unoccupy available parking stalls within a user created city
// (client adds blocks and parking stalls). ---MORE HEADER TO BE DETERMINED---
// ---TESTING INTERFACE WILL BE CLEANER---
// --STILL NEED TO CHANGE ANY STATIC CHAR THAT WILL NOT BE DYNAMIC TO STRING--
//
//
//
// *****************************************************************************



int main()
{  
    // ---------- TESTING ADDRESS OBJECTS AND MEMBER FUNCTIONS ----------

    //Variable definitions
    address test_address;
    char test_street[MAX];
    char test_city[MAX];
    
    //Test input and display
    cout << "test_address" << endl;
    test_address.input();
    test_address.display();

    //Test CC and display
    cout << "test_address2" << endl;
    address test_address2(test_address);
    test_address2.display();

    //Test constructor manual set
    cout << "test_address3" << endl;
    cout << "Please enter a street name: ";
    cin.get(test_street, MAX, '\n');
    cin.ignore(100, '\n');

    cout << "Please enter a city name: ";
    cin.get(test_city, MAX, '\n');
    cin.ignore(100, '\n');

    address test_address3(test_street, test_city);
    test_address3.display();

    //Test change an address
    cout << "Changing test_address to test_address3" << endl;
    test_address.change_address(test_street, test_city);
    test_address.display();

    //Test copy an address
    cout << "Copying test_address2 to test_address3" << endl;
    test_address3.copy_address(test_address2);
    test_address3.display();

    //Test check a street
    if (test_address.check_street(test_street))
        cout << "test_address matches street" << endl;
    if (test_address2.check_street(test_street))
        cout << "test_address2 matches street" << endl;
    if (test_address3.check_street(test_street))
        cout << "test_address3 matches street" << endl;

    //Test check a city
    if (test_address.check_city(test_city))
        cout << "test_address matches city" << endl;
    if (test_address2.check_city(test_city))
        cout << "test_address2 matches city" << endl;
    if (test_address3.check_city(test_city))
        cout << "test_address3 matches city" << endl;
    // -------------------------------------------------------------------------


    // ---------- TESTING STALL OBJECTS AND MEMBER FUNCTIONS ----------
    stall test_stall;

    //Test input and display
    cout << "test_stall" << endl;
    test_stall.input();
    test_stall.display();

    //Test copy constructor
    cout << "test_stall2" << endl;
    stall test_stall2(test_stall);
    test_stall2.display();

    //Test manipulation
    cout << "change test_stall2" << endl;
    test_stall2.change_address(test_street, test_city);
    test_stall2.display();

    cout << "change test_stall" << endl;
    test_stall.copy_address(test_address);
    test_stall.display();

    //Change type
    char stall_type[MAX];
    cout << "change stall type to: ";
    cin.get(stall_type, MAX, '\n');
    cin.ignore(100, '\n');

    test_stall.change_type(stall_type);
    test_stall.display();

    //Find stall type
    cout << "find stall type " << stall_type << " at " << test_street << endl;
    if(!test_stall2.find_by_street(test_street, stall_type))
        cout << "It's here!!!" << endl << endl;
    else
        cout << "it's not here... " << endl << endl;

    cout << "find stall type " << stall_type << " at " << test_city << endl;
    if (!test_stall2.find_by_city(test_city, stall_type))
        cout << "It's in the city!!! " << endl << endl;
    else
        cout << "it's not in the city..." << endl << endl;

    
    // ---------- TESTING VEHICLE OBJECTS AND MEMBER FUNCTIONS ----------

    vehicle test_vehicle;

    //Input and display test_vehicle
    test_vehicle.input();
    test_vehicle.display();

    //Occupy the stall and exit it
    test_stall.occupy(test_vehicle);
    test_stall.display();

    //Is the stall empty
    if (!test_stall.is_empty())
       cout << "The stall is empty" << endl;
    else
       cout << "The stall is not empty" << endl;

    if (!test_stall2.is_empty())
        cout << "test_stall2 is empty" << endl;
    else
        cout << "test_stall2 is not empty" << endl;

    //Test CC and then change the make and model
    vehicle test_vehicle2(test_vehicle);
    char new_make[MAX];
    char new_model[MAX];

    cout << "New make? ";
    cin.get(new_make, MAX, '\n');
    cin.ignore(100, '\n');

    cout << "New model? ";
    cin.get(new_model, MAX, '\n');
    cin.ignore(100, '\n');

    test_vehicle2.change_vehicle(new_make, new_model);
    test_vehicle2.display();

/*
    // ---------- TESTING CAR OBJECTS AND MEMBER FUNCTIONS ----------
    car test_car;

    //Input and display test_car
    test_car.input();
    test_car.display();

    //Change trip's purpose
    char new_purpose[MAX];

    cout << "What's the new trip's purpose: ";
    cin.get(new_purpose, MAX, '\n');
    cin.ignore(100, '\n');

    test_car.change_purpose(new_purpose);
    test_car.display();

    //Test CC and display
    car test_car2(test_car);
    test_car2.display();

    //Add and remove passengers
    int new_total = test_car.add_passenger(1);
    cout << "There are " << new_total << " passengers now" << endl << endl;

    if (test_car2.add_passenger(30) == -1)
        cout << "That's not a valid amount of passengers..." << endl << endl;



    // ---------- TESTING TRUCK  OBJECTS AND MEMBER FUNCTIONS ----------
    truck test_truck;

    //Input and display test_truck
    test_truck.input();
    test_truck.display();
    
    //Increase capacity
    int new_cap = test_truck.change_capacity(30);
    cout << "The truck has a capacity of " << new_cap << " now" << endl << endl;
    test_truck.display();
*/

    return 0;
}
