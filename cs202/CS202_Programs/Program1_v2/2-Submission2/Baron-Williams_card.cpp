#include "Baron-Williams_card.h"

// *****************************************************************************
// Program 1
// Author: Connor Baron-Williams
// Due Date: January 26, 2022
// Course: CS202 Programming Systems
// Filename: Baron-Williams_card.cpp
// *****************************************************************************
// This file contains the implementation of the member functions in the 'card', 
// 'action', 'spell', and 'defend' classes, all with the purpose to add, 
// manipulate, display, and remove objects of the class types listed. These
// member function jobs allow for the management of one card object to be used 
// in a card game, with a specific focus on the derived class objects ('action',
// 'spell', or 'defend' card object. With the 'card' class being a base class to 
// the other three classes, its purpose is maintain the default card information
// as well as the single inheritance hierarchy structure. Other than maintaining
// the creation, manipulation, and removal of one card type object, member
// functions also allow for gameplay, including attacking an opponent
// ('action'), defending oneself ('defend'), and enhancement of a 'defend' or 
// 'action' card's power. The 'card' class and 'action' class deal with dynamic
// memory and take extra measures to deallocate data when finished. Otherwise,
// there is no dynamic memory used in the remaining class' member functions.
// *****************************************************************************



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~ C A R D _ C L A S S ~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//This default constructor sets the data members to their zero equivalent
//values in an inititialization list. It takes no arguments and returns nothing.
card::card(): card_num(0), a_type(NULL)
{}



//This constructor takes arguments passed in and copies them to the data
//members. It takes an integer type, to be the card number, and a constant 
//pointer to a char type, to be the card's "environment" type, passed in as
//arguments and returns nothing.
card::card(int num, const char * type)
{
  //Check if passed in data types are greater than zero, not NULL, and that the
  //pointer to the char type is the same as one of the "environment" types 
  //before copying the data to the data members. Otherwise, set the data members 
  //to their zero equivalent values.
  if (type && num > 0 && (!strcmp(type, "Forest") || !strcmp(type, "Water") || 
                          !strcmp(type, "Fire") || !strcmp(type, "Desert")))
  {
    card_num = num;

    a_type = new char[strlen(type) + 1];
    strcpy(a_type, type);
  }
  else
  {
    card_num = 0;
    a_type = NULL;
  }
}



//This copy constructor copies a passed in constant 'card' object and copies
//its data members to this object's data members. It returns nothing.
card::card(const card & from)
{
  //Check if passed in data types are greater than zero, not NULL, and that the
  //pointer to the char type is the same as one of the "environment" types 
  //before copying the data to the data members. Otherwise, set the data members 
  //to their zero equivalent values.
  if (from.a_type && from.card_num > 0 && (!strcmp(from.a_type, "Forest") || 
      !strcmp(from.a_type, "Water") || !strcmp(from.a_type, "Fire") || 
      !strcmp(from.a_type, "Desert")))
  {
    card_num = from.card_num;

    a_type = new char[strlen(from.a_type) + 1];
    strcpy(a_type, from.a_type);
  }
  else
  {
    card_num = 0;
    a_type = NULL;
  }
}



//This destructor resets the data members to their zero equivalent values. It 
//takes no arguments and returns nothing.
card::~card()
{
  card_num = 0;

  if (a_type)
  {
    delete [] a_type;
    a_type = NULL;
  }
}



// This member function allows the user to change a card, giving it its new
// data member information. It takes an integer type, to be the card number, and 
// a constant pointer to a char type, to be the "environment" card type (Forest, 
// Water, Fire, and Desert are the only options), as arguments and returns the 
// card number integer. Otherwise, it returns 0, indicating a failure of the
// operation.
int card::change(int num, const char * type)
{
  //Check if the passed in data type is not NULL and that it is the same as any
  //one of the required "environment" card types before adding it to the data
  //member.
  if (type && num > 0 && (!strcmp(type, "Forest") || !strcmp(type, "Water") || 
                          !strcmp(type, "Fire") || !strcmp(type, "Desert")))
  {
    //If the data member is not NULL deallocate the member and set to NULL
    //before copying the passed in data to it.
    if (a_type)
    {
      delete [] a_type;
      a_type = NULL;
    }

    a_type = new char[strlen(type) + 1];
    strcpy(a_type, type);

    card_num = num;

    return card_num; //Returns the card number and a success of the operation
  }

  return 0; //Failure of the operation
}



