#include <iostream>
#include <cctype>
using namespace std;

// *****************************************************************************
// Connor Williams
// April 14, 2021
// CS162 - Introduction to Computer Science
// Individual Programming Assignment #1
// *****************************************************************************
// This program allows the user to calculate how many commercials can fit in a 
// show that is scheduled for a 60-minute time slot. All variables needed for 
// this program are initialized at the beginning of the main function. The user 
// is first welcomed, explaining what this program is, how it works, and what is
// needed from the user in order for the program to work. The user is informed 
// about restrictions and valid vs. invalid inputs; the restriction is 
// 60-minutes (total_time) and the inputs must be whole numbers from zero to 60 
// (these inputs go to show_length, comm_length, and comm_num). The user is then
// prompted to enter the length of the show they plan to air. If the input 
// (show_length) is out of range, the user will be asked to try again, using a 
// do while loop. Otherwise, the input will be subtracted from total_time. While
// (loop) the new total_time is not equal to zero AND the variable response (for
// later user decisions) is not equal to 'N' (initialized to equal 'Y'), then 
// that variable response is now assigned 'N' and the user is informed of how 
// much time they have left to work with. Next, the user is prompted to enter 
// the length of the commercial they plan to air. Again, if the input 
// (comm_length) is out of range, the user will be asked to try again, using a 
// do while loop. Otherwise, the input will be subtracted from the total_time. 
// If the total_time is not equal to zero, then the comm_length will actually be
// added back to the total_time in case, in the next steps, the user chooses to 
// air this commercial more than once. The user is then prompted to enter how 
// many times they plan to air this commercial. If the input (comm_num) 
// multiplied by the comm_length (comm_total) is out of range, the user will be 
// asked to try again, using a do while loop. Otherwise, the comm_total will be
// subtracted from the total_time. If the total_time is not equal to zero, the 
// user will be informed of how much time they have left to work with. The user 
// will then be asked if they would like to air another commercial. If the input
// (response) is invalid, the user will be asked to try again, using a do while 
// loop. Else if the response is yes (equal to 'Y'), then the user will be able 
// to add another commercial, using a do while loop that envelops the three 
// commercial prompts (length, how many times, and whether to add more). If the
// response is no (equal to 'N'), then the do while loop is broken as well as 
// the preceding while loop (not equal to zero AND response not equal to 'N'), 
// which envelops this do while loop. If, at any point, the total_time is equal 
// to zero, the user will be brought to the same point after this while loop. 
// Now, the program will check, again, if the total_time is equal to zero. If it
// is not, the total_time will be outputted to the user again, informing them 
// that this is the amount of time needed for filler commercials. If it is equal
// to zero, then the user will be informed that they filled the 60-minute time 
// slot. The user will then be asked if they would like to fill in another 
// time_slot (starting over). If the input (response) is out of range, the user 
// will be asked to try again, using a do while loop. If the user response is 
// yes (equal to 'Y'), the counter variable will be assigned 0, and a while loop
// will cout 100 new lines (clearing the screen for new use). A do while loop, 
// enveloping everything up to that point, not including the variable 
// definitions and the welcoming of the user, will bring the user back to the 
// prompt asking what the length of the show should be. Otherwise, if the user 
// response is no (equal to 'N'), then the loop will end and a cout statement 
// will thank the user and exit the program.
// *****************************************************************************

