#include "list.h"

//Write the code to add a node at the end of LLL using recursion
int add_at_end(node * & head)
{
    //SIMPLE base case - WHY DO I WANT TO STOP
    if (!head)
    {
        head = new node;
        head->data = 99;
        head->next = NULL;
        return 1;
    }
    return add_at_end(head->next) + 1;
}

//Write the code to remove last node LLL using recursion
//Summ all of the data in the list as well
int remove_last_and_sum(node * & head)
{
    //SIMPLE base case - WHY DO I WANT TO STOP
    if (!head)
        return 0;
    if (!head->next)
    {
        //Sum does not include this node
        int local = head->data;
        delete head;  //release the memory that head is pointing at
        head = NULL;
        return local;
    }
    return head->data + remove_last_and_sum(head->next);
}
