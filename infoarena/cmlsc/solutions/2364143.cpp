#include <bits/stdc++.h>

const int MV = (1 << 10) + 5 ;

int A[MV] ;
int B[MV] ;
int dp[MV][MV] ;
int n, m ;
std::vector<int> sol ;

void cmlsc() {
  int i, j ;
  for (i = 1 ; i <= n ; ++ i) {
    for (j = 1 ; j <= m ; ++ j) {
      if (A[i] == B[j])
        dp[i][j] = dp[i - 1][j - 1] + 1 ;
      else dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]) ;
    }
  }
}

void get_substr() {
  int i(n), j(m) ;
  while (i && j) {
    if (A[i] == B[j]) {
      sol.push_back(A[i]), i --, j -- ;
    } else (dp[i - 1][j] < dp[i][j - 1]) ? -- j : -- i ;
  }
}

int main() {
  freopen("cmlsc.in", "r", stdin) ;
  freopen("cmlsc.out", "w", stdout) ;
  scanf("%d %d", &n, &m) ;
  int i ;
  for (i = 1 ; i <= n ; ++ i) {
    scanf("%d", A + i) ;
  }
  for (i = 1 ; i <= m ; ++ i) {
    scanf("%d", B + i) ;
  }
  cmlsc() ;
  printf("%d\n", dp[n][m]) ;
  get_substr() ;
  reverse(begin(sol), end(sol)) ;
  for (auto it : sol) {
    printf("%d ", it) ;
  }
  return 0 ; }
