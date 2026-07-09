#include <fstream>
#include <vector>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n,m;
vector<short> a(1025),b(1025),v;
vector<vector<int>> dp(1025,vector<int>(1025));

void reconstrunct(int i,int j) {
    if(i==0 || j==0)
        return;
    if(a[i]==b[j]) {
        v.push_back(a[i]);
        reconstrunct(i-1,j-1);
    } else if (dp[i-1][j] < dp[i][j-1])
        reconstrunct(i,j-1);
    else
        reconstrunct(i-1,j);
}

int main() {

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

    reconstrunct(n,m);

    fout<<dp[n][m]<<'\n';
    for (auto it=rbegin(v); it!=rend(v); it++)
        fout<<*it<<' ';

    return 0;
}
