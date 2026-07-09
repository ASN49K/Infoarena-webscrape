#include<cstdio>
int gcd(int x,int y)
{
	if(y)
		return gcd(y,x%y);
	return x;
}

int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	int i,t,a,b;
	scanf("%d",&t);
	for (i=1;i<=t;i++)
	{
	    scanf("%d %d",&a,&b);
	    printf("%d\n",gcd(a,b));
	}
	return 0;
}

