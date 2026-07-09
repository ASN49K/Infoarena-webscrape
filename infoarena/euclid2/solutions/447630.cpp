#include <cstdio>

int t,a,b;

int cmmdc(int a,int b)
{
	if(b==0)
		return a;
	else
		return cmmdc(b,a%b);
}
void rez()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d",&t);
	for(;t--;)
	{
		scanf("%d%d",&a,&b);
		printf("%d\n",cmmdc(a,b));
	}
}
int main()
{
	rez();
	return 0;
}
