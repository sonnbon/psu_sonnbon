#include "list.h"

int display_except(node * head)
{
    int count = 0;
    int fifth = 0;
    node * current = head;

    if (!head)
        return 0;
    while (current)
    {
      ++count;
      if (count == 5)
      {
        fifth = current->data;
        current = current->next;
      }
      else
      {
          cout << current->data << "  ";
          current = current->next;
      }
    }
     return fifth;
}
            

int display_except1(node * head)
{
    int count = 0;
    int fifth = 0;
    return display_except2(head, count, fifth);
}
            

int display_except2(node * head, int count, int fifth)
{
    if (!head)
        return fifth;
    ++count; //count myself
    if (5 == count)
        fifth = head->data;
    else
        cout << head->data;
    return display_except2(head->next, count, fifth);
}
