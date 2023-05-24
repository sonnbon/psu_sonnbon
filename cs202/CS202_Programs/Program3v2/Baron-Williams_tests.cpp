#include "Baron-Williams_BST.h"

// *****************************************************************************
// Program 3
// Author: Connor Baron-Williams
// Due Date: February 28, 2022
// Course: CS202 Programming Systems
// Filename: Baron-Williams_tests.cpp
// *****************************************************************************
// This file manages all the functions to be used in the main application, 
// including different test functions that test the functionality of all of the
// derived athlete classes, including the athlete parent class itself, as well 
// as the data structures that hold collections of those classes. It tests for
// add, manipulation, display, retrieval, and removal, when applicable, of all 
// objects with the use of operator overloading. Data structures used include a
// Binary Search Tree, created by author, and two STL containers, array and
// forward_list.
// *****************************************************************************



//This function runs the main functionality of a STL's Array container. It 
//allows the user to insert, remove, remove all, retrieve, display all, and add 
//or subtract points to the most recently added athlete. It takes no arguments 
//and has a void return type.
void STL_forwardlist_function()
{
    using namespace std;

    //Variable definitions
    int option {0};                       //User options to manage a list
    int points {0};                       //User inputted points scored
    BAD_INPUT b_input;                    //Users incorrect input if needed
    bobsled player;                       //Bobsledder object
    forward_list<bobsled> sledders;       //Collection of bobsledders
    forward_list<bobsled>::iterator iter; //Iterates through forward list
 
    do
    {
      cout << "\nWhat would you like to do?\n"
           << "1 - Add bobsledder to front of list\n"
           << "2 - Display all bobsledders\n"
           << "3 - Add points to most recently added bobsledder\n"
           << "4 - Subtract points from most recently added bobsledder\n"
           << "5 - Remove bobsledder at front of list\n"
           << "6 - Remove the most recently added bobsledder\n"
           << "7 - Remove all bobsledders\n"
           << "8 - Reverse the order of the bobsledders\n"
           << "9 - Sort the bobsledders\n"
           << endl;

      cout << "Enter a whole number: ";
      cin >> option;
      cin.ignore(100, '\n');

      //Make sure user chooses a number between 1 and 9. Otherwise, throw a
      //BAD_INPUT structure and have them try again.
      try
      {
        if (option < 1 || option > 9 || cin.fail())
        {
          cin.clear();
          cin.ignore(100, '\n');
          b_input.bad_int = option;
          throw b_input;
        }

        switch (option)
        {
          case 1:
            //Add an athlete to front of list
            cin >> player;
            sledders.push_front(player);
            break;

          case 2:
            //Display all athletes by using STL's iterator method and printing
            //a dereferenced iterated element if not empty.
            if (!sledders.empty())
            {
              for (iter = sledders.begin(); iter != sledders.end(); ++iter)
                cout << *iter << endl;
            }

            //Otherwise, the list is empty.
            else
              cout << "The list is empty." << endl << endl;
            break;

          case 3:
            //Add points for athlete
            //Check if list is not empty.
            if (!sledders.empty())
            {
              cout << "Minutes to subtract? ";
              cin >> points;
              cin.ignore(100, '\n');

              //Check for valid input.
              if (cin.fail())
              {
                cin.clear();
                cin.ignore(100, '\n');
                b_input.bad_int = 0;
                throw b_input;
              }

              player -= points;
              sledders.remove(player); //Remove before adding updated object
              sledders.push_front(player);
            }

            //Otherwise, the list is empty.
            else
              cout << "The list is empty." << endl << endl;
            break;

          case 4:
            //Subtract points for athlete
            //Check if list is not empty.
            if (!sledders.empty())
            {
              cout << "Minutes to add? ";
              cin >> points;
              cin.ignore(100, '\n');

              //Check for valid input.
              if (cin.fail())
              {
                cin.clear();
                cin.ignore(100, '\n');
                b_input.bad_int = 0;
                throw b_input;
              }

              player += points;
              sledders.remove(player); //Remove before adding updated object
              sledders.push_front(player);
            }

            //Otherwise, the list is empty.
            else
              cout << "The list is empty." << endl << endl;
            break;

          case 5:
            //Remove athlete at front of list if not empty
            if (!sledders.empty())
              sledders.pop_front();
            else
              cout << "The list is empty." << endl << endl;
            break;

          case 6:
            //Remove the most recently added bobsledder if not empty
            if (sledders.empty())
              cout << "The list is empty." << endl << endl;
            else
              sledders.remove(player); //Remove by player match
            break;

          case 7:
            //Remove all by checking whether the list is empty.
            while (!sledders.empty())
              sledders.pop_front();

            cout << "The list is empty." << endl << endl;
            break;

          case 8:
            //Reverse the order of the athletes
            if (sledders.empty())
              cout << "The list is empty." << endl << endl;
            else
              sledders.reverse(); //Reverse order
            break;

          case 9:
            //Sort the athletes
            if (sledders.empty())
              cout << "The list is empty." << endl << endl;
            else
              sledders.sort(); //Sorts the objects
            break;

          default:
            cout << "Default should not get called." << endl;
            break;
        }
      }

      //Catch any errors that may have occurred when choosing a switch option.
      catch (...)
      {
        cout << "That is not a valid response. Try again." << endl << endl;
      }

      cout << "See the list of bobsledders submenu again? Yes (Y) or No (N): ";
  
    } while (again()); //Returns whether user enters Yes or No

    cout << "Exiting submenu..." << endl << endl;
    return;
}



