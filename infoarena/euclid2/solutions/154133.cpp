#include<stdio.h>
int main()
{
unsigned long a,b;
freopen("euclid2.in","r",stdin);
freopen("euclid2.out","w",stdout);
scanf("%lu%lu",&a,&b);
int r;
while(b)
{
r=a%b;
a=b;
b=r;
}
printf("%lu",a);
fcloseall();
return 0;
}