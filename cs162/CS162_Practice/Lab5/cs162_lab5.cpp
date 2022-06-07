//Connor Williams
//CS 162 Lab
//This program is to work with structures and keeping information about a
//student and their course that they are taking.

#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>
using namespace std;

//Constants
const int NAME = 31;
const int COURSE = 10;
const int NUM = 4;

//Place your structure definition here (globally):
struct name
{
    char first[NAME];
    char m_initial;
    char last[NAME];
};

struct course
{
    int crn;
    char course[COURSE];
    char section[NUM];
};


//Place any prototypes that use the structure here:
void read_name(name & a_name);
void read_course(course & a_course);
void display(course & a_course);
void write_out(name & a_name, course & a_course);
void catalog_course(course course_list[]);
int read_one_course(course course_list[], int num);


int main()
{
     //Create a variable of the struct here:
     name student;
     //course course;
     course course_list[COURSE];
     int number = 0;

     //Call the functions here:
     //read_name(student);
     //read_course(course);
     number = read_one_course(course_list, number);
     catalog_course(course_list);
     //display(student, course);
     //write_out(student, course);

     return 0;
}

//Implement the body of the functions here:

void catalog_course(course course_list[])
{


    for (int i = 0; i < COURSE; ++i)
    {
        display(course_list[i]);
    }

}

void write_out(name & a_name, course & a_course)
{
    ofstream file_out;
    file_out.open("Schedule.txt", ios::app);

    if (!file_out)
      file_out << "ERROR ERROR ERROR" << endl;
    else
    {
      file_out << a_name.first << '\t' << a_name.m_initial << '\t' 
               << a_name.last << '\n';
      file_out << a_course.crn << '\t' << a_course.course << '\t' 
               << a_course.section << '\n' << endl;
    }

    file_out.close();
}

void display(course & a_course)
{
    cout << a_course.crn << '\t' << a_course.course << '\t' << a_course.section
         << endl;
}


//Function reads in the students name
void read_name(name & a_name)
{
    cout << "First name: ";
    cin.width(NAME);
    cin >> a_name.first;
    cin.ignore(100, '\n');

    cout << "Middle initial: ";
    cin >> a_name.m_initial;
    cin.ignore(100, '\n');

    cout << "Last name: ";
    cin.width(NAME);
    cin >> a_name.last;
    cin.ignore(100, '\n');
}

//Function counts course list
int read_one_course(course course_list[], int num)
{
    for (int i = 0; i < COURSE; ++i)
      read_course(course_list[i]);
    return num;
}

//Function reads in the course info
void read_course(course & a_course)
{
    cout << "CRN: ";
    cin >> a_course.crn;
    cin.ignore(100, '\n');

    cout << "Course: ";
    cin.width(COURSE);
    cin >> a_course.course;
    cin.ignore(100, '\n');

    cout << "Section: ";
    cin.width(NUM);
    cin >> a_course.section;
    cin.ignore(100, '\n');
}


