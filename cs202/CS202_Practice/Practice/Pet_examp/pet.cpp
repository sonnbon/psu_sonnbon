#include "pet.h"

//assignment operator
pet & pet::operator=(const pet & op2)
{
    if (this == &op2) //Check if we are pointing to the same place
        return *this;

    if (name)
        delete [] name;

    if (breed)
        delete [] breed;

    name = new char[strlen(op2.name) + 1];
    strcpy(name, op2.name);

    breed = new char[strlen(op2.breed) + 1];
    strcpy(breed, op2.breed);

    age = op2.age;

    return *this;
}


//Insertion operator
ostream & operator<<(ostream & op1, const pet & op2) //op1 is a bad name. maybe use output?
{
    //if (!op2.name || !op2.breed) throw No_Data;

    op1 << op2.name << '\t' << op2.breed << '\t' << "Age: " << op2.age;

    return op1;
}

//The + operator
pet operator+(const pet & op1, const int health)
{
    pet temp = *this;
    
    temp.health = op1.health + health;

    return temp;
}


pet operator+(const int health, const pet & op1)
{
    pet temp = *this;
    
    temp.health = health + op1.health;

    return temp;
}


//The += operator
pet & pet::operator+=(const pet & op2)
{
    health += op2.health;

    return *this;
}

pet & pet::operator+=(const int add_health)
{
    health += add_health;

    return *this;
}


bool operator<(const pet & op1, const pet & op2)
{
    return strcmp(op1.name, op2.name) < 0;
}

bool operator<(const pet &, const char * name)
{
    //because we are friends we have access to op1's name
    return strcmp(op1.name, name) < 0;
}

bool operator<(const char * name, const pet & op2);
{
    return strcmp(name, op2.name) < 0;
}

bool operator<=(const pet & op1, const pet & op2)
{
    return strcmp(op1.name, op2.name) <= 0;
}

bool operator<=(const pet &, const char * name)
{
    //because we are friends we have access to op1's name
    return strcmp(op1.name, name) <= 0;
}

bool operator<=(const char * name, const pet & op2);
{
    return strcmp(name, op2.name) <= 0;
}

bool operator>(const pet & op1, const pet & op2)
{
    return strcmp(op1.name, op2.name) > 0;
}

bool operator>(const pet &, const char * name)
{
    //because we are friends we have access to op1's name
    return strcmp(op1.name, name) > 0;
}

bool operator>(const char * name, const pet & op2);
{
    return strcmp(name, op2.name) > 0;
}

bool operator>=(const pet & op1, const pet & op2)
{
    return strcmp(op1.name, op2.name) >= 0;
}

bool operator>=(const pet &, const char * name)
{
    //because we are friends we have access to op1's name
    return strcmp(op1.name, name) >= 0;
}

bool operator>=(const char * name, const pet & op2);
{
    return strcmp(name, op2.name) >= 0;
}

bool operator==(const pet & op1, const pet & op2)
{
    return strcmp(op1.name, op2.name) == 0;
}

bool operator==(const pet &, const char * name)
{
    //because we are friends we have access to op1's name
    return strcmp(op1.name, name) == 0;
}

bool operator==(const char * name, const pet & op2);
{
    return strcmp(name, op2.name) == 0;
}

bool operator!=(const pet & op1, const pet & op2)
{
    return strcmp(op1.name, op2.name) != 0;
}

bool operator!=(const pet &, const char * name)
{
    //because we are friends we have access to op1's name
    return strcmp(op1.name, name) != 0;
}

bool operator!=(const char * name, const pet & op2);
{
    return strcmp(name, op2.name) != 0;
}