int main()
{
    //Variable definitions
    int total_time = 60;    //Running total (time slot) length set to 60 minutes

    int show_length = 0;    //Show length entered will be subtracted from 
                            //running total
    int comm_length = 0;    //Commercial length entered to be combined with 
                            //commercial frequency
    int comm_num = 0;	    //Commercial frequency entered to be combined with 
                            //commercial length
    int comm_total = 0;     //Be product of commercial length and frequency, 
                            //then will be subtracted from running total
    char response = 'Y';    //Used to determine if user wants to add more 
                            //commercials or start over ('Y' = Yes, 'N' = No) 
    int counter;            //Be used to clear screen (will cout 100 new lines)
                            //if user decides to start over

    //Welcome the user and explain the program
    cout << "Welcome to the 60-Minute Time Slot Calculator Program!" 
	 << endl << endl;

    cout << "This program is meant to help you calculate how many " << endl
	 << "commercials you can fit in a show that is scheduled for " << endl
	 << "a 60-minute time slot." 
	 << endl << endl;
    
    cout << "After inputting how long the show is that is being aired " << endl
	 << "during the time slot of interest, you will then input the " << endl
	 << "length of each commercial and how many times you plan to " << endl
	 << "air them (in minutes)." 
	 << endl << endl;

    cout << "Remember! You only have a 60-minute time slot to work " << endl 
	 << "with. The sum of the length of the show and the " << endl
	 << "commercials must not exceed 60 minutes." 
	 << endl << endl;

    cout << "Please only enter whole numbers from 0 to 60!" 
	 << endl << endl;

    //Do while inputted response is yes (equal to 'Y')
    do
    {
      //Do while length of show inputted is less than zero or greater than
      //the total time left 
      do
      {
        //Prompt and read in the length of the show
        cout << "Please enter the length of the show you plan to air "
	     << "(in minutes): ";
        cin >> show_length;    //Read in the users number

	//Check for valid input
        if (show_length < 0 || show_length > total_time)
        {
          cout << "The number you entered is out of range...please try again!" 
	       << endl << endl;
	}

      } while (show_length < 0 || show_length > total_time);

      total_time -= show_length;    //Get how much time is left over

      //Execute while the total time left is not equal to zero and the users
      //inputted response is not no (not equal to 'N')
      while (total_time != 0 && response != 'N')
      {
	//Do while the users inputted response is yes (equal to 'Y') 
        do
        {
          response = 'N';    //Set and reset response

	  //Echo the amount of time left to user
          cout << "You have " << total_time << " minute(s) left to work with." 
	       << endl << endl;

	  //Do while the inputted commercial length is less than zero or
	  //greater than the total time left
          do
          { 
            //Prompt and read in the length of the commercial
            cout << "Please enter the length of a commercial you plan to air "
		 << "(in minutes): ";
            cin >> comm_length;    //Read in the users number

	    //Check for valid input
            if (comm_length < 0 || comm_length > total_time)
	    {
              cout << "The number you entered is out of range..."
		   << "please try again!" 
		   << endl << endl;
	    }

          } while (comm_length < 0 || comm_length > total_time);

	  total_time -= comm_length;    //Check that commercial length is 
	                                //appropriate

	  //Execute if total time left is not equal to zero
          if (total_time != 0)
          {
            total_time += comm_length;    //Add commercial length back to 
	                                  //total_time in case commercial to be 
			                  //aired more than once

	    //Do while the commercial total (commercial length multiplied
	    //by its frequency) is less than zero or greater than the total
	    //time left
            do
            {
              //Prompt and read in the number of times the commercial 
	      //will be aired
              cout << "How many times do you plan on airing this commercial "
		   << "(in whole numbers)? ";
              cin >> comm_num;    //Read in the users number

              comm_total = comm_num * comm_length;    //Get total length of
	                                              //commercials combined

	      //Check for valid input
              if (comm_total < 0 || comm_total > total_time)
	      {
                cout << "The number you entered is out of range..."
	             << "please try again!" 
		     << endl << endl;
	      }

	    } while (comm_total < 0 || comm_total > total_time);
        
	    total_time -= comm_total;    //Get how much time is left over

	    //Execute if total time left is not equal to zero
	    if (total_time != 0)
            {
	      //Echo the amount of time left to user
              cout << "You have " << total_time 
		   << " minute(s) left to work with." 
		   << endl << endl;
 
	      //Do while the inputted response is not yes nor no (not equal to
	      //'Y' nor 'N')  
              do
              { 
                //Ask user if they want to add more commercials
                cout << "Would you like to add another commercial (Y/N)? ";
                cin >> response;    //Read in the users response
      
                response = toupper(response);    //Capitalize character input

		//Check for valid input
                if (response != 'Y' && response != 'N')
		{
                  cout << "That is an invalid response...please try again!" 
		       << endl << endl;
		}

		//Execute else if response is yes (equal to 'Y'), creating an
		//empty line for later readability
	        else if ('Y' == response)
                  cout << endl;

              } while (response != 'Y' && response != 'N');

	    }

	  }

        } while ('Y' == response);
      
      }

      //Execute if total time left is still greater than zero
      if (total_time > 0)
      {
	//Echo the time remaining to be used for filler commercials out to user
        cout << "It looks like you will need " << total_time 
	     << " minute(s) worth of filler commercials." 
	     << endl << endl;
      }

      //Execute else if total time left is equal to zero
      else if (total_time == 0)
      {
        cout << "\nYou have filled the 60-minute time slot!" 
	     << endl << endl;
      }

      //Do while the inputted response is not yes nor no (not equal to
      //'Y' nor 'N') 
      do
      {
	//Prompt and read in whether the user would like to start over
        cout << "Would you like to start over and fill another 60-minute "
	     << "time slot (Y/N)? ";
        cin >> response;    //Read in the users response

        response = toupper(response);    //Capitalize character input

	//Check for invalid input
        if (response != 'Y' && response != 'N')
	{
          cout << "That is an invalid response...please try again!" 
	       << endl << endl;
	}

	//Execute else if inputted response is yes (equal to 'Y') 
	else if ('Y' == response)
        {
          total_time = 60;    //Reset total time left to 60 minutes

	  //Clear screen to start over
	  counter = 0;    //Set or reset counter to zero

	  //While the counter is less than zero, incrementing by one,
	  //add new line
	  while (counter < 100)
          {
            ++counter;
	    cout << "\n";
	  }

	}

      } while (response != 'Y' && response != 'N');

    } while ('Y' == response);

    //Ending message
    cout << "\nThanks for using the 60-Minute Time Slot Calculator Program! "
	 << "Exiting now." 
	 << endl << endl;


    return 0;
}
