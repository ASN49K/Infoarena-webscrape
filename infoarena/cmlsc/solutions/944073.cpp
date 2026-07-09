#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXL = 1025;
int A[MAXL], B[MAXL];
int dp[MAXL][MAXL];
int pre[MAXL][MAXL];

int main() {
  freopen("cmlsc.in","r",stdin);
  freopen("cmlsc.out","w",stdout);

  int M, N;
  scanf("%d %d",&M,&N);
  for(int i = 1;i <= M;i++) {
    scanf("%d",&A[i]);
  }
  for(int i = 1;i <= N;i++) {
    scanf("%d",&B[i]);
  }

  for(int i = 1;i <= M;i++) {
    for(int j = 1;j <= N;j++) {
      if(A[i] == B[j]) {
	dp[i][j] = dp[i-1][j-1]+1;
	pre[i][j] = 1;
      }else if(dp[i][j-1] > dp[i-1][j]) {
	dp[i][j] = dp[i][j-1];
	pre[i][j] = 2;
      }else {
	dp[i][j] = dp[i-1][j];
	pre[i][j] = 3;
      }
    }
  }

  printf("%d\n",dp[M][N]);
  vector<int> out;
  for(int a = M, b = N;pre[a][b] > 0;) {
    if(pre[a][b] == 1) {
      out.push_back(A[a]);
      a--; b--;
    }else if(pre[a][b] == 2) b--;
    else a--;
  }
  for(;!out.empty();out.pop_back()) printf("%d ",out.back());
  puts("");

  return 0;
}
