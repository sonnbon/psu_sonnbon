#include "Baron-Williams_pile.h"

// *****************************************************************************
// Program 1
// Author: Connor Baron-Williams
// Due Date: January 26, 2022
// Course: CS202 Programming Systems
// Filename: Baron-Williams_pile.cpp
// *****************************************************************************
// This file contains the implementation of the member functions in the 'pile',
// 'a_deck', 'd_deck', 's_deck', 'a_hand', 'd_hand', and 's_hand' classes. The
// purpose of the member functions in the 'pile' class are to set the size of
// a card pile, check whether a pile is full or empty, and display how many
// cards are left. The purpose of the remaining class' member functions is to 
// act as an appropriate data structure, which inserts, copies, retrieves, 
// displays, and removes data. The 'a_deck', 'd_deck', and 's_deck', all derived
// from the 'pile' base class, use these member functions to manage a Circular
// Linked List of their respective cards (action, defend, and spell,
// respectively). The 'a_hand', 'd_hand', and 's_hand', all derived from the
// 'pile' base class, use these member functions to manage an Array of Linear
// Linked Lists of their respective cards (action, defend, and spell, 
// respectively). The Array of Linear Linked Lists has a more complicated
// purpose of managing one player's "cards to be played" (index 0), another
// player's "cards to be played" (index 1), the first player's "played cards"
// (index 2), the second player's "played cards" (index 3), and all the cards
// used, or discard pile (index 4).
// *****************************************************************************



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ P I L E ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//This default constructor sets the data members to their zero equivalent value
//using an initialization list. It takes no arguments and returns nothing.
pile::pile(): max_size(0), num_of_cards(0)
{}



//This constructor sets the size of a pile with passed in information but the
//number of cards is still still to zero. It takes an integer type, to be the 
//max size, as an argument and returns nothing.
pile::pile(int size)
{
  //Check that the passed in integer is positive. If not, convert it to a
  //positive number, even if the passed in value is zero.
  if (size < 0)
    max_size = (-1 * size);
  else
    max_size = size;

  num_of_cards = 0;
}



//This constant member function checks if the pile is full. It takes no
//arguments and returns a bool value.
bool pile::is_full() const
{
  //Check if the number of cards equals the max size of the pile.
  if (num_of_cards == max_size)
    return true;

  return false; //The pile is not full.
}



//This constant member function checks if the pile is empty. It takes no
//arguments and returns a bool value.
bool pile::is_empty() const
{
  //Check if the pile has any cards or if the max size is greater than zero.
  if (num_of_cards == 0 || max_size == 0)
    return true;

  return false; //The pile is not empty
}



//This constant member function displays the number of cards left in a pile. It
//is using namespace std, takes no arguments, and has a void return type.
void pile::cards_left() const
{
  using namespace std;

  //Check if the pile is full or empty before displaying the number of cards
  //left.
  if (is_full())
  {
    cout << "This pile of cards is full! There are " << num_of_cards << " left."
         << endl << endl;
  }
  else if (is_empty())
  {
    cout << "This pile is empty! There are no cards left." 
         << endl << endl;
  }
  else
  {
    cout << "There are " << num_of_cards << " cards left in this pile."
         << endl << endl;
  }

  return;
}



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~ A C T I O N _ D E C K ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//This default constructor sets the data member to its zero equivalent value
//with an initialization list. It takes no arguments and returns nothing.
a_deck::a_deck(): rear(NULL)
{}



//This constructor sets the data member to its zero equivalent value but also 
//sets the max size of the deck in an intialization list. It takes an integer 
//type, to be the max size, passed in as an argument and returns nothing.
a_deck::a_deck(int size): pile(size), rear(NULL)
{}



//This copy constructor copies an 'a_deck' object to this object by calling the
//copy all member function. It takes a constant 'a_deck' object as an argument 
//and returns nothing.
a_deck::a_deck(const a_deck & from): pile(from)
{
  //Check if passed in data member is not NULL. Otherwise, set number of cards
  //to zero.
  if (from.rear)
    num_of_cards = copy_all(from);
  else
  {
    rear = NULL;
    num_of_cards = 0;
  }
}



