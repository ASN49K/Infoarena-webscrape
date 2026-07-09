#include <bits/stdc++.h>

using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

int a[1111],b[1111];
int dp[1111][1111];
vector <int> v;

int main()
{
    int n,m;
    fin >> n >> m;
    int I=n,J=m;
    for (int i=1;i<=n;++i){
        fin >> a[i];
    }
    for (int i=1;i<=m;++i){
        fin >> b[i];
    }
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            if (a[i]==b[j]){
                dp[i][j] = dp[i-1][j-1]+1;
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    while (dp[I][J]>0){
        if (a[I]==b[J]){
            v.push_back(a[I]);
            I--;
            J--;
        }else if (dp[I-1][J]<dp[I][J-1]){
            J--;
        }else{
            I--;
        }
    }
    reverse(v.begin(),v.end());
    fout << dp[n][m] << '\n';
    for (auto ans:v) fout << ans << ' ';
    return 0;
}
