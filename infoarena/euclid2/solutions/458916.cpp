#include<stdio.h>
# define infile "euclid2.in"
#define outfile "euclid2.out"

void solve();

int main()
{
	freopen(infile,"r",stdin);
	freopen(outfile,"w",stdout);
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
long cmmdc(long a,long b)
{
	long r,aux;
	if(a<b)
	{
		aux=a;
		a=b;
		b=aux;
	}
	while(b!=0)
	{
		r=a%b;
		a=b;
		b=r;
	}
	return a;
}
void solve()
{
	long i,n,r,a,b;
	scanf("%ld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%ld%ld",&a,&b);
		r=cmmdc(a,b);
		printf("%ld\n",r);
	}
}
