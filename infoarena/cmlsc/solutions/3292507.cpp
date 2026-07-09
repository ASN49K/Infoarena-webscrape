#include <bits/stdc++.h>
using namespace std;

#define ll long long

int dp[1030][1030];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);


    int n, m; cin>>n>>m;
    set<int> s;
    vector<int> a(n+1);
    vector<int> b(m+1);

    for(int i=1;i<=n;i++)
        cin>>a[i];

    for(int i=1;i<=m;i++)
        cin>>b[i];

    dp[0][0]=dp[1][0]=dp[0][1]=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
    }
    cout<<dp[n][m]<<endl;
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
                    cout<<a[i+1]<<" ";
                    ant=dp[i+1][1];
            }

            else
                if(dp[i][j]+1==dp[i][j+1]&& dp[i][j+1]!=ant){
                    ant=dp[i][j+1];
                    cout<<a[i]<<" ";
                }

    }



    return 0;
}
