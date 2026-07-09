#include <bits/stdc++.h>
#define INF 0x3f3f3f3f  // INF mare pentru long long
#define mod 666013
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n,m,a[2001],b[2001],dp[2001][2001],sir[2001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    f>>n>>m;

    for(int i=1; i<=n; ++i)
        f>>a[i];
    for(int i=1; i<=m; ++i)
        f>>b[i];
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
            if(a[i]==b[j])
                dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    int i=n,j=m;
    int cnt=0;
    while(i>0 && j>0){
            if(a[i]==b[j])
            {
                sir[++cnt]=a[i];
                --i; --j;
            }
            else{  if (dp[i - 1][j] < dp[i][j - 1]) {
                --j;
            } else {
                --i;
            }
            }
    }
    g<<cnt<<'\n';
    for(int i=cnt; i>0; --i)
        g<<sir[i]<<' ';


    return 0;
}
