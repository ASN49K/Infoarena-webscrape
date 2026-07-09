#include<stdio.h>
int cmmdc(int a,int b)
	{int r;
	 while(b!=0)
    	{r=a%b;
       a=b;
       b=r;}
    return a;
   }
int solve()
	{int n,i,x[3],s;
    scanf("%d",&n);s=0;
    for(i=1;i<=n;i++)
    	{ scanf("%d%d",&x[1],&x[2]);
        s=cmmdc(x[1],x[2]);
        printf(" %d",s);
      }
     return 0;
    }
int main()
	{freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    solve();
    return 0;
    }

