#include <fstream>
#include <algorithm>
using namespace std;

ifstream cin ("cmlsc.in");
ofstream cout ("cmlsc.out");

int a[1030],b[1030],dp[1030][1030],sol[1030];

int main() {
    int m,n;
    cin>>m>>n;
    for (int i=1; i<=m; ++i) {
        cin>>a[i];
    }
    for (int j=1; j<=n; ++j) {
        cin>>b[j];
    }
    for (int i=1; i<=m; ++i) {
        for (int j=1; j<=n; ++j) {
            if (a[i]==b[j]) {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout<<dp[m][n]<<"\n";
    int i=m,j=n,k=0;
    while (i>0 && j>0) {
        if (a[i]==b[j]) {
            sol[k++]=a[i];
            --i;
            --j;
        }
        else if (dp[i-1][j]>=dp[i][j-1]) {
            --i;
        }
        else {
            --j;
        }
    }
    for (int p=k-1; p>=0; --p) {
        cout<<sol[p]<<" ";
    }
    return 0;
}