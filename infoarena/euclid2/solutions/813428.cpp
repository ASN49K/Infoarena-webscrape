#include <stdio.h>
int main ()
{
    freopen ("euclid2.in","r" ,stdin);
    freopen ("euclid2.out","r" ,stdout);
    long n,m,p,i,k;
    scanf("%d",&k);
for(i=1;i<=k;++i)
{
scanf("%ld%ld",&n,&m);
while(m>0)
{
p=n%m;
n=m;
m=p;
}
printf("%ld\n",n);
}
return 0;
}


