#include <iostream>

using namespace std;
const int maxn = 1030;
int A[maxn], B[maxn], Ans[maxn], Dp[maxn][maxn], lg;
int main() {
    int n,m,i,j;
    cin>>n>>m;
    for(i=1;i<=n;i++) {
        cin>>A[i];
    }
    for(i=1;i<=m;i++) {
        cin>>B[i];
    }
    for (i=1;i<=n;i++) {
        for (j = 1; j <= m; j++) {
            if (A[i] == B[j]) {
                Dp[i][j] = Dp[i - 1][j - 1] + 1;
            } else {
                Dp[i][j] = max(Dp[i - 1][j], Dp[i][j - 1]);
            }
        }
    }
    i = n, j = m;
    while (i && j) {
        if (A[i] == B[j]) {
            Ans[++lg] = A[i];
            i--;
            j--;
        } else if (Dp[i - 1][j] > Dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    cout << lg << "\n";
    for (i = lg; i; i--) {
        cout << Ans[i] << " ";
    }
    return 0;

}
