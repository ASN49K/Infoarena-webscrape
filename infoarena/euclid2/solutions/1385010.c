#include <stdio.h>

unsigned long int euclidAlgorithm(unsigned long int a, unsigned long int b);

int main()
{
    FILE* inputStream;
    FILE* outputStream;

    unsigned long int numberOfPairs;
    unsigned long int a, b;

    inputStream = fopen("euclid2.in", "r");
    outputStream = fopen("euclid2.out", "w");

    fscanf(inputStream, "%lu", &numberOfPairs);

    for (unsigned long int index = 0; index < numberOfPairs; index++)
    {
        fscanf(inputStream, "%lu", &a);
        fscanf(inputStream, "%lu", &b);

        fprintf(outputStream, "%lu\n", euclidAlgorithm(a, b));
    }

    fclose(inputStream);
    fclose(outputStream);
}

unsigned long int euclidAlgorithm(unsigned long int a, unsigned long int b)
{
    while (b > 0)
    {
        unsigned long int c = a % b;
        a = b;
        b = c;
    }

    return a;
}
