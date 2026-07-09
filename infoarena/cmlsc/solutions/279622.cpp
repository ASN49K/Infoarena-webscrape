#include <stdio.h>
#define FOR(i, a, b) for(i = a; i <= b; i++)
#define dim 50
#define max(a, b) ( (a) > (b) ? (a) : (b))
int n, m, a[dim], b[dim], c[dim][dim], i, j, sir[dim], k;

void read(void)
{
 freopen("cmlsc.in", "r", stdin);
 freopen("cmlsc.out", "w", stdout);
 scanf("%d %d", &m, &n);

 FOR(i, 1, m)
  scanf("%d", &a[i]);
 FOR(i, 1, n)
  scanf("%d", &b[i]);

 fclose(stdin);
}
void solve()
{
  c[1][1] = (a[1] == b[1]) ? 1 : 0;
 FOR(i, 2, m)
  c[i][1] = (a[i] == b[1]) ? 1 : c[i-1][0];
 FOR(i, 2, n)
  c[1][i] = (a[1] == b[i]) ? 1 : c[1][j-1];

 FOR(i, 2, m)
  FOR(j, 2, n)
	c[i][j] = max( max( ((a[i] == b[j]) ? c[i-1][j-1] + 1 : 0) , c[i-1][j]), c[i][j-1]);



 i = m;
 j = n;
 while( i >=1 && j>=1)
  if(a[i] == b[j])
  {
	sir[++k] = a[i];
	--j;
	--i;
  }
  else
	if( i - 1 >= 1 && c[i][j] == c[i-1][j])
	 --i;
	else
	 --j;
}
void print(void)
{
  printf("%d\n", c[m][n]);
  for(i = k; i >= 1; i--)
	printf("%d ", sir[i]);
}
int main(void)
{
  read();
  solve();
  print();

  fclose(stdout);
  return 0;

}