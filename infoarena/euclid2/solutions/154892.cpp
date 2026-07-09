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
 scanf("%d", &n);
 for (int i=1;i<=n;i++)  
 {
  scanf("%d %d",&a,&b);
  printf("%d \n",div(a,b));
 }
 return 0;
}