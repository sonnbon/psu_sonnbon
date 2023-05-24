// *****************************************************************************
// Program 3
// Author: Connor Baron-Williams
// Due Date: February 28, 2022
// Course: CS202 Programming Systems
// Filename: Baron-Williams_error.h
// *****************************************************************************
// This file manages a structure for the purposes of error exception handling. 
// It contains the structure 'BAD_INPUT', which has the job of managing a char,
// integer, and string object that will be assigned to a user's incorrect input
// and/or response in the program.
// *****************************************************************************



//This structure manages a char, integer, and string object, to be input and 
//response errors entered by the user.
struct BAD_INPUT
{
  char bad_char;         //Bad character assigned
  int bad_int;           //Bad integer assigned
  std::string bad_array; //Bad string assigned
};



