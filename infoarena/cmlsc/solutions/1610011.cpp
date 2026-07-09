#include <fstream>
#include <vector>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
#define MAXN 1025

vector<int> sir;
int dp[MAXN][MAXN],a[MAXN],b[MAXN];
int n,m,i,j;

int main()
{
    cin>>n>>m;
    for(i=1; i<=n; i++)
        cin>>a[i];
    for(i=1; i<=m; i++)
        cin>>b[i];

    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);


    cout<<dp[n][m]<<"\n";
    i=n; j=m;
    while(i>=1 && j>=1)
    {
        if(a[i] == b[j])
        {
            sir.push_back(a[i]);
            i--; j--;
        }
        else
            if(dp[i-1][j] > dp[i][j-1])
                i--;
            else
                j--;
    }
    for(i=0; i<sir.size(); i++)
        cout<<sir[i]<<" ";
    cout<<"\n";
    return 0;
}
