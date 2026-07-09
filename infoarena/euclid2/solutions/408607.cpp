#include<cstdio>
using namespace std;
int main()
{
	int a,b,r,t,i;
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
 scanf("%d",&t);
	for(i=1;i<=t;i++){
		scanf("%d%d",&a,&b);
	while(a%b!=0)
	{r=a%b;
	a=b;
	b=r;
	}
	printf("%d\n",b);
	}
return 0;
}

