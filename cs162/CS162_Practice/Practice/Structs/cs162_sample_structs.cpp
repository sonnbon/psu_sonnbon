#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

//Connor Williams
//Structure examples in CS162 lecture
//This is going to create and manage a list of action items
//To begin we will read them in and display
//Ultimately we will also do some work on correcting the notes given

//Constants
const int SIZE = 10;  //This will be the max number of action items
const int NAME = 21;  //include the '\0' plus 20 other characters

//Structs
struct item
{
    char name[NAME];
    int priority;
};

//Prototypes
void read_one(item & action_item); //read from the user a single action item
int read_all(item action_item_list[]); //return the number of items read in
void display_one(item & action_item);  //display just one action item
void display_all(item array[], int number_to_display); //display as many as have been set

int main()
{
    //We started by testing just one
    //item one_item;
    //read_one(one_item);
    //cout << one_item.name << " " << one_item.priority << endl;
    //display_one(one_item);

    item to_do_list[SIZE];    //library or a list of action items to do
    int num_items = 0;        //keep track of how many action items we have so far

    num_items = read_all(to_do_list);  //function call
    cout << "number of items we read: " << num_items << endl;
    display_all(to_do_list, num_items);


    return 0;
}

//Display all items
void display_all(item array[], int num)
{
    for (int i = 0; i < num; ++i)
    {
        display_one(array[i]);
    }
}

//Read in ALL action items until EITHER we run out of room OR the user wants to quit
//Return the number of items read in
int read_all(item array[])
{
    char response = 'n';
    int i = 0;  //Start with index zero
    do
    {
        read_one(array[i]);
        ++i;
        cout << "Again? ";
        cin >> response;
        cin.ignore(100, '\n');
    } while (toupper(response) != 'N' && i < SIZE);
    return i; //i represents number of items we have so far!
}

//Display one action item that is passed in as an argument
void display_one(item & action_item)
{
    cout << "Priority " << action_item.priority << '\t' << "Action item: "
         << action_item.name << endl;
}

//Reading in one action item which inclues a name and a priority which is passed in as an
//argument using a structure
void read_one(item & action_item)
{
    cout << "Please enter the name of the next to do item: ";
    cin.get(action_item.name, NAME, '\n');
    cin.ignore(100, '\n');

    cout << "Please enter the priority next: ";
    cin >> action_item.priority;
    cin.ignore(100, '\n');
}

