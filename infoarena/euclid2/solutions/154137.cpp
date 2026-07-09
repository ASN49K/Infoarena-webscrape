#include<stdio.h>
int main()
{
unsigned long a,b,t,i;
freopen("euclid2.in","r",stdin);
freopen("euclid2.out","w",stdout);
scanf("%lu",&t);
for(i=1;i<=t;i++)
{
scanf("%lu%lu",&a,&b);
int r;
while(b)
{
r=a%b;
a=b;
b=r;
}
printf("%lu\n",a);
}
fcloseall();
return 0;
}