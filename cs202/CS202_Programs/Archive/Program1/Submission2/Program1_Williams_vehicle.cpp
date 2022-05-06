#include "Program1_Williams_vehicle.h"



// *****************************************************************************
// Author: Connor Williams
// Date: October 20, 2021
// Course: CS202 - Programming Systems
// Project: Program 1
// Filename: Program1_Williams_vehicle.cpp
// *****************************************************************************
// The purpose of this file is to implement car and truck object related member
// functions in order to manage more specific vehicle information. This file 
// implements the car class' ability to add, remove, manipulate, read in, and 
// display number of passenger, passenger capacity, and trip purpose (Shopping,
// Restaurant, etc.) information for one object. It also can access information
// from its parent class, vehicle (in Program1_Williams_location.cpp file). The 
// truck class has the ability to do the same (except with packages and capacity 
// size) as well as access information from its parent class, vehicle. Default 
// and copy constructors (for the car class) are implemented in order to set 
// members to their zero equivalent values and to deep copy another object with 
// dynamic data, respectively. The car class specifically takes pointers to 
// character and integer data types as arguments in order to change internal 
// vehiclular aspects. The truck class specifically takes integer data 
// types as arguments in order to change internal vehicular aspects. Member 
// function return types include void, integer, and boolean. Integer and boolean 
// return types are specifically used to check for the success of a member 
// function's operation. More specifically most integer return types are used
// to catch an updated number, whether it be the number of passengers in a car,
// or the number of packages or new capacity of a truck.
// *****************************************************************************



// - - - - - - - - - - VEHICLE CLASS IMPLEMENTATION - - - - - - - - - -

//This default constructor sets all the data members to their zero equivalent
//value in an initialization list. It takes no arguments and has no return type.
vehicle::vehicle(): make(nullptr), model(nullptr), license(nullptr), 
                    type(nullptr)
{}



//This copy constructor deep copies a client inputted constant vehicle object to
//the invoked vehicle object and sets its parent address' object data in an 
//initialization list. It has a constant vehicle object, passed by reference, as 
//an argument and has no return type.
vehicle::vehicle(const vehicle & source): address(source)
{
    //Checks if passed in object's data members are valid and then dynamically
    //allocates the right-sized memory and deep copies the passed in data to
    //each of the current object's data members.
    if (source.make && source.model && source.license && source.type)
    {
        make = new char[strlen(source.make) + 1];
        strcpy(make, source.make);

        model = new char[strlen(source.model) + 1];
        strcpy(model, source.model);

        license = new char[strlen(source.license) + 1];
        strcpy(license, source.license);

        type = new char[strlen(source.type) + 1];
        strcpy(type, source.type);
    }
}



//This destructor deletes any of the data members' dynamically allocated memory
//and resets them to their zero equivalent values. It takes no arguments and has
//no return type.
vehicle::~vehicle()
{
    //Checks for any dynamically allocated memory and, if so, deallocates the
    //memory and sets the array to NULL.
    if (make)
    {
        delete [] make;
        make = nullptr;
    }
    
    //Checks for any dynamically allocated memory and, if so, deallocates the
    //memory and sets the array to NULL.
    if (model)
    {
        delete [] model;
        model = nullptr;
    }

    //Checks for any dynamically allocated memory and, if so, deallocates the
    //memory and sets the array to NULL.
    if (license)
    {
        delete [] license;
        license = nullptr;
    }

    //Checks for any dynamically allocated memory and, if so, deallocates the
    //memory and sets the array to NULL.
    if (type)
    {
        delete [] type;
        type = nullptr;
    }
}



//This member function allows the client to change a vehicle object's make and
//model. This function takes two pointers to a character data type as
//arguments and has a void return type.
void vehicle::change_vehicle(char * new_make, char * new_model)
{
    //Checks if passed in data is valid before making any deep copies to the
    //data members
    if (new_make && new_model)
    {
        //Deallocates the data member's memory if there is already dynamically
        //allocated data.
        if (make)
            delete [] make;

        //Dynamically allocates the right-sized memory for the new value to be
        //deep copied to the data member.
        make = new char[strlen(new_make) + 1];
        strcpy(make, new_make);

        //Deallocates the data member's memory if there is already dynamically
        //allocated data.
        if (model)
            delete [] model;

        //Dynamically allocates the right-sized memory for the new value to be
        //deep copied to the data member.
        model = new char[strlen(new_model) + 1];
        strcpy(model, new_model);
    }

    return;
}



