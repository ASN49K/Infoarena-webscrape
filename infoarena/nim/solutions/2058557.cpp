#include <cstdio>

int main() {
  freopen("nim.in", "r", stdin);
  freopen("nim.out", "w", stdout);

  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; t++) {
    int N;
    scanf("%d", &N);
    int s = 0;
    for (int i = 0; i < N; i++) {
      int x;
      scanf("%d", &x);
      s ^= x;
    }
    if (s == 0) {
      printf("NU\n");
    } else {
      printf("DA\n");
    }
  }
  return 0;
}
