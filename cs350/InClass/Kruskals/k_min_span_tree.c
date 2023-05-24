#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// James Connor Baron-Williams
// Implement Kruskall's Minimum Spanning Tree

#define M 1000

int graph[M][M];
int table[M];
int size = 6;
int length = 0;


struct graph_s
{
    int edge;
    int start;
    int end;
} graph_t;

struct graph_s array[M*M];
struct graph_s mst[M*M];
struct graph_s temp[M*M];

void merge(int lo, int mid, int hi)
{
    int lh_scan = 0; //For tracking the left hand indearray increment scans
    int rh_scan = 0; //For tracking the right hand indearray increment scans
    int count = 0;   //For tracking the temporary array assignments and indices

    lh_scan = count = lo; //Set lh_scan and count to lo
    rh_scan = mid + 1;


    //While the left and right side traversals are within their mid and hi
    //indearray bounds, respectively.
    while (lh_scan <= mid && rh_scan <= hi)
    {
        //Check if the left side element is less than the right side element
        //before assigning to temp and incrementing.
        if (array[lh_scan].edge < array[rh_scan].edge)
        {
            temp[count].edge = array[lh_scan].edge;
            temp[count].start = array[lh_scan].start;
            temp[count].end = array[lh_scan].end;
            ++lh_scan;
        }

        //Otherwise, assigne the right side element to temp and increment the
        //right indearray.
        else
        {
            temp[count].edge = array[rh_scan].edge;
            temp[count].start = array[rh_scan].start;
            temp[count].end = array[rh_scan].end;
            ++rh_scan;
        }

        ++count; //Increment the current indearray of the temp array
    }

    //If the left hand side has not finished its scan, assign the remaining
    //elements to the temp array.
    while (lh_scan <= mid)
    {
        temp[count].edge = array[lh_scan].edge;
        temp[count].start = array[lh_scan].start;
        temp[count].end = array[lh_scan].end;
        ++lh_scan;
        ++count;
    }

    //If the right hand side has not finished its scan, assign the remaining
    //elements to the temp array.
    while (rh_scan <= hi)
    {
        temp[count].edge = array[rh_scan].edge;
        temp[count].start = array[rh_scan].start;
        temp[count].end = array[rh_scan].end;
        ++rh_scan;
        ++count;
    }

    //Copy the temp array over to the array array for less than the count of
    //elements assigned.
    for (lo; lo < count; ++lo) {
        array[lo].edge = temp[lo].edge;
        array[lo].start = temp[lo].start;
        array[lo].end = temp[lo].end;
    }

}

void merge_sort(int lo, int hi)
{
    int mid = 0;  //For tracking the middle of the array

    //Base case: Check if lo is equal to hi and return.
    if (lo == hi)
        return;

    mid = (hi + lo) / 2;

    merge_sort(lo, mid);     //Traverse left
    merge_sort(mid + 1, hi); //Traverse right
    merge(lo, mid, hi);      //Sort and merge the current passed in data
}

void init_graph()
{
    int value = 0;

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            printf("Enter table: ");
            scanf("%d", &value);
            graph[i][j] = value;
        }
    }
}


void init_array()
{
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (graph[i][j] > 0 && j > i) {
                array[length].edge = graph[i][j];
                array[length].start = i;
                array[length].end = j;
                ++length;
            }
        }
    }
    merge_sort(0, length - 1);
}


void print_graph()
{
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            printf("[ %d ] ", graph[i][j]);
        }
        printf("\n");
    }
}


void create_mst()
{
    int len = length;
    int tree_num = 1;
    length = 0;

    for (int i = 0; i < size; ++i) {
        table[i] = 0;
    }
    for (int i = 0; i < len; ++i) {
        int start = array[i].start;
        int end = array[i].end;

        if (table[start] == 0 && table[end] == 0) {
            table[start] = tree_num;
            table[end] = tree_num;

            mst[length].edge = array[i].edge;
            mst[length].start = start;
            mst[length].end = end;
            ++length;
            ++tree_num;
        }
        else if (table[start] < table[end]) {
            if (table[start] == 0) {
                tree_num = table[end];
                table[start] = tree_num;
            }
            else {
                int hold = table[end];
                tree_num = table[start];
                for (int j = 0; j < size; ++j) {
                    if (table[j] == hold) {
                        table[j] = tree_num;
                    }
                }
            }
            mst[length].edge = array[i].edge;
            mst[length].start = start;
            mst[length].end = end;
            ++length;
        }
        else if (table[start] > table[end]) {
            if (table[end] == 0) {
                tree_num = table[start];
            }
            else {
                int hold = table[start];
                tree_num = table[end];
                for (int j = 0; j < size; ++j) {
                    if (table[j] == hold) {
                        table[j] = tree_num;
                    }
                }
            }
            mst[length].edge = array[i].edge;
            mst[length].start = start;
            mst[length].end = end;
            ++length;
        }
    }
}


void print_array()
{
    for (int i = 0; i < length; ++i) {
        printf("Start: %d  End: %d  Weight: %d\n", array[i].start, array[i].end, array[i].edge);
    }

}

void print_mst()
{
    for (int i = 0; i < length; ++i) {
        printf("Start: %d  End: %d  Weight: %d\n", mst[i].start, mst[i].end, mst[i].edge);
    }

}

int main()
{
    init_graph();
    print_graph();
    init_array();
    print_array();
    create_mst();
    printf("\n");
    print_mst();
    return 0;
}
