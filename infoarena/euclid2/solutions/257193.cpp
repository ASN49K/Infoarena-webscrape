#include <stdio.h>
int n,a,b;
int cmmdc(int a, int b)
{if (b==0) return a;
 return cmmdc(b,a%b);
}
int main(void)
{
freopen("euclid1.cpp","r",stdin);
freopen("euclid2.cpp","w",stdout);
scanf("%d",&n);
for (int i=0;i<n;i++)
{
 scanf("%d %d", &a, &b);
 printf("%d\n", cmmdc(a,b));
}
return 1;
}