//This function runs the main functionality of a STL's Array container. It 
//allows the user to insert, remove, remove all, retrieve, display all, and add 
//or subtract points to the most recently added athlete. It takes no arguments 
//and has a void return type.
void STL_array_function()
{
    using namespace std;

    //Variable definitions
    char temp_name[SIZE];              //Hold various temporary array responses
    int length {0};                    //Length of temporary array responses
    int option {0};                    //User options to manage a list
    int points {0};                    //User inputted points scored
    int index {0};                     //Index of array
    bool added {true};                 //Checks whether ski jumper was added
    bool found {false};                //Checks whether ski jumper was found
    BAD_INPUT b_input;                 //Users incorrect input if needed
    ski_jump player;                   //Ski jumper object
    array<ski_jump, ARR_SIZE> jumpers; //Collection of ski jumpers
 
    do
    {
      cout << "\nWhat would you like to do?\n"
           << "1 - Add ski jumper\n"
           << "2 - Display ski jumper\n"
           << "3 - Display all ski jumpers\n"
           << "4 - Display front of list\n"
           << "5 - Display back of list\n"
           << "6 - Add points to ski jumper\n"
           << "7 - Subtract points from ski jumper\n"
           << endl;

      cout << "Enter a whole number: ";
      cin >> option;
      cin.ignore(100, '\n');

      //Make sure user chooses a number between 1 and 7. Otherwise, throw a
      //BAD_INPUT structure and have them try again.
      try
      {
        if (option < 1 || option > 7 || cin.fail())
        {
          cin.clear();
          cin.ignore(100, '\n');
          b_input.bad_int = option;
          throw b_input;
        }

        switch (option)
        {
          case 1:
            //Add an athlete
            do
            {
              //Check if within bounds.
              if (index < ARR_SIZE)
              {
                cin >> player;
                jumpers[index] = player;
                ++index;
              }

              //Otherwise, list is full
              else
              {
                cout << "The list is full." << endl << endl;
                added = false;
              }

              if (added)
                cout << "Add another athlete? Yes (Y) or No (N): ";

            } while (added && again());

            added = true;
            break;

          case 2:
            //Display athlete
            cout << "Enter athlete's name: ";
            cin.get(temp_name, SIZE, '\n');
            cin.ignore(100, '\n');
  
            length = strlen(temp_name);

            //Capitalize first letter and anything after a space.
            temp_name[0] = toupper(temp_name[0]);

            for (int i = 1; i < length; ++i)
            {
              if (temp_name[i - 1] == ' ')
                temp_name[i] = toupper(temp_name[i]);
            }
 
            //Look for ski jumper.
            for (int i = 0; i < ARR_SIZE; ++i)
            {
              if (jumpers[i] == temp_name)
              {
                cout << jumpers.at(i) << endl; //Displays element
                found = true;
              }
            }

            if (!found)
              cout << "Athlete not found" << endl << endl;
            else
              found = false;
            break;

          case 3:
            //Display all athletes
            for (int i = 0; i < ARR_SIZE; ++i)
            {
              if (!jumpers[i].is_empty())
                cout << jumpers.at(i) << endl << endl;
            }
            break;

          case 4:
            //Display front of the list
            if (!jumpers[0].is_empty())
              cout << jumpers.front() << endl << endl;
            else
              cout << "No athlete at the front" << endl << endl;
            break;

          case 5:
            //Display end of the list
            if (!jumpers[ARR_SIZE - 1].is_empty())
              cout << jumpers.back() << endl << endl;
            else
              cout << "No athlete at the back" << endl << endl;
            break;

          case 6:
            //Add points for athlete
            cout << "Velocity to add? ";
            cin >> points;
            cin.ignore(100, '\n');

            //Check for valid input.
            if (cin.fail())
            {
              cin.clear();
              cin.ignore(100, '\n');
              b_input.bad_int = 0;
              throw b_input;
            }

            cout << "To which athlete? Enter name: ";
            cin.get(temp_name, SIZE, '\n');
            cin.ignore(100, '\n');
  
            length = strlen(temp_name);

            //Capitalize first letter and anything after a space.
            temp_name[0] = toupper(temp_name[0]);

            for (int i = 1; i < length; ++i)
            {
              if (temp_name[i - 1] == ' ')
                temp_name[i] = toupper(temp_name[i]);
            }
 
            //Look for ski jumper.
            for (int i = 0; i < ARR_SIZE; ++i)
            {
              if (jumpers[i] == temp_name)
              {
                jumpers[i] += points;
                cout << jumpers.at(i) << endl << endl; //Displays element
                found = true;
              }
            }

            if (!found)
              cout << "Athlete not found" << endl << endl;
            else
              found = false;
            break;

          case 7:
            //Subtract points for athlete
            cout << "Velocity to subtract? ";
            cin >> points;
            cin.ignore(100, '\n');

            //Check for valid input.
            if (cin.fail())
            {
              cin.clear();
              cin.ignore(100, '\n');
              b_input.bad_int = 0;
              throw b_input;
            }

            cout << "To which athlete? Enter name: ";
            cin.get(temp_name, SIZE, '\n');
            cin.ignore(100, '\n');
  
            length = strlen(temp_name);

            //Capitalize first letter and anything after a space.
            temp_name[0] = toupper(temp_name[0]);

            for (int i = 1; i < length; ++i)
            {
              if (temp_name[i - 1] == ' ')
                temp_name[i] = toupper(temp_name[i]);
            }
 
            //Look for ski jumper.
            for (int i = 0; i < ARR_SIZE; ++i)
            {
              if (jumpers[i] == temp_name)
              {
                jumpers[i] -= points;
                cout << jumpers.at(i) << endl << endl; //Displays element
                found = true;
              }
            }

            if (!found)
              cout << "Athlete not found" << endl << endl;
            else
              found = false;
            break;

          default:
            cout << "Default should not get called." << endl;
            break;
        }
      }

      //Catch any errors that may have occurred when choosing a switch option.
      catch (...)
      {
        cout << "That is not a valid response. Try again." << endl << endl;
      }

      cout << "See the list of ski jumpers submenu again? Yes (Y) or No (N): ";
  
    } while (again()); //Returns whether user enters Yes or No

    cout << "Exiting submenu..." << endl << endl;
    return;
}



