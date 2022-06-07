//doubly linked list
#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
using namespace std;


struct node
{
    int data;		//some questions use a char * data;
    node * previous;
    node * next;
};

class list
{
    public:
        //These functions are already written
        list();         //supplied
        ~list();        //supplied
        void build();   //supplied
        void display(); //supplied
        

     /* *****************YOUR TURN! ******************************** */
     /* place your prototype here */
        int copy_list(list & source);
        int remove_every_other();
        bool insert_data(int num);
        int duplicate_first();
     
     private:
        int copy_list(node * head, node * & dest, node * & tail);
        int remove_every_other(node * & head);
        bool insert_data(node * & head, int num);
        int duplicate_first(node * & head, int first);

         node * head;   //notice there is both a head
         node * tail;   //and a tail, common for DLL
};
