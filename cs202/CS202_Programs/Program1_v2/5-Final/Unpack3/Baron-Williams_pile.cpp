#include "Baron-Williams_pile.h"

// *****************************************************************************
// Program 1
// Author: Connor Baron-Williams
// Due Date: January 31, 2022
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
// Linked Lists (ARR) of their respective cards (action, defend, and spell, 
// respectively). The ARR has a more complicated purpose of managing one 
// player's "cards to be played" (index 0), another player's "cards to be 
// played" (index 1), the first player's "played cards" (index 2), the second 
// player's "played cards" (index 3), and all the cards used, or discard pile 
// (index 4).
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
    if (temp)
    {
      delete temp;
      temp = NULL;
    }
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



//This member function removes a random node in this class. It takes an
//'action' object passed in as an argument, to copy to, and returns a bool 
//value.
bool a_deck::remove(action & copy)
{
  //Variable definitions
  int rand_num = 0; //To be random number to traverse the list
  int moves = 0;    //To be the number of moves taken up to the random number

  //Check if the list is empty.
  if (!rear)
    return false; //Nothing was removed

  //Check if it is a one node list.
  if (rear == rear->go_next())
  {
    rear->copy_to(copy); //Copies to passed in object

    delete rear;
    rear = NULL;

    num_of_cards = 0;

    return true; //Returns a successful operation and now the list is empty
  }

  //Seed and run a random number generator to be used to traverse the list.
  srand(time(0));
  rand_num = (rand() % num_of_cards) + 1;

  return remove_rand(rear, copy, rand_num, moves);
}