//This member function allows the user to copy a 'card' object to this 'card'
//object. It takes a constant card object passed in as an argument and returns
//the card number integer. Otherwise, it returns 0, indicating a failure of the
//operation.
int card::copy(const card & from)
{
  return change(from.card_num, from.a_type);
}



//This constant member function checks to see if an exact match is found,
//searching by a 'card' object. It takes a constant 'card' object, to match
//with this object's card number and "environment" type, passed in as an
//argument and returns a bool value.
bool card::find_card(const card & from) const
{
  //Check if the passed in object's pointer to a char type is not NULL, that it
  //matches the respective data member, and that its card number matches this
  //object's card number before returning true.
  if (a_type && from.a_type && card_num == from.card_num &&
      !strcmp(a_type, from.a_type))
    return true;

  return false; //A match was not found
}



//This member function prompts and reads in the users inputted card number and
//"environment" card type to be added to this object. It is using namespace std,
//locally, takes no arguments and has a void return type.
void card::read() 
{ 
  using namespace std;

  //Variable definitions
  char temp[SIZE]; //To be temporary array of characters

  //Deallocate memory if it is not NULL already.
  if (a_type)
  {
    delete [] a_type;
    a_type = NULL;
  }

  //Do while loop until the user enters a card number greater than zero.
  do
  {
    cout << "Enter the card number (greater than zero): ";
    cin >> card_num;
    cin.ignore(100, '\n');

    if (card_num < 1)
    {
      cout << "You did not enter a valid card number. Please try again."
           << endl << endl;
    }

  } while (card_num < 1);

  //Do while loop until the user enters a valid "environment" type card,
  //matching one of the required "environment" types.
  do
  {
    cout << "\nEnter if it is a Forest, Fire, Water, or Desert card: ";
    cin.get(temp, SIZE, '\n');
    cin.ignore(100, '\n');

    if (strcmp(temp, "Forest") && strcmp(temp, "Fire") &&
        strcmp(temp, "Water") && strcmp(temp, "Desert"))
    {
      cout << "You did not enter a valid type. Please try again." 
           << endl << endl;
    }

  } while (strcmp(temp, "Forest") && strcmp(temp, "Fire") && 
           strcmp(temp, "Water") && strcmp(temp, "Desert"));

  a_type = new char[strlen(temp) + 1];
  strcpy(a_type, temp);

  return;
}



//This constant member function displays all the data relating to the 'card' 
//class. It is using the namespace std locally, takes no arguments, and has a
//void return type.
void card::display() const 
{ 
  using namespace std;

  //Check if the data members have information before attempting to display
  //them.
  if (!card_num && !a_type)
    cout << "This is a blank card!" << endl << endl;
  else
  {
    cout << "\n>>>--------------------------<<<\n" 
         << " Card #" << card_num << "\n "
         << a_type << " Card" << endl << endl;
  }

  return;
} 



//This member function removes the data by setting the data members to their
//zero equivalent values. It takes no arguments and returns a bool value.
bool card::remove() 
{
  card_num = 0;

  //Check to see if there is anything to remove before deallocating it.
  if (a_type)
  {
    delete [] a_type;
    a_type = NULL;
   
    return true;
  }

  return false; //There is nothing to deallocate.
}



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~ A C T I O N _ C L A S S ~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//This default constructor sets the data members to their zero equivalents in an
//initialization list. It takes no arguments and returns nothing.
action::action(): damage_points(0), a_weapon(NULL)
{}



