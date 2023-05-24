#include "Baron-Williams_athlete.h"

// *****************************************************************************
// Program 3
// Author: Connor Baron-Williams
// Due Date: February 28, 2022
// Course: CS202 Programming Systems
// Filename: Baron-Williams_athlete.cpp
// *****************************************************************************
// This file contains the implementation of the member functions and operator
// overloaders in the 'athlete', 'figure_skate', 'ski_jump', and 'bobsled'
// all with the main purpose to manage specific information about their 
// respective competition type statistics in the Winter Olympics. The class 
// methods allow for reading in, displaying and comparing object information 
// while also being inheritted throughout the single inheritance hierarchy. The 
// operator overloaders allow for adding and subtracting points, assignment, and 
// more specific comparisons but are not completely inheritted. Only the 
// 'athlete' class deals with dynamic memory and takes extra measures to 
// deallocate data when finished and is the only class to require an assignment 
// operator. Otherwise, there is no dynamic memory used in the remaining class' 
// methods.
// *****************************************************************************



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~ A T H L E T E _ C L A S S ~~~~~~~~~~~~~~~~~~~~~~~~~
//
//This default constructor sets the data members to their zero equivalent
//values. It takes no arguments and has no return type.
athlete::athlete(): name(nullptr), country("none"), experience(0), score(0)
{}



//This copy constructor copies an object of the same type. It takes a constant
//athlete object, passed by reference, as an argument and has no return type.
athlete::athlete(const athlete & from)
{
  //Variable definitions
  BAD_INPUT b_input; //Holds any errors to be thrown

  //Check if passed in data is invalid.
  if (!from.name)
  {
    b_input.bad_array = "bad";
    throw b_input;
  }

  name = new char[strlen(from.name) + 1];
  strcpy(name, from.name);

  country = from.country;
  experience = from.experience;
  score = from.score;
}



//This destructor deallocates any allocated memory and sets the data members to
//their zero equivalent values. It takes no arguments and has no return type.
athlete::~athlete()
{
  //Check if any memory is allocated before deallocating.
  if (name)
  {
    delete [] name;
    name = nullptr;
  }

  country = "none";
  experience = 0;
  score = 0;
}



//This method prompts and reads in the appropriate information to be copied to 
//this class' data members. It takes an 'istream' object, passed by reference,
//as an argument and has a void return type.
void athlete::read(std::istream & in)
{
  using namespace std;

  //Variable definitions
  BAD_INPUT b_input; //Holds any errors to be thrown
  char temp[SIZE];   //Temporary array to copy athlete's name
  int length {0};    //Holds the length of an array of characters

  //Get athlete's information (name, country, years of experience, and points
  //scored).
  cout << "Athlete's name: ";
  in.get(temp, SIZE, '\n');
  in.ignore(100, '\n');

  //Check if any memory is allocated and deallocate.
  if (name)
  {
    delete [] name;
    name = nullptr;
  }

  name = new char[strlen(temp) + 1];
  strcpy(name, temp);

  cout << "Country: ";
  getline(in, country);

  length = strlen(name);

  //Make sure the first letter and anything after a space is capitalized for
  //both data members.
  name[0] = toupper(name[0]);

  for (int i = 1; i < length; ++i)
  {
    if (name[i - 1] == ' ')
      name[i] = toupper(name[i]);
  }

  length = country.length();

  country[0] = toupper(country[0]);

  for (int i = 1; i < length; ++i)
  {
    if (country[i - 1] == ' ')
     country[i] = toupper(country[i]);
  }

  //Get experience.
  do
  {
    //Get valid input.
    try
    {
      cout << "Years athlete has competed: ";
      in >> experience;

      //Check that the value is positive and valid.
      if (experience < 0 || in.fail())
      {
        in.clear();
        b_input.bad_int = -1;
        throw b_input;
      }
    }
    
    //Catch any errors to be thrown.
    catch (...)
    {
      cout << "Please a positive whole number." << endl << endl;
      experience = b_input.bad_int;
    }

    in.ignore(100, '\n');

  } while (experience < 0);

  //Get score.
  do
  {
    //Get valid input.
    try
    {
      cout << "Enter the total points scored: ";
      in >> score;

      if (score < 0 || in.fail())
      {
        in.clear();
        b_input.bad_int = -1;
        throw b_input;
      }
    }

    //Catch any errors to be thrown.
    catch (...)
    {
      cout << "Please enter a positive whole number." << endl << endl;
      score = b_input.bad_int;
    }

    in.ignore(100, '\n');

  } while (score < 0);

  return;
}



//This constant method displays the contents of this class' data members. It
//takes an 'ostream' object, passed by reference, as an argument and has a
//void return type.
void athlete::display(std::ostream & out) const
{
  using namespace std;

  //Variable definitions
  BAD_INPUT b_input; //Holds any errors to be thrown

  //Check if the current object is valid.
  if (!name)
  {
    b_input.bad_array = "bad";
    throw b_input;
  }

  out << "Name: " << name 
      << "\nCountry: " << country 
      << "\nExperience: " << experience << " year(s)"
      << "\nScore: " << score << " points" << endl;

  return;
}



//This constant method compares two objects' athlete names and returns whether 
//the current object's name is less than (-1), equal to (0), or greater than (1) 
//the other object. It takes a constant 'athlete' object, passed by reference, 
//as an argument and returns an integer, to be the comparison result.
int athlete::compare(const athlete & from) const
{
  //Variable definitions
  BAD_INPUT b_input; //Holds a bad input error to be thrown

  if (!from.name || !name)
  {
    b_input.bad_array = "bad";
    throw b_input;
  }

  //Returns the name comparison result
  return compare(from.name);

}



//This constant method compares two names and returns whether the current
//object's name is less than (-1), equal to (0), or greater than (1) the other
//name. It takes a pointer to a char as an argument and returns an integer, to 
//be the comparison result.
int athlete::compare(const char * compare) const
{
  //Variable definitions
  int result {0};    //Result of the object comparison
  BAD_INPUT b_input; //Holds a bad input error to be thrown

  //Check if the current object's name or the passed in data is invalid.
  if (!name || !compare)
  {
    b_input.bad_array = "bad";
    throw b_input;
  }

  //If the current name is neither less than nor greater than, then it is
  //equal to the passed in name.
  if (strcmp(name, compare) < 0)
    result = -1; //Less than result
  else if (strcmp(name, compare) > 0)
    result = 1;  //Greater than result

  return result;
}



//This method copies an object of the same type to this class' object. It takes
//a constant 'athlete' object, passed by reference, and has a void return type.
void athlete::copy(const athlete & from)
{
  //Variable definitions
  BAD_INPUT b_input; //Holds any errors to be thrown

  if (!from.name)
  {
    b_input.bad_array = "bad";
    throw b_input;
  }

  //Check for allocated memory in the current object and deallocate.
  if (name)
    delete [] name;

  name = new char[strlen(from.name) + 1];
  strcpy(name, from.name);

  country = from.country;
  experience = from.experience;
  score = from.score;

  return;
}



//This member operator assigns an object of the same type. It takes a constant
//'athlete' object, passed by reference, as an argument and returns a reference
//to an 'athlete' object.
athlete & athlete::operator=(const athlete & player)
{
  //Variable definitions
  BAD_INPUT b_input; //Holds any errors to be thrown

  if (!player.name)
  {
    b_input.bad_array = "bad";
    throw b_input;
  }

  //Check for self assignment.
  if (this == &player)
    return *this;

  //Copy the object
  copy(player);

  return *this;
}



//This operator reads in data specific to an 'athlete' object. It takes an
//'istream' and 'athlete' object, passed by reference, and returns a 
//reference to an 'istream' object.
std::istream & operator>>(std::istream & in, athlete & player)
{
  //Calls read method.
  player.read(in);

  return in;
}



