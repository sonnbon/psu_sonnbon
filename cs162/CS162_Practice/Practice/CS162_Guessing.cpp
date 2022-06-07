#include <iostream>
using namespace std;

// Connor Williams
// CS162 - Introduction to Computer Science
// This program is designed for us to play the number guessing game
// This is a number guessing game, where player 1 enters in a number 0-100
// and the second player guess

int main()
{
    //Variable definitions
    int number = 0;    //for clearing the screen
    int answer = 0;    //This is from player 1
    int guess = 0;     //Player 2 will enter this value
    int counter = 1;   //Limit the number of tries a player has


    //Welcome the user - Describe the purpose of the program - Indicate what the two players
    //are going to do - Mention valid versus invalid inputs
    cout << "Welcome to the guessing game!!";
    cout << endl << endl;    //a blank line
    cout << "Player 1 will enter the number to be guessed while player 2 looks away. ";
    cout << endl;
    cout << "Then, Player 2 can guess the number. They get 5 tries! Have fun!!";
    cout << endl << endl;    //a blank line gets ouput

    //Prompt and Read in the original answer (0-100).
    do
    {
      cout << "Player 1 - please enter a whole number from 0 through 100: ";
      cin >> answer;

      //Check to see that the answer is within range
      if (answer < 0)
      {
        cout << "Sorry, the answer is negative! " << endl;
      }
      else if (answer > 100)
      {
        cout << "Oops, the answer is larger than it is supposed to be! " << endl;
      }
    } while (answer < 0 || answer > 100); //loop as long as I have a bad answer

    //clear the screen
    while (number < 100)
    {
      ++number;
      cout << "\n";    //an escape sequence (endl)
    }
    
    //Prompt and Read in Player 2's guess (0-100)
    //a. Display and prompt for Player 2 to enter in a number
    //b. Read in the number
    //c. Check if the number is out of range
    cout << "Player 2 it is now your turn to begin your time guessing a number! "
         << endl << "Please enter in your guess from 0 through 100. Have fun! "
         << endl << endl;
    do
    {
      do
      {
        cout << "Please enter your guess: ";
        cin >> guess;

        if (guess < 0 || guess > 100)
          cout << "Your guess is out of range, try again." << endl;
      } while (guess < 0 || guess > 100);    //Notice a while loop has semicolon at the end

      cout << "Player 2's guess is " << guess << endl;

      //Compare the guess to the answer
      //a. If teh guess is the same as the answer, display a message that we have a winner
      //b. Otherwise, if the chance counter is 4 - tell the player you get only one more chance

      if (guess == answer)
        cout << "Congrat's, Player 2 is the winner! " << endl;
      else if (guess != answer && counter < 4)
        cout << "Not quite! Try again. " << endl;
      else if (counter == 4)
      {
        cout << "Not quite! Try again. " << endl;
        cout << "You have only one more chance. " << endl;
      }
      
      ++counter;   //add one to the chance counter
    
    } while (guess != answer && counter <= 5);

    if (guess != answer)
      cout << "Sorry, you ran out of guesses." << endl;

    return 0;
}
