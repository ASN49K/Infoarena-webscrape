#include <bits/stdc++.h>
#define MaxN 1500
using namespace std;

int dp[MaxN + 1][MaxN + 1];
int A[MaxN + 1];
int B[MaxN + 1];
int N, M;

int main(){

    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    int i, j;

    cin >> N >> M;
    for(i = 1; i <= N; i++) cin >> A[i];
    for(i = 1; i <= M; i++) cin >> B[i];
    for(i = N; i >= 1; i--)
        for(j = M; j >= 1; j--)
            if(A[i] == B[j]) dp[i][j] = 1 + dp[i + 1][j + 1];
            else dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);

    cout << dp[1][1] << '\n';
    for(i = j = 1; i <= N && j <= M; )
        if(A[i] == B[j]) { cout << A[i] << ' '; i++, j++; }
        else if(dp[i + 1][j] > dp[i][j + 1]) i++;
        else j++;



return 0;
}

