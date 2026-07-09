#include <stdio.h>
#define dim 100001
int  v[dim], max[dim], next[dim], n, i, j, l, start;
void read(void)
{
 freopen("scmax.in","r",stdin);
 freopen("scmax.out","w",stdout);
 scanf("%d", &n);
 for ( i = 1; i <= n ; i++)
  scanf("%d", &v[i]);

}
void scm(int v[], int n)
{
  max[n] = 1;
  next[n] = -1;
  for( i = n - 1; i >= 1; i--)
  {
	max[i] = 1;
	next[i] = -1;
	for( j = i + 1; j <= n; j++)
	{
	 if(v[i] < v[j] && max[i] <= max[j])
	  {
		max[i] = max[j] + 1;
		next[i] = j;
	  }
	}
  }
 l = max[1];
 start = 1;
 for( i = 2; i <= n; i++)
 {
  if(l < max[i])
	{
	 l = max[i];
	 start = i;
	}
 }
 printf("%d\n", l);
 printf("%d ",v[start]);
 for(i = 2; i <= l; i++)
  {
	start = next[start];
	printf("%d ", v[start]);
  }
  printf("\n");


}

int main(void)
{
  read();
  scm(v, n);

  fcloseall();
  return 0;
}