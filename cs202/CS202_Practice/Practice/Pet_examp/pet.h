#include <iostream>


//Exception handling support
struct NO_DATA
{
    int error_flag;
};


//Class that manages one pet
//
class pet
{
    public:
        pet();
        pet(const pet & from);
        ~pet();
        pet & operator=(const pet & from); //Assignment operator overloading
        friend ostream & operator<<(ostream & op1, const pet & op2);
        friend pet operator+(const pet &, const int health);
        friend pet operator+(const int health, const pet &);
        pet & operator+=(const pet &);
        pet & operator+=(const int health);

        friend bool operator<(const pet &, const pet &);
        friend bool operator<(const pet &, const char * name);
        friend bool operator<(const char * name, const pet &);

        friend bool operator<=(const pet &, const pet &);
        friend bool operator<=(const pet &, const char * name);
        friend bool operator<=(const char * name, const pet &);

        friend bool operator>(const pet &, const pet &);
        friend bool operator>(const pet &, const char * name);
        friend bool operator>(const char * name, const pet &);

        friend bool operator>=(const pet &, const pet &);
        friend bool operator>=(const pet &, const char * name);
        friend bool operator>=(const char * name, const pet &);

        friend bool operator==(const pet &, const pet &);
        friend bool operator==(const pet &, const char * name);
        friend bool operator==(const char * name, const pet &);

        friend bool operator!=(const pet &, const pet &);
        friend bool operator!=(const pet &, const char * name);
        friend bool operator!=(const char * name, const pet &);

    protected:
        char * name;
        char * breed;
        int age;
        int health;
};

