#include<stdio.h>
int main()
{   freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    int a,b,n;
     scanf("%d",&n);   
    for(int i=1;i<=n;i++)
    {
    scanf("%d",&a);
    scanf("%d",&b);
    if(a>=b)
    {
    for(int i2=b;i2!=0;--i2)
    if(a%i2==0&&b%i2==0)
    {
                        printf("%d\n",i2);
                        i2=1;
    }
    }
    if(a<=b)
    for(int i3=a;i3!=0;--i3)
    if(a%i3==0&&b%i3==0)
    {
                        printf("%d\n",i3);
                        i3=1;
    }
    }
    return 0;
    }
