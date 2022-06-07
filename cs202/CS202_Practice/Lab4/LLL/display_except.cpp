#include "list.h"

//Display everything except the first and last item in the LLL
//Return the sum of the first and last data items in main
//
//Wrapper
int list::display_except()
{
    int last {0};

    if (!head) return 0;
    if (!head->next)
        return head->data; //Sum of first and last! Don't display!
    
    last = display_except(head->next);

    cout << endl << endl;

    return head->data + last;
}

//Recursive call
int list::display_except(node * head)
{
    if (!head->next)
        return head->data;

    cout << head->data << " ";

    return display_except(head->next);
}