//This constructor sets the data members to the passed in argument list in an
//initialization list. It takes two integer types, to be the base class' card
//number and this class' damage points, and two constant pointers to char types,
//to be the base class' "environment" type and this class' weapon type, passed
//in as arguments and returns nothing.
action::action(int num, const char * a_type, int damage,
               const char * weapon): card(num, a_type)
{
  //Check that the passed in arguments relating to the data members are valid
  //before copying them. Otherwise, set this class' data members to their zero 
  //equivalent values.
  if (weapon && damage < 0 && num > 0 && a_type)
  {
    damage_points = damage;

    a_weapon = new char[strlen(weapon) + 1];
    strcpy(a_weapon, weapon);
  }
  else
  {
    damage_points = 0;
    a_weapon = NULL;
  }
}



//This copy constructor copies an object to this class' data members with the 
//use of an initialization list. It takes a constant 'action' object passed in
//as an argument and returns nothing.
action::action(const action & from): card(from)
{
  //Check that the passed in arguments relating to the data members are valid
  //before copying them. Otherwise, set the data members to their zero 
  //equivalent values.
  if (from.a_weapon && from.damage_points < 0)
  {
    damage_points = from.damage_points;

    a_weapon = new char[strlen(from.a_weapon) + 1];
    strcpy(a_weapon, from.a_weapon);
  }
  else
  {
    damage_points = 0;
    a_weapon = NULL;
  }
}



//This destructor sets the data members back to the zero equivalent values. It
//takes no arguments and returns nothing.
action::~action()
{
  damage_points = 0;

  //Check that the data member is not NULL before deallocating memory.
  if (a_weapon)
  {
    delete [] a_weapon;
    a_weapon = NULL;
  }
}



//This member function adds all information relating to the base and derived 
//data members. It takes two integer types, to be become the card number and 
//damage points, and two constant pointers to char types, to be the 
//"environment" card type and weapon type, as arguments and returns the card
//number integer if the operation is successful.
int action::add(int num, const char * type, int damage, const char * weapon)
{
  //Check that the base class gets its data members added before moving on to
  //add information to this class.
  if (change(num, type))
  {
    //Check that the passed in data is valid before adding any data to this
    //class.
    if (weapon && damage < 0)
    {
      damage_points = damage;

      //Check if data member is not NULL. Otherwise, deallocate its memory.
      if (a_weapon)
      {
        delete [] a_weapon;
        a_weapon = NULL;
      }

      a_weapon = new char[strlen(weapon) + 1];
      strcpy(a_weapon, weapon);

      return card_num; //Returns the card number and a successful operation
    }
  }
  
  return 0; //Returns a failure of the operation
}



//This constant member function checks for an exact 'action' card match. It
//takes a constant 'action' object passed in as an argument and returns a
//bool value.
bool action::compare(const action & from) const
{
  //Variable definitions
  bool is_match = false; //To be whether a match is found

  //Check if the data member and the passed in object's data members are
  //valid as well as the same before checking if the object also matches
  //the base class' data members.
  if (a_weapon && from.a_weapon && damage_points == from.damage_points && 
      !strcmp(a_weapon, from.a_weapon))
    is_match = find_card(from); //Checks for base data member match

  return is_match; //Returns whether it was an exact match
}



//This member function copies an object to this class' object. It takes a 
//constant 'action' object passed in as an argument and returns a card
//number integer for a successful operation.
int action::copy(const action & from)
{
  return add(from.card_num, from.a_type, from.damage_points, from.a_weapon);
}