//This member function truly copies a client inputted vehicle object to the 
//current vehicle object, which will represent a vehicle parking in a stall
//object. This function takes a constant vehicle object, passed by reference, as
//an argument and returns an integer to represent the success (1) or failure of
//the operation.
int vehicle::park(const vehicle & to_occupy)
{
    //Checks if passed in object's data members are valid and then dynamically
    //allocates the right-sized memory and deep copies the passed in data to
    //each of the current object's data members.
    if (to_occupy.make && to_occupy.model && to_occupy.license && 
        to_occupy.type)
    {
        //Calls member function to add each passed in object's data member
        //to the current object's data members.
        add(to_occupy.make, to_occupy.model, to_occupy.license, 
                    to_occupy.type);

        return 1; //Returns a success of the operation
    }

    return 0; //Returns a failure of the operation
}



//This member function truly removes the vehicle object by first matching
//the passed in vehicle object, which will represent a vehicle exiting a
//stall object. This function takes a vehicle object, passed by reference,
//as an argument and returns an integer to represent the success (1) or failure 
//of an operation.
int vehicle::exit(const vehicle & to_exit)
{
    //Checks if the inputted data is valid or if it does not match with the
    //current object's license plate number.
    if (!to_exit.license || strcmp(license, to_exit.license))
        return 0; //Returns a failure of the operation

    //Checks for any dynamically allocated memory and, if so, deallocates the
    //memory and sets the array to NULL.
    if (make)
    {
        delete [] make;
        make = nullptr;
    }
    
    //Checks for any dynamically allocated memory and, if so, deallocates the
    //memory and sets the array to NULL.
    if (model)
    {
        delete [] model;
        model = nullptr;
    }

    //Checks for any dynamically allocated memory and, if so, deallocates the
    //memory and sets the array to NULL.
    if (license)
    {
        delete [] license;
        license = nullptr;
    }

    //Checks for any dynamically allocated memory and, if so, deallocates the
    //memory and sets the array to NULL.
    if (type)
    {
        delete [] type;
        type = nullptr;
    }

    //Returns a failure for debugging purposes if somehow there is no address to
    //remove.
    if(!address::remove())
        return 0;

    return 1; //Returns a success of the operation
}


void vehicle::add(char * a_make, char * a_model, char * a_license, 
                  char * a_type)
{
    //Checks if passed in values are valid and then dynamically allocates the 
    //right-sized memory and deep copies the passed in data to each of the 
    //current object's data members.
    if (a_make && a_model && a_license && a_type)
    {
        make = new char[strlen(a_make) + 1];
        strcpy(make, a_make);

        model = new char[strlen(a_model) + 1];
        strcpy(model, a_model);

        license = new char[strlen(a_license) + 1];
        strcpy(license, a_license);

        type = new char[strlen(a_type) + 1];
        strcpy(type, a_type);
    }

    return;
}



//This member function lets the client input or add vehicle information of an
//object's make, model, license plate number, and type (personal or delivery). 
//It prompts and reads in the vehicle information and then calls the add_vehicle
//member function. This function takes no arguments and has a void return type.
void vehicle::input()
{
    //Variable definitions
    char a_make[MAX];    //To be a temporary make
    char a_model[MAX];   //To be a temporary model
    char a_license[MAX]; //To be a temporary license plate
    char a_type[MAX];    //To be a temporary type

    address::input(); //Inputs address information first

    cout << "Please enter the vehicle's make: ";
    cin.get(a_make, MAX, '\n');
    cin.ignore(100, '\n');

    cout << "Please enter the vehicle's model: ";
    cin.get(a_model, MAX, '\n');
    cin.ignore(100, '\n');

    cout << "Please enter the vehicle's license plate number: ";
    cin.get(a_license, MAX, '\n');
    cin.ignore(100, '\n');

    cout << "Please enter if this is a Personal or Delivery vehicle: ";
    cin.get(a_type, MAX, '\n');
    cin.ignore(100, '\n');

    //Calls the member function to add the client inputted data to the object.
    return add(a_make, a_model, a_license, a_type);
}



//This constant member function displays the vehicle data to the client. This
//function takes no arguments and has a void return type.
void vehicle::display() const
{
    address::display(); //Displays vehicle's address object information

    //Checks that the vehicle has data before displaying.
    if (make && model && license && type)
    {
        cout << "Make: " << make << endl;
        cout << "Model: " << model << endl;
        cout << "License Plate Number: " << license << endl;
        cout << "Type: " << type << endl << endl;
    }

    return;
}

// -----------------------------------------------------------------------------



// - - - - - - - - - - CAR CLASS IMPLEMENTATION - - - - - - - - - -

