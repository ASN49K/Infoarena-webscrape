#include<stdio.h>
int gcd(int a,int b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}
int main()
{
	int T,i,a,b;
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.in","w",stdout);
	scanf("%d",&T);
	for(i=1;i<=T;i++)
	{
		scanf("%d %d\n",&a,&b);
		printf("%d\n",gcd(a,b));
	}
	return 0;
}
