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
    int T,x,y,z,i;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {scanf("%d",&x);
    scanf("%d",&y);
    z=cmmdc(x,y);
    printf("%d\n",z);
    }
      return 0;
     }
     
