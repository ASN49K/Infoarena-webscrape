#include <fstream>
#include <vector>
using namespace std;

void reconstrunct(vector<int> a,vector<int> b,int i,int j,vector<vector<int>> dp,vector<int> &v) {
    if(i==0 || j==0)
        return;
    if(a[i]==b[j]) {
        v.push_back(a[i]);
        reconstrunct(a,b,i-1,j-1,dp,v);
    } else if (dp[i-1][j] < dp[i][j-1])
        reconstrunct(a,b,i,j-1,dp,v);
    else
        reconstrunct(a,b,i-1,j,dp,v);
}

int main() {
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");

    int n,m;
    vector<int> a(1025),b(1025),v;
    vector<vector<int>> dp(1025,vector<int>(1025));
    fin>>n>>m;
    for(int i=1; i<=n; i++)
        fin>>a[i];

    for(int i=1; i<=m; i++)
        fin>>b[i];

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

    reconstrunct(a,b,n,m,dp,v);

    fout<<dp[n][m]<<'\n';
    for (auto it=rbegin(v); it!=rend(v); it++)
        fout<<*it<<' ';

    return 0;
}