//This constant member function displays an attack message and returns the 
//damage points as an integer type acting as an attack. It takes no arguments.
int action::attack() const
{
  //Check if the damage points and weapon type are set before attacking.
  if (damage_points < 0 && a_weapon)
  {
    std::cout << "An action card has been played!"
              << "\nIt attacks with its " << a_weapon << "!"
              << "\nDamage cost: " << (-1 * damage_points) << "!" 
              << std::endl << std::endl;

    return damage_points; //Returns the damage points
  }

  std::cout << "You can't play that card." << std::endl << std::endl;
  return 0; //Returns a failure of the operation
}



//This constant member function displays an attack message and returns the 
//damage points doubled as an integer type acting as an extreme attack. It takes 
//no arguments.
int action::double_attack() const
{
  //Check if the damage points, weapon type, and base class' "environment" type 
  //are set before attacking.
  if (damage_points < 0 && a_weapon && a_type)
  {
    std::cout << "An action card has been played!"
              << "\nThe " << a_weapon << " suddenly calls upon its " << a_type
              << "\nnature and attacks with double the strength!"
              << "\nDamage cost: " << (-2 * damage_points) << "!" 
              << std::endl << std::endl;

    return (2 * damage_points); //Returns the damage points doubled
  }

  std::cout << "You can't play that card." << std::endl << std::endl;
  return 0; //Returns a failure of the operation
}



//This constant member function displays an attack message and returns the 
//damage points halved as an integer type acting as a weak attack. It takes 
//no arguments.
int action::throw_weapon() const
{
  //Check if the damage points and weapon type are set before attacking.
  if (damage_points < 0 && a_weapon)
  {
    std::cout << "An action card has been played!"
              << "\nWhat's this?! The " << a_weapon << " gets thrown with "
              << "\ngreat accuracy but with half the strength."
              << "\nDamage cost: " << (damage_points / -1) << "..." 
              << std::endl << std::endl;

    return (damage_points / 2); //Returns the damage points halved
  }

  std::cout << "You can't play that card." << std::endl << std::endl;
  return 0; //Returns a failure of the operation
}



//This constant member function returns the amount of damage points this class'
//object has. It takes no arguments and returns an integer.
int action::power() const
{
  return damage_points;
}



//This member function prompts and reads in the user inputted data for the base 
//class' information and then this class' information. It is using namespace
//std, takes no arguments, and has a void return type.
void action::read()
{
  using namespace std;

  //Variable definitions
  char temp[SIZE]; //To be temporary array of characters

  card::read(); //Read in the default card information.

  //Check that the data member is not NULL. Otherwise deallocate its memory.
  if (a_weapon)
  {
    delete [] a_weapon;
    a_weapon = NULL;
  }

  cout << "\nEnter the action card's weapon type: ";
  cin.get(temp, SIZE, '\n');
  cin.ignore(100, '\n');

  a_weapon = new char[strlen(temp) + 1];
  strcpy(a_weapon, temp);

  //Do while loop until the user enters a damage point as a negative number.
  do
  {
    cout << "\nEnter the weapon's damage cost as a negative number: ";
    cin >> damage_points;
    cin.ignore(100, '\n');

    if (damage_points > -1)
    {
      cout << "You did not enter a valid damage cost. Please try again."
           << endl << endl;
    }
  } while (damage_points > -1);

  cout << "CARD ADDED!!!" << endl << endl;

  return;
}



//This constant member function displays all the data members of this class and
//its base class. It is using namespace std, takes no arguments and has a void 
//return type.
void action::display() const
{
  using namespace std;

  //Check that the base and derived class have all the necessary information to 
  //display before displaying any data.
  if (a_type && card_num > 0 && a_weapon && damage_points < 0)
  {
    card::display(); //Displays default card information first

    cout << " TYPE: ACTION\n"
         << " Weapon type: " << a_weapon
         << "\n Damage points: " << damage_points << " cost"
         << "\n<<<-------------------------->>>\n"
         << endl;
  }
  else
    cout << "This card is empty!" << endl << endl;

  return;
}



