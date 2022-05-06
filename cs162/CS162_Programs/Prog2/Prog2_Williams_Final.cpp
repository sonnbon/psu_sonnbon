#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

// *****************************************************************************
// Connor Williams
// CS 162 - Introduction to Computer Science
// April 28, 2021
// *****************************************************************************
// This is a shorthand mapping program that takes three shorthand notated words
// and replaces them with their actual respective words in an outputted
// sentence. The welcome_user function is first called, welcoming the user and
// displaying an explanation of the program and what is a valid versus invalid
// entry. The user is then prompted to enter three full words and three 
// shorthand words to represent each respective full word, by calling the 
// get_full_word and get_short_word functions. Within the get_full_word 
// function, two more functions, is_too_long and is_satisfied, are called to 
// check if the users input is too long and if the user is satisfied with their 
// input, respectively. Within the get_short_word function, three more
// functions, is_too_long, is_satisfied, and is_bad_note, are called. The
// is_bad_note function checks for any invalid character input. These four to
// five functions (not including welcome_user) are called on a for loop three
// times so the user has a chance to enter three full words and three
// shorthand words. After already being echoed back to the user individually
// every time the is_satisfied function is called, the three full words and
// three shorthand notated words are then echoed back to the user, grouped
// together, again before moving on. The user is then prompted to input a
// shorthand notated sentence with the shorthand notated words included by
// calling the function, get_short_sent. Within this function, the is_too_long 
// and is_bad_sent functions are called to check for invalid lengths and
// characters. The length of the inputted sentence is then stored, to be used
// for iterating through each element and looking for word matches. The 
// get_next_word function is then called, which searches for the next
// unique word within the inputted sentence by cutting words off at non-numeric
// and non-alphabetic characters (implying spaces). When a unique word
// is stored at a cut off point, it is copied to be used outside of the function
// and its length is returned as a whole number. The length is to be used to
// iterate passed the word to the next element of the inputted sentence when
// necessary. The unique word is then passed in the function, display_result,
// along with the three full words and three shorthand notated words. This
// function compares each shorthand notated word to the current unique word. If
// they are the same, then the shorthand notated words associated full word is
// printed out. Otherwise, if there are no matches, the unique word is printed
// out. This is done for the whole sentence by using a while loop which calls
// both the two previously mentioned functions while adding the unique word's
// returned length to the index value of the sentence and iterating up to the
// length of the inputted sentence. Once the while loop is finished, the
// updated sentence, with full words replacing the shorthand notated words, will
// be displayed to the user. The function, again, is then called, asking the
// user if they would like to start over. If yes, the function will return true,
// and they will get to begin again, entering in new words and a sentence, as 
// before. If no, then the function, exiting, is called within the again
// function and displays an exiting message. The again function will then return
// false, and the program will not begin again.
// *****************************************************************************

//Constant definition
const int SIZE = 202;    //Will allow tracking of whether array input is too 
                         //long (one greater than 200 characters)

//Function prototypes
void welcome_user();                         //Welcomes the user
void exiting();                              //Exiting message displayed
void get_full_word(char word[], int count);  //Gets users full word input 
void get_short_word(char word[], int count); //Gets users shorthand word input
void get_short_sent(char sentence[]);        //Gets users shorthand sentence
void display_result(char next_word[],        //Finds matches and outputs words 
	            char word1[],            //accordingly
	            char word2[], 
	            char word3[],
	            char notated1[], 
	            char notated2[], 
	            char notated3[]);

bool is_bad_sent(char user_input[]);         //Checks for any bad characters
bool is_bad_note(char user_input[]);         //Checks for any bad characters or
                                             //spaces
bool is_too_long(char user_input[]);         //Checks if users input is too long
bool is_satisfied(char word[]);              //Echos word and checks if user is
                                             //satisfied
bool play_again();                           //Check if user wants to start
                                             //over

int get_next_word(char sentence[],           //Gets next word from inputted
		  char next_word[],          //sentence by checking for 
		  int index);                //ASCII values that are not
                                             //alphabetic or numeric

