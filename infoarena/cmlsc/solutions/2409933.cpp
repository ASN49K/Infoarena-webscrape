#include <fstream>
#include <algorithm>

const short int NMAX=1030;

using namespace std;

ifstream cin ("cmlsc.in");
ofstream cout ("cmlsc.out");

short int a[NMAX],b[NMAX],dp[NMAX][NMAX];

int main()
{
    int m,n;
    cin>>m>>n;
    for(int i=1; i<=m; ++i)
        cin>>a[i];
    for(int i=1; i<=n; ++i)
        cin>>b[i];
    for(int i=1; i<=m; ++i)
        for(int j=1; j<=n; ++j) {
            if(a[i]==b[j]) {
                dp[i][j]=max(dp[i-1][j],max(dp[i][j-1],dp[i-1][j-1]))+1;
            }
            else {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    cout<<dp[m][n]<<'\n';
    vector <short int> sol;
    int l=m,c=n;
    while((l>0 && c>0) && dp[l][c]>0) {
        if(dp[l][c]==dp[l-1][c])
            l--;
        else {
            if(dp[l][c]==dp[l][c-1])
                c--;
            else {
                sol.push_back(a[l]);
                l--;
                c--;
            }
        }
    }
    reverse(sol.begin(),sol.end());
    for(auto x: sol)
        cout<<x<<" ";
    cout<<'\n';
    return 0;
}
