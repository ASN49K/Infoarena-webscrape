#include<cstdio>

int main()
{
 int n, a, b, t;
 freopen("euclid2.in", "r", stdin);
 freopen("euclid2.out", "w", stdout);
 scanf("%d", &n);
 while(n>0)
 {
  scanf("%d %d", &a, &b);
  while(b!=0)
  {
		t = b;
		b = a % b;
		a = t;
  }
	printf("%d\n", a);
  n--;
 } 
}
