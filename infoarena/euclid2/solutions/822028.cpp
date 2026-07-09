#include<cstdio>
using namespace std;
# const int T_max=100000;
long long a,b,T;
unsigned int i,r;
int cmmmdc(int x,int y)
{	
	int z;
	while(y!=0)
	{
		z=x%y;
		x=y;
		y=z;

	}
	return x;

{
int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%lld",&T);
	for(i=1;i<=T;i++)
	{
		scanf("%lld%lld",&a,&b);
		printf("%d",cmmdc(a,b);	

	}

	return 0;
{