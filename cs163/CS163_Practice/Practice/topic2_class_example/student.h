#include <iostream>
#include <cctype>
#include <cstring>

//Connor Williams - Topic 2 lecture
//This code will manage a studen class which will allow applications to create
//a student, add a new studen, display a student, etc.

//Constants
//Prototypes
//Class interfaces
class student
{
    public:
        student(); //default constructor, initialize data members to zero
        ~student();//deallocate any dynamic memory and reset data members to 0
        int add(char name[], char id[], float grade); //new info to add
        int add(const student & new_student); //add an entire student all at once
        int display();

    private:
        char * name; //dynamically allocated array of characters: full name
        char * id;   //psu id number dynamically allocated
        float grade;
};
