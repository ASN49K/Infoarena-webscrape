#include<stdio.h>
#define DIM 101
int a,b,min,n;
int main ()
{
    freopen ("euclid2.in","r",stdin);
    freopen ("euclid2.out","w",stdout);
    int i,j;
    scanf("%d",&n);
    for(i=1;i<=n;++i)
    {
                     scanf("%d%d",&a,&b);
                     if(a==b+1 || b==a+1)
                     printf("1\n");
                     else
                     {
                     if(a<b)
                     min=a;
                     else
                     min=b;
                     for(j=1;j<=min;++j)
                     {
                                      if(b%(min/j)==0)
                                      {
                                                      printf("%d\n",min/j);break;
                                      }
                     }
                     }
    }
    return 0;
}
