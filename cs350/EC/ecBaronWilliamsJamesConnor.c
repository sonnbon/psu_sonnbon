#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// ----------------------------------------------------------------------------
// Author: James Connor Baron-Williams
// Course: CS350
// Assignment: Extra Credit - Heap Sort Method 2
// Due Date: March 13, 2023
// ----------------------------------------------------------------------------
// This file implements Method 2 of the heap sort algorithm, or the Swap Down
// Algorithm. It first takes an array created manually by the user and
// transforms it into an array representation of a Maximum Heap using the Swap 
// Down Algorithm (Method 2). Once the heap representation is created, the data 
// in the array is sorted by swapping the root element with the last element in
// the heap, reheaping the swapped element into the correct position of a heap
// that is size - 1 smaller, and then repeating (those last two steps) until 
// the size of the heap is one element.
// ----------------------------------------------------------------------------

#define ARRAY_SIZE 100000000

float x[ARRAY_SIZE]; //Array to be sorted



//This function creates an array manually sized and inputted by the user. It
//takes no arguments and returns an integer to represent a success (size) or 
//failure (0) of the operation.
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

    //Have the user enter in the elements for the array.
    for (int i = 0; i < size; ++i) {
        printf("Please enter a number into the array: ");
        scanf("%f", &x[i]); //Read in element number
    }

    return size;
}



//This function prints an array's elements. It takes two integers, representing
//a low and high index of an array, as arguments, and has a void return type.
void print_array(int lo, int hi)
{
    for (int i = lo; i <= hi; ++i)
        printf("%.3f ", x[i]);

    printf("\n") ;
}



//This function swaps two values with each other. It takes two pointers to 
//floats, representing the values to be swapped with each other, as arguments,
//and has a void return type.
void swap(float *num1, float *num2)
{
    float temp = 0; //Holds a value for swapping

    if (!num1 || !num2)
        return;

    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}



//This function implements method 2, or the swap down method, for maintaining a 
//Maximum Heap. It takes two integers, representing the parent and high index 
//of an array, as arguments and has a void return type.
void swap_down(int parent, int hi)
{
    int left = (2 * parent) + 1;  //Holds the left child index
    int right = (2 * parent) + 2; //Holds the right child index
    int largest = parent;         //Holds largest item, set to parent index

    //Check if left child element is greater than the largest element 
    //(initially set to parent).
    if (left <= hi && x[largest] < x[left]) {
        largest = left;
    }

    //Check if right child element is greater than the largest element.
    if (right <= hi && x[largest] < x[right]) {
        largest = right;
    }

    //If the largest element is not the parent, then swap and call the function
    //again, using the largest as the new parent input.
    if (largest != parent) {
        swap(&x[parent], &x[largest]);
        swap_down(largest, hi);
    }
}



//This function creates the heap itself by looping through the array backwards,
//beginning where the last element's parent should be. It takes two integers,
//representing the low and high index, as arguments and has a void return type.
void create_heap(int lo, int hi)
{
    //Loop through each parent, traversing backwards from the last parent
    //(parent of the hi index), transforming the array into a Maximum Heap.
    for (int i = (hi - 1) / 2; i >= lo; --i) {
        swap_down(i, hi);
    }

}



//This function sorts a Maximum Heap. It first swaps the root element of a 
//heap with its last element. It then re-heaps the heap, only using size - 1 of
//the heap, by moving the new root to its correct heap position (swapping 
//down). Those two steps are then repeated until the size of the heap is one. 
//It takes two integers, representing the low and high index of an array, as 
//arguments and has a void return type.
void heap_sort(int lo, int hi)
{
    //Loop through heap, swapping and repositioning the root until it is 
    //sorted.
    for (int i = hi; i > 0; --i) {
        swap(&x[lo], &x[i]);
        swap_down(lo, i - 1); //Put root in the correct modified heap position
    }
}



int main()
{
    int size = 0; //Size of the data set to be used
    int lo = 0;   //Low index number of array
    int hi = 0;   //High index number of array

    size = create_array(); //Build random array and return its size

    //If the size is valid, print the unsorted array, create the heap and
    //display the heaped array, then heap_sort the array and display the sorted
    //array.
    if (size > 0)
    {
        hi = size - 1;

        printf("\n========================================================\n");
        printf("Number of data items: %d\n\n", size);

        printf("Unsorted data: ");
        print_array(lo, hi);
        printf("\n");

        create_heap(lo, hi); //Create heap of out the inputted array

        printf("Heaped data:   ");
        print_array(lo, hi);
        printf("\n");

        heap_sort(lo, hi); //Sort the heap of data

        printf("Sorted data:   ");
        print_array(lo, hi);
        printf("========================================================\n");
    }

  return 0;
}
