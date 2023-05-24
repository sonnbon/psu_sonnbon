#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// James Connor Baron-Williams
// Sorting Algorithms - Selection Sort

const int MAX = 50;

int main()
{
    int array[MAX];
    int lf = 0;
    int rf = 0;
    int temp = 0;

    //randomize array
    for (int i = 0; i < MAX; ++i)
        array[i] = floor(1000*drand48());

    //print array
    for (int i = 0; i < MAX; ++i)
        printf("%d ", array[i]);

    printf("\n");

    //SELECTION SORT ----------------------------------------------------------
    //LF waits for rf to iterate before iterating itself to the second to last 
    //element
    for (lf = 0; lf < MAX - 1; ++lf)
    {
        //RF iterates to end of list
        for (rf = lf + 1; rf < MAX; ++rf)
        {
            //If left side is greater, swap them
            if (array[lf] > array[rf])
            {
                temp = array[lf];
                array[lf] = array[rf];
                array[rf] = temp;
            }
        }
    }

    //print sorted array
    for (int i = 0; i < MAX; ++i)
        printf("%d ", array[i]);

    printf("\n");
    //-------------------------------------------------------------------------
    
    return 0;
}



