#include <bits/stdc++.h>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, dp[1025][1025], a[1025], b[1025];

int main(){
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>a[i];
    for(int i=1;i<=m;i++)
        fin>>b[i];

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            if(a[i]==b[j])
                dp[i][j]=max(dp[i][j], dp[i-1][j-1]+1);
            //cout<<dp[i][j]<<' ';
        }
        //cout<<endl;
    }

    fout<<dp[n][m]<<'\n';
    int l=dp[n][m], i=n, j=m;
    int ans[l];
    while(l){
        int ok=1;
        while(ok){
            ok=0;
            if(dp[i-1][j]==dp[i][j]){
                i--;
                ok=1;
            }
            if(dp[i][j-1]==dp[i][j]){
                j--;
                ok=1;
            }
        }

        ans[l]=a[i];
        i--;
        j--;
        //cout<<i<<' '<<j<<' '<<a[i]<<endl;
        l--;
    }

    for(int i=1;i<=dp[n][m];i++)
        fout<<ans[i]<<' ';
    return 0;
}
