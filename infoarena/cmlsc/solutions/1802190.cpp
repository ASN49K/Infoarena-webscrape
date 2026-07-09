#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;

vector<int> A, B;
vector<vector<int> > dp(2);

int lcs(int n, int m, vector<vector<int> > dp) {
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      if(A[i] == B[j]) {
        dp[i%2][j] = dp[(i+1)%2][j-1] + 1;
      } else {
        dp[i%2][j] = max(dp[(i+1)%2][j], dp[i%2][j-1]);
      }
    }
  }
  return dp[n%2][m];
}

int main() {
  ifstream in("cmlsc.in");
  ofstream out("cmlsc.out");
  int N, M, n, m;
  in >> N >> M;
  A.push_back(0);
  B.push_back(0);
  for(int i = 0; i < N; i++) {
    in >> n;
    A.push_back(n);
  }
  for(int i = 0; i < M; i++) {
    in >> m;
    B.push_back(m);
  }
  for(int i = 0 ; i < 2; i++) {
    dp[i] = vector<int>(M+1);
  }
  out << lcs(N, M, dp);
  return 0;
}
