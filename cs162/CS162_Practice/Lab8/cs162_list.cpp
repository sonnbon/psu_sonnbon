#include "cs162_list.h"


//Implement the following functions for Lab #8

//Insert a node at the beginning of a linear linked list
void list::insert(int to_add)
{
    node * temp;
    temp = new node;

	//Step #5 - Write the code here
    if (!head)
    {
        head = new node;
        head->data = to_add;
        head->next = NULL;
    }
    else
    {
        temp->next = head;
        head = temp;
        head->data = to_add;
    }
}

//Count the number of nodes in the LLL, returning the result
//Add a new node to the front of the list
//with the count as the data member
int list::count_and_insert()
{
     	//Step #6 - Write the code here
    node * current;
    current = head;
    int count = 0;

    if (!head)
        return 0;
    else
    {
        while (current)
        {
            current = current->next;
            ++count;
        }
        count += 1;
        return count;
    }
}

//Append a node to the end of a linear linked list
void list::append(int to_add)
{
        //Step #7 - Write the code here
        node * current;
        current = head;
        node * temp;
        temp = new node;
        temp->data = to_add;
        
        if (!head)
        {
            head = new node;
            head->data = to_add;
            head->next = NULL;
        }
        else
        {
            while (current->next)
            {
                current = current->next;
            }
            current->next = temp;
            temp->next = NULL;
        }
}

//Remove the last node from the list
void list::remove_last()
{
   	//Step #7 - Write the code here
    node * current;
    current = head;
    node * previous;
    previous = current;
    node * hold;

    if (!head)
      cout << "empty" << endl;
    else if (!head->next)
    {
        delete current;
        head = NULL;
    }
    else
    {
      while (current->next)
      {
        previous = current;
        current = current->next;
      }
      hold = current->next;
      delete current;
      previous->next = hold;
    }
}

//Deallocate all nodes (Destructor)
list::~list()
{
        //Step #8 - Write the code here
        node * temp;
        
        while (head)
        {
           temp = head->next;
           delete head;
           head = temp;
        }

}

//Challenge - 
void list::copy_last()
{
    


}      

