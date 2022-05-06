#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

// *****************************************************************************
// Connor Williams
// CS 162 - Introduction to Computer Science
// April 22, 2021
// *****************************************************************************
// This is a shorthand mapping program that takes three shorthand notated words
// and replaces them with their actual respective words in an outputted
// sentence. The welcome_user function is first called, welcoming the user and
// displaying an explanation of the program and what is a valid versus invalid
// entry. The user is then prompted to enter three full words and three 
// shorthand words to represent each respective full word, by calling the 
// get_full_word and get_short_word functions. Within these functions, two more
// functions, is_too_long and is_sastisfied, are called to check if the users
// input is too long and if the user is satisfied with their input,
// respectively. These four functions (not including welcome_user) are called on
// a loop three times so the user has a chance to enter three full words and
// three shorthand words. (TASK 1 AND TASK 2)
// *****************************************************************************

//Constant definition
const int SIZE = 202;    //Will allow tracking of whether array input is too 
                         //long (one greater than 200 characters)

//Function prototypes
void welcome_user();                         //Welcomes the user
void get_full_word(char word[], int count);  //Gets users full word input 
void get_short_word(char word[], int count); //Gets users shorthand word input
bool is_too_long(char user_input[]);         //Checks if users input is too long
bool is_satisfied(char word[]);              //Echos word and checks if user is
                                             //satisfied

int main()
{
    //Variable definitions
    char short_word1[SIZE];    //To be first shorthand notated word
    char short_word2[SIZE];    //To be second shorthand notated word
    char short_word3[SIZE];    //To be third shorthand notated word
    char full_word1[SIZE];     //To be full word associated with 1st shorthand
    char full_word2[SIZE];     //To be full word associated with 2nd shorthand
    char full_word3[SIZE];     //To be full word associated with 3rd shorthand
    char short_sent[SIZE];     //To be sentence with shorthand notated words
    char full_sent[SIZE];      //To be resulting sentence with full words
    int counter = 0;           //For tracking number of word entries

    //Welcome the user
    welcome_user();

    //Prompt and read in what three words the user would like to be replaced
    //when taking short hand notes. Check if user input is too long, echo users
    //inputs back to them, and then ask if user is satisfied with their choices.
    for (counter; counter < 3; ++counter)
    {
      if ((counter + 1) == 1)
      {
        get_full_word(full_word1, counter);
	get_short_word(short_word1, counter);
      }
      else if ((counter + 1) == 2)
      {
        get_full_word(full_word2, counter);
	get_short_word(short_word2, counter);
      }
      else
      {
        get_full_word(full_word3, counter);
	get_short_word(short_word3, counter);
      }
    }

    cout << "Great! Your words have been chosen! Here they are one more time: "
	 << endl << endl;

    cout << "'" << full_word1 << "' will be notated as '" << short_word1 << "'."
	 << endl;
    cout << "'" << full_word2 << "' will be notated as '" << short_word2 << "'."
	 << endl;
    cout << "'" << full_word3 << "' will be notated as '" << short_word3 << "'."
	 << endl << endl;

    return 0;
}

// Function welcomes the user by displaying a welcome message and messages
// describing the purpose of the program, explaining what the user must do, and
// what valid versus invalid inputs will work. Function takes no arguments and
// returns nothing.
void welcome_user()
{
    cout << "****************************************************************\n"
         << "------------Welcome to the Shorthand Mapping Program------------\n"
         << "****************************************************************"
         << endl << endl;

    cout << "The purpose of this program is to help you with your shorthand\n"
         << "notes! This program allows you to replace three of your\n" 
	 << "shorthand notated words with the actual words you would have\n"
	 << "written if you had the time!"
         << endl << endl;

    cout << "In order for this program to help you, you must first enter the\n"
         << "three words you wish to be replaced when taking shorthand notes.\n"
         << "You will then enter a sentence representing your notes with\n"
	 << "those three words in shorthand notation. This program will then\n"
	 << "display your notes back to you with your three notated words\n"
	 << "replaced with the actual words!"
         << endl << endl;

    cout << "Valid entries for your shorthand notation include characters as\n"
         << "well as integers. You may capitalize your shorthand or full\n"
	 << "words as well. Please do not exceed 200 characters with any of\n"
	 << "your inputs."
         << endl << endl;

    cout << "****************************************************************"
         << endl << endl;
}

// Function prompts user for a full word they wish to be replaced when taking
// shorthand notes. Function then checks count + 1 (resulting in 1, 2, or 3) and
// allows user to input their word accordingly as the first, second, or third
// full word. Function takes an array, word, and an integer, count, as
// arguments and returns nothing.
void get_full_word(char word[], int count)
{
    //Variable definitions
    bool bad_length;    //Used to check whether input is too long
    bool satisfy;       //Used to check whether user is satisfied with input
    
    do
    {
      do
      {
        cout << "Please enter the full word you wish to be replaced when\n"
	     << "taking shorthand notes."
             << endl << endl;

        cout << "Full word " << count + 1 << ": ";
        cin.get(word, SIZE, '\n');
        cin.ignore(300, '\n');

        bad_length = is_too_long(word);    //Assign functions boolean return

      } while (bad_length);
      
      satisfy = is_satisfied(word);    //Echos back users word and checks for
                                       //users satisfaction
      cout << endl;

    } while (!(satisfy));
}