//This function runs the main functionality of the 'BST' class. It allows the
//user to insert, remove, remove all, retrieve, display all, and add or subtract
//points to the most recently added athlete. It takes no arguments and has a 
//void return type.
void BST_function()
{
    using namespace std;

    //Variable definitions
    char temp_name[SIZE]; //Hold various temporary array responses
    int length {0};       //Length of temporary array responses
    int option {0};       //User options to manage a list
    int points {0};       //User inputted points scored
    BAD_INPUT b_input;    //Users incorrect input if needed
    figure_skate player;  //Figure skating object
    BST skaters;          //Collection of figure skaters
  
    do
    {
      cout << "\nWhat would you like to do?\n"
           << "1 - Add figure skater\n"
           << "2 - Display figure skater\n"
           << "3 - Display all figure skaters\n"
           << "4 - Add points to most recently added figure skater\n"
           << "5 - Subtract points from most recently added figure skater\n"
           << "6 - Remove figure skater\n"
           << "7 - Remove all skaters by entering 'ALL ATHLETES'\n"
           << endl;

      cout << "Enter a whole number: ";
      cin >> option;
      cin.ignore(100, '\n');

      //Make sure user chooses a number between 1 and 7. Otherwise, throw a
      //BAD_INPUT structure and have them try again.
      try
      {
        if (option < 1 || option > 7 || cin.fail())
        {
          cin.clear();
          cin.ignore(100, '\n');
          b_input.bad_int = 0;
          throw b_input;
        }

        switch (option)
        {
          case 1:
            //Add an athlete
            cin >> player;
            skaters += player;
            break;

          case 2:
            //Display athlete
            cout << "Enter athlete's name: ";
            cin.get(temp_name, SIZE, '\n');
            cin.ignore(100, '\n');
  
            length = strlen(temp_name);

            //Capitalize first letter and anything after a space.
            temp_name[0] = toupper(temp_name[0]);

            for (int i = 1; i < length; ++i)
            {
              if (temp_name[i - 1] == ' ')
                temp_name[i] = toupper(temp_name[i]);
            }

            if (!(skaters == temp_name))
              cout << "No match found" << endl << endl;
            break;

          case 3:
            //Display all athletes
            cout << skaters << endl << endl;
            break;

          case 4:
            //Add points for athlete
            cout << "Triple axels landed to add? ";
            cin >> points;
            cin.ignore(100, '\n');

            //Check for valid input.
            if (cin.fail())
            {
              cin.clear();
              cin.ignore(100, '\n');
              b_input.bad_int = 0;
              throw b_input;
            }

            player += points;
            skaters += player;
            break;

          case 5:
            //Subtract points for athlete
            cout << "Triple axels landed to subtract? ";
            cin >> points;
            cin.ignore(100, '\n');

            //Check for valid input.
            if (cin.fail())
            {
              cin.clear();
              cin.ignore(100, '\n');
              b_input.bad_int = 0;
              throw b_input;
            }

            player -= points;
            skaters += player;
            break;

          case 6:
            //Remove athlete
            cout << "Enter athlete's name: ";
            cin.get(temp_name, SIZE, '\n');
            cin.ignore(100, '\n');

            length = strlen(temp_name);

            //Capitalize first letter and anything after a space.
            temp_name[0] = toupper(temp_name[0]);

            for (int i = 1; i < length; ++i)
            {
              if (temp_name[i - 1] == ' ')
                temp_name[i] = toupper(temp_name[i]);
            }

            skaters -= temp_name;
            break;

          case 7:
            //Remove all athletes
            cout << "Enter 'ALL ATHLETES' to remove all: ";
            cin.get(temp_name, SIZE, '\n');
            cin.ignore(100, '\n');

            length = strlen(temp_name);

            //Capitalize all letters.
            for (int i = 0; i < length; ++i)
            {
              temp_name[i] = toupper(temp_name[i]);
            }

            skaters -= temp_name;
            break;

          default:
            cout << "Default should not get called." << endl;
            break;
        }
      }

      //Catch any errors that may have occurred when choosing a switch option.
      catch (...)
      {
        cout << "That is not a valid response. Try again." << endl << endl;
      }

      cout << "See the list of figure skaters submenu again? Yes (Y) or No (N): ";
  
    } while (again()); //Returns whether user enters Yes or No

    cout << "Exiting submenu..." << endl << endl;
    return;
}



//This function tests the functionality of the 'BST' class. It tests 
//for insert, remove, remove all, retrieve, display all, and its operators that
//are overloaded. It takes no arguments and has a void return type.
void test_BST()
{
    using namespace std;

    //Variable definitions
    char temp_name[SIZE]; //Hold various temporary array responses
    int length {0};       //Length of temporary array responses
    int option {0};       //User options to manage a list
    int points {0};       //User inputted points scored
    BAD_INPUT b_input;    //Users incorrect input if needed
    figure_skate player;  //Figure skating object
    BST skaters;          //Collection of figure skaters
    BST temp_BST;         //Temporary BST object
    BST skaters_copy;     //Copy of figure skaters
  
    do
    {
      cout << "\nWhat would you like to do?\n"
           << "1 - Add figure skater - test 1\n"
           << "2 - Add figure skater - test 2\n"
           << "3 - Add figure skater - test3\n"
           << "4 - Display figure skater\n"
           << "5 - Display all figure skaters\n"
           << "6 - Copy list of figure skaters\n"
           << "7 - Add points to most recently added figure skater\n"
           << "8 - Subtract points from most recently added figure skater\n"
           << "9 - Remove figure skater - test 1\n"
           << "10 - Remove figure skater - test 2\n"
           << "11 - Remove figure skater - test 3\n"
           << "12 - Remove all skaters by entering 'ALL ATHLETES'\n"
           << endl;

      cout << "Enter a whole number: ";
      cin >> option;
      cin.ignore(100, '\n');

      //Make sure user chooses a number between 1 and 12. Otherwise, throw a
      //BAD_INPUT structure and have them try again.
      try
      {
        if (option < 1 || option > 12 || cin.fail())
        {
          cin.clear();
          cin.ignore(100, '\n');
          b_input.bad_int = 0;
          throw b_input;
        }

        switch (option)
        {
          case 1:
            //Add an athlete
            cin >> player;
            temp_BST = skaters + player;
            skaters = temp_BST;
            break;

          case 2:
            //Add an athlete
            cin >> player;
            temp_BST = player + skaters;
            skaters = temp_BST;
            break;

          case 3:
            //Add an athlete
            cin >> player;
            skaters += player;
            break;

          case 4:
            //Display athlete
            cout << "Enter athlete's name: ";
            cin.get(temp_name, SIZE, '\n');
            cin.ignore(100, '\n');
  
            length = strlen(temp_name);

            //Capitalize first letter and anything after a space.
            temp_name[0] = toupper(temp_name[0]);

            for (int i = 1; i < length; ++i)
            {
              if (temp_name[i - 1] == ' ')
                temp_name[i] = toupper(temp_name[i]);
            }

            if (!(skaters == temp_name))
              cout << "No match found" << endl << endl;
            break;

          case 5:
            //Display all athletes
            cout << skaters << endl << endl;
            break;

          case 6:
            //Copy to another list
            skaters_copy = skaters;
            cout << "Copied list: " << endl << endl;
            cout << skaters_copy << endl << endl;
            break;

          case 7:
            //Add points for athlete
            cout << "Triple axels landed to add? ";
            cin >> points;
            cin.ignore(100, '\n');

            //Check for valid input.
            if (cin.fail())
            {
              cin.clear();
              cin.ignore(100, '\n');
              b_input.bad_int = 0;
              throw b_input;
            }

            player += points;
            skaters += player;
            break;

          case 8:
            //Subtract points for athlete
            cout << "Triple axels landed to subtract? ";
            cin >> points;
            cin.ignore(100, '\n');

            //Check for valid input.
            if (cin.fail())
            {
              cin.clear();
              cin.ignore(100, '\n');
              b_input.bad_int = 0;
              throw b_input;
            }

            player -= points;
            skaters += player;
            break;

          case 9:
            //Remove athlete
            cout << "Enter athlete's name: ";
            cin.get(temp_name, SIZE, '\n');
            cin.ignore(100, '\n');

            length = strlen(temp_name);

            //Capitalize first letter and anything after a space.
            temp_name[0] = toupper(temp_name[0]);

            for (int i = 1; i < length; ++i)
            {
              if (temp_name[i - 1] == ' ')
                temp_name[i] = toupper(temp_name[i]);
            }

            temp_BST = skaters - temp_name;
            skaters = temp_BST;
            break;

          case 10:
            //Remove athlete
            cout << "Enter athlete's name: ";
            cin.get(temp_name, SIZE, '\n');
            cin.ignore(100, '\n');

            length = strlen(temp_name);

            //Capitalize first letter and anything after a space.
            temp_name[0] = toupper(temp_name[0]);

            for (int i = 1; i < length; ++i)
            {
              if (temp_name[i - 1] == ' ')
                temp_name[i] = toupper(temp_name[i]);
            }

            //This would not make sense in the real world. This function has
            //been tweaked to remove an athlete from the list.
            temp_BST = temp_name - skaters;
            skaters = temp_BST;
            break;

          case 11:
            //Remove athlete
            cout << "Enter athlete's name: ";
            cin.get(temp_name, SIZE, '\n');
            cin.ignore(100, '\n');

            length = strlen(temp_name);

            //Capitalize first letter and anything after a space.
            temp_name[0] = toupper(temp_name[0]);

            for (int i = 1; i < length; ++i)
            {
              if (temp_name[i - 1] == ' ')
                temp_name[i] = toupper(temp_name[i]);
            }

            skaters -= temp_name;
            break;

          case 12:
            //Remove all athletes
            cout << "Enter 'ALL ATHLETES' to remove all: ";
            cin.get(temp_name, SIZE, '\n');
            cin.ignore(100, '\n');

            length = strlen(temp_name);

            //Capitalize all letters.
            for (int i = 0; i < length; ++i)
            {
              temp_name[i] = toupper(temp_name[i]);
            }

            skaters -= temp_name;
            break;

          default:
            cout << "You shouldn't be here!" << endl;
            break;
        }
      }

      //Catch any errors that may have occurred when choosing a switch option.
      catch (...)
      {
        cout << "That is not a valid response." << endl << endl;
      }

      cout << "See the BST test menu again? Yes (Y) or No (N): ";
  
    } while (again()); //Returns whether user enters Yes or No

    cout << "Exiting BST test..." << endl << endl;
    return;
}



