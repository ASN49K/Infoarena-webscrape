#include <fstream>
#define NMAX 1025
using namespace std;

int n,m;
int A[NMAX],B[NMAX];
int dp[NMAX][NMAX];
int sol[NMAX];
ofstream o("cmlsc.out");

void cit()
{
    int i;
    FILE *in=fopen("cmlsc.in","r");
    fscanf(in,"%d%d",&n,&m);
    for(i=1;i<=n;i++)
        fscanf(in,"%d",&A[i]);
    for(i=1;i<=m;i++)
        fscanf(in,"%d",&B[i]);
    fclose(in);
}

int maxim(int a, int b)
{
    return (a>b)?a:b;
}

void pd()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(A[i]==B[j])
                dp[i][j]=dp[i][j-1]+1;
            dp[i][j]=maxim(dp[i][j],dp[i-1][j]);
            dp[i][j]=maxim(dp[i][j],dp[i][j-1]);
            if(dp[i][j]>dp[i][0])
                dp[i][0]=dp[i][j];
        }
    }
}

void afis()
{
    int i,p=n,old,nr=0;
    for(i=1;i<=m;i++)
    {
        if(dp[n][i]==dp[n][0])
        {
            nr++;
            sol[nr]=B[i];
            i=m+13;
        }
    }
    old=dp[n][0];
    for(p=n-1;p>=1;p--)
    {
        for(i=1;i<=m;i++)
        {
            if(dp[p][i]==old-1)
            {
                nr++;
                sol[nr]=B[i];
                i=m+13;
                old=dp[p][i];
            }
        }
    }
    for(i=nr;i>=1;i--)
        o<<sol[i]<<' ';
}

int main()
{
    cit();
    pd();
    o<<dp[n][0]<<'\n';
    afis();
    o.close();
    return 0;
}
