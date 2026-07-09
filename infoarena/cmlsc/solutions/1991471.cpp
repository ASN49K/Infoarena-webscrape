#include<cstdio>
#define MAX_N 1024
using namespace std;

int n, m, k, a[MAX_N], b[MAX_N], v[MAX_N], dp[MAX_N+1][MAX_N+1];

inline int maxim(int a, int b)
{
    if(a > b) return a;
    return b;
}

int main()
{
    int i, j;
    FILE *fin, *fout;
    fin = fopen("cmlsc.in","r");
    fout = fopen("cmlsc.out","w");
    fscanf(fin,"%d%d",&n,&m);
    for(i=0; i<n; i++)
        fscanf(fin,"%d",&a[i]);
    for(i=0; i<m; i++)
        fscanf(fin,"%d",&b[i]);
    fclose(fin);
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            if(a[i-1] == b[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = maxim(dp[i-1][j], dp[i][j-1]);
    i = n; j = m;
    while(dp[i][j])
    {
        if(a[i-1] == b[j-1])
        {
            v[k++] = a[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j] == dp[i][j])
            i--;
        else j--;
    }
    fprintf(fout,"%d\n",dp[n][m]);
    for(i=k-1; i>=0; i--)
        fprintf(fout,"%d ",v[i]);
    fprintf(fout,"\n");
    fclose(fout);
    return 0;
}