//This function tests the functionality of the 'bobsled' class. It tests 
//for input, output, and operator overloading. It takes no arguments and has a
//void return type.
void test_bobsledder()
{
    using namespace std;

    //Variable definitions
    char temp_name[SIZE]; //Hold various temporary array responses
    int length {0};       //Length of temporary array responses
    int option {0};       //User options to manage a list
    int points {0};       //User inputted points scored
    BAD_INPUT b_input;    //Users incorrect input if needed
    bobsled player1;     //Bobsledder object 1
    bobsled player2;     //Bobsledder object 2
    bobsled temp;        //Temporary bobsledder object
  
    do
    {
      cout << "\nWhat would you like to do?\n"
           << "1 - Add bobsledder 1\n"
           << "2 - Display bobsledder 1\n"
           << "3 - Display bobsledder 2\n"
           << "4 - Copy to bobsledder 2\n"
           << "5 - Add points to bobsledder 1\n"
           << "6 - Add points to bobsledder 1\n"
           << "7 - Add points to bobsledder 2\n"
           << "8 - Subtract points from bobsledder 1\n"
           << "9 - Subtract points from bobsledder 1\n"
           << "10 - Subtract points from bobsledder 2\n"
           << "11 - Bobsledder 1's name vs. Bobsledder 2's name\n"
           << endl;

      cout << "Enter a whole number: ";
      cin >> option;
      cin.ignore(100, '\n');

      //Make sure user chooses a number between 1 and 11. Otherwise, throw a
      //BAD_INPUT structure and have them try again.
      try
      {
        if (option < 1 || option > 11 || cin.fail())
        {
          cin.clear();
          cin.ignore(100, '\n');
          b_input.bad_int = 0;
          throw b_input;
        }

        switch (option)
        {
          case 1:
            //Add an athlete
            cin >> player1;
            break;

          case 2:
            //Display athlete 1
            cout << player1;
            break;

          case 3:
            //Display athlete 2
            cout << player2;
            break;

          case 4:
            //Copy to athlete 2
            player2 = player1;
            break;

          case 5:
            //Add points to athlete 1
            cout << "How many minutes to subtract from race time? ";
            cin >> points;
            cin.ignore(100, '\n');

            //Check for valid input.
            if (cin.fail())
            {
              cin.clear();
              cin.ignore(100, '\n');
              b_input.bad_int = 0;
              throw b_input;
            }

            temp = player1 - points;
            player1 = temp;
            cout << player1;
            break;

          case 6:
            //Add points to athlete 1
            cout << "How many minutes to subtract from race time? ";
            cin >> points;
            cin.ignore(100, '\n');

            //Check for valid input.
            if (cin.fail())
            {
              cin.clear();
              cin.ignore(100, '\n');
              b_input.bad_int = 0;
              throw b_input;
            }

            //This would not really make sense in the real world. Function is
            //tweaked to still subtract from player.
            temp = points - player1;
            player1 = temp;
            cout << player1;
            break;

          case 7:
            //Add points to athlete 2
            cout << "How many minutes to subtract from race time? ";
            cin >> points;
            cin.ignore(100, '\n');

            //Check for valid input.
            if (cin.fail())
            {
              cin.clear();
              cin.ignore(100, '\n');
              b_input.bad_int = 0;
              throw b_input;
            }

            player2 -= points;
            cout << player2;
            break;

          case 8:
            //Subtract points from athlete 1
            cout << "How many minutes to add to race time? ";
            cin >> points;
            cin.ignore(100, '\n');

            //Check for valid input.
            if (cin.fail())
            {
              cin.clear();
              cin.ignore(100, '\n');
              b_input.bad_int = 0;
              throw b_input;
            }

            temp = player1 + points;
            player1 = temp;
            cout << player1;
            break;

          case 9:
            //Subtract points from athlete 1
            cout << "How many minutes to add to race time? ";
            cin >> points;
            cin.ignore(100, '\n');

            //Check for valid input.
            if (cin.fail())
            {
              cin.clear();
              cin.ignore(100, '\n');
              b_input.bad_int = 0;
              throw b_input;
            }

            temp = points + player1;
            player1 = temp;
            cout << player1;
            break;

          case 10:
            //Subtract points from athlete 2
            cout << "How many minutes to add to race time? ";
            cin >> points;
            cin.ignore(100, '\n');

            //Check for valid input.
            if (cin.fail())
            {
              cin.clear();
              cin.ignore(100, '\n');
              b_input.bad_int = 0;
              throw b_input;
            }

            player2 += points;
            cout << player2;
            break;

          case 11:
            //Compare athletes
            cout << "Enter a name: ";
            cin.get(temp_name, SIZE, '\n');
            cin.ignore(100, '\n');

            length = strlen(temp_name);

            //Capitalize first letter and anything after a space.
            temp_name[0] = toupper(temp_name[0]);

            for (int i = 1; i < length; ++i)
            {
              if (temp_name[i - 1] == ' ')
                temp_name[i] = toupper(temp_name[i]);
            }

            cout << "\nFirst, is athlete 1's name less than athlete 2's?" 
                 << endl;
            if (player1 < player2)
              cout << "YES!" << endl;
            else
              cout << "NO!" << endl;

            cout << "\nIs athlete 1 less than " << temp_name << "?" << endl;
            if (player1 < temp_name)
              cout << "YES!" << endl;
            else
              cout << "NO!" << endl;

            cout << "\nIs " << temp_name << " less than athlete 2?" << endl;
            if (temp_name < player2)
              cout << "YES!" << endl;
            else
              cout << "NO!" << endl;

            cout << "\nSecond, is athlete 1's name less or equal to athlete "
                 << "2's?" << endl;
            if (player1 <= player2)
              cout << "YES!" << endl;
            else
              cout << "NO!" << endl;

            cout << "\nIs athlete 1 less than or equal to " << temp_name << "?" 
                 << endl;
            if (player1 <= temp_name)
              cout << "YES!" << endl;
            else
              cout << "NO!" << endl;

            cout << "\nIs " << temp_name << " less than or equal to athlete 2?" 
                 << endl;
            if (temp_name <= player2)
              cout << "YES!" << endl;
            else
              cout << "NO!" << endl;

            cout << "\nThird, is athlete 1's name greater than athlete 2's?" 
                 << endl;
            if (player1 > player2)
              cout << "YES!" << endl;
            else
              cout << "NO!" << endl;

            cout << "\nIs athlete 1 greater than " << temp_name << "?" << endl;
            if (player1 > temp_name)
              cout << "YES!" << endl;
            else
              cout << "NO!" << endl;

            cout << "\nIs " << temp_name << " greater than athlete 2?" << endl;
            if (temp_name > player2)
              cout << "YES!" << endl;
            else
              cout << "NO!" << endl;

            cout << "\nFourth, is athlete 1's name greater than or equal to "
                 << "athlete 2's?" << endl;
            if (player1 >= player2)
              cout << "YES!" << endl;
            else
              cout << "NO!" << endl;

            cout << "\nIs athlete 1 greater than or equal to " << temp_name 
                 << "?" << endl;
            if (player1 >= temp_name)
              cout << "YES!" << endl;
            else
              cout << "NO!" << endl;

            cout << "\nIs " << temp_name << " greater than or equal to "
                 << "athlete 2?" << endl;
            if (temp_name >= player2)
              cout << "YES!" << endl;
            else
              cout << "NO!" << endl;

            cout << "\nIs athlete 1 the same as athlete 2?" << endl;
            if (player1 == player2)
              cout << "YES!" << endl;
            else
              cout << "NO!" << endl;

            cout << "\nIs athlete 1 completely different than athlete 2?" 
                 << endl;
            if (player1 != player2)
              cout << "YES!" << endl;
            else
              cout << "NO!" << endl;
            break;

          default:
            cout << "You shouldn't be here!" << endl;
            break;
        }
      }
  
      //Catch any errors that may have occurred when choosing a switch option.
      catch (...)
      {
        cout << "That is not a valid response." << endl << endl;
      }

      cout << "See the bobsledder test menu again? Yes (Y) or No (N): ";
  
    } while (again()); //Returns whether user enters Yes or No

    cout << "Exiting bobsledder test..." << endl << endl;
    return;
}



