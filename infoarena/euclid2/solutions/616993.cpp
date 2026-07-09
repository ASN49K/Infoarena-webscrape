#include<cstdio>
using namespace std;
#define infile "euclid2.in"
#define outfile "euclid2.out"
int main ()
{
	freopen(infile, "r", stdin);
	freopen(outfile, "w", stdout);
int i,T,a,b,rest;
scanf("%d",&T);
for(i=1;i<=T;i++)
	{
	scanf("%d %d", &a, &b);
	rest=a%b;
	while(rest!=0)
		{a=b;
		b=rest;
		rest=a%b;
		}
	printf("%d\n", b);
	}

return 0;
}