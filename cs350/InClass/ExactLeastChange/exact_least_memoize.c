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

    if (t[num] != -1)
        return t[num];
    if (1 == num || 3 == num || 4 == num)
        return 1;
    if (2 == num)
        return 2;

    a = exact_least_change(num - 4);
    b = exact_least_change(num - 3);
    c = exact_least_change(num - 1);

    min = a;

    if (b < min)
        min = b;
    if (c < min)
        min = c;

    t[num] = 1 + min;
    return t[num];
}

int main()
{
    int num = 0; //Value of coins to bring to bank
    
    for (int i = 0; i < N; ++i) {
        t[i] = -1;
    }

    printf("Enter # of coins you're bringing to the bank (integer): ");
    scanf("%d", &num);

    if (num > 0)
        printf("The exact least change is: %d\n", exact_least_change(num));

    return 0;
}



