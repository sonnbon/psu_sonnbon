#include "roster.h"

//Connor Williams - topic 2
//Implement the member functions for a collection of students called a roster
//with a linear linked list where there is both a head and a tail pointer. This
//means all of the code needs to manage both of those pointers.

/* 
   Here is the node's members:

    student a_student;
    node * next;
*/

//Default constructor
roster::roster()  
{
    head = tail = NULL;  //make sure to set your DATA members;
}


//Destructure
roster::~roster()
{
    //deallocate all dynamic memory; loop through all and delete everything
    node * temp = NULL;
    while (head)
    {
        temp = head->next; //NEVER access memory that is deallocated
        delete head;
        head = temp;
    }
    tail = NULL;
}


//Pass in a student to be added to a roster
int roster::add (const student & new_student)
{
    node * temp = new node;
    if (!temp) return 0;
    temp->a_student.add(new_student);
    temp->next = NULL;

    //place this new node in the right spot
    if (!head)  //simple case
        head = tail = temp;
    else
    {
        tail->next = temp;
        tail = tail->next;
    }
    return 1;
}
int roster::display() //display the entire roster
{
    if (!head) return 0; //nothing to display
    node * current = head;
    while (current)
    {
        current->a_student.display();
        current = current->next;
    }
    return 1;
}

