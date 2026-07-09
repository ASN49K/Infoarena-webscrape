#include <stdio.h>
#define FOR(i, a, b) for(i = a; i <= b; i++)
#define dim 1025
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

 FOR(i, 1, m)
  FOR(j, 1, n)
	if(a[i] == b[j])
	 c[i][j] = c[i-1][j-1] + 1;
	else
	 c[i][j] = max(c[i-1][j], c[i][j-1]);


 i = m, j = n;
 while(  i && j )
  if(a[i] == b[j])
  {
	sir[++k] = a[i];
	--j;
	--i;
  }
  else
	if( c[i-1][j] > c[i][j-1])
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