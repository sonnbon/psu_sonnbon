#include "Baron-Williams_BST.h"

// *****************************************************************************
// Program 3
// Author: Connor Baron-Williams
// Due Date: February 28, 2022
// Course: CS202 Programming Systems
// Filename: Baron-Williams_BST.cpp
// *****************************************************************************
// This file contains the implementation of the methods in the 'node' and 'BST' 
// classes. The purpose of the methods in the 'node' is to act as a container of
// its inheritted data members and methods from the 'figure_skate' class. The 
// 'node' specific methods will allow a user to go to the left or right 'nodes' 
// and set the left or right 'node'. The purpose of the 'BST' class' methods is 
// to act as a Binary Search Tree (BST) data structure, which inserts, copies, 
// retrieves, displays, and removes 'node' class objects. Only the BST manages
// dynamic memory.
// *****************************************************************************



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~ N O D E _ C L A S S ~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//This default constructor sets all the data members to their zero equivalent
//values. It takes no arguments and has no return type.
node::node(): left(nullptr), right(nullptr)
{}



//This method reference returns a pointer to the left 'node'. It takes no 
//arguments.
node * & node::go_left()
{
  return left;
}



//This method reference returns a pointer to the right 'node'. It takes no 
//arguments.
node * & node::go_right()
{
  return right;
}



//This method sets the left node. It takes a pointer to the 'node' class type 
//and has a void return type.
void node::set_left(node * src)
{
  //Check if the passed in pointer is NULL.
  if (!src)
    left = NULL;

  //Set the data member to equal the passed in pointer.
  else
    left = src;

  return;
}



//This method sets the right node. It takes a pointer to the 'node' class type 
//and has a void return type.
void node::set_right(node * src)
{
  //Check if the passed in pointer is NULL.
  if (!src)
    right = NULL;

  //Set the data member to equal the passed in pointer.
  else
    right = src;

  return;
}



//This member operator overloader specifically assigns just a 'figure_skate' 
//object to this class' object. It takes a constant 'figure_skate' object, 
//passed by reference, as an argument and returns a 'node' object by reference.
node & node::operator=(const figure_skate & game)
{
  //Call parent copy method.
  figure_skate::copy(game);

  return *this;
}



//This operator overloader outputs the current object. It takes an 'ostream'
//object and a constant 'node' object, passed by reference, as arguments and 
//returns an 'ostream' object by reference.
std::ostream & operator<<(std::ostream & out, const node & from)
{
  //Call parent class' method.
  from.display(out);

  return out;
}



//This constant member operator overloader compares whether this class' name is
//less than the passed in name. It takes a constant pointer to a char as an 
//argument and returns a bool value.
bool node::operator<(const char * name) const
{
  //Call ancestor class and return whether this class' name is less than the 
  //passed in name.
  return -1 == compare(name);
}



//This constant member operator overloader compares whether this class' name is
//less than the passed in name. It takes a constant 'figure_skate' object, 
//passed by reference, and returns a bool value.
bool node::operator<(const figure_skate & game) const
{
  //Call ancestor class and return whether this class' name is less than the 
  //passed in object.
  return -1 == compare(game);
}



//This constant member operator overloader compares whether this class' name is
//less than or equal to the passed in name. It takes a constant pointer to a 
//char as an argument and returns a bool value.
bool node::operator<=(const char * name) const
{
  //Call ancestor class and return whether this class' name is less than or 
  //equal to the passed in name.
  return (0 == compare(name) || -1 == compare(name));
}



//This constant member operator overloader compares whether this class' name is
//less than or equal to the passed in name. It takes a constant 'figure_skate' 
//object, passed by reference, and returns a bool value.
bool node::operator<=(const figure_skate & game) const
{
  //Call ancestor class and return whether this class' name is less than or 
  //equal to the passed in name.
  return (0 == compare(game) || -1 == compare(game));
}



//This constant member operator overloader compares whether this class' name is
//greater than the passed in name. It takes a constant pointer to a char as an 
//argument and returns a bool value.
bool node::operator>(const char * name) const
{
  //Call ancestor class and return whether this class' name is greater than the
  //passed in name.
  return 1 == compare(name);
}



//This constant member operator overloader compares whether this class' name is
//greater than the passed in name. It takes a constant 'figure_skate' object, 
//passed by reference, and returns a bool value.
bool node::operator>(const figure_skate & game) const
{
  //Call ancestor class and return whether this class' name is greater than the
  //passed in name.
  return 1 == compare(game);
}



//This constant member operator overloader compares whether this class' name is
//greater than or equal to the passed in name. It takes a constant pointer to a 
//char as an argument and returns a bool value.
bool node::operator>=(const char * name) const
{
  //Call ancestor class and return whether this class' name is greater than or 
  //equal to the passed in name.
  return (0 == compare(name) || 1 == compare(name));
}



