#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

/// dp[i][j] = cel mai lung subsir comun
///          care se obtine din primele i nr din primul sir si primele j din al doilea

int n,m,a[1026],b[1026];
int dp[1026][1026];
int main()
{
    fin>>n>>m;
    for(int i=1;i<=n;++i)
        fin>>a[i];
    for(int i=1;i<=m;++i)
        fin>>b[i];
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
    }

    fout<<dp[n][m]<<'\n';
    vector<int>rasp;
    int x=n,y=m;
    while(dp[x][y] != 0)
    {
        if(a[x]==b[y])
        {
            rasp.push_back(a[x]);
            x--;
            y--;
        }
        else
        {
            if(dp[x-1][y] > dp[x][y-1])
            {
                x--;
            }
            else
            {
                y--;
            }
        }
    }

    reverse(rasp.begin(),rasp.end());
    for(auto it : rasp)
        fout<<it<<' ';
}
