#include<stdio.h>
using namespace std;
int a,b,r;

int main ()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d%d",&a,&b);
	while(b!=0)
	{
		r=a%b;
		a=b;
		b=r;
	}
	printf("%d",a);
	return 0;
}