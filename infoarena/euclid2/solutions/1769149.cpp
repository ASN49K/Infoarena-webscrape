#include <stdio.h>

int cmmdc(int a, int b)  {
    if(b == 0)
        return a;
    return cmmdc(b, a % b);
}

int main()  {
    FILE *fin = fopen("euclid2.in", "r");
    FILE *fout = fopen("euclid2.out", "w");
    int n;
    fscanf(fin, "%d", &n);
    int i, a, b;
    for(i = 0;i < n;i++)  {
        fscanf(fin, "%d%d", &a, &b);
        fprintf(fout, "%d\n", cmmdc(a, b));
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
