#include "Baron-Williams_node.h"

// *****************************************************************************
// Program 1
// Author: Connor Baron-Williams
// Due Date: January 26, 2022
// Course: CS202 Programming Systems
// Filename: Baron-Williams_node.cpp
// *****************************************************************************
// This file contains the implementation of the member functions in the 
// 'a_node', 'd_node', 's_node classes, all with the purpose to create a node
// container of the objects of the class types they derive from (action, defend,
// and spell class, respectively). These member function jobs allow for the 
// management of one node object to be used in data structures containing cards
// in a card game. The member functions in each node type manage traversal to 
// the next node, of the same type, that it may or may not be connected to and 
// whether the next pointer data member is pointing to another node. 
// *****************************************************************************



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~ A C T I O N _ N O D E ~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//This default constructor sets its data member to its zero equivalent value in
//an initialization list. It takes no arguments and returns nothing.
a_node::a_node(): next(NULL)
{}



//This constructor copies another object to its class' object and sets this
//class' data member to its zero equivalent value in an initialization list. It 
//takes a constant 'action' object passed in as an argument and returns nothing.
a_node::a_node(const action & from): action(from), next(NULL)
{}



//This copy constructor copies an object of the same type. It takes a constant
//'a_node' object passed in as an argument and returns nothing.
a_node::a_node(const a_node & from): action(from)
{
  //This next pointer gets the value of the passed in object's next pointer.
  next = from.next;
}



//This member function reference returns the pointer pointing to the next node
//as a pointer to the 'a_node' type. It takes no arguments.
a_node * & a_node::go_next()
{
  return next;
}



//This constant member function checks if the next node it NULL. It takes no
//arguments and returns a bool value.
bool a_node::has_next() const
{
  //Check if next pointer is not NULL.
  if (next)
    return true;

  return false; //The next pointer is NULL
}



//This member function sets the next node. It takes a pointer to an 'a_node'
//class type and has a void return type.
void a_node::set_next(a_node * src)
{
  //Check if the passed in pointer is NULL.
  if (!src)
    next = NULL;

  //Set the data member to equal the passed in pointer.
  else
    next = src;

  return;
}



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~ D E F E N D _ N O D E ~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//This default constructor sets its data member to its zero equivalent value in
//an initialization list. It takes no arguments and returns nothing.
d_node::d_node(): next(NULL)
{}



//This constructor copies another object to its class' object and sets this
//class' data member to its zero equivalent value in an initialization list. It 
//takes a constant 'defend' object passed in as an argument and returns nothing.
d_node::d_node(const defend & from): defend(from), next(NULL)
{}



//This copy constructor copies an object of the same type. It takes a constant
//'d_node' object passed in as an argument and returns nothing.
d_node::d_node(const d_node & from): defend(from)
{
  //This next pointer gets the value of the passed in object's next pointer.
  next = from.next;
}



//This member function reference returns the pointer pointing to the next node
//as a pointer to the 'd_node' type. It takes no arguments.
d_node * & d_node::go_next()
{
  return next;
}



//This constant member function checks if the next node it NULL. It takes no
//arguments and returns a bool value.
bool d_node::has_next() const
{
  //Check if next pointer is not NULL.
  if (next)
    return true;

  return false; //The next pointer is NULL
}



//This member function sets the next node. It takes a pointer to an 'd_node'
//class type and has a void return type.
void d_node::set_next(d_node * src)
{
  //Check if the passed in pointer is NULL.
  if (!src)
    next = NULL;

  //Set the data member to equal the passed in pointer.
  else
    next = src;

  return;
}


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~ S P E L L _ N O D E ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//This default constructor sets its data member to its zero equivalent value in
//an initialization list. It takes no arguments and returns nothing.
s_node::s_node(): next(NULL)
{}



//This constructor copies another object to its class' object and sets this
//class' data member to its zero equivalent value in an initialization list. It 
//takes a constant 'spell' object passed in as an argument and returns nothing.
s_node::s_node(const spell & from): spell(from), next(NULL)
{}



//This copy constructor copies an object of the same type. It takes a constant
//'s_node' object passed in as an argument and returns nothing.
s_node::s_node(const s_node & from): spell(from)
{
  //This next pointer gets the value of the passed in object's next pointer.
  next = from.next;
}



//This member function reference returns the pointer pointing to the next node
//as a pointer to the 's_node' type. It takes no arguments.
s_node * & s_node::go_next()
{
  return next;
}



//This constant member function checks if the next node it NULL. It takes no
//arguments and returns a bool value.
bool s_node::has_next() const
{
  //Check if next pointer is not NULL.
  if (next)
    return true;

  return false; //The next pointer is NULL
}



//This member function sets the next node. It takes a pointer to an 's_node'
//class type and has a void return type.
void s_node::set_next(s_node * src)
{
  //Check if the passed in pointer is NULL.
  if (!src)
    next = NULL;

  //Set the data member to equal the passed in pointer.
  else
    next = src;

  return;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
