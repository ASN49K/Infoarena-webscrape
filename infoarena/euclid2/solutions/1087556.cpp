#include<cstdio>
#define filein "euclid2.in"
#define fileout "euclid2.out"
using namespace std;

int cmmdc(int a,int b);

int main()
{
	freopen (filein,"r",stdin);
	freopen (fileout,"w",stdout);
	int t,i,a,b;
	scanf("%d",&t);
	for (i=1; i<=t; i++)
	{
		scanf("%d %d",&a,&b);
		printf("%d\n",cmmdc(a,b));
	}
	return 0;
}

int cmmdc(int a,int b)
{
	if (a%b==0) 
		return b;
	return cmmdc(b,a%b);
}
