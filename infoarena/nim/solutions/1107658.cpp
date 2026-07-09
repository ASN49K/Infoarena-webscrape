#include <cstdio>

using namespace std;

void solve_test() {
  int N, x = 0, g;
  scanf("%d", &N);
  while(N--) {
    scanf("%d", &g);
    x ^= g;
  }
  printf(x ? "DA\n" : "NU\n");
}

int main(int argc, char *argv[]) {
  freopen("nim.in", "r", stdin);
  freopen("nim.out", "w", stdout);

  int T;
  scanf("%d", &T);
  while(T--) solve_test();

  return 0;
}
