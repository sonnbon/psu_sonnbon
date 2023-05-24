#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define N 1000000
int t[N];

// James Connor Baron-Williams
// Exact least change algorithm, assuming we have three coins numd at
// 1, 3, and 4.

int exact_least_change(int num)
{
    int min = 0;     //To be min to add
    int a, b, c = 0; //To hold recursive values

    if (num == 1 || num == 2 || num == 3 || num == 4)
        return t[num];
    for (int k = 5; k <= num; ++k) {
        a = t[k - 1];
        b = t[k - 3];
        c = t[k - 4];

        min = a;
        if (b < min)
            min = b;
        if (c < min)
            min = c;

        t[k] = 1 + min;
    }

    return t[num];
}

int main()
{
    int num = 0; //Value of coins to bring to bank

    t[1] = t[3] = t[4] = 1;
    t[2] = 2;

    printf("Enter # of coins you're bringing to the bank (integer): ");
    scanf("%d", &num);

    if (num > 0)
        printf("The exact least change is: %d\n", exact_least_change(num));

    return 0;
}



