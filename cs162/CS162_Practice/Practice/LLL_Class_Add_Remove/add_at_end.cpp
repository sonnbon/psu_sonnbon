#include "list.h"

//Add at the end of a LLL
//and return the number of items in this list

int add_end_LLL(node * & head, int new_data)
{
    node * current = head;  //for traversal
    int count = 0;

    if(!head) //there is nothing in the list - it is empty
    {
        head = new node;
        head->data = new_data;
        head->next = NULL;
    }
    else //traverse to the end of the LLL
    {
        while (current->next)  //loop until I get to the last node
        {
            ++count;
            current = current->next;  //traversal
        }

        //WE ARE NOW AT THE LAST NODE IN THE LIST
        current->next = new node;
        current = current->next;  //traverse to the new node
        current->data = new_data;
        current->next = NULL;
        count += 2;
    }
    return count;
}

void createlist(node * & head, node * new_animal)
{

    if (!head)
    {
        head = new node;
        head = new_animal;
        head->next = NULL;
    }
    else if (new_animal->data > head->data)
    {
        node * temp = new node;
        temp = new_animal;
        temp->next = head;
        head = temp;
    }
    else
    {
        node * current = head->next;
        node * previous = current;
        node * temp = new node;
        temp = new_animal;
        temp->next = NULL;

        while (current && new_animal->data < current->data)
        {
            previous = current;
            current = current->next;
        }
        previous->next = temp;
        temp->next = current;
    }
}

