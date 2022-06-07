#include "list.h"
//Connor Williams
//CS162 - prerecorded lecture on Linear Linked Lists (LLL)

void display_every_item(node * head)
{
    node * current = head;
    while (current != NULL)  //while (current)
    {
        cout << current->data << ' ';
        current = current->next;
    }
}

//Display JUST the last item
void display_just_last(node * head)
{
    if (!head)  //if head == NULL - nothing to display
      return;
    node * current = head;
    while (current->next != NULL) //Stop at the last node
    {
        current = current->next;
    }
    cout << "The last item is: " << current->data << endl;
}
