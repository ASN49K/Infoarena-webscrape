#include<stdio.h>
#include<stdlib.h>

int t[1025][1025];

int max3(int a, int b, int c)
{
    if (a < b)
        a = b;
    if (a < c)
        a = c;
    return a;
}

int main()
{
    int m, n;
    int a[1025], b[1025];


    FILE* fi = fopen("cmlsc.in", "r");
    FILE* fo = fopen("cmlsc.out", "w");

    int i, j, k;
    int rez[1025];

    fscanf(fi,"%d%d", &m, &n);
    for(i = 1; i <= m; i++)
        fscanf(fi, "%d", &a[i]);

    for(i = 1; i <= n; i++)
        fscanf(fi, "%d", &b[i]);

    for(i = 0; i <= m; i++)
        t[i][0] = 0;
    for(i = 1; i <= n; i++)
        t[0][n] = 0;



    for(i = 1; i <= m; i++)
    {
        for(j = 1; j <= m; j++)
        {
            if (a[i] == b[j])
                k = 1;
            else
                k = 0;
            t[i][j] = max3(t[i - 1][j], t[i][j - 1], t[i - 1][j - 1] + k);
        }
    }

    fprintf(fo, "%d\n", t[m][n]);

    i = m;
    j = n;
    k = 0;

    while (j > 0 && i > 0) {
        if (a[i] == b[j]) {
            rez[k++] = a[i--];
            j--;
        } else {
            if (t[i - 1][j] > t[i][j - 1])
                i--;
            else
                j--;
        }
    }

    while (k > 0)
        fprintf(fo, "%d ", rez[--k]);

    close(fi);
    close(fo);

    return 0;
}
