#include<cstdio>
using namespace std;
int n,x,y,r,c;
int cmmdc(int a,int b)
{while(b)
	{r=a%b;a=b;b=r;
	}
 return a;
}
void cit()
{freopen("euclid2.in","rt",stdin);
 freopen("euclid2.out","wt",stdout);
 scanf("%d",&n);
 for(register int i=1;i<=n;++i)
	 {scanf("%d%d",&x,&y);c=cmmdc(x,y);printf("%d\n",c);
	 }
}
int main()
{cit();
 return 0;
}
