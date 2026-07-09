#include <stdio.h>

int t,T,a,b;

inline int f(int a,int b)
{
	if(b==0) return a;
	else return f(b,a%b);
}

int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);

	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
		scanf("%d%d",&a,&b);
		printf("%d\n",f(a,b));
	}

	return 0;
}