//This member function acts as a wrapper function to copying one deck to this
//deck class. It takes a constant 'a_deck' object passed in as an argument and
//returns an integer type, to be the number of cards in the deck.
int a_deck::copy_all(const a_deck & from)
{
  //Deallocate any memory of an existing list if it exists.
  if (rear)
    remove_all();

  //Check if the passed in data member is NULL.
  if (!from.rear)
  {
    rear = NULL;
    return 0; //Returns a failure of the operation
  }

  rear = new a_node(*from.rear); //Allocate memory and copy to rear

  //Check if there is only one node from the passed in data member.
  if (from.rear == from.rear->go_next())
  {
    rear->set_next(rear);
    return 1;
  }

  a_node * hold = rear; //To hold the real rear pointer

  //Calls the recursive function to copy the rest
  return copy_all(hold, rear->go_next(), from.rear, from.rear->go_next());
}



//This private member function copies one deck to this deck class,
//recursively. It takes four pointers to 'a_node' class types as arguments, 
//one of which is passed by reference to copy information to it. The other three 
//pointers represent the rear and front of the source list that the function is 
//copying from and a hold of the real new rear pointer. It returns an integer 
//type to be the number of cards in the deck.
int a_deck::copy_all(a_node * hold, a_node * & rear, a_node * src_rear, 
                     a_node * src_front)
{
  //Variable defintions
  int count = 0; //To be number of cards copied

  //Check if the front and rear pointer to copy from are the same. If they are
  //the function has completed its traversal.
  if (src_front == src_rear)
    return 1;
  
  rear = new a_node(*src_front); //Allocate new node and copy current data
  
  //Returns 1 plus the return value of the next node.
  count = 1 + copy_all(hold, rear->go_next(), src_rear, src_front->go_next());

  if (src_front->go_next() == src_rear)
    rear->set_next(hold); //Set rear's next pointer to the real rear

  return count; //Return the number of cards copied
}



//This destructor deallocates any memory and sets the data member to its zero
//equivalent value by calling the remove all member function. It takes no
//arguments and returns nothing.
a_deck::~a_deck()
{
  //Check if the data member is not NULL before deallocating the memory.
  if (rear)
    remove_all();
}



//This member function acts a wrapper function to remove all the nodes in this
//class's deck. It takes no arguments and has a void return type.
void a_deck::remove_all()
{
  //Check if the data member is NULL before deallocating the memory.
  if (!rear)
    return;

  //Check if there is only one node in the list.
  if (rear == rear->go_next())
  {
    delete rear;
    rear = NULL;
    return;
  }

  remove_all(rear->go_next()); //Remove the rest recursively

  delete rear; //Deallocate the last node after the recursive call
  rear = NULL;
  return;
}



//This private member function removes all the nodes in this class' deck,
//recursively. It takes a pointer to an 'a_node' class type as an argument and 
//has a void return type.
void a_deck::remove_all(a_node * & rear)
{
  //Check if there is only one node left before deallocating memory.
  if (rear == this->rear)
    return;

  a_node * hold = rear->go_next(); //Hold rear's next pointer
  delete rear;
  rear = hold;                     //Set near rear, moving forward one node
    
  return remove_all(rear); //Go to the next node.
}



//This member function inserts a card into the deck. It takes a constant
//'action' object as an argument and returns an integer type, to be the new
//number of cards.
int a_deck::insert(const action & from)
{
  //Check if the deck is already full.
  if (is_full())
    return num_of_cards; //Returns existing number of cards

  a_node * temp = new a_node; //Set pointer to a new allocated node

  //Check that card gets added to node.
  if(temp->copy(from))
  {
    //Check if the list is empty.
    if (!rear)
    {
      rear = temp;          //Set rear to be the new allocated node
      rear->set_next(rear); //Have the node point to itself
    }

    //Otherwise, insert the new node into the front of the list.
    else
    {
      a_node * hold = rear->go_next(); //Pointer gets the value of the next node
      temp->set_next(hold);            //New node points to old front of the list
      rear->set_next(temp);            //Rear points to the new node (new front)
    }
   
    ++num_of_cards;
  }

  //The card did not get added. Remove newly allocated node.
  else
  {
    delete temp;
    temp = NULL;
  }

  return num_of_cards; //Returns the new number of cards
}



