#include<cstdio>
#define MAX_LEN 1024
using namespace std;

int x[MAX_LEN + 1], y[MAX_LEN + 1], dp[MAX_LEN + 1][MAX_LEN + 1], n, m;
int v[MAX_LEN], k;

inline int maxim(int x, int y)
{
    if(x > y) return x;
    return y;
}

int main()
{
    int i, j;
    FILE *fin, *fout;
    fin = fopen("cmlsc.in","r");
    fout = fopen("cmlsc.out","w");
    fscanf(fin,"%d%d",&n,&m);
    for(i=1; i<=n; i++)
        fscanf(fin,"%d",&x[i]);
    for(i=1; i<=m; i++)
        fscanf(fin,"%d",&y[i]);

    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            if(x[i] == y[j])
                dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = maxim(dp[i][j-1],dp[i-1][j]);
    fprintf(fout,"%d\n",dp[n][m]);
    i = n; j = m;
    while(dp[i][j])
    {
        if(x[i] == y[j])
        {
            v[k++] = x[i];
            i--;
            j--;
        }
        else if(dp[i][j] == dp[i-1][j])
            i--;
        else j--;
    }
    for(i=k-1; i>=0; i--)
        fprintf(fout,"%d ",v[i]);
    fprintf(fout,"\n");
    fclose(fin);
    fclose(fout);
    return 0;
}
