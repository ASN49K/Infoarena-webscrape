#include<cstdio>
#include<algorithm>
const int NMAX = 1024;
int a[NMAX + 1];
int b[NMAX + 1];
int sol[NMAX + 1];
int L[NMAX + 1][NMAX + 1];
int main()
{
  int n , m;
  freopen("cmlsc.in" , "r" , stdin);
  freopen("cmlsc.out" , "w" , stdout);
  scanf("%d%d" , &n , &m);
  for(int i = 1; i <= n ; i ++)
    scanf("%d" , &a[i]);
  for(int j = 1; j <= n ; j ++)
    scanf("%d" , &b[j]);
  for(int i = 1; i <= n ; i ++)
    for(int j = 1; j <= m; j ++)
  {
      if(a[i] == b[j])
      {
        L[i][j] = L[i - 1][j - 1] + 1;
      }
      else
      {
        L[i][j] = std :: max(L[i - 1][j] , L[i][j - 1]);
      }
  }
  int i = n;
  int j = m;
  int k = 0;
  while(i > 0 && j > 0)
  {
    if(a[i] == b[j])
    {
      sol [++k] = a[i];
      i --;
      j --;
    }
    else if(L[i-1][j] < L[i][j-1])
      j --;
    else
      i --;
  }
  printf("%d\n" , k);
  while(k)
  {
    printf("%d " , sol[k]);
    k --;
  }
  return 0;
}