//This constant member function acts as a wrapper function to check for an exact
//match in the deck. It takes a constant 'action' object passed in as an 
//argument and returns a bool value.
bool a_deck::retrieve(const action & from) const              
{
  //Check if the list is empty.
  if (!rear)
    return false; //Returns no match found

  //Check if it is a one node list
  if (rear == rear->go_next())
  {
    //Compare the data for a match
    if (rear->compare(from))
      return true;

    return false; //Returns no match found
  }

  return retrieve(rear->go_next(), from); //Returns if match was found
}



//This constant member function checks for an exact match in the deck. It takes
//a pointer to an 'a_node' class type and a constant 'action' object passed
//in as arguments and returns a bool value.
bool a_deck::retrieve(a_node * rear, const action & from) const
{
  //Variable definitions
  bool is_match = false; //To flag whether a match was found

  //Check if the rear and this pointers are equal to each other, indicating a 
  //full traversal of the list.
  if (rear == this->rear)
  {
    //Check if a match is found calling the node's parent member function.
    if (rear->compare(from))
      is_match = true;

    return is_match; //Returns whether a match was found
  }

  //Check if a match is found calling the node's parent member function.
  if (rear->compare(from))
    return true;

  return retrieve(rear->go_next(), from); //Returns if there's a match
}



//This member function removes the current node in this class. It takes no 
//arguments and returns a bool value.
bool a_deck::remove()
{
  //Check if the list is empty.
  if (!rear)
    return false; //Nothing was removed

  //Check if it is a one node list.
  if (rear == rear->go_next())
  {
    delete rear;
    rear = NULL;
  }

  //The list has more than one node in it.
  else
  {
    a_node * hold = rear->go_next();
    hold = hold->go_next();
    delete rear->go_next();
    rear->go_next() = hold;
  }

  return true; //The current node was deleted
}



//This constant member function displays the contents of the current node. It
//takes no arguments and has a void return type.
void a_deck::display() const
{
  //Check if the list is empty.
  if (!rear)
  {
    std::cout << "There is no card to display." << std::endl << std::endl;
    return; //The list is empty
  }

  rear->display(); //Calls the node's parent class display function
  return;
}



//This constant member function acts as a wrapper function to display the
//contents of every node in the list. It takes no arguments and returns an
//integer type, to be the number of cards in the deck.
int a_deck::display_all() const
{
  //Check if the list is empty.
  if (!rear)
  {
    std::cout << "There are no cards to display." << std::endl << std::endl;
    return 0; //The list is empty
  }

  //Check if it is a one node list.
  if (rear == rear->go_next())
  {
    rear->display();
    return 1; //Returns one card in the deck
  }
  
  return display_all(rear->go_next()); //Traverse through the list
}



//This constant member function displays the contents of every node in the list.
//It takes a pointer to an 'a_node' class type and returns an integer type, to 
//be the number of cards in the deck.
int a_deck::display_all(a_node * rear) const
{
  //Check if the list is at the end of the traversal.
  if (rear == this->rear)
  {
    rear->display();
    return 1; //The function is done traversing
  }

  rear->display();

  return 1 + display_all(rear->go_next()); //Go to the next node
}



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~ D E F E N D _ D E C K ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//This default constructor sets the data member to its zero equivalent value
//with an initialization list. It takes no arguments and returns nothing.
d_deck::d_deck(): rear(NULL)
{}



//This constructor sets the data member to its zero equivalent value but also 
//sets the max size of the deck in an intialization list. It takes an integer 
//type, to be the max size, passed in as an argument and returns nothing.
d_deck::d_deck(int size): pile(size), rear(NULL)
{}



