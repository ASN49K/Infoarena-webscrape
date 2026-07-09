#include <stdio.h>

int T,a,b;
int cmmdc(int a,int b)
{int r;
while (b)
{
r=a%b;
a=b;
b=r;
}
return a;
}

int main()
{
freopen("euclid2.in","r",stdin);
freopen("euclid2.out","w",stdout);

scanf("%d",&T);
while (T)
{
scanf("%d %d",&a,&b);
printf("%d\n",cmmdc(a,b));
--T;
}
return 0;
}