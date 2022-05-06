#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

// *****************************************************************************
// Connor Williams
// CS 162 - Introduction to Computer Science
// April 26, 2021
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
// a for loop three times so the user has a chance to enter three full words and
// three shorthand words. After already being echoed back to the user
// individually every time the is_satisfied function is called, the three full
// words and three shorthand notated words are then echoed back to the user
// altogether again before moving on. The user is then prompted to input a
// shorthand notated sentence with the shorthand notated words included, by
// calling the function, get_short_sent. Within this function, the is_too_long 
// function is called to check whether the inputted sentence is too long. The
// program then takes all the inputted information so far, the shorthand notated
// words, the full words, and the shorthand notated sentence, finds their
// lengths, and uses them to determine what the resulting length of the full
// sentence will be. This is achieved by calling the functions, words_len
// (for both the shorthand notated words and the full words) and
// get_full_length. The resulting length is used within the get_full_length
// function to add underscores as temporary filler characters for the array.
// This is done to avoid any possible errors from adding to an empty array. The
// function, get_full_sent, is then called three times for each pair of
// shorthand notated and full word. This function takes the shorthand notated
// word and iterates it through the shorthand notated sentence, looking for full
// matches. When full matches are found, the full associated word is added
// accordingly to the resulting full sentence. Otherwise, characters are taken
// directly from the shorthand notated sentence and placed in the resulting full
// sentence. Once the shorthand notated sentence is completely iterated through,
// the resulting full sentence is then copied to the shorthand notated
// sentence so it is ready to be iterated through again, ready to find matches
// for the next shorthand notated word. Once the get_full_sent function gets
// called three times, the resulting sentence is displayed to the user. The user
// is then asked if they would like to start over by calling the function,
// play_again. If the function returns true, the program will start over where
// the user is first prompted to input a full word of their choosing. If the
// function returns false, the program exits. (PROGRESS SUBMISSION 2)
// *****************************************************************************

//Constant definition
const int SIZE = 202;    //Will allow tracking of whether array input is too 
                         //long (one greater than 200 characters)

//Function prototypes
void welcome_user();                         //Welcomes the user
void get_full_word(char word[], int count);  //Gets users full word input 
void get_short_word(char word[], int count); //Gets users shorthand word input
void get_short_sent(char sentence[]);        //Gets users shorthand sentence

void get_full_sent(char full_sent[],         //Gets sentence result with full
		   char short_sent[],        //words added
		   char notated[],
		   char word[]);

void get_full_length(char full_sent[],       //Initializes result array with
		     char short_sent[],      //the correct number of  
		     int len_notated,        //underscores
		     int len_word);

bool is_too_long(char user_input[]);         //Checks if users input is too long
bool is_satisfied(char word[]);              //Echos word and checks if user is
                                             //satisfied

int get_match(char sentence[],               //Checks for word matches
	       char notated[],
	       int length,
	       int index);
bool play_again();                           //Check if user wants to start
                                             //over

int words_len(char word1[], char word2[],    //Gets total length of all words
	      char word3[]);                 //inputted