//This member function removes the base class' and this class' data members by
//setting them to their zero equivalent values. It takes no arguments and 
//returns a bool value.
bool action::remove()
{
  damage_points = 0;

  //Check to see if there is anything to remove before deallocating it.
  if (a_weapon)
  {
    delete [] a_weapon;
    a_weapon = NULL;

    //At this point, this should be true no matter what, but it checks that
    //removing the default portion of the card is also a success.
    if (card::remove())
      return true;
  }

  return false; //There is nothing to remove and something is not working
}



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~ D E F E N D _ C L A S S ~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//This default constructor sets the data members to their zero equivalent values
//in an initialization list. It takes no arguments and returns nothing.
defend::defend(): strength_points(0), a_shield("none")
{}



//This constructor sets the data members to the passed in argument list in an
//initialization list. It takes two integer types, to be the base class' card
//number and this class' strength points, a constant pointer to a char type,
//to be the base class' "environment" type, and a constant string, to be this 
//class' shield type, passed in as arguments and returns nothing.
defend::defend(int num, const char * type, int strength, 
               const std::string & shield): card(num, type)
{
  //Check that the passed in arguments relating to the data members are valid
  //before copying them. Otherwise, set this class' data members to their zero 
  //equivalent values.
  if (strength > 0 && num > 0 && a_type)
  {
    strength_points = strength;
    a_shield = shield;
  }
  else
  {
    strength_points = 0;
    a_shield = "none";
  }
}



//This member function adds all information relating to the base and derived 
//data members. It takes two integer types, to be become the card number and 
//strength points, a constant pointer to a char type, to be the "environment" 
//card type, and a constant string, to be the shield type, as arguments and 
//returns the card number integer if the operation is successful.
int defend::add(int num, const char * type, int strength, 
                const std::string & shield)
{
  //Check that the base class gets its data members added before moving on to
  //add information to this class.
  if (change(num, type))
  {
    //Check that the passed in data is valid before adding any data to this
    //class.
    if (strength > 0)
    {
      strength_points = strength;
      a_shield = shield;

      return card_num; //Returns the card number and a successful operation
    }
  }
  
  return 0; //Returns a failure of the operation
}



//This constant member function checks for an exact 'defend' card match. It
//takes a constant 'defend' object passed in as an argument and returns a
//bool value.
bool defend::compare(const defend & from) const
{
  //Variable definitions
  bool is_match = false; //To be whether a match is found

  //Check if the data members and the passed in object's data members are the
  //same before checking if the object also matches the base class' data 
  //members.
  if (strength_points == from.strength_points && a_shield == from.a_shield)
    is_match = find_card(from); //Checks for base data member match

  return is_match; //Returns whether it was an exact match
}



//This member function copies an object to this class' object. It takes a 
//constant 'defend' object passed in as an argument and returns a card
//number integer for a successful operation.
int defend::copy(const defend & from)
{
  return add(from.card_num, from.a_type, from.strength_points, from.a_shield);
}



//This constant member function displays a block message and returns the 
//strength points as an integer type acting as protection. It takes no 
//arguments.
int defend::block() const
{
  //Check if the strength points are set before blocking.
  if (strength_points > 0)
  {
    std::cout << "A defend card has been played!"
              << "\nIt blocks with its " << a_shield << "!"
              << "\nStrength gain: " << strength_points << "!" 
              << std::endl << std::endl;

    return strength_points; //Returns the strength points
  }

  std::cout << "You can't play that card." << std::endl << std::endl;
  return 0; //Returns a failure of the operation
}



