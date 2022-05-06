#include <iostream>
#include <cctype>
using namespace std;

// **************************************************
// Connor Williams
// CS162 - Introduction to Computer Science
// This program allows the user to calculate how many
// commercials can fit in a show that is scheduled
// for a 60-minute time slot.
// **************************************************

int main()
{
    //Variable defintions
    int total_time = 60;    //running total (time slot) length set to 60 minutes
    int show_length = 0;    //show length entered will be subtracted from running total
    int comm_length = 0;    //commercial length entered to be combined with commercial frequency
    int comm_num = 0;	    //commercial frequency entered to be combined with commercial length
    int comm_total = 0;     //be product of commercial length and frequency, will subtract from total
    char response = 'N';    //used to determine if user wants to add more commercials or start over

    //Welcome the user
    cout << "Welcome to the 60-Minute Time Slot Calculator Program!" << endl << endl;

    cout << "This program is meant to help you calculate how many " << endl
	 << "commercials you can fit in a show that is scheduled " << endl
	 << "for a 60-minute time slot." << endl << endl;
    
    cout << "After inputting how long the show is that is being aired " << endl
	 << "during the time slot of interest, you will then input the " << endl
	 << "length of each commercial and how many times you plan to " << endl
	 << "to air them (in minutes)." << endl << endl;

    cout << "Remember! You only have a 60-minute time slot to work with." << endl
	 << "The sum of the length of the show and the commercials must " << endl
	 << "not exceed 60-minutes." << endl << endl;

    cout << "Please only enter whole numbers from 0 to 60!" << endl << endl;

    do
    {
      //Prompt and read in the length of the show
      cout << "Please enter the length of the show you plan to air (in minutes): ";
      cin >> show_length;    //read in the users number
      if (show_length < 0 || show_length > total_time)
        cout << "The number you entered is out of range...please try again!" << endl << endl;
      else
      {
        total_time -= show_length;
        if (total_time > 0)
	  cout << "You have " << total_time << " minute(s) left to work with." << endl << endl;
	else
	  cout << "You have filled the 60-minute time slot." << endl << endl;
      }
    } while (total_time != 0);


      //Prompt and read in the length of the commercial 
      //Prompt and read in the number of times the commercial will be aired
      //Ending Message

    return 0;

}
