#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// ----------------------------------------------------------------------------
// Author: James Connor Baron-Williams
// Course: CS350
// Assignment: HW4
// Due Date: February 8, 2023
// ----------------------------------------------------------------------------
// This file implements the smart_sort algorithm, which sorts an unsorted
// array. This algorithm involves multiple steps. It takes the left most 
// element, called the "pivot", and compares it with two different elements of 
// the list, starting with the closest and farthest indexed elements. 
// Incrementally, these comparable elements swap under circumstances that 
// result in the pivot being placed in the correct position while ensuring that 
// everything to the left of the pivot is less than the pivot and everything to 
// the right is greater than the pivot. From this point, recursion is 
// implemented to the left and right of this pivot to take care of the rest of 
// the sorting work.
// ----------------------------------------------------------------------------


#define ARRAY_SIZE 100000000

int x[ARRAY_SIZE]; //Array to be sorted



//This function creates an array of randomly generated data up to the size of
//the users request. It takes no arguments and returns an integer to represent 
//a success (size) or failure (0) of the operation.
int create_array()
{
    int size = 0; //Size of the data set to be used

    printf("Please enter the size of the array you wish to sort: ");
    scanf("%d", &size); //Read in size number

    //If size is too big, return a failure.
    if (size <= 0 || size > ARRAY_SIZE)
    {
        printf("Size request of %d is invalid\n", size);
        return 0;
    }

    //Randomly generate data for the array.
    srandom(300);
    for (int i = 0; i < size; ++i)
        x[i] = abs(random()) % 100;

    return size;
}



//This function prints an array's elements. It takes two integers, representing
//a low and high index of an array, as arguments, and has a void return type.
void print_array(int lo, int hi)
{
    for (int i = lo; i <= hi; ++i)
        printf("%d ", x[i]);

    printf("\n") ;
}



//This function swaps two values with each other. It takes two pointers to 
//integers, representing the values to be swapped with each other, as 
//arguments, and has a void return type.
void swap(int *num1, int *num2)
{
    int temp = 0; //Holds a value for swapping

    if (!num1 || !num2)
        return;

    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}



//This function sorts an array by taking a "pivot" element and placing all
//lower values at a lower index than where the "pivot" is and all higher values
//at a higher index than where the "pivot" is. It continues to sort through
//recursion, sorting everything to the "left" of the "pivot" and then
//everything to the "right" of the pivot. It takes two integers, representing
//the low and high index of an array, as arguments, and has a void return type.
void smart_sort(int lo, int hi)
{
    int pivot = lo;     //Pivot gets left most index value
    int p1 = pivot + 1; //P1 used for low index comparisons
    int p2 = hi;        //P2 used for high index comparisons
    int count = 0;      //Checks if loop has looped more than once

    //Check if there is no more work to be done.
    if (p1 > p2)
        return;

    //Compare p1's elements to the pivot's element while p1 is not equal to p2.
    while (p1 != p2)
    {
        //Increment p1 while it is less than p2 and while p1's element is not
        //greater than the pivot's element.
        while (p1 < p2 && x[p1] <= x[pivot])
            ++p1;

        //If count is greater than zero, the current p2 has already been
        //checked and should be decremented.
        if (p1 != p2 && count > 0)
            --p2;
        
        //Check that p1 is still not equal to p2.
        if (p1 != p2)
        {
            //Decrement p2 while it is greater than p1 and while p2's element
            //is not less than the pivot's element.
            while (p2 > p1 && x[p2] >= x[pivot])
                --p2;
        }

        //If p1 and p2 are still not equal to each other, then swap their
        //elements.
        if (p1 != p2)
        {
            swap(&x[p1], &x[p2]);
            ++p1;
        }

        ++count;
    }

    //P1 and p2 must equal each other now.
    //If p2's element is greater than the pivot's, decrement p2.
    if (x[p2] > x[pivot])
        --p2;

    swap(&x[pivot], &x[p2]); //Swap with the pivot to its correct location

    smart_sort(lo, p2 - 1); //Sort left of the pivot's correct location
    smart_sort(p2 + 1, hi); //Sort right of the pivot's correct location

    return;
}



int main()
{
    int size = 0; //Size of the data set to be used
    int lo = 0;   //Low index number of array
    int hi = 0;   //High index number of array

    size = create_array(); //Build random array and return its size

    //If the size is valid, print the array, smart_sort the array, then print 
    //the newly sorted array.
    if (size > 0)
    {
        hi = size - 1;

        printf("Array size: %d\n\n", size);

        printf("Unsorted data: ");
        print_array(lo, hi);

        smart_sort(lo, hi); //Sort the data through smart sort

        printf("Sorted data:   ");
        print_array(lo, hi);
    }

  return 0;
}
