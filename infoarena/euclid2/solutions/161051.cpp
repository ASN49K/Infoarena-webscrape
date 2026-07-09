#include <stdio.h>   
  
int a,b,r,i,t;   
  
int main()   
{   
    freopen("euclid2.in","r",stdin);   
    freopen("euclid2.out","w",stdout);   
    scanf("%d",&t);
    for (i=1; i<=t; ++i)
    {
    scanf("%d",&a);   
    scanf("%d",&b);   
    while (b!=0)   
    {   
        r=a%b;   
        a=b;   
        b=r;   
    }   
    if (b!=1) printf("%d",a);   
    }
    return 0;   
}  
