#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");
int dp[100][100];
int a[100],b[100],afis[100];
int main()
{
    int n,m;
    fin>>n>>m;
    for(int i=1;i<=n;i++) fin>>a[i];
    for(int i=1;i<=m;i++) fin>>b[i];



    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j]=max(dp[i-1][j-1],max(dp[i][j-1],dp[i-1][j]));
            }
        }
    }

    /*for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            fout<<dp[i][j]<<" ";
        fout<<"\n";
    }*/


    fout<<dp[n][m]<<"\n";
    int l=dp[n][m];
    for(int i=n,j=m; i>=1 || j>=1; )
    {
        if(a[i]==b[j])
        {
            //fout<<a[i]<<" ";
            afis[l]=a[i];
            l--;
            i--;
            j--;
        }
        else
        {
            if(dp[i-1][j]>dp[i][j-1])
                i--;
            else j--;
        }
    }

    for(int i=1;i<=dp[n][m];i++)
    {
        fout<<afis[i]<<" ";
    }


    return 0;
}
