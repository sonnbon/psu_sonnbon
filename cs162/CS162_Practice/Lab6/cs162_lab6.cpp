//Put your header comments here with your name, class
//and purpose of the program

#include "cs162_course.h"





int main()
{

    //Step #4 - Create an object of the class here:
    course student;
    course courses[5];
    char first[SIZE];
    char last[SIZE];
    bool match = false;
    bool drop = false;
    int CRN = 0;

    //Steps #5-10 - Call the member functions here:
    student.read_name();
    student.read_course();
    student.display();

    for (int i = 0; i < 5; ++i)
    {
        courses[i].read_name();
        courses[i].read_course();
        courses[i].display();
    }
        

    


     

    return 0;
}
