#include <stdio.h>
int main()
{
    FILE *inputFile = fopen("nim.in", "r"), *outputFile = fopen("nim.out", "w");
    
    int n, m, i, x, sauex;
    
    fscanf(inputFile, "%d", &n);
    
    while(n--)
    {
        fscanf(inputFile, "%d", &m);
        
        sauex = 0;
        for(i = 1; i <= m; i++)
        {
            fscanf(inputFile, "%d", &x);
            sauex = sauex ^ x;
        }
        
        if(sauex) fprintf(outputFile, "DA\n");
        else fprintf(outputFile, "NU\n");
    }
    
    return 0;
}