void replace(char sentence[], char word[],   //Adds full word to correct
	     int length, int index);         //position in resulting sentence


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
    char full_sent[SIZE];     //To be resulting sentence with full words
    bool again;               //To check whether user wants to start over
    int counter = 3;          //For tracking number of word entries
    int len_notated = 0;      //For combining the shorthand notation word
                              //lengths to determine resulting sentence length
    int len_word = 0;         //For combining the full word lengths to
                              //determine resulting sentence length

    //Welcome the user
    welcome_user();

    do
    {
      //Prompt and read in what three words the user would like to be replaced
      //when taking short hand notes. Check if user input is too long, echo
      //users inputs back to them, and then ask if user is satisfied with their
      //choices.
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

      cout << "Great! Your words have been chosen! Here they are one more "
	   << " time: " << endl << endl;

      cout << "'" << word1 << "' will be notated as '" << notated1 << "'." 
	   << endl;
      cout << "'" << word2 << "' will be notated as '" << notated2 << "'."
	   << endl;
      cout << "'" << word3 << "' will be notated as '" << notated3 << "'."
	   << endl << endl;

      //Prompt and read in the users sentence, written in shorthand notation.
      //Check if user input is too long.
      get_short_sent(short_sent);

      //Get total length of inputted shorthand notated words and full words
      //to be used in determining the length of the resulting full sentence.
      len_notated = words_len(notated1, notated2, notated3);
      len_word = words_len(word1, word2, word3);
      get_full_length(full_sent, short_sent, len_notated, len_word);
      
      //Display the resulting sentence with the shorthand notation replaced with
      //their full associated words.
      get_full_sent(full_sent, short_sent, notated1, word1);
      
      get_full_sent(full_sent, short_sent, notated2, word2);

      get_full_sent(full_sent, short_sent, notated3, word3);

      cout << "Your sentence is: " << full_sent << endl << endl;

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

// Function gets and creates the full length of the resulting sentence with
// underscores used as a temporary filler. Function takes the length of all
// the shorthand notated words, the length of all the full words, and the 
// length of the shorthand notated sentence to get the length of the 
// resulting sentence. Function takes two arrays, full_sent and short_sent,
// and two integers, len_notated and len_word, and returns nothing.
void get_full_length(char full_sent[], char short_sent[], 
		     int len_notated, int len_word)
{
    //Variable definitions
    int len_short = 0;      //To get shorthand sentence length
    int len_long = 0;       //To get full resulting sentence length
    char filler = '_';      //To fill full resulting sentence with underscores

    len_short = strlen(short_sent);    //Get shorthand sentence length
    len_long = len_short - len_notated + len_word;    //Get resulting sentence
                                                      //length
    
    for (int i = 0; i < len_long; ++i)
    {
      full_sent[i] = filler;
    }
    full_sent[len_long] = '\0';    //Adds null terminator to end of array.

}

// Function prompts user for shorthand notated sentence. Function checks that
// sentence length is not too long. Function takes an array, sentence, and 
// returns nothing.
void get_short_sent(char sentence[])
{
    //Variable definitions
    bool bad_length;    //Used to check whether input is too long

    do
    {
      cout << "Please enter the sentence with all of your shorthand\n"
           << "notated words."
	   << endl << endl;

      cout << "Shorthand sentence: ";
      cin.get(sentence, SIZE, '\n');
      cin.ignore(300, '\n');

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

// Function checks whether the shorthand notated word matches from a specific
// indexed element in the shorthand notated sentence. Function takes two
// arrays, sentence and notated, and two integers, length of the shorthand
// notation and index, as arguments and returns 0 or the length of the word.
int get_match(char sentence[], char notated[], int length, int index)
{
    //Variable definitions
    int i = 0;           //Index to be used to iterate through shorthand notated
                         //word
    int count = 0;       //To be number of element matches
    int match = 0;       //Check whether the word is a match
    int len_loop = 0;    //To iterate through the correct length while keeping
                         //index consistent

    len_loop = index + length;

    for (index; index < len_loop; ++index)
    {
      if (sentence[index] == notated[i])
      {
        ++count;
	++i;
      }
    }
    //Checks that ASCII value is not alphabetical, indicating that
    //shorthand notation is not a part of another word.
    if (toupper(sentence[index]) < 'A' || toupper(sentence[index]) > 'Z' 
        && count == length)
      match = count;
    return match;
}

// Function adds the full word associated to a shorthand notated word to the
// resulting sentence. Function takes two arrays, full_sent and word, and two
// integers, length of the full word and index, and returns the index integer.
void replace(char sentence[], char word[], int length, int index)
{
  for (int i = 0; i < length; ++i)
  {
    sentence[index] = word[i];
    ++index;    //Increments result index for next element
  }
}

// Function takes the users inputted shorthand word and checks whether it is
// in the shorthand notated sentence. If it is, the word associated with the
// shorthand word will be added to a new array, to be the resulting full
// sentence. Otherwise the shorthand notated sentence will be iterated through
// and add each element to the new array. Function takes four arrays, full_sent,
// short_sent, notated, and word, as arguments and returns returns nothing.
void get_full_sent(char full_sent[], char short_sent[], 
		   char notated[], char word[])
{
    //Variable definitions
    int r_index = 0;        //Result index to iterate through full resulting
                            //sentence
    int len_notated = 0;    //To be length of shorthand notated word
    int len_word = 0;       //To be length of full word
    int len_short = 0;      //To be length of shorthand notated sentence
    int len_result = 0;     //To be length of resulting full sentence
    int match = 0;          //Returns number if word matches

    //Get lengths of shorthand notation, word, shorthand notated sentence and
    //resulting full sentence.
    len_notated = strlen(notated);    //Get length of notated word
    len_word = strlen(word);          //Get length of full word
    len_short = strlen(short_sent);   //Get length of shorthand sentence
    len_result = strlen(full_sent);   //Get length of resulting sentence
  
    //Iterate through shorthand sentence, check for full matches and replace
    //for full word accordingly, resulting in full new array sentence. 
    for (int i = 0; i < len_short; ++i)
    {
      match = get_match(short_sent, notated, len_notated, i);

      if (match != 0)
      {
	replace(full_sent, word, len_word, r_index);
	
	r_index += len_word;  //Sets index up for element directly after
	                      //the replacement
        i = i + match - 1;    //Sets index up for element directly after
                              //the matches
      }
      else
      {
	full_sent[r_index] = short_sent[i];
	++r_index;    //Increments result index for next element
      }
    }
    full_sent[len_result] = '\0';    //Add null terminator to end of new array
    strcpy(short_sent, full_sent);   //Copy full sentence to the shorthand
                                     //notated sentence, ready to be iterated
				     //through with the next shorthand notated
				     //word
}

// Function gets the length of all the inputted shorthand notation or full words
// to be used in helping determine the length of the full sentence. Function 
// takes three arrays, all the inputted shorthand notation together or full
// words together, as its arguments and returns an integer of the total length 
// of the words combined.
int words_len(char word1[], char word2[], char word3[])
{
    //Variable definitions
    int len_word1 = 0;    //To be length of word 1
    int len_word2 = 0;    //To be length of word 2
    int len_word3 = 0;    //To be length of word 3
    int total = 0;        //To be length of words combined

    //Get length of words combined
    len_word1 = strlen(word1);    //Get length of word 1
    len_word2 = strlen(word2);    //Get length of word 2
    len_word3 = strlen(word3);    //Get length of word 3
    total = len_word1 + len_word2 + len_word3;    //Get total length

    return total;
}

//Function checks if user would like to start the program over from the
//beginning. Function takes no arguments and returns true or false.
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
      cout << "****************************************************************"
	   << endl
           << "------------------------Exiting Program-------------------------"
           << endl
           << "****************************************************************"
           << endl << endl;

    return again;
}

