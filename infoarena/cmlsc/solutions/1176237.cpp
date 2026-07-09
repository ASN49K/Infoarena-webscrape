#include <cstdio>
#include <stack>
#define sh short int
#define NM 1026
using namespace std;
sh N, M, s1[NM], s2[NM];
sh a[NM][NM];
stack <sh> st;

int main() {
  freopen("cmlsc.in","r",stdin);
  freopen("cmlsc.out","w",stdout);
  scanf("%hd %hd", &N, &M);
  for (int i = 1; i <= N; ++i) {
    scanf("%hd",&s1[i]);
    a[i][0] = 0;
  }
  for (int i = 1; i <= M; ++i) {
    scanf("%hd",&s2[i]);
    a[0][i] = 0;
  }
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= M; ++j) {
      if (s1[i] == s2[j]) {
        a[i][j] = a[i-1][j-1] + 1;
        continue;
      }
      if (a[i][j-1] > a[i-1][j]) {
        a[i][j] = a[i][j-1];
        continue;
      }
      a[i][j] = a[i-1][j];
    }
  }
  printf("%hd\n",a[N][M]);

  int i=N, j=M;
  while (i && j) {
      if (s1[i] == s2[j]) {
        st.push(s1[i]);
        --i;--j;
        continue;
      }
      if (a[i][j-1] > a[i-1][j]) {
        --j;
        continue;
      }
      --i;

  }
  while (!st.empty()) {
    printf("%hd ", st.top());
    st.pop();
  }
  return 0;
}
