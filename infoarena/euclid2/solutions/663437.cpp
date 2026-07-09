#include <cstdio>

int euclid(int C, int D)
{
  if(D == 0)
  {
    return C;
  }
  else
  {
    return euclid(D, C % D);
  }
}

int main()
{
  freopen("euclid2.in", "r", stdin);
  freopen("euclid2.out", "w", stdout);

  int T, C, D, x;

  scanf("%d", &T);

  for(x=0; x<T; x++)
  {
    scanf("%d %d", &C, &D);
    printf("%d\n", euclid(C, D));
  }
}
