#include "list.h"

//Connor Williams
//CS162 Class lecture on LLL
//This function is going to return the number of items in the list and output
//any even data
int display_even_data(node * head)
{
    //With a linear linked list I don't know how many items I have. There
    //could be zero
    if (NULL == head) //empty list
        return 0;

    //Need a counter variable
    int counter = 0;
    node * current = head;  //Use a separate variable to traverse

    //Loop through all of the nodes, checking to see if they contain even data
    while (current != NULL) //while (current)
    {
        ++counter;  //count the node
        if (current->data % 2 == 0)  //even data
            cout << current->data << ' ';
        current = current->next;  //traverse to the next node
    }
    return counter;
}

