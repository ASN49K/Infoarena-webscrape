#include <stdio.h>
int main()
{
int a,b,r,i,n;
freopen("euclid2.in","r",stdin);
freopen("euclid2.out","w",stdout);
scanf("%d",&n);
for(i=1;i<=n;i++)
{scanf("%d %d",&a,&b);
r=a%b;
while(r!=0)
{a=b;
b=r;
r=a%b;
}
printf("%d\n",b);}
return 0;
}