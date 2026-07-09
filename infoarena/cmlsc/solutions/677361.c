#include<stdio.h>

int m, n, a[1025], b[1025];
int lcs[1025][1025];

void print(int i, int j)
{
  if (i == 0 || j == 0)
    return;
  if (a[i] == b[j])
  {
    print(i-1, j-1);
    printf("%d ", a[i]);
  } else {
    if (lcs[i][j-1] > lcs[i-1][j])
      print(i, j-1);
    else
      print(i - 1, j);
  }
}

int main()
{
  freopen("cmlsc.in", "r", stdin);
  freopen("cmlsc.out", "w", stdout);

  scanf("%d %d", &m, &n);
  int i, j;
  for(i = 1; i <= m; i++)
    scanf("%d", &a[i]);

  for(i = 1; i <= n; i++)
    scanf("%d", &b[i]);

  for(i = 1; i <= m; i++)
    for(j = 1; j <= n; j++)
      if (a[i] == b[j])
        lcs[i][j] = lcs[i-1][j-1] + 1;
      else
        if (lcs[i][j-1] > lcs[i-1][j])
          lcs[i][j] = lcs[i][j-1];
        else
          lcs[i][j] = lcs[i-1][j];

  printf("%d\n", lcs[m][n]);
  print(m, n);

  return 0;
}
