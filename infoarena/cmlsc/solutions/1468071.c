#include <stdio.h>
#include <stdlib.h>
int s[1030][1030];
FILE *out;
void read(int *n, int *m, int *x, int *y)
{
    FILE *in = fopen("cmlsc.in", "r");
    fscanf(in, "%d %d", n,m);
    int i;
    for(i = 1; i <= *n; i++)
        fscanf(in, "%d", x+i);
    for(i = 1; i <= *m; i++)
        fscanf(in, "%d", y+i);
}
void print_lcs(int *x, int i, int j)
{
    if(i == 0 || j == 0)
        return;
    if((s[i-1][j] == s[i-1][j-1])&&(s[i-1][j] == s[i][j-1])&&(s[i][j] == s[i-1][j-1]+1))
    {
        print_lcs(x,i-1,j-1);
        fprintf(out, "%d ", x[i]);
    }
    else if(s[i-1][j]>=s[i][j-1])
        print_lcs(x,i-1,j);
    else
        print_lcs(x,i,j-1);
}
int main()
{
    out = fopen("cmlsc.out","w");
    int n, m, x[1030], y[1030];

    read(&n, &m, x,y);
    int i;
    for(i = 0; i <= n; i++)
        s[i][0] = 0;
    for(i = 0; i <= m; i++)
        s[0][i] = 0;
    int j;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
    {
        if(x[i] == y[j])
            s[i][j] = s[i-1][j-1] + 1;
        else if(s[i-1][j] >= s[i][j-1])
            s[i][j] = s[i-1][j];
        else
            s[i][j] = s[i][j-1];
    }
    fprintf(out, "%d\n", s[n][m]);
    print_lcs(x,n,m);
    return 0;
}
