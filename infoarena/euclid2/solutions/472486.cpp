#include<stdio.h>
int a,b,t;
int main()
{freopen("euclid2.in","r",stdin);
freopen("euclid2.out","w",stdout);
scanf("%d",&t);
while(t)
{t--;
scanf("%d%d",&a,&b);
int r=1;
while(r)
{r=b%a;
b=a;
a=r;
}
printf("%d\n",b);
}
return 0;
}
