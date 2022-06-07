//clist.h
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;


struct node
{
    int data;	//some questions are a char * data;
    node * next;
};

class list
{
   public:
   		//These functions are already written
   		list();			//supplied
   		~list();		//supplied
   		void build();	//supplied
   		void display();	//supplied

	/* *****************YOUR TURN! ********************* */
	//Write your function prototype here:
    int remove_node_before_last();
    int display_all_but_last();
    bool remove_last();
    int copy_all(const list & from);
    int copy_to(list & new_list);
    int add_node_last(int num);
    int add_before_even();
    bool remove_same_last();
    int remove_out_of_order();


	private:
		node * rear;

        int remove_node_before_last(node * & rear);
        int display_all_but_last(node * rear);
        bool remove_last(node * & rear, node * front);
        int copy_all(node * & dest, node * src_rear, node * src_current);
        int copy_to(node * rear, node * & dest);
        int add_node_last(node * & rear, int num);
        int add_before_even(node * & rear);
        bool remove_same_last(node * & rear, int last);
        int remove_out_of_order(node * & rear);
};
