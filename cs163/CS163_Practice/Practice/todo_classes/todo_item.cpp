#include "todo_item.h"
using namespace std;

//Connor Williams - Lecture 3
//This file manages the code for a SINGLE todo item

/*
        char * name;
        char * description;
        int priority;
*/

//initialize the data members to their zero equivalent value
todo_item::todo_item()
{
    name = description = NULL;
    priority = 0;
}


//Release all dynamic memory
todo_item::~todo_item()
{
    if (name) 
        delete [] name;
    if (description) 
        delete [] description;
    name = description = NULL;
    priority = 0;
}


//Take the three arguments and allocate the appropriate memory and copy the data
int todo_item::set(char * new_name, char * new_desc, int new_priority)
{
    if (!new_name || !new_desc) return 0; //return a failure if the appropriate
                                          //info is not passed in
    
    if (name) //what if name is point to some memory already?
        delete [] name;
    if (description) //what if there is already a description
        delete [] description;

    name = new char[strlen(new_name) + 1];
    strcpy(name, new_name);

    description = new char[strlen(new_desc) + 1];
    strcpy(description, new_desc);

    priority = new_priority;

    return 1;
}



int todo_item::set(const todo_item & to_add)
{
    //What if the name and description are NULL since they are pointers...
    if (!to_add.name || !to_add.description) return 0;

    //What if the memory for name and description was already set and allocated
    if (name)
        delete [] name;
    if (description)
        delete [] description;

    name = new char[strlen(to_add.name) + 1];
    strcpy(name, to_add.name);
    description = new char[strlen(to_add.description) + 1];
    strcpy(description, to_add.description);
    priority = to_add.priority;

    return 1;
}



bool todo_item::is_matching_priority(int to_check) const
{
    return true;
}



int todo_item::display() const
{
    if (!name || !description) return 0; //error situation

    cout << name << endl << description << "\tPriority: " << priority << endl;
    return 1;
}
