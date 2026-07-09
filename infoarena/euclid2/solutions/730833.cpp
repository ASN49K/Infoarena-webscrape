using namespace std;
#include<cstdio>
int a,b,T,r,i;
int main ()
{
	freopen("euclid.in","r",stdin);
	freopen("euclid.out","w",stdout);
	scanf("%d",&T);
	for(i=1;i<=T;i++)
	{ scanf("%d%d",&a,&b);
	r=1;
	while(b)
{ r=a%b;
a=b;
b=r;
} printf("%d\n",a);
	}
return 0;
	}