//This constant member function displays a defend message and returns the 
//strength points doubled as an integer type acting as stronger shield. It takes 
//no arguments.
int defend::hide() const
{
  //Check if the strength points and base class' "environment" type are set
  //before hiding.
  if (strength_points > 0 && a_type)
  {
    std::cout << "A defend card has been played!" << std::endl;

    //Depending on the card's "environment" type, a different type of hiding
    //occurs.
    if (!strcmp(a_type, "Forest"))
    {
      std::cout << "Roots grow from the ground, attaching to the \n" 
                << a_shield << ", creating an indestructible shelter, ";
    }
    else if (!strcmp(a_type, "Water"))
    {
      std::cout << "The " << a_shield << " creates an instant downpouring of\n"
                << "rain that flashes before your eyes, flooding the senses, ";
    }
    else if (!strcmp(a_type, "Fire"))
    {
      std::cout << "The " << a_shield << " bursts into flames, roaring to \n"
                << "impossible heights, engulfing the skies with terror, ";
    }
    else
    {
      std::cout << "Coarse sand spews from the " << a_shield << " in all\n"
                << "directions, creating gigantic dunes of despair, ";
    } 

    std::cout << "allowing you to hide\nand double your protection!!!"
              << "\nStrength gain: " << (2 * strength_points) << "!" 
              << std::endl << std::endl;

    return (2 * strength_points); //Returns the strength points doubled
  }

  std::cout << "You can't play that card." << std::endl << std::endl;
  return 0; //Returns a failure of the operation
}



//This constant member function displays a defend message and returns a
//quarter of the strength points as an integer type acting as a weak attack with
//no health gain. It takes no arguments.
int defend::push_back() const
{
  //Check if the strength points are set before pushing back.
  if (strength_points > 0)
  {
    std::cout << "A defend card has been played!"
              << "\nIn a desperate attempt, you take the " << a_shield << ",\n"
              << "lounge forward, and push back with all your might, forgoing\n"
              << "any gain to your lifeline, but dealing damage with a\n"
              << "quarter of your strength!"
              << "\nDamage cost: " << (strength_points / -4) << "." 
              << std::endl << std::endl;

    return (strength_points / -4); //Returns the now quartered damage points
  }

  std::cout << "You can't play that card." << std::endl << std::endl;
  return 0; //Returns a failure of the operation
}



//This constant member function returns the amount of strength points this 
//class' object has. It takes no arguments and returns an integer.
int defend::power() const
{
  return strength_points;
}



//This member function prompts and reads in the user inputted data for the base 
//class' information and then this class' information. It is using namespace
//std, takes no arguments, and has a void return type.
void defend::read()
{
  using namespace std;

  card::read(); //Read in the default card information.

  cout << "\nEnter the defend card's shield type: ";
  cin >> a_shield;
  cin.ignore(100, '\n');

  //Do while loop until the user enters a strength point as a positive number.
  do
  {
    cout << "\nEnter the shield's strength gain as a positive number: ";
    cin >> strength_points;
    cin.ignore(100, '\n');

    if (strength_points < 1)
    {
      cout << "You did not enter a valid strength gain. Please try again."
           << endl << endl;
    }
  } while (strength_points < 1);

  cout << "CARD ADDED!!!" << endl << endl;

  return;
}



//This constant member function displays all the data members of this class and
//its base class. It is using namespace std, takes no arguments and has a void 
//return type.
void defend::display() const
{
  using namespace std;

  //Check that the base and derived class have all the necessary information to 
  //display before displaying any data.
  if (a_type && card_num > 0 && strength_points > 0)
  {
    card::display(); //Displays default card information first

    cout << " TYPE: DEFEND\n"
         << " Shield type: " << a_shield
         << "\n Strength points: " << strength_points << " gain"
         << "\n<<<-------------------------->>>\n"
         << endl;
  }
  else
    cout << "This card is empty!" << endl << endl;

  return;
}



//This member function removes the base class' and this class' data members by
//setting them to their zero equivalent values. It takes no arguments and 
//returns a bool value.
bool defend::remove()
{
  strength_points = 0;
  a_shield = "none";

  //Check that removing the default portion of the card is a success.
  if (card::remove())
    return true;

  return false; //There is nothing to remove and something is not working
}



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~ S P E L L _ C L A S S ~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//This default constructor sets the data members to their zero equivalent values
//in an initialization list. It takes no arguments and returns nothing.
spell::spell(): enhancement_factor(0), magic("none")
{}



