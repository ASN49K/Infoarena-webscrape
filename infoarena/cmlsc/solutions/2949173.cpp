#include <iostream>
#include <vector>

#define MaxN 1026

using namespace std;

int dp[MaxN][MaxN], M, N;
int A[MaxN], B[MaxN];

int LCS(int i, int j) {
    if(i > M || j > N) {
        return 0;
    }
    if(dp[i][j] == -1) {
        if(A[i] == B[j]) {
            dp[i][j] = 1 + LCS(i + 1, j + 1);
            return dp[i][j];
        } else {
            dp[i][j] = max(LCS(i + 1, j), LCS(i, j + 1));
            return dp[i][j];
        }
    } else {
        return dp[i][j];
    }
}

vector<int> res;

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    cin >> M >> N;
    /* FOR Memoisation method
    for(int i = 1; i <= M; i++) {
        for(int j = 1; j <= N; j++) {
            dp[i][j] = -1;
        }
    }
    */

    for(int i = 1; i <= M; i++) {
        cin >> A[i];
    }

    for(int i = 1; i <= N; i++) {
        cin >> B[i];
    }

    for(int i = 1; i <= M; i++) {
        for(int j = 1; j <= N; j++) {
            if(A[i] == B[j]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
          //  cout << dp[i][j] << " ";
        }
        //cout << endl;
    }

    cout << dp[M][N] << endl;

    int i = M, j = N;
    while(i != 0 && j != 0) {
        if(A[i] == B[j]) {
            res.push_back(A[i]);
            i--;
            j--;
        } else {
            if(dp[i][j - 1] > dp[i - 1][j]) {
                j = j - 1;
            } else {
                i = i - 1;
            }
        }
    }

    for(auto it = res.rbegin(); it != res.rend(); ++it) {
        cout << *it << " ";
    }

    return 0;
}
