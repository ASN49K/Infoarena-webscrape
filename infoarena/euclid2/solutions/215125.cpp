#include <stdio.h>
/*******************/
int cmmdc(int x,int y)
{int r;
 while (y!=0)
        {r=x%y;
         x=y;
         y=r;
        }
 return x;
}

int main()
{freopen("euclid2.in","r",stdin);
 freopen("euclid2.out","w",stdout);
 int t,i,a,b;
 scanf("%d",&t);
 for (i=1;i<=t;i++)
        {scanf("%d %d",&a,&b);
         printf("%d\n",cmmdc(a,b));
        }
 return 0;
}