//This constructor sets the data members to the passed in argument list in an
//initialization list. It takes an integer type, to be the base class' card
//number, a float type, to be this class' enhancement factor, a constant pointer 
//to a char type, to be the base class' "environment" type, and a constant 
//string, to be this class' magic type, passed in as arguments and returns 
//nothing.
spell::spell(int num, const char * type, float factor, 
               const std::string & magic_type): card(num, type)
{
  //Check that the passed in arguments relating to the data members are valid
  //before copying them. Otherwise, set this class' data members to their zero 
  //equivalent values.
  if (factor > 0 && num > 0 && a_type)
  {
    enhancement_factor = factor;
    magic = magic_type;
  }
  else
  {
    enhancement_factor = 0;
    magic = "none";
  }
}



//This member function adds all information relating to the base and derived 
//data members. It takes an integer type, to be the base class' card
//number, a float type, to be this class' enhancement factor, a constant pointer 
//to a char type, to be the base class' "environment" type, and a constant 
//string, to be this class' magic type, passed in as arguments and returns the
//card number integer if the operation is successful.
int spell::add(int num, const char * type, float factor, 
                const std::string & magic_type)
{
  //Check that the base class gets its data members added before moving on to
  //add information to this class.
  if (change(num, type))
  {
    //Check that the passed in data is valid before adding any data to this
    //class.
    if (factor > 0)
    {
      enhancement_factor = factor;
      magic = magic_type;

      return card_num; //Returns the card number and a successful operation
    }
  }
  
  return 0; //Returns a failure of the operation
}



//This constant member function checks for an exact 'spell' card match. It
//takes a constant 'spell' object passed in as an argument and returns a
//bool value.
bool spell::compare(const spell & from) const
{
  //Variable definitions
  bool is_match = false; //To be whether a match is found

  //Check if the data members and the passed in object's data members are the
  //same before checking if the object also matches the base class' data 
  //members.
  if (enhancement_factor == from.enhancement_factor && magic == from.magic)
    is_match = find_card(from); //Checks for base data member match

  return is_match; //Returns whether it was an exact match
}



//This member function copies an object to this class' object. It takes a 
//constant 'spell' object passed in as an argument and returns a card
//number integer for a successful operation.
int spell::copy(const spell & from)
{
  return add(from.card_num, from.a_type, from.enhancement_factor, from.magic);
}



//This constant member function displays a spell message and returns the 
//enhancement factor result as a float type acting as a defense enhancement of
//strength points. It takes a constant 'defend' object passed in as an 
//argument.
float spell::enhance(const defend & from) const
{
  //Variable defintions
  float enhanced = 0; //To be updated strength points
  int defense_power = 0; //To be power of passed in object

  defense_power = from.power();

  //Check if the enhancement factor and defend object are valid before 
  //enhancing.
  if (enhancement_factor > 0 && defense_power > 0)
  {
    enhanced = enhancement_factor * defense_power; //Updated strength points

    std::cout << "A spell card has been played!\n"
              << "The " << a_type << " gods whisper a spell, " << magic << ".\n"
              << ".\n.\n.\nMagically, the defense's strength points are \n"
              << "enhanced by a factor of " << enhancement_factor << "!"
              << "\nUpdated strength gain: " << enhanced << "!" 
              << std::endl << std::endl;

    return enhanced; //Returns updated strength points
  }

  std::cout << "You can't play that card." << std::endl << std::endl;
  return 0; //Returns a failure of the operation
}



