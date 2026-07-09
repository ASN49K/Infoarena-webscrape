#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PAIRS 100000

unsigned int gcdByDivision(unsigned int a, unsigned int b)
{
    // Be sure that `a` is the maximum value.
    unsigned int saver;

    if(b > a) {
        saver = a;
        a = b;
        b = saver;     
    }

    while(b != 0) {
        saver = b;
        b = a % b;
        a = saver;
    }

    return a;
}

void getNumberPairs(FILE *fileHandle, int values[][2])
{
    char *linePtr = NULL;
    size_t len = 0;
    ssize_t read;
    
    for(int i = 0; (read = getline(&linePtr, &len, fileHandle)) != -1; i++) {
        fscanf(fileHandle, "%d %d", &values[i][0], &values[i][1]);
    }
    free(linePtr);
}

int main()
{
    FILE *fileHandleIn = fopen("euclid2.in", "r");
    FILE *fileHandleOut = fopen("euclid2.out", "w");

    // get the number of pairs
    int pairs;
    int values[PAIRS][2]; 
    fscanf(fileHandleIn, "%d", &pairs);
   
    // get the pairs
    getNumberPairs(fileHandleIn, values);

    // test the correctness of pairs
    for(int i = 0; i < pairs; i++) {
        fprintf(fileHandleOut, "%u\n", gcdByDivision(values[i][0], 
                                                    values[i][1]));
    }
    
    fclose(fileHandleIn);
    fclose(fileHandleOut);

    return 0;
}
