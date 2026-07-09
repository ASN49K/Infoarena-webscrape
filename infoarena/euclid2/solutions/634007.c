#include <stdio.h>
#include <stdlib.h>

#define FILEIN "euclid2.in"
#define FILEOUT "euclid2.out" 

int gcd(int a, int b)
{
    int r;
    
    while (b) {
        r = a % b;
        a = b;
        b = r;
    }
    
    return a; 
}

int main(int argc, char* argv[])
{
    FILE *fileIn, *fileOut;
    int n, i, a, b;
    
    fileIn = fopen(FILEIN, "r");
    fileOut = fopen(FILEOUT, "w");
    if (fileIn == NULL) {
        printf("Cannot open file %s\n", FILEIN);
        exit(1);
    }
    else {
        fscanf(fileIn, "%d", &n);
        for (i = 0; i < n; i++) {
            fscanf(fileIn, "%d %d", &a, &b);
            fprintf(fileOut, "%d\n", gcd(a, b));
        }
    }
    return 0;
}
