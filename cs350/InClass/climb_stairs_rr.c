#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// James Connor Baron-Williams
//
// How many ways are there to climb a staircase with n-stairs if you can walk 
// up the stairs 1 or 2 at a time?



int ways_to_climb(int num_of_stairs)
{
    int num_of_ways = 0;

    if (0 == num_of_stairs || 1 == num_of_stairs)
        return 1;

    if (2 == num_of_stairs)
        return 2;

    num_of_ways += ways_to_climb(num_of_stairs - 1) 
                  + ways_to_climb(num_of_stairs - 2);

    return num_of_ways;
}



int main()
{
    int num_of_stairs = 0;
    int num_of_ways = 0;

    printf("Enter the number of stairs to climb: ");
    scanf("%d", &num_of_stairs);

    num_of_ways = ways_to_climb(num_of_stairs);

    printf("There are %d ways to climb %d stairs.\n", num_of_ways
           , num_of_stairs);

    return 0;
}
