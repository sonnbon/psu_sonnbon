#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// James Connor Baron-Williams
//
// Imagine a binary sequence (0’s and 1’s) that is n-digits long. How many 
// of these n-digit sequences exist if the sequences cannot contain consecutive 
// 1’s?



int binary_sequences(int n_digits)
{
    int num_of_sequences = 0;

    if (1 == n_digits)
        return 2;

    if (2 == n_digits)
        return 3;

    num_of_sequences += binary_sequences(n_digits - 1) 
                  + binary_sequences(n_digits - 2);

    return num_of_sequences;
}



int main()
{
    int n_digits = 0;
    int num_of_sequences = 0;

    printf("Enter the number of digits to sequence: ");
    scanf("%d", &n_digits);

    num_of_sequences = binary_sequences(n_digits);

    printf("There are %d binary sequences with %d digits, when 1 is not \n"
           "consecutive.\n"
           , num_of_sequences
           , n_digits);

    return 0;
}
