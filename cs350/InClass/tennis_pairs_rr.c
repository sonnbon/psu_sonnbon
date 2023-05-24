#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// James Connor Baron-Williams
//
// How many ways are there to pair off 2n people for tennis matches? Express 
// this function in terms of f(n), where n is the number of PAIRS and 2n is the 
// number of people.



int ways_to_pair(int n_pairs)
{
    int num_of_ways = 0;

    if (n_pairs == 1)
        return 1;

    num_of_ways += ((2 * n_pairs) - 1) * ways_to_pair(n_pairs - 1);

    return num_of_ways;
}



int main()
{
    int n_pairs = 0;
    int num_of_ways = 0;

    printf("Enter the number of pairs to pair off for tennis matches: ");
    scanf("%d", &n_pairs);

    num_of_ways = ways_to_pair(n_pairs);

    printf("There are %d ways to pair off 2(%d) people for tennis matches.\n"
           , num_of_ways
           , n_pairs);

    return 0;
}
