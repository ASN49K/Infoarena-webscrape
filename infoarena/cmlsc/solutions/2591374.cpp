#include <stdio.h>
#define N 0x401
#define max(a, b) a>b?a:b
int a[N][N];
int main () {
    FILE *fin=fopen ("cmlsc.in", "r"),
         *fout=fopen ("cmlsc.out", "w");
    int n, m, i, j, v[N], w[N], ans[N], k=0;
    fscanf (fin, "%d%d", &n, &m);
    for (i=1; i<=n; i++)
        fscanf (fin, "%d", v+i);
    for (j=1; j<=m; j++)
        fscanf (fin, "%d", w+j);
    for (i=1; i<=n; i++)
        for (j=1; j<=m; j++)
            if (v[i]==w[j])
                a[i][j]=a[i-1][j-1]+1;
            else
                a[i][j]=max(a[i-1][j], a[i][j-1]);
    fprintf (fout, "%d\n", a[n][m]);
    for (i=n, j=m; i;)
        if (v[i]==w[j])
            ans[++k]=v[i],
            i--,
            j--;
        else
            a[i-1][j]<a[i][j-1]?j--:i--;
    for (; k; k--)
        fprintf (fout, "%d ", ans[k]);
    return 0;
}
