#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// James Connor Baron-Williams
//
//How many n-letter “words” can be created from an unlimited supply of 
//a’s, b’s, and c’s, if each word MUST contain an even number of a’s?



//For every new letter, we can add a b or c to the previous arrangement. This 
//gives us all arrangements with an even number of a's from the previous. Then
//we want to add all the arrangements from the previous that would have been an
//odd a, but would be even for the current arrangement. We add all the
//arrangements from the previous minus all the even arrangements of the
//previous to get the odd ones.
int n_letter_words(int n_letters)
{
    int num_of_ways = 0;

    if (1 == n_letters)
        return 2;

    num_of_ways += n_letter_words(n_letters - 1) + pow(3, n_letters - 1);

    return num_of_ways;
}



int main()
{
    int n_letters = 0;
    int num_of_ways = 0;

    printf("Enter the number of letters to arrange: ");
    scanf("%d", &n_letters);

    num_of_ways = n_letter_words(n_letters);

    printf("There are %d ways to create %d-letter words from an unlimited\n"
           "supply of a's, b's, and c's, when each word must contain an even\n"
           "number of a's.\n"
           , num_of_ways
           , n_letters);

    return 0;
}
