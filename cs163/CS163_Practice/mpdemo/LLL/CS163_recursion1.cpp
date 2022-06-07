#include "list.h"

int count_all(node * head)
{
    if (!head) return 0;
    int count = 1;   //++count;
    count += count_all(head->next);
    return count;
}


int count_all2(node * head)
{
    if (!head) return 0;
    return count_all2(head->next) + 1;
}


//Count the number of times the last node's data appears in a LLL
//Return the count and have the last item be as an argument
int count_last(node * head, int & last)
{
    if (!head) return 0; //count is zero at the time we are an empty list
    if (!head->next)   //at the last node
    {
        last = head->data;
        return 1;
    }
    int count = count_last(head->next, last);
    //AFTER the call - we NOW KNOW what the last node's data is
    if (head->data == last)
        ++count;
    return count;
}