int main()
{
    //Variable definitions
    char notated1[SIZE];      //To be first shorthand notated word
    char notated2[SIZE];      //To be second shorthand notated word
    char notated3[SIZE];      //To be third shorthand notated word
    char word1[SIZE];         //To be full word associated with 1st shorthand
    char word2[SIZE];         //To be full word associated with 2nd shorthand
    char word3[SIZE];         //To be full word associated with 3rd shorthand
    char short_sent[SIZE];    //To be sentence with shorthand notated words
    char next_word[SIZE];     //To find individual word from inputted sentence
    bool again;               //To check whether user wants to start over
    bool match;               //To check for notated word matches in sentence
    int counter = 3;          //For tracking number of word entries
    int len_short = 0;        //To be length of inputted notated sentence
    int len_next_word = 0;    //To be length of each individual word from
                              //inputted sentence
    int index = 0;            //To be index that iterates through inputted
                              //sentence 

    //Welcome the user
    welcome_user();

    do
    {
      //Prompt and read in what three words the user would like to be replaced
      //when taking shorthand notes. Check if user input is too long or if any
      //invalid characters are present, echo users inputs back to them, and then 
      //ask if user is satisfied with their choices.
      for (int i = 0; i < counter; ++i)
      {
        if ((i + 1) == 1)
        {
          get_full_word(word1, i);
	  get_short_word(notated1, i);
        }
        else if ((i + 1) == 2)
        {
          get_full_word(word2, i);
	  get_short_word(notated2, i);
        }
        else
        {
          get_full_word(word3, i);
	  get_short_word(notated3, i);
        }
      }

      //Echo back all input so far again so user has easy access to what they
      //inputted.
      cout << "Great! Your words have been chosen! Here they are one more "
	   << "time: " << endl << endl;

      cout << "'" << word1 << "' will be notated as '" << notated1 << "'." 
	   << endl;
      cout << "'" << word2 << "' will be notated as '" << notated2 << "'."
	   << endl;
      cout << "'" << word3 << "' will be notated as '" << notated3 << "'."
	   << endl << endl;

      //Prompt and read in the users sentence, written in shorthand notation.
      //Check if user input is too long or if invalid characters are present.
      get_short_sent(short_sent);

      len_short = strlen(short_sent);    //Get length of shorthand sentence
      index = 0;                         //Set or reset index to 0.

      //Display the resulting sentence with the shorthand notation replaced
      //with the actual words.
      while (index < len_short) 
      {
        len_next_word = get_next_word(short_sent, next_word, index);
        display_result(next_word, word1, word2, word3, 
		       notated1, notated2, notated3);

	index += len_next_word;    //Index appropriate number of elements
      }
      cout << endl << endl;

      //Ask the user if they would like to do this again.
      again = play_again();
      
    } while (again);

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
	 << "You will then enter the three shorthand notated words you wish\n"
	 << "to represent those words. Then, you will enter a sentence\n"
	 << "representing your notes with those three shorthand notated\n"
	 << "words. This program will then display your notes back to you\n"
	 << "with your three notated words replaced with the actual words!"
         << endl << endl;

    cout << "Valid entries for your shorthand notation and sentence include\n"
	 << "alphabetic and numeric characters only. Do not use any\n"
	 << "punctuation in your shorthand words or sentences. Do not use\n"
	 << "any spaces in your shorthand words either. However, your full\n"
	 << "words may have any punctuation or characters you would like!\n"
	 << "Please do not exceed 200 characters with any of your inputs."
         << endl << endl;

    cout << "****************************************************************"
         << endl << endl;
}

// Function prompts user for a full word they wish to be replaced when taking
// shorthand notes. Function then checks count + 1 (resulting in 1, 2, or 3) and
// allows user to input their word accordingly as the first, second, or third
// full word. Function checks that the word is not too long. Function takes an 
// array, word, and an integer, count, as arguments and returns nothing.
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
// or third shorthand notated word. Function checks that the word is not too
// long and that no invalid characters exist. Function takes an array, word, and
// an integer, count, as arguments and returns nothing.
void get_short_word(char word[], int count)
{
    //Variable definitions
    bool bad_length;    //Used to check whether input is too long
    bool satisfy;       //Used to check whether user is satisfied with input
    bool bad_char;      //Used to check whether a bad character was inputted

    do
    {
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

	  bad_char = is_bad_note(word);      //Checks for bad characters and
	                                     //spaces
	
	} while (bad_char);

        bad_length = is_too_long(word);    //Checks for bad length

      } while (bad_length);

      satisfy = is_satisfied(word);    //Echos back users word and checks for
                                       //users satisfaction
      cout << endl;

    } while (!(satisfy));
}

// Function prompts user for shorthand notated sentence. Function checks that
// sentence length is not too long and that no invalid characters exist. 
// Function takes an array, sentence, and returns nothing.
void get_short_sent(char sentence[])
{
    //Variable definitions
    bool bad_length;    //Used to check whether input is too long
    bool bad_char;      //Used to check whether a bad character was inputted

    do
    {
      do
      {
        cout << "Please enter the sentence with all of your shorthand\n"
             << "notated words."
	     << endl << endl;

        cout << "Shorthand sentence: ";
        cin.get(sentence, SIZE, '\n');
        cin.ignore(300, '\n');

        bad_char = is_bad_sent(sentence);      //Checks for bad characters

      } while (bad_char);

      bad_length = is_too_long(sentence);    //Checks for bad length

    } while (bad_length);

}

