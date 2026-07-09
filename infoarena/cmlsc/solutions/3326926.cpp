#include <iostream>

using namespace std;
int m,n,a[1100],b[1100],dp[1100][1100],ras[1100],i,j,l;
void f(int x,int y)
{
    if(dp[x][y]==0)
    {
        return;
    }
    if(a[x]==b[y])
    {
        l++;
        ras[l]=a[x];
        f(x-1,y-1);
    }
    else
    {
        if(dp[x-1][y]<=dp[x][y-1])
        {
            f(x,y-1);
        }
        else
        {
            f(x-1,y);
        }
    }
}
int main()
{
    cin>>m>>n;
    for(i=1;i<=m;i++)
    {
        cin>>a[i];
    }
    for(i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(a[i]==b[j])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout<<dp[m][n]<<endl;
    f(m,n);
    for(i=l;i>=1;i--)
    {
        cout<<ras[i]<<' ';
    }
    return 0;
}
