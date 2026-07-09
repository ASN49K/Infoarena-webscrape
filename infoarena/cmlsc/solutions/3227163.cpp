#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define NMAX 1030
#define MOD 1000005
using namespace std;
int v1[NMAX];
int v2[NMAX];
int dp[NMAX][NMAX];
vector<int>ans;
int main()
{
    ifstream cin("cmlsc.in");
    ofstream cout("cmlsc.out");
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>v1[i];
    for(int i=1;i<=m;i++)
        cin>>v2[i];
    for(int i=1;i<=n;i++)
    {
        dp[i][1]=0;
        if(v2[1]==v1[i])
        {
            for(int j=i;j<=n;j++)
                dp[j][1]=1;
            break;
        }
    }
    for(int i=1;i<=m;i++)
    {
        dp[1][i]=0;
        if(v1[1]==v2[i])
        {
            for(int j=i;j<=m;j++)
                dp[1][j]=1;
            break;
        }
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=2;j<=m;j++)
        {
            if(v1[i]==v2[j])
                dp[i][j]=max(dp[i][j-1],max(dp[i-1][j],dp[i-1][j-1]+1));
            else
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        }
    }
    cout<<dp[n][m];
//    for(int i=1;i<=n;i++)
//    {
//        for(int j=1;j<=m;j++)
//        {
//            cout<<dp[i][j]<<" ";
//        }
//        cout<<'\n';
//    }
    int x=n,y=m;
    while(x!=0 && y!=0)
    {
        if(dp[x-1][y]==dp[x][y])
            x--;
        else if(dp[x][y-1]==dp[x][y])
            y--;
        else
        {
            ans.pb(v1[x]);
            x--,y--;
        }
    }
    cout<<'\n';
    reverse(ans.begin(),ans.end());
    for(int x:ans)
        cout<<x<<" ";
    return 0;
}
/*
  1 3 7 9 8
7 0 0 1 1 1
5 0 0 1 1 1
8 0 0 1 1 2

  7 5 8
1 0 1 1
3 0 1 1
7 0 1 1
9 0 1 1
8 0 1 2

0 0 0
0 0 0
0 0 0
1 1 1
1 1 2
*/
