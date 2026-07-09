#include <bits/stdc++.h>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m;
int A[1025];
int B[1025];
int dp[1025][1025];
vector<int>R;
int main()
{
    fin>>n>>m;
    for(int i=1; i<=n; i++)
        fin>>A[i];
    for(int i=1; i<=m; i++)
        fin>>B[i];
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(A[i]==B[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
    fout<<dp[n][m]<<'\n';
    int x=n,y=m;
    while(!(x==1 && y==1))
    {
        if(A[x]==B[y])
            R.push_back(A[x]);
        if(x==1)
            y--;
        else if(y==1)
            x--;
        else if(dp[x-1][y]>=dp[x][y-1])
            x--;
        else
            y--;
    }
    for(int i=R.size()-1;i>=0;i--)
        fout<<R[i]<<" ";
    return 0;
}
