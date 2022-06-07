#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

//Connor Williams
//CS162 hangman example lecture
//This is the hangman program where one player provides a secret word
//and the next player guesses it until either 5 guesses are missed or all
//characters have been guessed.

const int SECRET = 21;  //20 character word, plus 1 for the '\0'

//Prototype - FUNCTION DECLARATION
//DECLARES to the compiler that the function exists and that the functions
//can be specified in any order
//  format:   return_type   function_name   (argument list);
void explain_rules();
void read_secret_word(char secret_word[]);
void clear_screen();
int play_game(char secret_word[]); //returns the number of characters missed
void fill_result(char array[], int len); //fill an array with underscores
void display_result(char array[]);
bool is_in_secret(char secret[], char result[], char guess);

int main()
{
    //char secret[SECRET];  //the original word entered by player 1
    //char result[SECRET];  //start as underscores and be the resulting word
    char guess;           //the character that the user guesses
    int score = 0;        //how many missed characters
    
    //Function call
    explain_rules();      //function call to explain how to use this program
    read_secret_word(secret);  //function calls do not have data types
    score = play_game(secret);    //now let's go play the game; number missed

    
    //Testing:
    //cout << "IN MAIN we got the secret word: " << secret << endl;
    cout << "Our score was: " << score << endl;

    return 0;
}

//Check to see if the ugess is in the secret word and if so update the 
//resulting array to have that character and set the found variable to true.
//Return if it is found.
bool is_in_secret(char secret[], char result[], char guess)
{
    bool found = false;
    int len = strlen(secret);
    for (int i = 0; i < len; ++i)
    {
        if (guess == secret[i])
        {
            found = true;
            result[i] = guess;
        }
    }
    return found;
}

//Fill the resulting array with underscores to begin with
void fill_result(char array[], int len)
{
    for (int i = 0; i < len; ++i)
        array[i] = '_';
    array[len] = '\0';
}

//Display the resulting array with spaces inbetween each element
void display_result(char array[])
{
    int len = strlen(array);
    for (int i = 0; i < len; ++i)
        cout << array[i] << ' ';
    cout << endl;
}

//Play the game - read in a guess, see if it is in the secret word
//keeps track of the number of missed guesses and returns that
int play_game(char secret[])
{
    char result[SECRET];  //start as underscores and be the resulting word
    char guess;           //the character that the user guesses
    bool found = false;   //did we find match?
    int score = 0;

    //Build the result array and fill it with underscores
    fill_result(result, strlen(secret));
    display_result(result);

    do
    {
      //prompt the user for a character to guess and read it in
      cout << "Player2: Please enter your guess: ";
      cin >> guess;
      cin.ignore(100, '\n');

      found = is_in_secret(secret, result, guess);
      display_result(result);

      //update the score
      if (!found)
          ++score;
    } while (score < 5 && strcmp(secret, result));

    return score;
}

//Clear the screen
void clear_screen()
{
    for (int i = 0; i < 500; ++i)
        cout << '\n';
    cout << endl; //flush all of the newlines out to the screen
}

// This function prompt the user for a secret word and read it in
void read_secret_word(char word[])
{
    //Prompt the user
    cout << "Please enter the secret word while player 2 looks away: ";

    //Read in the word
    cin.width(SECRET); //restrict how much we read to just SECRET-1 characters
    cin >> word;
    cin.ignore(100, '\n'); //EVERY TIME we read, follow it with an ignore

    clear_screen(); //function call
}

//HEADER COMMENT FOR EVERY FUNCTION
//Explain the purpose of the function, return type, arguments
//The purpose of this function is to explain the rules to the user of how to 
//use the hangman game
void explain_rules()
{
    cout << "Welcome to the hangman game! " << endl << endl;
    cout << "Player 1 will provide a secret word and player 2 will "
         << "\nguess the characters - they get five possible tries! "
         << endl << endl;
}
