#include "cs163_list.h"
using namespace std;




//Implement these three functions
//Add to the end of the LLL as efficiently as possible
int list::add(journal_entry & to_add)
{
           //Implement this function using the
           //journal entry functions we just wrote!
           if (!head)
           {
               //Insert at the head
               head = new node;
               head->next = NULL;
               tail = head;
               if (!head->entry.copy_entry(to_add))
               {
                   delete head;
                   head = tail = NULL;
                   return 0;
               }
            }
            else
            {
                node * current = head;
                while (current->next)
                    current = current->next;
                current->next = new node;
                current = current->next;
                current->next = NULL;
                tail = current;
                if (!current->entry.copy_entry(to_add))
                {
                    delete current;
                    current = tail = NULL;
                    return 0;
                }
            }
            return 1;
}

//Display all journal entries
//Return false if there are no entries
int list::display() const
{
         //Your code goes here!
         node * current = head;
         if (!current->entry.display())
             return 0;
         while (current)
         {
             current->entry.display();
             current = current->next;
         }
         return 1;
}

//Determine if there is a match with the title passed in
//and if so provide the matching journal entry back to the
//client program through the second argument.
//Return a zero if no match is found
int list::find(char matching_title[], journal_entry & found)
{
	//Your code goes here!           
   if (!head) return 0;
   node * current = head;
   while (current)
   {
     if (!strcmp(matching_title, current->entry.title))
     {
         int match = entry.retrieve(matching_title, found);
         current->entry.display();
         current = current->next;
     }
   }

   return match;
}


//Copy the list passed in as an argument
//and add the nodes to the end of the current list
int list::append(list & source)
{

        //Your code goes here!
    return 0;
}
