#include<stdio.h>
int main()
{int t,a,b,c;
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
 scanf("%d",&t);
 int i;
 for(i=1;i<=t;i++)
    {
        scanf("%d%d",&a,&b);
        c=a%b;
        while(c!=0)
          {a=b;
           b=c;
           c=a%b;
                     }
        printf("%d\n",b);
    }

}
