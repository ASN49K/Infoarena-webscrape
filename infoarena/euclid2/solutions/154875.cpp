#include<stdio.h>

long div(long a, long b)
{
  if (!b) return a;
  else return div(b,a%b);
}

int main()
{
 long a,b;
 int n;
 freopen("euclid2.in","r",stdin),
 freopen("euclid2.out","w",stdout);
 scanf("%l", &n);
 for (int i=1;i<=n;i++)  
 {
  scanf("%l %l",&a,&b);
  printf("%l\n",div(a,b));
 }
 return 0;
}