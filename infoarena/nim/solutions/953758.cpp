#include<cstdio>

using namespace std;

int main()
{
  freopen("nim.in", "r", stdin);
  freopen("nim.out", "w", stdout);
  int t, n, x, i, j;
  int c;
  scanf("%d", &t);
  for(i = 1; i <= t; ++ i)
  {
    x = 0;
    scanf("%d", &n);
    for(j = 1; j <= n; ++ j)
    {
      scanf("%d", &c);
      x = x ^ c;
    }
    if(x)
      printf("DA\n");
    else
      printf("NU\n");
  }
  return 0;
}
