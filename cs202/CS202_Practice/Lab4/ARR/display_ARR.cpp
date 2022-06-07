#include "arr.h"

//Display all data in an ARR
//Return the number of items displayed
//
//Wrapper
int display_ARR()
{
    int count {0};

    if (!head) return 0;

    for (int i = 0; i < size; ++i)
        count += display_ARR(head[i]);

    return count;
}

//Recursive call
int display_ARR(node * head)
{
    if (!head)
        return 0;

    cout << head->data << " <--> ";

    return 1 + display_ARR(head->next);
}