//This constant member function displays a spell message and returns the 
//enhancement factor result as a float type acting as an attack diminished of
//damage points. It takes a constant 'action' object passed in as an 
//argument.
float spell::diminish(const action & from) const
{
  //Variable defintions
  float diminished = 0; //To be updated damage points
  int attack_power = 0; //To be power of passed in object

  attack_power = from.power();

  //Check if the enhancement factor and action object are valid before 
  //enhancing.
  if (enhancement_factor > 0 && attack_power < 0)
  {
    diminished = attack_power / enhancement_factor; //Updated damage points

    std::cout << "A spell card has been played!\n"
              << "The " << a_type << " gods scream a spell, " << magic << ".\n"
              << ".\n.\n.\nMagically, the attacks's damage points are \n"
              << "diminished by a factor of " << enhancement_factor << "!"
              << "\nUpdated damage cost: " << (-1 * diminished) << "..." 
              << std::endl << std::endl;

    return diminished; //Returns updated damage points
  }

  std::cout << "You can't play that card." << std::endl << std::endl;
  return 0; //Returns a failure of the operation
}



//This constant member function displays a spell message and returns the 
//enhancement factor result as a float type acting as an attack enhancement of
//damage points to be redirected. It takes a constant 'action' object passed in 
//as an argument.
float spell::redirect(const action & from) const
{
  //Variable defintions
  float enhanced = 0; //To be updated damage points
  int attack_power = 0; //To be power of passed in object

  attack_power = from.power();

  //Check if the enhancement factor and action object are valid before enhancing.
  if (enhancement_factor > 0 && attack_power < 0)
  {
    enhanced = enhancement_factor * attack_power; //Updated damage points

    std::cout << "A spell card has been played!\n"
              << "The " << a_type << " gods chant a spell, " << magic << ".\n"
              << ".\n.\n.\nDisorientation! Confusion! The attack's damage\n"
              << "points are enhanced by a factor of " 
              << enhancement_factor << " but also redirected!!!"
              << "\nUpdated and redirected damage cost: " 
              << (-1 * enhanced) << "!" 
              << std::endl << std::endl;

    return enhanced; //Returns updated damage points
  }

  std::cout << "You can't play that card." << std::endl << std::endl;
  return 0; //Returns a failure of the operation
}



//This member function prompts and reads in the user inputted data for the base 
//class' information and then this class' information. It is using namespace
//std, takes no arguments, and has a void return type.
void spell::read()
{
  using namespace std;

  card::read(); //Read in the default card information.

  cout << "\nEnter the spell card's magic incantation: ";
  cin >> magic;
  cin.ignore(100, '\n');

  //Do while loop until the user enters an enhancment factor as a positive 
  //decimal number between 0 and 5.
  do
  {
    cout << "Enter the spell's enhancement factor (between 0 and 5): ";
    cin >> enhancement_factor;
    cin.ignore(100, '\n');

    if (enhancement_factor <= 0 || enhancement_factor > 5)
    {
      cout << "You did not enter a valid enhancement factor. Please try again."
           << endl << endl;
    }
  } while (enhancement_factor <= 0 || enhancement_factor > 5);

  cout << "CARD ADDED!!!" << endl << endl;

  return;
}



//This constant member function displays all the data members of this class and
//its base class. It is using namespace std, takes no arguments and has a void 
//return type.
void spell::display() const
{
  using namespace std;

  //Check that the base and derived class have all the necessary information to 
  //display before displaying any data.
  if (a_type && card_num > 0 && enhancement_factor > 0 && 
      enhancement_factor <= 5)
  {
    card::display(); //Displays default card information first

    cout << " TYPE: SPELL\n"
         << " Spell incantation: " << magic
         << "\n Enhancement factor: " << enhancement_factor << "x"
         << "\n<<<-------------------------->>>\n"
         << endl;
  }
  else
    cout << "This card is empty!" << endl << endl;

  return;
}



//This member function removes the base class' and this class' data members by
//setting them to their zero equivalent values. It takes no arguments and 
//returns a bool value.
bool spell::remove()
{
  enhancement_factor = 0;
  magic = "none";

  //Check that removing the default portion of the card is a success.
  if (card::remove())
    return true;

  return false; //There is nothing to remove and something is not working
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

