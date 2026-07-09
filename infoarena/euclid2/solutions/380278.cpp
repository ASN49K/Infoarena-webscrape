#include<stdio.h>
int cmmdc(int a,int b)
{
    int r;
    while(a%b!=0)
    {
      r=a%b;
      a=b;
      b=r;
      }
return b;
}
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    int T,x,y,z;
    scanf("%d",&T);
    do
    {scanf("%d",&x);
    scanf("%d\n",&y);
    z=cmmdc(x,y);
    printf("%d",z);
    }while(x!=0)
     return 0;
     }