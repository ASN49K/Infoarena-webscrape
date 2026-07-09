#include<cstdio>
using namespace std;
int n;
struct str{int a,b,r;
			int cmmdc() 
				{while(b) {r=a%b;a=b;b=r;}
				 return a;
				}
			};
str x;
int main()
{freopen("euclid2.in","rt",stdin);
 freopen("euclid2.out","wt",stdout);
 scanf("%d",&n);
 for(register int i=1;i<=n;i++)
	 {scanf("%d%d",&x.a,&x.b); printf("%d\n",x.cmmdc());
	 }
 return 0;
}
