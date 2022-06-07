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
    
    int display_unique_iter();  //display unique iteratively
    int display_unique_recur(); //display unique recursively WRAPPER
    int display_last_not_first(); //display last if not the same as the first iteratively
    int display_last_not_recur(); //display last if not first recursively WRAPPER
    float average_unique_iter(); //average the unique data iteratively
    float average_unique_recur(); //average the unique data recursively WRAPPER
    int count_unique_recur(); //count unique data items recursively WRAPPER
    int sum_unique_recur(); //sum unique data items recursively WRAPPER
    int move_first_to_end_iter(); //move first to end iteratively and return sum
    int move_first_to_end_recur(); //move first to end recursively and return sum WRAPPER
    void display_all();
    int dup_first_to_end_iter(); //duplicate first and move to end iteratively, return sum of last two
    int dup_first_to_end_recur(); //duplicate first and move to end recursively WRAPPER, return sum of last two
    int remove_duplicate_iter(); //remove duplicates iteratively and return the number removed
    int remove_last_largest();


   private:		//notice there is both a head and a tail!
      int display_unique_recur(node * head); //display unique recursively
      int display_unique_recur(node * head, int match); //display unique recursively
      int display_last_not_recur(node * head, int to_match); //display last if not first recursively
      int count_unique_recur(node * head); //count unique recursively
      int count_unique_recur(node * head, int match); //count unique recursively
      int sum_unique_recur(node * head); //sum unique recursively
      int move_first_to_end_recur(node * & head, int first); //move first to end recursively and return sum
      int dup_first_to_end_recur(node * & head, int first); //duplicate first and move to end recursively, return sum of last two
      bool remove_last_largest(node * & head, int & largest);

      node * head;
      node * tail;
};
