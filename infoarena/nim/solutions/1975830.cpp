#include <cstdio>
using namespace std;
int main(){
  freopen("nim.in", "r", stdin);
  freopen("nim.out", "w", stdout);
  int t, n, x;
  scanf("%d", &t);
  for (int i = 1; i <= t; ++i){
    scanf("%d%d", &n, &x);
    for (int i = 2; i <= n; ++i){
      int a;
      scanf("%d", &a);
      x ^= a;
    }
    if (x == 0)
      printf("NU\n");
    else
      printf("DA\n");
  }
  return 0;
}
