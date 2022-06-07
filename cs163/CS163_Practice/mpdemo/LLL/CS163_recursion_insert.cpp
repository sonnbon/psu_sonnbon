#include "list.h"

// Let's add the first node's data to the end of the list, amking
// a new node. Return # of times this data exists in the list.


/*
Question to ask:
1. Is the problem repetitive?   Yes
2. Is part of the problem repetitive vs not? 
    We need a wrapper function to set up the recursive function
    with the first node's data (if there is a first node)


For the repetitive part:
3. What is the simple stopping condition (the base case)?
   (eg., if head is NULL)
   -If !head, add the new node with the data passed in

4. Is there another stopping condition (or base case)?
   NO

5. Is there something that needs to be done in this invocation?
   -Compare the data to see if it is a match and add 1

6. How do we get to the next smaller subproblem?
   Call the function with head->next

7. Is there something that needs to be done AFTER the recursive call?
   NO

8. Make sure we return the correct information
*/


//Wrapper or helper function that sets the stage for what we want to do
int append_end(node * & head)
{
    if (!head) return 0; //empty list
    return append_end(head->next, head->data) + 1;
}


//Recursive to add at the end
int append_end(node * & head, int data)
{
    if (!head)
    {
        head = new node;
        head->data = data;
        head->next = NULL;
        return 1;
    }
    if (head->data == data)
        return append_end(head->next, data) + 1;
    return append_end(head->next, data);
}
