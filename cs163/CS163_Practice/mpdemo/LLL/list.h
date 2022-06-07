//list.h
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

struct node
{
    int data;
    node * next;
};

/* These functions are already written and can be called to test out your code */
void build(node * & head);  //supplied
void display(node * head);  //supplied
void destroy(node * &head); //supplied

/* *****************YOUR TURN! ******************************** */
//Write your function prototype here:

int remove_last_recursive(node * & head);
int remove_last_refined(node * & head);
int remove_first_last(node * & head);
int remove_last(node * & head);
int append_end(node * & head);
int append_end(node * & head, int data);
int count_node (node * head);
int sum_all(node * head);
int sum_even2(node * head);
int average(node * head);
int copy_new(node * head, node * & new_head);
int add_at_beginning(node * & head);
int add_at_end(node * & head);
int duplicate_last(node * & head);
int add_after_any_2(node * & head);
int remove_first(node * & head);
int remove_last_node(node * & head);
int remove_last_two_nodes(node * & head);
int remove_every_node(node * & head);
int delete_all_but_first(node * & head);
bool first_equal_last(node * head, int & data);
int count_greater_than_4(node * head);
int copy_even_only(node * head, node * & new_head);
float average_even(node * head);
int sum_less_than_10 (node * head);
float even_count(node * head);
int count_same_first(node * head);
int count_same_first(node * head, int data);
int count_same_last(node * head);
int count_same_last(node * head, int data);
int remove_first_place_last(node * & head);
int remove_first_place_last(node * & head, int data);
int remove_largest(node * & head);
int remove_largest(node * & head, int & largest);
int remove_last_2(node * & head);
int remove_last_2(node * & head, int count);
bool find_last2(node * head);
int remove_match(node * & head, int match);
