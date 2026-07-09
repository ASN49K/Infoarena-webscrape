#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int m,n;
int a[1030],b[1030];
int dp[1030][1030];
vector<int> ans;
int main()
{
    in>>n>>m;
    for(int i=1; i<=n; i++) in>>a[i];
    for(int i=1; i<=m; i++) in>>b[i];

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            if(a[i]==b[j]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }

    int i,j;
    for(i=n,j=m; i && j;)
    {
        if(a[i]==b[j])
        {
            ans.push_back(a[i]);
            i--; j--;
        }
        else if(dp[i-1][j]>dp[i][j-1]) i--;
        else j--;
    }

    out<<ans.size()<<'\n';
    for(int i=ans.size()-1; i>=0; i--)
        out<<ans[i]<<" ";
    return 0;
}
