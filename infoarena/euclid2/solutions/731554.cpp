#include<stdio.h>

int cmmdc(int a, int b)
{
  int r;
  r = a % b;
  while(r) {
    a = b;
    b = r;
    r = a % b;
  }
  return b;
}

int main()
{
  freopen("euclid2.in","r",stdin);
  freopen("euclid2.out","w",stdout);

  int a, b, n;

  scanf("%d", &n);

  for(int i=1;i<=n;i++) {
    scanf("%d%d", &a, &b);
    printf("%d\n", cmmdc(a,b));
  }

  return 0;
}
