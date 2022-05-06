#include "Prog2_Williams_stack.h"
using namespace std;

// *****************************************************************************
// Author: Connor Williams
// Date: July 23, 2021
// Course: CS163 Data Structures
// Assignment: Program 2
// Filename: Prog2_Williams_main.cpp
// *****************************************************************************
// This file contains the necessary variables, objects, and function calls to 
// test for the successful operations of creating, manipulating, and removing
// task items to complete an activity. Each task item will be held in a "task"
// object, each list of task items to complete an activity will be held in a
// "queue" object, and all "queue" objects, or activity attempts, will be held
// in a "stack" object. Tasks can be added to the rear, or back, of the queue 
// list or removed from the front. A queue can then be added to or removed from 
// the top of a stack, meaning the first item in the stack's list. The user can 
// test whether the lists are empty by calling display functions to print out 
// the current user created queue, the top of the stack (most recent queue
// added), or every queue added to the stack in order from the most recent to
// the oldest. If the user removes a queue from the top of the stack, it will be
// copied, allowing the user to still display the deleted queue. All program 
// options/tests are listed in a text-based menu format.
// *****************************************************************************



int main()
{
  //Variable definitions
  int task_num = 0;    //User inputted task number for a specific activity
  char plan[SIZE];     //User inputted task description for a specific activity
  char notes[SIZE];    //User inputted task notes for a specific activity
  int menu_option = 0; //User inputted menu option choice
  task piano_task;     //Object to hold one task for learning the piano
  queue learn_piano;   //Object holds all tasks for learning the piano
  stack piano_trials;  //Object holds all queues for attempts to learn the piano
  queue trial_removed; //Object holds a queue removed from the top of the stack



  cout << "This application will allow you to add the steps or tasks that it\n"
       << "takes you to complete an activity, such as learning how to play\n"
       << "the piano. What are the steps that it takes to learn the piano?\n"
       << "How could you improve each step or task the next time you try to\n"
       << "learn the piano? You will be able to add each task to a list,\n"
       << "until you feel the activity is complete. You will then be able to\n"
       << "archive that activity attempt into another list for later\n"
       << "reference. This way you can see all the activity attempts in order\n"
       << "from most recent to the oldest.\n\n"
       << "Choose from the menu below to start testing your activity's\n"
       << "algorithm, 'How to learn the piano'."
       << endl;
  do
  {
    cout << "\n\t1) Create a task and add it to the list\n"
         << "\t2) Display all tasks in the current activity\n"
         << "\t3) Remove the first task you added to the list\n"
         << "\t4) Archive the most recent activity\n"
         << "\t5) Display entire archive: most recent to oldest\n"
         << "\t6) Display the most recently archived trial\n"
         << "\t7) Remove the most recently archived trial\n"
         << "\t8) Display the most recently removed trial\n"
         << "\t9) Exit program\n"
         << endl << endl;

    cout << "Enter a number from the menu: ";
    cin >> menu_option;
    cin.ignore(100, '\n');

    //Text-based menu
    switch (menu_option)
    {
      case 1:
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
        if (!piano_task.create_entry(task_num, plan, notes))
          cerr << "There's nothing to add...\n\n";
  
        //Check and add task to queue for an activity
        if (!learn_piano.enqueue(piano_task))
          cerr << "There's nothing to add...\n\n";
        break;
  
      case 2:
        //Check and display the list of tasks for an activity
        if (!learn_piano.display_all())
          cerr << "There's nothing to display...\n\n";
        break;
       
      case 3:
        //Check and remove a task from the front of the queue
        if (!learn_piano.dequeue())
          cerr << "There's nothing to remove...\n\n";
        break;

      case 4:
        //Check and push most recent trial to the top of the archive
        if(!piano_trials.push(learn_piano))
          cerr << "There's nothing to add...\n\n";
        break;
    
      case 5:
        //Check and display the entire archive
        if (!piano_trials.display_all())
          cerr << "There's nothing to display...\n\n";
        break;

      case 6:
        //Check and display the most recently archived trial
        if (!piano_trials.display_top())
          cerr << "There's nothing to display...\n\n";
        break;

      case 7:
        //Check and remove the most recently archived trial
        if (!piano_trials.pop(trial_removed))
          cerr << "There's nothing to remove...\n\n";
        break;

      case 8:
        //Check and display the removed trial
        if (!trial_removed.display_all())
          cerr << "There's nothing to display...\n\n";
        break;

      case 9:
        //Exit the program
        cout << "Exiting program" << endl << endl;
        break;

      default:
        cout << "That's not an option. Try again..." << endl << endl;
    } 

  } while (menu_option != 9);

  return 0;
}