//This default constructor sets the data members to their zero equivalent values 
//in an initialization list. It has no arguments or return type.
car::car(): num_of_passengers(0), capacity(0), trip_purpose(nullptr)
{}




//This copy constructor deep copies a client inputted constant car object to
//the invoked car object. It has a constant car object, passed by reference, as 
//an argument and has no return type.
car::car(const car & source): vehicle(source)
{
    num_of_passengers = source.num_of_passengers;
    capacity = source.capacity;

    //Checks if the inputted object's data member is valid before dynamically
    //allocating the right-sized memory and deep copying to the current object's
    //data member.
    if (source.trip_purpose)
    {
        trip_purpose = new char[strlen(source.trip_purpose) + 1];
        strcpy(trip_purpose, source.trip_purpose);
    }
}



//This destructor deallocates any dynamically allocated memory and resets all
//data members to their zero equivalent values. It takes no arguments and has no
//return type.
car::~car()
{
    num_of_passengers = 0;
    capacity = 0;

    //Checks if there is any dynamically allocated memory before deallocating
    //and resetting to NULL.
    if (trip_purpose)
    {
        delete [] trip_purpose;
        trip_purpose = nullptr;
    }
}



//This member function changes the purpose of the car's trip through the client
//inputted data. This function takes a constant pointer to a character data type
//as an argument and has a void return type.
void car::change_purpose(const char * to_change)
{
    //Checks if the inputted data is valid.
    if (to_change)
    {
        //If there is already memory allocated, then it gets deallocated.
        if (trip_purpose)
            delete [] trip_purpose;

        //Right-sized memory is dynamically allocated to the data member and the
        //client inputted data is deep copied to it.
        trip_purpose = new char[strlen(to_change) + 1];
        strcpy(trip_purpose, to_change);
    }

    return;

}



//This constant member function checks to see if the car is full of passengers.
//This function takes no arguments and returns true (full) or false.
bool car::is_full() const
{
    //If the number of passengers is the same as the capacity then return
    //true to the client.
    if (num_of_passengers == capacity)
        return true;

    return false;
}



//This member function removes one or more passengers from the car depending on
//the client's inputted data. This function takes an integer as an argument and
//returns an integer to represent the number of passengers left in the car.
int car::remove_passenger(int to_remove)
{
    //If the data member is already zero or subtracting would result in a
    //negative number, return a failure of the operation.
    if (num_of_passengers == 0 || to_remove < 0 || 
        num_of_passengers - to_remove < 0)
        return -1; //Returns -1 since 0 is a valid result in this case
    
    num_of_passengers -= to_remove; 

    return num_of_passengers; //Returns the number of passengers
}



//This member function adds one or more passengers to the car depending on the
//client's inputted data. This function takes an integer as an argument and 
//returns an integer to represent the number of passengers in the car.
int car::add_passenger(int to_add)
{
    //If the data member is already at capacity or adding would result in being
    //over capacity, return a failure of the operation.
    if (num_of_passengers == capacity || to_add < 0 || 
        to_add + num_of_passengers > capacity)
        return -1; //Returns -1 since 0 could be a valid result in this case.

    num_of_passengers += to_add;

    return num_of_passengers; //Returns the number of passengers
}



//This member function lets the client input or add car information of an
//object's number of passengers, capacity, and purpose of trip. It prompts and 
//reads in the car information. This function takes no arguments and has a void 
//return type.
void car::input()
{
    //Variable definitions
    char temp_purpose[MAX]; //To be temporary trip's purpose

    address::input(); //Inputs address information
    vehicle::input(); //Inputs vehicle information

    cout << "Please enter what the purpose of your trip is (Shopping, "
         << "Restaurant, etc.): ";
    cin.get(temp_purpose, MAX, '\n');
    cin.ignore(100, '\n');

    //Deallocate any memory that might already be allocated to this data member.
    if (trip_purpose)
        delete [] trip_purpose;

    //Right-sized memory gets dynamically allocated to the data member and the
    //temporary data gets deep copied to it.
    trip_purpose = new char[strlen(temp_purpose) + 1];
    strcpy(trip_purpose, temp_purpose);

    //Loop makes sure the client does not enter too many passengers.
    do
    {
        cout << "Please enter the number of passengers in your car: ";
        cin >> num_of_passengers;
        cin.ignore(100, '\n');

        cout << "Please enter the capacity of your car: ";
        cin >> capacity;
        cin.ignore(100, '\n');

        //Checks that the number of passengers is correct.
        if (num_of_passengers < 0 || capacity < 0 || 
            num_of_passengers > capacity)
        {
            cout << "Sorry, this is an invalid entry. Try again..."
                 << endl << endl;
        }

    } while (num_of_passengers < 0 || capacity < 0 || num_of_passengers > capacity);

    return;
}




