#include <stdio.h>

int cmmdcRec(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return cmmdcRec(b, a % b);
    }
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
            fprintf(pFileOut, "%d\n", cmmdcRec(a, b));
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