// Function prompts user for shorthand notated word they wish to represent
// their inputted full word. Function then checks count + 1 (resulting in 1, 2,
// or 3) and allows user to input their word accordingly as the first, second,
// or third shorthand notated word. Function takes an array, word, and an
// integer, count, as arguments and returns nothing.
void get_short_word(char word[], int count)
{
    //Variable definitions
    bool bad_length;    //Used to check whether input is too long
    bool satisfy;       //Used to check whether user is satisfied with input

    do
    {
      do
      {
        cout << "Please enter the shorthand notation you wish to use to\n"
             << "represent that word."
	     << endl << endl;

        cout << "Shorthand notation " << count + 1 << ": ";
        cin.get(word, SIZE, '\n');
        cin.ignore(300, '\n');

        bad_length = is_too_long(word);    //Checks for bad length

      } while (bad_length);

      satisfy = is_satisfied(word);    //Echos back users word and checks for
                                       //users satisfaction
      cout << endl;

    } while (!(satisfy));
}

// Function checks whether the inputted word, shorthand notation, or sentence
// is too long (greater than 200 characters). Function takes an array,
// user_input,  as its argument and returns true or false.
bool is_too_long(char user_input[])
{
    //Variable definitions
    int length = 0;             //To get length of inputted characters
    bool bad_length = false;    //Will check if input is too long, set to false

    length = strlen(user_input);    //Length of inputted characters

    if (length > 200)
    {
      cout << "The word you entered is too long. Please try again!"
	   << endl << endl;
      bad_length = true;
    }

    return bad_length;
}

// Function echos back users input and asks if they are sastisfied with their
// word or shorthand notation input. Boolean function takes an array, word, and
// returns true or false.
bool is_satisfied(char word[])
{
    //Variable definitions
    char response;           //To be users yes or no response ('Y' or 'N')
    bool satisfy = false;    //Will check if user is satisfied with input,
                             //set to false. 

    do
    {
      cout << "Are you satisfied with '" << word << "' as your choice? (Y/N): ";
      cin >> response;
      cin.ignore(300, '\n');

      response = toupper(response);    //Allows for lowercase 'y' or 'n' input
    
      if (response != 'Y' && response != 'N')
        cout << "Your response is invalid. Please try again!" << endl << endl;

    } while (response != 'Y' && response != 'N');
    
    if (response == 'Y')
    {
      satisfy = true;
    }

    return satisfy;
}


//NEXT STEPS...
/*4. Prompt and read in the users sentence, which represents their notes in
   shorthand notation.
  a. Display a prompt asking the user for a sentence including any or all of
     their shorthand notated words.
  b. Read in the sentence.
  c. Check if the sentence is too long.
  d. If it is, display an error message and repeat step 4.
  e. Otherwise, check if the sentence includes any of the shorthand notated 
     words.
  f. If it does not, display an error message to the user and repeat step 4. 
5. Display the resulting sentence with the shorthand notation replaced with the
   actual words.
  a. Check for matches in the sentence to the inputted shorthand notation.
  b. If the indexed element of the sentence does not match the same indexed
     element of the inputted shorthand notation, add indexed element of the
     sentence to a new array.
  c. Else if the indexed element of the sentence does match the same indexed
     element of the inputted shorthand notation, save the index number to note
     where the match first occurred and check for matches in the following 
     elements of the sentence up to the length of the shorthand notated word.
    i. If the next element in the sentence does not match the next element in 
       the shorthand notation, add the previous (saved) indexed element of the
       sentence to the new array and repeat 5.b continuing from the next 
       indexed element.
   ii. Else if the next element in the sentence does match the next element of
       the shorthand notation, increment a counter to track the match and 
       repeat 5.c.i for the length of the shorthand notated word.
      A. If the resulting counter is equal to the length of the shorthand
         notation and the next element of the sentence is a space, add each
         element of the word associated with the shorthand notation to the next
         element of the new array.
        I. Save the sum of the length of the added word and the index number of 
           where it was added to the new array. This sum is the new index
           starting point for any element added to the new array.
       II. Repeat step 5.b from the index sum of the previous (saved) indexed
           element of the sentence and the length of the shorthand notation.
           This sum will put the index at the next element after where the
           shorthand notation was in the sentence.
      B. Otherwise, the counter does not equal the length of the shorthand 
         notation or there is no space after the shorthand match in the sentence
         (indicating that it is part of another word), then add the previous 
         (saved) indexed element of the sentence to the new array and repeat 
         5.b from the next indexed element.
  d. Repeat step 5.a for the next shorthand notation.
  e. Assign a '\0' to the end of the new array with its length used as its
     index.
  f. Display the new sentence to the user.
6. Prompt and read in whether the user would like to start over.
  a. If the response is yes, then repeat step 3.
  b. Else if the response is neither yes nor no, then display an error message
     and repeat step 6.
  c. Otherwise, thank the user for using the program and exit.*/