//This constant member operator overloader compares whether this class' name is
//greater than or equal to the passed in name. It takes a constant 
//'figure_skate' object, passed by reference, and returns a bool value.
bool node::operator>=(const figure_skate & game) const
{
  //Call ancestor class and return whether this class' name is greater than or 
  //equal to the passed in name.
  return (0 == compare(game) || 1 == compare(game));
}



//This constant member operator overloader compares whether this class' name is
//equal to the passed in name. It takes a constant pointer to a char as an 
//argument and returns a bool value.
bool node::operator==(const char * name) const
{
  //Call ancestor class and return whether this class' name is equal to the
  //passed in name.
  return 0 == compare(name);
}



//This constant member operator overloader compares whether this class' name is
//not equal to the passed in name. It takes a constant pointer to a char as an 
//argument and returns a bool value.
bool node::operator!=(const char * name) const
{
  //Call ancestor class and return whether this class' name is not equal to the
  //passed in name.
  return (!(0 == compare(name)));
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ B S T _ C L A S S ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 
//This default constructor sets its data members to their zero equivalent
//values. It takes no arguments and has no return type.
BST::BST(): root(nullptr)
{}



//This copy constructor copies an object of the same type to this class' data
//members. It takes a constant 'BST' object, passed by reference, as an
//argument and has no return type.
BST::BST(const BST & from)
{
  //Variable definitions
  BAD_INPUT b_input; //Holds any errors to be thrown

  //Check if the passed in data is valid.
  if (!from.root)
  {
    root = nullptr;
    b_input.bad_int = 0;
    throw b_input;
  }

  copy_all(from); //Wrapper function to copy all data
}



//This method acts as a wrapper function to copy an object of the same type to
//this class' data members. It takes a constant 'BST' object, passed by 
//reference, as an argument and has a void return type.
void BST::copy_all(const BST & from)
{
  //Variable definitions
  BAD_INPUT b_input; //Holds any errors to be thrown

  //Check if the passed in data is valid.
  if (!from.root)
  {
    b_input.bad_int = 0;
    throw b_input;
  }

  //Deallocate any memory that might exist in the current object.
  if (root)
    remove_all(); //Wrapper function to delete all data

  copy_all(root, from.root); //Manages copying the array

  return;
}



//This private method uses recursion to copy a list of the same object type to
//the current object. It takes two pointers to the 'node' class type, to be the
//destination (root) and source BST's (root pointer passed by reference), as
//arguments and has a void return type.
void BST::copy_all(node * & root, node * src)
{
  //Check if the list is empty or at the end of the list.
  if (!src)
  {
    root = nullptr;
    return;
  }

  //Allocate a new node and copy the passed in data.
  root = new node;
  root->copy(*src);

  copy_all(root->go_left(), src->go_left());
  copy_all(root->go_right(), src->go_right());

  return;
}



//This destructor deallocates any memory in the BST and sets all data members to 
//their zero equivalent values. It takes no arguments and has no return type.
BST::~BST()
{
  //Check that there is memory allocated before calling the 'remove_all' method.
  if (root)
    remove_all();
}



//This method acts as a wrapper function to deallocate any memory in the BST and 
//sets all data members to their zero equivalent values. It takes no arguments 
//and returns an integer type, to be the number of items deleted.
int BST::remove_all()
{
  //Check that there is memory allocated before calling the 'remove_all' private
  //method.
  if (root)
    return remove_all(root); //Returns number of athletes removed

  return 0; //Returns a failure of operation
}



//This private method deallocates any memory in the BST and sets it to NULL. It 
//takes a pointer to a 'node' class type, passed by reference, as an argument 
//and returns an integer type, to be the number of items deleted.
int BST::remove_all(node * & root)
{
  //Variable definitions
  int count {0}; //Number of athletes removed

  //Check when the list has been completely removed.
  if (!root)
    return 0;

  count += remove_all(root->go_left());
  count += remove_all(root->go_right());

  delete root;
  root = nullptr;

  ++count;

  return count;
}



//This method acts as a wrapper function to remove an object of the 
//'figure_skate' class. It takes a constant pointer to a char, to be the name to 
//look for, as an argument and returns a bool value.
bool BST::remove(const char * name)
{
  //Variable definitions
  BAD_INPUT b_input; //Holds any errors to be thrown

  //Check passed in data or the current object is valid.
  if (!root || !name)
  {
    b_input.bad_array = "bad";
    throw b_input;
  }

  return remove(root, name); //Returns success or failure of removal
}



//This private method removes an object of the 'figure_skate' class. It takes a
//pointer to the 'node' class type, passed by reference, and a constant pointer 
//to a char, to be the name of the athlete, as arguments and returns a bool 
//value.
bool BST::remove(node * & root, const char * name)
{
  //Variable definitions
  bool removed {false}; //Holds whether match is found

  //Check if the end of the list has been reached.
  if (!root)
    return false; //Returns a failure of the operation

  //Check if the dereferenced root's name is equal to the passed in data.
  if (*root == name)
  {
    removed = true;

    //Check if the matched node is a leaf.
    if (!root->go_left() && !root->go_right())
    {
      delete root;
      root = nullptr;
    }

    //Check if there is only a left child.
    else if (!root->go_right())
    {
      node * hold = root->go_left();
      delete root;
      root = hold;
    }

    //Check if there is only a right child.
    else if (!root->go_left())
    {
      node * hold = root->go_right();
      delete root;
      root = hold;
    }

    //Otherwise there are two children and an inorder successor must be found.
    else
    {
      node * hold = root->go_right();

      //Check if there is no left child.
      if (!hold->go_left())
      {
        root->copy(*hold);        
        root->set_right(hold->go_right());
        delete hold;
      }

      //Otherwise traverse all the way left from the held 'node'.
      else
      {
        //removed = remove_IOS(root, hold);
        node * prev = hold;
        while (hold->go_left())
        {
          prev = hold;
          hold = hold->go_left();
        }
        root->copy(*hold);
        prev->set_left(hold->go_right());
        delete hold;
      }
    }

    return removed; //This should return true unless an error occurs
  }

  //If the name is less than the 'nodes' name, go left.
  if (*root >= name)
    return remove(root->go_left(), name);

  //Otherwise, go right.
  return remove(root->go_right(), name);
}



//This method acts as a wrapper function to insert a figure skater into the BST.
//It takes constant 'figure_skate' object, passed by reference, as an argument
//and has a void return type. 
void BST::insert(const figure_skate & from)
{
  //Check if the BST is empty.
  if (!root)
  {
    root = new node;
    *root = from; //Set dereferenced root's data to get passed in data
    return;
  }

  //Otherwise, traverse the list to sort the new athlete.
  insert(root, from);

  return;
}



//This private method inserts a figure skater into the BST, sorted by name. It 
//takes pointer to the 'node' class and a constant 'figure_skate' object, passed 
//by reference, as arguments and has a void return type. 
void BST::insert(node * & root, const figure_skate & from)
{
  //Check if at the end of the BST
  if (!root)
  {
    root = new node;
    *root = from; //Set derefenced root's data to get passed in data
    return;
  }

  //If the object's name is the same, then update the information and return.
  if (*root == from)
  {
    *root = from;
    return;
  }

  //If the object's name is less than the 'nodes', go left.
  if (*root >= from)
    return insert(root->go_left(), from);

  //Otherwise, go right.
  return insert(root->go_right(), from);
}



//This constant method acts as a wrapper function to search for and display 
//whether an athlete is in the BST. It takes a constant pointer to a char, to be
//the name to search for, as an argument and returns a bool value.
bool BST::retrieve(const char * name) const
{
  //Variable defintions
  BAD_INPUT b_input; //Holds an errors to be thrown

  //Check if the passed in data or current object is valid.
  if (!name || !root)
  {
    b_input.bad_array = "bad";
    throw b_input;
  }

  return retrieve(root, name);
}



//This private constant method traverses a BST and searches for and displays an
//athlete. It takes a pointer to the 'node' class and a constant pointer to a 
//char as arguments and returns a bool value.
bool BST::retrieve(node * root, const char * name) const
{
  //Check if at the end of the list.
  if (!root)
    return false; //Returns no match found

  //Check if a match was found, calling a compare function.
  if (*root == name)
  {
    std::cout << *root;
    return true;
  }

  //If the name is less than the 'nodes' name, go left.
  if (*root >= name)
    return retrieve(root->go_left(), name);

  //Otherwise go right.
  return retrieve(root->go_right(), name);
}



//This constant method acts as a wrapper function to display every item in the 
//BST. It takes an 'ostream' object, passed by reference, and returns an 
//integer, to be the number of items displayed.
int BST::display_all(std::ostream & out) const
{
  //Check if the BST is empty.
  if (!root)
    return 0;

  return display_all(out, root); //Returns number of items displayed
}



//This private constant method displays all the contents of a BST alphabetically
//by name. It takes an 'ostream' object, passed by reference, and a  pointer to 
//the 'node' class as an argument and returns an integer, to be the number of 
//items displayed.
int BST::display_all(std::ostream & out, node * root) const
{
  //Variable definitions
  int count {0}; //Number of items displayed

  //Check if at the end of the list
  if (!root)
    return 0;

  //Traverse all the way left first
  count = display_all(out, root->go_left());

  root->display(out);
  ++count;

  //Traverse right at each node on the way back up the stack.
  count += display_all(out, root->go_right());

  return count;
}



//This member operator assigns an object of the same type to this class, 
//copying over all data. It takes a constant 'BST' object, passed by reference,
//as an argument and returns a 'BST' object by reference.
BST & BST::operator=(const BST & old_tree)
{
  //Check for self assignment
  if (this == &old_tree)
    return *this;

  //Copy all data over.
  copy_all(old_tree);

  return *this;
}



//This operator ouputs all the data in a BST. It takes an 'ostream' object and a
//constant 'BST' object, passed by reference, as arguments and returns an
//'ostream' object by reference.
std::ostream & operator<<(std::ostream & out, const BST & tree)
{
  //Variable definitions
  int count = {0}; //Number of items displayed

  //Display all data in the BST.
  count = tree.display_all(out);

  if (count == 1)
    out << "1 athlete displayed";
  else
    out << count << " athletes displayed";

  return out;
}



//This member operator adds one athlete to a BST. It takes a constant 'BST'
//object and a constant 'figure_skate' object, passed by reference, as arguments
//and returns a 'BST' object by value.
BST operator+(const BST & list, const figure_skate & game)
{
  //Variable definitions
  BAD_INPUT b_input; //Holds any errors to be thrown
  BST temp;          //Temporary 'BST' object

  //Check that the passed in athlete is valid.
  if (game.is_empty())
  {
    b_input.bad_array = "bad";
    throw b_input;
  }

  //Check if the passed in list has any data.
  if (list.root)
    temp.copy_all(list);
  
  temp += game; //Add passed in figure skater to temporary list

  return temp;
}



//This member operator adds one athlete to a BST. It takes a constant 'BST'
//object and a constant 'figure_skate' object, passed by reference, as arguments
//and returns a 'BST' object by value.
BST operator+(const figure_skate & game, const BST & list)
{
  //Variable definitions
  BAD_INPUT b_input; //Holds any errors to be thrown
  BST temp;          //Temporary 'BST' object

  //Check that the passed in athlete is valid.
  if (game.is_empty())
  {
    b_input.bad_array = "bad";
    throw b_input;
  }

  //Check if the passed in list has any data.
  if (list.root)
    temp.copy_all(list);
  
  temp += game; //Add passed in figure skater to temporary list

  return temp;
}



//This member operator adds one athlete to the BST. It takes a constant 
//'figure_skate' object, passed by reference, as an argument and returns a 'BST'
//object by reference.
BST & BST::operator+=(const figure_skate & game)
{
  //Variable definitions
  BAD_INPUT b_input; //Holds any errors to be thrown

  //Check that the passed in athlete is valid.
  if (game.is_empty())
  {
    b_input.bad_array = "bad";
    throw b_input;
  }

  //Insert the object into the BST.
  insert(game);

  return *this;
}



//This member operator removes one athlete to a BST. It takes a constant 'BST'
//object, passed by reference, and a constant pointer to a char as arguments and
//returns a 'BST' object by value.
BST operator-(const BST & list, const char * name)
{
  //Variable definitions
  BST temp(list);    //Temporary holds passed in 'BST'

  temp -= name; //Remove passed in name from temporary list

  return temp;
}



//This member operator removes one athlete to a BST. It takes a constant 'BST'
//object, passed by reference, and a constant pointer to a char as arguments and
//returns a 'BST' object by value.
BST operator-(const char * name, const BST & list)
{
  //Variable definitions
  BST temp(list); //Temporary holds passed in 'BST'

  temp -= name; //Remove passed in name from temporary list

  return temp;
}



//This member operator subtracts one athlete from the BST. It takes a constant
//pointer to a char as an argument and returns a 'BST' object by reference.
BST & BST::operator-=(const char * name)
{
  //Variable definitions
  BAD_INPUT b_input; //Holds any errors to be thrown

  if (!strcmp(name, "ALL ATHLETES"))
  {
    int count = remove_all();
    
    if (count == 1)
      std::cout << count << " athlete removed" << std::endl << std::endl;
    else
      std::cout << count << " athletes removed" << std::endl << std::endl;
  }

  //Check for a successful removal.
  else 
  {
    if (!remove(name))
    {
      b_input.bad_array = "bad";
      throw b_input;
    }
  }

  return *this;
}



//This constant member operator checks for a name match within the BST and 
//displays a match. It takes a cosntant pointer to a char as an argument and 
//returns a bool value.
bool BST::operator==(const char * name) const
{
  //Returns whether a match was found.
  return retrieve(name);
}



//This constant member operator checks that a name does not match within the 
//BST. It takes a cosntant pointer to a char as an argument and returns a bool 
//value.
bool BST::operator!=(const char * name) const
{
  //Returns whether a match was not found.
  return (!retrieve(name));
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

