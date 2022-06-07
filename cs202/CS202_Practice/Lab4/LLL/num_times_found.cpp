#include "list.h"

//Count the number of times the requested data is in a LLL
//Return the number
//
//Wrapper function
int list::num_times(int match)
{
    if (!head) return 0;

    return num_times(head, match);
}

//Recursive function
int list::num_times(node * head, int match)
{
    int count {0};

    if (!head) return 0;

    if (match == head->data)
        ++count;

    count += num_times(head->next, match);

    return count;

}
