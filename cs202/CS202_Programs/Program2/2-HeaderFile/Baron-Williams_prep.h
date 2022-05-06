#include <iostream>
#include <cstring>
#include <cctype>
#include <string>

// *****************************************************************************
// Program 2
// Author: Connor Baron-Williams
// Due Date: February 4, 2022
// Course: CS202 Programming Systems
// Filename: Baron-Williams_prep.h
// *****************************************************************************
// This file contains the classes 'prep', 'exam', 'demo', and 'future', 
// all with the job of managing a practice concept or question for studying
// purposes. The 'prep' class contains and manages information that the 
// latter three classes all have in common and acts as an Abstract Base Class
// (ABC). The latter three classes contain and manage information unique to
// their respective classes. The purpose of this configuration is to manage
// three different preparation methods (written exam prep, proficiency demo 
// prep, and future concepts prep) using a single inheritance hierarchy. The 
// 'prep' class is the ABC of the four classes. The 'exam', 'demo', and 
// 'future' classes all derive from the 'prep' class, inheritting its
// information. The 'exam', 'demo', and 'future' classes specifically 
// manage if a question needs more practice, a function prototype name, and a
// new concept of the future, respectively. The 'prep' class manages a type of
// question, a sample question, and the difficulty rating of that question. 
// Dynamic memory will only be allocated for char types in the 'prep' and 
// 'demo' class.
// *****************************************************************************



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~ C O N S T A N T S ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
const int SIZE = 91; //To be size of temporary arrays
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ C L A S S E S ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
// The 'prep' class manages the data needed to practice or study concepts and
// questions for any reason. The data members contained are a question type,
// stored as a string object, a sample question, stored as a pointer to a char
// type, and a difficulty rating, stored as a float type. This class is 
// considered a base class, or more specifically an ABC, in a single inheritance 
// hierarchy. This ABC uses only pure virtual member functions, not including
// the default constructor, copy constructor, and destructor (just virtual). 
// Only the constructors and destructor are implemented in this ABC. The rest of
// the member functions act as a hub for other derived classes to implement
// them. These functions include marking a question complete, rating the 
// difficulty, editing the question, reading in question information, and 
// displaying question information. The rate_difficulty member function takes
// a float type passed in as an argument to update or change the difficulty 
// rating and the edit_question member function takes a constant pointer to a
// char type to edit a question. The only return types are a bool value for
// marking a question complete and a float value for changing the difficulty
// rating. Lastly, a copy constructor and virtual destructor are provided 
// because dynamic memory is being allocated.
class prep
{
  public:
    prep();                  //Default constructor
    prep(const prep & from); //Copy constructor
    virtual ~prep();         //Virtual Destructor

    //The derived classes must implement these operations.
    virtual bool mark_complete() = 0;                    //Mark complete
    virtual float rate_difficulty(float new_rating) = 0; //Rate difficulty
    virtual void edit_question(const char * new_q) = 0;  //Edit question
    virtual void read() = 0;                             //Read in practice info
    virtual void display() const = 0;                    //Display information

  protected:
    std::string q_type; //To be question type
    char * q_sample;    //To be the sample question
    float rating;       //To be difficulty rating
};



// The 'exam' class manages the data needed to practice or study concepts and
// questions for a written exam. This class inherits the data members from its
// parent class and contains a data member that checks if the user needs more
// practice, stored as a bool type. This class is derived from the 'prep' class.
// This class' functions include marking a question complete, rating the 
// difficulty, editing the question, reading in question information, 
// displaying question information, and marking if a user needs more practice.
// The rate_difficulty member function takes a float type passed in as an 
// argument to update or change the difficulty rating and the edit_question 
// member function takes a constant pointer to a char type to edit a question. 
// Member function return types include bool values for marking a question 
// complete and marking if a user needs more practice, and a float value for 
// changing the difficulty rating. This class does not work with dynamic
// memory so a copy constructor and a destructor are not needed.
class exam: public prep
{
  public:
    exam();                                  //Default constructor
    bool mark_complete();                    //Mark complete
    float rate_difficulty(float new_rating); //Rate difficulty
    void edit_question(const char * new_q);  //Edit question
    void read();                             //Read in exam info
    void display() const;                    //Display information

    //Not self similar to other classes.
    bool needs_practice() const;             //Checks if more practice is needed

  protected:
    bool is_ready; //Checks to see if more practice is needed

};



// The 'demo' class manages the data needed to practice or study concepts and
// questions for a live coding proficiency demo exam. This class inherits the 
// data members from its parent class and contains a data member that holds the
// name of a prototype function to be used to solve the coding question, stored
// as a pointer to a char type. This class is derived from the 'prep' class.
// This class' functions include marking a question complete, rating the 
// difficulty, editing the question, reading in question information, and
// displaying question information. The rate_difficulty member function takes a 
// float type passed in as an argument to update or change the difficulty rating 
// and the edit_question member function takes a constant pointer to a char type 
// to edit a question. Member function return types include a bool value for 
// marking a question complete and a float value for changing the difficulty 
// rating. Lastly, a copy constructor and destructor are provided because 
// dynamic memory is being allocated.
class demo: public prep
{
  public:
    demo();                                  //Default constructor
    demo(const demo & from);                 //Copy constructor
    ~demo();                                 //Destructor
    bool mark_complete();                    //Mark complete
    float rate_difficulty(float new_rating); //Rate difficulty
    void edit_question(const char * new_q);  //Edit question
    void read();                             //Read in proficiency info
    void display() const;                    //Display information

  protected:
    char * prototype; //To be function prototype to practice/solve
};



// The 'future' class manages the data needed to practice or study concepts and
// questions for the future. This class inherits the data members from its 
// parent class and contains a data member that holds the new concept to study,
// stored as a string object. This class is derived from the 'prep' class.
// This class' functions include marking a question complete, rating the 
// difficulty, editing the question, reading in question information, and
// displaying question information. The rate_difficulty member function takes a 
// float type passed in as an argument to update or change the difficulty rating 
// and the edit_question member function takes a constant pointer to a char type 
// to edit a question. Member function return types include a bool value for 
// marking a question complete and a float value for changing the difficulty 
// rating. This class does not work with dynamic memory so a copy constructor 
// and a destructor are not needed.
class future: public prep
{
  public:
    future();                                //Default constructor
    bool mark_complete();                    //Mark complete
    float rate_difficulty(float new_rating); //Rate difficulty
    void edit_question(const char * new_q);  //Edit question
    void read();                             //Read in new concept info
    void display() const;                    //Display information

  protected:
    std::string new_concept; //To be the new concept to study
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