//This function tests the functionality of the 'ski_jump' class. It tests 
//for input, output, and operator overloading. It takes no arguments and has a
//void return type.
void test_ski_jumper()
{
    using namespace std;

    //Variable definitions
    char temp_name[SIZE]; //Hold various temporary array responses
    int length {0};       //Length of temporary array responses
    int option {0};       //User options to manage a list
    int points {0};       //User inputted points scored
    BAD_INPUT b_input;    //Users incorrect input if needed
    ski_jump player1;     //Ski jumper object 1
    ski_jump player2;     //Ski jumper object 2
    ski_jump temp;        //Temporary ski jumper object
  
    do
    {
      cout << "\nWhat would you like to do?\n"
           << "1 - Add ski jumper 1\n"
           << "2 - Display ski jumper 1\n"
           << "3 - Display ski jumper 2\n"
           << "4 - Copy to ski jumper 2\n"
           << "5 - Add points to ski jumper 1\n"
           << "6 - Add points to ski jumper 1\n"
           << "7 - Add points to ski jumper 2\n"
           << "8 - Subtract points from ski jumper 1\n"
           << "9 - Subtract points from ski jumper 1\n"
           << "10 - Subtract points from ski jumper 2\n"
           << "11 - Ski jumper 1's name vs. Ski jumper 2's name\n"
           << endl;

      cout << "Enter a whole number: ";
      cin >> option;
      cin.ignore(100, '\n');

      //Make sure user chooses a number between 1 and 11. Otherwise, throw a
      //BAD_INPUT structure and have them try again.
      try
      {
        if (option < 1 || option > 11 || cin.fail())
        {
          cin.clear();
          cin.ignore(100, '\n');
          b_input.bad_int = 0;
          throw b_input;
        }

        switch (option)
        {
          case 1:
            //Add an athlete
            cin >> player1;
            break;

          case 2:
            //Display athlete 1
            cout << player1;
            break;

          case 3:
            //Display athlete 2
            cout << player2;
            break;

          case 4:
            //Copy to athlete 2
            player2 = player1;
            break;

          case 5:
            //Add points to athlete 1
            cout << "How much velocity gained? ";
            cin >> points;
            cin.ignore(100, '\n');

            //Check for valid input.
            if (cin.fail())
            {
              cin.clear();
              cin.ignore(100, '\n');
              b_input.bad_int = 0;
              throw b_input;
            }

            temp = player1 + points;
            player1 = temp;
            cout << player1;
            break;

          case 6:
            //Add points to athlete 1
            cout << "How much velocity gained? ";
            cin >> points;
            cin.ignore(100, '\n');

            //Check for valid input.
            if (cin.fail())
            {
              cin.clear();
              cin.ignore(100, '\n');
              b_input.bad_int = 0;
              throw b_input;
            }

            temp = points + player1;
            player1 = temp;
            cout << player1;
            break;

          case 7:
            //Add points to athlete 2
            cout << "How much velocity gained? ";
            cin >> points;
            cin.ignore(100, '\n');

            //Check for valid input.
            if (cin.fail())
            {
              cin.clear();
              cin.ignore(100, '\n');
              b_input.bad_int = 0;
              throw b_input;
            }

            player2 += points;
            cout << player2;
            break;

          case 8:
            //Subtract points from athlete 1
            cout << "How much velocity lost? ";
            cin >> points;
            cin.ignore(100, '\n');

            //Check for valid input.
            if (cin.fail())
            {
              cin.clear();
              cin.ignore(100, '\n');
              b_input.bad_int = 0;
              throw b_input;
            }

            temp = player1 - points;
            player1 = temp;
            cout << player1;
            break;

          case 9:
            //Subtract points from athlete 1
            cout << "How much velocity lost? ";
            cin >> points;
            cin.ignore(100, '\n');

            //Check for valid input.
            if (cin.fail())
            {
              cin.clear();
              cin.ignore(100, '\n');
              b_input.bad_int = 0;
              throw b_input;
            }

            //This would not really make sense in the real world. Function is
            //tweaked to still subtract from player.
            temp = points - player1;
            player1 = temp;
            cout << player1;
            break;

          case 10:
            //Subtract points from athlete 2
            cout << "How much velocity lost? ";
            cin >> points;
            cin.ignore(100, '\n');

            //Check for valid input.
            if (cin.fail())
            {
              cin.clear();
              cin.ignore(100, '\n');
              b_input.bad_int = 0;
              throw b_input;
            }

            player2 -= points;
            cout << player2;
            break;

          case 11:
            //Compare athletes
            cout << "Enter a name: ";
            cin.get(temp_name, SIZE, '\n');
            cin.ignore(100, '\n');

            length = strlen(temp_name);

            //Capitalize first letter and anything after a space.
            temp_name[0] = toupper(temp_name[0]);

            for (int i = 1; i < length; ++i)
            {
              if (temp_name[i - 1] == ' ')
                temp_name[i] = toupper(temp_name[i]);
            }

            cout << "\nFirst, is athlete 1's name less than athlete 2's?" 
                 << endl;
            if (player1 < player2)
              cout << "YES!" << endl;
            else
              cout << "NO!" << endl;

            cout << "\nIs athlete 1 less than " << temp_name << "?" << endl;
            if (player1 < temp_name)
              cout << "YES!" << endl;
            else
              cout << "NO!" << endl;

            cout << "\nIs " << temp_name << " less than athlete 2?" << endl;
            if (temp_name < player2)
              cout << "YES!" << endl;
            else
              cout << "NO!" << endl;

            cout << "\nSecond, is athlete 1's name less or equal to athlete "
                 << "2's?" << endl;
            if (player1 <= player2)
              cout << "YES!" << endl;
            else
              cout << "NO!" << endl;

            cout << "\nIs athlete 1 less than or equal to " << temp_name << "?" 
                 << endl;
            if (player1 <= temp_name)
              cout << "YES!" << endl;
            else
              cout << "NO!" << endl;

            cout << "\nIs " << temp_name << " less than or equal to athlete 2?" 
                 << endl;
            if (temp_name <= player2)
              cout << "YES!" << endl;
            else
              cout << "NO!" << endl;

            cout << "\nThird, is athlete 1's name greater than athlete 2's?" 
                 << endl;
            if (player1 > player2)
              cout << "YES!" << endl;
            else
              cout << "NO!" << endl;

            cout << "\nIs athlete 1 greater than " << temp_name << "?" << endl;
            if (player1 > temp_name)
              cout << "YES!" << endl;
            else
              cout << "NO!" << endl;

            cout << "\nIs " << temp_name << " greater than athlete 2?" << endl;
            if (temp_name > player2)
              cout << "YES!" << endl;
            else
              cout << "NO!" << endl;

            cout << "\nFourth, is athlete 1's name greater than or equal to "
                 << "athlete 2's?" << endl;
            if (player1 >= player2)
              cout << "YES!" << endl;
            else
              cout << "NO!" << endl;

            cout << "\nIs athlete 1 greater than or equal to " << temp_name 
                 << "?" << endl;
            if (player1 >= temp_name)
              cout << "YES!" << endl;
            else
              cout << "NO!" << endl;

            cout << "\nIs " << temp_name << " greater than or equal to "
                 << "athlete 2?" << endl;
            if (temp_name >= player2)
              cout << "YES!" << endl;
            else
              cout << "NO!" << endl;

            cout << "\nIs athlete 1 the same as athlete 2?" << endl;
            if (player1 == player2)
              cout << "YES!" << endl;
            else
              cout << "NO!" << endl;

            cout << "\nIs athlete 1 completely different than athlete 2?" 
                 << endl;
            if (player1 != player2)
              cout << "YES!" << endl;
            else
              cout << "NO!" << endl;
            break;

          default:
            cout << "You shouldn't be here!" << endl;
            break;
        }
      }
  
      //Catch any errors that may have occurred when choosing a switch option.
      catch (...)
      {
        cout << "That is not a valid response." << endl << endl;
      }

      cout << "See the ski jumper test menu again? Yes (Y) or No (N): ";
  
    } while (again()); //Returns whether user enters Yes or No

    cout << "Exiting ski jumper test..." << endl << endl;
    return;
}



