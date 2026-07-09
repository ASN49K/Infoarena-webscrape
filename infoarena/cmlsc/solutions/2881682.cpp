#include <bits/stdc++.h>
using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

const int MAXN=1050;

int n,m,a[MAXN],b[MAXN];
int dp[MAXN][MAXN];
int rez1,rez[MAXN],k;

int main()
{
    fin >>n>>m;
    for (int i=1;i<=n;++i)
        fin >>a[i];
    for (int i=1;i<=m;++i)
        fin >>b[i];
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            if (a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max ({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]+(a[i]==b[j])});
            rez1=max (dp[i][j],rez1);
        }
    }

    for (int i=n,j=m;i,j;){
        if (a[i]==b[j]){
            rez[++k]=a[i]; i--; j--;
        }
        else{
            if (dp[i-1][j]>dp[i][j-1]) i--;
            else j--;
        }
    }
    fout <<rez1<<'\n';
    for (int i=k;i>=1;--i)
        fout <<rez[i]<<' ';
    return 0;
}
