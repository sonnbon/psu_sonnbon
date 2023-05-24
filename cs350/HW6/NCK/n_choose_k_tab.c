#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// James Connor Baron-Williams
// Implement N choose K with tabulation. This could have been achieved in one
// function, then returned in the n_choose_k function, but I wanted to set the
// table up as tabulation was discussed in class, with the base cases hardcoded in.
// Then we can build up from their in the n_choose_k function to find our answer.
// Space and Time complexity are O(n x k).

#define MAX_N 10000
#define MAX_K 10000
long x[MAX_N][MAX_K];


void set_table(int n, int k)
{
    for (int i = 0; i <= n; ++i) {
        x[i][0] = 1;
        x[i][1] = i;
        x[i][i] = 1;
        for (int j = 0; j <= k; ++j) {
            if (j > i) {
                x[i][j] = 0;
            }
        }
    }
}



void print_table(int n, int k)
{
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            printf("[ %ld ] ", x[i][j]);
        }
        printf("\n");
    }
}



long n_choose_k(int n, int k)
{
    if (n == k || k == 0 || k == 1 || k > n) {
        return x[n][k];
    }

    for (int i = 3; i <= n; ++i) {
        for (int j = 2; j <= k; ++j) {
            x[i][j] = x[i - 1][j - 1] + x[i - 1][j];
        }
    }
    return x[n][k];
}


int main()
{
    int n = 0;
    int k = 0;

    printf("What is n: ");
    scanf("%d", &n);

    printf("What is k: ");
    scanf("%d", &k);

    set_table(n, k);
    printf("Table set:\n");
    print_table(n, k);

    printf("%d choose %d is: %ld\n\n", n, k, n_choose_k(n, k));

    printf("Table post tabulation algorithm:\n");
    print_table(n, k);

    return 0;
}