//This operator outputs data specifc to an 'athlete' object. It takes an
//'ostream' and a constant 'athlete' object, passed by reference, as arguments
//and returns a reference to an 'ostream' object.
std::ostream & operator<<(std::ostream & out, const athlete & player)
{
  //Calls display method.
  player.display(out);

  return out;
}



//This operator adds points to the athlete's total score. It takes a constant
//'athlete' object, passed by reference, and an integer as arguments and returns
//an 'athlete' object by value.
athlete operator+(const athlete & player, int points)
{
  //Variable definitions
  BAD_INPUT b_input;    //Holds any errors to be thrown
  athlete temp(player); //Holds temporary object to be returned

  //Check if the passed in object is valid.
  if (!player.name)
  {
    b_input.bad_array = "bad";
    throw b_input;
  }

  temp.score += points;

  return temp;
}



//This operator adds points to the athlete's total score. It takes a constant
//'athlete' object, passed by reference, and an integer as arguments and returns
//an 'athlete' object by value.
athlete operator+(int points, const athlete & player)
{
  //Variable definitions
  BAD_INPUT b_input;    //Holds any errors to be thrown
  athlete temp(player); //Holds temporary object to be returned

  //Check if the passed in object is valid.
  if (!player.name)
  {
    b_input.bad_array = "bad";
    throw b_input;
  }

  temp.score += points;

  return temp;
}



//This operator adds points to the athlete's total score. It takes an integer as
//an argument and returns an 'athlete' object by reference.
athlete & athlete::operator+=(int points)
{
  //Variable definitions
  BAD_INPUT b_input; //Holds any errors to be thrown

  //Check if the passed in object is valid.
  if (!name)
  {
    b_input.bad_array = "bad";
    throw b_input;
  }

  score += points;

  return *this;
}



//This operator subtracts points from the athlete's total score. It takes a 
//constant 'athlete' object, passed by reference, and an integer as arguments 
//and returns an 'athlete' object by value.
athlete operator-(const athlete & player, int points)
{
  //Variable definitions
  BAD_INPUT b_input;    //Holds any errors to be thrown
  athlete temp(player); //Holds temporary object to be returned

  //Check if the passed in object is valid.
  if (!player.name)
  {
    b_input.bad_array = "bad";
    throw b_input;
  }

  temp.score -= points;

  return temp;
}



//This operator subtracts points from the athlete's total score. It takes a 
//constant 'athlete' object, passed by reference, and an integer as arguments 
//and returns an 'athlete' object by value.
athlete operator-(int points, const athlete & player)
{
  //Variable definitions
  BAD_INPUT b_input;    //Holds any errors to be thrown
  athlete temp(player); //Holds temporary object to be returned

  //Check if the passed in object is valid.
  if (!player.name)
  {
    b_input.bad_array = "bad";
    throw b_input;
  }

  temp.score -= points;

  return temp;
}



//This operator subtracts points from the athlete's total score. It takes an 
//integer as an argument and returns an 'athlete' object by reference.
athlete & athlete::operator-=(int points)
{
  //Variable definitions
  BAD_INPUT b_input; //Holds any errors to be thrown

  //Check if the passed in object is valid.
  if (!name)
  {
    b_input.bad_array = "bad";
    throw b_input;
  }

  score -= points;

  return *this;
}



//This operator checks if one athlete's name is less than another. It takes two
//constant 'athlete' objects, passed by reference, as arguments and returns a
//bool value.
bool operator<(const athlete & player1, const athlete & player2)
{
  //Returns if first argument is less than second argument
  return -1 == player1.compare(player2);
}



//This operator checks if one athlete's name is less than another. It takes a
//constant 'athlete' object, passed by reference, and a pointer to a char as 
//arguments and returns a bool value.
bool operator<(const athlete & player, const char * name)
{
  //Returns if first argument is less than second argument
  return -1 == player.compare(name);
}



//This operator checks if one athlete's name is less than another. It takes a
//constant 'athlete' object, passed by reference, and a pointer to a char as 
//arguments and returns a bool value.
bool operator<(const char * name, const athlete & player)
{
  //Returns if second argument is greater than first argument (making the first
  //argument less than).
  return 1 == player.compare(name);
}



//This operator checks if one athlete's name is less than or equal to another. 
//It takes two constant 'athlete' objects, passed by reference, as arguments and
//returns a bool value.
bool operator<=(const athlete & player1, const athlete & player2)
{
  //Returns whether the two objects are the same or the first is less than the
  //second.
  return (player1 == player2 || -1 == player1.compare(player2));
}



//This operator checks if one athlete's name is less than or equal to another. 
//It takes a constant 'athlete' object, passed by reference, and a pointer to a
//char as arguments and returns a bool value.
bool operator<=(const athlete & player, const char * name)
{
  //Returns whether the two names are the same or the first is less than the
  //second.
  return (0 == player.compare(name) || -1 == player.compare(name));
}



//This operator checks if one name is less than or equal to another. It takes a 
//constant 'athlete' object, passed by reference, and a pointer to a char as 
//arguments and returns a bool value.
bool operator<=(const char * name, const athlete & player)
{
  //Returns whether the two names are the same or the second is greater than the
  //first.
  return (0 == player.compare(name) || 1 == player.compare(name));
}



//This operator checks if one athlete's name is greater than another. It takes 
//two constant 'athlete' objects, passed by reference, as arguments and returns 
//a bool value.
bool operator>(const athlete & player1, const athlete & player2)
{
  //Returns if first argument is greater than second argument
  return 1 == player1.compare(player2);
}



//This operator checks if one athlete's name is greater than another. It takes a
//constant 'athlete' object, passed by reference, and a pointer to a char as 
//arguments and returns a bool value.
bool operator>(const athlete & player, const char * name)
{
  //Returns if first argument is greater than second argument
  return 1 == player.compare(name);
}



//This operator checks if one athlete's name is greater than another. It takes a
//constant 'athlete' object, passed by reference, and a pointer to a char as 
//arguments and returns a bool value.
bool operator>(const char * name, const athlete & player)
{
  //Returns if second argument is less than first argument (making the first
  //argument greater than).
  return -1 == player.compare(name);
}



//This operator checks if one athlete's name is greater than or equal to 
//another. It takes two constant 'athlete' objects, passed by reference, as 
//arguments and returns a bool value.
bool operator>=(const athlete & player1, const athlete & player2)
{
  //Returns whether the two objects are the same or the first is greater than 
  //the second.
  return (player1 == player2 || 1 == player1.compare(player2));
}



//This operator checks if one athlete's name is greater than or equal to 
//another. It takes a constant 'athlete' object, passed by reference, and a 
//pointer to a char as arguments and returns a bool value.
bool operator>=(const athlete & player, const char * name)
{
  //Returns whether the two names are the same or the first is greater than the
  //second.
  return (0 == player.compare(name) || 1 == player.compare(name));
}



//This operator checks if one name is greater than or equal to another. It 
//takes a constant 'athlete' object, passed by reference, and a pointer to a 
//char as arguments and returns a bool value.
bool operator>=(const char * name, const athlete & player)
{
  //Returns whether the two names are the same or the second is less than the
  //first.
  return (0 == player.compare(name) || -1 == player.compare(name));
}



//This constant operator checks if the current object's name is equal to 
//another object of the same type. It takes two constant 'athlete' objects, 
//passed by reference, as arguments and returns a bool value.
bool operator==(const athlete & player1, const athlete & player2)
{
  //Returns if the names match.
  return 0 == player1.compare(player2);
}



//This constant operator checks if the current object's name is equal to 
//another object of the same type. It takes a constant 'athlete' object, 
//passed by reference, and a constant pointer to a char as arguments and 
//returns a bool value.
bool operator==(const athlete & player1, const char * name)
{
  //Returns if the names match.
  return 0 == player1.compare(name);
}



//This constant operator checks if the current object's name is equal to 
//another object of the same type. It takes a constant 'athlete' object, 
//passed by reference, and a constant pointer to a char as arguments and 
//returns a bool value.
bool operator==(const char * name, const athlete & player2)
{
  //Returns if the names match.
  return 0 == player2.compare(name);
}



