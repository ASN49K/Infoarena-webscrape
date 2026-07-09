#include <bits/stdc++.h>

#pragma optimize GCC ("Ofast")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

///#include <tryhardmode>
///#include <GODMODE::ON>

using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

#define cin fin
#define cout fout

const int NMAX=2e3+5;
int dp[NMAX][NMAX];
int a[NMAX];
int b[NMAX];

void rebuild(int n,int m)
{
    if(n==0 || m==0)
        return ;
    else
    {
        if(a[n]==b[m])
        {
            rebuild(n-1,m-1);
            cout<<a[n]<<" ";
        }
        else
        {
            if(dp[n-1][m]>dp[n][m-1])
                rebuild(n-1,m);
            else
                rebuild(n,m-1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m,i,j;
    cin>>n>>m;
    for(i=1;i<=n;i++)
        cin>>a[i];
    for(i=1;i<=m;i++)
        cin>>b[i];
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(a[i]==b[j])
                dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
            else
                dp[i][j]=max({dp[i][j],dp[i-1][j],dp[i][j-1]});
        }
    }
    cout<<dp[n][m]<<"\n";
    rebuild(n,m);
    cin.close();
    cout.close();
    return 0;
}
