#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// James Connor Baron-Williams
// Implement N choose K recursively.


int n_choose_k_rec(int n, int k)
{
    if (n == k) return 1;
    if (k == 1) return n;
    if (k > n || n < 0 || k < 0) return 0;

    return n_choose_k_rec(n - 1, k - 1) + n_choose_k_rec(n - 1, k);
}


int main(void)
{
    int n, k = 0;

    printf("What is n: ");
    scanf("%d", &n);

    printf("What is k: ");
    scanf("%d", &k);

    printf("%d choose %d is: %d\n", n, k, n_choose_k_rec(n, k));

    return 0;
}
