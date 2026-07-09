#include <fstream>
#include <vector>
using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int n,m;
int a[1025],b[1025];
int dp[1025][1025];
vector<int> ans;
int main()
{
    in>>m>>n;
    for(int i=1; i<=m; i++)
        in>>a[i];
    for(int j=1; j<=n; j++)
        in>>b[j];

    for(int i=1; i<=m; i++)
        for(int j=1; j<=n; j++)
        {
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }

    out<<dp[m][n]<<'\n';

    int i=m,j=n;
    while(i && j)
    {
        if(a[i]==b[j])
        {
            ans.push_back(a[i]);
            i--; j--;
        }
        else
        {
            if(dp[i][j]==dp[i-1][j]) i--;
            else j--;
        }
    }

    for(int i=ans.size()-1; i>=0; i--)
        out<<ans[i]<<' ';

    return 0;
}
