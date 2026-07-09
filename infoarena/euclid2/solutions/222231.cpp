#include<stdio.h>

using namespace std;
int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	int a,b,d;
	scanf("%d%d%d",&a,&b);
	if(a<b)
	{
		d=a;
		a=b;
		b=d;
	}
	while(a%b)
	{
		d=a%b;
		a=b;
		b=d;
	}
	printf("%d",b);
	return 0;
}
