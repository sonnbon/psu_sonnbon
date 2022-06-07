#include "cs163_list.h"
using namespace std;

//Sum  all of the data together in a LLL
int list::sum_total()
{
 	//FIRST do this iteratively here. Then recursively
        //COMMENT out the iterative version when  rewriting
        //the solution recursively
    /*if (!head) return 0; 
    node * current = head;
    int sum = 0;
    while (current)
    {
        sum += current->data;
        current = current->next;
    }
    return sum;*/
        //To solve this recursively write another
        //function:   int sum_total(node * head);
        //and call it from this function
    return sum_total(head);
}

//Now implement the function recursively!
int list::sum_total(node * head)
{
    if (!head) return 0;
    int sum = head->data;
    sum += sum_total(head->next);
    return sum;
}

// *************************************************
//Remove the last node in a LLL. Return false if the
//list is empty and nothing is removed
bool list::remove_last()
{
        //Write your code here
 	//FIRST do this iteratively here. Then recursively
        //COMMENT out the iterative version when  rewriting
    /*if (!head) return false;
    if (!head->next)
    {
        delete head;
        head = NULL;
        return true;
    }
    node * current = head->next;
    node * previous = head;
    while (current->next)
    {
        previous = current;
        current = current->next;
    }
    delete current;
    previous->next = NULL;
    return true;*/
    return remove_last(head, tail);
}

//Now implement the function recursively!
bool list::remove_last(node * & head, node * & tail)
{
    if (!head) return false;
    if (!head->next)
    {
        delete tail;
        delete head;
        head = NULL;
        tail = NULL;
        return true;
    }
    if (head->next == tail)
    {
        delete tail;
        head->next = NULL;
        tail = head;
        return true;
    }
    remove_last(head->next, tail);
    return true;
}

// ************************************************
//Remove all nodes in a LLL. Remove false if there is
//nothing to remove
bool list::remove_all()
{
        //Remove all nodes in a LLL
 	//FIRST do this iteratively here. Then recursively
        //COMMENT out the iterative version when  rewriting
    if (!head) return false;
    if (!head->next)
    {
        delete head;
        head = NULL;
        return true;
    }
    /*node * current = head;
    while (current)
    {
        current = current->next;
        delete head;
        head = current;
    }
    return true;
    */
    return remove_all(head);
}

//Now implement the function recursively!
bool list::remove_all(node * & head)
{
    if (!head) return false;
    if (!head->next)
    {
        delete head;
        head = NULL;
        return true;
    }
    node * temp = head->next;
    delete head;
    head = temp;

    remove_all(head);
    return true;
}


// ************************************************
//Return true if the requested item (sent in as an argument)
//is in the list, otherwise return false
bool list::find_item(int item_to_find)
{
        //Write your code here
    if (!head) return false;
    /*node * current = head;
    while (current && item_to_find != current->data)
        current = current->next;
    bool result = true;
    if (!current)
        result = false;
    return result;*/
    bool result = find_item(head, item_to_find);
    return result;
}

//Now implement the function recursively!
bool list::find_item(node * head, int item_to_find)
{
    if (!head) return false;
    if (item_to_find == head->data)
        return true;
    return find_item(head->next, item_to_find);
}


// ************************************************
//Make a complete copy of a LLL
bool list::copy(list & from)
{
        //Write your code here
    if (!(from.head)) return false;
    /*node * dest_head = new node;
    dest_head->data = from.head->data;
    dest_head->next = NULL;
    node * dest_tail = dest_head;
    from.head = from.head->next;
    while (from.head)
    {
        dest_tail->next = new node;
        dest_tail = dest_tail->next;
        dest_tail->data = from.head->data;
        from.head = from.head->next;
    }
    dest_tail->next = NULL;
    return true;*/
    node * dest_head = NULL;
    node * dest_tail = NULL;
    return copy(dest_head, dest_tail, from.head);
}

//Now implement the function recursively
bool list::copy(node * & dest_head, node * & dest_tail, node * source)
{
    if (!source) return false;
    dest_head = new node;
    dest_head->data = source->data;
    dest_head->next = NULL;
    dest_tail = dest_head;
    source = source->next;
    copy(dest_head->next, dest_tail, source);
    return true;

}
