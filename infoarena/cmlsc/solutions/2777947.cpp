#include<iostream>
#include<fstream>
#include<cstring>
#include<bits/stdc++.h>
#include<iomanip>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    fin>>n>>m;
    vector<int>a;
    vector<int>b;
    int x;

    int i,j;
    for(i=1;i<=n;i++)
    {
        fin>>x;
        a.push_back(x);
    }

    for( i=1;i<=m;i++)
    {
        fin>>x;
        b.push_back(x);
    }

    int dp[1025][1025];

    for(i=0;i<=n;i++)
        dp[i][0] = 0;

    for(j=0;j<=m;j++)
        dp[0][j] = 0;

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
            if(a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }    

    fout<<dp[n][m]<<'\n';

    vector<int>res;
    for(i=n,j=m;i;)
    {
        if(a[i-1] == b[j-1])
        {
            res.push_back(a[i-1]);
            i--;
            j--;
        }
        else if(dp[i-1][j] < dp[i][j-1])
            j--;
        else i--;
    }

    for(i=res.size()-1;i>=0;i--)
        fout<<res[i]<<" ";
    
    fin.close();
    fout.close();
    return 0;
}
