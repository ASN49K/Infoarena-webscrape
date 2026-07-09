#include <iostream>
#include <cstdio>

using namespace std;

#define DIM 1030

int A[DIM], B[DIM];
int st[DIM], dp[DIM][DIM];

int main() {
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);

    int N, M;

    scanf("%d %d\n", &N, &M);

    for(int i = 1; i <= N; ++i) {
        scanf("%d", &A[i]);
    }

    for(int i = 1; i <= M; ++i) {
        scanf("%d", &B[i]);
    }

    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= M; ++j) {
            if(A[i] == B[j]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int i = N, j = M;

    while(i > 0 && j > 0) {
        if(A[i] == B[j]) {
            st[++st[0]] = A[i];
            --i, --j;
        }
        else {
            if(dp[i - 1][j] > dp[i][j - 1]) {
                --i;
            }
            else {
                --j;
            }
        }
    }

    cout << st[0] << '\n';
    while(st[0]) {
        cout << st[st[0]--] << ' ';
    }

    return 0;
}
