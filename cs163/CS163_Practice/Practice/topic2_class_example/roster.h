#include "student.h"

//Connor Williams - topic 2
//The purpose is to create a collection or roster of students
//We can then add, drop, display, advise, etc.

struct node
{
    student a_student;
    node * next;
};


class roster
{
    public:
        roster();  //constructor
        ~roster(); //destructor
        int add (const student & new_student);
        int display(); //display the entire roster

    private:
        node * head;
        node * tail;
};
