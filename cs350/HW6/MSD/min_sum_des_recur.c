#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// James Connor Baron-Williams
// Implement minimum sum descent recursively.

#define M_MAX 1000
#define N_MAX 1000
long x[M_MAX][N_MAX];


void set_table()
{
                       x[0][0] = 2;

                 x[1][0] = 5; x[1][1] = 4;

          x[2][0] = 1; x[2][1] = 4; x[2][2] = 7;

    x[3][0] = 8; x[3][1] = 6; x[3][2] = 9; x[3][3] = 6;
}

long min_sum_des_rec(int n1, int n2)
{
    long sum_a = 0;
    long sum_b = 0;
    long cur_min = 0;
    long real_min = 0;

    if (n2 > n1 || n1 < 0 || n2 < 0) {
        return 0;
    }

    if (min_sum_des_rec(n1 - 1, n2 - 1) < min_sum_des_rec(n1 - 1, n2)) {
        sum +=
    }

    if (sum_b < sum_a) {
        cur_min = sum_b;
    }
    else {
        cur_min = sum_a;
    }
    return real_min;
}


int main(void)
{
    int n = 4;

    set_table();

    printf("Minimum Sum Descent with %d rows and %d cols: %ld\n"
            , n
            , n
            , min_sum_des_rec(n, n));

    return 0;
}