//This copy constructor copies a 'd_deck' object to this object by calling the
//copy all member function. It takes a constant 'd_deck' object as an argument 
//and returns nothing.
d_deck::d_deck(const d_deck & from): pile(from)
{
  //Check if passed in data member is not NULL. Otherwise, set number of cards
  //to zero.
  if (from.rear)
    num_of_cards = copy_all(from);
  else
  {
    rear = NULL;
    num_of_cards = 0;
  }
}



//This member function acts as a wrapper function to copying one deck to this
//deck class. It takes a constant 'd_deck' object passed in as an argument and
//returns an integer type, to be the number of cards in the deck.
int d_deck::copy_all(const d_deck & from)
{
  //Deallocate any memory of an existing list if it exists.
  if (rear)
    remove_all();

  //Check if the passed in data member is NULL.
  if (!from.rear)
  {
    rear = NULL;
    return 0; //Returns a failure of the operation
  }

  rear = new d_node(*from.rear); //Allocate memory and copy to rear

  //Check if there is only one node from the passed in data member.
  if (from.rear == from.rear->go_next())
  {
    rear->set_next(rear);
    return 1;
  }

  d_node * hold = rear; //To hold the real rear pointer

  //Calls the recursive function to copy the rest
  return copy_all(hold, rear->go_next(), from.rear, from.rear->go_next());
}



//This private member function copies one deck to this deck class,
//recursively. It takes four pointers to 'd_node' class types as arguments, 
//one of which is passed by reference to copy information to it. The other three 
//pointers represent the rear and front of the source list that the function is 
//copying from and a hold of the real new rear pointer. It returns an integer 
//type to be the number of cards in the deck.
int d_deck::copy_all(d_node * hold, d_node * & rear, d_node * src_rear, 
                     d_node * src_front)
{
  //Variable defintions
  int count = 0; //To be number of cards copied

  //Check if the front and rear pointer to copy from are the same. If they are
  //the function has completed its traversal.
  if (src_front == src_rear)
    return 1;
  
  rear = new d_node(*src_front); //Allocate new node and copy current data
  
  //Returns 1 plus the return value of the next node.
  count = 1 + copy_all(hold, rear->go_next(), src_rear, src_front->go_next());

  if (src_front->go_next() == src_rear)
    rear->set_next(hold); //Set rear's next pointer to the real rear

  return count; //Return the number of cards copied
}



//This destructor deallocates any memory and sets the data member to its zero
//equivalent value by calling the remove all member function. It takes no
//arguments and returns nothing.
d_deck::~d_deck()
{
  //Check if the data member is not NULL before deallocating the memory.
  if (rear)
    remove_all();
}



//This member function acts a wrapper function to remove all the nodes in this
//class's deck. It takes no arguments and has a void return type.
void d_deck::remove_all()
{
  //Check if the data member is NULL before deallocating the memory.
  if (!rear)
    return;

  //Check if there is only one node in the list.
  if (rear == rear->go_next())
  {
    delete rear;
    rear = NULL;
    return;
  }

  remove_all(rear->go_next()); //Remove the rest recursively

  delete rear; //Deallocate the last node after the recursive call
  rear = NULL;
  return;
}



//This private member function removes all the nodes in this class' deck,
//recursively. It takes a pointer to a 'd_node' class type as an argument and 
//has a void return type.
void d_deck::remove_all(d_node * & rear)
{
  //Check if there is only one node left before deallocating memory.
  if (rear == this->rear)
    return;

  d_node * hold = rear->go_next(); //Hold rear's next pointer
  delete rear;
  rear = hold;                     //Set near rear, moving forward one node
    
  return remove_all(rear); //Go to the next node.
}



