#include "list.h"

/*
1. Is the problem repetitive?
    Only apply recursion (or iteration) to repetitive problems!
2. Is part of the problem repetitive?
    Perform the non-repetitive part (possibly) in a "wrapper"
    And then write the recursive function for the repetitive part
3. Ok, now let's talk about the recursive function
    First, what is the base case? What is the simple stopping condition
    - what is the case
    - what do I want to do in the event that this case is found
4. Is there another stopping condition?
    - what is the case
    - what do I want to do in this case
5. Is there anything I need to do in this function?
    - what is it and what needs to get done
6. How do I get to the "next smaller subproblem"?
7. Is there anything else that needs to get done?
8. If our function has a non void return type, are you
    (a) returning the right information
    (b) catching or using the returned value
*/


int count_special(node * head)
{
    int count = 0;

    if (!head)
        return 0;
    if (head->data % 2 == 0) //even number
        ++count;
    count += count_special(head->next);
    return count;
}

//Find the largest data item in a linear linked list recursively
//AND cound how many there are
int find_largest(node * head, int & largest)
{
    //base case
    if (!head)
        return 0;
    //compare
    if (head->data > largest)
        largest = head->data;
    //How do I get to the next smaller subproblem?
    int count = find_largest(head->next, largest);

    if (head->data == largest)
        ++count;
    return count;
}
