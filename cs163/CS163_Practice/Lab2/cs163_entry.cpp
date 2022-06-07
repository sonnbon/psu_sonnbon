#include "cs163_entry.h"

//Test for linux #2.2


//Step #7: Implement this function
//This function takes the argument and copies it into
//the journal's data members
int journal_entry::copy_entry(const journal_entry & copy_from)
{
    //Error check
    if (!copy_from.title || !copy_from.notes) return 0;
    if (title) delete [] title;
    if (notes) delete [] notes;
    
    title = new char[strlen(copy_from.title) + 1];
    strcpy(title, copy_from.title);

    notes = new char[strlen(copy_from.notes) + 1];
    strcpy(notes, copy_from.notes);
    return 1;

       //Place your code here
}


//Step #8: Implement this function
//This function will return non-zero if the title sent
//in as an argument matches the data member. It supplies
//the matching journal back as an argument
int journal_entry::retrieve(char * matching_title, journal_entry & found)
{

      //Place your code here
    if (!matching_title || !title) return 0;
    if (!strcmp(matching_title, title))
    {
        if (found.title) delete [] found.title;
        if (found.notes) delete [] found.notes;

        found.title = new char[strlen(title) + 1];
        strcpy(found.title, title);

        found.notes = new char[strlen(notes) + 1];
        strcpy(found.notes, notes);
    }
    return 1;
}