//This member function inserts a card into the deck. It takes a constant
//'defend' object as an argument and returns an integer type, to be the new
//number of cards.
int d_deck::insert(const defend & from)
{
  //Check if the deck is already full.
  if (is_full())
    return num_of_cards; //Returns existing number of cards

  d_node * temp = new d_node; //Set pointer to a new allocated node

  //Check that card gets added to node.
  if(temp->copy(from))
  {
    //Check if the list is empty.
    if (!rear)
    {
      rear = temp;          //Set rear to be the new allocated node
      rear->set_next(rear); //Have the node point to itself
    }

    //Otherwise, insert the new node into the front of the list.
    else
    {
      d_node * hold = rear->go_next(); //Pointer gets the value of the next node
      temp->set_next(hold);            //New node points to old front of the list
      rear->set_next(temp);            //Rear points to the new node (new front)
    }
   
    ++num_of_cards;
  }

  //The card did not get added. Remove newly allocated node.
  else
  {
    delete temp;
    temp = NULL;
  }

  return num_of_cards; //Returns the new number of cards
}



//This constant member function acts as a wrapper function to check for an exact
//match in the deck. It takes a constant 'defend' object passed in as an 
//argument and returns a bool value.
bool d_deck::retrieve(const defend & from) const              
{
  //Check if the list is empty.
  if (!rear)
    return false; //Returns no match found

  //Check if it is a one node list
  if (rear == rear->go_next())
  {
    //Compare the data for a match
    if (rear->compare(from))
      return true;

    return false; //Returns no match found
  }

  return retrieve(rear->go_next(), from); //Returns if match was found
}



//This constant member function checks for an exact match in the deck. It takes
//one pointer to a 'd_node' class type and a constant 'defend' object passed
//in as arguments and returns a bool value.
bool d_deck::retrieve(d_node * rear, const defend & from) const
{
  //Variable definitions
  bool is_match = false; //To flag whether a match was found

  //Check if the rear and this pointers are equal to each other, indicating a 
  //full traversal of the list.
  if (rear == this->rear)
  {
    //Check if a match is found calling the node's parent member function.
    if (rear->compare(from))
      is_match = true;

    return is_match; //Returns whether a match was found
  }

  //Check if a match is found calling the node's parent member function.
  if (rear->compare(from))
    return true;

  return retrieve(rear->go_next(), from); //Returns if there's a match
}



//This member function removes the current node in this class. It takes no 
//arguments and returns a bool value.
bool d_deck::remove()
{
  //Check if the list is empty.
  if (!rear)
    return false; //Nothing was removed

  //Check if it is a one node list.
  if (rear == rear->go_next())
  {
    delete rear;
    rear = NULL;
  }

  //The list has more than one node in it.
  else
  {
    d_node * hold = rear->go_next();
    hold = hold->go_next();
    delete rear->go_next();
    rear->go_next() = hold;
  }

  return true; //The current node was deleted
}



//This constant member function displays the contents of the current node. It
//takes no arguments and has a void return type.
void d_deck::display() const
{
  //Check if the list is empty.
  if (!rear)
  {
    std::cout << "There is no card to display." << std::endl << std::endl;
    return; //The list is empty
  }

  rear->display(); //Calls the node's parent class display function
  return;
}



//This constant member function acts as a wrapper function to display the
//contents of every node in the list. It takes no arguments and returns an
//integer type.
int d_deck::display_all() const
{
  //Check if the list is empty.
  if (!rear)
  {
    std::cout << "There are no cards to display." << std::endl << std::endl;
    return 0; //The list is empty
  }

  //Check if it is a one node list.
  if (rear == rear->go_next())
  {
    rear->display();
    return 1; //Returns one card in the deck
  }
  
  return display_all(rear->go_next()); //Traverse through the list
}



//This constant member function displays the contents of every node in the list.
//It takes one pointer to a 'd_node' class type and returns an integer type, to
//be the number of cards in the deck.
int d_deck::display_all(d_node * rear) const
{
  //Check if the list is at the end of the traversal.
  if (rear == this->rear)
  {
    rear->display();
    return 1; //The function is done traversing
  }

  rear->display();

  return 1 + display_all(rear->go_next()); //Go to the next node
}



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~ S P E L L _ D E C K ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//This default constructor sets the data member to its zero equivalent value
//with an initialization list. It takes no arguments and returns nothing.
s_deck::s_deck(): rear(NULL)
{}



//This constructor sets the data member to its zero equivalent value but also 
//sets the max size of the deck in an intialization list. It takes an integer 
//type, to be the max size, passed in as an argument and returns nothing.
s_deck::s_deck(int size): pile(size), rear(NULL)
{}



