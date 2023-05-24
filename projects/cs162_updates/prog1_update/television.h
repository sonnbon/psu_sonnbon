#include <iostream>
#include <cctype>
#include <cstring>

// ****************************************************************************
// Author: Connor Baron-Williams
// Program: CS162 Program 1 Updated in August 2022
// Filename: television.h
// ****************************************************************************
// This file holds the class definitions for slot, show, and commercial, all of
// which are meant to be used to hold television show and commercial
// information for one given time slot on a telelvision program. The slot class
// is a parent to the show class and represents the time slot itself. It
// contains a dynamic array of commericials, to be the number of commercials in
// a time slot. The commercial class holds information about a commercial. The
// show class holds information about a television show.
// ****************************************************************************



class commercial
{
    public:
        void read();
        int change_length();
        void display();

    private:
        int length;
        char * name;
        char * c_info;
};

class slot
{
    public:
        void read();
        int change_length();
        int add_commercial();
        void display();

    protected:
        int length;
        int num_of_com;
        commercial * commercials;
};

class show: public slot
{
    public:
        void read();
        int change_length();
        bool change_title();

    private:
        int length;
        char * name;
        char * genre;
};
