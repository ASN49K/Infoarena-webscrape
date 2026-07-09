#include <stdio.h>
int a, b, n;
int cmmdc(int a, int b)
{
 if(!b)
  return a;
 else
  return cmmdc(b, a%b);
}
int main(void)
{
 freopen("euclid2.in","r",stdin);
 freopen("euclid2.out","w",stdout);
 scanf("%d", &n);
 for( int i = 1; i <= n; i++)
 {
	scanf("%d%d", &a,&b);
	printf("%d", cmmdc(a,b));
 }
 fcloseall();
 return 0;
}