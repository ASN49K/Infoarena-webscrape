#include <stdio.h>
#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)
#define REP(i,a,b) for(int i=a;i<b;i++)

using namespace std;

const int MaxN = 1024;
int M, N, A[MaxN], B[MaxN], C[MaxN][MaxN], L[MaxN];

int dp(int m, int n) {
  if (m < 0 || n < 0) {
    return 0;
  }
  if (C[m][n] != -1) { return C[m][n]; }

  if (A[m] == B[n]) {
    C[m][n] =  dp(m-1, n-1) + 1;
    L[C[m][n]-1] = A[m];
  } else {
    C[m][n] = max(dp(m-1, n), dp(m, n-1));
  }
  return C[m][n];
}

int main(void) {
  freopen("cmlsc.in", "r", stdin);
  freopen("cmlsc.out", "w", stdout);

  cin >> M >> N;

  rep(i, M) {
    rep(j, N) {
      C[i][j] = -1;
    }
  }

  rep(i, M) { cin >> A[i]; }
  rep(i, N) { cin >> B[i]; }

  int result = dp(M-1, N-1);

  cout << result << endl;
  rep(i, result) {
    cout << L[i] << " ";
  }
  cout << endl;

  return 0;
}
