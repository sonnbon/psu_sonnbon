#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// James Connor Baron-Williams
// Pebble Collecting Robot - Can only move right or down

#define M 4
#define N 5
int x[M][N];

void print_grid(void)
{
    for (int m = 0; m < M; ++m) {
        for (int n = 0; n < N; ++n) {
            printf("[ %d ] ", x[m][n]);
        }
        printf("\n");
    }
}

int robot_collector(int row, int col)
{
    int result = 0;
    int max = 0;
    int a, b = 0;
    int pebble = 0;

    if (row == 0 && col == 0) {
        if (x[row][col] == 1)
            pebble = 1;
        return pebble;
    }
    if (row < 0 || col < 0)
        return 0;

    if (x[row][col] == 1)
        pebble = 1;

    a = robot_collector(row - 1, col);
    b = robot_collector(row, col - 1);
   
    max = a; 
    if (a < b)
        max = b;

    result = pebble + max;
    return result;
}

int main()
{
    int r = M;
    int c = N;

    //Set grid to zero
    for (int m = 0; m < M; ++m) {
        for (int n = 0; n < N; ++n) {
            x[m][n] = 0;
        }
    }

    //Add custom pebbles (1).
    x[0][1] = x[0][4] = x[1][1] = x[1][2] = x[1][4] = x[2][0] = x[2][2]
            = x[2][3] = x[3][0] = x[3][3] = x[3][4] = 1;
    print_grid();

    printf("\nMax pebbles robot can pick up: %d\n", robot_collector(r, c));
    return 0;
}

