#include "cs163_table.h"
using namespace std;

//In main when we create an object - we have to send in the value fo this 
//initial size
//syntax would be something like:
//
//table object(11);  ///the parentheses say what we're passing in as argument 
//                      for the constructor
//

/* Implement these three functions for this lab */
table::table(int size)
{
      //Allocate the hash table and initialize each
      //element and data member.
      hash_table = new node * [size];

      for (int i = 0; i < size; ++i)
        hash_table[i] = NULL;

      hash_table_size = size;
}


//Do something with the key being passed 
//in and return a number(or in our case an index)
//Make sure you're within the array size!
int table::hash_function(char *key) const
{
    //Place your code here
    int length = strlen(key);
    int sum = 0;
    int index = 0;
    for (int i = 0; i < length; ++i)
        sum += key[i];
    index = sum % hash_table_size;
    return index;
}



//Using a hash function, insert a new value into the 
//head of the chain
int table::insert(char * key_value, const journal_entry & to_add)
{

        //Place your code here
    int index = hash_function(key_value);

    node * temp = hash_table[index];

    hash_table[index] = new node;
    hash_table[index]->entry.copy_entry(to_add);
    hash_table[index]->next = temp;

    return 1;
}



//Using a hash function determine which chain to search
//then return 0 if no match is found
int table::retrieve(char * title_to_find, journal_entry & found) const
{

        //Place your code here
    int index = hash_function(title_to_find);

    if (!hash_table[index])
      return 0;

    node * current = hash_table[index];

    while (current && !current->entry.retrieve(title_to_find, found))
        current = current->next;

    if (!current) return 0;

    return 1;

}


int table::remove(char * title_to_find, journal_entry & found)
{
    int index = hash_function(title_to_find);

    if (!hash_table[index]) return 0;

    return remove(hash_table[index], title_to_find, found);
}

int table::remove(node * & head, char * title_to_find, journal_entry & found)
{
    if (!head) return 0;

    if (head->entry.retrieve(title_to_find, found))
    {
        node * hold = head->next;
        delete head;
        head = hold;
        return 1;
    }

    return remove(head->next, title_to_find, found);
}

int table::remove_chain(int index)
{
    if (!hash_table[index]) return 0;

    node * current = hash_table[index];

    while (current)
    {
        node * hold = current->next;
        delete current;
        current = hold;
    }
    return 1;
}

int table::remove_all()
{
    if (hash_table)
    {
        for (int i = 0; i < hash_table_size; ++i)
        {
            if (hash_table[i])
            {
                node * current = hash_table[i];
                while (current)
                {
                    node * hold = current->next;
                    delete current;
                    current = hold;
                }
            }
        }
        delete [] hash_table;
        hash_table = NULL;
        return 1;
    }
    return 0;
} 









