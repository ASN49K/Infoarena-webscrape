#include<bits/stdc++.h>
#define nl '\n'
using namespace std;
const string file="cmlsc";
ifstream f(file+".in");
ofstream g(file+".out");
//#define f cin
//#define g cout
const int DD=1033;
int n,m,dp[DD][DD];
int a[DD],b[DD];
int main(){
    f>>n>>m;
    for (int i=1; i<=n; ++i) f>>a[i];
    for (int i=1; i<=m; ++i) f>>b[i];
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=m; ++j) {
            if (a[i]==b[j]) {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    g<<dp[n][m]<<nl;
    vector<int>r;
    for (int i=n,j=m; i;){
        if (a[i]==b[j]) r.push_back(a[i]),--i,--j;
        else if (dp[i-1][j]<dp[i][j-1]) --j;
        else --i;
    }
    reverse(r.begin(),r.end());
    for (auto e:r) g<<e<<' ';
    system("pause");
    return 0;
}