// Function checks whether the inputted word, shorthand notation, or sentence
// is too long (greater than 200 characters). Function takes an array,
// user_input,  as its argument and returns true or false.
bool is_too_long(char user_input[])
{
    //Variable definitions
    int length = 0;             //To get length of inputted characters
    bool bad_length = false;    //Will check if input is too long, set to false

    length = strlen(user_input);    //Get length of inputted characters

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

// Function checks if user would like to start the program over from the
// beginning. Function takes no arguments and returns true or false.
bool play_again()
{
    //Variable definitions
    char response;          //To be users yes or no response ('Y' or 'N')
    bool again = false;     //Will check if user wants to start over, set
                            //to false.

    do
    {
      cout << "Would you like to start over and enter new notes? (Y/N): ";
      cin >> response;
      cin.ignore(100, '\n');

      response = toupper(response);    //Allows for lowercase 'y' or 'n' input
    
      if (response != 'Y' && response != 'N')
        cout << "Your response is invalid. Please try again!" << endl << endl;

    } while (response != 'Y' && response != 'N');
    
    cout << endl;

    if (response == 'Y')
      again = true;
    else
      exiting();

    return again;
}

// Function displays exiting message. Function takes no arguments and returns
// nothing.
void exiting()
{
    cout << "****************************************************************"
	 << endl
         << "------------------------Exiting Program-------------------------"
         << endl
         << "****************************************************************"
         << endl << endl;
}

// Function checks if user enters anything other than numeric or alphabetic
// values for the sentence input. Function takes an array, user_input, as an 
// argument and returns true or false.
bool is_bad_sent(char user_input[])
{
    //Variable definitions
    int length = 0;           //To get length of user input
    int count = 0;            //Will count if there is any punctuation used
    bool bad_char = true;     //Will check if punctuation is used, set to true

    length = strlen(user_input);    //Get length of user input

    //Check for bad characters by checking outside of alphabetic and numeric
    //ASCII values (spaces are allowed).
    for (int i = 0; i < length; ++i)
    {
      if (toupper(user_input[i]) >= 'A' && 
          toupper(user_input[i]) <= 'Z' ||
          user_input[i] >= 48 && user_input[i] <= 57 || user_input[i] == ' ')
        ++count;
    }
    if (count == length)
      bad_char = false;
    else
      cout << "Please do not use any punctuation. Try again!" << endl << endl;
      
    return bad_char;
}

// Function checks if user enters anything other than numeric or alphabetic
// values for the shorthand word inputs. Function takes an array, user_input, as
// an argument and returns true or false.
bool is_bad_note(char user_input[])
{
    //Variable definitions
    int length = 0;           //To get length of user input
    int count = 0;            //Will count if there is any punctuation used
    bool bad_char = true;     //Will check if punctuation is used, set to true

    length = strlen(user_input);    //Get length of user input

    //Check for bad characters by checking outside of alphabetic and numeric
    //ASCII values.
    for (int i = 0; i < length; ++i)
    {
      if (toupper(user_input[i]) >= 'A' && 
          toupper(user_input[i]) <= 'Z' ||
          user_input[i] >= 48 && user_input[i] <= 57)
        ++count;
    }
    if (count == length)
      bad_char = false;
    else
      cout << "Please do not use any punctuation or spaces. Try again!" 
	   << endl << endl;
      
    return bad_char;
}

// Function gets the next word in the inputted sentence by checking for only 
// numeric or alphabetic characters to indicate when word separation occurs. Two
// arrays, sentence and next_word, and one integer, index, are taken as 
// arguments and the function returns the length of the next_word as a whole 
// number.
int get_next_word(char sentence[], char next_word[], int index)
{
    //Variable definitions
    int len_word = 0;        //Saves next words' length
    int i = 0;               //To iterate through new word
    char word[SIZE] = {};    //Initialize or reset array to be empty

    //Check for breaks in sentence to determine an individual word by checking
    //while element is alphabetic or numeric.
    while (toupper(sentence[index]) >= 'A' &&
           toupper(sentence[index]) <= 'Z' ||
	   sentence[index] >= 48 && sentence[index] <= 57)
	   
    {
      word[i] = sentence[index];
      ++i;
      ++index;
    }

    len_word = i + 1;         //Gets word length by adding one to number of 
                              //elements counted
    word[len_word] = '\0';    //Adds '\0' to end of array

    strcpy(next_word, word);  //Copy new word to next_word array

    return len_word;
}    

// Function checks whether a match is found and outputs a statement accordingly.
// Each notated word is checked to see if it matches the next word from the
// inputted sentence. If it is a match, the full associated word is outputted. 
// If it is not a match, then the next notated word is checked until all notated
// words are checked. If none of the notated words match, the word from the 
// inputted sentence is outputted. Function takes seven arrays, next_word, 
// word1, word2, word3, notated1, notated2, and notated3, as arguments and 
// returns nothing. 
void display_result(char next_word[], char word1[], char word2[], char word3[],
	            char notated1[], char notated2[], char notated3[])
{
    //If a match is found, output its associated full word. Otherwise, output
    //the word from the inputted sentence.
    if (!strcmp(next_word, notated1))
      cout << word1 << ' ';
    else if (!strcmp(next_word, notated2))
      cout << word2 << ' ';
    else if (!strcmp(next_word, notated3))
      cout << word3 << ' ';
    else
      cout << next_word << ' ';
}
