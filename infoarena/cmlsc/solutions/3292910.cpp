#include <fstream>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int dp[1025][1025],a[1025],b[1025],c[1025];
int main() {
    int m,n;
    cin >> m >> n;
    for(int i=0;i<m;i++)
        cin >> a[i];
    for(int i=0;i<n;i++)
        cin >> b[i];
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            if(a[i-1]==b[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    cout << dp[m][n] << '\n';
    int k=dp[m][n]-1;
    int i=m,j=n;
    while(i>=1 && j>=1)
        if(a[i-1]==b[j-1])
            c[k--]=a[i-1],i--,j--;
        else if(dp[i-1][j]>dp[i][j-1])
            i--;
        else
            j--;
    for(i=0;i<dp[m][n];i++)
        cout << c[i] << ' ';
    return 0;
}