//This copy constructor copies a 's_deck' object to this object by calling the
//copy all member function. It takes a constant 's_deck' object as an argument 
//and returns nothing.
s_deck::s_deck(const s_deck & from): pile(from)
{
  //Check if passed in data member is not NULL. Otherwise, set number of cards
  //to zero.
  if (from.rear)
    num_of_cards = copy_all(from);
  else
  {
    rear = NULL;
    num_of_cards = 0;
  }
}



//This member function acts as a wrapper function to copying one deck to this
//deck class. It takes a constant 's_deck' object passed in as an argument and
//returns an integer type, to be the number of cards in the deck.
int s_deck::copy_all(const s_deck & from)
{
  //Deallocate any memory of an existing list if it exists.
  if (rear)
    remove_all();

  //Check if the passed in data member is NULL.
  if (!from.rear)
  {
    rear = NULL;
    return 0; //Returns a failure of the operation
  }

  rear = new s_node(*from.rear); //Allocate memory and copy to rear

  //Check if there is only one node from the passed in data member.
  if (from.rear == from.rear->go_next())
  {
    rear->set_next(rear);
    return 1;
  }

  s_node * hold = rear; //To hold the real rear pointer

  //Calls the recursive function to copy the rest
  return copy_all(hold, rear->go_next(), from.rear, from.rear->go_next());
}



//This private member function copies one deck to this deck class,
//recursively. It takes four pointers to 's_node' class types as arguments, 
//one of which is passed by reference to copy information to it. The other three 
//pointers represent the rear and front of the source list that the function is 
//copying from and a hold of the real new rear pointer. It returns an integer 
//type to be the number of cards in the deck.
int s_deck::copy_all(s_node * hold, s_node * & rear, s_node * src_rear, 
                     s_node * src_front)
{
  //Variable defintions
  int count = 0; //To be number of cards copied

  //Check if the front and rear pointer to copy from are the same. If they are
  //the function has completed its traversal.
  if (src_front == src_rear)
    return 1;
  
  rear = new s_node(*src_front); //Allocate new node and copy current data
  
  //Returns 1 plus the return value of the next node.
  count = 1 + copy_all(hold, rear->go_next(), src_rear, src_front->go_next());

  if (src_front->go_next() == src_rear)
    rear->set_next(hold); //Set rear's next pointer to the real rear

  return count; //Return the number of cards copied
}



//This destructor deallocates any memory and sets the data member to its zero
//equivalent value by calling the remove all member function. It takes no
//arguments and returns nothing.
s_deck::~s_deck()
{
  //Check if the data member is not NULL before deallocating the memory.
  if (rear)
    remove_all();
}



//This member function acts a wrapper function to remove all the nodes in this
//class's deck. It takes no arguments and has a void return type.
void s_deck::remove_all()
{
  //Check if the data member is NULL before deallocating the memory.
  if (!rear)
    return;

  //Check if there is only one node in the list.
  if (rear == rear->go_next())
  {
    delete rear;
    rear = NULL;
    return;
  }

  remove_all(rear->go_next()); //Remove the rest recursively

  delete rear; //Deallocate the last node after the recursive call
  rear = NULL;
  return;
}



//This private member function removes all the nodes in this class' deck,
//recursively. It takes a pointer to a 's_node' class type as an argument and 
//has a void return type.
void s_deck::remove_all(s_node * & rear)
{
  //Check if there is only one node left before deallocating memory.
  if (rear == this->rear)
    return;

  s_node * hold = rear->go_next(); //Hold rear's next pointer
  delete rear;
  rear = hold;                     //Set near rear, moving forward one node
    
  return remove_all(rear); //Go to the next node.
}