//This constant member function displays the car data to the client. This
//function takes no arguments and has a void return type.
void car::display() const
{
    address::display(); //Display's address information
    vehicle::display(); //Display's vehicle information

    //If data members are valid, car's information gets displayed.
    if (capacity != 0 && trip_purpose)
    {
        cout << "Number of passengers: " << num_of_passengers << endl;
        cout << "Car's passenger capacity: " << capacity << endl;
        cout << "Trip's purpose: " << trip_purpose << endl << endl;
    }

    return;
}

// -----------------------------------------------------------------------------



// - - - - - - - - - - TRUCK CLASS IMPLEMENTATION - - - - - - - - - -
        
   /* protected:
        int num_of_packages; //To be number of packages
        int capacity;        //To be object's package capacity
   */

//This default constructor sets the data members to their zero equivalent values 
//in an initialization list. It has no arguments or return type.
truck::truck(): num_of_packages(0), capacity(0)
{}



//This destructor resets the data members to their zero equivalent values. It
//has no arguments or return type.
truck::~truck()
{
    num_of_packages = 0;
    capacity = 0;
}



//This member function changes the capacity of packages to a size depening on
//clients inputted data. This function takes an integer as an argument and 
//returns an integer representing the capacity of the object.
int truck::change_capacity(int new_size)
{
    //Checks that the inputted value is valid and returns a failure of the
    //operation if so.
    if (new_size <= 0)
        return 0; //Return zero works because a capacity of zero is not possible
    
    capacity = new_size;

    return capacity; //Returns new capacity size
}



//This constant member function checks if the truck is full. This function takes
//no arguments and returns true (full) or false.
bool truck::is_full() const
{
    //Check if the number of packages is equal to the capacity and return true
    //to the client if so.
    if (num_of_packages == capacity)
        return true;

    return false;
}



//This member function adds one or more packages to the truck depending on the 
//client's inputted data. This function takes an integer as an arugment and
//returns an integer to represent the total number of packages.
int truck::add_package(int to_add)
{
    //Checks that the inputted data is valid and that its addition does not
    //result in being greater than the capacity, resulting in a failure of the
    //operation if either are true.
    if (num_of_packages == capacity || to_add < 0 || 
        to_add + num_of_packages > capacity)
        return -1; //Returns a negative since 0 is valid in this case

    num_of_packages += to_add;

    return num_of_packages; //Returns the total number of packages
}



//This member function removes one or more packages from the truck depending on
//the client's inputted data. This function takes an integer as an argument and
//returns an integer to represent the number of packages left.
int truck::remove_package(int to_remove)
{
    //Checks if the inputted data is valid, whether the number of packages is
    //already zero, or if the resulting subtraction is less than zero, and
    //returns a failure if any are true.
    if (to_remove < 0 || num_of_packages == 0 || 
        num_of_packages - to_remove < 0)
        return -1; //Returns a negative since 0 is valid in this case

    num_of_packages -= to_remove;

    return num_of_packages; //Returns the total number of packages

}




//This member function lets the client input or add truck information of an
//object's number of packages and capacity. It prompts and reads in the truck 
//information. This function takes no arguments and has a void return type.
void truck::input()
{
    address::input(); //Inputs address information
    vehicle::input(); //Inputs vehicle information

    //Loop makes sure the client does not enter too many packages
    do
    {
        cout << "Please enter the number of packages in your truck: ";
        cin >> num_of_packages;
        cin.ignore(100, '\n');

        cout << "Please enter the capacity of your truck: ";
        cin >> capacity;
        cin.ignore(100, '\n');

        //Checks that the number of packages is correct.
        if (num_of_packages < 0 || capacity < 0 || 
            num_of_packages > capacity)
        {
            cout << "Sorry, this is an invalid entry. Try again..."
                 << endl << endl;
        }

    } while (num_of_packages < 0 || capacity < 0 || num_of_packages > capacity);

    return;

}



//This constant member function displays the truck data to the client. This
//function takes no arguments and has a void return type.
void truck::display() const
{
    address::display(); //Display's address information
    vehicle::display(); //Display's vehicle information

    //If data members is valid, truck's information gets displayed.
    if (capacity != 0)
    {
        cout << "Number of packages: " << num_of_packages << endl;
        cout << "Truck's package capacity: " << capacity << endl;
    }

    return;
}

// -----------------------------------------------------------------------------

