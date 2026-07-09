#include<stdio.h>
#define inf "euclid2.in"
#define ouf "euclid2.out"
using namespace std;
int n,a,b;

int cmmdc(int a, int b)
{
	if(!b) return a;
	return cmmdc(b,a%b);
}

int main()
{
	freopen(inf,"r",stdin);
	freopen(ouf,"w",stdout);
	scanf("%d\n",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d\n",&a,&b);
		printf("%d\n",cmmdc(a,b));
	}
	return 0;
}
