#include "Program1_Williams_node.h"



// *****************************************************************************
// Author: Connor Williams
// Date: October 20, 2021
// Course: CS202 - Programming Systems
// Project: Program 1
// Filename: Program1_Williams_node.cpp
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



// - - - - - - - - - - STALL CLASS IMPLEMENTATION - - - - - - - - - -

//This default constructor sets the block ID and stall number integer, empty
//boolean, and stall type pointer to a character data types to their zero 
//equivalent value in an initialization list. It has no arguments or return 
//type.
stall::stall(): block_id(0), stall_num(0), empty(false), stall_type(nullptr)
{}



//This copy constructor deep copies a client inputted constant stall object to
//the invoked stall object and sets its parent address' object data in an 
//initialization list. It has a constant stall object, passed by reference, as 
//an argument and has no return type.
stall::stall(const stall & source): address(source)
{
    //Integer and boolean data types are memberwise copied.
    block_id = source.block_id;
    stall_num = source.stall_num;
    empty = source.empty;

    //Right-sized memory is dynamically allocated to the data member and the 
    //passed in object's respective data member is deep copied to it.
    stall_type = new char[strlen(source.stall_type) + 1];
    strcpy(stall_type, source.stall_type);
}



//This destructor resets all the stall object's data members to their zero
//value equivalent. It takes no arguments and has no return type.
stall::~stall()
{
    //Integer and boolean data types are reset to their zero values.
    block_id = 0;
    stall_num = 0;
    empty = false;

    //Checks if data member has memory before deallocating and resetting it
    //to NULL.
    if (stall_type)
    {
        delete [] stall_type;
        stall_type = nullptr;
    }
}



//This member function changes the stall type of the parking stall (2 Hour, 
//Loading Zone, etc.) using the client inputted data. This function takes a
//constant pointer to a character data type as an argument and has a void
//return type.
void stall::change_type(const char * new_type)
{
    //Checks if passed in data is valid.
    if (new_type)
    {
        //Checks if object's data already has memory and deallocates it if it
        //does.
        if (stall_type)
            delete [] stall_type;

        //Right-sized memory is dynamically allocated to the object's data
        //member and the new data is deep copied to it.
        stall_type = new char[strlen(new_type) + 1];
        strcpy(stall_type, new_type);
    }

    return;
}



//This member function finds a stall by its block ID and stall number, and
//removes the object if a match is found. This function takes two integer
//data types as arguments and returns an integer data type to represent
//the success or failure of a stall removal.
int stall::remove(int id_match, int stall_match)
{
    //If a match is not found, function returns a failure.
    if (block_id != id_match && stall_num != stall_match)
        return 0;
    
    //Integer and boolean data are reset to their zero equivalent values.
    block_id = 0;
    stall_num = 0;
    empty = false;

    //If the data member has memory allocated to it, then it is deallocated and
    //reset to NULL.
    if (stall_type)
    {
        delete [] stall_type;
        stall_type = nullptr;
    }

    //Returns a failure for debugging purposes if somehow there is no address to
    //remove.
    if(!address::remove())
        return 0;

    return 1; //Returns a success of the operation
}



//This constant member function checks to find if the cliented inputted street 
//name and parking stall type match the stall object's street and stall type
//data members. This function takes two pointers to a character data type as 
//arguments and returns true (a match) or false.
bool stall::find_by_street(char * match_street, char * match_type) const
{
    //Variable definitions
    bool is_match = false; //Will change to true if a match is found


    is_match = check_street(match_street); //Catches the street comparing result

    //Checks if is_match is already true, the inputted data and data member are
    //valid, and if the object's stall type and inputted stall type match.
    if (is_match && match_type && stall_type && !strcmp(stall_type, match_type))
        is_match = true;

    return is_match; //Returns a success (match) or failure of the operation
}



//This constant member function checks to find if the cliented inputted city
//name and parking stall type match the stall object's city and stall type
//data members. This function takes two pointers to a character data type as 
//arguments and returns true (a match) or false.
bool stall::find_by_city(char * match_city, char * match_type) const
{
    //Variable definitions
    bool is_match = false; //Will change to true if a match is found


    is_match = check_city(match_city); //Catches the city comparing result

    //Checks if is_match is already true, the inputted data and data member are
    //valid, and if the object's stall type and inputted stall type match.
    if (is_match && match_type && stall_type && !strcmp(stall_type, match_type))
        is_match = true;

    return is_match; //Returns a success (match) or failure of the operation
}



//This constant member function checks whether a parking stall is empty or
//occupied by a vehicle. It takes no arguments and returns true or false.
bool stall::is_empty() const
{
    //Checks if parking stall is empty
    if (empty)
        return true;

    return false; //Returns that the parking stall is occupied
}



//This member function occupies a parking stall with a vehicle object. It takes
//a constant vehicle object, passed by reference, as an argument and returns an
//integer to represent the success (1) or failure of the operation.
int stall::occupy(const vehicle & to_occupy)
{
    //Checks if the passed in vehicle object is valid and returns a failure of 
    //the operation if it is not.
    if(!my_vehicle.park(to_occupy))
        return 0;

      empty = false; //Parking stall is no longer empty

      return 1; //Returns a success of the operation
}



//This member function removes a vehicle from a parking stall and marks it as
//empty. This function takes a vehicle object, passed by reference, as an 
//argument and returns an integer to represent the success (1) or failure of the 
//operation.
int stall::exit(const vehicle & to_exit)
{
    //Checks if the stall is already empty or there is a failure in removing a
    //vehcle, returning a failure of this operation if either are true.
    if(empty || !my_vehicle.exit(to_exit))
        return 0;

    empty = true; //Parking stall is now empty

    return 1; //Returns a success of the operation
}



//This member function takes the client's input and adds parking stall 
//information to a stall object. This function takes no arguments and has a void
//return type.
void stall::input()
{
    //Variable definitions
    char temp_type[MAX]; //To be stall type of the object

    address::input(); //Reads in information for the stall's address object

    cout << "Please enter the block number where the stall is located: ";
    cin >> block_id;
    cin.ignore(100, '\n');

    cout << "Please enter the stall number it is on block " << block_id << ": ";
    cin >> stall_num;
    cin.ignore(100, '\n');

    empty = true; //A new stall starts off as unoccupied

    cout << "Please enter the stall type (2 Hour, 30 Minute, Loading Zone, "
         << "etc.): ";
    cin.get(temp_type, MAX, '\n');
    cin.ignore(100, '\n');

    //Dynamically allocates right sized memory for data member to be deep copied
    //to.
    stall_type = new char[strlen(temp_type) + 1];
    strcpy(stall_type, temp_type);

    return;
}



//This constant member function displays all stall object information to the
//client. This function takes no arguments and has a void return type.
void stall::display() const
{
    if (block_id != 0 && stall_num != 0 && stall_type)
    {
        address::display(); //Displays stall's address object information

        cout << "Block number: " << block_id << endl;
        cout << "Parking stall number: " << stall_num << endl;
        cout << "Stall type: " << stall_type << endl;
    
        //If stall is occupied, vehicle information gets displayed as well.
        if (empty)
            cout << "The stall is empty." << endl;
        else
        {
            cout << "The stall is occupied by a vehicle." << endl << endl;
            cout << "Vehicle information:" << endl;

            my_vehicle.display(); //Displays vehicle object information
        }
    }

    return;
}

// -----------------------------------------------------------------------------