//This private member function removes a random node in this class. It takes a
//pointer to an 'a_node', an 'action' object and two integer types, to be the 
//random number to traverse and the number of moves taken, passed in as 
//arguments and returns a bool value.
bool a_deck::remove_rand(a_node * & rear, action & copy, int rand_num, 
                         int & moves)
{
  //Check if the random number is less than or equal to zero.
  if (rand_num <= 0)
    return false; //Returns a failure of the operation

  //Check if traversal is back at the rear of the list and skip it to hold the
  //structure.
  if (rear == this->rear)
    --moves;

  //Check if the number of moves needed has taken place.
  if (moves == rand_num)
  {
    a_node * hold = rear->go_next();

    rear->copy_to(copy); //Copies to passed in object

    delete rear;
    rear = hold;

    --num_of_cards; //Takes one card away from card number total
    moves = 0;      //Reset the moves to zero

    return true; //Data has been copied and deleted
  }

  ++moves; //Increment the number of moves

  return remove_rand(rear->go_next(), copy, rand_num, moves);
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



//This member function reads in an external text file and builds a deck of this
//class type. It is using namespace std, takes a constant string type, to be the 
//file name to read from, as an argument and returns an integer type to be the 
//number of cards loaded.
int a_deck::build(const std::string & filename)
{
  using namespace std;

  //Variable definitions
  int get_cardnum = 0;     //To read in default card number
  char get_cardtype[SIZE]; //To read in default card "environment" type
  int get_damage = 0;      //To read in action card's damage points
  char get_weapon[SIZE];   //To read in action card's weapon type
  action to_load;          //To hold the read in data for insertion

  ifstream file_in; //To connect and read in files from an external file

  file_in.open(filename); //Connect to the passed in file

  //Check if the connection is working and load the data stored in the external
  //file
  if (file_in)
  {
    file_in >> get_cardnum;
    file_in.ignore(100, '|');

    //Checks that the read is not at the end of the file.
    while (!file_in.eof())
    {
      file_in.get(get_cardtype, SIZE, '|');
      file_in.ignore(100, '|');

      file_in >> get_damage;
      file_in.ignore(100, '|');

      file_in.get(get_weapon, SIZE, '\n');
      file_in.ignore(100, '\n');

      ++num_of_cards; //Increment the number of cards in the deck

      to_load.add(get_cardnum, get_cardtype, get_damage, get_weapon);
      insert(to_load);

      //Start reading in the next line.
      file_in >> get_cardnum;
      file_in.ignore(100, '|');
    }

    file_in.close(); //Close the file before exiting the function
  }

  max_size = num_of_cards; //Set the max size of the deck to the number read in

  return num_of_cards; //Returns the number of cards in the deck
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
    if (temp)
    {
      delete temp;
      temp = NULL;
    }
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



//This member function removes a random node in this class. It takes a
//'defend' object passed in as an argument, to copy to, and returns a bool 
//value.
bool d_deck::remove(defend & copy)
{
  //Variable definitions
  int rand_num = 0; //To be random number to traverse the list
  int moves = 0;    //To be the number of moves taken up to the random number

  //Check if the list is empty.
  if (!rear)
    return false; //Nothing was removed

  //Check if it is a one node list.
  if (rear == rear->go_next())
  {
    rear->copy_to(copy); //Copies to passed in object

    delete rear;
    rear = NULL;

    num_of_cards = 0;

    return true; //Returns a successful operation and now the list is empty
  }

  //Seed and run a random number generator to be used to traverse the list.
  srand(time(0));
  rand_num = (rand() % num_of_cards) + 1;

  return remove_rand(rear, copy, rand_num, moves);
}



//This private member function removes a random node in this class. It takes a
//pointer to a 'd_node', an 'defend' object and two integer types, to be the 
//random number to traverse and the number of moves taken, passed in as 
//arguments and returns a bool value.
bool d_deck::remove_rand(d_node * & rear, defend & copy, int rand_num, 
                         int & moves)
{
  //Check if the random number is less than or equal to zero.
  if (rand_num <= 0)
    return false; //Returns a failure of the operation

  //Check if traversal is back at the rear of the list and skip it to hold the
  //structure.
  if (rear == this->rear)
    --moves;

  //Check if the number of moves needed has taken place.
  if (moves == rand_num)
  {
    d_node * hold = rear->go_next();

    rear->copy_to(copy); //Copies to passed in object

    delete rear;
    rear = hold;

    --num_of_cards; //Takes one card away from card number total
    moves = 0;      //Reset the moves to zero

    return true; //Data has been copied and deleted
  }

  ++moves; //Increment the number of moves

  return remove_rand(rear->go_next(), copy, rand_num, moves);
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



//This member function reads in an external text file and builds a deck of this
//class type. It is using namespace std, takes a constant string type, to be the 
//file name to read from, as an argument and returns an integer type to be the 
//number of cards loaded.
int d_deck::build(const std::string & filename)
{
  using namespace std;

  //Variable definitions
  int get_cardnum = 0;     //To read in default card number
  char get_cardtype[SIZE]; //To read in default card "environment" type
  int get_strength = 0;    //To read in defend card's strength points
  string get_shield;       //To read in defend card's shield type
  defend to_load;          //To hold the read in data for insertion

  ifstream file_in; //To connect and read in files from an external file

  file_in.open(filename); //Connect to the passed in file

  //Check if the connection is working and load the data stored in the external
  //file
  if (file_in)
  {
    file_in >> get_cardnum;
    file_in.ignore(100, '|');

    //Checks that the read is not at the end of the file.
    while (!file_in.eof())
    {
      file_in.get(get_cardtype, SIZE, '|');
      file_in.ignore(100, '|');

      file_in >> get_strength;
      file_in.ignore(100, '|');

      file_in >> get_shield;
      file_in.ignore(100, '\n');

      ++num_of_cards; //Increment the number of cards in the deck

      to_load.add(get_cardnum, get_cardtype, get_strength, get_shield);
      insert(to_load);

      //Start reading in the next line.
      file_in >> get_cardnum;
      file_in.ignore(100, '|');
    }

    file_in.close(); //Close the file before exiting the function
  }

  max_size = num_of_cards; //Set the max size of the deck to the number read in

  return num_of_cards; //Returns the number of cards in the deck
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
    if (temp)
    {
      delete temp;
      temp = NULL;
    }
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



//This member function removes a random node in this class. It takes a
//'spell' object passed in as an argument, to copy to, and returns a bool 
//value.
bool s_deck::remove(spell & copy)
{
  //Variable definitions
  int rand_num = 0; //To be random number to traverse the list
  int moves = 0;    //To be the number of moves taken up to the random number

  //Check if the list is empty.
  if (!rear)
    return false; //Nothing was removed

  //Check if it is a one node list.
  if (rear == rear->go_next())
  {
    rear->copy_to(copy); //Copies to passed in object

    delete rear;
    rear = NULL;

    num_of_cards = 0;

    return true; //Returns a successful operation and now the list is empty
  }

  //Seed and run a random number generator to be used to traverse the list.
  srand(time(0));
  rand_num = (rand() % num_of_cards) + 1;

  return remove_rand(rear, copy, rand_num, moves);
}



//This private member function removes a random node in this class. It takes a
//pointer to a 's_node', an 'spell' object and two integer types, to be the 
//random number to traverse and the number of moves taken, passed in as 
//arguments and returns a bool value.
bool s_deck::remove_rand(s_node * & rear, spell & copy, int rand_num, 
                         int & moves)
{
  //Check if the random number is less than or equal to zero.
  if (rand_num <= 0)
    return false; //Returns a failure of the operation

  //Check if traversal is back at the rear of the list and skip it to hold the
  //structure.
  if (rear == this->rear)
    --moves;

  //Check if the number of moves needed has taken place.
  if (moves == rand_num)
  {
    s_node * hold = rear->go_next();

    rear->copy_to(copy); //Copies to passed in object

    delete rear;
    rear = hold;

    --num_of_cards; //Takes one card away from card number total
    moves = 0;      //Reset the moves to zero

    return true; //Data has been copied and deleted
  }

  ++moves; //Increment the number of moves

  return remove_rand(rear->go_next(), copy, rand_num, moves);
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



//This member function reads in an external text file and builds a deck of this
//class type. It is using namespace std, takes a constant string type, to be the 
//file name to read from, as an argument and returns an integer type to be the 
//number of cards loaded.
int s_deck::build(const std::string & filename)
{
  using namespace std;

  //Variable definitions
  int get_cardnum = 0;     //To read in default card number
  char get_cardtype[SIZE]; //To read in default card "environment" type
  float get_factor = 0;    //To read in spell card's enhancement factor
  string get_magic;        //To read in spell card's magic type
  spell to_load;           //To hold the read in data for insertion

  ifstream file_in; //To connect and read in files from an external file

  file_in.open(filename); //Connect to the passed in file

  //Check if the connection is working and load the data stored in the external
  //file
  if (file_in)
  {
    file_in >> get_cardnum;
    file_in.ignore(100, '|');

    //Checks that the read is not at the end of the file.
    while (!file_in.eof())
    {
      file_in.get(get_cardtype, SIZE, '|');
      file_in.ignore(100, '|');

      file_in >> get_factor;
      file_in.ignore(100, '|');

      file_in >> get_magic;
      file_in.ignore(100, '\n');

      ++num_of_cards; //Increment the number of cards in the deck

      to_load.add(get_cardnum, get_cardtype, get_factor, get_magic);
      insert(to_load);

      //Start reading in the next line.
      file_in >> get_cardnum;
      file_in.ignore(100, '|');
    }

    file_in.close(); //Close the file before exiting the function
  }

  max_size = num_of_cards; //Set the max size of the deck to the number read in

  return num_of_cards; //Returns the number of cards in the deck
}



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~ A C T I O N _ H A N D ~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//This default constructor sets the size of the ARR and sets each indexed
//pointer to it's zero equivalent value. It takes a default integer type, to be
//the array size, passed in as an argument and returns nothing.
a_hand::a_hand(int size): num_of_hands(size)
{
  //Create an empty ARR recursively.
  create_arr();
}



//This member function acts as a wrapper function to create an empty ARR,
//setting all the indexed pointers within the array to NULL. It takes no
//arguments and has a void return type.
void a_hand::create_arr()
{
  //Variable definitions
  int index = 0; //To be index of array

  //Allocate a new ARR with the size of the class' data member.
  head = new a_node * [num_of_hands];

  create_arr(index); //Recursively make all indices point to NULL

  return;
}



//This private member function creates an empty ARR, setting all the indexed
//pointers within the array to NULL. It takes an integer type, to be the index 
//of the array, passed in as an argument and has a void return type.
void a_hand::create_arr(int & index)
{
  //If the index is equal to the size of the array, traversal has completed.
  if (index == num_of_hands)
    return;

  head[index] = NULL;
  ++index;

  create_arr(index); //Go to next index

  return;
}



//This copy constructor copies an 'a_hand' object to this class' object by 
//calling its copy_all member function. It takes a constant 'a_hand' object 
//passed in as an argument and returns nothing.
a_hand::a_hand(const a_hand & from): pile(from)
{
  //Check if passed in object's ARR is not NULL before copying its data.
  //Otherwise set this object's data to its zero equivalent values.
  if (from.head)
    num_of_cards = copy_all(from);
  else
  {
    head = NULL;
    num_of_hands = 0;
  }
}



//This member function acts as a wrapper function to copy all the data from an
//'a_hand' object. It takes a constant 'a_hand' object passed in as an argument
//and returns an integer type, to be the total number of discarded cards.
int a_hand::copy_all(const a_hand & from)
{
  //Variable definitions
  int index = 0; //To be index of the ARR

  //Check if the passed in object is valid.
  if (!from.head)
    return 0;

  //Check if this object's ARR has any data already and deallocate all the 
  //memory.
  if (head)
    remove_all();

  num_of_hands = from.num_of_hands;

  //Allocate a new array of pointers to the size of the passed in ARR.
  head = new a_node * [num_of_hands];

  //Set the ARR, with all indexed pointers set to NULL.
  create_arr(index);

  index = 0; //Reset the index

  return copy_all(from.head, index); //Calls the recursive array function
}



//This private member function copies all the data from an existing ARR to this 
//class' ARR. It take a pointer to a pointer to the 'a_node' class type, and an 
//integer type, to be the index of the ARR, passed in as arguments and returns 
//an integer to be the total number of discarded cards.
int a_hand::copy_all(a_node ** src, int & index)
{
  //Variable definitions
  int count = 0;

  //Check if the destination's array's index is at the end of the array. Copy
  //the last indexed information and return out of the function.
  if (index == (num_of_hands - 1))
  {
    //Check if the source's indexed pointer is NULL.
    if (!src[index])
      return 0; //Returns zero cards copied at end of traversal

    //Return the count of the last indexed list.
    return count = copy_list(head[index], src[index]);
  }

  //Check if the source's indexed pointer is not NULL.
  if (src[index])
    count = copy_list(head[index], src[index]); //Holds a count of the copied cards

  ++index;  //Increment to the next index of the array

  return copy_all(src, index); //Go to the next index of the array
}



//This private member function copies all the data from an existing LLL to this 
//class' LLL. It takes two pointers to the 'a_node" class type, one of which is 
//passed by reference, as arguments and returns an integer to be the number of 
//cards copied.
int a_hand::copy_list(a_node * & dest, a_node * src)
{
  //Check if the source data to be copied is NULL. Otherwise, allocate a new
  //node to the destination list.
  if (!src)
  {
    dest = NULL;
    return 0; //Returns the end of this function, whether successful or not
  }

  dest = new a_node(*src);
  
  return 1 + copy_list(dest->go_next(), src->go_next()); //Go to the next node
}



//This destructor deallocates any memory in the ARR by calling the remove_all
//member function. It takes no arguments and returns nothing.
a_hand::~a_hand()
{
  //Check if the ARR has memory to delete.
  if (head)
    remove_all();

  num_of_hands = 0;
}



//This member function acts a wrapper function to remove any and all allocated
//memory in the ARR. It takes no arguments and has a void return type.
void a_hand::remove_all()
{
  //Variable definitions
  int index = 0; //To be index of array

  //Check if there is anything to remove.
  if (!head)
    return;

  remove_all(index); //Calls the function recursively

  //After all information has been remvoed. Deallocate the array's memory and
  //set to NULL.
  delete [] head;
  head = NULL;

  return;
}



//This private member function manages the removal of a list within each index 
//of the ARR. It calls a recursive removal of a Linear Linked List within the 
//index before moving onto the next index. It takes an integer type, to be the 
//ARR index, passed in as an argument and has a void return type.
void a_hand::remove_all(int & index)
{
  //Check if the index is equal to the size of the ARR. If so, the traversal
  //is complete.
  if (index == num_of_hands)
    return;
  
  //Check if the indexed pointer is not NULL.
  if (head[index])
    remove_list(head[index]); //Removes the Linear Linked List at this index

  ++index;

  return remove_all(index); //Call the function recursively
}



//This member function acts as a wrapper function to remove the discarded pile
//from the hand. It takes an 'a_deck' object, to copy to, passed in as an 
//argument and returns a bool value.
bool a_hand::remove_discarded(a_deck & add_to)
{
  //Variable definitions
  int index = 0; //To be the index of the array
  bool copied_over = false; //To be whether the data was removed and copied

  index = num_of_hands - 1; //Index of array to deallocate a list

  //Check if the array is NULL.
  if (!head)
    return false; //Returns a failure of the operation

  //Check if the discarded list is NULL.
  if (!head[index])
    return false; //Returns a failure of the operation

  //Check that the deck getting the discarded cards is empty before copying to 
  //it
  if (add_to.is_empty())
    copied_over = remove_discarded(head[index], add_to); //Removes and copies


  return copied_over; //The list has been removed and copied over to a deck
}



//This private member function manages the removal of a Linear Linked List by 
//calling itself recursively and it copies its data to an empty deck. It takes 
//a pointer to the 'a_node' class type and an 'a_deck' object, to copy to, as an 
//arguments and returns a bool value.
bool a_hand::remove_discarded(a_node * & head, a_deck & add_to)
{
  //Variable definitions
  bool copied_over = false; //To be whether the data was deleted and copied over

  //Check if there is anything to remove.
  if (!head)
    return copied_over;

  if (!add_to.insert(*head))
    return copied_over;

  //Check if it is the last node of the list.
  if (!head->go_next())
  {
    delete head;
    head = NULL;
  }

  //Otherwise, remove the node and reattach.
  else
  {
    a_node * hold = head->go_next();
    delete head;
    head = hold;
  }

  copied_over = true;

  return copied_over += remove_discarded(head, add_to); //Go to the next node
}



//This private member function manages the removal of a Linear Linked List by 
//calling itself recursively. It takes a pointer to the 'a_node' class type as 
//an arguments and has a void return type.
void a_hand::remove_list(a_node * & head)
{
  //Check if there is anything to remove.
  if (!head)
    return;

  //Check if it is the last node of the list.
  if (!head->go_next())
  {
    delete head;
    head = NULL;
  }

  //Otherwise, remove the node and reattach.
  else
  {
    a_node * hold = head->go_next();
    delete head;
    head = hold;
  }

  remove_list(head); //Go to the next node to remove

  return;
}



//This member function insets a card into a specific hand of this class' ARR. It
//takes a constant 'action' object, to the be the inserted card, and an integer
//type, to be the ARR's index to add the card, as arguments and returns an
//integer type, to represent a success or failure of the operation.
int a_hand::insert(const action & from, int hand_num)
{
  //Check if the hand number for the card to be inserted is valid.
  if (hand_num >= 0 && hand_num < num_of_hands)
  {
    if (!head)
      create_arr();

    a_node * temp = new a_node;

    //Check if newly allocated node copies the passed in object successfully.
    if(temp->copy(from))
    {
      //Check if the indexed pointer is NULL. Otherwise insert it at the
      //beginning of the list.
      if (!head[hand_num])
        head[hand_num] = temp;
      else
      {
        temp->set_next(head[hand_num]);
        head[hand_num] = temp;
      }

      return 1; //Returns a success of the operation.
    }

    //The operation was a failure. Deallocate the newly allocated node and set
    //it to NULL.
    else
    {
      //Make sure there is something to delete before deallocating the temporary
      //pointer.
      if (temp)
      {
        delete temp;
        temp = NULL;
      }
    }
  }

  return 0; //Returns a failure of the operation
}



//This constant member function acts as a wrapper function to search and find
//a matching card based on the passed in information. It takes a constant
//'action' object and an integer type, to be the hand number to look in, passed
//as arguments and returns a bool value.
bool a_hand::retrieve(const action & from, int hand_num) const
{
  //Variable defintions
  bool is_match = false; //To check whether a match was found

  //Check if the ARR is NULL before traversing for a match
  if (head)
  {
    //Check if the passed in hand number is valid.
    if (hand_num >= 0 && hand_num < num_of_hands)
    {
      //Check if the indexed pointer is not NULL before traversing.
      if (head[hand_num])
        is_match = retrieve_list(head[hand_num], from); //Finds a match in list
    }
  }

  return is_match; //Returns whether a match was found
}



//This constant private member function searches for a matching card in a LLL
//based on passed in information. It takes a pointer to the 'a_node' class type
//and a constant 'action' object, passed in as arguments and returns a bool
//value.
bool a_hand::retrieve_list(a_node * head, const action & from) const
{
  //Check if the pointer is NULL.
  if (!head)
    return false; //The list is empty or has been traversed with no match found

  //Check if a match is found.
  if(head->compare(from))
    return true; //Returns a successful match

  return retrieve_list(head->go_next(), from); //Go to the next node
}



//This member function removes the current node in an ARR. It takes an 'action'
//object, to copy to, and an integer to be the hand number, passed in as 
//arguments and returns a bool value.
bool a_hand::remove(action & copy, int hand_num)
{
  //Check if the array is NULL.
  if (!head)
    return false; //Returns a failure of the operation

  //Check if the indexed list is NULL.
  if (!head[hand_num])
    return false; //Returns a failure of the operation

  head[hand_num]->copy_to(copy);

  //If there is only one node left in the list, deallocate the memory and set it
  //to NULL.
  if (!head[hand_num]->go_next())
  {
    delete head[hand_num];
    head[hand_num] = NULL;
  }

  //Otherwise, hold onto the next node, deallocate it and reconnect.
  else
  {
    a_node * hold = head[hand_num]->go_next();
    delete head[hand_num];
    head[hand_num] = hold;
  }

  return true; //One node successfully removed
}



//This constant member function displays the current card in a specific hand. It
//takes an integer type, to be the hand number, passed in as an argument and has 
//a void return type.
void a_hand::display(int hand_num) const
{
  //Check if the array is not NULL.
  if (head)
  {
    //Check that the passed in argument is valid.
    if (hand_num >= 0 && hand_num < num_of_hands)
    {
      //Check that the indexed pointer of the array is not NULL.
      if (head[hand_num])
        head[hand_num]->display();
    }
  }

  return;
}



//This constant member function acts as a wrapper to display every card in a 
//specific hand. It takes an integer type, to be the hand number, passed in as
//an argument returns an integer type to be the number of cards displayed.
int a_hand::display_all(int hand_num) const
{
  //Variable defintions
  int count = 0; //To be the number of cards displayed

  //Check if the array is NULL.
  if (!head)
    return 0; //Returns a failure of the operation

  //Check that the passed in argument is valid.
  if (hand_num >= 0 && hand_num < num_of_hands)
  {
    //Check if the index pointer of the array is NULL.
    if (head[hand_num])
    {
      //Check which hand is going to be displayed.
      if (hand_num == 0)
        std::cout << "Player 1's hand:\n" << std::endl;
      else if (hand_num == 1)
        std::cout << "Player 1's played cards:\n" << std::endl;
      else if (hand_num == 2)
        std::cout << "Player 2's hand:\n" << std::endl;
      else if (hand_num == 3)
        std::cout << "Player 2's played cards:\n" << std::endl;
      else
        std::cout << "All played cards:\n" << std::endl;

      //Display the hand and count how many cards are displayed.
      count = display_list(head[hand_num]);
    }
  }

  return count; //Returns the number of cards displayed
}



//This constant private member function displays all the data in a LLL. It takes
//a pointer to the 'a_node' class type passed in as an argument and returns an
//integer to be the number of cards displayed.
int a_hand::display_list(a_node * head) const
{
  //Check if the list is empty.
  if (!head)
    return 0; //Returns the end of the recursion or a failure of the operation

  head->display(); //Displays the contents of the current node

  return 1 + display_list(head->go_next()); //Counts and goes to the next node
}



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~ D E F E N D _ H A N D ~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//This default constructor sets the size of the ARR and sets each indexed
//pointer to it's zero equivalent value. It takes a default integer type, to be
//the array size, passed in as an argument and returns nothing.
d_hand::d_hand(int size): num_of_hands(size)
{
  //Create an empty ARR recursively.
  create_arr();
}



//This member function acts as a wrapper function to create an empty ARR,
//setting all the indexed pointers within the array to NULL. It takes no
//arguments and has a void return type.
void d_hand::create_arr()
{
  //Variable definitions
  int index = 0; //To be index of array

  //Allocate a new ARR with the size of the class' data member.
  head = new d_node * [num_of_hands];

  create_arr(index); //Recursively make all indices point to NULL

  return;
}



//This private member function creates an empty ARR, setting all the indexed
//pointers within the array to NULL. It takes an integer type, to be the index 
//of the array, passed in as an argument and has a void return type.
void d_hand::create_arr(int & index)
{
  //If the index is equal to the size of the array, traversal has completed.
  if (index == num_of_hands)
    return;

  head[index] = NULL;
  ++index;

  create_arr(index); //Go to next index

  return;
}



//This copy constructor copies an 'd_hand' object to this class' object by 
//calling its copy_all member function. It takes a constant 'd_hand' object 
//passed in as an argument and returns nothing.
d_hand::d_hand(const d_hand & from): pile(from)
{
  //Check if passed in object's ARR is not NULL before copying its data.
  //Otherwise set this object's data to its zero equivalent values.
  if (from.head)
    num_of_cards = copy_all(from);
  else
  {
    head = NULL;
    num_of_hands = 0;
  }
}



//This member function acts as a wrapper function to copy all the data from an
//'d_hand' object. It takes a constant 'd_hand' object passed in as an argument
//and returns an integer type, to be the total number of discarded cards.
int d_hand::copy_all(const d_hand & from)
{
  //Variable definitions
  int index = 0; //To be index of the ARR

  //Check if the passed in object is valid.
  if (!from.head)
    return 0;

  //Check if this object's ARR has any data already and deallocate all the 
  //memory.
  if (head)
    remove_all();

  num_of_hands = from.num_of_hands;

  //Allocate a new array of pointers to the size of the passed in ARR.
  head = new d_node * [num_of_hands];

  //Set the ARR, with all indexed pointers set to NULL.
  create_arr(index);

  index = 0; //Reset the index

  return copy_all(from.head, index); //Calls the recursive array function
}



//This private member function copies all the data from an existing ARR to this 
//class' ARR. It take a pointer to a pointer to the 'd_node' class type, and an 
//integer type, to be the index of the ARR, passed in as arguments and returns 
//an integer to be the total number of discarded cards.
int d_hand::copy_all(d_node ** src, int & index)
{
  //Variable definitions
  int count = 0;

  //Check if the destination's array's index is at the end of the array. Copy
  //the last indexed information and return out of the function.
  if (index == (num_of_hands - 1))
  {
    //Check if the source's indexed pointer is NULL.
    if (!src[index])
      return 0; //Returns zero cards copied at end of traversal

    //Return the count of the last indexed list.
    return count = copy_list(head[index], src[index]);
  }

  //Check if the source's indexed pointer is not NULL.
  if (src[index])
    count = copy_list(head[index], src[index]); //Holds a count of the copied cards

  ++index;  //Increment to the next index of the array

  return copy_all(src, index); //Go to the next index of the array
}



//This private member function copies all the data from an existing LLL to this 
//class' LLL. It takes two pointers to the 'd_node" class type, one of which is 
//passed by reference, as arguments and returns an integer to be the number of 
//cards copied.
int d_hand::copy_list(d_node * & dest, d_node * src)
{
  //Check if the source data to be copied is NULL. Otherwise, allocate a new
  //node to the destination list.
  if (!src)
  {
    dest = NULL;
    return 0; //Returns the end of this function, whether successful or not
  }

  dest = new d_node(*src);
  
  return 1 + copy_list(dest->go_next(), src->go_next()); //Go to the next node
}



//This destructor deallocates any memory in the ARR by calling the remove_all
//member function. It takes no arguments and returns nothing.
d_hand::~d_hand()
{
  //Check if the ARR has memory to delete.
  if (head)
    remove_all();

  num_of_hands = 0;
}



//This member function acts a wrapper function to remove any and all allocated
//memory in the ARR. It takes no arguments and has a void return type.
void d_hand::remove_all()
{
  //Variable definitions
  int index = 0; //To be index of array

  //Check if there is anything to remove.
  if (!head)
    return;

  remove_all(index); //Calls the function recursively

  //After all information has been remvoed. Deallocate the array's memory and
  //set to NULL.
  delete [] head;
  head = NULL;

  return;
}



//This private member function manages the removal of a list within each index 
//of the ARR. It calls a recursive removal of a Linear Linked List within the 
//index before moving onto the next index. It takes an integer type, to be the 
//ARR index, passed in as an argument and has a void return type.
void d_hand::remove_all(int & index)
{
  //Check if the index is equal to the size of the ARR. If so, the traversal
  //is complete.
  if (index == num_of_hands)
    return;
  
  //Check if the indexed pointer is not NULL.
  if (head[index])
    remove_list(head[index]); //Removes the Linear Linked List at this index

  ++index;

  return remove_all(index); //Call the function recursively
}



//This member function acts as a wrapper function to remove the discarded pile
//from the hand. It takes a 'd_deck' object, to copy to, passed in as an 
//argument and returns a bool value.
bool d_hand::remove_discarded(d_deck & add_to)
{
  //Variable definitions
  int index = 0; //To be the index of the array
  bool copied_over = false; //To be whether the data was removed and copied

  index = num_of_hands - 1; //Index of array to deallocate a list

  //Check if the array is NULL.
  if (!head)
    return false; //Returns a failure of the operation

  //Check if the discarded list is NULL.
  if (!head[index])
    return false; //Returns a failure of the operation

  //Check that the deck getting the discarded cards is empty before copying to 
  //it
  if (add_to.is_empty())
    copied_over = remove_discarded(head[index], add_to); //Removes and copies


  return copied_over; //The list has been removed and copied over to a deck
}



//This private member function manages the removal of a Linear Linked List by 
//calling itself recursively and it copies its data to an empty deck. It takes 
//a pointer to the 'd_node' class type and a 'd_deck' object, to copy to, as an 
//arguments and returns a bool value.
bool d_hand::remove_discarded(d_node * & head, d_deck & add_to)
{
  //Variable definitions
  bool copied_over = false; //To be whether the data was deleted and copied over

  //Check if there is anything to remove.
  if (!head)
    return copied_over;

  if (!add_to.insert(*head))
    return copied_over;

  //Check if it is the last node of the list.
  if (!head->go_next())
  {
    delete head;
    head = NULL;
  }

  //Otherwise, remove the node and reattach.
  else
  {
    d_node * hold = head->go_next();
    delete head;
    head = hold;
  }

  copied_over = true;

  return copied_over += remove_discarded(head, add_to); //Go to the next node
}



//This private member function manages the removal of a Linear Linked List by 
//calling itself recursively. It takes a pointer to the 'd_node' class type as 
//an arguments and has a void return type.
void d_hand::remove_list(d_node * & head)
{
  //Check if there is anything to remove.
  if (!head)
    return;

  //Check if it is the last node of the list.
  if (!head->go_next())
  {
    delete head;
    head = NULL;
  }

  //Otherwise, remove the node and reattach.
  else
  {
    d_node * hold = head->go_next();
    delete head;
    head = hold;
  }

  remove_list(head); //Go to the next node to remove

  return;
}



//This member function insets a card into a specific hand of this class' ARR. It
//takes a constant 'defend' object, to the be the inserted card, and an integer
//type, to be the ARR's index to add the card, as arguments and returns an
//integer type, to represent a success or failure of the operation.
int d_hand::insert(const defend & from, int hand_num)
{
  //Check if the hand number for the card to be inserted is valid.
  if (hand_num >= 0 && hand_num < num_of_hands)
  {
    if (!head)
      create_arr();

    d_node * temp = new d_node;

    //Check if newly allocated node copies the passed in object successfully.
    if(temp->copy(from))
    {
      //Check if the indexed pointer is NULL. Otherwise insert it at the
      //beginning of the list.
      if (!head[hand_num])
        head[hand_num] = temp;
      else
      {
        temp->set_next(head[hand_num]);
        head[hand_num] = temp;
      }

      return 1; //Returns a success of the operation.
    }

    //The operation was a failure. Deallocate the newly allocated node and set
    //it to NULL.
    else
    {
      //Make sure there is something to delete before deallocating the temporary
      //pointer.
      if (temp)
      {
        delete temp;
        temp = NULL;
      }
    }
  }

  return 0; //Returns a failure of the operation
}



//This constant member function acts as a wrapper function to search and find
//a matching card based on the passed in information. It takes a constant
//'defend' object and an integer type, to be the hand number to look in, passed
//as arguments and returns a bool value.
bool d_hand::retrieve(const defend & from, int hand_num) const
{
  //Variable defintions
  bool is_match = false; //To check whether a match was found

  //Check if the ARR is NULL before traversing for a match
  if (head)
  {
    //Check if the passed in hand number is valid.
    if (hand_num >= 0 && hand_num < num_of_hands)
    {
      //Check if the indexed pointer is not NULL before traversing.
      if (head[hand_num])
        is_match = retrieve_list(head[hand_num], from); //Finds a match in list
    }
  }

  return is_match; //Returns whether a match was found
}



//This constant private member function searches for a matching card in a LLL
//based on passed in information. It takes a pointer to the 'd_node' class type
//and a constant 'defend' object, passed in as arguments and returns a bool
//value.
bool d_hand::retrieve_list(d_node * head, const defend & from) const
{
  //Check if the pointer is NULL.
  if (!head)
    return false; //The list is empty or has been traversed with no match found

  //Check if a match is found.
  if(head->compare(from))
    return true; //Returns a successful match

  return retrieve_list(head->go_next(), from); //Go to the next node
}



//This member function removes the current node in an ARR. It takes an 'defend'
//object, to copy to, and an integer to be the hand number, passed in as 
//arguments and returns a bool value.
bool d_hand::remove(defend & copy, int hand_num)
{
  //Check if the array is NULL.
  if (!head)
    return false; //Returns a failure of the operation

  //Check if the indexed list is NULL.
  if (!head[hand_num])
    return false; //Returns a failure of the operation

  head[hand_num]->copy_to(copy);

  //If there is only one node left in the list, deallocate the memory and set it
  //to NULL.
  if (!head[hand_num]->go_next())
  {
    delete head[hand_num];
    head[hand_num] = NULL;
  }

  //Otherwise, hold onto the next node, deallocate it and reconnect.
  else
  {
    d_node * hold = head[hand_num]->go_next();
    delete head[hand_num];
    head[hand_num] = hold;
  }

  return true; //One node successfully removed
}



//This constant member function displays the current card in a specific hand. It
//takes an integer type, to be the hand number, passed in as an argument and has 
//a void return type.
void d_hand::display(int hand_num) const
{
  //Check if the array is not NULL.
  if (head)
  {
    //Check that the passed in argument is valid.
    if (hand_num >= 0 && hand_num < num_of_hands)
    {
      //Check that the indexed pointer of the array is not NULL.
      if (head[hand_num])
        head[hand_num]->display();
    }
  }

  return;
}



//This constant member function acts as a wrapper to display every card in a 
//specific hand. It takes an integer type, to be the hand number, passed in as
//an argument returns an integer type to be the number of cards displayed.
int d_hand::display_all(int hand_num) const
{
  //Variable defintions
  int count = 0; //To be the number of cards displayed

  //Check if the array is NULL.
  if (!head)
    return 0; //Returns a failure of the operation

  //Check that the passed in argument is valid.
  if (hand_num >= 0 && hand_num < num_of_hands)
  {
    //Check if the index pointer of the array is NULL.
    if (head[hand_num])
    {
      //Check which hand is going to be displayed.
      if (hand_num == 0)
        std::cout << "Player 1's hand:\n" << std::endl;
      else if (hand_num == 1)
        std::cout << "Player 1's played cards:\n" << std::endl;
      else if (hand_num == 2)
        std::cout << "Player 2's hand:\n" << std::endl;
      else if (hand_num == 3)
        std::cout << "Player 2's played cards:\n" << std::endl;
      else
        std::cout << "All played cards:\n" << std::endl;

      //Display the hand and count how many cards are displayed.
      count = display_list(head[hand_num]);
    }
  }

  return count; //Returns the number of cards displayed
}



//This constant private member function displays all the data in a LLL. It takes
//a pointer to the 'd_node' class type passed in as an argument and returns an
//integer to be the number of cards displayed.
int d_hand::display_list(d_node * head) const
{
  //Check if the list is empty.
  if (!head)
    return 0; //Returns the end of the recursion or a failure of the operation

  head->display(); //Displays the contents of the current node

  return 1 + display_list(head->go_next()); //Counts and goes to the next node
}



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~ S P E L L _ H A N D ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//This default constructor sets the size of the ARR and sets each indexed
//pointer to it's zero equivalent value. It takes a default integer type, to be
//the array size, passed in as an argument and returns nothing.
s_hand::s_hand(int size): num_of_hands(size)
{
  //Create an empty ARR recursively.
  create_arr();
}



//This member function acts as a wrapper function to create an empty ARR,
//setting all the indexed pointers within the array to NULL. It takes no
//arguments and has a void return type.
void s_hand::create_arr()
{
  //Variable definitions
  int index = 0; //To be index of array

  //Allocate a new ARR with the size of the class' data member.
  head = new s_node * [num_of_hands];

  create_arr(index); //Recursively make all indices point to NULL

  return;
}



//This private member function creates an empty ARR, setting all the indexed
//pointers within the array to NULL. It takes an integer type, to be the index 
//of the array, passed in as an argument and has a void return type.
void s_hand::create_arr(int & index)
{
  //If the index is equal to the size of the array, traversal has completed.
  if (index == num_of_hands)
    return;

  head[index] = NULL;
  ++index;

  create_arr(index); //Go to next index

  return;
}



//This copy constructor copies an 's_hand' object to this class' object by 
//calling its copy_all member function. It takes a constant 's_hand' object 
//passed in as an argument and returns nothing.
s_hand::s_hand(const s_hand & from): pile(from)
{
  //Check if passed in object's ARR is not NULL before copying its data.
  //Otherwise set this object's data to its zero equivalent values.
  if (from.head)
    num_of_cards = copy_all(from);
  else
  {
    head = NULL;
    num_of_hands = 0;
  }
}



//This member function acts as a wrapper function to copy all the data from an
//'s_hand' object. It takes a constant 's_hand' object passed in as an argument
//and returns an integer type, to be the total number of discarded cards.
int s_hand::copy_all(const s_hand & from)
{
  //Variable definitions
  int index = 0; //To be index of the ARR

  //Check if the passed in object is valid.
  if (!from.head)
    return 0;

  //Check if this object's ARR has any data already and deallocate all the 
  //memory.
  if (head)
    remove_all();

  num_of_hands = from.num_of_hands;

  //Allocate a new array of pointers to the size of the passed in ARR.
  head = new s_node * [num_of_hands];

  //Set the ARR, with all indexed pointers set to NULL.
  create_arr(index);

  index = 0; //Reset the index

  return copy_all(from.head, index); //Calls the recursive array function
}



//This private member function copies all the data from an existing ARR to this 
//class' ARR. It take a pointer to a pointer to the 's_node' class type, and an 
//integer type, to be the index of the ARR, passed in as arguments and returns 
//an integer to be the total number of discarded cards.
int s_hand::copy_all(s_node ** src, int & index)
{
  //Variable definitions
  int count = 0;

  //Check if the destination's array's index is at the end of the array. Copy
  //the last indexed information and return out of the function.
  if (index == (num_of_hands - 1))
  {
    //Check if the source's indexed pointer is NULL.
    if (!src[index])
      return 0; //Returns zero cards copied at end of traversal

    //Return the count of the last indexed list.
    return count = copy_list(head[index], src[index]);
  }

  //Check if the source's indexed pointer is not NULL.
  if (src[index])
    count = copy_list(head[index], src[index]); //Holds a count of the copied cards

  ++index;  //Increment to the next index of the array

  return copy_all(src, index); //Go to the next index of the array
}



//This private member function copies all the data from an existing LLL to this 
//class' LLL. It takes two pointers to the 's_node' class type, one of which is 
//passed by reference, as arguments and returns an integer to be the number of 
//cards copied.
int s_hand::copy_list(s_node * & dest, s_node * src)
{
  //Check if the source data to be copied is NULL. Otherwise, allocate a new
  //node to the destination list.
  if (!src)
  {
    dest = NULL;
    return 0; //Returns the end of this function, whether successful or not
  }

  dest = new s_node(*src);
  
  return 1 + copy_list(dest->go_next(), src->go_next()); //Go to the next node
}



//This destructor deallocates any memory in the ARR by calling the remove_all
//member function. It takes no arguments and returns nothing.
s_hand::~s_hand()
{
  //Check if the ARR has memory to delete.
  if (head)
    remove_all();

  num_of_hands = 0;
}



//This member function acts a wrapper function to remove any and all allocated
//memory in the ARR. It takes no arguments and has a void return type.
void s_hand::remove_all()
{
  //Variable definitions
  int index = 0; //To be index of array

  //Check if there is anything to remove.
  if (!head)
    return;

  remove_all(index); //Calls the function recursively

  //After all information has been remvoed. Deallocate the array's memory and
  //set to NULL.
  delete [] head;
  head = NULL;

  return;
}



//This private member function manages the removal of a list within each index 
//of the ARR. It calls a recursive removal of a Linear Linked List within the 
//index before moving onto the next index. It takes an integer type, to be the 
//ARR index, passed in as an argument and has a void return type.
void s_hand::remove_all(int & index)
{
  //Check if the index is equal to the size of the ARR. If so, the traversal
  //is complete.
  if (index == num_of_hands)
    return;
  
  //Check if the indexed pointer is not NULL.
  if (head[index])
    remove_list(head[index]); //Removes the Linear Linked List at this index

  ++index;

  return remove_all(index); //Call the function recursively
}



//This member function acts as a wrapper function to remove the discarded pile
//from the hand. It takes a 's_deck' object, to copy to, passed in as an 
//argument and returns a bool value.
bool s_hand::remove_discarded(s_deck & add_to)
{
  //Variable definitions
  int index = 0; //To be the index of the array
  bool copied_over = false; //To be whether the data was removed and copied

  index = num_of_hands - 1; //Index of array to deallocate a list

  //Check if the array is NULL.
  if (!head)
    return false; //Returns a failure of the operation

  //Check if the discarded list is NULL.
  if (!head[index])
    return false; //Returns a failure of the operation

  //Check that the deck getting the discarded cards is empty before copying to 
  //it
  if (add_to.is_empty())
    copied_over = remove_discarded(head[index], add_to); //Removes and copies


  return copied_over; //The list has been removed and copied over to a deck
}



//This private member function manages the removal of a Linear Linked List by 
//calling itself recursively and it copies its data to an empty deck. It takes 
//a pointer to the 's_node' class type and a 's_deck' object, to copy to, as an 
//arguments and returns a bool value.
bool s_hand::remove_discarded(s_node * & head, s_deck & add_to)
{
  //Variable definitions
  bool copied_over = false; //To be whether the data was deleted and copied over

  //Check if there is anything to remove.
  if (!head)
    return copied_over;

  if (!add_to.insert(*head))
    return copied_over;

  //Check if it is the last node of the list.
  if (!head->go_next())
  {
    delete head;
    head = NULL;
  }

  //Otherwise, remove the node and reattach.
  else
  {
    s_node * hold = head->go_next();
    delete head;
    head = hold;
  }

  copied_over = true;

  return copied_over += remove_discarded(head, add_to); //Go to the next node
}



//This private member function manages the removal of a Linear Linked List by 
//calling itself recursively. It takes a pointer to the 's_node' class type as 
//an arguments and has a void return type.
void s_hand::remove_list(s_node * & head)
{
  //Check if there is anything to remove.
  if (!head)
    return;

  //Check if it is the last node of the list.
  if (!head->go_next())
  {
    delete head;
    head = NULL;
  }

  //Otherwise, remove the node and reattach.
  else
  {
    s_node * hold = head->go_next();
    delete head;
    head = hold;
  }

  remove_list(head); //Go to the next node to remove

  return;
}



//This member function insets a card into a specific hand of this class' ARR. It
//takes a constant 'spell' object, to the be the inserted card, and an integer
//type, to be the ARR's index to add the card, as arguments and returns an
//integer type, to represent a success or failure of the operation.
int s_hand::insert(const spell & from, int hand_num)
{
  //Check if the hand number for the card to be inserted is valid.
  if (hand_num >= 0 && hand_num < num_of_hands)
  {
    if (!head)
      create_arr();

    s_node * temp = new s_node;

    //Check if newly allocated node copies the passed in object successfully.
    if(temp->copy(from))
    {
      //Check if the indexed pointer is NULL. Otherwise insert it at the
      //beginning of the list.
      if (!head[hand_num])
        head[hand_num] = temp;
      else
      {
        temp->set_next(head[hand_num]);
        head[hand_num] = temp;
      }

      return 1; //Returns a success of the operation.
    }

    //The operation was a failure. Deallocate the newly allocated node and set
    //it to NULL.
    else
    {
      //Make sure there is something to delete before deallocating the temporary
      //pointer.
      if (temp)
      {
        delete temp;
        temp = NULL;
      }
    }
  }

  return 0; //Returns a failure of the operation
}



//This constant member function acts as a wrapper function to search and find
//a matching card based on the passed in information. It takes a constant
//'spell' object and an integer type, to be the hand number to look in, passed
//as arguments and returns a bool value.
bool s_hand::retrieve(const spell & from, int hand_num) const
{
  //Variable defintions
  bool is_match = false; //To check whether a match was found

  //Check if the ARR is NULL before traversing for a match
  if (head)
  {
    //Check if the passed in hand number is valid.
    if (hand_num >= 0 && hand_num < num_of_hands)
    {
      //Check if the indexed pointer is not NULL before traversing.
      if (head[hand_num])
        is_match = retrieve_list(head[hand_num], from); //Finds a match in list
    }
  }

  return is_match; //Returns whether a match was found
}



//This constant private member function searches for a matching card in a LLL
//based on passed in information. It takes a pointer to the 's_node' class type
//and a constant 'spell' object, passed in as arguments and returns a bool
//value.
bool s_hand::retrieve_list(s_node * head, const spell & from) const
{
  //Check if the pointer is NULL.
  if (!head)
    return false; //The list is empty or has been traversed with no match found

  //Check if a match is found.
  if(head->compare(from))
    return true; //Returns a successful match

  return retrieve_list(head->go_next(), from); //Go to the next node
}



//This member function removes the current node in an ARR. It takes an 'spell'
//object, to copy to, and an integer to be the hand number, passed in as 
//arguments and returns a bool value.
bool s_hand::remove(spell & copy, int hand_num)
{
  //Check if the array is NULL.
  if (!head)
    return false; //Returns a failure of the operation

  //Check if the indexed list is NULL.
  if (!head[hand_num])
    return false; //Returns a failure of the operation

  head[hand_num]->copy_to(copy);

  //If there is only one node left in the list, deallocate the memory and set it
  //to NULL.
  if (!head[hand_num]->go_next())
  {
    delete head[hand_num];
    head[hand_num] = NULL;
  }

  //Otherwise, hold onto the next node, deallocate it and reconnect.
  else
  {
    s_node * hold = head[hand_num]->go_next();
    delete head[hand_num];
    head[hand_num] = hold;
  }

  return true; //One node successfully removed
}



//This constant member function displays the current card in a specific hand. It
//takes an integer type, to be the hand number, passed in as an argument and has 
//a void return type.
void s_hand::display(int hand_num) const
{
  //Check if the array is not NULL.
  if (head)
  {
    //Check that the passed in argument is valid.
    if (hand_num >= 0 && hand_num < num_of_hands)
    {
      //Check that the indexed pointer of the array is not NULL.
      if (head[hand_num])
        head[hand_num]->display();
    }
  }

  return;
}



//This constant member function acts as a wrapper to display every card in a 
//specific hand. It takes an integer type, to be the hand number, passed in as
//an argument returns an integer type to be the number of cards displayed.
int s_hand::display_all(int hand_num) const
{
  //Variable defintions
  int count = 0; //To be the number of cards displayed

  //Check if the array is NULL.
  if (!head)
    return 0; //Returns a failure of the operation

  //Check that the passed in argument is valid.
  if (hand_num >= 0 && hand_num < num_of_hands)
  {
    //Check if the index pointer of the array is NULL.
    if (head[hand_num])
    {
      //Check which hand is going to be displayed.
      if (hand_num == 0)
        std::cout << "Player 1's hand:\n" << std::endl;
      else if (hand_num == 1)
        std::cout << "Player 1's played cards:\n" << std::endl;
      else if (hand_num == 2)
        std::cout << "Player 2's hand:\n" << std::endl;
      else if (hand_num == 3)
        std::cout << "Player 2's played cards:\n" << std::endl;
      else
        std::cout << "All played cards:\n" << std::endl;

      //Display the hand and count how many cards are displayed.
      count = display_list(head[hand_num]);
    }
  }

  return count; //Returns the number of cards displayed
}



//This constant private member function displays all the data in a LLL. It takes
//a pointer to the 's_node' class type passed in as an argument and returns an
//integer to be the number of cards displayed.
int s_hand::display_list(s_node * head) const
{
  //Check if the list is empty.
  if (!head)
    return 0; //Returns the end of the recursion or a failure of the operation

  head->display(); //Displays the contents of the current node

  return 1 + display_list(head->go_next()); //Counts and goes to the next node
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~



