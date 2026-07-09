#include<cstdio>
using namespace std;
int t1,i,a,b;
int cmmdc(int a,int b)
{
	int r;
	while(b!=0)
	{
		r=a%b;
		a=b;
		b=r;
	}
	return a;
}
int main()
{
freopen("euclid2.in","r",stdin);
freopen("euclid2.out","w",stdout);
scanf("%d",&t1);
for(i=1;i<=t1;i++)
{
	scanf("%d",&a);
	scanf("%d",&b);
	printf("%d\n",cmmdc(a,b));
}
return 0;
}
