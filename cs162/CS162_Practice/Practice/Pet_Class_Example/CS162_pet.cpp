#include "CS162_pet.h"
using namespace std;

//  Connor Williams
//  CS 162 - Lecture on classes
//  This file is where we implement the member functions for the pet class
/*
        char name[NAME];
        char breed[BREED];
*/

//Each function name starts with the CLASS NAME and the SCOPE RESOLUTION
//OPERATOR

//constructor - initialize the data members to their zero
pet::pet() 
{
    name[0] = '\0';
    breed[0] = '\0';

}

//destructor - reset the data members back to their zero 
pet::~pet() 
{
    for (int i = 0; i < NAME; ++i)
        name[i] = '\0';
    for (int i = 0; i < BREED; ++i)
        breed[i] = '\0';
}

//read in a pet's info
void pet::input() 
{
    cout << "Please enter the pet name: ";
    cin.get(name, NAME, '\n');
    cin.ignore(100, '\n');

    cout << "What is the breed: ";
    cin.get(breed, BREED, '\n');
    cin.ignore(100, '\n');
}

//display a pet's info
void pet::display() 
{
    cout << "Name: " << name << " \t" << "Breed: " << breed << endl;
}

//save to an external data file
void pet::save()
{
    ofstream output_pet;  //This will be bound to the petinfo.txt file
    output_pet.open("petinfo.txt", ios::app);
    if (output_pet)   //if true, we were success at opening up the file
    {
        output_pet << name << '|' << breed << endl;
    }
}