//This function tests the functionality of the 'figure_skate' class. It tests 
//for input, output, and operator overloading. It takes no arguments and has a
//void return type.
void test_figure_skater()
{
    using namespace std;

    //Variable definitions
    char temp_name[SIZE]; //Hold various temporary array responses
    int length {0};       //Length of temporary array responses
    int option {0};       //User options to manage a list
    int points {0};       //User inputted points scored
    BAD_INPUT b_input;    //Users incorrect input if needed
    figure_skate player1; //General figure skater object 1
    figure_skate player2; //General figure skater object 2
    figure_skate temp;    //Temporary figure skater object
  
    do
    {
      cout << "\nWhat would you like to do?\n"
           << "1 - Add figure skater 1\n"
           << "2 - Display figure skater 1\n"
           << "3 - Display figure skater 2\n"
           << "4 - Copy to figure skater 2\n"
           << "5 - Add points to figure skater 1\n"
           << "6 - Add points to figure skater 1\n"
           << "7 - Add points to figure skater 2\n"
           << "8 - Subtract points from figure skater 1\n"
           << "9 - Subtract points from figure skater 1\n"
           << "10 - Subtract points from figure skater 2\n"
           << "11 - Figure skater 1's name vs. Figure skater 2's name\n"
           << endl;

      cout << "Enter a whole number: ";
      cin >> option;
      cin.ignore(100, '\n');

      //Make sure user chooses a number between 1 and 11. Otherwise, throw a
      //BAD_INPUT structure and have them try again.
      try
      {
        if (option < 1 || option > 11 || cin.fail())
        {
          cin.clear();
          cin.ignore(100, '\n');
          b_input.bad_int = 0;
          throw b_input;
        }

        switch (option)
        {
          case 1:
            //Add an athlete
            cin >> player1;
            break;

          case 2:
            //Display athlete 1
            cout << player1;
            break;

          case 3:
            //Display athlete 2
            cout << player2;
            break;

          case 4:
            //Copy to athlete 2
            player2 = player1;
            break;

          case 5:
            //Add points to athlete 1
            cout << "How many more axels landed? ";
            cin >> points;
            cin.ignore(100, '\n');

            //Check for valid input.
            if (cin.fail())
            {
              cin.clear();
              cin.ignore(100, '\n');
              b_input.bad_int = 0;
              throw b_input;
            }

            temp = player1 + points;
            player1 = temp;
            cout << player1;
            break;

          case 6:
            //Add points to athlete 1
            cout << "How many more axels landed? ";
            cin >> points;
            cin.ignore(100, '\n');

            //Check for valid input.
            if (cin.fail())
            {
              cin.clear();
              cin.ignore(100, '\n');
              b_input.bad_int = 0;
              throw b_input;
            }

            temp = points + player1;
            player1 = temp;
            cout << player1;
            break;

          case 7:
            //Add points to athlete 2
            cout << "How many more axels landed? ";
            cin >> points;
            cin.ignore(100, '\n');

            //Check for valid input.
            if (cin.fail())
            {
              cin.clear();
              cin.ignore(100, '\n');
              b_input.bad_int = 0;
              throw b_input;
            }

            player2 += points;
            cout << player2;
            break;

          case 8:
            //Subtract points from athlete 1
            cout << "How many fewer axels landed? ";
            cin >> points;
            cin.ignore(100, '\n');

            //Check for valid input.
            if (cin.fail())
            {
              cin.clear();
              cin.ignore(100, '\n');
              b_input.bad_int = 0;
              throw b_input;
            }

            temp = player1 - points;
            player1 = temp;
            cout << player1;
            break;

          case 9:
            //Subtract points from athlete 1
            cout << "How many fewer axels landed? ";
            cin >> points;
            cin.ignore(100, '\n');

            //Check for valid input.
            if (cin.fail())
            {
              cin.clear();
              cin.ignore(100, '\n');
              b_input.bad_int = 0;
              throw b_input;
            }

            //This would not really make sense in the real world. Function is
            //tweaked to still subtract from player.
            temp = points - player1;
            player1 = temp;
            cout << player1;
            break;

          case 10:
            //Subtract points from athlete 2
            cout << "How many fewer axels landed? ";
            cin >> points;
            cin.ignore(100, '\n');

            //Check for valid input.
            if (cin.fail())
            {
              cin.clear();
              cin.ignore(100, '\n');
              b_input.bad_int = 0;
              throw b_input;
            }

            player2 -= points;
            cout << player2;
            break;

          case 11:
            //Compare athletes
            cout << "Enter a name: ";
            cin.get(temp_name, SIZE, '\n');
            cin.ignore(100, '\n');

            length = strlen(temp_name);

            //Capitalize first letter and anything after a space.
            temp_name[0] = toupper(temp_name[0]);

            for (int i = 1; i < length; ++i)
            {
              if (temp_name[i - 1] == ' ')
                temp_name[i] = toupper(temp_name[i]);
            }

            cout << "\nFirst, is athlete 1's name less than athlete 2's?" 
                 << endl;
            if (player1 < player2)
              cout << "YES!" << endl;
            else
              cout << "NO!" << endl;

            cout << "\nIs athlete 1 less than " << temp_name << "?" << endl;
            if (player1 < temp_name)
              cout << "YES!" << endl;
            else
              cout << "NO!" << endl;

            cout << "\nIs " << temp_name << " less than athlete 2?" << endl;
            if (temp_name < player2)
              cout << "YES!" << endl;
            else
              cout << "NO!" << endl;

            cout << "\nSecond, is athlete 1's name less or equal to athlete "
                 << "2's?" << endl;
            if (player1 <= player2)
              cout << "YES!" << endl;
            else
              cout << "NO!" << endl;

            cout << "\nIs athlete 1 less than or equal to " << temp_name << "?" 
                 << endl;
            if (player1 <= temp_name)
              cout << "YES!" << endl;
            else
              cout << "NO!" << endl;

            cout << "\nIs " << temp_name << " less than or equal to athlete 2?" 
                 << endl;
            if (temp_name <= player2)
              cout << "YES!" << endl;
            else
              cout << "NO!" << endl;

            cout << "\nThird, is athlete 1's name greater than athlete 2's?" 
                 << endl;
            if (player1 > player2)
              cout << "YES!" << endl;
            else
              cout << "NO!" << endl;

            cout << "\nIs athlete 1 greater than " << temp_name << "?" << endl;
            if (player1 > temp_name)
              cout << "YES!" << endl;
            else
              cout << "NO!" << endl;

            cout << "\nIs " << temp_name << " greater than athlete 2?" << endl;
            if (temp_name > player2)
              cout << "YES!" << endl;
            else
              cout << "NO!" << endl;

            cout << "\nFourth, is athlete 1's name greater than or equal to "
                 << "athlete 2's?" << endl;
            if (player1 >= player2)
              cout << "YES!" << endl;
            else
              cout << "NO!" << endl;

            cout << "\nIs athlete 1 greater than or equal to " << temp_name 
                 << "?" << endl;
            if (player1 >= temp_name)
              cout << "YES!" << endl;
            else
              cout << "NO!" << endl;

            cout << "\nIs " << temp_name << " greater than or equal to "
                 << "athlete 2?" << endl;
            if (temp_name >= player2)
              cout << "YES!" << endl;
            else
              cout << "NO!" << endl;

            cout << "\nIs athlete 1 the same as athlete 2?" << endl;
            if (player1 == player2)
              cout << "YES!" << endl;
            else
              cout << "NO!" << endl;

            cout << "\nIs athlete 1 completely different than athlete 2?"
                 << endl;
            if (player1 != player2)
              cout << "YES!" << endl;
            else
              cout << "NO!" << endl;
            break;

          default:
            cout << "What would you like to do?" << endl;
            break;
        }
      }

      //Catch any errors that may have occurred when choosing a switch option.
      catch (...)
      {
        cout << "That is not a valid response." << endl << endl;
      }

      cout << "See the figure skater test menu again? Yes (Y) or No (N): ";
  
    } while (again()); //Returns whether user enters Yes or No

    cout << "Exiting figure skater test..." << endl << endl;
    return;
}



