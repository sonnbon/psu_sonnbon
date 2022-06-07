#include "list.h"



//REMOVE the last node from a LLL and return the count



/*
Question to ask:
1. Is the problem repetitive?  YES

2. Is part of the problem repetitive vs not?  No, the base case handles it

3. What is the simple stopping condition (the base case)?
   If head is NULL, empty list and there is nothing to do, return zero

4. Is there another stopping condition (or base case)?
   I'm at the alst ndoe.
   I know I'm at the last ndoe because head->next is NULL
   -delete the memory that head is pointing to, set head to NULL
   -return 1

5. Is there something that needs to be done in this invocation?
   - count ourselves

6. How do we get to the next smaller subproblem?
   Call the function with head->next
   Remember to catch the count coming back

7. Is there something that needs to be done AFTER the recursive call?
   NOPE

8. Make sure we return the correct information
   make sure to return the count

*/



int remove_last_recursive(node * & head)
{
    int count = 0;

    if (!head) return 0; //base case
    if (!head->next)
    {
        delete head;
        head = NULL;
        return 1;
    }
    ++count;
    count += remove_last_recursive(head->next);
    return count;
}



int remove_last_refined(node * & head)
{
    if (!head) return 0; //base case
    if (!head->next)
    {
        delete head;
        head = NULL;
        return 1;
    }
    return remove_last_recursive(head->next) + 1;
}



//REMOVE THE LARGEST ITEM IN A LLL (remove all and return how many we removed)

/*
Question to ask:
1. Is the problem repetitive?  YES

2. Is part of the problem repetitive vs not?  No
   I may want a "wrapper function" to set up the desired arguments
   I need an argument that is the current "largest" value found so far
   so a wrapper function will set this up

3. What is the simple stopping condition (the base case)?
   If head is NULL, empty list and there is nothing to do, return zero

4. Is there another stopping condition (or base case)? No

5. Is there something that needs to be done in this invocation?
   compare the data at this node and see if it is larger than the
   largest (that is passed in as an argument). If so, I need this
   argument to change (so I should pass this by reference)

6. How do we get to the next smaller subproblem?
   Call the function with head->next
   Remember to catch the count coming back

7. Is there something that needs to be done AFTER the recursive call?
   Yes, we need to compare the current nodes data to see if it is the largest
   and if it is, delete it and increment the counter

8. Make sure we return the correct information
   make sure to return the count
*/


//Wrapper
//to set up the largest as an argument to begin with
int remove_largest(node * & head)
{
    if (!head) return 0; //empty list
    int largest = head->data;

    return remove_largest(head, largest);
}

int remove_largest(node * & head, int & largest)
{
    if (!head) return 0;  //base case
    if (largest < head->data)  //update largest
        largest = head->data;
    int counter = remove_largest(head->next, largest);
    //time to remove as we UNWIND the stack
    if (head->data == largest)
    {
        node * temp = head->next;  //hold onto the next
        delete head;  //release the node
        head = temp;  //update head around the deleted node
        ++counter;
    }
    return counter;
}



