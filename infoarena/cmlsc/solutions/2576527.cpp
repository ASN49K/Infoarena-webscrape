#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,i,a[1030],b[1030],dp[1030][1030],j,viz1[1030],viz2[1030],k,sol[1030];
void drum(int i, int j)
{
    if(i!=0&&j!=0)
    {
        if(a[i]==b[j]&&viz1[i]==0&&viz2[j]==0)
        {
            k++;
            sol[k]=a[i];
            viz1[i]=1;
            viz2[j]=1;
            drum(i-1,j-1);

        }
        else
        {
            if(dp[i][j-1]>dp[i-1][j])
            {
                drum(i,j-1);
            }
            else
            {
                if(dp[i][j-1]<dp[i-1][j])
                {
                   drum(i-1,j);
                }
                else
                {
                    drum(i,j-1);
                    drum(i-1,j);
                }
            }

        }

    }
}
int main()
{
    fin>>n>>m;
    for(i=1;i<=n;i++)
    {
        fin>>a[i];
    }
    for(i=1;i<=m;i++)
    {
        fin>>b[i];
    }
    for(i=1;i<=n;i++)
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
    fout<<dp[n][m]<<'\n';
    drum(n,m);
    for(i=dp[n][m];i>0;i--)
    {
        fout<<sol[i]<<" ";
    }
    return 0;
}
