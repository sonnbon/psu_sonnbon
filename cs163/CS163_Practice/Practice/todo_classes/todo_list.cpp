#include "todo_list.h"

//Connor Williams
//This is to show the implementation of one of the list class functions

//For demonstration:
//First using a struct for the underlying data
int todo_list::insert(char * name, char * description, int priority)
{
    if (!name || !description) //major problem - nothing to copy from
        return 0;

    if (!head)
    {
        head = new node; //very first node
        head->next = NULL;
        head->data.name = new char[strlen(name) + 1];
        strcpy(head->data.name, name);
        head->data.description = new char[strlen(description) + 1];
        strcpy(head->data.description, description);
        head->data.priority = priority;
    }
    else {}
    return 1;

}


//Next demonstrating using the class for the underlying data
int todo_list::insert(char * name, char * description, int priority)
{
    node * temp = new node;
    if (!temp->data.set(name, description, priority))
    {
        delete temp;
        return 0; //erroneous - can't proceed
    }

    //MY JOB IS TO MANAGE THE DATA STRUCTURE
    if (!head)
    {
        head = temp;
        head->next = NULL;
    }
}


