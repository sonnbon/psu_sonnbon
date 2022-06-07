#include "roster.h"
using namespace std;

//Connor Williams - topic 2
//This code is aimed at testing the software created

int main()
{
    char name[21];
    char id[13];
    float grade;
    student object;

    cout << "Please enter a name to add for a student: ";
    cin.get(name, 21, '\n');
    cin.ignore(100, '\n');
    cout << "Please enter an id to add for the student: ";
    cin.width(13);
    cin >> id;
    cin.ignore(100, '\n');
    cout << "Please enter the grade percentage for the student: ";
    cin >> grade;
    cin.ignore(100, '\n');

    object.add(name, id, grade);
    object.display();

    //Test the roster part of the software
    roster students;
    students.add(object);
    students.add(object);
    students.display();

    return 0;
}