//This constant operator checks if the current object's name is not equal to 
//another object of the same type. It takes two constant 'athlete' objects, 
//passed by reference, as arguments and returns a bool value.
bool operator!=(const athlete & player1, const athlete & player2)
{
  //Returns if the names do not match.
  return !(0 == player1.compare(player2));
}



//This constant operator checks if the current object's name is not equal to 
//another object of the same type. It takes a constant 'athlete' object, 
//passed by reference, and a constant pointer to a char as arguments and 
//returns a bool value.
bool operator!=(const athlete & player1, const char * name)
{
  //Returns if the names do not match.
  return !(0 == player1.compare(name));
}



//This constant operator checks if the current object's name is not equal to 
//another object of the same type. It takes a constant 'athlete' object, 
//passed by reference, and a constant pointer to a char as arguments and 
//returns a bool value.
bool operator!=(const char * name, const athlete & player2)
{
  //Returns if the names match.
  return !(0 == player2.compare(name));
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~ F I G U R E _ S K A T E _ C L A S S ~~~~~~~~~~~~~~~~~~~~
//
//This default constructor sets the data members to their zero equivalent
//values. It takes no arguments and has no return type.
figure_skate::figure_skate(): triple_axels(0), song("none")
{}



//This method prompts and reads in the appropriate information to be copied to 
//this class' data members. It takes an 'istream' object, passed by reference,
//as an argument and has a void return type.
void figure_skate::read(std::istream & in)
{
  using namespace std;
  
  //Variable definitions
  int length {0};    //Hold the length of a string object
  BAD_INPUT b_input; //Holds any errors to be thrown

  //Get figure skating statistics information (number of axels and song choice).
  do
  {
    //Get valid input.
    try
    {
      cout << "Number of triple axels landed: ";
      in >> triple_axels;

      if (triple_axels < 0 || in.fail())
      {
        in.clear();
        b_input.bad_int = -1;
        throw b_input;
      }
    }

    //Catch any errors to be thrown.
    catch (...)
    {
      cout << "Please enter a positive whole number." << endl << endl;
      triple_axels = b_input.bad_int;
    }

    in.ignore(100, '\n');

  } while (triple_axels < 0);

  cout << "Song choice: ";
  getline(in, song);

  length = song.length();

  //Make sure the first letter and anything after a space is capitalized.
  song[0] = toupper(song[0]);

  for (int i = 1; i < length; ++i)
  {
    if (song[i - 1] == ' ')
      song[i] = toupper(song[i]);
  }

  return;
}



//This constant method displays the contents of this class' data members. It
//takes an 'ostream' object, passed by reference, as an argument and has a
//void return type.
void figure_skate::display(std::ostream & out) const
{
  using namespace std;

  //Variable definitions
  BAD_INPUT b_input; //Holds any errors to be thrown

  //Check if the current object is valid.
  if (song == "none")
  {
    b_input.bad_array = "bad";
    throw b_input;
  }

  athlete::display(out); //Calls parent class first

  out << "Number of triple axels landed: " << triple_axels
      << "\nSong choice: " << song << endl << endl;

  return;
}



//This method copies an object of the same type to this class' object. It takes
//a constant 'figure_skate' object, passed by reference, and has a void return
//type.
void figure_skate::copy(const figure_skate & from)
{
  //Copy parent's data first.
  athlete::copy(from);

  //Copy this class' data.
  triple_axels = from.triple_axels;
  song = from.song;

  return;
}



//This constant method checks whether the current object is empty. It takes no
//arugments and returns a bool value.
bool figure_skate::is_empty() const
{
  //Check if all data members are set to their zero equivalent values.
  if (triple_axels == 0 && song == "none")
    return true;

  return false;
}



//This operator reads in data members of the object. It takes an 'istream' and 
//'figure_skate' object, passed by reference, and returns a reference to an 
//'istream' object.
std::istream & operator>>(std::istream & in, figure_skate & game)
{
  //Call the parent class first.
  game.athlete::read(in);

  //Calls read method for this class.
  game.read(in);

  return in;
}



//This operator outputs data members of this object. It takes an 'ostream' and a 
//constant 'figure_skate' object, passed by reference, as arguments and returns 
//a reference to an 'ostream' object.
std::ostream & operator<<(std::ostream & out, const figure_skate & game)
{
  //Calls display method for this class.
  game.display(out);

  return out;
}



//This operator adds the number of axels to the figure skater's landings, which
//adds points to the athlete's total score. It takes a constant 'figure_skate' 
//object, passed by reference, and an integer as arguments and returns an 
//'figure_skate' object by value.
figure_skate operator+(const figure_skate & game, int axels)
{
  //Variable definitions
  BAD_INPUT b_input;       //Holds any errors to be thrown
  figure_skate temp(game); //Holds temporary object to be returned

  //Check if the passed in object is valid.
  if (game.song == "none")
  {
    b_input.bad_array = "bad";
    throw b_input;
  }

  //Add number of axels as points scored to the parent class.
  static_cast<athlete &> (temp) = static_cast <const athlete &> (game) + axels;

  //Add number of axels to this class.
  temp.triple_axels += axels;

  return temp;
}



//This operator adds the number of axels to the figure skater's landings, which
//adds points to the athlete's total score. It takes a constant 'figure_skate' 
//object, passed by reference, and an integer as arguments and returns an 
//'figure_skate' object by value.
figure_skate operator+(int axels, const figure_skate & game)
{
  //Variable definitions
  BAD_INPUT b_input;       //Holds any errors to be thrown
  figure_skate temp(game); //Holds temporary object to be returned

  //Check if the passed in object is valid.
  if (game.song == "none")
  {
    b_input.bad_array = "bad";
    throw b_input;
  }

  //Add number of axels as points scored to the parent class.
  static_cast<athlete &> (temp) = axels + static_cast <const athlete &> (game);

  //Add number of axels to this class.
  temp.triple_axels += axels;

  return temp;
}



//This operator adds the number triple axels landed, which adds points to the
//parent class' total score. It takes an integer as an argument and returns an 
//'figure_skate' object by reference.
figure_skate & figure_skate::operator+=(int axels)
{
  //Variable definitions
  BAD_INPUT b_input; //Holds any errors to be thrown

  //Check if the passed in object is valid.
  if (song == "none")
  {
    b_input.bad_array = "bad";
    throw b_input;
  }

  //Add number of axels as points scored to the parent class.
  athlete::operator+=(axels);

  //Add number of axels to this class.
  triple_axels += axels;

  return *this;
}



//This operator subtracts the number of axels from the figure skater's landings, 
//which subtracts points from the athlete's total score. It takes a constant 
//'figure_skate' object, passed by reference, and an integer as arguments and 
//returns an 'figure_skate' object by value.
figure_skate operator-(const figure_skate & game, int axels)
{
  //Variable definitions
  BAD_INPUT b_input;       //Holds any errors to be thrown
  figure_skate temp(game); //Holds temporary object to be returned

  //Check if the passed in object is valid.
  if (game.song == "none")
  {
    b_input.bad_array = "bad";
    throw b_input;
  }

  //Subtact number of axels as points lost to the parent class.
  static_cast<athlete &> (temp) = static_cast <const athlete &> (game) - axels;

  //Subtract number of axels from this class.
  temp.triple_axels -= axels;

  //If triple axels landed is less than 0, change the data member to equal zero.
  if (temp.triple_axels < 0)
    temp.triple_axels = 0;

  return temp;
}



//This operator subtracts the number of axels from the figure skater's landings, 
//which subtracts points from the athlete's total score. It takes a constant 
//'figure_skate' object, passed by reference, and an integer as arguments and 
//returns an 'figure_skate' object by value.
figure_skate operator-(int axels, const figure_skate & game)
{
  //Variable definitions
  BAD_INPUT b_input;       //Holds any errors to be thrown
  figure_skate temp(game); //Holds temporary object to be returned

  //Check if the passed in object is valid.
  if (game.song == "none")
  {
    b_input.bad_array = "bad";
    throw b_input;
  }

  //Subtact number of axels as points lost to the parent class.
  static_cast<athlete &> (temp) = axels - static_cast <const athlete &> (game);

  //Subtract number of axels from this class.
  temp.triple_axels -= axels;

  //If triple axels landed is less than 0, change the data member to equal zero.
  if (temp.triple_axels < 0)
    temp.triple_axels = 0;

  return temp;
}



//This operator subtracts the number triple axels landed, which subtracts points 
//from the parent class' total score. It takes an integer as an argument and 
//returns an 'figure_skate' object by reference.
figure_skate & figure_skate::operator-=(int axels)
{
  //Variable definitions
  BAD_INPUT b_input; //Holds any errors to be thrown

  //Check if the passed in object is valid.
  if (song == "none")
  {
    b_input.bad_array = "bad";
    throw b_input;
  }

  //Subtract number of axels as points lost to the parent class.
  athlete::operator-=(axels);

  //Subtract number of axels from this class.
  triple_axels -= axels;

  //If triple axels landed is less than 0, change the data member to equal zero.
  if (triple_axels < 0)
    triple_axels = 0;

  return *this;
}



//This operator checks if one figure skater's name is less than another. It 
//takes two constant 'figure_skate' objects, passed by reference, as arguments 
//and returns a bool value.
bool operator<(const figure_skate & game1, const figure_skate & game2)
{
  //Returns if first argument is less than second argument
  return -1 == game1.compare(game2);
}



//This operator checks if one figure skaters's name is less than another. It 
//takes a constant 'figure_skate' object, passed by reference, and a pointer to 
//a char as arguments and returns a bool value.
bool operator<(const figure_skate & game, const char * name)
{
  //Returns if first argument is less than second argument
  return -1 == game.compare(name);
}



//This operator checks if one figure skater's name is less than another. It 
//takes a constant 'figure_skate' object, passed by reference, and a pointer to 
//a char as arguments and returns a bool value.
bool operator<(const char * name, const figure_skate & game)
{
  //Returns if second argument is greater than first argument (making the first
  //argument less than).
  return 1 == game.compare(name);
}



//This operator checks if one figure skaters's name is less than or equal to 
//another. It takes two constant 'figure_skate' objects, passed by reference, 
//as arguments and returns a bool value.
bool operator<=(const figure_skate & game1, const figure_skate & game2)
{
  //Returns whether the two objects are the same or the first is less than the
  //second.
  return (game1 == game2 || -1 == game1.compare(game2));
}



//This operator checks if one figure skater's name is less than or equal to 
//another. It takes a constant 'figure_skate' object, passed by reference, and a 
//pointer to a char as arguments and returns a bool value.
bool operator<=(const figure_skate & game, const char * name)
{
  //Returns whether the two names are the same or the first is less than the
  //second.
  return (0 == game.compare(name) || -1 == game.compare(name));
}



//This operator checks if one name is less than or equal to another. It takes a 
//constant 'figure_skate' object, passed by reference, and a pointer to a char 
//as arguments and returns a bool value.
bool operator<=(const char * name, const figure_skate & game)
{
  //Returns whether the two names are the same or the second is greater than the
  //first.
  return (0 == game.compare(name) || 1 == game.compare(name));
}



//This operator checks if one figure skater's name is greater than another. It 
//takes two constant 'figure_skate' objects, passed by reference, as arguments 
//and returns a bool value.
bool operator>(const figure_skate & game1, const figure_skate & game2)
{
  //Returns if first argument is greater than second argument
  return 1 == game1.compare(game2);
}



//This operator checks if one figure skater's name is greater than another. It 
//takes a constant 'figure_skate' object, passed by reference, and a pointer to 
//a char as arguments and returns a bool value.
bool operator>(const figure_skate & game, const char * name)
{
  //Returns if first argument is greater than second argument
  return 1 == game.compare(name);
}



//This operator checks if one figure skater's name is greater than another. It 
//takes a constant 'figure_skate' object, passed by reference, and a pointer to 
//a char as arguments and returns a bool value.
bool operator>(const char * name, const figure_skate & game)
{
  //Returns if second argument is less than first argument (making the first
  //argument greater than).
  return -1 == game.compare(name);
}



//This operator checks if one figure skater's name is greater than or equal to 
//another. It takes two constant 'figure_skate' objects, passed by reference, as 
//arguments and returns a bool value.
bool operator>=(const figure_skate & game1, const figure_skate & game2)
{
  //Returns whether the two objects are the same or the first is greater than 
  //the second.
  return (game1 == game2 || 1 == game1.compare(game2));
}



//This operator checks if one figure skater's name is greater than or equal to 
//another. It takes a constant 'figure_skate' object, passed by reference, and a 
//pointer to a char as arguments and returns a bool value.
bool operator>=(const figure_skate & game, const char * name)
{
  //Returns whether the two names are the same or the first is greater than the
  //second.
  return (0 == game.compare(name) || 1 == game.compare(name));
}



//This operator checks if one name is greater than or equal to another. It 
//takes a constant 'figure_skate' object, passed by reference, and a pointer to 
//a char as arguments and returns a bool value.
bool operator>=(const char * name, const figure_skate & game)
{
  //Returns whether the two names are the same or the second is less than the
  //first.
  return (0 == game.compare(name) || -1 == game.compare(name));
}



//This constant operator checks if the current object's name is equal to 
//another object of the same type. It takes two constant 'figure_skate' objects, 
//passed by reference, as arguments and returns a bool value.
bool operator==(const figure_skate & game1, const figure_skate & game2)
{
  //Returns if the names match.
  return 0 == game1.compare(game2);
}



//This constant operator checks if the current object's name is equal to 
//another object of the same type. It takes a constant 'figure_skate' object, 
//passed by reference, and a constant pointer to a char as arguments and 
//returns a bool value.
bool operator==(const figure_skate & game1, const char * name)
{
  //Returns if the names match.
  return 0 == game1.compare(name);
}



//This constant operator checks if the current object's name is equal to 
//another object of the same type. It takes a constant 'figure_skate' object, 
//passed by reference, and a constant pointer to a char as arguments and 
//returns a bool value.
bool operator==(const char * name, const figure_skate & game2)
{
  //Returns if the names match.
  return 0 == game2.compare(name);
}



//This constant operator checks if the current object's name is not equal to 
//another object of the same type. It takes two constant 'figure_skate' objects, 
//passed by reference, as arguments and returns a bool value.
bool operator!=(const figure_skate & game1, const figure_skate & game2)
{
  //Returns if the names do not match.
  return !(0 == game1.compare(game2));
}



//This constant operator checks if the current object's name is not equal to 
//another object of the same type. It takes a constant 'figure_skate' object, 
//passed by reference, and a constant pointer to a char as arguments and 
//returns a bool value.
bool operator!=(const figure_skate & game1, const char * name)
{
  //Returns if the names do not match.
  return !(0 == game1.compare(name));
}



//This constant operator checks if the current object's name is not equal to 
//another object of the same type. It takes a constant 'figure_skate' object, 
//passed by reference, and a constant pointer to a char as arguments and 
//returns a bool value.
bool operator!=(const char * name, const figure_skate & game2)
{
  //Returns if the names match.
  return !(0 == game2.compare(name));
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~ S K I _ J U M P _ C L A S S ~~~~~~~~~~~~~~~~~~~~~~~~
//
//This default constructor sets the data members to their zero equivalent
//values. It takes no arguments and has no return type.
ski_jump::ski_jump(): distance(0.0), wind(0), speed(0)
{}



//This method prompts and reads in the appropriate information to be copied to 
//this class' data members. It takes an 'istream' object, passed by reference,
//as an argument and has a void return type.
void ski_jump::read(std::istream & in)
{
  using namespace std;

  //Variable definitions
  BAD_INPUT b_input; //Holds any errors to be thrown
  
  //Get wind speed statistics.
  do
  {
    //Get valid wind input.
    try
    {
      b_input.bad_array = "good";

      cout << "Wind speed (in mph: headwind (-), tailwind (+): ";
      in >> wind;

      //Check if input failed.
      if (in.fail())
      {
        in.clear();
        b_input.bad_array = "bad";
        throw b_input;
      }
    }

    //Catch any errors that were thrown.
    catch (...)
    {
      cout << "Please enter a valid whole number" << endl << endl;
      wind = 0;
    }

    in.ignore(100, '\n');

  } while (b_input.bad_array == "bad");

  //Get speed statistics.
  do
  {
    //Get valid speed input.
    try
    {
      cout << "Speed traveled at jump (in mph): ";
      in >> speed;

      //Check if the input is invalid.
      if (speed <= 0 || in.fail())
      {
        in.clear();
        b_input.bad_int = 0;
        throw b_input;
      }
    }

    //Catch any errors that were thrown.
    catch (...)
    {
      cout << "Please enter a positive whole number." << endl;
      speed = b_input.bad_int;
    }

    in.ignore(100, '\n');

  } while (speed <= 0);

  //Calculate the distance traveled based on speed traveled and wind cost.
  distance = calc_distance(wind, speed);

  return;
}



//This constant method displays the contents of this class' data members. It
//takes an 'ostream' object, passed by reference, as an argument and has a
//void return type.
void ski_jump::display(std::ostream & out) const
{
  using namespace std;

  //Variable definitions
  BAD_INPUT b_input; //Holds any errors to be thrown

  //Check if the current object is valid.
  if (speed == 0)
  {
    b_input.bad_int = speed;
    throw b_input;
  }

  athlete::display(out); //Displays parent first

  out << "Wind speed and direction: ";

  if (wind == 0)
    out << wind << " mph\n";
  else if (wind < 0)
    out << (-1 * wind) << " mph headwind\n";
  else
    out << wind << " mph tailwind\n";

  out << "Speed traveled at jump: " << speed << " mph\n"
      << "Total distance traveled: " << distance << " feet" << endl << endl;

  return;
}



//This method calculates the distance traveled based on a specific wind speed
//and speed at the moment of a jump. It uses a made up trajectory formula that 
//assumes the angle of takeoff is zero degrees, the amount of time in the air is 
//5 seconds, and it is directly multiplied by the speed, + or - the wind cost. 
//It takes two integers as arguments and returns an integer, to be the distance 
//traveled.
float ski_jump::calc_distance(int gust, int velocity)
{
  //Variable definitions
  int sec {5};          //Time in the air, in seconds
  float foot_speed {0}; //Holds the velocity as feet per second
  float foot_wind {0};  //Holds the gust as feet per second
  float dist {0};       //Holds distance traveled

  foot_speed = (velocity * 5280) / 3600; //Feet per second conversion
  foot_wind = (gust * 5280) / 3600;      //Feet per second conversion

  //Get distance in feet.
  if ((foot_speed * sec) < (-1 * foot_wind))
    dist = 1; //Prevents a negative distance.
  else
    dist = (foot_speed * sec) + foot_wind; //Very inaccurate trajectory formula

  return dist;
}



//This method copies an object of the same type to this class' object. It takes
//a constant 'ski_jump' object, passed by reference, and has a void return type.
void ski_jump::copy(const ski_jump & from)
{
  //Copy parent's data first.
  athlete::copy(from);

  //Copy this class' data.
  distance = from.distance;
  speed = from.speed;
  wind = from.wind;

  return;
}



//This constant method checks whether the object is empty. It takes no 
//arguments and returns a bool value.
bool ski_jump::is_empty() const
{
  //Check if the data members are set to their zero equivalent values.
  if (!distance && !speed && !wind)
    return true;

  return false;
}



//This operator reads in data members of the object. It takes an 'istream' and 
//'ski_jump' object, passed by reference, and returns a reference to an 
//'istream' object.
std::istream & operator>>(std::istream & in, ski_jump & game)
{
  //Call the parent class first.
  game.athlete::read(in);

  //Calls read method for this class.
  game.read(in);

  return in;
}



//This operator outputs data members of this object. It takes an 'ostream' and a 
//constant 'ski_jump' object, passed by reference, as arguments and returns 
//a reference to an 'ostream' object.
std::ostream & operator<<(std::ostream & out, const ski_jump & game)
{
  //Calls display method for this class.
  game.display(out);

  return out;
}



//This operator adds velocity to the ski jumpers speed, which adds points to the 
//athlete's total score. It takes a constant 'ski_jump' object, passed by 
//reference, and an integer as arguments and returns an 'ski_jump' object by 
//value.
ski_jump operator+(const ski_jump & game, int velocity)
{
  //Variable definitions
  BAD_INPUT b_input;   //Holds any errors to be thrown
  ski_jump temp(game); //Holds temporary object to be returned

  //Check if the temporary object is valid.
  if (temp.speed == 0)
  {
    b_input.bad_int = temp.speed;
    throw b_input;
  }

  //Add speed as points gained to the parent class.
  static_cast<athlete &> (temp) = static_cast <const athlete &> (game) + velocity;

  //Add velocity to this class.
  temp.speed += velocity;

  //If speed is less than or equal to 0, change the data member to equal one. 
  //The ski jumper must be moving at least a little!
  if (temp.speed <= 0)
    temp.speed = 1;

  //Recalculate distance traveled.
  temp.distance = temp.calc_distance(temp.wind, temp.speed);

  return temp;
}



//This operator adds velocity to the ski jumpers speed, which adds points to the 
//athlete's total score. It takes a constant 'ski_jump' object, passed by 
//reference, and an integer as arguments and returns an 'ski_jump' object by 
//value.
ski_jump operator+(int velocity, const ski_jump & game)
{
  //Variable definitions
  BAD_INPUT b_input;   //Holds any errors to be thrown
  ski_jump temp(game); //Holds temporary object to be returned

  //Check if the temporary object is valid.
  if (temp.speed == 0)
  {
    b_input.bad_int = temp.speed;
    throw b_input;
  }

  //Add speed as points gained to the parent class.
  static_cast<athlete &> (temp) = velocity + static_cast <const athlete &> (game);

  //Add velocity to this class.
  temp.speed += velocity;

  //If speed is less than or equal to 0, change the data member to equal one. 
  //The ski jumper must be moving at least a little!
  if (temp.speed <= 0)
    temp.speed = 1;

  //Recalculate distance traveled.
  temp.distance = temp.calc_distance(temp.wind, temp.speed);

  return temp;
}



//This operator adds speed traveled, which positively impacts points in the 
//parent class' total score. It takes an integer as an argument and returns an 
//'ski_jump' object by reference.
ski_jump & ski_jump::operator+=(int velocity)
{
  //Variable definitions
  BAD_INPUT b_input; //Holds any errors to be thrown

  //Check if the current object is valid.
  if (speed == 0)
  {
    b_input.bad_int = speed;
    throw b_input;
  }

  //Add or subtract speed gain or loss to parent class score.
  athlete::operator+=(velocity);

  //Add or subtract speed gain or loss to this class.
  speed += velocity;

  //If speed is less than or equal to 0, change the data member to equal one. 
  //The ski jumper must be moving at least a little!
  if (speed <= 0)
    speed = 1;

  //Recalculate distance traveled.
  distance = calc_distance(wind, speed);

  return *this;
}



//This operator subtracts velocity from the ski jumpers speed, which subtracts 
//points from the athlete's total score. It takes a constant 'ski_jump' object, 
//passed by reference, and an integer as arguments and returns an 'ski_jump' 
//object by value.
ski_jump operator-(const ski_jump & game, int velocity)
{
  //Variable definitions
  BAD_INPUT b_input;   //Holds any errors to be thrown
  ski_jump temp(game); //Holds temporary object to be returned

  //Check if the temporary object is valid.
  if (temp.speed == 0)
  {
    b_input.bad_int = temp.speed;
    throw b_input;
  }

  //Subtact speed as points lost to the parent class.
  static_cast<athlete &> (temp) = static_cast <const athlete &> (game) - velocity;

  //Subtract velocity from this class.
  temp.speed -= velocity;

  //If speed is less than or equal to 0, change the data member to equal one. 
  //The ski jumper must be moving at least a little!
  if (temp.speed <= 0)
    temp.speed = 1;

  //Recalculate distance traveled.
  temp.distance = temp.calc_distance(temp.wind, temp.speed);

  return temp;
}



//This operator subtracts velocity from the ski jumpers speed, which subtracts 
//points from the athlete's total score. It takes a constant 'ski_jump' object, 
//passed by reference, and an integer as arguments and returns an 'ski_jump' 
//object by value.
ski_jump operator-(int velocity, const ski_jump & game)
{
  //Variable definitions
  BAD_INPUT b_input;   //Holds any errors to be thrown
  ski_jump temp(game); //Holds temporary object to be returned

  //Check if the temporary object is valid.
  if (temp.speed == 0)
  {
    b_input.bad_int = temp.speed;
    throw b_input;
  }

  //Subtact speed as points lost to the parent class.
  static_cast<athlete &> (temp) = velocity - static_cast <const athlete &> (game);

  //Subtract velocity from this class.
  temp.speed -= velocity;

  //If speed is less than or equal to 0, change the data member to equal one. 
  //The ski jumper must be moving at least a little!
  if (temp.speed <= 0)
    temp.speed = 1;

  //Recalculate distance traveled.
  temp.distance = temp.calc_distance(temp.wind, temp.speed);

  return temp;
}



//This operator subtracts speed traveled, which negatively impacts points in the 
//parent class' total score. It takes an integer as an argument and returns an 
//'ski_jump' object by reference.
ski_jump & ski_jump::operator-=(int velocity)
{
  //Variable definitions
  BAD_INPUT b_input; //Holds any errors to be thrown

  //Check if the current object is valid.
  if (speed == 0)
  {
    b_input.bad_int = speed;
    throw b_input;
  }

  //Subtract speed from parent class score.
  athlete::operator-=(velocity);

  //Subtract speed.
  speed -= velocity;

  //If speed is less than or equal to 0, change the data member to equal one. 
  //The ski jumper must be moving at least a little!
  if (speed <= 0)
    speed = 1;

  //Recalculate distance traveled.
  distance = calc_distance(wind, speed);

  return *this;
}



//This operator checks if one ski jumper's name is less than another. It 
//takes two constant 'ski_jump' objects, passed by reference, as arguments 
//and returns a bool value.
bool operator<(const ski_jump & game1, const ski_jump & game2)
{
  //Returns if first argument is less than second argument
  return -1 == game1.compare(game2);
}



//This operator checks if one ski jumper's name is less than another. It 
//takes a constant 'ski_jump' object, passed by reference, and a pointer to 
//a char as arguments and returns a bool value.
bool operator<(const ski_jump & game, const char * name)
{
  //Returns if first argument is less than second argument
  return -1 == game.compare(name);
}



//This operator checks if one ski jumper's name is less than another. It 
//takes a constant 'ski_jump' object, passed by reference, and a pointer to 
//a char as arguments and returns a bool value.
bool operator<(const char * name, const ski_jump & game)
{
  //Returns if second argument is greater than first argument (making the first
  //argument less than).
  return 1 == game.compare(name);
}



//This operator checks if one ski jumper's name is less than or equal to 
//another. It takes two constant 'ski_jump' objects, passed by reference, 
//as arguments and returns a bool value.
bool operator<=(const ski_jump & game1, const ski_jump & game2)
{
  //Returns whether the two objects are the same or the first is less than the
  //second.
  return (game1 == game2 || -1 == game1.compare(game2));
}



//This operator checks if one ski jumper's name is less than or equal to 
//another. It takes a constant 'ski_jump' object, passed by reference, and a 
//pointer to a char as arguments and returns a bool value.
bool operator<=(const ski_jump & game, const char * name)
{
  //Returns whether the two names are the same or the first is less than the
  //second.
  return (0 == game.compare(name) || -1 == game.compare(name));
}



//This operator checks if one name is less than or equal to another. It takes a 
//constant 'ski_jump' object, passed by reference, and a pointer to a char 
//as arguments and returns a bool value.
bool operator<=(const char * name, const ski_jump & game)
{
  //Returns whether the two names are the same or the second is greater than the
  //first.
  return (0 == game.compare(name) || 1 == game.compare(name));
}



//This operator checks if one ski jumper's name is greater than another. It 
//takes two constant 'ski_jump' objects, passed by reference, as arguments 
//and returns a bool value.
bool operator>(const ski_jump & game1, const ski_jump & game2)
{
  //Returns if first argument is greater than second argument
  return 1 == game1.compare(game2);
}



//This operator checks if one ski jumper's name is greater than another. It 
//takes a constant 'ski_jump' object, passed by reference, and a pointer to 
//a char as arguments and returns a bool value.
bool operator>(const ski_jump & game, const char * name)
{
  //Returns if first argument is greater than second argument
  return 1 == game.compare(name);
}



//This operator checks if one ski jumper's name is greater than another. It 
//takes a constant 'ski_jump' object, passed by reference, and a pointer to 
//a char as arguments and returns a bool value.
bool operator>(const char * name, const ski_jump & game)
{
  //Returns if second argument is less than first argument (making the first
  //argument greater than).
  return -1 == game.compare(name);
}



//This operator checks if one ski jumper's name is greater than or equal to 
//another. It takes two constant 'ski_jump' objects, passed by reference, as 
//arguments and returns a bool value.
bool operator>=(const ski_jump & game1, const ski_jump & game2)
{
  //Returns whether the two objects are the same or the first is greater than 
  //the second.
  return (game1 == game2 || 1 == game1.compare(game2));
}



//This operator checks if one ski jumper's name is greater than or equal to 
//another. It takes a constant 'ski_jump' object, passed by reference, and a 
//pointer to a char as arguments and returns a bool value.
bool operator>=(const ski_jump & game, const char * name)
{
  //Returns whether the two names are the same or the first is greater than the
  //second.
  return (0 == game.compare(name) || 1 == game.compare(name));
}



//This operator checks if one name is greater than or equal to another. It 
//takes a constant 'ski_jump' object, passed by reference, and a pointer to 
//a char as arguments and returns a bool value.
bool operator>=(const char * name, const ski_jump & game)
{
  //Returns whether the two names are the same or the second is less than the
  //first.
  return (0 == game.compare(name) || -1 == game.compare(name));
}



//This constant operator checks if the current object's name is equal to 
//another object of the same type. It takes two constant 'ski_jump' objects, 
//passed by reference, as arguments and returns a bool value.
bool operator==(const ski_jump & game1, const ski_jump & game2)
{
  //Returns if the names match.
  return 0 == game1.compare(game2);
}



//This constant operator checks if the current object's name is equal to 
//another object of the same type. It takes a constant 'ski_jump' object, 
//passed by reference, and a constant pointer to a char as arguments and 
//returns a bool value.
bool operator==(const ski_jump & game1, const char * name)
{
  //Returns if the names match.
  return 0 == game1.compare(name);
}



//This constant operator checks if the current object's name is equal to 
//another object of the same type. It takes a constant 'ski_jump' object, 
//passed by reference, and a constant pointer to a char as arguments and 
//returns a bool value.
bool operator==(const char * name, const ski_jump & game2)
{
  //Returns if the names match.
  return 0 == game2.compare(name);
}



//This constant operator checks if the current object's name is not equal to 
//another object of the same type. It takes two constant 'ski_jump' objects, 
//passed by reference, as arguments and returns a bool value.
bool operator!=(const ski_jump & game1, const ski_jump & game2)
{
  //Returns if the names do not match.
  return !(0 == game1.compare(game2));
}



//This constant operator checks if the current object's name is not equal to 
//another object of the same type. It takes a constant 'ski_jump' object, 
//passed by reference, and a constant pointer to a char as arguments and 
//returns a bool value.
bool operator!=(const ski_jump & game1, const char * name)
{
  //Returns if the names do not match.
  return !(0 == game1.compare(name));
}



//This constant operator checks if the current object's name is not equal to 
//another object of the same type. It takes a constant 'ski_jump' object, 
//passed by reference, and a constant pointer to a char as arguments and 
//returns a bool value.
bool operator!=(const char * name, const ski_jump & game2)
{
  //Returns if the names match.
  return !(0 == game2.compare(name));
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~ B O B S L E D _ C L A S S ~~~~~~~~~~~~~~~~~~~~~~~~~
//
//This default constructor sets the data members to their zero equivalent
//values. It takes no arguments and has no return type.
bobsled::bobsled(): total_time(0), position("none")
{}



//This method prompts and reads in the appropriate information to be copied to 
//this class' data members. It takes an 'istream' object, passed by reference,
//as an argument and has a void return type.
void bobsled::read(std::istream & in)
{
  using namespace std;

  //Variable definitions
  BAD_INPUT b_input; //Holds any errors to be thrown

  //Get bobsled statistics information (total time to complete course and
  //bobsledder position).
  do
  {
    //Get valid input.
    try
    {
      cout << "Time to finish race (in minutes): ";
      in >> total_time;

      if (total_time <= 0 || in.fail())
      {
        in.clear();
        b_input.bad_int = 0;
        throw b_input;
      }
    }

    //Catch any errors that were thrown.
    catch (...)
    {
      cout << "Please enter a positive whole number." << endl;
      total_time = b_input.bad_int;
    }

    in.ignore(100, '\n');

  } while (total_time <= 0);

  cout << "Position (front, middle, rear): ";
  getline(in, position);

  //Capitalize first letter.
  position[0] = toupper(position[0]);

  return;
}



//This constant method displays the contents of this class' data members. It
//takes an 'ostream' object, passed by reference, as an argument and has a
//void return type.
void bobsled::display(std::ostream & out) const
{
  using namespace std;

  //Variable definitions
  BAD_INPUT b_input; //Holds any errors to be thrown

  //Check if the current object is valid.
  if (total_time == 0)
  {
    b_input.bad_int = total_time;
    throw b_input;
  }

  athlete::display(out); //Displays parent first

  out << "Race time: " << total_time << " minute(s)\n"
      << "Position: " << position << endl << endl;

  return;
}



//This method copies an object of the same type to this class' object. It takes
//a constant 'bobsled' object, passed by reference, and has a void return type.
void bobsled::copy(const bobsled & from)
{
  //Copy parent's data first.
  athlete::copy(from);

  //Copy this class' data.
  total_time = from.total_time;
  position = from.position;

  return;
}



//This constant method checks whether the object is empty. It takes no
//arguments and returns a bool value.
bool bobsled::is_empty() const
{
  //Check if the data members are their zero equivalent values.
  if (!total_time && position == "none")
    return true;

  return false;
}



//This operator reads in data members of the object. It takes an 'istream' and 
//'bobsled' object, passed by reference, and returns a reference to an 
//'istream' object.
std::istream & operator>>(std::istream & in, bobsled & game)
{
  //Call the parent class first.
  game.athlete::read(in);

  //Calls read method for this class.
  game.read(in);

  return in;
}



//This operator outputs data members of this object. It takes an 'ostream' and a 
//constant 'bobsled' object, passed by reference, as arguments and returns 
//a reference to an 'ostream' object.
std::ostream & operator<<(std::ostream & out, const bobsled & game)
{
  //Calls display method for this class.
  game.display(out);

  return out;
}



//This operator adds minutes to the bob sledders time, which subtracts points
//from the athlete's total score. It takes a constant 'bobsled' object, passed 
//by reference, and an integer as arguments and returns a 'bobsled' object by 
//value.
bobsled operator+(const bobsled & game, int minutes)
{
  //Variable definitions
  BAD_INPUT b_input;  //Holds any errors to be thrown
  bobsled temp(game); //Holds temporary object to be returned

  //Check if the temporary object is valid.
  if (temp.position == "none")
  {
    b_input.bad_array = "bad";
    throw b_input;
  }

  //Subtracts minutes as points lost to the parent class.
  static_cast<athlete &> (temp) = static_cast <const athlete &> (game) - minutes;

  //Adds minutes to this class.
  temp.total_time += minutes;

  //If the total race time is less than or equal to 0, change the data member to 
  //equal one.
  if (temp.total_time <= 0)
    temp.total_time = 1;

  return temp;
}



//This operator adds minutes to the bob sledders time, which subtracts points
//from the athlete's total score. It takes a constant 'bobsled' object, passed 
//by reference, and an integer as arguments and returns a 'bobsled' object by 
//value.
bobsled operator+(int minutes, const bobsled & game)
{
  //Variable definitions
  BAD_INPUT b_input;  //Holds any errors to be thrown
  bobsled temp(game); //Holds temporary object to be returned

  //Check if the temporary object is valid.
  if (temp.position == "none")
  {
    b_input.bad_array = "bad";
    throw b_input;
  }

  //Subtracts minutes as points lost to the parent class.
  static_cast<athlete &> (temp) = minutes - static_cast <const athlete &> (game);

  //Adds minutes to this class.
  temp.total_time += minutes;

  //If the total race time is less than or equal to 0, change the data member to 
  //equal one.
  if (temp.total_time <= 0)
    temp.total_time = 1;

  return temp;
}



//This operator adds minutes to the race time, which negatively impacts points 
//in the parent class' total score. It takes an integer as an argument and 
//returns a 'bobsled' object by reference.
bobsled & bobsled::operator+=(int minutes)
{
  //Variable definitions
  BAD_INPUT b_input; //Holds any errors to be thrown

  //Check if the current object is valid.
  if (position == "none")
  {
    b_input.bad_array = "bad";
    throw b_input;
  }

  //Subtract minutes as points lost to the parent class score.
  athlete::operator-=(minutes);

  //Add minutes to this class.
  total_time += minutes;

  //If the total race time is less than or equal to 0, change the data member to 
  //equal one.
  if (total_time <= 0)
    total_time = 1;

  return *this;
}



//This operator subtracts minutes from the bob sledders time, which adds points
//to the athlete's total score. It takes a constant 'bobsled' object, passed by 
//reference, and an integer as arguments and returns a 'bobsled' object by 
//value.
bobsled operator-(const bobsled & game, int minutes)
{
  //Variable definitions
  BAD_INPUT b_input;  //Holds any errors to be thrown
  bobsled temp(game); //Holds temporary object to be returned

  //Check if the temporary object is valid.
  if (temp.position == "none")
  {
    b_input.bad_array = "bad";
    throw b_input;
  }

  //Add minutes as points gained to the parent class.
  static_cast<athlete &> (temp) = static_cast <const athlete &> (game) + minutes;

  //Subtract minutes from this class.
  temp.total_time -= minutes;

  //If the total race time is less than or equal to 0, change the data member to 
  //equal one.
  if (temp.total_time <= 0)
    temp.total_time = 1;

  return temp;
}



//This operator subtracts minutes from the bob sledders time, which adds points
//to the athlete's total score. It takes a constant 'bobsled' object, passed by 
//reference, and an integer as arguments and returns a 'bobsled' object by 
//value.
bobsled operator-(int minutes, const bobsled & game)
{
  //Variable definitions
  BAD_INPUT b_input;  //Holds any errors to be thrown
  bobsled temp(game); //Holds temporary object to be returned

  //Check if the temporary object is valid.
  if (temp.position == "none")
  {
    b_input.bad_array = "bad";
    throw b_input;
  }

  //Add minutes as points gained to the parent class.
  static_cast<athlete &> (temp) = minutes + static_cast <const athlete &> (game);

  //Subtract minutes from this class.
  temp.total_time -= minutes;

  //If the total race time is less than or equal to 0, change the data member to 
  //equal one.
  if (temp.total_time <= 0)
    temp.total_time = 1;

  return temp;
}



//This operator subtracts minutes from the race time, which positively impacts 
//points in the parent class' total score. It takes an integer as an argument 
//and returns an 'bobsled' object by reference.
bobsled & bobsled::operator-=(int minutes)
{
  //Variable definitions
  BAD_INPUT b_input; //Holds any errors to be thrown

  //Check if the current object is valid.
  if (position == "none")
  {
    b_input.bad_array = "bad";
    throw b_input;
  }

  //Add minutes as points gained to parent class score.
  athlete::operator+=(minutes);

  //Subtract minutes from this class.
  total_time -= minutes;

  //If the total race time is less than or equal to 0, change the data member to 
  //equal one.
  if (total_time <= 0)
    total_time = 1;

  return *this;
}



//This operator checks if one bobsledder's name is less than another. It 
//takes two constant 'bobsled' objects, passed by reference, as arguments 
//and returns a bool value.
bool operator<(const bobsled & game1, const bobsled & game2)
{
  //Returns if first argument is less than second argument
  return -1 == game1.compare(game2);
}



//This operator checks if one bobsledder's name is less than another. It 
//takes a constant 'bobsled' object, passed by reference, and a pointer to 
//a char as arguments and returns a bool value.
bool operator<(const bobsled & game, const char * name)
{
  //Returns if first argument is less than second argument
  return -1 == game.compare(name);
}



//This operator checks if one bobsledder's name is less than another. It 
//takes a constant 'bobsled' object, passed by reference, and a pointer to 
//a char as arguments and returns a bool value.
bool operator<(const char * name, const bobsled & game)
{
  //Returns if second argument is greater than first argument (making the first
  //argument less than).
  return 1 == game.compare(name);
}



//This operator checks if one bobsledder's name is less than or equal to 
//another. It takes two constant 'bobsled' objects, passed by reference, 
//as arguments and returns a bool value.
bool operator<=(const bobsled & game1, const bobsled & game2)
{
  //Returns whether the two objects are the same or the first is less than the
  //second.
  return (game1 == game2 || -1 == game1.compare(game2));
}



//This operator checks if one bobsledder's name is less than or equal to 
//another. It takes a constant 'bobsled' object, passed by reference, and a 
//pointer to a char as arguments and returns a bool value.
bool operator<=(const bobsled & game, const char * name)
{
  //Returns whether the two names are the same or the first is less than the
  //second.
  return (0 == game.compare(name) || -1 == game.compare(name));
}



//This operator checks if one name is less than or equal to another. It takes a 
//constant 'bobsled' object, passed by reference, and a pointer to a char 
//as arguments and returns a bool value.
bool operator<=(const char * name, const bobsled & game)
{
  //Returns whether the two names are the same or the second is greater than the
  //first.
  return (0 == game.compare(name) || 1 == game.compare(name));
}



//This operator checks if one bobsledder's name is greater than another. It 
//takes two constant 'bobsled' objects, passed by reference, as arguments 
//and returns a bool value.
bool operator>(const bobsled & game1, const bobsled & game2)
{
  //Returns if first argument is greater than second argument
  return 1 == game1.compare(game2);
}



//This operator checks if one bobsledder's name is greater than another. It 
//takes a constant 'bobsled' object, passed by reference, and a pointer to 
//a char as arguments and returns a bool value.
bool operator>(const bobsled & game, const char * name)
{
  //Returns if first argument is greater than second argument
  return 1 == game.compare(name);
}



//This operator checks if one bobsledder's name is greater than another. It 
//takes a constant 'bobsled' object, passed by reference, and a pointer to 
//a char as arguments and returns a bool value.
bool operator>(const char * name, const bobsled & game)
{
  //Returns if second argument is less than first argument (making the first
  //argument greater than).
  return -1 == game.compare(name);
}



//This operator checks if one bobsledder's name is greater than or equal to 
//another. It takes two constant 'bobsled' objects, passed by reference, as 
//arguments and returns a bool value.
bool operator>=(const bobsled & game1, const bobsled & game2)
{
  //Returns whether the two objects are the same or the first is greater than 
  //the second.
  return (game1 == game2 || 1 == game1.compare(game2));
}



//This operator checks if one bobsledder's name is greater than or equal to 
//another. It takes a constant 'bobsled' object, passed by reference, and a 
//pointer to a char as arguments and returns a bool value.
bool operator>=(const bobsled & game, const char * name)
{
  //Returns whether the two names are the same or the first is greater than the
  //second.
  return (0 == game.compare(name) || 1 == game.compare(name));
}



//This operator checks if one name is greater than or equal to another. It 
//takes a constant 'bobsled' object, passed by reference, and a pointer to 
//a char as arguments and returns a bool value.
bool operator>=(const char * name, const bobsled & game)
{
  //Returns whether the two names are the same or the second is less than the
  //first.
  return (0 == game.compare(name) || -1 == game.compare(name));
}



//This constant operator checks if the current object's name is equal to 
//another object of the same type. It takes two constant 'bobsled' objects, 
//passed by reference, as arguments and returns a bool value.
bool operator==(const bobsled & game1, const bobsled & game2)
{
  //Returns if the names match.
  return 0 == game1.compare(game2);
}



//This constant operator checks if the current object's name is equal to 
//another object of the same type. It takes a constant 'bobsled' object, 
//passed by reference, and a constant pointer to a char as arguments and 
//returns a bool value.
bool operator==(const bobsled & game1, const char * name)
{
  //Returns if the names match.
  return 0 == game1.compare(name);
}



//This constant operator checks if the current object's name is equal to 
//another object of the same type. It takes a constant 'bobsled' object, 
//passed by reference, and a constant pointer to a char as arguments and 
//returns a bool value.
bool operator==(const char * name, const bobsled & game2)
{
  //Returns if the names match.
  return 0 == game2.compare(name);
}



//This constant operator checks if the current object's name is not equal to 
//another object of the same type. It takes two constant 'bobsled' objects, 
//passed by reference, as arguments and returns a bool value.
bool operator!=(const bobsled & game1, const bobsled & game2)
{
  //Returns if the names do not match.
  return !(0 == game1.compare(game2));
}



//This constant operator checks if the current object's name is not equal to 
//another object of the same type. It takes a constant 'bobsled' object, 
//passed by reference, and a constant pointer to a char as arguments and 
//returns a bool value.
bool operator!=(const bobsled & game1, const char * name)
{
  //Returns if the names do not match.
  return !(0 == game1.compare(name));
}



//This constant operator checks if the current object's name is not equal to 
//another object of the same type. It takes a constant 'bobsled' object, 
//passed by reference, and a constant pointer to a char as arguments and 
//returns a bool value.
bool operator!=(const char * name, const bobsled & game2)
{
  //Returns if the names match.
  return !(0 == game2.compare(name));
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~ N O N _ M E M B E R _ F U N C T I O N S ~~~~~~~~~~~~~~~~~~
//
//This function checks if a user wants to do something again by reading in a yes
//or no response. It takes no arguments and returns a bool value.
bool again()
{
  //Variable defintions
  char response {'N'};  //To be users response

  //Get response.
  do
  {
    std::cin >> response;
    std::cin.ignore(100, '\n');

    response = toupper(response);

    //Check if the correct response has been inputted.
    if (response != 'N' && response != 'Y')
    {
      std::cout << "Invalid response. Try again..." << std::endl << std::endl;
      std::cout << "Y or N: ";
    }
    
  } while (response != 'N' && response != 'Y');

  if (response == 'Y')
    return true;

  return false;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
