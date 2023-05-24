// gcc -Wall -g -o ra ra.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF 1024

int
main(void)
{
    char **ragged_array = NULL;
    int nelm = 0;
    FILE *iFile = stdin;
    char buffer[MAX_BUF] = {'\0'};

//# define BORING
#define COOL
#ifdef COOL
    for ( ; fgets(buffer, MAX_BUF, iFile) != NULL
            ; ragged_array = realloc(ragged_array, (nelm + 1) * sizeof (char *))
            , ragged_array[nelm++] = strdup(buffer));
#else // ! COOL
    char *bptr = fgets(buffer, MAX_BUF, iFile);
    while (bptr != NULL) {
# ifdef BORING
        char **tmpArr = malloc ((nelm + 1) * sizeof(char *));

        for (int i = 0; i < nelm; i++) {
            tmpArr[i] = ragged_array[i];
        }
        free(ragged_array);
        ragged_array = tmpArr;

        ragged_array[nelm] = malloc((strlen(buffer) + 1) * sizeof(char));
        strcpy(ragged_array[nelm], buffer);
        nelm++;
# else // BORING
        ragged_array = realloc(ragged_array, (nelm + 1) * sizeof(char *)); //This line does the work of lines 21-27 
        ragged_array[nelm++] = strdup[buffer]; //This line does the work of lines 29-31
# endif // BORING
        bptr = fgets(buffer, MAX_BUF, iFile);
    }
#endif // COOL

    for (int celm = 0; celm < nelm; celm++) {
        printf("%3d: %s", (celm + 1), ragged_array[celm]);
    }
    for (int celm = 0; celm < nelm; celm++) {
        free(ragged_array[celm]);
        ragged_array[celm] = NULL;
    }
    free(ragged_array);
    ragged_array = NULL;

    return EXIT_SUCCESS;
}

