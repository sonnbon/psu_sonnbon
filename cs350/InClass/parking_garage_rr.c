#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// James Connor Baron-Williams
//
// Imagine a parking garage with n car spaces. Type A cars take up 1 space. 
// Type B and type C cars take up 2 spaces. Given an unlimited number of each 
// kind of car, how many arrangements of cars on n-spaces are there (order 
// matters as it is an arrangement)?



int ways_to_park(int n_spaces)
{
    int num_of_ways = 0;

    if (1 == n_spaces)
        return 1;

    if (2 == n_spaces)
        return 3;

    num_of_ways += ways_to_park(n_spaces - 1) 
                   + (2 * ways_to_park(n_spaces - 2));

    return num_of_ways;
}



int main()
{
    int n_spaces = 0;
    int num_of_ways = 0;

    printf("Enter the number of parking spaces: ");
    scanf("%d", &n_spaces);

    num_of_ways = ways_to_park(n_spaces);

    printf("There are %d ways to arrange cars a, b, and c, on %d parking \n"
           "spaces.\n"
           , num_of_ways
           , n_spaces);

    return 0;
}
