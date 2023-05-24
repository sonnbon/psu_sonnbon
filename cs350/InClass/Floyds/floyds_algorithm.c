#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// James Connor Baron-Williams
// Implement Kruskall's Minimum Spanning Tree

#define M 1000

int graph[M][M];
int size = 9;


void init_graph()
{
    FILE *fin;

    fin = fopen("graph.txt", "r");

    if (!fin)
        return;

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            fscanf(fin, "%d", &graph[i][j]);
        }
    }
    fclose(fin);
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


void shortest_paths()
{
    for (int k = 0; k < size; ++k) {
        for (int row = 0; row < size; ++row) {
            for (int col = 0; col < size; ++col) {
                if (graph[row][col] != 0 && graph[row][k] != -1 && graph[k][col] != -1) {
                    int new_dist = graph[row][k] + graph[k][col];
                    if (graph[row][col] > new_dist || graph[row][col] == -1) {
                        graph[row][col] = new_dist;
                    }
                }
            }
        }
        printf("\n\nk = %d:\n\n", k + 1);
        print_graph();
    }
}


int main()
{
    init_graph();
    print_graph();
    shortest_paths();
    return 0;
}