//This function tests the functionality of the 'athlete' class. It tests for
//input, output, comparison, and operator overloading. It takes no arguments
//and has a void return type.
void test_athlete()
{
    using namespace std;

    //Variable definitions
    char temp_name[SIZE];//Hold various temporary array responses
    int length {0};       //Length of temporary array responses
    int option {0};      //User options to manage a list
    int points {0};      //User inputted points scored
    BAD_INPUT b_input;   //Users incorrect input if needed
    athlete player1;     //General athlete object 1
    athlete player2;     //General athlete object 2
    athlete temp;        //Temporary athlete object
  
    do
    {
      cout << "\nWhat would you like to do?\n"
           << "1 - Add athlete 1\n"
           << "2 - Display athlete 1\n"
           << "3 - Display athlete 2\n"
           << "4 - Copy to athlete 2\n"
           << "5 - Add points to athlete 1\n"
           << "6 - Add points to athlete 1\n"
           << "7 - Add points to athlete 2\n"
           << "8 - Subtract points from athlete 1\n"
           << "9 - Subtract points from athlete 1\n"
           << "10 - Subtract points from athlete 2\n"
           << "11 - Athlete 1's name vs. Athlete 2's name\n"
           << endl;

      cout << "Enter a whole number: ";
      cin >> option;
      cin.ignore(100, '\n');

      //Make sure user chooses a number between 1 and 11. Otherwise, throw a
      //BAD_INPUT structure and have them try again.
      try
      {
        if (option < 1 || option > 11 || cin.fail())
        {
          cin.clear();
          cin.ignore(100, '\n');
          b_input.bad_int = 0;
          throw b_input;
        }

        switch (option)
        {
          case 1:
            //Add an athlete
            cin >> player1;
            break;

          case 2:
            //Display athlete 1
            cout << player1;
            break;

          case 3:
            //Display athlete 2
            cout << player2;
            break;

          case 4:
            //Copy to athlete 2
            player2 = player1;
            break;

          case 5:
            //Add points to athlete 1
            cout << "How many points? ";
            cin >> points;
            cin.ignore(100, '\n');

            //Check for valid input.
            if (cin.fail())
            {
              cin.clear();
              cin.ignore(100, '\n');
              b_input.bad_int = 0;
              throw b_input;
            }

            temp = player1 + points;
            player1 = temp;
            cout << player1;
            break;

          case 6:
            //Add points to athlete 1
            cout << "How many points? ";
            cin >> points;
            cin.ignore(100, '\n');

            //Check for valid input.
            if (cin.fail())
            {
              cin.clear();
              cin.ignore(100, '\n');
              b_input.bad_int = 0;
              throw b_input;
            }

            temp = points + player1;
            player1 = temp;
            cout << player1;
            break;

          case 7:
            //Add points to athlete 2
            cout << "How many points? ";
            cin >> points;
            cin.ignore(100, '\n');

            //Check for valid input.
            if (cin.fail())
            {
              cin.clear();
              cin.ignore(100, '\n');
              b_input.bad_int = 0;
              throw b_input;
            }

            player2 += points;
            cout << player2;
            break;

          case 8:
            //Subtract points from athlete 1
            cout << "How many points? ";
            cin >> points;
            cin.ignore(100, '\n');

            //Check for valid input.
            if (cin.fail())
            {
              cin.clear();
              cin.ignore(100, '\n');
              b_input.bad_int = 0;
              throw b_input;
            }

            temp = player1 - points;
            player1 = temp;
            cout << player1;
            break;

          case 9:
            //Subtract points from athlete 1
            cout << "How many points? ";
            cin >> points;
            cin.ignore(100, '\n');

            //Check for valid input.
            if (cin.fail())
            {
              cin.clear();
              cin.ignore(100, '\n');
              b_input.bad_int = 0;
              throw b_input;
            }

            //This would not really make sense in the real world. Function is
            //tweaked to still subtract from player.
            temp = points - player1;
            player1 = temp;
            cout << player1;
            break;

          case 10:
            //Subtract points from athlete 2
            cout << "How many points? ";
            cin >> points;
            cin.ignore(100, '\n');

            //Check for valid input.
            if (cin.fail())
            {
              cin.clear();
              cin.ignore(100, '\n');
              b_input.bad_int = 0;
              throw b_input;
            }

            player2 -= points;
            cout << player2;
            break;

          case 11:
            //Compare athletes
            cout << "Enter a name: ";
            cin.get(temp_name, SIZE, '\n');
            cin.ignore(100, '\n');

            length = strlen(temp_name);

            //Capitalize first letter and anything after a space.
            temp_name[0] = toupper(temp_name[0]);

            for (int i = 1; i < length; ++i)
            {
              if (temp_name[i - 1] == ' ')
                temp_name[i] = toupper(temp_name[i]);
            }

            cout << "\nFirst, is athlete 1's name less than athlete 2's?" 
                 << endl;
            if (player1 < player2)
              cout << "YES!" << endl;
            else
              cout << "NO!" << endl;

            cout << "\nIs athlete 1 less than " << temp_name << "?" << endl;
            if (player1 < temp_name)
              cout << "YES!" << endl;
            else
              cout << "NO!" << endl;

            cout << "\nIs " << temp_name << " less than athlete 2?" << endl;
            if (temp_name < player2)
              cout << "YES!" << endl;
            else
              cout << "NO!" << endl;

            cout << "\nSecond, is athlete 1's name less or equal to athlete "
                 << "2's?" << endl;
            if (player1 <= player2)
              cout << "YES!" << endl;
            else
              cout << "NO!" << endl;

            cout << "\nIs athlete 1 less than or equal to " << temp_name << "?" 
                 << endl;
            if (player1 <= temp_name)
              cout << "YES!" << endl;
            else
              cout << "NO!" << endl;

            cout << "\nIs " << temp_name << " less than or equal to athlete 2?" 
                 << endl;
            if (temp_name <= player2)
              cout << "YES!" << endl;
            else
              cout << "NO!" << endl;

            cout << "\nThird, is athlete 1's name greater than athlete 2's?" 
                 << endl;
            if (player1 > player2)
              cout << "YES!" << endl;
            else
              cout << "NO!" << endl;

            cout << "\nIs athlete 1 greater than " << temp_name << "?" << endl;
            if (player1 > temp_name)
              cout << "YES!" << endl;
            else
              cout << "NO!" << endl;

            cout << "\nIs " << temp_name << " greater than athlete 2?" << endl;
            if (temp_name > player2)
              cout << "YES!" << endl;
            else
              cout << "NO!" << endl;

            cout << "\nFourth, is athlete 1's name greater than or equal to "
                 << "athlete 2's?" << endl;
            if (player1 >= player2)
              cout << "YES!" << endl;
            else
              cout << "NO!" << endl;

            cout << "\nIs athlete 1 greater than or equal to " << temp_name 
                 << "?" << endl;
            if (player1 >= temp_name)
              cout << "YES!" << endl;
            else
              cout << "NO!" << endl;

            cout << "\nIs " << temp_name << " greater than or equal to "
                 << "athlete 2?" << endl;
            if (temp_name >= player2)
              cout << "YES!" << endl;
            else
              cout << "NO!" << endl;

            cout << "\nIs athlete 1 the same as athlete 2?" << endl;
            if (player1 == player2)
              cout << "YES!" << endl;
            else
              cout << "NO!" << endl;

            cout << "\nIs athlete 1 completely different than athlete 2?" 
                 << endl;
            if (player1 != player2)
              cout << "YES!" << endl;
            else
              cout << "NO!" << endl;
            break;

          default:
            cout << "You shouldn't be here!" << endl;
            break;
        }
      }

      //Catch any errors that may have occurred when choosing a switch option.
      catch (...)
      {
        cout << "That is not a valid response." << endl << endl;
      }

      cout << "See the athlete test menu again? Yes (Y) or No (N): ";
  
    } while (again()); //Returns whether user enters Yes or No

    cout << "Exiting athlete test..." << endl << endl;
    return;
}

