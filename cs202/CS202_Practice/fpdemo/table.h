//list.h
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

struct node
{
    int data;   //some questions use char * data;
    node * left;
    node * right;
};

struct l_node
{
    int data;
    l_node * next;
};


class table
{
    public:
    	//These functions are supplied already
    	table();			//supplied
    	~table();			//supplied
        void build(); 		//supplied
        void display(); 	//supplied


/* ************** PLACE YOUR PUBLIC PROTOTYPE HERE ***************** */
        bool find_root();
        int duplicate_largest();
        double copy_get_avg(table & new_list);
        int copy_to_LLL(l_node * & head);
        bool add_if_new(int data);
        int remove_largest();
        int get_height();
        int find_IOS();
        int display_once();
        int copy_leaves(table & new_list);
        int delete_leaves();
 
 	private:
 		node * root;

/* ************** PLACE YOUR PRIVATE PROTOTYPE HERE ***************** */
        bool find_root(node * root); //Remember you can use the this pointer to find if duplicate.
        int duplicate_largest(node * & root);
        double copy_get_avg(node * & dest, node * src, int & count);
        int copy_to_LLL(l_node * & head, node * root);
        bool add_if_new(node * & root, int data);
        int remove_largest(node * & root);
        int get_height(node * root);
        int find_IOS(node * root);
        int display_once(node * root);
        int copy_leaves(node * & dest, node * src);
        int delete_leaves(node * & root);
};
  

