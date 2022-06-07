#include "student.h"
using namespace std;

//Connor Williams - Topic 2 lecture
//Implement the member functions of the student class that manages two array of
//characters dynamically allocated and a float
/* My data members:
        char * name; //dynamically allocated array of characters: full name
        char * id;   //psu id number dynamically allocated
        float grade;
*/
 
student::student() //default constructor, initialize data members to zero
{
    name = NULL;
    id = NULL;
    grade = 0.0;
}



student::~student() //deallocate any dynamic memory and reset data members to 0
{
    if (name)
        delete [] name;  //release the memory for the name
    if (id)
        delete [] id;
    name = id = NULL;    //reset your data members back to where they started
    grade = 0.0;
}



int student::add(char name_toadd[], char id_toadd[], 
                float grade_toadd) //new info to add
{
    if (!name_toadd || !id_toadd) return 0;

    name = new char[strlen(name_toadd) + 1];
    strcpy(name, name_toadd);
    id = new char[strlen(id_toadd) + 1];
    strcpy(id, id_toadd);
    grade = grade_toadd;
    return 1;

}



//add a new student all at once
int student::add(const student & new_student)
{
    return add(new_student.name, new_student.id, new_student.grade);
}


//display a student's members
int student::display()
{
    cout << name << '\t' << id << '\t' << "Grade: " << grade << '%'
         << endl;
    return 1;
}

