#include<stdio.h>
int main()
{int a,b,r,n,i;
freopen("cmmdc.in","r",stdin);
freopen("cmmdc.out","w",stdout);
scanf("%d",&n);
for(i=1;i<=n;i++)
{
scanf("%d%d",&a,&b);
while(b!=0)
{r=a%b;
 a=b;
 b=r;
}
printf("%d\n",a);
}
return 0;}