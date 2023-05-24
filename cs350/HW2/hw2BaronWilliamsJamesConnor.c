#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// ----------------------------------------------------------------------------
// Author: James Connor Baron-Williams
// Course: CS350
// Assignment: HW2
// Due Date: January 30, 2023
// ----------------------------------------------------------------------------
// This file implements the merge_sort algorithm, which takes an array and 
// sorts its elements by using recursion, "dividing and conquering" the 
// unsorted array into smaller, simpler pieces of data and then builds them 
// back up into a sorted list.
// ----------------------------------------------------------------------------


#define ARRAY_SIZE 100000000

int x[ARRAY_SIZE];    //Array to be sorted
int temp[ARRAY_SIZE]; //Temp array to be copied to array x



//This function creates an array by reading input from the user (< input.txt
//for this assignment). It takes no arguments and returns an integer to
//represent a success (size) or failure (0) of the operation.
int create_array()
{
    int size = 0; //Size of the data set to be used

    scanf("%d", &size); //Read in size number

    //If size is too big, return a failure.
    if (size == 0 || size > ARRAY_SIZE)
    {
        printf("Size request of %d is invalid\n", size);
        return 0;
    }

    //Read numbers into an array set to the input size.
    for (int i = 0; i < size; ++i)
        scanf("%d", &x[i]);

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



//This function compares, sorts, and merges data from a temporary array to the 
//x array. It takes three integers, representing the low, middle, and high 
//indexes of the arrays, as arguments and has a void return type.
void merge(int lo, int mid, int hi)
{
    int lh_scan = 0; //For tracking the left hand index increment scans
    int rh_scan = 0; //For tracking the right hand index increment scans
    int count = 0;   //For tracking the temporary array assignments and indices

    lh_scan = count = lo; //Set lh_scan and count to lo
    rh_scan = mid + 1;


    //While the left and right side traversals are within their mid and hi
    //index bounds, respectively.
    while (lh_scan <= mid && rh_scan <= hi)
    {
        //Check if the left side element is less than the right side element
        //before assigning to temp and incrementing.
        if (x[lh_scan] < x[rh_scan])
        {
            temp[count] = x[lh_scan];
            ++lh_scan;
        }

        //Otherwise, assigne the right side element to temp and increment the
        //right index.
        else
        {
            temp[count] = x[rh_scan];
            ++rh_scan;
        }

        ++count; //Increment the current index of the temp array
    }

    //If the left hand side has not finished its scan, assign the remaining
    //elements to the temp array.
    while (lh_scan <= mid)
    {
        temp[count] = x[lh_scan];
        ++lh_scan;
        ++count;
    }

    //If the right hand side has not finished its scan, assign the remaining
    //elements to the temp array.
    while (rh_scan <= hi)
    {
        temp[count] = x[rh_scan];
        ++rh_scan;
        ++count;
    }

    //Copy the temp array over to the x array for less than the count of
    //elements assigned.
    for (lo; lo < count; ++lo)
        x[lo] = temp[lo];
}



//This function uses the merge sort algorithm to recursively sort an unsorted
//array through the divide and conquer method. It takes two integers,
//representing a low and high index of an array, as arguments, and has a void
//return type.
void merge_sort(int lo, int hi)
{
    int mid = 0;  //For tracking the middle of the array
    
    //Base case: Check if lo is equal to hi and return.
    if (lo == hi)
        return;

    mid = (hi + lo) / 2;

    merge_sort(lo, mid);     //Traverse left
    merge_sort(mid + 1, hi); //Traverse right
    merge(lo, mid, hi);      //Sort and merge the current passed in data
}



int main()
{
    int size = 0; //Size of the data set to be used
    int lo = 0;   //Low index number of array
    int hi = 0;   //High index number of array

    size = create_array(); //Build array and return its size

    //If the size is valid, print the array, merge_sort the array, then print 
    //the newly sorted array.
    if (size)
    {
        hi = size - 1;

        printf("Array size: %d\n\n", size);

        printf("Unsorted data: ");
        print_array(lo, hi);

        merge_sort(lo, hi); //Sort the data through merge sort

        printf("Sorted data:   ");
        print_array(lo, hi);
    }

  return 0;
}
