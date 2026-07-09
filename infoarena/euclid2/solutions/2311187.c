#include <stdio.h>
#include <stdlib.h>
int eu(int a, int b)
{
    int r;
    while(b>1)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    FILE *fin, *fout;
    fin=fopen("euclid2.in", "r");
    fout=fopen("euclid2.out", "w");
    int n, a, b, i, e;
    fscanf(fin, "%d", &n);
    for(i=0; i<n; i++)
    {
        fscanf(fin, "%d %d", &a, &b);
        if(a>b)
            e=eu(a, b);
        else
            e=eu(b, a);
        if(a%e==0 && b%e==0)
            fprintf(fout, "%d\n", e);
        else
            fprintf(fout, "1\n");
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
