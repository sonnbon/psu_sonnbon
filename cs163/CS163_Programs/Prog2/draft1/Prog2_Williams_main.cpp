#include "Prog2_Williams_stack.h"
using namespace std;

// *****************************************************************************
// Author: Connor Williams
// Date: July 13, 2021
// Course: CS163 Data Structures
// Assignment: Program 2
// Filename: Prog2_Williams_main.cpp
// *****************************************************************************
//
// *****************************************************************************




int main()
{
  //Variable definitions
  int task_num = 0;  //User inputted task number for a specific activity
  char plan[SIZE];   //User inputted task description for a specific activity
  char notes[SIZE];  //User inputted task notes for a specific activity
  task learn_piano;  //Object to hold one task for learning the piano



  //Take client input to create a task for an activity
  cout << "Please enter the task number: ";
  cin >> task_num;
  cin.ignore(400, '\n');

  cout << "Please enter the task's description: ";
  cin.get(plan, SIZE, '\n');
  cin.ignore(400, '\n');

  cout << "Please enter notes on how to improve the task next time: ";
  cin.get(notes, SIZE, '\n');
  cin.ignore(400, '\n');

  //Check and create a task for an activity
  if (!learn_piano.create_entry(task_num, plan, notes))
    cerr << "There's nothing to add...\n\n";

  //Check and display the created task for the activity
  if (!learn_piano.display())
    cerr << "There's nothing to display...\n\n";

  return 0;
}
