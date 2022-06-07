//list.h
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;


struct node
{
    int data;   //some questions are a char * data;
    node * next;
};

class list
{
   public:
   //These functions are already written for you
     list();			//supplied
     ~list();			//supplied
     void build();     		//supplied
     void display();  		//supplied
    
    /* *****************YOUR TURN! ******************************** */
    //Write your function prototype here:
     int num_times(int match); //Count number of times number is found
     int display_except(); //Display except first and last
      int remove_except(); //Remove all but last two
      bool same_contents(list & second_list); //Are two lists the same?
    

   private:		//notice there is both a head and a tail!
      int num_times(node * head, int match);
      int display_except(node * head);
      int remove_except(node * & head);
      bool same_contents(node * head1, node * head2);

      node * head;
      node * tail;
};
