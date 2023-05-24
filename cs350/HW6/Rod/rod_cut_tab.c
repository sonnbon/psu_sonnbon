#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// James Connor Baron-Williams
// Implement rod cutting algorithm in tabulation.
// The space

#define N 100000
double p[N];
double t[N];


void set_array(int n)
{
    srand(300);
    for (int i = 0; i <= n; ++i) {
        p[i] = rand() % 100 + 1;
    }
}

void print_p(int n)
{
    for (int i = 0; i <= n; ++i) {
        printf("[ %lf ] ", p[i]);
    }
    printf("\n");
}

void print_t(int n)
{
    for (int i = 0; i <= n; ++i) {
        printf("[ %lf ] ", t[i]);
    }
    printf("\n");
}

double max_sale_price(int n)
{
    double max = -1;  //Holds max value
    double price = 0; //Holds current price

    t[0] = p[0]; //Set first element to the existing array's element

    //Loop through both arrays, start at index 1, building the t[] array at
    //each iteration.
    for (int i = 1; i <= n; ++i) {
        //For each i, check all combinations of price sums up to index i.
        //Get price by adding the current index (j) of p[] to a previous 
        //(i - j) index of t[].
        for (int j = 1; j <= i; ++j) {
            price = t[i - j] + p[j]; //Get current price sum

            //If the price is greater than the current max, update max.
            if (price > max) {
                max = price;
            }
        }
        t[i] = max; //Update the current index of the max sale sum's array
    }
    return t[n]; //Return the maximum sale's sum
}


int main(void)
{
    int n = 0;

    printf("Enter n: ");
    scanf("%d", &n);

    set_array(n);
    print_p(n);

    printf("Maximum sales price with rod cutting %d items: %lf\n"
            , n
            , max_sale_price(n));
    print_t(n);

    return 0;
}
