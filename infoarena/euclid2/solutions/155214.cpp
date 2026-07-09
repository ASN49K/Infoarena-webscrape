#include<stdio.h>
int t,a,b;
int eul(int a,int b)
{
	int r;
	r=a%b;
	while(r)
	{
		a=b;
		b=r;
		r=a%b;
	}
	return b;
}
int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d",&t);
	while(t>0)
	{
		scanf("%d%d",&a,&b);
		printf("%d\n",eul(a,b));
		t--;
	}
	return 0;
}
