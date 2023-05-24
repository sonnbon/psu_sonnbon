#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// James Connor Baron-Williams
// Implement N choose K with memoization.

#define MAX_N 10000
#define MAX_K 10000
long x[MAX_N][MAX_K];


void set_table(int n)
{
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            x[i][j] = -1;
        }
    }
}



void print_table(int n)
{
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            printf("[ %ld ] ", x[i][j]);
        }
        printf("\n");
    }
}



long n_choose_k_memo(int n, int k)
{
    if (x[n][k] != -1)
        return x[n][k];
    if (n == k) {
        x[n][k] = 1;
        return 1;
    }
    if (k == 1) {
        x[n][k] = n;
        return n;
    }
    if (k > n || n < 0 || k < 0) {
        x[n][k] = 0;
        return 0;
    }

    x[n][k] = n_choose_k_memo(n - 1, k - 1) + n_choose_k_memo(n - 1, k);
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

    set_table(n);
    printf("Table set:\n");
    print_table(n);

    printf("%d choose %d is: %ld\n\n", n, k, n_choose_k_memo(n, k));

    printf("Table post memoization algorithm:\n");
    print_table(n);

    return 0;
}
