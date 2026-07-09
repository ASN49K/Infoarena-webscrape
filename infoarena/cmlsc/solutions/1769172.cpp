#include <stdio.h>
#include <stdlib.h>

#define maxim(a, b)(a > b?a:b)
#define MAX 1050

int a[MAX], b[MAX], mat[MAX][MAX], sir[MAX];

int main()  {
FILE *fin = fopen("cmlsc.in", "r");
FILE *fout = fopen("cmlsc.out", "w");
int m, n, max = 0;
fscanf(fin, "%d%d", &m, &n);
int i, j;
for(i = 1;i <= m;i++)
    fscanf(fin, "%d", &a[i]);
for(i = 1;i <= n;i++)
    fscanf(fin, "%d", &b[i]);
for(i = 1;i <= m;i++)
    for(j = 1;j <= n;j++)  {
        if(a[i] == b[j])
            mat[i][j] = mat[i - 1][j - 1] + 1;
        else
            mat[i][j] = maxim(mat[i - 1][j] , mat[i][j - 1]);
    }
for(i = m, j = n;i;)  {
    if(a[i] == b[j])  {
        sir[++max] = a[i];
        i--;
        j--;
    }
    else if(mat[i - 1][j] < mat[i][j - 1])  {
        j--;
    }
    else i--;
    }
    fprintf(fout, "%d\n", max);
    for(i = max;i > 0;i--)
        fprintf(fout, "%d ", sir[i]);
fclose(fin);
fclose(fout);
return 0;
}
