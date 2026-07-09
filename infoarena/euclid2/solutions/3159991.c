#include <stdio.h>
#include <stdlib.h>
int cmmdc(int a, int b)
{
    int r;
    while (b > 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main()
{
    FILE *input = fopen("euclid2.in", "r");
    FILE *output = fopen("euclid2.out", "w");
    int n, a, b, r;
    fscanf(input, "%d", &n);
    for (int i = 1; i <= n; i++)
    {
        fscanf(input, "%d%d", &a, &b);
        int rez = cmmdc(a, b);
        fprintf(output, "%d\n", rez);
    }
    fclose(input);
    fclose(output);
    return 0;
}