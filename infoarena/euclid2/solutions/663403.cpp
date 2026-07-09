#include <cstdio>

int euclid(int C, int D)
{
  int max = 0;
  int x = 1;
  while (x <= C and x <= D)
  {
    if(C % x == 0 and D % x == 0)
    {
      max = x;
    }
    x++;
  }
  return max;
}

int main()
{
  freopen("euclid.in", "r", stdin);
  freopen("euclid.out", "w", stdout);

  int T, C, D, x;

  scanf("%d", &T);

  for(x=0; x<T; x++)
  {
    scanf("%d %d", &C, &D);
    printf("%d\n", euclid(C, D));
  }
}
