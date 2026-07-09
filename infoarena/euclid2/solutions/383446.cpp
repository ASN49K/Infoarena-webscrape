#include<stdio.h>
#include<stdlib.h>

int main()
{int t,a,b,r;
freopen("euclid2.in","r",stdin);
freopen("euclid2.out","w",stdout);
scanf("%d",&t);
for(;t;--t)
{
scanf("%d%d",&a,&b);
while(r==1)
{
r=a%b;
b=a;
r=b;
}
printf("%d",r);
}
fclose(stdin);
fclose(stdout);
return 0;
}