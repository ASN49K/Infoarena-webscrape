#include <fstream>
#include <vector>
#define maxn 1025

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int dp[maxn][maxn];

int main() {
    vector<int> A, B, sol;
    int m, n, x, best, i, j;

    in>>m>>n;
    for(int i = 0; i < m; i++) {
        in>>x;
        A.push_back(x);
    }

    for(int i = 0; i < n; i++) {
        in>>x;
        B.push_back(x);
    }

    for(int i = 1; i <= m;i++)
        for(int j = 1; j <= n; j++) {
            if(A[i-1] == B[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }

    best = dp[m][n];
    out<<best<<"\n";
    if(!best)
     return 0;
    while(true) {
        if(A[m-1] == B[n-1]) {
            sol.push_back(A[m - 1]);
            if(sol.size() == best)
                break;
            m--;
            n--;
        }
        else if(dp[m-1][n] > dp[m][n-1]) m--;
        else n--;
    }

    reverse(sol.begin(), sol.end());
    for(int i = 0 ;i < sol.size(); i++)
        out<<sol[i]<<" ";
}