#include <bits/stdc++.h>
using namespace std;
 
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
#define cin in
#define cout out
#define NMAX 1029

int M, N, A[NMAX], B[NMAX], dp[NMAX][NMAX], rez[NMAX], lung_rez;

void dinamic() {
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            if (A[i] == B[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
}

void solution() {
    for (int i = M, j = N; i > 0;)
        if (A[i] == B[j]) {
            rez[++lung_rez] = A[i];
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }

    cout << lung_rez << '\n';
    for (int i = lung_rez; i > 0; i--) {
        cout << rez[i] << ' ';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> M >> N;
    for (int i = 1; i <= M; i++)
        cin >> A[i];
    for (int i = 1; i <= N; i++)
        cin >> B[i];

    dinamic();
    solution();
}