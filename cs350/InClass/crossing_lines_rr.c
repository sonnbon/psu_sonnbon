#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// James Connor Baron-Williams
//
// Imagine a piece of paper with n crossing lines how many regions of area are 
// there? The constraints are that no lines are ever parallel and no more than 
// two lines intersect at any single point.



int num_of_regions(int n_lines)
{
    int num_of_regs = 0;

    if (n_lines == 0)
        return 1;

    num_of_regs += num_of_regions(n_lines - 1) + n_lines;

    return num_of_regs;
}



int main()
{
    int n_lines = 0;
    int num_of_regs = 0;

    printf("Enter the number of pairs to pair off for tennis matches: ");
    scanf("%d", &n_lines);

    num_of_regs = num_of_regions(n_lines);

    printf("There are %d numbers of regions when %d lines are crossing.\n"
           , num_of_regs
           , n_lines);

    return 0;
}
