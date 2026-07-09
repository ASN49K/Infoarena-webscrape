#include <cstdio>

int cmmdc(int a, int b)
{
    if((!a) || (!b)) return a+b;
    if(a > b) return cmmdc(a%b, b);
    return cmmdc(a, b%a);
}

int main()
{
    FILE * iFile;
    FILE * oFile;

    iFile = fopen("euclid2.in", "r");
    oFile = fopen("euclid2.out", "w");

    int i, n, a, b;

    fscanf(iFile, "%d", &n);

    for(i=1;i<=n;i++)
    {
        fscanf(iFile, "%d %d", &a, &b);
        fprintf(oFile, "%d\n", cmmdc(a, b));
    }

    fclose(iFile);
    fclose(oFile);

    return 0;
}
