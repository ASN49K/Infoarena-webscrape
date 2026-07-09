#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n,m,dp[1030][1030];
int s1[1030],s2[1030];
void solve(int i,int j)
{
    if(i==0 || j==0)
    {
        return;

    }
    if(s1[i]==s2[j])
    {

        solve(i-1,j-1);
        fout<<s1[i]<<" ";
    }
    else
    {
        if(dp[i-1][j]>dp[i][j-1])
            solve(i-1,j);
        solve(i,j-1);
    }
}
int main()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>s1[i];
    for(int j=1;j<=m;j++)
        fin>>s2[j];

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(s1[i]==s2[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

     fout<<dp[n][m]<<"\n";
     solve(n,m);


    return 0;
}
