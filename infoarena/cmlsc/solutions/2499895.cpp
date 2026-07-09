#include <iostream>
#include <fstream>

using namespace std;

ifstream in ("cmlsc.in");
ofstream out ("cmlsc.out");

int a[1026],b[1026],dp[1026],viz[1026];
int main()
{
    int n,m;
    in>>n>>m;
    for (int i=1;i<=n;i++)
        in>>a[i];
    for (int i=1;i<=m;i++)
        in>>b[i];
    int indb=0;
    for (int i=1;i<=n;i++)
    {
        int inou=-1;
        for (int j=indb+1;j<=m;j++)
            if (b[j]==a[i])
            {
                viz[j]=i;
                inou=j;
                break;
            }
        if (inou>-1)
        {
            indb=inou;
            dp[i]=dp[i-1]+1;
        }
        else
        {
            for (int j=indb-1;j>0;j--)
                if (b[j]==a[i])
                {
                    viz[j]=i;
                    inou=j;
                    break;
                }
            if (inou>-1)
            {
                for (int j=inou-1;j>0;j--)
                    if (viz[j]>0)
                        dp[i]=max(dp[i-1],dp[viz[j]]+1);
            }
            else dp[i]=dp[i-1];
        }
    }
    out<<dp[n]<<'\n';
    int x=1;
    for (int j=1;j<=m;j++)
        if (viz[j]>0 && dp[viz[j]]==x)
        {
            x++;
            out<<a[viz[j]]<<' ';
        }

    //for (int i=1;i<=n;i++)
      //  cout<<dp[i]<<' ';
    return 0;
}
