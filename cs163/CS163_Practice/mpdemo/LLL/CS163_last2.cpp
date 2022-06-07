#include "list.h"

/*
 * FINDING THE LAST 2 in a LLL
 * base case - head is NULL
 * Otherwise I want to go all the way to the end
 * The very first 2 I find as we "return" the stack is the last 2
 *
 * We need a flag variable - returned or can be a passed by reference argument
 *
 *
 * 1. Base case
 *   - head is NULL
 *   - return flag - NOT FOUND
 * 
 * 2. Anything to be done? NO
 * 
 * 3. How to get to the next smaller sub program
 *   - flag = call function with head->next
 *   - catch it!
 *
 * 4. After: if !found && it's a 2
 *   - reset flag
 *   - success
 */


//Find the last two in the list and change the data to 99 - HEAD RECURSION
bool find_last2(node * head)
{
    if (!head)
        return false; //not found the last 2
    bool found = find_last2(head->next);
    //Now is where the works happens
    if (!found && head->data == 2)
    {
        head->data = 99;
        found = true; //SUCCESS, we found it
    }
    return found;
}
