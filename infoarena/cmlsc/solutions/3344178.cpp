#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    FILE *f=fopen("cmlsc.in","r");
    FILE *g=fopen("cmlsc.out","w");
    int n,m,i,j,dp[101][101]={0},a[101],b[101];
    vector <int> sol;
    fscanf(f,"%d%d",&n,&m);
    for(i=1;i<=n;i++)
        fscanf(f,"%d",&a[i]);
    for(i=1;i<=m;i++)
        fscanf(f,"%d",&b[i]);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    fprintf(g,"%d\n",dp[n][m]);
    i=n,j=m;
    while(i>0 && j>0)
        if(a[i]==b[j])
        {
            sol.push_back(a[i]);
            i--;
            j--;
        }
        else if(dp[i-1][j]>=dp[i][j-1])
            i--;
        else
            j--;
    for(i=sol.size()-1;i>=0;i--)
        fprintf(g,"%d ",sol[i]);
}