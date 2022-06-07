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
//int remove_after_isempty(node * & root, int data);
//int remove_item(node * & root, int data);
//float display_largest_and_smallest(node * root);
//int display_smallest(node * root);
//int display_largest(node * root);
int count_all(node * root);
int count_even(node * root);
int sum_all(node * root);
int sum_even(node * root);
int count_largest_left(node * root); 
int sum_root_largest(node * root);
int get_largest(node * root);
int get_smallest(node * root);
int display_sorted(node * root);
int count_larger(node * root);
int count_larger_than_root(node * root, int data);
int display_largest_smallest(node * root);
int largest_equal_root(node * root);
int goto_root_IOS(node * root);
int display_root_IOS(node * root);
int remove_leaves(node * & root);
int remove_largest(node * & root);
int remove_smallest(node * & root);
int remove_smallest_and_largest(node * & root);
float average_all(node * root);
float average_even(node * root);
int copy_tree(node * & dest, node * source);
int copy_even(node * & dest, node * source);
int insert_num(node * & root, int data);
int remove_all(node * & root);
int count_match(node * root, int data);
int insert_unique(node * & root, int data);
bool ismatch(node * root, int data);
int count_leaves(node * root);
int get_height(node * root);
int display_largest_two(node * root);

