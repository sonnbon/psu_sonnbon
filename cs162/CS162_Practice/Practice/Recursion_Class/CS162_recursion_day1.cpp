#include "list.h"

//Connor Williams
//Class lecture on recursion

/*
//Loop
int display_everything (node * head)
{
    node * current = head;
    int count = 0;
    while (current != NULL)
    {
        cout << head->data << " ";
        ++count;
        current = current->next;
    }
    return count;
}

//Recursion instead
int display_recursive(node * head)
{
    //Base Case - what will STOP the repetitive process
    if (!head)
        return 0;
    //What to do otherwise in this invocation
    cout << head->data << " ";
    return display_recursive(head->next) + 1;
}


//Recursion instead with count
int display_recursive(node * head)
{
    int count = 0;
    //Base Case - what will STOP the repetitive process
    if (!head)
        return 0;
    //What to do otherwise in this invocation
    cout << head->data << " ";
    //How to get to the next smaller subproblem
    count += display_recursive(head->next);
    return count;
    // return display_recursive(head->next) + 1;
}*/


int display_reverse(node * head)
{
    //Base Case - what will STOP the repetitive process
    if (!head)
        return 0;
    int count = 1;
    count += display_reverse(head->next);
    cout << head->data << " ";
    return count;
}

void remove_all_nodes(node * & head)
{
    //Base case - process ALL nodes, we want to stop when head is NULL
    if (!head)
        return;
    node * hold = head->next; //hold onto the next node
    delete head;              //get rid of node
    head = hold;              //update head around the deleted node without accessing memory that
                              //is not mine
    remove_all_nodes(head);
}


void remove_all_nodes_reverse(node * & head)
{
    //Base case - process ALL nodes, we want to stop when head is NULL
    if (!head)
        return;
    remove_all_nodes(head->next);
    delete head;              //get rid of node
    head = NULL;
}
