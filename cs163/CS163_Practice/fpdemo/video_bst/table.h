//list.h
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

//Connor Williams
//CS163

struct node
{
    int data;
    node * left;
    node * right;;
};

void build(node * & root);  //supplied
void display(node *  root); //supplied
void destroy_all(node * & root);

/* ************** PLACE YOUR PROTOTYPE HERE ***************** */
//int add_bst(node * & root, int data);
//int display_inorder(node * root);
int remove_after_isempty(node * & root, int data);
int remove_item(node * & root, int data);
  

