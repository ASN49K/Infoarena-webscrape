
/// dp[i][j] = solutia pt primele i din primul sir si primele j din al doilea sir
/// dp[i][j] = dc a[i] == b[j] atunci max(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] + 1) altfel max(
/// m[i][j] = 1, 2, 3

#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;

const int maxN = 1024;
int dp[maxN + 2][maxN + 2], m[maxN + 2][maxN + 2];
int A[maxN + 1], B[maxN + 1];
int N, M;

int main() {
  freopen("cmlsc.in", "r", stdin);
  freopen("cmlsc.out", "w", stdout);
  scanf("%d %d", &N, &M);
  for(register int i = 1; i <= N; ++ i)
    scanf("%d", &A[i]);
  for(register int i = 1; i <= M; ++ i)
    scanf("%d", &B[i]);
  for(register int i = 1; i <= N; ++ i) {
    for(register int j = 1; j <= M; ++ j) {
      if(A[i] == B[j]) {
        m[i][j] = 1;
        dp[i][j] = dp[i - 1][j];
        if(dp[i][j] < dp[i][j - 1]) {
          dp[i][j] = dp[i][j - 1];
          m[i][j] = 2;
        }
        if(dp[i][j] < dp[i - 1][j - 1] + 1) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
          m[i][j] = 3;
        }
      } else {
        m[i][j] = 1;
        dp[i][j] = dp[i - 1][j];
        if(dp[i][j] < dp[i][j - 1]) {
          dp[i][j] = dp[i][j - 1];
          m[i][j] = 2;
        }
      }
    }
  }

  int x = N, y = M;
  printf("%d\n", dp[N][M]);
  stack<int> st;
  while(x and y) {
    switch(m[x][y]) {
      case 1: -- x; break;
      case 2: -- y; break;
      case 3: st.push(A[x]); -- x, -- y; break;
    }
  }

  while(!st.empty()) {
    printf("%d ", st.top());
    st.pop();
  }
  return 0;
}
