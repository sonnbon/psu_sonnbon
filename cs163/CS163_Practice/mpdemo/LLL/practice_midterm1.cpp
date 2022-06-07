#include "list.h"

//Just practicing traversal, insertion, removal, and copy

int count_node(node * head)
{
    if (!head) return 0;
    return count_node(head->next) + 1;
}

int sum_all(node * head)
{
    int sum = 0;
    if (!head) return 0;
    sum = head->data;
    return sum += sum_all(head->next);
}

int sum_even2(node * head)
{
    int sum = 0;
    if (!head) return 0;
    if (head->data % 2 == 0)
        sum = head->data;
    return sum += sum_even2(head->next);
}

int average(node * head)
{
    float avg = 0.0;
    return avg = sum_all(head) / count_node(head);
}
    
int copy_new(node * head, node * & new_head)
{
    if (!head)
    {
        new_head = NULL;
        return 0;
    }
    new_head = new node;
    new_head->data = head->data;
    new_head->next = NULL;

    return copy_new(head->next, new_head->next) + 1;
}
    
int add_at_beginning(node * & head)
{
    if (!head)
    {
        head = new node;
        head->data = 988;
        head->next = NULL;
        return 1;
    }
    node * temp = new node;
    temp->data = 988;
    temp->next = head;
    head = temp;
    return 1;
}

int add_at_end(node * & head)
{
    if (!head)
    {
        head = new node;
        head->data = 19999;
        head->next = NULL;
        return 0;
    }
    return add_at_end(head->next) + 1;
}

int duplicate_last(node * & head)
{
    if (!head)
      return 0;
    if (!head->next)
    {
      node * temp = new node;
      temp->data = head->data;
      head->next = temp;
      temp->next = NULL;
      return 1;
    }
    return duplicate_last(head->next) + 1;
}

int add_after_any_2(node * & head)
{
    if (!head) return 0;
    if (!head->next && head->data == 2)
    {
        node * temp = new node;
        temp->data = 3939;
        head->next = temp;
        temp->next = NULL;
        return 1;
    }
    if (head->data == 2)
    {
        node * temp = new node;
        temp->data = 3939;
        temp->next = head->next->next;
        head->next = temp;
    }
    return add_after_any_2(head->next) + 1;
}

int remove_first(node * & head)
{
    if (!head) return 0;
    if (!head->next)
    {
        delete head;
        head = NULL;
        return 1;
    }
    node * temp = head->next;
    delete head;
    head = temp;
    return 1;
}

int remove_last_node(node * & head)
{
    if (!head) return 0;
    if (!head->next)
    {
        delete head;
        head = NULL;
        return 1;
    }
    return remove_last_node(head->next);
}

int remove_last_two_nodes(node * & head)
{
    if (!head) return 0;
    if (!head->next)
    {
        delete head;
        head = NULL;
        return 1;
    }
    if (!head->next->next)
    {
        delete head->next;
        delete head;
        head = NULL;
        return 2;
    }
    return remove_last_two_nodes(head->next);
}

int remove_every_node(node * & head)
{
    if (!head) return 0;
    if (!head->next)
    {
        delete head;
        head = NULL;
        return 1;
    }
    node * temp = head->next;
    delete head;
    head = temp;
    return remove_every_node(head);
}

int delete_all_but_first(node * & head)
{
    if (!head) return 0;
    if (!head->next) return 1;
    node * temp = head->next->next;
    delete head->next;
    head->next = temp;
    return delete_all_but_first(head);
}

bool first_equal_last(node * head, int & data)
{
    if (!head) return false;
    if (!head->next)
        data = head->data;
    
    first_equal_last(head->next, data);

    if (head->data == data)
        return true;
    return false;
}
    
int count_greater_than_4(node * head)
{
    if (!head) return 0;
    if (head->data > 4)
      return count_greater_than_4(head->next) + 1;
    return count_greater_than_4(head->next);
}

int copy_even_only(node * head, node * & new_head)
{
    if (!head)
    {
        new_head = NULL;
        return 0;
    }
    if (head->data % 2 == 0)
    {
        new_head = new node;
        new_head->data = head->data;
        new_head->next = NULL;
        return copy_even_only(head->next, new_head->next);
    }
    return copy_even_only(head->next, new_head);
}

float average_even(node * head)
{
    float avg = 0.0;

    if (!head) return 0;

    avg = sum_even2(head) / even_count(head);
    return avg;
}

float even_count(node * head)
{
    if (!head) return 0;
    if (head->data % 2 == 0)
        return even_count(head->next) + 1;
    return even_count(head->next);
}

int sum_less_than_10 (node * head)
{
    if (!head) return 0;
    if (head->data < 10)
    {
        return sum_less_than_10(head->next) + head->data;
    }
    return sum_less_than_10(head->next);
}

int count_same_first(node * head)
{
    int data = 0;
    if (!head) return 0;
    data = head->data;
    return count_same_first(head->next, data);
}

int count_same_first(node * head, int data)
{
    if (!head) return 0;
    if (data == head->data)
        return count_same_first(head->next, data) + 1;
    return count_same_first(head->next, data);
}

int count_same_last(node * head)
{
    int data = 0;
    int count = 0;
    if (!head) return 0;
    if (!head->next)
      data = head->data;
    data = count_same_last(head->next);

    if (head->data == data)
        ++count;
    return count;
}

int remove_first_place_last(node * & head)
{
    int data = 0;
    if (!head) return 0;
    node * temp = head->next;
    data = head->data;
    delete head;
    head = temp;
    
    return remove_first_place_last(head, data);
}

int remove_first_place_last(node * & head, int data)
{
    if (!head) return 0;
    if (!head->next)
    {
        node * temp = new node;
        temp->data = data;
        temp->next = NULL;
        head->next = temp;
        return 1;
    }
    return remove_first_place_last(head->next, data);
}

int remove_largest(node * & head)
{
    if (!head) return 0;
    int largest = head->data;
    return remove_largest(head->next, largest);
}

int remove_largest(node * & head, int & largest)
{
    if (!head) return 0;
    if (largest < head->data)
        largest = head->data;
    int counter = remove_largest(head->next, largest);
    if (largest == head->data)
    {
        node * temp = head->next;
        delete head;
        head = temp;
        ++counter;
    }
    return counter;
}

int remove_last_2(node * & head)
{
    int count = 0;
    if (!head) return 0;
    if (head->data == 2)
        ++count;
    count += remove_last_2(head->next);
    return remove_last_2(head, count);
}

int remove_last_2(node * & head, int count)
{
    int count_check = 0;
    if (!head) return 0;
    if (head->data == 2)
    {
      ++count_check;
      if (count_check == count)
      {
        node * temp = head->next;
        delete head;
        head = temp;
        return count_check;
      }
    count_check += remove_last_2(head->next, count);
    return count_check;
}




    





    

























    

