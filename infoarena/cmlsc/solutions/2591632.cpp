#include <stdio.h>
#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)
#define REP(i,a,b) for(int i = a; i < b; i++)

using namespace std;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;
const int Nmax = 1024;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

int R[Nmax][Nmax], A[Nmax], B[Nmax], P[Nmax];

int dp(int m, int n) {
  if (m < 0 || n < 0) { return 0; }
  if (R[m][n] != -1) { return R[m][n]; }

  if(A[m] == B[n]) {
    R[m][n] = dp(m-1, n-1) + 1;
  } else {
    R[m][n] = max(dp(m, n-1), dp(m-1, n));
  }
  return R[m][n];
}

int main(void) {
  int M,N;
  fin >> M >> N;
  rep(i,M) { fin >> A[i]; }
  rep(i,N) { fin >> B[i]; }
  memset(R, -1, sizeof(R));

  int result = dp(M-1, N-1);
  fout << result << '\n';

  int k = result, m = M-1, n = N-1;
  while(k > 0) {
    if (A[m] == B[n]) {
      P[--k] = A[m];
      m--;
      n--;
    } else if (m > 0 && k == R[m-1][n]) {
      m--;
    } else if (n > 0 && k == R[m][n-1]) {
      n--;
    }
  }
  rep(i,result) { fout << P[i] << ' '; }
  cout << endl;

  return 0;
}
