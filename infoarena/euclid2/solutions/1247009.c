#include <stdio.h>
#include <stdlib.h>

#define PAIRS 100000

int main()
{
    FILE *inputFile = fopen("euclid2.in", "r");
    FILE *outputFile = fopen("euclid2.out","w");

    int pairs;
    int num1, num2, saver;
    fscanf(inputFile, "%d", &pairs);

    while(pairs--) {
        fscanf(inputFile, "%d %d", &num1, &num2);
        while(num2 != 0) {
            saver = num2;
            num2 = num1 % num2;
            num1 = saver;
        }
        fprintf(outputFile, "%d\n", num1);
    }

    fclose(inputFile);
    fclose(outputFile);


    return 0;
}
