#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// James Connor Baron-Williams
// Implement minimum sum descent tabulation.
// The space and time complexity is O(n^2)

#define N 1000
long tri[N][N];
long t[N][N];


void set_table(int n)
{
/*                       tri[0][0] = 2;

                 tri[1][0] = 5; tri[1][1] = 4;

          tri[2][0] = 1; tri[2][1] = 4; tri[2][2] = 7;

    tri[3][0] = 8; tri[3][1] = 6; tri[3][2] = 9; tri[3][3] = 6;
*/
    srand(300);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            tri[i][j] = rand() % 100 + 1;
        }
    }
}

void print_tri(int n)
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            printf("[ %ld ] ", tri[i][j]);
        }
        printf("\n");
    }
}

void print_t(int n)
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            printf("[ %ld ] ", t[i][j]);
        }
        printf("\n");
    }
}

long min_sum_descent(int n)
{
    long min = 0; //Holds min value

    t[0][0] = tri[0][0]; //Set first index to same index of triangle

    //Loop through rows, starting at index 1.
    for (int i = 1; i < n; ++i) {
        //Loop through colums, up to no more than the value of i.
        for (int j = 0; j <= i; ++j) {
            //If we are all the way to the "left" add the value that is above
            //to the right.
            if (j == 0) {
                t[i][j] = t[i - 1][j] + tri[i][j];
            }
            //If we are all the way to the "right" add teh value that is above
            //to the left.
            else if (j == i) {
                t[i][j] = t[i - 1][j - 1] + tri[i][j];
            }
            //Otherwise, add the minimum between the "left" and "right" values
            //above.
            else {
                if (t[i - 1][j - 1] < t[i - 1][j]) {
                    t[i][j] = t[i - 1][j - 1] + tri[i][j];
                }
                else {
                    t[i][j] = t[i - 1][j] + tri[i][j];
                }
            }
        }
    }

    min = t[n - 1][0]; //Set min to the first value in the last row.

    //Loop through the bottom row, updating min if necessary.
    for (int j = 1; j < n; ++j) {
        if (t[n - 1][j] < min) {
            min = t[n - 1][j];
        }
    }
    return min;
}


int main(void)
{
    int n = 0;

    printf("Enter n: ");
    scanf("%d", &n);

    set_table(n);
    print_tri(n);

    printf("Minimum Sum Descent with %d rows and %d cols: %ld\n"
            , n
            , n
            , min_sum_descent(n));
    print_t(n);

    return 0;
}
