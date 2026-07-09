#include <bits/stdc++.h>
using namespace std;

#define ll long long

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int dp[1030][1030];
int n, m;
vector<int> a(n+1);
vector<int> b(m+1);

void dfs_reverse(int i, int j,int m){
    if(i<1 || j<1)
        return ;

    if(a[i]==b[j]){
        dfs_reverse(i-1,j-1,m);
        fout<<a[i]<<" ";
    }else{
        if(j==1 && i!=1)
            dfs_reverse(i-1,m,m);
        else
            dfs_reverse(i,j-1,m);
    }
}

int main()
{
	ios::sync_with_stdio(false);
	fin.tie(nullptr);

    fin>>n>>m;

    for(int i=1;i<=n;i++)
        fin>>a[i];

    for(int i=1;i<=m;i++)
        fin>>b[i];

    dp[0][0]=dp[1][0]=dp[0][1]=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
    }
    fout<<dp[n][m]<<endl;
/**
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
        }
**/
    dfs_reverse(n,m,m);

    return 0;
}