//This member function inserts a card into the deck. It takes a constant
//'spell' object as an argument and returns an integer type, to be the new
//number of cards.
int s_deck::insert(const spell & from)
{
  //Check if the deck is already full.
  if (is_full())
    return num_of_cards; //Returns existing number of cards

  s_node * temp = new s_node; //Set pointer to a new allocated node

  //Check that card gets added to node.
  if(temp->copy(from))
  {
    //Check if the list is empty.
    if (!rear)
    {
      rear = temp;          //Set rear to be the new allocated node
      rear->set_next(rear); //Have the node point to itself
    }

    //Otherwise, insert the new node into the front of the list.
    else
    {
      s_node * hold = rear->go_next(); //Pointer gets the value of the next node
      temp->set_next(hold);            //New node points to old front of the list
      rear->set_next(temp);            //Rear points to the new node (new front)
    }
   
    ++num_of_cards;
  }

  //The card did not get added. Remove newly allocated node.
  else
  {
    delete temp;
    temp = NULL;
  }

  return num_of_cards; //Returns the new number of cards
}



//This constant member function acts as a wrapper function to check for an exact
//match in the deck. It takes a constant 'spell' object passed in as an 
//argument and returns a bool value.
bool s_deck::retrieve(const spell & from) const              
{
  //Check if the list is empty.
  if (!rear)
    return false; //Returns no match found

  //Check if it is a one node list
  if (rear == rear->go_next())
  {
    //Compare the data for a match
    if (rear->compare(from))
      return true;

    return false; //Returns no match found
  }

  return retrieve(rear->go_next(), from); //Returns if match was found
}



//This constant member function checks for an exact match in the deck. It takes
//one pointer to a 's_node' class type and a constant 'spell' object passed
//in as arguments and returns a bool value.
bool s_deck::retrieve(s_node * rear, const spell & from) const
{
  //Variable definitions
  bool is_match = false; //To flag whether a match was found

  //Check if the rear and this pointers are equal to each other, indicating a 
  //full traversal of the list.
  if (rear == this->rear)
  {
    //Check if a match is found calling the node's parent member function.
    if (rear->compare(from))
      is_match = true;

    return is_match; //Returns whether a match was found
  }

  //Check if a match is found calling the node's parent member function.
  if (rear->compare(from))
    return true;

  return retrieve(rear->go_next(), from); //Returns if there's a match
}



//This member function removes the current node in this class. It takes no 
//arguments and returns a bool value.
bool s_deck::remove()
{
  //Check if the list is empty.
  if (!rear)
    return false; //Nothing was removed

  //Check if it is a one node list.
  if (rear == rear->go_next())
  {
    delete rear;
    rear = NULL;
  }

  //The list has more than one node in it.
  else
  {
    s_node * hold = rear->go_next();
    hold = hold->go_next();
    delete rear->go_next();
    rear->go_next() = hold;
  }

  return true; //The current node was deleted
}



//This constant member function displays the contents of the current node. It
//takes no arguments and has a void return type.
void s_deck::display() const
{
  //Check if the list is empty.
  if (!rear)
  {
    std::cout << "There is no card to display." << std::endl << std::endl;
    return; //The list is empty
  }

  rear->display(); //Calls the node's parent class display function
  return;
}



//This constant member function acts as a wrapper function to display the
//contents of every node in the list. It takes no arguments and returns an
//integer type.
int s_deck::display_all() const
{
  //Check if the list is empty.
  if (!rear)
  {
    std::cout << "There are no cards to display." << std::endl << std::endl;
    return 0; //The list is empty
  }

  //Check if it is a one node list.
  if (rear == rear->go_next())
  {
    rear->display();
    return 1; //Returns one card in the deck
  }
  
  return display_all(rear->go_next()); //Traverse through the list
}



//This constant member function displays the contents of every node in the list.
//It takes one pointer to a 's_node' class type and returns an integer type, to
//be the number of cards in the deck.
int s_deck::display_all(s_node * rear) const
{
  //Check if the list is at the end of the traversal.
  if (rear == this->rear)
  {
    rear->display();
    return 1; //The function is done traversing
  }

  rear->display();

  return 1 + display_all(rear->go_next()); //Go to the next node
}



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~ A C T I O N _ H A N D ~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~ D E F E N D _ H A N D ~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~ S P E L L _ H A N D ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~



