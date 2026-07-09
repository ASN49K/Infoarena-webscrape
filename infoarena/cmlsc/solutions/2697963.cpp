#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n, m, a[1025], b[1025], sub[1025], dp[1025][1025], len;
int main() {
    f>>n>>m;
    for (int i=1; i<=n; i++){
        f>>a[i];
    }
    for (int j=1; j<=m; j++){
        f>>b[j];
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (a[i]==b[j]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    int i=n, j=m;
    while (i>=1 and j>=1) {
        if (a[i]==b[j]) {
            sub[++len]=a[i];
            i--;
            j--;
        } else if (dp[i-1][j]>dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    g<<len<<'\n';
    while (len>=1){
        g<<sub[len]<<' ';
        len--;
    }
    return 0;
}
