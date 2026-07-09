#include <iostream>
#include <stdio.h>
using namespace std;
FILE *f,*g;
int dp[1050][1050];
int v[1050],v2[1050],sol[1050];
int n,m,k;
void read()
{
    fscanf(f,"%d %d",&n,&m);
    for(int i=1; i<=n; i++)
        fscanf(f,"%d",&v[i]);
    for(int i=1; i<=m; i++)
        fscanf(f,"%d",&v2[i]);
}
int maxim(int a, int b)
{
    return a>b ? a:b;
}
void solve()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(v[i]==v2[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=maxim(dp[i-1][j], dp[i][j-1]);
        }
    }
    int i=n;
    int j=m;
    while(i>0 || j>0)
    {
        if(v[i]==v2[j])
            sol[++k]=v[i],i--,j--;
        else if(dp[i-1][j]>dp[i][j-1])
            i--;
        else
            j--;
    }
}
void write()
{
    fprintf(g,"%d\n",k);
    for(int i=k; i>=1; i--)
        fprintf(g,"%d ",sol[i]);
}
int main()
{
    f=fopen("cmlsc.in","r");
    g=fopen("cmlsc.out","w");
    read();
    solve();
    write();
    fclose(f);
    fclose(g);
    return 0;
}
