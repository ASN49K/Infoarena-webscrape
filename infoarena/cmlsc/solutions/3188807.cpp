#include <bits/stdc++.h>

using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

int a[1111],b[1111],c[2222];
int dp[1111][1111];

int main()
{
    int n,m;
    fin >> n >> m;
    for (int i=1;i<=n;++i){
        fin >> a[i];
    }
    for (int i=1;i<=m;++i){
        fin >> b[i];
    }
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            if (a[i]==b[j]){
                dp[i][j] = max(dp[i][j],dp[i-1][j-1]+1);
            }
        }
    }
    fout << dp[n][m] << '\n';
    int I=n,J=m,x=0;
    while (I>0 and J>0){
        if (dp[I-1][J-1]+1==dp[I][J]){
            x++;
            if (I>0) c[x] = a[I];
            else c[x] = b[J];
            I--;
            J--;
        }else{
            if(dp[I][J-1]>dp[I-1][J]){
                J--;
            }else{
                I--;
            }
        }
    }
    for (int i=x;i>=1;--i){
        fout << c[i] << ' ';
    }
    return 0;
}
