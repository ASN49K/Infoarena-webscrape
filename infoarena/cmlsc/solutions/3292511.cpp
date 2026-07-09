#include <bits/stdc++.h>
using namespace std;

#define ll long long

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int dp[1030][1030];

int main()
{
	ios::sync_with_stdio(false);
	fin.tie(nullptr);


    int n, m; fin>>n>>m;
    set<int> s;
    vector<int> a(n+1);
    vector<int> b(m+1);

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
/*
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
        }
*/
    int ant=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            if(j==m && i<n && dp[i][j]+1==dp[i+1][1] && dp[i+1][1]!=ant){
                    fout<<a[i+1]<<" ";
                    ant=dp[i+1][1];
            }

            else
                if(dp[i][j]+1==dp[i][j+1]&& dp[i][j+1]!=ant){
                    ant=dp[i][j+1];
                    fout<<a[i]<<" ";
                }

    }

    return 0;
}
