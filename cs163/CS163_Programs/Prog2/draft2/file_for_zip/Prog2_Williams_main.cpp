#include "Prog2_Williams_stack.h"
using namespace std;

// *****************************************************************************
// Author: Connor Williams
// Date: July 16, 2021
// Course: CS163 Data Structures
// Assignment: Program 2
// Filename: Prog2_Williams_main.cpp
// *****************************************************************************
// This file contains the necessary variables, objects, and function calls to 
// test for the successful operations of creating, manipulating, and removing
// task items to complete an activity to and from a queue of tasks. The queue of
// those tasks or the full activity can then be added to or removed from a 
// stack. In terms of the queue of tasks, a user can add to an empty list or a 
// list of already added tasks at the rear. The user can test whether the list 
// is empty by using calling the "display_all" function. The user can do similar 
// operations with the stack of queues, creating and displaying a queue (list of
// tasks) from the top of the stack. The user can also remove tasks from the
// front of a queue and remove a queue from the top of a stack. All program 
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
  queue learn_copy;    //Copy to this object for debugging purposes



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
         << "\t4) Copy the activity (for debugging)\n"
         << "\t5) Display the copy (for debugging)\n"
         << "\t10) Exit program\n"
         << "\t\t\tMORE OPTIONS COMING SOON....................."
         << endl << endl;

    cout << "Enter a number from the menu: ";
    cin >> menu_option;
    cin.ignore(100, '\n');

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
        //Check that the copy function works and display for debugging purposes
        if(!learn_piano.copy(learn_copy))
          cerr << "There's nothing to copy...\n\n";
        break;
    
      case 5:
        //Check and display the copy
        if (!learn_copy.display_all())
          cerr << "There's nothing to display...\n\n";
        break;

      case 10:
        //Exit the program
        cout << "Exiting program" << endl << endl;
        break;

      default:
        cout << "That's not an option. Try again..." << endl << endl;
    } 

  } while (menu_option != 10);

  return 0;
}
