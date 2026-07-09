#include <stdio.h>

int cmmdc(int a, int b)
{
    while (b != 0)
    {
        int aux = b;
        b = a % b;
        a = aux;
    }

    return a;
}

int main()
{
    FILE *pFileIn = fopen("euclid2.in", "r");
    FILE *pFileOut = fopen("euclid2.out", "w");

    if (pFileIn != NULL && pFileOut != NULL)
    {
        int n;
        fscanf(pFileIn, "%d", &n);

        for (int i = 0; i < n; i++)
        {
            int a, b;
            fscanf(pFileIn, "%d%d", &a, &b);
            fprintf(pFileOut, "%d\n", cmmdc(a, b));
        }

        fclose(pFileIn);
        fclose(pFileOut);
        return 0;
    }
    else
    {
        printf("File open error!");
        return 1;
    }
}