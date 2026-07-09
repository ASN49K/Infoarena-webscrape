using namespace std;
#include<cstdio>
int d;
void cmmdc(int a,int b)
{
	if(b)
		cmmdc(b,a%b);
	else
		d=a;
}
int main()
{
	freopen("cmmdc.in","r",stdin);
	freopen("cmmdc.out","w",stdout);
	int a,b,T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&a,&b);
		cmmdc(a,b);
		printf("%d\n",d);
	}
	return 0;
}
